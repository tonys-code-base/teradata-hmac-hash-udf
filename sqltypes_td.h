#ifndef _SQLTYPES_TD_
#define _SQLTYPES_TD_
/**********************************************************************
Name:        sqltypes_td.h

   Copyright (c) 2001-2013, 2015  by Teradata Corporation.
   All Rights Reserved. 

Description: Defines the SQL data type in their equivalent C formats.

History:
         DR48360-CA3-01   01Apr20   Initial implementation
         DR59022-RGS-01   02Jun07   Add malloc/free
         DR60086-jbc-01   02May06   Added LOB support
         DR66509-jbc-01   02Dec18   Change size of LOB_REF
         DR66803-CKL-01   03Feb04   Define default interim field size for aggr
                                    UDFs
         DR66803-rgs-01  03Feb19    Redefine time/timestamp with zone.
      DR85421-kevinv-01  03Dec08    UDT support
         DR81673-CA3-01  03Sep02    Changes/Additions for V2R6.0
         DR86125-CKL-01  04Mar04    Fix FNC_free.
         DR96810-rgs-01  05Jul05    Adjust for 64 bit platforms.
      DR97161-rakesh-01  05Jul25    Porting of DR96810 to 6.0.2 branch.
         DR95355-th6-01  05Nov16    Support dynamic output parameters 
                                    for table function
         DR95403-fsk-01  05Oct24    LID
     DR88432-debbieg-01  06Feb15    Add Queryband FNC functions
        DR106050-fsk-01  06Jul20    BIGINT def
   DR106946-sb230132-01  06Oct18    Period dada type support.

        DR111840-fsk-01  07Mar13    Change BIGINT def to #define for older compilers
        DR114685-CKL-01  07Jun25    Enclose all functions within the extern 
                                    "C" statement
    DR114379-phanibr-01  07Nov15    Added FNC_GetStructuredAttributeCount and
                                    FNC_GetStructuredAttributeInfo
    DR123169-phanibr-01  09Jun08    changed attribute_info_t.                                 
   DR116929-hr185004-01  08Feb20    Add changes to report last row
   DR118500-df120645-01  08May21    Support for GLOP feature
   DR130005-jk151003-01  09Feb22    Added 7 new FNC routines.
   DR130711-ct185029-01  09Mar04  Add SIZEOF_UDT_HANDLE macro
   DR115783-RT185013-01  09Sep22  Algorithmic Compression.
   dr135358-ananthas-01  09Nov09  UDWA support.
   DR143678-dw186001-01  10Jun30  Add defines for zone_hour manipulation.
   DR143877-dw186001-01  10Jul09  Corrects cases defines for zone_hour manipulation.
   DR135739-lk185036-01  10Aug04  Add anytype_param_info_t   
   DR138743-kd186004-01  01Oct10  Added FNCs for BAR
   DR107917-cl186009-01  10Nov17  Add UDTName to anytype_param_info_t, ARRAY FNC routines
   DR107917-cl186009-01  11Jan19  Added ARRAY FNC routines.
   DR143253-dz186001-01  11Jan26  NUMBER data type.
   DR153659-as186041-01  11Aug22  Added NUMBER_DT and FNC_DATATYPESETSIZE to dtype_en.
   DR155079-gw186000-01  26Oct11  Add table function new phase control options
                                  introduced by RFC 128333.
   DR144953-ME186004-01  11Dec12  Add FNC functions to support table operators
   DR144953-vt186001-01  12Jan06  Add FNC functions to support Table Operators
   DR114759-pa180002-01  12Jun06  Add FNC_GetISFDName
   DR114759-ap186032-01  12Jul23  EON related changes
   DR161950-vt186001-01  13Feb18  Update FNC_Names_ord_t to support
                                  14.10 syntax expansion
   DR159751-jr185066-01  13May29  Aster Integration.
   DR163183-sd186032     13Aug14  Down amp support for table operators and table functions.
   DR157674-cl186009-01  13Aug14  JSON Support
   DR162287-db186031-01  13Apr03  SQL-H for 15.0
   DR162287-jz186002-01  13May17  SQL-H for 15.0
   DR168146-jz186002-01  13Nov20  SQL-H 15.0
   DR168601-kv121476-01  13Dec18  Add FNC functions for UDT serialize/deserialize
   DR168497-yl185012-01  14Jan07  Support Co-group in user-defined Table Op  
   DR169579-jz186002-01  14Jan31  Extend FNC setExplainText to accept multiple texts
   DR171050-jz186002-01  14May22  Add new FNC functions.
   DR169238-debbieg-01   14Apr11  Add profile query band
   DR162286-en185000-01  14May06  Add FNC_TblOpGetUniqID for SQL-H.
   DR168816-cl186009-01  14Feb06  Enhancements for binary JSON
   DR170274-sd186032-01  14Mar16  SQL-A support 
   DR170274-jz186002-01  14May27  Add new FNC functions. 
   DR170274-pa180002-01  14Jul21  Extend extoptype_et
   DR160658-ar186006-01  14Aug16  Add fillers into some structure to eleminate
                                  padding.
   DR173284-pa180002-01  14Sep22  Extend extoptype_et

   DR173600-ak186072-01  14Oct29  Add FNC_AvailableMallocLimit function
   DR172802-ak186072-01  14Oct10  Add JSON_DT to dtype_en
   DR175456-nt255011-01  15Mar20  Declared FNC_malloc_V,FNC_free_V for  
                                  UDF support
   DR173650-debbieg-01   15Jun22  Increase query band max length
   DR173858-cl186009-01  15Mar09  Changes for FILE data type
   DR171210-yh186003-01  14Aug11  Add FNC_GetExtendedJSONInfo
   DR177116-jt186040-01  15Dec23  Dynamic Stats for Remote Table Optimization
   DR124416-kv121476-01  14Jun05  Add FNC support for ST_Geometry, MBR, MBB, and XML
   DR124416-jr185066-01  15Feb12  Java Enhancements.
   DR124416-ml186063-01  16Mar30  Updated GetExtendedJSONInfo
   DR172404-pn151000     15Oct31  Add FNC_SparseTableAMPs
   DR176703-kv121476-01  16Apr21  Dataset Support
   DR181816-sd186032-01  16Jun13  Add FNC_TblopSetBufSize. 
   DR181519-kv121476-01  16Jun02  CSV Support
   DR180807-ss186170-01  16Apr01  QG MHM Changes
   DR185415-dm186017-01  17Mar06  QGOrideText should be same as QRYBANDMAXLEN.
   DR186130-jk151003-01  17May17  pcre-related safe memory managed interfaces
   DR186504-pn151000     17Jun06  Add FNC_SparseMapAMPs
   DR180417-sd186032-01  17May09  New FNC for Spool reduction for table operator.
   DR186868-vm186030-01  17Oct10  New FNC to get DBS Session attribute info.
   **********************************************************************/

/*******************************************************************/
/* NOTE: In order to use this file the user has to define SQL_TEXT */
/* prior to the include for this file in their source              */
/* code. SQL_TEXT needs to be defined to be the character set type */
/* used when the function was compiled. Example:                   */
/*                                                                 */
/* #define SQL_TEXT Latin_Text                                     */
/*                                                                 */
/* #include <sqltypes_td.h>                                        */
/*                                                                 */
/* SQL_TEXT can be:                                                */
/*                                                                 */
/* Unicode_Text, Latin_Text, Kanjisjis_Text, Kanji1_Text           */
/*                                                                 */
/*******************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>
#include <stdlib.h>

#if ((INT_MAX < 2147483647) || (INT_MAX > 2147483647))
#error "A 'int' must be defined as 32 bits"
#endif

#define FNC_MAXNAMELEN 30
#define FNC_MAXNAMELEN_EON 513                /* DR114759-ap186032-01 */
#define DEFINTERIMSIZE 64
#define PDT_DT 35                    /* DR106946-sb230132-01 */
/* DR169238-debbieg-01 Increase query band sizes for profile query band */
/* Size includes space for a null terminator. */
/* DR173650-debbieg-01 Increase max length of each query band to 4K */
#define FNC_MAXQUERYBANDSIZE   12304 /* Max QueryBand size in bytes */
#define FNC_MAXQUERYBANDSIZE_U 24608 /* Max Unicode Queryband size in bytes */
/* The options for the GetPhaseEx function */
#define TBL_NOOPTIONS 0                          /* DR128333-gw186000-01 */
#define TBL_LASTROW 1                            /* DR116929-hr185004-01 */
#define TBL_NEWROW 2                             /* DR128333-gw186000-01 */
#define TBL_NEWROWEOF 4                          /* DR128333-gw186000-01 */

/* DR144953-mw125167-01-->*/
/* Table Operator open options*/
#define TBLOP_NOOPTIONS        0
#define TBLOP_RAWMODE          1
/*<-- DR144953-mw125167-01*/
/* DR144953-mw125167-01-->*/
/* Table Operator helper macros*/
#define TBLOPISNULL(ptr,N) \
    ( ((BYTE*)ptr)[(N)/ 8] & ( 0x80 >> (((N) % 8))) )
#define TBLOPSETNULL(ptr,N) \
    ( ((BYTE*)ptr)[(N)/ 8] |= ( 0x80 >> (((N) % 8))) )    
#define TBLOPINDICSIZE(c) (((c)+7)/8)
/*<-- DR144953-mw125167-01*/
/* DR144953-mw125167-01-->*/
/* Table Operator read/write return states*/
#define TBLOP_NOROW           -4
#define TBLOP_ERROR           -3
#define TBLOP_ABORT           -2
#define TBLOP_EOF             -1
#define TBLOP_SUCCESS          0
/*<-- DR144953-mw125167-01*/
/*DR162287-db186031-01->>*/
/* Contract Phases */
#define FNC_CTRCT_GET_ALLCOLS_PHASE     0
#define FNC_CTRCT_VALIDATE_PHASE        1
#define FNC_CTRCT_COMPLETE_PHASE        2
#define FNC_CTRCT_DDL_PHASE             3
#define FNC_CTRCT_DEFINE_SERVER_PHASE   4
#define FNC_CTRCT_NULL_PHASE            5
#define FNC_CTRCT_INIT_PHASE            6
#define FNC_CTRCT_FINAL_PHASE           7
#define FNC_CTRCT_OPT_PHASE		8
/*<<-DR162287-db186031-01*/
/*<<-DR177116-rv186022-01*/
#define NUMBER_MAX_MANTISSA_SIZE 17 /* DR143253-dz186001-01 */

typedef unsigned short Unicode_Text;
typedef unsigned char Latin_Text;
typedef unsigned char Kanjisjis_Text;
typedef unsigned char Kanji1_Text;

typedef unsigned char CHARACTER;
typedef unsigned char BYTE;
typedef unsigned short GRAPHIC;

typedef signed char BYTEINT;
typedef short SMALLINT;
typedef int INTEGER;
#define BIGINT long long

typedef double REAL;
typedef double DOUBLE_PRECISION;
typedef double FLOAT;


/* Database DECIMAL data types */
/* of the form DECIMAL(n,m) or  */
/* NUMERIC(n,m) */
typedef signed char DECIMAL1;   /* 1 <= n <= 2 */
typedef short DECIMAL2;  /* 2 <= n <= 4 */
typedef int DECIMAL4;   /* 4 <= n <= 9 */


typedef signed char NUMERIC1;   /* 1 <= n <= 2 */
typedef short NUMERIC2;  /* 2 <= n <= 4 */
typedef int NUMERIC4;   /* 4 <= n <= 9 */

typedef struct 
{
    unsigned int  low;
    int           high;
} DECIMAL8, NUMERIC8;       /*10 <= n <= 18 */

typedef struct 
{
    unsigned  int      int1;
    unsigned  int      int2;
    unsigned  int      int3;
    int                int4;
} DECIMAL16, NUMERIC16;       /*19 <= n <= 38 */

/* DR143253-dz186001-01 --> */
/* database NUMBER type */ 

typedef struct NUMBER 
{
    int length;          
	short scale;
    BYTE mantissa[NUMBER_MAX_MANTISSA_SIZE];  /* allocate max size */
} NUMBER;

/* <-- DR143253-dz186001-01-> */

/* database CHARACTER types */

typedef Latin_Text CHARACTER_LATIN;
typedef Kanjisjis_Text CHARACTER_KANJISJIS;
typedef Kanji1_Text CHARACTER_KANJI1;
typedef Unicode_Text CHARACTER_UNICODE;

/* database VARCHAR type */

typedef Latin_Text VARCHAR_LATIN;
typedef Kanjisjis_Text VARCHAR_KANJISJIS;
typedef Kanji1_Text VARCHAR_KANJI1;
typedef Unicode_Text VARCHAR_UNICODE;
 
/* database VARBYTE type */

  /* Use this for reference to an existing varbyte */

typedef struct VARBYTE 
{
	int    length;		/* length of string */
	BYTE   bytes[1];		/* bytes - size must be adjusted */
} VARBYTE;

   /* Use this macro to define your own varbyte of specific length */
   /* like this:                                                   */
   /*                                                              */
   /* VARBYTE_M(30) myvbstr;                                       */

#define VARBYTE_M(len) struct { int length; BYTE bytes[len]; }

/* database VARGRAPHIC type */

/* use this for reference to an existing vargraphic */

typedef struct VARGRAPHIC {
	int      length;        /* length of string */
	GRAPHIC  graphic[1];	/* string - size must be adjusted */
} VARGRAPHIC;

   /* Use this macro to define your own vargraphic of specific length */
   /* like this:                                                      */
   /*                                                                 */
   /* VARGRAPHIC_M(30) myvgstr;                                       */

#define VARGRAPHIC_M(len) struct { int length; GRAPHIC graphic[len]; }

/* Type definitions for large objects */

typedef int  LOB_LOCATOR;
typedef int  LOB_RESULT_LOCATOR;
typedef int  LOB_CONTEXT_ID;
typedef unsigned long FNC_LobLength_t;

typedef struct LOB_REF
{
    unsigned char data[64];
} LOB_REF;



/* Type definitions for UDTs */

typedef int  UDT_HANDLE;

typedef int  PDT_HANDLE;                           /* DR106946-sb230132-01 */

typedef int  JSON_HANDLE;                          /* DR157674-cl186009-01 */

typedef int  DATASET_HANDLE;                       /* DR173858-cl186009-01 */

typedef int  GEO_HANDLE;                           /* DR124416-kv121476-01 */

typedef int  XML_HANDLE;                           /* DR124416-kv121476-01 */

typedef unsigned long FNC_GeomSize_t;              /* DR124416-kv121476-01 */

typedef unsigned long FNC_XMLSize_t;              /* DR124416-kv121476-01 */

/* Moved definition up from below */
typedef unsigned char boolean_t; /* DR124416-es200014-01 */

/* DBS Information Structure */

typedef struct dbs_info_t 
{	
    SQL_TEXT  	UserAccount[FNC_MAXNAMELEN]; /* users account string */
	SQL_TEXT  	UserName[FNC_MAXNAMELEN];	    /* User name */
	int     UserId;		        /* User ID */
    short   StatementNo;        /* Current statement number for request */
    short   Host;               /* Host ID */
	int 	SessionNo;		    /* Session Number */
    int     RequestNo;          /* Current request number */
} dbs_info_t;

                                            /* DR114759-ap186032-01-> */
/* Add 14.10 version. Names can be a maximum of FNC_MAXNAMELEN_EON length */
typedef struct dbs_info_eon_t 
{	
	char  	UserAccount[FNC_MAXNAMELEN_EON]; /* users account string */
	char  	UserName[FNC_MAXNAMELEN_EON];	    /* User name */
	int     UserId;		        /* User ID */
    short   StatementNo;        /* Current statement number for request */
    short   Host;               /* Host ID */
	int 	SessionNo;		    /* Session Number */
    int     RequestNo;          /* Current request number */
} dbs_info_eon_t;

extern void FNC_DbsInfo_EON(const dbs_info_eon_t *);
                                            /* <-DR114759-ap186032-01 */

/* calls functions can make */

extern int FNC_GetOutputBufferSize();

extern int FNC_GetByteLength(void *inputdata);

extern int FNC_GetCharLength(void *inputstring);

extern int FNC_GetGraphicLength(void *inputdata);

extern int FNC_GetVarCharLength(void *inputstring);

extern void FNC_SetVarCharLength(void *outputstring, int outputstringlength);

extern void FNC_DbsInfo(const dbs_info_t *);

extern void FNC_DBSSessionAttrInfo(char *jsonData); /*DR186868-vm186030-01*/

extern void *FNC_DefMem(int len);

extern void *FNC_malloc(size_t size);

extern unsigned long FNC_AvailableMallocLimit();        /*DR173600-ak186072-01*/

extern void FNC_free(void *ptr);
                                                      /* DR175456-nt255011-01 */
extern void *FNC_malloc_V(size_t size);

extern void FNC_free_V(void *ptr);
                                                      /* DR175456-nt255011-01 */

#define malloc FNC_malloc
#define free   FNC_free

extern void FNC_Trace_String(void *TraceStr);

extern void FNC_Trace_Write(int argc, void *argv[]);

extern void FNC_Trace_Write_DL(int argc, void *argv[], int length[]);

/* Large object access functions */

FNC_LobLength_t
FNC_GetLobLength( LOB_LOCATOR object );

FNC_LobLength_t
FNC_LobOpen( LOB_LOCATOR     object,
             LOB_CONTEXT_ID* ctxid,
             FNC_LobLength_t start,
             FNC_LobLength_t maxlength );

int
FNC_LobRead( LOB_CONTEXT_ID   ctxid,
             BYTE*            buffer,
             FNC_LobLength_t  buffer_length,
             FNC_LobLength_t* actual_length );

void
FNC_LobClose( LOB_CONTEXT_ID  ctxid );

int 
FNC_LobAppend( LOB_RESULT_LOCATOR     object,
               BYTE*                  data,
               FNC_LobLength_t        data_length,
               FNC_LobLength_t*       actual_length );

void
FNC_LobLoc2Ref( LOB_LOCATOR     locator,
                LOB_REF*        ref );

LOB_LOCATOR
FNC_LobRef2Loc( const LOB_REF*  ref );

/* UDT access functions */
void
FNC_GetDistinctValue( UDT_HANDLE    udtHandle,
                      void*         returnValue,
                      int           bufSize,
                      int*          length );

void
FNC_SetDistinctValue( UDT_HANDLE    udtHandle,
                      void*         newValue,
                      int           length );

void
FNC_GetStructuredAttribute( UDT_HANDLE  udtHandle,
                            char*       attributePath,
                            void*       returnValue,
                            int         bufSize,
                            int*        nullIndicator,
                            int*        length );

void
FNC_SetStructuredAttribute( UDT_HANDLE  udtHandle,
                            char*       attributePath,
                            void*       newValue,
                            int         nullIndicator,
                            int         length );

void
FNC_GetDistinctInputLob( UDT_HANDLE     udtHandle,
                         LOB_LOCATOR*   object );

void
FNC_GetDistinctResultLob( UDT_HANDLE            udtHandle,
                          LOB_RESULT_LOCATOR*   object );

void
FNC_GetStructuredInputLobAttribute( UDT_HANDLE      udtHandle,
                                    char*           attributePath,
                                    int*            nullIndicator,
                                    LOB_LOCATOR*    object );

void
FNC_GetStructuredResultLobAttribute( UDT_HANDLE             udtHandle,
                                     char*                  attributePath,
                                     LOB_RESULT_LOCATOR*    object );

void
FNC_GetInternalValue( int           udtHandle,      /*DR157674-cl186009-01*/
                      void*         returnValue,
                      int           bufSize,
                      int*          length );

void
FNC_SetInternalValue( int           udtHandle,      /*DR157674-cl186009-01*/
                      void*         newValue,
                      int           length );

FNC_LobLength_t
FNC_StructInternalTypeAttrSize( UDT_HANDLE  udtHandle,
                                char*       attributePath );

void
FNC_StructInternalTypeAttrSerializeToLob( UDT_HANDLE         udtHandle,
                                          char*              attributePath,
                                          LOB_RESULT_LOCATOR object,
                                          FNC_LobLength_t    *bytesWritten );

void
FNC_StructInternalTypeAttrDeserializeFromLob( UDT_HANDLE      udtHandle,
                                              char*           attributePath,
                                              LOB_LOCATOR     object,
                                              LOB_CONTEXT_ID  ctxid,
                                              FNC_LobLength_t length,
                                              FNC_LobLength_t *bytesRead );

void
FNC_GetStructuredAttributeCount( UDT_HANDLE udtHandle,
                                 int        *Attribute_count);

void
FNC_GetStructuredAttributeByNdx( UDT_HANDLE udtHandle,
                                 int        attributeIndex,
                                 void*      returnValue,
                                 int        bufSize,
                                 int*       nullIndicator,
                                 int*       length );
void
FNC_SetStructuredAttributeByNdx( UDT_HANDLE  udtHandle,
                                 int         attributeIndex,
                                 void*       newValue,
                                 int         nullIndicator,
                                 int         length );
void
FNC_GetStructuredInputLobAttributeByNdx( UDT_HANDLE   udtHandle,
                                         int          attributeIndex,
                                         int*         nullIndicator,
                                         LOB_LOCATOR* object );
void
FNC_GetStructuredResultLobAttributeByNdx( UDT_HANDLE          udtHandle,
                                          int                 attributeIndex,
                                          LOB_RESULT_LOCATOR* object );
FNC_LobLength_t
FNC_StructInternalTypeAttrSizeByNdx( UDT_HANDLE  udtHandle,
                                     int         attributeIndex );
void
FNC_StructInternalTypeAttrSerializeToLobByNdx( UDT_HANDLE         udtHandle,
                                               int                attributeIndex,
                                               LOB_RESULT_LOCATOR object,
                                               FNC_LobLength_t    *bytesWritten );
void
FNC_StructInternalTypeAttrDeserializeFromLobByNdx( UDT_HANDLE      udtHandle,
                                                   int             attributeIndex,
                                                   LOB_LOCATOR     object,
                                                   LOB_CONTEXT_ID  ctxid,
                                                   FNC_LobLength_t length,
                                                   FNC_LobLength_t *bytesRead );
                                                     
void FNC_Dummy(void *argsPtr);
void FNC_Print(void *txtPtr);
void FNC_BARTest1(void *argsPtr);

/* Macros for C Data Type sizes used by the UDT access functions. */
#define SIZEOF_CHARACTER_LATIN(len) ( (len) * sizeof(CHARACTER_LATIN) )
#define SIZEOF_CHARACTER_LATIN_WITH_NULL(len) ( (len) * sizeof(CHARACTER_LATIN) + sizeof(CHARACTER_LATIN) )
#define SIZEOF_CHARACTER_KANJISJIS(len) ( (len) * sizeof(CHARACTER_KANJISJIS) )
#define SIZEOF_CHARACTER_KANJISJIS_WITH_NULL(len) ( (len) * sizeof(CHARACTER_KANJISJIS) + sizeof(CHARACTER_KANJISJIS) )
#define SIZEOF_CHARACTER_KANJI1(len) ( (len) * sizeof(CHARACTER_KANJI1) )
#define SIZEOF_CHARACTER_KANJI1_WITH_NULL(len) ( (len) * sizeof(CHARACTER_KANJI1) + sizeof(CHARACTER_KANJI1) )
#define SIZEOF_CHARACTER_UNICODE(len) ( (len) * sizeof(CHARACTER_UNICODE) )
#define SIZEOF_CHARACTER_UNICODE_WITH_NULL(len) ( (len) * sizeof(CHARACTER_UNICODE) + sizeof(CHARACTER_UNICODE) )
#define SIZEOF_VARCHAR_LATIN(len) ( (len) * sizeof(VARCHAR_LATIN) )
#define SIZEOF_VARCHAR_LATIN_WITH_NULL(len) ( (len) * sizeof(VARCHAR_LATIN) + sizeof(VARCHAR_LATIN) )
#define SIZEOF_VARCHAR_KANJISJIS(len) ( (len) * sizeof(VARCHAR_KANJISJIS) )
#define SIZEOF_VARCHAR_KANJISJIS_WITH_NULL(len) ( (len) * sizeof(VARCHAR_KANJISJIS) + sizeof(VARCHAR_KANJISJIS) )
#define SIZEOF_VARCHAR_KANJI1(len) ( (len) * sizeof(VARCHAR_KANJI1) )
#define SIZEOF_VARCHAR_KANJI1_WITH_NULL(len) ( (len) * sizeof(VARCHAR_KANJI1) + sizeof(VARCHAR_KANJI1) )
#define SIZEOF_VARCHAR_UNICODE(len) ( (len) * sizeof(VARCHAR_UNICODE) )
#define SIZEOF_VARCHAR_UNICODE_WITH_NULL(len) ( (len) * sizeof(VARCHAR_UNICODE) + sizeof(VARCHAR_UNICODE) )
#define SIZEOF_VARBYTE(len) ( sizeof(int) + (len) * sizeof(BYTE) )
#define SIZEOF_BYTE(len) ( (len) * sizeof(BYTE) )
#define SIZEOF_GRAPHIC(len) ( (len) * sizeof(GRAPHIC) )
#define SIZEOF_VARGRAPHIC(len) ( sizeof(int) + (len) * sizeof(GRAPHIC) )
#define SIZEOF_SMALLINT ( sizeof(SMALLINT) )
#define SIZEOF_INTEGER ( sizeof(INTEGER) )
#define SIZEOF_BIGINT ( sizeof(int) + sizeof(int) )
#define SIZEOF_REAL ( sizeof(REAL) )
#define SIZEOF_DOUBLE_PRECISION ( sizeof(DOUBLE_PRECISION) )
#define SIZEOF_FLOAT ( sizeof(FLOAT) )
#define SIZEOF_DECIMAL1 ( sizeof(DECIMAL1) )
#define SIZEOF_DECIMAL2 ( sizeof(DECIMAL2) )
#define SIZEOF_DECIMAL4 ( sizeof(DECIMAL4) )
#define SIZEOF_DECIMAL8 ( sizeof(unsigned int) + sizeof(int) )
#define SIZEOF_DECIMAL16 ( sizeof(unsigned int) + sizeof(int) + sizeof(int) + sizeof(int) )
#define SIZEOF_NUMERIC1 ( sizeof(NUMERIC1) )
#define SIZEOF_NUMERIC2 ( sizeof(NUMERIC2) )
#define SIZEOF_NUMERIC4 ( sizeof(NUMERIC4) )
#define SIZEOF_NUMERIC8 ( sizeof(unsigned int) + sizeof(int) )
#define SIZEOF_NUMERIC16 ( sizeof(unsigned int) + sizeof(int) + sizeof(int) + sizeof(int) )
#define SIZEOF_NUMBER ( sizeof(NUMBER) )    /* DR143253-dz186001-01 */
#define SIZEOF_BYTEINT ( sizeof(BYTEINT) )
#define SIZEOF_DATE ( sizeof(DATE) )
#define SIZEOF_ANSI_Time ( sizeof(DECIMAL4) + 2 * sizeof(BYTEINT) )
#define SIZEOF_TimeStamp ( sizeof(DECIMAL4) + sizeof(SMALLINT) + 4 * sizeof(BYTEINT) )
#define SIZEOF_INTERVAL_YEAR ( sizeof(INTERVAL_YEAR) )
#define SIZEOF_IntrvlYtoM ( 2 * sizeof(SMALLINT) )
#define SIZEOF_INTERVAL_MONTH ( sizeof(INTERVAL_MONTH) )
#define SIZEOF_INTERVAL_DAY ( sizeof(INTERVAL_DAY) )
#define SIZEOF_IntrvlDtoH ( 2 * sizeof(SMALLINT) )
#define SIZEOF_IntrvlDtoM ( 3 * sizeof(SMALLINT) + sizeof(short) )
#define SIZEOF_IntrvlDtoS ( sizeof(DECIMAL4) + 3 * sizeof(SMALLINT) )
#define SIZEOF_HOUR ( sizeof(HOUR) )
#define SIZEOF_IntrvlHtoM ( 2 * sizeof(SMALLINT) )
#define SIZEOF_IntrvlHtoS ( 2 * sizeof(SMALLINT) + sizeof(DECIMAL4) )
#define SIZEOF_MINUTE ( sizeof(MINUTE) )
#define SIZEOF_IntrvlMtoS ( sizeof(DECIMAL4) + sizeof(SMALLINT) )
#define SIZEOF_IntrvlSec ( sizeof(DECIMAL4) + sizeof(SMALLINT) )
#define SIZEOF_ANSI_Time_WZone ( sizeof(DECIMAL4) + 4 * sizeof(BYTEINT) )
#define SIZEOF_ANSI_TimeStamp_WZone ( sizeof(DECIMAL4) + sizeof(SMALLINT) + 6 * sizeof(BYTEINT) )
#define SIZEOF_UDT_HANDLE ( sizeof(UDT_HANDLE) )        /* DR130711-ct185029-01 */

/****************************************************************/
/* Aggregate function phase enumeration type and table function */
/* phase enumeration                                            */
/****************************************************************/

typedef enum FNC_Phase_et {AGR_INIT=1, 
                           AGR_DETAIL=2, 
                           AGR_COMBINE=3, 
                           AGR_FINAL=4, 
                           AGR_NODATA=5, 
                           AGR_MOVINGTRAIL=6,       /* dr135358-ananthas-01  */
                           TBL_PRE_INIT = 20,
                           TBL_INIT = 21,
                           TBL_BUILD = 22,
                           TBL_FINI = 23,
                           TBL_END = 24,
                           TBL_ABORT = 25,  
                           TBL_BUILD_EOF = 26
                       } FNC_Phase_et;
                       
#define FNC_Phase_en BYTE

#define FNC_Phase BYTE

/* Purpose: The options for the GetPhaseEx function */
#define TBL_NOOPTIONS 0
#define TBL_LASTROW 1
#define TBL_NEWROW 2
#define TBL_NEWROWEOF 4

/* Purpose: to define the mode of the arguments to a table function.  */
typedef enum FNC_Mode_et
{
    TBL_MODE_VARY = 1,                             /* arguments vary */
    TBL_MODE_CONST = 2,                    /* arguments are constant */
} FNC_Mode_et;

#define FNC_Mode BYTE 
                                            /* DR180807-ss186170-01-> */
/* Purpose: to provide a structure for the amp-node pair */
typedef struct AMP_Node_t
{
    unsigned short NodeId;
    unsigned short AMPId;
} AMP_Node_t;

/* Purpose: to provide a structure that lists on-line amps  */
typedef struct FNC_Node_Info_t
{
    int NumAMPNodes;
    int NumAMPs;
    AMP_Node_t AN[1]; /* number varies with number of */
                       /* AMP vprocs (one per AMP vproc) */
} FNC_Node_Info_t;

/* Purpose: to provide structure for amp specific information */
typedef struct AMP_Info_t
{
    unsigned short NodeId;
    unsigned short AMPId;
    unsigned short LowestAMPOnNode;
} AMP_Info_t;
                                            /* <-DR180807-ss186170-01 */

extern FNC_Mode FNC_GetPhase(FNC_Phase* Phase); 
extern FNC_Mode FNC_GetPhaseEx(FNC_Phase* Phase, int option);
extern int FNC_TblControl(void);
extern void *FNC_TblAllocCtrlCtx(int length);
extern void *FNC_TblGetCtrlCtx(void);
extern void *FNC_TblAllocCtx(int length);
extern void *FNC_TblGetCtx(void);
extern int FNC_TblOptOut(void);
extern int FNC_TblAbort(void);
extern FNC_Node_Info_t *FNC_TblGetNodeData(void);
extern AMP_Info_t *FNC_AMPInfo(void);
extern int FNC_DownAMP(void); /*DR163183-sd186032 */
extern int FNC_StpNextOK(void); /*DR170274-sd186032-01*/
extern int FNC_ISParallelStp(void); /*DR170274-sd186032-01*/
extern int FNC_TblFirstParticipant(void);

/*************/
/* DATE type */
/*************/

/* To be specific, the date has the following format: */
/*  ((year - 1900) * 10000 + (month * 100) + day)(INTEGER) */

typedef int DATE; 

/*************/
/* ANSI TIME */
/*************/

typedef struct ANSI_Time 
{
    DECIMAL4 seconds; /* represented as DECIMAL(8,6) */
    BYTEINT  hour;
    BYTEINT  minute;
} ANSI_Time;

/***********************/
/* ANSI TIMESTAMP type */
/***********************/

typedef struct TimeStamp 
{
    DECIMAL4 seconds;   /* represented as DECIMAL(8,6) */
    SMALLINT year;
    BYTEINT  month;
    BYTEINT  day;
    BYTEINT  hour;
    BYTEINT  minute;
} TimeStamp;

/*****************/
/* INTERVAL YEAR */
/*****************/

typedef SMALLINT INTERVAL_YEAR;

/**************************/
/* INTERVAL YEAR TO MONTH */
/**************************/

typedef struct IntrvlYtoM 
{
    SMALLINT year;
    SMALLINT month;
} IntrvlYtoM;

/******************/
/* INTERVAL MONTH */
/******************/

typedef SMALLINT INTERVAL_MONTH; 

/****************/
/* INTERVAL DAY */
/****************/

typedef SMALLINT INTERVAL_DAY;

/************************/
/* INTERVAL DAY TO HOUR */
/************************/

typedef struct IntrvlDtoH 
{
    SMALLINT day;
    SMALLINT hour;
} IntrvlDtoH;

/**************************/
/* INTERVAL DAY TO MINUTE */
/**************************/

typedef struct IntrvlDtoM 
{
    SMALLINT day;
    SMALLINT hour;
    SMALLINT minute;
    short pad;   /* contains no useful information */
} IntrvlDtoM;

/**************************/
/* INTERVAL DAY TO SECOND */
/**************************/

typedef struct IntrvlDtoS 
{
    DECIMAL4 seconds;  /* represented as a DECIMAL(8,6) */
    SMALLINT day;
    SMALLINT hour;
    SMALLINT minute;
} IntrvlDtoS;

/*****************/
/* INTERVAL HOUR */
/*****************/

typedef SMALLINT HOUR;

/***************************/
/* INTERVAL HOUR TO MINUTE */
/***************************/

typedef struct IntrvlHtoM 
{
    SMALLINT hour;
    SMALLINT minute;
} IntrvlHtoM;

/***************************/
/* INTERVAL HOUR TO SECOND */
/***************************/

typedef struct IntrvlHtoS 
{
    SMALLINT hour;
    SMALLINT minute;
    DECIMAL4 seconds; /* represented as a DECIMAL(8,6) */
} IntrvlHtoS;

/*******************/
/* INTERVAL MINUTE */
/*******************/

typedef SMALLINT MINUTE;

/*****************************/
/* INTERVAL MINUTE TO SECOND */
/*****************************/

typedef struct IntrvlMtoS 
{
    DECIMAL4 seconds; /* represented as a DECIMAL(8,6) */
    SMALLINT minute;
} IntrvlMtoS;

/*******************/
/* INTERVAL SECOND */
/*******************/

/* Note: fract_sec only contains the fractional seconds. The */
/* whole_sec contains the number of whole seconds            */

typedef struct IntrvlSec 
{
    DECIMAL4  fract_sec; /* represented as a DECIMAL(8,6) */
    SMALLINT whole_sec;
} IntrvlSec;

/***********************/
/* TIME WITH TIME ZONE */
/***********************/

typedef struct ANSI_Time_WZone 
{
    DECIMAL4 seconds; /* represented as DECIMAL(8,6) */
    BYTEINT  hour;
    BYTEINT  minute;
    BYTEINT  zone_hour;
    BYTEINT  zone_minutes;
} ANSI_Time_WZone;

/****************************/
/* TIMESTAMP WITH TIME ZONE */
/****************************/

typedef struct ANSI_TimeStamp_WZone 
{
    DECIMAL4 seconds;   /* represented as DECIMAL(8,6) */
    SMALLINT year;
    BYTEINT  month;
    BYTEINT  day;
    BYTEINT  hour;
    BYTEINT  minute;
    BYTEINT  zone_hour;
    BYTEINT  zone_minutes;
} ANSI_TimeStamp_WZone;

/***********************************/
/* TIMEZONE_INTERNAL_TO_EXTERNAL   */
/* TIMEZONE_EXTERNAL_TO_INTERNAL   */
/***********************************/

/* 
The SQL Types TIME WITH TIME ZONE and TIMESTAMP WITH TIME ZONE zone_hour and
zone_minute fields as UDF input are in internal form. Likewise SQL Types 
TIME WITH TIME ZONE and TIMESTAMP WITH TIME ZONE as UDF output for zone_hour
and zone_minute fields must be in internal form. Note that this also affects
period data composed of two TIME WITH TIME ZONE types or 
TIMESTAMP WITH TIME ZONE types. The following defines are provided to convert
to and from internal and external representation of the time zone fields of
ANSI_Time_WZone and ANSI_TimeStamp_WZone.  The external representation consists
of 3 values, a sign, a hour offset, and a minute offset. The sign is a BYTEINT
which is 0 if the offsets are negative and 1 if the offsets are positve. 
External form for the hour offset should be a BYTEINT between 0 and 14
inclusive prior and post conversion. This represents the hour offset between
UTC and the given zone. External form for the minute offset should be a BYTEINT
between 0 and 59 inclusive. This represents the minute offset between UTC and
the given zone. The largest value for negative offsets is -12:59. The largest
value for positive offsets is +14:00. This representation results in two
representations of UTC, that is +00:00 and -00:00. This mirrors the internal
representation which uses both representations for display purpose.  
*/

/*
MACRO: TIMEZONE_INTERNAL_TO_EXTERNAL(i,s,h,m)
INPUT:  i, ANSI_Time_WZone or ANSI_TimeStamp_WZone.
        s, a BYTEINT to store the sign of i.
        h, a BYTEINT to store the hour offset of i.
        m, a BYTEINT to store the minute offset of i.
*/
#define TIMEZONE_INTERNAL_TO_EXTERNAL(i,s,h,m) \
{\
    s = (BYTEINT)((i)->zone_hour)/(BYTEINT)16; \
    h = ((i)->zone_hour)%(BYTEINT)16 ; \
    m = (BYTEINT)((i)->zone_minutes); \
}

/*
MACRO: TIMEZONE_EXTERNAL_TO_INTERNAL(s,h,m,i)
INPUT:  s, a BYTEINT to set the sign for i.
        h, a BYTEINT to set the hour offset for i.
        m, a BYTEINT to set the minute offset for i.
        i, ANSI_Time_WZone or ANSI_TimeStamp_WZone whose zone is to be set.
*/
#define TIMEZONE_EXTERNAL_TO_INTERNAL(s,h,m,i) \
{\
    (i)->zone_hour = (s) * (BYTEINT) 16 + (h); \
    (i)->zone_minutes = (m); \
}

/**************************/
/* Function Context block */
/**************************/
/* Note: the function context block will have new fields added in */
/* future releases but existing fields will never be changed.     */

typedef struct
{
    unsigned unused   : 30;
    unsigned excl_row : 1;   /* bit 1: set exclude current row */ 
                             /* from OA window */
    unsigned last_row : 1;   /* bit 0: set means last row for OA group */
} FNC_flags_t;

typedef struct FNC_Context_t 
{
    int   version;        /* the version of this context */
    FNC_flags_t flags;    /* misc flags */
    void  *interim1;      /* pointer to intermediate storage 1 */
    int   intrm1_length;  /* length of interim1 area */
    char  filler1[4];     /* DR160658-ar186006-01 */
    void  *interim2;      /* pointer to intermediate storage 2 */
    int   intrm2_length;  /* length of interim2 area */
    char  filler2[4];     /* DR160658-ar186006-01 */
    long  group_count;    /* number of rows in statistical group */
    long  window_size;    /* the size of the statistical window */
    long  pre_window;     /* number of pre window rows */
    long  post_window;    /* number of post window rows */
} FNC_Context_t;

/*******************************************************/
/* Valid data type enumeration for FNC_CallSP support. */
/*******************************************************/

typedef enum dtype_en
{
        UNDEF_DT=0,   
        CHAR_DT=1,
        VARCHAR_DT=2,
        BYTE_DT=3,
        VARBYTE_DT=4,
        GRAPHIC_DT=5,
        VARGRAPHIC_DT=6,
        BYTEINT_DT=7,
        SMALLINT_DT=8,
        INTEGER_DT=9,
        BIGINT_DT=36,
        REAL_DT=10,
        DECIMAL1_DT=11,
        DECIMAL2_DT=12,
        DECIMAL4_DT=13,
        DECIMAL8_DT=14,
        DECIMAL16_DT=37,
        DATE_DT=15,
        TIME_DT=16,
        TIMESTAMP_DT=17,
        INTERVAL_YEAR_DT=18,
        INTERVAL_YTM_DT=19,
        INTERVAL_MONTH_DT=20,
        INTERVAL_DAY_DT=21,
        INTERVAL_DTH_DT=22,
        INTERVAL_DTM_DT=23,
        INTERVAL_DTS_DT=24,
        INTERVAL_HOUR_DT=25,
        INTERVAL_HTM_DT=26,
        INTERVAL_HTS_DT=27,
        INTERVAL_MINUTE_DT=28,
        INTERVAL_MTS_DT=29,
        INTERVAL_SECOND_DT=30,
        TIME_WTZ_DT=31,
        TIMESTAMP_WTZ_DT=32,
        BLOB_REFERENCE_DT=33,
        CLOB_REFERENCE_DT=34,
        UDT_DT=35,
        /* The 8 byte integer type (BIGINT_DT) and
         * the 16 byte decimal type (DECIMAL16_DT) 
         * are located above and have the following
         * values:
         *
         * BIGINT_DT=36    
         * DECIMAL16_DT=37 
         */
        NUMBER_DT=38,                                      /*<-DR153659-as186041-01*/
        PERIOD_DT = 39,                                    /*DR144953-yl185012-01*/
       
        JSON_DT = 40,                    /* DR124416-jr185066-01->> */
        DATASET_AVRO_DT = 41,                           /*DR173858-cl186009-01*/
        ST_GEOMETRY_DT = 42,
        MBR_DT = 43,
        MBB_DT = 44,
        ARRAY_DT = 45,
        XML_DT = 46, /* <<-DR124416-bh186019-01 */ 
        DATASET_CSV_DT = 47,                            /* DR181519-kv121476-01 */
        FNC_DATATYPESETSIZE=48                          /*<-DR95403-fsk-01*//*DR144953-yl185012-01*//*DR172802-ak186072-01*//*DR124416-bh186019-01*//*DR173858-cl186009-01*/
} dtype_en;

typedef int dtype_et;

/* Valid Parameter modes */
typedef enum dmode_en
{
        UNDEF_PM=0,
        IN_PM=1,
        INOUT_PM=2,
        OUT_PM=3
} dmode_en;

typedef int dmode_et;

/* Valid character set types */

typedef enum charset_en
{
        UNDEF_CT=0,
        LATIN_CT=1,
        UNICODE_CT=2,
        KANJISJIS_CT=3,
        KANJI1_CT=4,
        CHARSET_EN_SETSIZE=5 // DR144953-ME186004-01        
} charset_en;

typedef int charset_et;

/*DR168816-cl186009-01 -->*/
typedef enum json_storage_en
{
        JSON_INVALID_EN=-1,
        JSON_TEXT_EN=0,
        JSON_BSON_EN=1,
        JSON_UBJSON_EN=2,
        DATASET_AVRO_EN=3   /*DR173858-cl186009-01*/
} json_storage_en;            /*DR173858-cl186009-01*/

typedef BYTE json_storage_et; /*DR173858-cl186009-01*/
/*<-- DR168816-cl186009-01 */

                    /*DR144953-yl185012-01->*/
typedef enum{
    NOT_PERIOD = 0,
    PERIOD_DATE = 1,
    PERIOD_TIME = 2,
    PERIOD_TIME_WTZ =3,
    PERIOD_TIMESTAMP = 4,
    PERIOD_TIMESTAMP_WTZ = 5
}period_en;
                    /*<-DR144953-yl185012-01*/
typedef BYTE period_et;  /* DR124416-es200014-01 */

/*
** Structure that defines the parameters to the SP
** that is being called via a 'FNC_CallSP' call.
*/
typedef struct parm_t
{
        dtype_et      datatype;
        dmode_et      direction;
        charset_et    charset;

        union {

          int    length;        /* Length of CHAR/VARCHAR/BYTE/GRAPHIC dtypes */

          int    intervalrange; /* range for interval dtypes,
                                 * say, INTERVAL YEAR(4)
                                 */
          int    precision;     /* precision for time/timestamp dtypes,
                                 * say TIME(4) or TIMESTAMP(6) etc.
                                 */
          struct {
            int    totaldigit;  /* value 'm' in a DECIMAL(m, n) data-type */
            int    fracdigit;   /* value 'n' in a DECIMAL(m, n) data-type */
          } range;
        } size;
} parm_t;

/*
Notes on usage of parm_t:

  datatype      Data-type of the parameter.
  direction     IN/OUT/INOUT parameter?
  charset       Character set of the CHAR/VARCHAR data.
  size          Its a union of length, precision and range fields.

                LENGTH:
                -------

                  The length field must be filled out by the C-caller for BYTE,
                  GRAPHIC, CHAR and VARCHAR data-types.

                  ** For other data-types, the length field is not relevant. **

                * For CHAR_DT the length will be taken to be the defined
                  character length of the string i.e. the length mentioned 
                  in the parm_t (for Unicode the number of bytes will actually 
                  be twice the number characters). If the actual length of the 
                  CHAR string is shorter, appropriate padding would be 
                  internally added to the string.

                  The length passed to the SP/XSP being invoked inside 
                  FNC_CallSP will always be the length specified in the 
                  length field. If the actual length of the CHAR string 
                  is shorter, appropriate padding would be internally added 
                  to the string.

                * For VARCHAR_DT the length is based the string length, but not
                  to exceeding the number of characters specified in the length
                  field. The length passed to the SP/XSP being invoked inside 
                  FNC_CallSP would be the specified length or less if the 
                  string being passed is less.

                * For BYTE_DT the length will be as specified in the length
                  field.

                * For GRAPHIC_DT the length will be as specified in the length
                  field. Note a graphic is a two byte character.

                !!! NOTE !!!
                ------------
                  The LENGTH mentioned in parm_t should not be less than
                  one byte and greater than 64000 bytes. If the C string
                  is longer than the length specified in parm_t, then the
                  rest will be thrown away with no error. It is for the
                  C developer to do the proper checking.

                INTERVALRANGE:
                --------------
                * Specifies the range/precision for interval data-types.

                PRECISION:
                ----------
                * Specifies the precision for time/timestamp data-types.

                RANGE: (totaldigit, fracdigit)
                ------
                * Specifies the total-digit and fractional-digits value for
                  DECIMAL data-type of the form DECIMAL(m, n).

                !!! NOTE !!!
                ------------
                  INTERVAL SECOND should also use RANGE to represent
                  INTERVAL SECOND(m, n) form.
*/

/************************/
/* FNC_CallSP prototype */
/************************/

extern void
FNC_CallSP( SQL_TEXT     *SP_Name,
            int           argc,
            void         *argv[],
            int           ind[],
            parm_t        dtype[],
            char         *sqlstate );
      
/***********************************************/
/* QueryBand FNC prototypes                    */
/***********************************************/      

typedef struct 
{	
    void  	*QBName;  /* queryband name */
	void  	*QBValue; /* queryband value */
} FNC_QB_Pair_t;

/* Purpose: to specify types of queryband searches */
typedef enum
{
    QB_FIRST = 0,   
    QB_TXN = 1,     
    QB_SESSION = 2 
} FNC_QBSearch_et;

extern void
FNC_GetQueryBand( void*      QBandBuf,
                  int        BufSize,
                  int*       QBandLen);
                  
extern FNC_QB_Pair_t *
FNC_GetQueryBandPairs( 
            void            *QBandBuf,
            FNC_QBSearch_et  QB_SearchType,
            int             *NumPairs);
                       
extern void
FNC_GetQueryBandValue( 
            void            *QBandBuf,
            FNC_QBSearch_et  QB_SearchType,
            void            *QBName,
            void            *QBValue);

/*DR114759-pa180002-01*/
extern void 
FNC_GetISFDName(
            void        *SrcName,
            void        *DstBuf);

/* Purpose to provide structure for table function runtime */
/* column definition                                       */

typedef struct FNC_ColumnDef_t
{
   int      num_columns;
   parm_t   column_types[1];        
} FNC_ColumnDef_t; 

/*  num_columns          
        maximum number of output parameters
    column_types 
        column data type information 

*/
extern FNC_ColumnDef_t *FNC_TblGetColDef(void);



typedef struct attribute_info_t
{
    INTEGER     attrIndex;                 /* Attribute positional index */
    dtype_et    data_type;           /* attribute data type */
    CHARACTER   attribute_name[256]; /* up to 256 byte attribute name */
    SMALLINT    udt_indicator;       /*
                                      * 0==None
                                      * 1==Struct
                                      * 2==Distinct
                                      * 3==Internal
                                      * 4==Array
                                      * 5==JSON ENCODE AS TEXT
                                      * 6==JSON ENCODE AS BSON
                                      * 7==JSON ENCODE AS UBJSON
                                      */
    CHARACTER   udt_type_name[256];  /* up to 256 byte UDT type name */
    BYTE padbyte;                    /* DR168816-cl186009-01 */
    json_storage_et JSONStorageFormat;   /* DR168816-cl186009-01 */ /*DR173858-cl186009-01*/
    INTEGER     max_length;          /* Max length for this data type */
    FNC_LobLength_t      lob_length;   /* LOB length for LOB data types */
    SMALLINT    total_interval_digits;    /* see usage notes below */
    SMALLINT    num_fractional_digits;    /* see usage notes below */
    charset_et  charset_code;             /* Character Set */
} attribute_info_t;


void  FNC_GetStructuredAttributeInfo( UDT_HANDLE AnyStructuredUdt,
                                      int        attribute_position,
                                      int        bufSize,
                                      attribute_info_t  * attributeArray );
                                            /* DR114759-ap186032-01-> */
/* Add 14.10 version. Names will be of FNC_MAXNAMELEN_EON size */
typedef struct attribute_info_eon_t
{
    INTEGER     attrIndex;                 /* Attribute positional index */
    dtype_et    data_type;           /* attribute data type *//*DR130467-KP185013-01 */
    CHARACTER   attribute_name[FNC_MAXNAMELEN_EON]; /* up to 513 byte attribute name */
    SMALLINT    udt_indicator;       /*
                                      * 0==None
                                      * 1==Struct
                                      * 2==Distinct
                                      * 3==Internal
                                      * 4==Array
                                      * 5==JSON ENCODE AS TEXT
                                      * 6==JSON ENCODE AS BSON
                                      * 7==JSON ENCODE AS UBJSON
                                      */
    CHARACTER   udt_type_name[FNC_MAXNAMELEN_EON];  /* up to 513 byte UDT type name */
    BYTE padbytes[2];                /* DR168816-cl186009-01 */
    json_storage_et JSONStorageFormat;   /* DR168816-cl186009-01 */ /*DR173858-cl186009-01*/
    INTEGER     max_length;          /* Max length for this data type */
    FNC_LobLength_t   lob_length;          /* LOB length for LOB data types *//* DR130467-KP185013-01 */
    SMALLINT    total_interval_digits;    /* see usage notes below */
    SMALLINT    num_fractional_digits;    /* see usage notes below */
    charset_et  charset_code;             /* Character Set *//*DR130467-KP185013-01*/
} attribute_info_eon_t;

void  FNC_GetStructuredAttributeInfo_EON( UDT_HANDLE AnyStructuredUdt,
                                          int        attribute_position,
                                          int        bufSize,
                                      attribute_info_eon_t  * attributeArray );
                                            /* <-DR114759-ap186032-01 */

/*
 * This section contains the GLOP routines and structures.
 */
 
/* The types of GLOP returned from an GLOP_ref_t from a call to FNC_Get_GLOP_Map. */
typedef enum
{
	  	GLOP_NULL = 0,    /* no mapping */
		GLOP_SY = 1,     /* system GLOP */
		GLOP_RO = 2,     /* role GLOP */
		GLOP_US = 3,     /* user GLOP */
		GLOP_SE = 4,     /* session GLOP */
		GLOP_TR = 5,     /* transaction GLOP */
		GLOP_RE = 6,     /* request GLOP */
		GLOP_XR = 7      /* external routine GLOP */
}  GLOP_Type;

/* The attributes of GLOP returned from an GLOP_ref_t from a call to FNC_Get_GLOP_Map. */
typedef enum
{
		GLOP_NONE = 0,    /* no map mode */
		GLOP_R = 1,       /* read only */
		GLOP_W = 2,       /* normal map read/write */
		GLOP_M = 3,       /* normal map global modify */
		GLOP_SW = 4,      /* shared map read/write */
		GLOP_SM = 5       /* shared map global modify */
} GLOP_Mode;

/* The GLOP structure returned from a call to FNC_Get_GLOP_Map. */      
typedef  struct 
{
    void     *GLOP_ptr;
    int       version;
    int       size;
    int       page;
    GLOP_Mode mode;
    GLOP_Type type;
}  GLOP_ref_t;

/* The GLOP structure returned from a call to FNC_Get_GLOP_Map. */  
typedef struct 
{
		GLOP_ref_t  GLOP[8];
} GLOP_Map_t;
	
/*
    This function is used to obtain the GLOP set map information 
    associated with an external routine. All external routines that 
    are a member of a GLOP set must use this call upon entry before 
    they can access any GLOP set data. The call serves two purposes. 
    It lets the system know that the GLOP memory is going to be used 
    and secondly it ensures that new mappings will be registered and 
    that old mappings will be restored. The pointer that is returned 
    is associated with structure GLOP_Map_t. It is an array of 8 GLOP_ref_t 
    structures, plus some internal structures. Eight (8) GLOP data 
    references is the maximum an external routine is allowed to map.

    Passed: 
    Address of where the GLOP structure address is to be stored. 
    
    Returned:
    The pointer to the GLOP structure. It returns a NULL pointer if 
    the external routine has no access to the GLOP set. For example, 
    the external routine contains no MEMBER clause in the create 
    statement or the GLOP data table could not find a row for 
    the specified GLOP set.
    
    Returned integer:
         0  the map was set up
        -1  the map was not set up. Exceeded GLOP data mapping limits
        -2  Not member of GLOP set. 
*/

int FNC_Get_GLOP_Map(GLOP_Map_t **Map); 


/*
    FNC_GLOP_Map_Page is used to map different pages of a read 
    only GLOP or to reload the single page of a read/write or 
    global modifiable GLOP. 

    Read only GLOP data can be split into a number of pages, each of 
    which can be overlaid with the current GLOP in memory. The page 
    to initially map for a read only GLOP can be specified when the 
    GLOP is added or changed. Read/write or global modifiable GLOP 
    data can only consist of one page. Remapping page one of such a 
    GLOP will remap the original data contents of the GLOP. Any changed 
    data in the read/write page will be thrown away.  All pages are the 
    same size and depend on the GLOP_Length field of the GLOP set row.

    The GLOP must not be locked when this call is made. It places an 
    internal exclusive lock that will block all read and write 
    locks while a page  is being replaced. 

    Rules to be aware of:
        You can map the same type of GLOP data in multiple map indexes 
        for read only GLOP data. That way you can map different pages 
        of the same GLOP at the same time. This has to be set up that 
        way in the GLOP_Map table. This can't be done for RO, US or XR GLOPs.

        When reloading page one map for a read write GLOP, an automatic w
        rite lock is placed to prevent any external routine from reading 
        or writing the GLOP while the data is being reinitialized with the 
        original contents. If you use this as part of the design, make sure 
        that all external routines are aware that this could happen.
        
        Different pages for a read only GLOP can be mapped by different external 
        routines at the same time.

    Passed:
        Map_Index  (0 to 7) to the GLOP entry being referred to in the GLOP map.  
        Page the number of the page to map.

    Returned:
         0 if the page was mapped. 
        -1 if the map index is not valid or the map does not exist.
        -2 invalid page number.
        -3 lock conflict. The GLOP is locked by the caller--cannot change the page.
*/

int  FNC_GLOP_Map_Page( int Map_Index, int Page);

/*
    LockType_en defines the choices of lock for use by FNC_GLOP_Lock. 

*/

typedef enum
{
	  	FNC_NONE_LOCK  = 0,    /*  */
		FNC_READ_LOCK  = 1,    /*  */
		FNC_WRITE_LOCK = 2     /*  */
}  LockType_en;

/*
    FNC_GLOP_Lock is used to lock for read or write a 
    vproc local GLOP.

    Multiple read locks will be granted and only one write lock will 
    be granted. All lock requests have a 130 second timeout1 associated 
    with them. If the lock request cannot be granted within 130 seconds 
    the request will return a -2 as the error. The caller should check 
    for that and reapply the request or move on to do something else. 
    The reason for doing this is to avoid any permanent deadlock. The 
    external routine can always decide to abort or try again. Also any 
    granted lock has a time out of 2 minutes. This default can be changed 
    with a configuration parameter. If the GLOP is locked for more than 2 minutes 
    the transaction will be aborted [4.15]. If the external routine 
    terminates with a lock in place it will abort [4.15] the transaction also. 
    This is done to avoid external routine code from locking the memory 
    for extended time periods. It avoids having the database add complex code 
    to try and solve global deadlock issues. Having the timeout also 
    encourages efficient usage of the GLOP while locked. The lock command 
    is only relevant to read/write data. There is no point in locking read 
    only data and it will not be allowed.

    This is an honor system. The external routine can change 
    memory (if it is read/write) at any time with no locks. It can 
    also read the memory with no locks. However the external routine 
    would have to know whether doing that makes sense and could cause 
    problems for other external routines. 

    Don't assume that because a read/write GLOP is mapped for example 
    at the request level that locks are not needed, because that is not n
    ecessarily the case when there are parallel steps in the request. 
    It still requires a lock to avoid any conflict.

    Passed:
        Index to the GLOP to be locked. Value of 0 to 7. It picks an entry in the 
        GLOP map structure. 

        Lock the type of lock to apply. FNC_READ_LOCK, FNC_WRITE_LOCK
    
    Returned:
         0 if the lock was granted. 
        -1 if the index is not valid or the map does not exist.
        -2 if the lock attempt timed out.
        -3 can't lock read only GLOP.

*/
int  FNC_GLOP_Lock( int Index, LockType_en Lock);

/*
    FNC_GLOP_Unlock is used to unlock read/write a GLOP that is locked.

    If some other external routine was waiting for the lock, they might 
    or might not get control before the function call returns.

    Passed:
        Index to the GLOP to be unlocked. Value of 0 to 7. 
        It picks an entry in the GLOP map structure.

    Returned:
         0 if the unlock was granted. 
        -1 if the index is not valid or the entry is not mapped.
        -2 if there was no lock
*/

int  FNC_GLOP_Unlock( int Index);


/*
    FNC_GLOP_Global_Copy is used to make a global copy of one 
    instance to a GLOP to all instances on all vprocs on all 
    nodes. The GLOP must be  globally modifiable, this is the 
    GLOP mode M setting.   A specific range of data can be copied.

    Passed:
        Index to the GLOP to be copied. It must have GLOP_M (3) 
        or GLOP_SM (5) setting for the GLOP_mode field in 
        structure GLOP_ref_t.

        Data_Addr is the starting address of the data to be copied. This could be from
        any valid memory location the external routine has access to. It may
        be an address inside the GLOP. A non destructive copy is performed
        if the Data_Addr and GLOB_Start_Addr overlap or are the same.

        GLOP_Start_Addr starting address of where the data is copied to 
        inside the GLOP.

        Length The length in bytes of the data to be copied. The exact number of bytes
        specified will be copied. 

    Returned:
         0 if the data was copied. 
        -1 if the index is not valid or the map does not exist.
        -2 if the copy attempt timed out.
        -3 can't copy read or read/write only GLOP.
        -4 Address range not valid
        -5 Improper GLOP type or not in correct context.
*/

int  FNC_GLOP_Global_Copy( int   Index,
				   		   void *Data_Addr,
				   		   void *GLOP_Start_Addr,
                           int   Length);
/*
    vproc_type - vproc types returned by FNC_Where_Am_I
    in the Vtype member.
*/
typedef enum
{
		UNK_VPROC = 0,     /* vproc type unknown */
		AMP_VPROC = 1,    /* AMP vproc */
		PE_VPROC = 2      /* PE vproc */
} vproc_type; 
/* 
    Vproc_Info_t returned by FNC_Where_Am_I.

    NumAMPs is the count of the number of online AMPs in the database system
    NumPEs is the count of the number of online PEs in the database system.
    NodeId is the unique number of the node.
    VprocId is the unique number of the vproc.
    Vtype is the type of vproc it is. The values are 1 for an AMP and 2 for a PE.
*/
typedef struct
{
		unsigned short NumAMPs;
		unsigned short NumPEs; 
		unsigned short NodeId;
		unsigned short VprocId;
		vproc_type     Vtype;
} Vproc_Info_t;	 


/* 
    FNC_Where_Am_I

    This function provides information as to what node ID, vproc ID, vproc type 
    and task ID the function is being executed on. This is useful if GLOP data 
    needs to be organized differently depending on where the external routine 
    that is executing is invoked from.

    Returned
    The pointer to structure Vproc_Info_t containing the information specified by the call.
*/

Vproc_Info_t 
*FNC_Where_Am_I(void);
/*DR135739-lk185036-01 -->>*/
typedef struct anytype_param_info_t
{
    INTEGER     paramIndex;  /* Parameter Positional Index*/   
    dtype_et    datatype;    /* Datatype of that parameter */
    dmode_et    direction;  /* Indicates if it is Input or Inout Or Output Parameter */
    INTEGER     max_length;     /*Max Length(in bytes) for this data type */   
    FNC_LobLength_t   lob_length;  /* Max Length of a LOB */
    SMALLINT    total_interval_digits;  /* value 'n' in a DECIMAL(n,m) data-type  or
                                          /*precision for time/timestamp dtypes,say TIME(4) */ 
    SMALLINT    num_fractional_digits;  /* value 'm' in a DECIMAL(n,m) data-type  or
                                          Fractional_seconds_precision for Interval datatypes*/  
    charset_et  charset;/* character set*/ 
    CHARACTER   UDTName[FNC_MAXNAMELEN];   /*name of the UDT, if the param is a UDT*/
    SMALLINT    udt_indicator;       /*
                                      * 0==None
                                      * 1==Struct
                                      * 2==Distinct
                                      * 3==Internal
                                      * 4==Array
                                      * 5==JSON ENCODE AS TEXT
                                      * 6==JSON ENCODE AS BSON
                                      * 7==JSON ENCODE AS UBJSON
                                      */
} anytype_param_info_t;

extern void FNC_GetAnyTypeParamInfo( int bufsize, int * numAnyTypeParams,
                             anytype_param_info_t * AnyTypeAttributeArray);
                             
/*
Purpose: To obtain the TD_ANYTYPE parameter Repr Info.
Passed:  
AnyTypeAttributeArray: Pointer to the buffer that will hold the   
                       TD_ANYTYPE parameter info.                       
              bufSize: Size of the AnyTypeAttributeArray buffer.
Returned: 
     numAnyTypeParams: Number of TD_ANYTYPE Parameters
AnyTypeAttributeArray: contains the info about the TD_ANYTYPE 
                       parameters.
*/

                                            /* DR114759-ap186032-01-> */
/* Add 14.10 version. Names can be a maximum of FNC_MAXNAMELEN_EON length */
typedef struct anytype_param_info_eon_t
{
    INTEGER     paramIndex;  /* Parameter Positional Index*/   
    dtype_et    datatype;    /* Datatype of that parameter */
    dmode_et    direction;  /* Indicates if it is Input or Inout Or Output Parameter */
    INTEGER     max_length;     /*Max Length(in bytes) for this data type */   
    FNC_LobLength_t   lob_length;  /* Max Length of a LOB */
    SMALLINT    total_interval_digits;  /* value 'n' in a DECIMAL(n,m) data-type  or
                                          /*precision for time/timestamp dtypes,say TIME(4) */ 
    SMALLINT    num_fractional_digits;  /* value 'm' in a DECIMAL(n,m) data-type  or
                                          Fractional_seconds_precision for Interval datatypes*/  
    charset_et  charset;/* character set*/ 
    char        UDTName[FNC_MAXNAMELEN_EON];   /*name of the UDT, if the param is a UDT*/
    json_storage_et JSONStorageFormat;   /* DR168816-cl186009-01 */ /*DR173858-cl186009-01*/
    SMALLINT    udt_indicator;       /*
                                      * 0==None
                                      * 1==Struct
                                      * 2==Distinct
                                      * 3==Internal
                                      * 4==Array
                                      * 5==JSON ENCODE AS TEXT
                                      * 6==JSON ENCODE AS BSON
                                      * 7==JSON ENCODE AS UBJSON
                                      */
} anytype_param_info_eon_t;

extern void FNC_GetAnyTypeParamInfo_EON( int bufsize, int * numAnyTypeParams,
                             anytype_param_info_eon_t * AnyTypeAttributeArray);
                                            /* <-DR114759-ap186032-01 */

/*<<--DR135739-lk185036-01 --*/

/*DR107917-cl186009-01 -->*/
typedef int ARRAY_HANDLE;
typedef unsigned char NullBitVecType;
#define FNC_MAXARRAYDIMENSIONS 5
#define NULLBITVECSIZE(items) ( (items%8==0 ? items/8 : items/8+1) )

typedef struct element_info_t
{
    dtype_et data_type;             /*data type of elements of ARRAY type*/
    SMALLINT udt_indicator;         /*indicates whether element is UDT:
                                        0: not UDT
                                        1: structured UDT
                                        2: distinct UDT
                                        3: Teradata proprietary internal UDT */
    CHARACTER udt_type_name[256];   /*UDT type name associated with element of ARRAY*/
    INTEGER max_length;             /*max length in bytes of element value. used as the size
                                      in bytes of the buffer you need to allocate before calling
                                      FNC_GetArrayElement() to get the values of elements*/
    SMALLINT total_interval_digits; /*precision value for certain element types ('n' value). List of types
                                      that use this value is same as attribute_info_t.total_interval_digits*/
    SMALLINT num_fractional_digits; /*precision or scale value for certain element types ('m' value). See
                                      list of types for attribute_info_t.num_fractional_digits for list of types.*/
    charset_et charset_code;        /*server character set associated with element type*/
} element_info_t;

typedef struct bounds_t
{
    int lowerBound;
    int upperBound;
} bounds_t; 


/*DR173858-cl186009-01 -->*/
typedef enum{
    LOWERUNBOUNDED  = 0x0001,      /* The bounds are unbounded in the lower range */
    UPPERUNBOUNDED  = 0x0002,      /* The bounds are unbounded in the upper range */
    VALIDSTEP       = 0x0004,      /* The bounds contain a valid step value */
}bounds_flags_en;
typedef char bounds_flags_et;

#define IsLowerUnbounded(flags) ( (((flags) & LOWERUNBOUNDED) > 0) )
#define setLowerUnbounded(flags) ( (flags) |= LOWERUNBOUNDED )
#define clearLowerUnbounded(flags) ( (flags) &= ~LOWERUNBOUNDED )

#define IsUpperUnbounded(flags) ( (((flags) & UPPERUNBOUNDED) > 0) )
#define setUpperUnbounded(flags) ( (flags) |= UPPERUNBOUNDED )
#define clearUpperUnbounded(flags) ( (flags) &= ~UPPERUNBOUNDED )

#define IsValidStep(flags) ( (((flags) & VALIDSTEP) > 0) )
#define setValidStep(flags) ( (flags) |= VALIDSTEP )
#define clearValidStep(flags) ( (flags) &= ~VALIDSTEP )

typedef struct bounds_ext_t
{
    int lowerBound;
    int upperBound;
    int step;
    bounds_flags_et boundsFlags;
} bounds_ext_t;
/*<-- DR173858-cl186009-01*/

typedef struct array_info_t
{
    int numDimensions;
    int totalNumElements;
    element_info_t elementInfo;
} array_info_t;

                                            /* DR114759-ap186032-01-> */
/* Add 14.10 version. Names will be of FNC_MAXNAMELEN_EON size */
typedef struct element_info_eon_t
{
    dtype_et data_type;
    SMALLINT udt_indicator;
    CHARACTER udt_type_name[FNC_MAXNAMELEN_EON];
    INTEGER    max_length;
    SMALLINT total_interval_digits;
    SMALLINT num_fractional_digits;
    charset_et charset_code;
    period_et period_type ;     /* BEGIN/END data type if PERIOD type */ /* DR124416-jr185066-01 */
} element_info_eon_t;

typedef struct array_info_eon_t
{
    int numDimensions;
    int totalNumElements;
    element_info_eon_t elementInfo;
    boolean_t default_null;         /* DR124416-es200014-01 */
} array_info_eon_t;

void
FNC_GetArrayTypeInfo_EON(   ARRAY_HANDLE         aryHandle,
                            array_info_eon_t    *arrayInfo,
                            bounds_t            *arrayScope);
                                            /* <-DR114759-ap186032-01 */
void
FNC_GetArrayNumDimensions(  ARRAY_HANDLE    aryHandle,
                            int*            numDimensions);

void
FNC_GetArrayElementCount(   ARRAY_HANDLE    aryHandle,
                            int*            presentElts,
                            int             lastPresentElement[]);
void
FNC_GetArrayTypeInfo(   ARRAY_HANDLE    aryHandle,
                        array_info_t    *arrayInfo,
                        bounds_t        *arrayScope);


int
FNC_SetNullBitVector(   NullBitVecType  *NullBitVector,
                        int             indexValue,
                        int             presenceValue,
                        long            bufSize);
int
FNC_SetNullBitVectorByElemIndex(   NullBitVecType  *NullBitVector,
                        int             indexValue[],
                        int             presenceValue,
                        long            bufSize,
                        bounds_t*       arrayScope,
                        int             numDimensions);
int
FNC_CheckNullBitVector( NullBitVecType  *NullBitVector,
                        int             indexValue,
                        long            bufSize);
int
FNC_CheckNullBitVectorByElemIndex( NullBitVecType  *NullBitVector,
                        int             indexValue[],
                        long            bufSize,
                        bounds_t*       arrayScope,
                        int             numDimensions);
void
FNC_GetArrayElements(   ARRAY_HANDLE    aryHandle,
                        bounds_t*       arrayInterval,
                        void*           returnValue,
                        long            returnValueBufSize,
                        NullBitVecType  *nullBitVec,
                        long            nullBitVecBufSize,
                        long*           length);
void  
FNC_SetArrayElements(   ARRAY_HANDLE    aryHandle,
                        bounds_t*       arrayInterval,
                        void*           newValues,
                        int             nullIndicator,
                        long            length);

void  
FNC_SetArrayElementsWithMultiValues(   ARRAY_HANDLE    aryHandle,
                            bounds_t*       arrayInterval,
                            void*           newValues, 
                            long            newValuesBufSize,
                            NullBitVecType  *nullBitVec,
                            long            nullBitVecBufSize);

void
FNC_GetUDTHandles(ARRAY_HANDLE aryHandle,
                        int 	numHandles,
                        void* 	returnValue,
                        long 	bufSize);

/*DR157674-cl186009-01 -->*/
void
FNC_GetJSONInfo(JSON_HANDLE   jsonHandle,
                int*          maxLength,
                charset_et*   charSet,
                int*          numLobs);

                                                  /* DR171210-yh186003-01 -> */
void
FNC_GetExtendedJSONInfo(JSON_HANDLE         jsonHandle,
                        int*                inlineLength,
                        int*                maxLength,
                        charset_et*         charSet,
                        int*                numLobs,
                        json_storage_et*    storageFmt); /*DR124416-ml186063-01*/
                                                  /* <- DR171210-yh186003-01 */

void
FNC_GetJSONInputLob( JSON_HANDLE     jsonHandle,
                     LOB_LOCATOR*    object );

void
FNC_GetJSONResultLob( JSON_HANDLE            jsonHandle,
                      LOB_RESULT_LOCATOR*    object );
/*<-- DR157674-cl186009-01*/

/* DR173858-kv121476-01-> */
typedef enum dataset_schema_encoding_en
{
    datasetSchemaUTF8 = 0,
    datasetSchemaUTF16 = 1
} dataset_schema_encoding_en;

typedef BYTE dataset_schema_encoding_t;

typedef enum dataset_storage_en
{
    DATASET_INVALID_EN = -1,
    DATASET_Avro_EN = 0,
    DATASET_CSV_EN = 1             /* DR181519-kv121476-01 */
} dataset_storage_en;

typedef BYTE dataset_storage_et;
/* <-DR173858-kv121476-01 */

/*DR173858-cl186009-01 -->*/
void
FNC_GetDatasetInfo(DATASET_HANDLE datasetHandle, int* maxLength,
                   int* inLineLength, int *schemaLength,
                   int *rawDataLength, dataset_storage_et* storageFormat,
                   boolean_t *dataLob, boolean_t *schemaLob);

void
FNC_GetDatasetSchema(DATASET_HANDLE datasetHandle, void* schemaBuf,
                     int schemaBufLen, int* actualSchemaLength,
                     dataset_schema_encoding_t schemaEncoding);

void
FNC_GetDatasetSchemaLob(DATASET_HANDLE datasetHandle,
                             LOB_LOCATOR* object,
                             dataset_schema_encoding_t schemaEncoding);

void
FNC_GetDatasetInputLob(DATASET_HANDLE datasetHandle, LOB_LOCATOR* object);

void
FNC_GetDatasetResultLob(DATASET_HANDLE datasetHandle, LOB_RESULT_LOCATOR* object);

void
FNC_SetDatasetLob(DATASET_HANDLE datasetHandle, LOB_LOCATOR datasetLob);
/*<-- DR173858-cl186009-01*/

/* DR168601-kv121476-01-> */
int
FNC_UdtSerializeSupported(UDT_HANDLE udtHandle);

FNC_LobLength_t
FNC_UdtGetSerializeSize(UDT_HANDLE udtHandle);

int
FNC_UdtSerialize(UDT_HANDLE      udtHandle,
                 BYTE*           buffer,
                 FNC_LobLength_t num_bytes,
		 FNC_LobLength_t *actual_length);

int
FNC_UdtDeserialize(UDT_HANDLE      udtHandle,
                   BYTE*           buffer,
                   FNC_LobLength_t data_length);
/* <-DR168601-kv121476-01 */

/* DR124416-kv121476-01-> */
void
FNC_GetGeometryInfo(GEO_HANDLE geoHandle,
                    FNC_GeomSize_t *maxLength,
                    int *numLobs);

FNC_GeomSize_t
FNC_GeomGetWKTSize(GEO_HANDLE geoHandle);

FNC_GeomSize_t
FNC_GeomGetWKBSize(GEO_HANDLE geoHandle);

void
FNC_GeomGetWKT(GEO_HANDLE     geoHandle,
               unsigned char *wktBuffer,
               FNC_GeomSize_t wktBufferSize,
               FNC_GeomSize_t *wktSize,
               int            *srid);

void
FNC_GeomSetWKT(GEO_HANDLE     geoHandle,
               unsigned char *wkt,
               FNC_GeomSize_t wktSize,
               int            srid);

void
FNC_GeomGetWKTClob(GEO_HANDLE     geoHandle,
                   LOB_LOCATOR   *geoClob,
                   int           *srid);

void
FNC_GeomGetResultWKTClob(GEO_HANDLE          geoHandle,
                         LOB_RESULT_LOCATOR *geoClob);

void
FNC_GeomSetWKTClob(GEO_HANDLE         geoHandle,
                   LOB_RESULT_LOCATOR geoClob,
                   int                srid);

void
FNC_GeomGetWKB(GEO_HANDLE     geoHandle,
               BYTE          *wkbBuffer,
               FNC_GeomSize_t wkbBufferSize,
               FNC_GeomSize_t *wkbSize,
               int            *srid);

void
FNC_GeomSetWKB(GEO_HANDLE     geoHandle,
               BYTE          *wktb,
               FNC_GeomSize_t wkbize,
               int            srid);

void
FNC_GeomGetWKBBlob(GEO_HANDLE     geoHandle,
                   LOB_LOCATOR   *geoBlob,
                   int            *srid);

void
FNC_GeomGetResultWKBBlob(GEO_HANDLE          geoHandle,
                         LOB_RESULT_LOCATOR *geoBlob);

void
FNC_GeomSetWKBBlob(GEO_HANDLE         geoHandle,
                   LOB_RESULT_LOCATOR geoBlob,
                   int                srid);

void
FNC_MBRGetValue(GEO_HANDLE mbrHandle,
                double    *mbrBuffer,
                int       *mbrSize);

void
FNC_MBRSetValue(GEO_HANDLE mbrHandle,
                double    *mbrValue);

void
FNC_MBBGetValue(GEO_HANDLE mbbHandle,
                double    *mbbBuffer,
                int       *mbbSize);

void
FNC_MBBSetValue(GEO_HANDLE mbbHandle,
                double    *mbbValue);

void
FNC_GetXMLInfo(XML_HANDLE xmlHandle,
               FNC_XMLSize_t *maxLength,
               int *numLobs);

void
FNC_GetXML(XML_HANDLE      xmlHandle,
           unsigned char  *xmlBuffer,
           int             xmlBufferSize,
           int            *xmlSize);

void
FNC_SetXML(XML_HANDLE     xmlHandle,
           unsigned char *xmlBuffer,
           int            xmlSize);

void
FNC_GetXMLClob(XML_HANDLE   xmlHandle,
               LOB_LOCATOR *xmlClob);

void
FNC_GetXMLResultClob(XML_HANDLE          xmlHandle,
                     LOB_RESULT_LOCATOR *xmlClob);

void
FNC_SetXMLClob(XML_HANDLE         xmlHandle,
               LOB_RESULT_LOCATOR xmlClob);

void
FNC_GetXMLBlob(XML_HANDLE   xmlHandle,
               LOB_LOCATOR *xmlBlob);

void
FNC_GetXMLResultBlob(XML_HANDLE          xmlHandle,
                     LOB_RESULT_LOCATOR *xmlBlob);

void
FNC_SetXMLBlob(XML_HANDLE         xmlHandle,
               LOB_RESULT_LOCATOR xmlBlob);

void
FNC_GetXMLByte(XML_HANDLE      xmlHandle,
               unsigned char  *xmlBuffer,
               int             xmlBufferSize,
               int            *xmlSize);

void
FNC_SetXMLByte(XML_HANDLE     xmlHandle,
               unsigned char *xmlBuffer,
               int            xmlSize);
/* <-DR124416-kv121476-01 */

/* DR144953-ME186004-01 -->>
   FNC functions to support table operators
*/ 


typedef CHARACTER names_t[FNC_MAXNAMELEN_EON];

/*
 * Schema of an attribute
 */
typedef struct
{
    dtype_et datatype;            // data type, for udt transforms result type
    CHARACTER column[FNC_MAXNAMELEN_EON];
    CHARACTER udt_type[FNC_MAXNAMELEN_EON];
    BYTE padbyte;                              /* DR168816-cl186009-01 */
    json_storage_et JSONStorageFormat;             /* DR168816-cl186009-01 */ /*DR173858-cl186009-01*/
    charset_et charset;
    period_en period_et;         
    int bytesize ;       
    union {
        long length;
        int intervalrange;
        int precision;
        struct {
            int totaldigit;
            int fracdigit;
        } range;
    } size;
} parm_tx;
/*
   Fields:
   datatype: data type of attribute (e.g., INTEGER_DT)
   column_name: name of the column
   udt_type_name: name of the UDT
   charset:  character set (e.g., UNICODE). applicable to character types
   period_et: granularity of period type, date/timestamp etc.
   bytesize: maximum size of fixed length fields
   size: fields to determine the size
    length: length in CHAR/VARCHAR/BYTE/GRAPHIC types
    intervalrange: range for interval types (e.g. 4 in INTERVAL YEAR(4))
    precision: precision for time/timestamp types (e.g. 4 in TIMES(4) and 6 in TIMESTAMP(6)
    range: determine the size of DECIMAL types
        totaldigit: total number of digits (i.e. n in DECIMAL(n, m))
        fracdigit: digits in the fraction portion (i.e. m in DECIMAL(n, m))
*/
/*DR144953-vt186001-01 ->>*/
#define MAX_KEY_SIZE FNC_MAXNAMELEN_EON

typedef struct{
    int        valueLen;     //size of value
    BYTE    *value;         //Pointer to the actual value
} Values_t;

typedef struct{
    int              numOfVal;                    //number of values this key has
    int              totalValSize;                  //total size of values in number of bytes
    size_t           keySize;                   //key size
    parm_tx      valType;                       //Type of values
    Values_t      *values_r;                     //array of values
    CHARACTER     key[FNC_MAXNAMELEN_EON];
} Key_info_t;

                                        /*<<- DR144953-vt186001-01*/

/*
 * Column definitions of a stream
 */
typedef struct
{
  int length;                   // size of data structure - 2 * sizeof(int)
  int num_columns;
  parm_tx column_types[1];      
} FNC_TblOpColumnDef_t;
/*
 The size of this structure depends on the number of attributes in the table 
 Fields
   length: number of bytes representing column types 
   num_column: number of columns in table
   column_types: an array of column types, one for each column. 
*/

/* DR144953-mw125167-01-->*/
/*
 * current record structure
 */
typedef struct {
   int length;
   short flavor;           
   BYTE *indicators;     
   BYTE **columnptr;    
   int  *lengths;       
   BYTE *body;        
} current_row_t;
/* Fields
   length: number of bytes in body   
   flavor: record type of body, matches parcel flavors
   indicators: a pointer to NULL indicators for fields in current record
   columnptr[0],..., columnptr[n-1]: pointers to values of attributes 0..n-1
   lenghts[0],..., lengths[n-1]: lenght of values of attributes 0..n-1
   body: pointer to record body   
*/
/* DR144953-mw125167-01-->*/
typedef enum
{
    ISOUTPUT = 'W',
    ISINPUT = 'R'
} Stream_Direction_en;
typedef enum                                              
{
    ISINIT = 1,         
    ISOPEN = 2,  
    ISCLOSE = 3
}  Stream_State_en;
/*<-- DR144953-mw125167-01*/

/*
 * A handle to a stream context.
 */
/* DR144953-mw125167-01-->*/
typedef struct {   
     int streamno;                 
     current_row_t  *row;            
     Stream_Direction_en direction;    
     unsigned int options;
     Stream_State_en state;          
} FNC_TblOpHandle_t;
/*<-- DR144953-mw125167-01*/
/* Fields
   streamno:  stream number
   row:       a pointer to a record with information of current row
   direction: whether the context is for an input or output stream 
   options:   open options
   state:     stream state
*/

/* DR162287-db186031-01->> */
typedef struct {
    void        *data;
    parm_tx      type;
} FNC_HashRow_t;
/* <<-DR162287-db186031-01 */


#define TblOpSIZECOLDEF(colcount)  (sizeof(parm_tx)*colcount + 2*sizeof(int))
#define TblOpINITCOLDEF(coldef, colcount) if (coldef != NULL) {coldef->num_columns = colcount; coldef->length = sizeof(parm_tx)*colcount; memset(coldef->column_types,0,coldef->length);}
#define TblOpSIZEORDERBY(colcount)  ( sizeof(int) + 1 + colcount * sizeof(names_t) )
#define TblOpSIZEHASHBY(colcount)   ( sizeof(int) + colcount * sizeof(names_t) )
/*
   FNC_TblOpGetColCount

   This function retrieves the number of columns in the stream

   Input parameters: stream number and directiion

   Return value: column count
*/
int 
FNC_TblOpGetColCount(int streamno, Stream_Direction_en direction);

/*
   FNC_TblOpGetColDef

   This function retrieves  column definitions of the stream specified in input parameters

   Input parameters: stream number and direction and location where column definitions will be returned

*/
extern void FNC_TblOpGetColDef(int streamno, 
                               Stream_Direction_en direction,
                               FNC_TblOpColumnDef_t *coldef);

/*
 sequence of column names
*/
typedef struct
{
  int number;        // number of column names
  names_t names[1];  // array of column names
} FNC_Names_t;
/*
 This data structure has variable size. Its size depends on the number of column names
*/

/* DR161950-vt186001-01 ->>*/
/*
 This structure represents a column name with the corresponding orders.
 */
typedef struct
{
   int       length;
   BYTE      direction;
   BYTE      nullspec;
   CHARACTER name[FNC_MAXNAMELEN_EON];
} names_ord_t;
/*
 FIELDS
 --------------
 length:    The length of the name.
 direction: The order of the values of this column, which can be descending or ascending.
 nullspec:  The order of the null values of this column, which can be first or last.
 name:      The name of the column.
 */
/*<<- DR161950-vt186001-01*/

/*
 sequence of column names with order
 */
typedef struct
{
  int     number;    // number of column names
  names_ord_t col[1];  /*  DR161950-vt186001-01
                           array of name-order-nulltype triplets 
                        */
} FNC_Names_Ord_t;
/*
 This data structure has variable size. Its size depends on the number of column names
*/

/*
   FNC_TblOpGetCountHashByDef
   
   This function retrieves the number of columns in HASH-BY clause associated with input stream <streamno>
*/
extern short FNC_TblOpGetCountHashByDef(int streamno);

/*
   FNC_TblOpGetCountLocalOrderByDef
   
   This function retrieves the number of columns in LOCAL-ORDER-BY clause associated with input stream <streamno>
*/
extern short FNC_TblOpGetCountLocalOrderByDef(int streamno);

/*
   FNC_TblOpGetHashByDef

   This function retrieves the hashby information for the input stream. The caller is responsible 
   for allocating memory for hashby information in out_colname.

   Input parameters: stream number, 
                     a pointer out_colname where column names will be stored. 
*/
extern void FNC_TblOpGetHashByDef(int streamno, 
                           FNC_Names_t *colNames);

/*
   FNC_TblOpGetLocalOrderByDef

   This function retrieves the local order by information for the input table. The caller is 
   responsible for allocating memory for local-order-by information in out_colname.

   Input parameters: : stream number, 
                       a pointer out_colname where column names and its ordering will be stored

*/
extern void FNC_TblOpGetLocalOrderByDef(int streamno, 
                                 FNC_Names_Ord_t *colNames);

/*
   FNC_TblOpSetHashByDef

   Allow contract function writer to set the hash by specification. It is a PE only function

   Input parameters: stream number,
                     a pointer to a structure with HASH BY metadata
*/
extern void FNC_TblOpSetHashByDef(int streamno, 
                                  FNC_Names_t *colNames);

/*
   FNC_TblOpSetLocalOrderByDef

   Allow contract function writer to set the ordering specifications.

   Input parameters: stream number,  
                     a pointer to a structure with LOCAL ORDER BY metadata. 
*/
extern void FNC_TblOpSetLocalOrderByDef(int streamno, 
                                 FNC_Names_Ord_t *colNames);

/*
  FNC_TblOpSetOutputColDef

  FNC_TblOpSetOutputColDefs is used to communicate the output columns of the output table to 
  the parser. If both the parser contract function and an explicit column definition list are 
  specified calling this function will set an error. It is an error to not set all of the 
  FNC_TblOpColumeDef_t fields, e.g. columne_name. 

  Input parameters: stream number, and 
                    the columns definition.
*/
extern void FNC_TblOpSetOutputColDef(int streamno, 
                                     FNC_TblOpColumnDef_t *coldefs);

/*
   FNC_TblOpSetContractDef 

   This function is used to set an opaque binary string value that the contract function passes 
   to the associated table operator at execution time

   Input parameters: A binary string representing the contract function context (ContractBuf) and 
                     its size (BufSize)

*/
extern void FNC_TblOpSetContractDef (void *ContractBuf, 
                                     int BufSize);

/*
   FNC_TblOpGetContractLength

   Retrieve the length of contract context.
*/
extern int FNC_TblOpGetContractLength();

/*
   FNC_TblOpGetContractDef

   Retrieve the contract context

   Input parameters: A pointer which will be set to the contract function context area and 
                     the size of the contract context.
*/
extern void FNC_TblOpGetContractDef (void *ContractBuf, 
                                     int inContractLen,
                                     int *outContractLen );
typedef enum                                            
{
    INDICFMT1 = 1,        /* Indicdata with row separator sentinels*/
    INDICBUFFMT1 = 2      /* Indicdata with NO row or partition separator sentinels */
} Stream_Fmt_en;

#define FMTAUXINFOLEN 128

/*
   FNC_TblOpSetFormat

   This function is used to set the format of the input and output streams
   Input parameters: format attribute to be set: "RECFMT"
                     stream number
                     direction of stream
                     new format attribute value.
*/
extern void FNC_TblOpSetFormat (char *attribute,
                           int streamno, 
                           Stream_Direction_en direction,
                           void *inValue,
                           int inSize);

/*
  FNC_TblOpGetFormat

  Returns the default format or the format set in the contract function by calling FNC_TblOpSetFormat.

  Input parameter: attribute name, stream number, direction of stream, address where attribute value will be placed
                   and length of attribute value.

  Output value: a pointer to a structure with a specification of the format
*/
extern void FNC_TblOpGetFormat (char *attribute,
                                int streamno, 
                                Stream_Direction_en direction,
                                void *outValue,
                                int outSize);

/*
   FNC_TblOpSetError

   FNC call to set the SQLSTATE and detailed error message information.

   Input parameters: A handle to a stream context where the error code and message would be placed, 
                     an error code (SQLState), and
                     a message
*/
extern void FNC_TblOpSetError(//FNC_TblOpHandle_t *Handle, 
                              char *SQLState, 
                              char *Message); 

/*
   FNC_TblOpGetFunctioDef

   Access calling operator information.

   Input parameters: Pointer to a buffer where name of the table operator will be returned, 
                     the length of this buffer,
                     pointer to memory location where the execution mode will be returned, 
                     pointer to memory location where the character set will be returned, and 
                     pointer to memory location where the case sensitivity of the operator will be returned
*/
extern void FNC_TblOpGetFunctionDef(char *fnameBuff, 
                                    int fnameBuff_len,
                                    BYTE *execmode, 
                                    unsigned short int *chartype, 
                                    boolean_t *casesensitivity);

/*
   FNC_TblOpGetStreamCount

   Get the number of input and output streams passed to the table operator

   Input parameters: pointer to integers where the number of input streams will be stored and
                     pointer to integers where the number of output streams will be stored
*/
extern void FNC_TblOpGetStreamCount(int* in_count, int* out_count);

/*
   FNC_TblOpOpen

   Initializes stream number streamno iterator interface for reading or writing, based on 
   mode value

   Input parameters: Index of stream associated with handle in array of streams (istream or ostream) of table operator context, 
                     mode of stream (R or W), and 
                     whether read calls would prepare field access by setting the pointers to have direct access to individual attributes

   Output value: a pointer to the Handle_t or NULL if error.
  
*/
extern FNC_TblOpHandle_t *FNC_TblOpOpen(int streamno, 
                                        char mode,
                                        unsigned int options);

/*
   FNC_TblOpRead

   Sets read context to next input row of data

   Input parameter: A handle associated with an input stream

   Output value: return SUCCESS,  EOF (no more data), ABORT or ERROR. 
*/
extern int FNC_TblOpRead(FNC_TblOpHandle_t *handle);

/*
   FNC_TblOpGetAttributeByNdx

   Access a specific input attribute value

   Input parameters: a handle to an input stream, 
                     the index of the attribute value to be retrieved, ranging from 0 to i-1 
                        where i is the total number of attributes,
                     pointer to the location of the attribute value,
                     pointer to the null indicator, and 
                     pointer to the actual length in bytes of the value to be returned. 
                        For character varying data types, the length includes the 2 byte length field.
  
*/
extern int FNC_TblOpGetAttributeByNdx(FNC_TblOpHandle_t *handle,
                                      int  index, 
                                      void **valueptr, 
                                      int  *null_ind, 
                                      int  *length); 

/*
   FNC_TblOpBindAttributeByNdx

   This function sets an attribute value of a current row in the output stream associated with a handle

   Input Parameters: The handle to an output stream, 
                     the index of the attribute value to be set 
                        (ranging from 0 to i-1 where i is the total number of attributes),
                     a pointer to location of attribute value, 
                     a pointer to an interger where null indicator will be set, and
                     a pointer to the length in bytes of the value. 
                        For character varying data types, the length includes the 2 byte length field. 

*/
extern int FNC_TblOpBindAttributeByNdx(FNC_TblOpHandle_t *handle, 
                                      int index, 
                                      void *valueptr, 
                                      int null_ind, 
                                      int length);

/*
   FNC_TblOpWrite

   Writes current output data to spool and sets output context to the next output row

   Input parameter: a handle returned from FNC_TblOpOpen.

   Output value: return SUCCESS, NOROW or ABORT
*/
extern int FNC_TblOpWrite(FNC_TblOpHandle_t *handle);

/*
   FNC_TblOpClose

   Closes and flushes the data to the DBS

   Input parameter: The handle associated with a stream

   Output value: returns SUCCESS, or TBLOP_ERROR.
*/
extern int FNC_TblOpClose(FNC_TblOpHandle_t *handle);

/*
   FNC_TblOpReadBuf

   Routine to handle reading a data buffer. If the buffer is empty, the
   call blocks after requesting DBS to fill the buffer with more data,
   and then point to the location of the buffer.

   Input parameters:
       bufptr - pointer to the location of the data buffer
       length   - pointer to the actual length in bytes of the buffer pointed to by bufptr
                  to be returned.

   Output value: return SUCCESS,  EOF (no more data), ABORT or ERROR.
*/
extern int FNC_TblOpReadBuf(BYTE **bufptr, int *length);

/*
  FNC_TblOpWriteBuf

  Routine to handle writing a data buffer. If the shared buffer is
  full, the call blocks after requesting DBS to empty the buffer,
  and then put the data into the shared buffer for writing.

  Input parameters:
       bufptr - pointer to the data buffer to be written
       length - the actual length in bytes of the input buffer to be written

   Output value: return SUCCESS, ABORT, or ERROR
*/
extern int FNC_TblOpWriteBuf (BYTE *bufptr, int length );

/*
   FNC_LobOpen_CL
   
   This function establishes a read context for subsequent sequential reads of a large object.

   Input parameters: A client locator, 
                     a context identifier, 
                     the starting byte offset, relative to 0, for the read operation, and 
                     the maximum number of bytes to read.

   Output value: The length of of data stream.
*/
extern FNC_LobLength_t FNC_LobOpen_CL (void *locator,
                                       LOB_CONTEXT_ID  *ctxid, 
                                       FNC_LobLength_t start,
                                       FNC_LobLength_t maxlength);                                                                                                  

/*
   FNC_GetLobLength_CL
   
   This function gets the length of an input LOB

   Input parameters: A client locator, 

   Output value: The length of lob.
*/
extern FNC_LobLength_t FNC_GetLobLength_CL( void *locator );

/*
   FNC_LobCol2Loc

   This function generates the locator of an output LOB which can be passed as input parameter
   to routines FNC_LobAppend and FNC_LobCopy.

   Input parameter: Stream number (0, 1, ...)
                    Column position of output LOB in stream (0, 1, ...)   

   Output value: Locator of output LOB.
*/
extern LOB_RESULT_LOCATOR FNC_LobCol2Loc(int streamno, int columnnr);

// <<-- DR144953-ME186004-01

/* DR144953-vt186001-01 ->>*/
/***********************************************************
 FNC_TblOpGetCustomKeyCount();

 Retrieves the number of name-value pairs in the custom clause of the
 Table Operator function

 Input:      None.
 Output:   The number of name-value pairs.
 
 ***********************************************************/
extern int FNC_TblOpGetCustomKeyCount();


/***********************************************************
 FNC_TblOpGetCustomKeyInfoOf(void *key, Key_info_t *return_info);

 Retrieves the number of values associated with key, their total size in bytes,
 and their type.

 Input:      The key whose info to be retrieved.
                A buffer to store the key info to be returned.

 Output:   0 or 1 to indicate success or failure, respectively.
 
 ***********************************************************/
extern int FNC_TblOpGetCustomKeyInfoOf(void *key, Key_info_t *return_info);

typedef struct FNC_conn_supp
{
   short isStaticPlanInputAvailable;
   short isDelayedFetchAvailable;
   CHARACTER textGeneratorlibrary[384];
   CHARACTER textGeneratorFunc[384];
   CHARACTER RemoteDBName[384];                /*DR185415-dm186017-01*/
} FNC_conn_supp;

                                                    /*DR185415-dm186017-01->*/
typedef struct FNC_conn_properties
{
    int HostType;
}FNC_conn_properties;
                                                    /*<-DR185415-dm186017-01*/
typedef struct qrw_stats_t
{
        FLOAT rowCount;
        FLOAT rowSize;
        short int cnfLvl;
        FLOAT elapsedSecs;
} qrw_stats_t;


typedef struct FNC_qrw_stats_t
{
        int qryCnt;
        qrw_stats_t QS[1];
} FNC_qrw_stats_t;                                  /*-------DR177116-rv186022-01*/

                                   /* DR180417-sd186032-01 -> */
typedef struct FNC_tblop_stats_t
{
        int qryCnt;
        qrw_stats_t QS[1];
} FNC_tblop_stats_t;
extern void FNC_TblOpSetStats(FNC_tblop_stats_t *qrw_stats);
                                   /* <- DR180417-sd186032-01 */


extern void FNC_TblOpSetStaticStats(FNC_qrw_stats_t *qrw_stats);
extern void FNC_TblOpSetConnSupp(FNC_conn_supp *connCapabilities);


                                                    /*DR177116-jt186040-01->*/
typedef struct FNC_TblOpDynamicStats {
    qrw_stats_t QS; // Contains the stats from delayed fetch. Only required fields will be populated.
}FNC_TblOpDynamicStats;

extern void FNC_TblOpSetDynamicStats(int strno,FNC_TblOpDynamicStats *dyn_stats);

/*DR185415-dm186017-01 QGOrideText should be same as QRYBANDMAXLEN*/
typedef struct FNC_OverrideTextType
{
  int       QGOrideTextLen;
  CHARACTER QGOrideText[4096];                   /*DR185415-dm186017-01*/
}FNC_OverrideTextType;

extern void FNC_TblOpGetOverride(FNC_OverrideTextType *QGOrideTextNode);

                                                    /*<-DR177116-jt186040-01*/
extern void FNC_TblopSetBufSize(signed int bufsize);  /*DR181816-sd186032-01*/
/***********************************************************
 FNC_TblOpGetCustomKeyInfoAt(int index, Key_info_t *return_info);

 Retrieves the number of values associated with the key at the specified index, 
 their total size in bytes, and their type.

 Input:      The index of the key whose info is to be retrieved.
                A buffer to store the key info to be returned.

 Output:   0 or 1 to indicate success or failure, respectively.
 
 ***********************************************************/
extern int FNC_TblOpGetCustomKeyInfoAt(int index, Key_info_t *return_info);


/***********************************************************
 FNC_TblOpGetCustomValuesOf(Key_info_t *key);

 Retrieves the values associated with the key stored inside key.

 Input:      The key structure containing the key whose values are to be retrieved.

 Output:   0 or 1 to indicate success or failure, respectively.
 
 ***********************************************************/
extern int FNC_TblOpGetCustomValuesOf(Key_info_t *key);

/* <<- DR144953-vt186001-01*/
                                            /* DR114759-ap186032-01-> */
/* To convert a UTF-8 name to UTF-16 */
extern
void
FNC_ConvertNameToUnicode(char *SrcName, unsigned short  *DstName, unsigned short *DstLen);
                                            /* <-DR114759-ap186032-01 */
                                               /* --> DR159751-jr185066-01 */
/***********************************************************
 int FNC_TblOpIsDimension(int streamno, Stream_Direction_en direction)

 Returns 1 if the table operator input stream is a DIMENSION input. 0 otherwise.

 Input:   Stream number and stream direction.

 Output:  0 or 1.

 ***********************************************************/
extern int FNC_TblOpIsDimension(int streamno, Stream_Direction_en direction);


/***********************************************************
 void FNC_TblOpGetAsClauseName(int streamno, Stream_Direction_en direction ,char* AsNamePtr, int buflen, int* namelen)

 - Retreives the alias name (As Name) associated with a particular input stream.

 Inputs:   Stream direction and stream number.
           AsName Buffer to hold the alias name, buffer length.
           namelen buffer to hold the actual name length. 

 Output:  None. The AsName and namelen buffer are filled with the alias name and length, if any.

 ***********************************************************/
extern void FNC_TblOpGetAsClauseName(int streamno, Stream_Direction_en direction,char* AsNamePtr, int buflen, int* namelen);

/*
   FNC_TblOpReadBufEx

   Routine to handle reading a data buffer. If the buffer is empty, the
   call blocks after requesting DBS to fill the buffer with more data,
   and then point to the location of the buffer.
   Same as FNC_TblOpReadBuf, except this one takes the input stream handle
   as a parameter. So it can handle multiple input streams.

   Input parameters:
       handle - handle to input stream.
       bufptr - pointer to the location of the data buffer
       length   - pointer to the actual length in bytes of the buffer pointed to by bufptr
                  to be returned.

   Output value: return SUCCESS,  EOF (no more data), ABORT or ERROR.
*/
extern int FNC_TblOpReadBufEx(FNC_TblOpHandle_t *handle, BYTE **bufptr, int *length);

                                            /* <-- DR159751-jr185066-01 */

                                                  /*DR168146-jz186002-01 --->*/
typedef enum
{
    ANSISQL = 1,
    HADOOP = 2
} serverType_et;

typedef int ServerType;
                                                  /*<--- DR168146-jz186002-01*/

                                                  /*DR162287-jz186002-01 --->*/
/*DR172069-pa180002-01 Add Overlaps and IsNULL*/
/*DR173284-pa180002-01 Adding more scalar functions*/
typedef enum
{
    Eq_ET,
    Ne_ET,
    Gt_ET,
    Le_ET,
    Lt_ET,
    And_ET,
    Or_ET,
    Not_ET,
    Between_ET,
    In_ET,
    NotIn_ET,
    Ge_ET,
    Like_ET,
    Overlaps_ET,
    IsNULL_ET,
    CurrTime_ET,
    CurrTimestamp_ET,
    CurrUser_ET,
    Case_ET,
    Cast_ET,
    WidthBucket_ET,
    Abs_ET,
    Mod_ET,
    Extract_ET,
    Ln_ET,
    Log_ET,
    Octet_Length_ET,
    Position_ET,
    Sqrt_ET,
    Concat_ET,
    Lower_ET,
    Upper_ET,
    Substring_ET,
    Trim_ET,
    AO_Plus_ET,
    AO_Minus_ET,
    AO_Mult_ET,
    AO_Div_ET
} extoptype_et;

typedef BYTE ExtOpType;
typedef long ExtOpSet;                                 /*DR173284-jz186002-01*/ 

typedef struct ExtOpSetType {
    ExtOpSet ExtOpSetList;
} ExtOpSetType;


/******************************************************************************
 FNC_TblOpGetExternalQuery

 This function generates the text of import query to be sent to remote server.

 Input:   colDefs          - list of column definitions that may occur in a 
                             WHERE conditional clause by the remote server.
          serverType       - 1 for ANSISQL, 2 for HDFS. For ANSISQL, the entire 
                             sub-query for the remote server's table is returned.
                             for HDFS, only the WHERE grammar is returned.
          condPtr          - set of valid operators allowed on remote server.
          interfaceVersion - interface version requested by the table operator. 

 Output:  extQryPtr        - Pointer to the generated text query string for the 
                             remote server. The query string is NULL-terminated.
          interfaceVersion - pointer to supported interface version.
          extQryLenPtr     - pointer to the length of external query (in bytes).

          Error handling is done inside the function.
 *****************************************************************************/

extern void FNC_TblOpGetExternalQuery(FNC_TblOpColumnDef_t  *colDefs,
                                      ServerType            serverType,
                                      ExtOpSetType          opSet,
                                      int                   *interfaceVersion,
                                      unsigned char         **extQryPtr,
                                      unsigned int          *extQryLenPtr);



/******************************************************************************
 FNC_TblOpSetInputColTypes

 This function sets casting statements on the input columns to cast types 
 as indicated by the caller.

 Input:   streamNo  - input stream number
          colDefs   - list of column definitions

 Output:  NONE. Error handling is done inside the function.
 *****************************************************************************/

extern void FNC_TblOpSetInputColTypes(int                   streamNo, 
                                      FNC_TblOpColumnDef_t  *colDefs);



/******************************************************************************
 FNC_TblOpSync

 This function provides synchronization among all AMPs to make sure they 
 reach the same point before performing further actions.

 Input:   None.
 Output:  return 1 if the caller is the last-done AMP, return 0 otherwise.
          Error handling is done inside the function.
 *****************************************************************************/

extern int FNC_TblOpSync();



/******************************************************************************
 FNC_TblOpSetDisplayLength

 This function resets the lengths in column definitions for varchar types using
 streamno and formatptr from ON clause tree. Invoked for both import and export.

 Input:   direction  - pass in ISINPUT for export; ISOUTPUT for import
          colDefs    - pointer to the column definitions

 Output:  colDefs    - pointer to the column definitions w. modified lengths.
 *****************************************************************************/

extern void FNC_TblOpSetDisplayLength(Stream_Direction_en    direction,
                                      FNC_TblOpColumnDef_t   *colDefs);



/******************************************************************************
 FNC_TblOpGetInnerContract

 This function gets contract definition of inner table operator in nested case.

 Input/Output:  innerContract - it will be allocated space inside the function,
                                and hold inner contract (not including length).
                                return NULL if inner contract doesn't exist.
 Output:        contractLen   - the length of the inner contract.
*****************************************************************************/

extern void FNC_TblOpGetInnerContract(void **innerContract, int *contractLen);



/******************************************************************************
 FNC_TblOpBytesTransferred

 This function records the number of bytes transferred between Teradata 
 and remote site by table operator.

 Input:   in  - the number of bytes transferred into Teradata from remote site.
          out - the number of bytes transferred from Teradata to remote site.
 
 Output:  NONE. Error handling is done inside the function.
 *****************************************************************************/

extern void FNC_TblOpBytesTransferred(unsigned long in, unsigned long out);



/******************************************************************************
 FNC_TblOpSetExplainText

 This function sets the explain text in TSeg when table operator has the
 hexplain custom clause set. It can accept multiple individually 
 self-contained explain texts.

 Input:   numOfTexts   - the number of individual explain texts.
          arrayOfTexts - the array of individual explain texts.
          arrayOfLens  - the array of length of each self-contained explain text.

 Output:  NONE. Error handling is done inside the function.
 *****************************************************************************/
                                                  /*DR169579-jz186002-01 --->*/
extern void FNC_TblOpSetExplainText(int numOfTexts, char **arrayOfTexts, int *arrayOfLens);
                                                  /*<--- DR169579-jz186002-01*/

                                                  /*<--- DR162287-jz186002-01*/


                                                  /*DR168146-jz186002-01 --->*/

/* A structure which contains the base info for a UDT. For example, for an array UDT,
   this structure will provide type info about the base element. */

typedef struct {
    SMALLINT      udt_indicator;     /* type of the UDT itself */
                                     /* 0=None 
                                       * 1=Array
                                       * 2=Structured
                                       * 3=JSON ENCODE AS TEXT
                                       * 4=Distinct
                                       * 5=PERIOD types
                                       * 6=XML
                                       * 7=ST_Geometry
                                       * 8=MBR
                                       * 9=MBB
                                       * 10=DATASET STORAGE FORMAT AVRO
                                       * 11=DATASET STORAGE FORMAT CSV */ /* DR176703-kv121476-01 *//*DR181519-kv121476-01*/
    int           array_numDimension;   /* the number of dimensions for array UDT */
    dtype_et      base_datatype;   /* for array UDT, this is the data type of each element */
    int           base_max_length;
    SMALLINT      base_total_interval_digits;
    SMALLINT      base_num_fractional_digits;
                                      /* --> DR124416-jr185066-01 */
    charset_et      base_charset;
    int             base_precision;
    json_storage_et json_storage_format;   /* JSON storage format
                                              (JSON/BSON)
                                            */
    int             struct_num_attributes; /* The number of attributes if
                                              a structured UDT
                                            */
    char            udt_name[FNC_MAXNAMELEN_EON]; /* Name of UDT */
    parm_tx         transform_info;     /* Describes the predefined data type 
                                         to which the UDT is mapped from/to.This
                                         cannot be another UDT type.  It could
                                         be either the UDTs transform type,
                                         or another type which is set by the
                                         Teradata Database.
                                       */
    array_info_eon_t  array_info;      /* Contains information about
                                         dimensions, total number elements,
                                         and element data type info
                                         for array
                                       */
    bounds_t        array_bounds[5];  /* Contains upper/lower bounds
                                         info for array_numDimension
                                      */
                                       /* <-- DR124416-jr185066-01 */
} UDT_BaseInfo_t;


/******************************************************************************
 FNC_TblOpGetBaseInfo
     
 This function examines each column in the parser tree, and gets the 
 info of base element if the type of the column is UDT. Curerently, it only 
 handles Array UDT. Will be extended for other UDTs later if needed.
         
 Input:   colDefs       - pointer to the column definitions
 Output:  baseInfo      - a list of UDT_BaseInfo_t, one for each column in colDefs
 *****************************************************************************/

extern void FNC_TblOpGetBaseInfo(FNC_TblOpColumnDef_t *colDefs, UDT_BaseInfo_t *baseInfo);

                                                  /*<--- DR168146-jz186002-01*/
                                                 /* --> DR124416-jr185066-01 */
/******************************************************************************
 FNC_TblOpGetUDTMetadata

 This function returns an array of UDT_BaseInfo_t structures that contain
 metadata information about input UDT columns. For non-UDT columns, the
 udt_indicator is set to 0.

  Input:   streamno      - Input stream number.
           direction     - Input or Output.
           columnno      - Column number for which UDT metadata is requested. If
                           set to -1, UDT Metadata will be returned for all
                           colums.
           bufSize       - Size of the udtbaseinfo buffer passed in.

  Output:  udtbaseInfo   - UDT_BaseInfo_t structure will metadata information
                           filled in. If user requests metadata for all input
                           columns, then the user must allocate sufficient
                           memory for all the columns.
  *****************************************************************************/

extern void FNC_TblOpGetUDTMetadata(int streamno ,
                                    Stream_Direction_en    direction,
                                    int columnno,
                                    int bufSize,
                                    UDT_BaseInfo_t *udtbaseInfo);


/******************************************************************************
 FNC_TblOpGetStructuredAttributeInfo

 This function returns an array of attribute_info_t structures that contain
 metadata information about Structured UDT attributes.

  Input:   udtName            -  Structured UDT Type name
           bufSize            -  Size of the attrInfo buffer passed in.

  Output:  attribute_info_t   -  Array of attribute_info_t structures that
                                 contain metadata info for the Structured UDT
                                 attributes.
 *****************************************************************************/

extern void FNC_TblOpGetStructuredAttributeInfo(unsigned char* udtName,
                                                int bufSize,
                                                attribute_info_t *attrInfo);
                                                  /* <-- DR124416-jr185066-01 */

                              
/* DR162287-db186031-01->> */
/***********************************************************
 FNC_TblOpGetContractPhase();

 Retrieves the value which indicates which phase in the parser the
 contract is being called from.

 Input:     None

 Output:    FNC_CTRCT_GET_ALLCOLS_PHASE = 0:
            This indicates all columns for the remote table are to be returned.

            FNC_CTRCT_VALIDATE_PHASE = 1:
            Validate that the given inputs are correct.  Callable multiple times.

            FNC_CTRCT_COMPLETE_PHASE = 2:
            This indicates the last call of the contract and that any remote server
            actions that are to be done once are to be completed.

            FNC_CTRCT_DDL_PHASE = 3:
            This indicates a create server is being completed and the connectivity
            should be verified.

            FNC_CTRCT_DEFINE_SERVER_PHASE = 4:
            This indicates a create view or create macro is being executed
            and that the custom clause data may not be valid.
 **********************************************************/

extern int FNC_TblOpGetContractPhase();

/**********************************************************
FNC_GetHashAmp(FNC_HashRow_t *data, int size, int *retCode);

Invokes the Teradata routine to determine the AMP that would be responsible
for that key.

Input:      FNC_HashRow_t *data -- Pointer to array of structures representing table columns
            int size            -- The size of the data and return arrays
            int *retCode        -- retCode holds an integer value to indicate success or an error number

Output:     returns the amp id that corresponds to the hashed row

 *********************************************************/

extern int FNC_GetHashAmp(FNC_HashRow_t *data, int size, int *retCode);

/**********************************************************
FNC_GetAmpHash(int **amphash, int size);

Returns values that hash to the amps specified.

Input:      int **amphash -- amphash[n][0] is the amp number and amphash[n][1] is the value that hashes to it
            int size      -- the size (n) of the amphash array

Output:     values that hash to the amps, stored in [n][1] of the amphash array

 *********************************************************/

extern void FNC_GetAmpHash(int **amphash, int size);

/**********************************************************
FNC_SetActivityCount(int Stream, long rowsexported);

Sets the number of rows exported

Input:      int Stream          -- specifies which stream to write to
            long rowsexported   -- the value to be written to ActivityCount

Output:     void

 *********************************************************/
 
extern void FNC_SetActivityCount(int Stream, long rowsexported);

/* <<-DR162287-db186031-01 */
                                 
                                 /*DR168497-yl185012-01->*/
/**********************************************************
FNC_TblOpDisableCoGroup();

Disable Co-Group logic

Input:      void

Output:     void

 *********************************************************/
 
extern void FNC_TblOpDisableCoGroup();
                                /*<- DR168497-yl185012-01*/

                                                  /*DR171050-jz186002-01 --->*/
/******************************************************************************
 FNC_TblOpDisableProjectionRewrite

  This function will set whether to disable column projection rewrite or not.
  It's callable only on PE by table operators, and can't be called in COMPLETE
  phase of contract.

  Input:   disable - If true, the column projection rewrite will be disabled.
                     If false, the column projection rewrite will be enabled.
  Output:  NONE.

 *****************************************************************************/

extern void FNC_TblOpDisableProjectionRewrite(boolean_t disable);


/******************************************************************************
 FNC_GetCurrentSessionDatabase

  This function gets the current session database name.
  It's callable only on PE by table operators.

  Input/Output:  currSessDb - it will be allocated space inside the function,
                              and hold the database name for current session.

                 currSessDbLen - will be set as the number of bytes of current 
                                 session database name.
  NOTE:    *currSesDb is allocated memory inside the function with FNC_malloc.
           If it is not returned as NULL, it's the caller's responsibility to
           release the memory with FNC_free after it's done using the data.
 *****************************************************************************/

extern void FNC_GetCurrentSessionDatabase(unsigned char  **currSessDb,
                                          unsigned int   *currSessDbLen);
                                                  /*<--- DR171050-jz186002-01*/


                                   /* DR162286-en185000-> */
/***********************************************************
 FNC_TblOpGetUniqID 

 Retrieves the Table Operator's unique ID 
 Input:    None.
 Output:   The Unique ID.
 
 ***********************************************************/
extern unsigned short FNC_TblOpGetUniqID();
                                   /* <-DR162286-en185000 */



                                                   /*DR170274-jz186002-01 --->*/
extern DECIMAL8 FNC_GetQueryID();

typedef enum
{
    STATUS_NONE = 0,
    CONTRACT_VALIDATING_REMOTE_CONNECTION = 1,
    CONTRACT_CONTACTING_REMOTE_FOR_METADATA = 2,
    CONTRACT_PREPARING_OUTPUT_COLDEF = 3,
    OPERATOR_SYNCHRONIZING = 4,
    OPERATOR_ESTABLISHING_FOREIGN_CONNECTION = 5,
    OPERATOR_WAITING_FOR_FOREIGN_COMMUNICATION_SETUP_TO_COMPLETE = 6,
    OPERATOR_EXPORTING_DATA = 7,
    OPERATOR_IMPORTING_DATA = 8,
    OPERATOR_EXECUTING_FOREIGN_QUERY = 9,
    OPERATOR_WAITING_FOR_FOREIGN_QUERY_TO_COMPLETE = 10,
    OPERATOR_CLOSING_OR_CLEANING_UP = 11
} queryStatus_et;

typedef unsigned short QueryStatus;

extern void FNC_TblOpSetLQStatus(QueryStatus status);

extern void FNC_TblOpSetRQIdent(short hostId, int sessionId, 
                                int requestId, long queryId);

                                                   /*<--- DR170274-jz186002-01*/

                                                          //DR186504-pn151000->
typedef struct
{
    Unicode_Text   DbName[128];
    Unicode_Text   ObjName[128];
    unsigned short AmpNo;     /* Amp No associated with the sparse map */
    char           type[2];   /* Primary or Fallback */
    char           ObjKind;
} FNC_SparseMapAmps_Type_t;

/******************************************************************************
  Purpose  :  This table function can be invoked from AMP and returns a list of
              AMPs and type of AMP (ie. 'P' for Primary, 'F' for Fallback,
              'PF' for Primary and Fallback).

  Passed   :  1. DbName is the database name of the input object.
              3. ObjName is the name of the input object.
              4. ObjKind is the kind of the input object, such as table, index...
              5. MapSlot
              6. NumOfAmps is the number of primary AMP which the input object
                 resides on.
              7. ColName is the colocation name of the input object.

  Returned :  1. AmpCnt is the number of returned rows of the table function.
              2. DstBuf holds the returned table (type of FNC_SparseMapAmps_Type_t).
******************************************************************************/
extern void 
FNC_SparseMapAMPs(void           *DbName,
                  void           *ObjName,
                  char            ObjKind,
                  unsigned short  MapSlot,
                  unsigned short  NumOfAmps,
                  void           *ColName,
                  unsigned short *AmpCnt,
                  void           *DstBuf );
                                                          //<-DR186504-pn151000

/******************************************************************************
 FNC_SparseTableAMPs
  Purpose  :  This function can be invoked from PE and returns a list of AMPs
              on which a specific table with a sparse map is defined.

  Passed   :  DbName is the database name of the input table.
              TblName is the name of the input table.

  Returned :  Function returns a list of AMPs in the format of fixed 7 char
              long right-justified character representation for each AMP, up
              the maximum of 1024 AMPs.
              '      1     12    123   1234  12345 123456'
******************************************************************************/
extern void 
FNC_SparseTableAMPs(void *DbName, void *TblName, void *DstBuf);
                                                          /*DR172404-pn151000*/
           
typedef struct
{
    unsigned int AmpNo;     /* Amp No associated with the contiguous map */
    char         type[2];   /* Primary or Fallback */
} FNC_CtgMapAmpNo_Type_t;

extern void 
FNC_CtgMapAMPs(void *MapName, unsigned int *AmpCnt, void *DstBuf);
                                                     /* DR172404-sn255019-01 */
                                                    /* DR186130-jk151003-01 ->*/
#define FNCMALLOCMEM 1
#define pcre_compile( _p1, _p2, _p3, _p4, _p5 ) \
 TD_pcre_compile( _p1, _p2, NULL, _p3, _p4, _p5, _p6, FNCMALLOCMEM )
#define pcre_exec( _p1, _p2, _p3, _p4, _p5, _p6, _p7, _p8 ) \
 TD_pcre_exec( _p1, _p2, _p3, _p4, _p5, _p6, _p7, _p8, FNCMALLOCMEM )
#define pcre_get_substring_list( _p1, _p2, _p3, _p4 ) \
 TD_pcre_get_substring_list( _p1, _p2, _p3, _p4, FNCMALLOCMEM )
#define pcre_free_substring_list( _p1 ) \
 TD_pcre_free_substring_list( _p1, FNCMALLOCMEM )
#define pcre_get_substring( _p1, _p2, _p3, _p4, _p5 ) \
 TD_pcre_get_substring( _p1, _p2, _p3, _p4, _p5, FNCMALLOCMEM )
#define pcre_get_named_substring( _p1, _p2, _p3, _p4, _p5, _p6 ) \
 TD_pcre_get_named_substring( _p1, _p2, _p3, _p4, _p5, _p6, FNCMALLOCMEM )
#define pcre_free_substring( _p1 ) \
 TD_pcre_free_substring( _p1, FNCMALLOCMEM )
#define pcre_maketables() \
 TD_pcre_maketables( FNCMALLOCMEM )
#define pcre_study( _p1, _p2, _p3 ) \
 TD_pcre_study( _p1, _p2, _p3, FNCMALLOCMEM )
#define pcre_free_study( _p1 ) \
 TD_pcre_free_study( _p1, FNCMALLOCMEM )
                                                    /*<- DR186130-jk151003-01 */


#ifdef __cplusplus
}
#endif

#endif 
