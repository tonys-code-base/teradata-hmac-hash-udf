/*
	hmac_hash.cpp
	Teradata UDF for Generating HMAC SHA256/MD5/SHA1 hashes
	Author : Tony Tannous

	This code uses functions/modules published by : https://stephan-brumme.com/
	which are covered under the zlib licence : http://www.zlib.net/zlib_license.html
*/

#define  SQL_TEXT Latin_Text
#include "sqltypes_td.h"

#include <string>
#include <iostream>
#include "cstring"
#include "sha256.h"
#include "hmac.h"
#include "md5.h"
#include "sha1.h"
#include<bits/stdc++.h> 

using std::string;
using std::stringstream;

extern "C"
void hmac_hash(const char *msg
	, const char *key
	, const char *hmac_hash_type
	, char *result
	, int *msgIsNull
	, int *keyIsNull
	, int *hmac_hash_typeIsNull
	, int *resultIsNull
	, char sqlstate[6]
	, SQL_TEXT extname[129]
	, SQL_TEXT specific_name[129]	
	, SQL_TEXT error_message[257]
	) 
{

	//checking NULL value for msg
	if (( *msgIsNull == -1 )) {
		*resultIsNull = -1;
		strcpy(sqlstate, "U0001");
		strcpy((char *)error_message, "Null value supplied for MSG");
		return;
	}

	//checking NULL value for key
	if (( *keyIsNull == -1 )) {
		*resultIsNull = -1;
		strcpy(sqlstate, "U0002");
		strcpy((char *)error_message, "Null value supplied for KEY");
		return;
	}

	//checking NULL value for hmac_hash_type
	if (( *hmac_hash_typeIsNull == -1 )) {
		*resultIsNull = -1;
		strcpy(sqlstate, "U0003");
		strcpy((char *)error_message, "Null value supplied for HMAC_HASH_TYPE");
		return;
	}

	std::string h_s = std::string(hmac_hash_type);
	transform(h_s.begin(), h_s.end(), h_s.begin(), ::toupper); 

	if ( h_s != "HMAC_MD5" && h_s != "HMAC_SHA256" && h_s != "HMAC_SHA1" ) {
		strcpy(sqlstate, "U0004");
		strcpy((char *)error_message, "Invalid Parameter Supplied for HASH_FUNC_TYPE");
		return;

	}

	if ( *key == '\0' ) {
		strcpy(sqlstate, "U0005");
		strcpy((char *)error_message, "KEY cannot be empty");
		return;
	}

	if ( *msg == '\0' ) {
		strcpy(sqlstate, "U0006");
		strcpy((char *)error_message, "MSG cannot be empty");
		return;
	}

	int key_len = strlen(key); // no need to include terminator \0

	if ( key_len % 2 != 0 )
	{
		strcpy(sqlstate, "U0007");
		strcpy((char *)error_message, "Incorrect number of hex bytes/Incorrectly formatted hex string");
		return;		
	}

	for(int k=0; k< key_len; k+=1){
	
		if (isxdigit(key[k]) == 0 ) {
			strcpy(sqlstate, "U0008");
			strcpy((char *)error_message, "Invalid hex byte/s detected");
			return;		  
		}
	}

	std::string hex_key = std::string(key);
	std::string decoded_hex_key;

	for(int i=0; i< key_len; i+=2) {

		std::string byte_as_str = hex_key.substr(i,2);
		std::istringstream strstrm (byte_as_str);
		strstrm.flags(std::ios::hex);
		
		int ord;
		strstrm >> ord;
		decoded_hex_key.push_back((char)ord);

		}

	//Calculate HMAC MD5
	if (h_s == "HMAC_MD5"){

		strcpy(result, hmac<MD5>(msg, decoded_hex_key).c_str());
		return;

	}

	//Calculate HMAC SHA256
	if (h_s == "HMAC_SHA256"){

		strcpy(result, hmac<SHA256>(msg, decoded_hex_key).c_str());
		return;

	}
	
	//Calculate HMAC SHA1
	if (h_s == "HMAC_SHA1"){

		strcpy(result,  hmac<SHA1>(msg, decoded_hex_key).c_str());
		return;

	}

} 