/*--------------------------------------------------------------------------------|
| UDF Name: hmac_hash                                                             |
| Purpose	: Generates HMAC hashes for MD5/SHA1/SHA25                            |
| Author	: Tony Tannous                                                        |
| Date   	: Feb 2020                                                            |
|                                                                                 |
----------------------------------------------------------------------------------|
|PARAMETERS                                                                       |
----------------------------------------------------------------------------------|
1) MSG : The input string which is to be hashed
2) SECRET_KEY: This must be a valid hex string generated using a CSPRNG
3) HMAC_HASH_TYPE: The supported values are currently:
	-> HMAC_MD5 
	-> HMAC_SHA256
	-> HMAC_SHA1
----------------------------------------------------------------------------------|
|SECRET KEY STORAGE                                                               |
----------------------------------------------------------------------------------|
Usage examples will assume the following test key values and location.

1) TABLE DEFINTION:

CREATE TABLE myproj.k_store 
	(
	key_name VARCHAR(30) CHARACTER SET LATIN NOT CASESPECIFIC,
	key_value VARCHAR(512) CHARACTER SET LATIN CASESPECIFIC
	)
PRIMARY INDEX ( key_name );

2) TABLE CONTENTS:
-----------------------------------------------------------------------------------
| key_name     | key_value                                                        |
|--------------|------------------------------------------------------------------|
| h_md5_key    | ca5af32a784e22de51df623bf13f51b1                                 |
| h_sha1_key   | 0f04ae0aa54db11c0c53dc36fbefbac27e099dbf                         |
| h_sha256_key | 6e670ed3e0ebf1daf7570f5f83b45ed48d6df3848c09f38c319c8df3fa5dfc41 |
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------
|USAGE EXAMPLES                                                                   |
-----------------------------------------------------------------------------------
1) GENERATE HMAC SHA256 HASH:

	SELECT hmac_hash(
		'The quick brown fox jumps over the lazy dog.'
	,(select key_value from myproj.k_store where key_name='h_sha256_key')
	, 'HMAC_SHA256'
	);

Output -> bb60d08740527e04c95f8d7c615a9e5c425951192913976c04c3f3419fa61004

2) GENERATE HMAC MD5 HASH: 
	SELECT hmac_hash(
		'The quick brown fox jumps over the lazy dog.'
	,(select key_value from myproj.k_store where key_name='h_md5_key')
	, 'HMAC_MD5'
	);

Output -> d74a6e93a5bc07422e3e18db7de13bc4

3) GENERATE HMAC SHA1 HASH: 
	SELECT hmac_hash(
		'The quick brown fox jumps over the lazy dog.'
	,(select key_value from myproj.k_store where key_name='h_sha1_key')
	, 'HMAC_SHA1'
	);
	
Output -> 9aa16612fc822e77a149896701f65c4aa64d7614
----------------------------------------------------------------------------------*/

DATABASE MYPROJ;

DROP FUNCTION hmac_hash;

CREATE FUNCTION hmac_hash (
	  MSG  VARCHAR(2500) CHARACTER SET LATIN 
	, SECRET VARCHAR(512) CHARACTER SET LATIN 
	, HMAC_HASH_TYPE VARCHAR(30) 
		)
RETURNS VARCHAR (512) CHARACTER SET LATIN
SPECIFIC hmac_hash 
LANGUAGE CPP                             
NO SQL  
EXTERNAL NAME 'CS!sha1!sha1.cpp!
CS!md5!md5.cpp!
CS!hmac_hash!hmac_hash.cpp!
CS!sha256!sha256.cpp!
CI!hmac!hmac.h!
CI!sha256!sha256.h!
CI!md5!md5.h!
CI!sha1!sha1.h!
F!hmac_hash'
PARAMETER STYLE SQL
;

--Only execute after exhaustive testing 
--ALTER FUNCTION hmac_hash EXECUTE NOT PROTECTED;
