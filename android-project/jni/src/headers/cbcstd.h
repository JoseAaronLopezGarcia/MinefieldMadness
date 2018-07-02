#ifndef CBCSTD_H
#define CBCSTD_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// public globals
#define OP_ADD '+'
#define OP_SUB '-'
#define OP_MUL '*'
#define OP_DIV '/'
#define OP_XOR '^'
#define OP_AND '&'
#define OP_OR '|'
#define OP_NOT '~'
#define OP_MOD '%'
#define OP_INC 'i'
#define OP_DEC 'd'
#include <stdio.h>
typedef struct cbcstd_Object_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Object_struct* self);
	void* (* __getvtable__)(struct cbcstd_Object_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Object_struct* self, struct cbcstd_Object_struct* other);
	struct cbcstd_Object_struct* (* __operate__)(struct cbcstd_Object_struct* self, struct cbcstd_Object_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Object_struct* self);
} cbcstd_Object_struct;
typedef cbcstd_Object_struct* cbcstd_Object;
extern const class_id cbcstd_Object__classid__;
extern cbcstd_Object cbcstd_Object_create();
extern void cbcstd_Object_init(cbcstd_Object self);
extern void cbcstd_Object_initsystem(cbcstd_Object self);
extern void cbcstd_Object_inituser(cbcstd_Object self);
extern void* cbcstd_Object___getvtable__(cbcstd_Object self, class_id id);
extern int cbcstd_Object___cmp__(cbcstd_Object self, cbcstd_Object other);
extern cbcstd_Object cbcstd_Object___operate__(cbcstd_Object self, cbcstd_Object other, char op, bool modify);
extern void* cbcstd_Object___str__(cbcstd_Object self);
extern void cbcstd_Object_enduser(cbcstd_Object self);
extern void cbcstd_Object_end(cbcstd_Object self);

typedef struct cbcstd_NoneType_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_NoneType_struct* self);
	void* (* __getvtable__)(struct cbcstd_NoneType_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_NoneType_struct* self, struct cbcstd_NoneType_struct* other);
	struct cbcstd_NoneType_struct* (* __operate__)(struct cbcstd_NoneType_struct* self, struct cbcstd_NoneType_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_NoneType_struct* self);
} cbcstd_NoneType_struct;
typedef cbcstd_NoneType_struct* cbcstd_NoneType;
extern const class_id cbcstd_NoneType__classid__;
extern cbcstd_NoneType cbcstd_NoneType_create();
extern void cbcstd_NoneType_init(cbcstd_NoneType self);
extern void cbcstd_NoneType_initsystem(cbcstd_NoneType self);
extern void cbcstd_NoneType_inituser(cbcstd_NoneType self);
extern void* cbcstd_NoneType___str__(cbcstd_NoneType self);
extern void cbcstd_NoneType_enduser(cbcstd_NoneType self);
extern void cbcstd_NoneType_end(cbcstd_NoneType self);

extern cbcstd_Object cbcstd_getNone();

extern size_t cbcstd_npos;

typedef struct cbcstd_String_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_String_struct* self);
	void* (* __getvtable__)(struct cbcstd_String_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_String_struct* self, struct cbcstd_String_struct* other);
	struct cbcstd_String_struct* (* __operate__)(struct cbcstd_String_struct* self, struct cbcstd_String_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_String_struct* self);
	char* (cstr_267);
	size_t (len_309);
	ssize_t (iter_count_217);
	long (hash_value_431);
	char* (* c_str)(struct cbcstd_String_struct* self);
	void (* __iterinit__)(struct cbcstd_String_struct* self, bool reversed);
	bool (* __iternext__)(struct cbcstd_String_struct* self, char* dest);
	bool (* __iterprev__)(struct cbcstd_String_struct* self, char* dest);
	long (* _hash_661)(struct cbcstd_String_struct* self);
	long (* hash)(struct cbcstd_String_struct* self);
	size_t (* size)(struct cbcstd_String_struct* self);
	bool (* equals)(struct cbcstd_String_struct* self, char* other);
	size_t (* span)(struct cbcstd_String_struct* self, char* chars);
	struct cbcstd_String_struct* (* pbrk)(struct cbcstd_String_struct* self, char* chars);
	size_t (* rfindChar)(struct cbcstd_String_struct* self, char search, size_t pos);
	size_t (* findChar)(struct cbcstd_String_struct* self, char search, size_t pos);
	size_t (* rfind)(struct cbcstd_String_struct* self, char* search, size_t pos);
	size_t (* find)(struct cbcstd_String_struct* self, char* search, size_t pos);
	bool (* exists)(struct cbcstd_String_struct* self, char* search);
	bool (* charExists)(struct cbcstd_String_struct* self, char search);
	struct cbcstd_String_struct* (* copy)(struct cbcstd_String_struct* self);
	struct cbcstd_String_struct* (* substr)(struct cbcstd_String_struct* self, size_t start, size_t end);
	char (* get)(struct cbcstd_String_struct* self, size_t pos);
	struct cbcstd_String_struct* (* cat)(struct cbcstd_String_struct* self, char* append);
	struct cbcstd_String_struct* (* capitalize)(struct cbcstd_String_struct* self);
	size_t (* count)(struct cbcstd_String_struct* self, char* str);
	bool (* endswith)(struct cbcstd_String_struct* self, char* str);
	bool (* startswith)(struct cbcstd_String_struct* self, char* str);
	struct cbcstd_String_struct* (* expandTabs)(struct cbcstd_String_struct* self, size_t tabsize);
	bool (* isWhitespaceChar)(struct cbcstd_String_struct* self, char test);
	bool (* isNumericChar)(struct cbcstd_String_struct* self, char test);
	bool (* isAlphaChar)(struct cbcstd_String_struct* self, char test);
	bool (* isAlphanumericChar)(struct cbcstd_String_struct* self, char test);
	bool (* isAlphaNumeric)(struct cbcstd_String_struct* self);
	bool (* isAlpha)(struct cbcstd_String_struct* self);
	bool (* isNumeric)(struct cbcstd_String_struct* self);
	bool (* isHexadecimal)(struct cbcstd_String_struct* self);
	bool (* isFloat)(struct cbcstd_String_struct* self);
	bool (* isBinary)(struct cbcstd_String_struct* self);
	bool (* isOctal)(struct cbcstd_String_struct* self);
	bool (* isLower)(struct cbcstd_String_struct* self);
	bool (* isUpper)(struct cbcstd_String_struct* self);
	bool (* isWhitespace)(struct cbcstd_String_struct* self);
	struct cbcstd_String_struct* (* ljustChar)(struct cbcstd_String_struct* self, size_t width, char fill);
	struct cbcstd_String_struct* (* rjust)(struct cbcstd_String_struct* self, size_t width, char fill);
	struct cbcstd_String_struct* (* lower)(struct cbcstd_String_struct* self);
	struct cbcstd_String_struct* (* upper)(struct cbcstd_String_struct* self);
	struct cbcstd_String_struct* (* swapcase)(struct cbcstd_String_struct* self);
	struct cbcstd_String_struct* (* replace)(struct cbcstd_String_struct* self, char* oldStr, char* newStr);
	struct cbcstd_String_struct* (* rstrip)(struct cbcstd_String_struct* self, char* remove);
	struct cbcstd_String_struct* (* lstrip)(struct cbcstd_String_struct* self, char* remove);
	struct cbcstd_String_struct* (* strip)(struct cbcstd_String_struct* self, char* remove);
	void (* print)(struct cbcstd_String_struct* self);
	void (* println)(struct cbcstd_String_struct* self);
} cbcstd_String_struct;
typedef cbcstd_String_struct* cbcstd_String;
extern const class_id cbcstd_String__classid__;
extern cbcstd_String cbcstd_String_create(char* orig);
extern void cbcstd_String_init(cbcstd_String self, char* orig);
extern void cbcstd_String_initsystem(cbcstd_String self);
extern void cbcstd_String_inituser(cbcstd_String self, char* orig);
extern char* cbcstd_String_c_str(cbcstd_String self);
extern void cbcstd_String___iterinit__(cbcstd_String self, bool reversed);
extern bool cbcstd_String___iternext__(cbcstd_String self, char* dest);
extern bool cbcstd_String___iterprev__(cbcstd_String self, char* dest);
extern long cbcstd_String__hash_661(cbcstd_String self);
extern long cbcstd_String_hash(cbcstd_String self);
extern size_t cbcstd_String_size(cbcstd_String self);
extern int cbcstd_String___cmp__(cbcstd_String self, cbcstd_String other);
extern bool cbcstd_String_equals(cbcstd_String self, char* other);
extern size_t cbcstd_String_span(cbcstd_String self, char* chars);
extern cbcstd_String cbcstd_String_pbrk(cbcstd_String self, char* chars);
extern size_t cbcstd_String_rfindChar(cbcstd_String self, char search, size_t pos);
extern size_t cbcstd_String_findChar(cbcstd_String self, char search, size_t pos);
extern size_t cbcstd_String_rfind(cbcstd_String self, char* search, size_t pos);
extern size_t cbcstd_String_find(cbcstd_String self, char* search, size_t pos);
extern bool cbcstd_String_exists(cbcstd_String self, char* search);
extern bool cbcstd_String_charExists(cbcstd_String self, char search);
extern cbcstd_String cbcstd_String_copy(cbcstd_String self);
extern cbcstd_String cbcstd_String_substr(cbcstd_String self, size_t start, size_t end);
extern char cbcstd_String_get(cbcstd_String self, size_t pos);
extern cbcstd_String cbcstd_String_cat(cbcstd_String self, char* append);
extern cbcstd_String cbcstd_String_capitalize(cbcstd_String self);
extern size_t cbcstd_String_count(cbcstd_String self, char* str);
extern bool cbcstd_String_endswith(cbcstd_String self, char* str);
extern bool cbcstd_String_startswith(cbcstd_String self, char* str);
extern cbcstd_String cbcstd_String_expandTabs(cbcstd_String self, size_t tabsize);
extern bool cbcstd_String_isWhitespaceChar(cbcstd_String self, char test);
extern bool cbcstd_String_isNumericChar(cbcstd_String self, char test);
extern bool cbcstd_String_isAlphaChar(cbcstd_String self, char test);
extern bool cbcstd_String_isAlphanumericChar(cbcstd_String self, char test);
extern bool cbcstd_String_isAlphaNumeric(cbcstd_String self);
extern bool cbcstd_String_isAlpha(cbcstd_String self);
extern bool cbcstd_String_isNumeric(cbcstd_String self);
extern bool cbcstd_String_isHexadecimal(cbcstd_String self);
extern bool cbcstd_String_isFloat(cbcstd_String self);
extern bool cbcstd_String_isBinary(cbcstd_String self);
extern bool cbcstd_String_isOctal(cbcstd_String self);
extern bool cbcstd_String_isLower(cbcstd_String self);
extern bool cbcstd_String_isUpper(cbcstd_String self);
extern bool cbcstd_String_isWhitespace(cbcstd_String self);
extern cbcstd_String cbcstd_String_ljustChar(cbcstd_String self, size_t width, char fill);
extern cbcstd_String cbcstd_String_rjust(cbcstd_String self, size_t width, char fill);
extern cbcstd_String cbcstd_String_lower(cbcstd_String self);
extern cbcstd_String cbcstd_String_upper(cbcstd_String self);
extern cbcstd_String cbcstd_String_swapcase(cbcstd_String self);
extern cbcstd_String cbcstd_String_replace(cbcstd_String self, char* oldStr, char* newStr);
extern cbcstd_String cbcstd_String_rstrip(cbcstd_String self, char* remove);
extern cbcstd_String cbcstd_String_lstrip(cbcstd_String self, char* remove);
extern cbcstd_String cbcstd_String_strip(cbcstd_String self, char* remove);
extern void cbcstd_String_print(cbcstd_String self);
extern void cbcstd_String_println(cbcstd_String self);
extern void* cbcstd_String___str__(cbcstd_String self);
extern void cbcstd_String_enduser(cbcstd_String self);
extern void cbcstd_String_end(cbcstd_String self);

typedef struct cbcstd_Int_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Int_struct* self);
	void* (* __getvtable__)(struct cbcstd_Int_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Int_struct* self, struct cbcstd_Int_struct* other);
	struct cbcstd_Int_struct* (* __operate__)(struct cbcstd_Int_struct* self, struct cbcstd_Int_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Int_struct* self);
	ssize_t value_527;
	int8_t (* to8Bits)(struct cbcstd_Int_struct* self);
	int16_t (* to16Bits)(struct cbcstd_Int_struct* self);
	int32_t (* to32Bits)(struct cbcstd_Int_struct* self);
	int64_t (* to64Bits)(struct cbcstd_Int_struct* self);
} cbcstd_Int_struct;
typedef cbcstd_Int_struct* cbcstd_Int;
extern const class_id cbcstd_Int__classid__;
extern cbcstd_Int cbcstd_Int_create(ssize_t value);
extern void cbcstd_Int_init(cbcstd_Int self, ssize_t value);
extern void cbcstd_Int_initsystem(cbcstd_Int self);
extern void cbcstd_Int_inituser(cbcstd_Int self, ssize_t value);
extern int8_t cbcstd_Int_to8Bits(cbcstd_Int self);
extern int16_t cbcstd_Int_to16Bits(cbcstd_Int self);
extern int32_t cbcstd_Int_to32Bits(cbcstd_Int self);
extern int64_t cbcstd_Int_to64Bits(cbcstd_Int self);
extern int cbcstd_Int___cmp__(cbcstd_Int self, cbcstd_Int other);
extern void* cbcstd_Int___str__(cbcstd_Int self);
extern void cbcstd_Int_enduser(cbcstd_Int self);
extern void cbcstd_Int_end(cbcstd_Int self);

typedef struct cbcstd_Hex_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Hex_struct* self);
	void* (* __getvtable__)(struct cbcstd_Hex_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Hex_struct* self, struct cbcstd_Hex_struct* other);
	struct cbcstd_Hex_struct* (* __operate__)(struct cbcstd_Hex_struct* self, struct cbcstd_Hex_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Hex_struct* self);
	ssize_t value_527;
	int8_t (* to8Bits)(struct cbcstd_Hex_struct* self);
	int16_t (* to16Bits)(struct cbcstd_Hex_struct* self);
	int32_t (* to32Bits)(struct cbcstd_Hex_struct* self);
	int64_t (* to64Bits)(struct cbcstd_Hex_struct* self);
} cbcstd_Hex_struct;
typedef cbcstd_Hex_struct* cbcstd_Hex;
extern const class_id cbcstd_Hex__classid__;
extern cbcstd_Hex cbcstd_Hex_create(ssize_t value);
extern void cbcstd_Hex_init(cbcstd_Hex self, ssize_t value);
extern void cbcstd_Hex_initsystem(cbcstd_Hex self);
extern void cbcstd_Hex_inituser(cbcstd_Hex self, ssize_t value);
extern void* cbcstd_Hex___str__(cbcstd_Hex self);
extern void cbcstd_Hex_enduser(cbcstd_Hex self);
extern void cbcstd_Hex_end(cbcstd_Hex self);

typedef struct cbcstd_Float_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Float_struct* self);
	void* (* __getvtable__)(struct cbcstd_Float_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Float_struct* self, struct cbcstd_Float_struct* other);
	struct cbcstd_Float_struct* (* __operate__)(struct cbcstd_Float_struct* self, struct cbcstd_Float_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Float_struct* self);
	double value_528;
} cbcstd_Float_struct;
typedef cbcstd_Float_struct* cbcstd_Float;
extern const class_id cbcstd_Float__classid__;
extern cbcstd_Float cbcstd_Float_create(double value);
extern void cbcstd_Float_init(cbcstd_Float self, double value);
extern void cbcstd_Float_initsystem(cbcstd_Float self);
extern void cbcstd_Float_inituser(cbcstd_Float self, double value);
extern int cbcstd_Float___cmp__(cbcstd_Float self, cbcstd_Float other);
extern void* cbcstd_Float___str__(cbcstd_Float self);
extern void cbcstd_Float_enduser(cbcstd_Float self);
extern void cbcstd_Float_end(cbcstd_Float self);

typedef struct cbcstd_Char_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Char_struct* self);
	void* (* __getvtable__)(struct cbcstd_Char_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Char_struct* self, struct cbcstd_Char_struct* other);
	struct cbcstd_Char_struct* (* __operate__)(struct cbcstd_Char_struct* self, struct cbcstd_Char_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Char_struct* self);
	char value_747;
} cbcstd_Char_struct;
typedef cbcstd_Char_struct* cbcstd_Char;
extern const class_id cbcstd_Char__classid__;
extern cbcstd_Char cbcstd_Char_create(char value);
extern void cbcstd_Char_init(cbcstd_Char self, char value);
extern void cbcstd_Char_initsystem(cbcstd_Char self);
extern void cbcstd_Char_inituser(cbcstd_Char self, char value);
extern int cbcstd_Char___cmp__(cbcstd_Char self, cbcstd_Char other);
extern void* cbcstd_Char___str__(cbcstd_Char self);
extern void cbcstd_Char_enduser(cbcstd_Char self);
extern void cbcstd_Char_end(cbcstd_Char self);

typedef struct cbcstd_Bool_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Bool_struct* self);
	void* (* __getvtable__)(struct cbcstd_Bool_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Bool_struct* self, struct cbcstd_Bool_struct* other);
	struct cbcstd_Bool_struct* (* __operate__)(struct cbcstd_Bool_struct* self, struct cbcstd_Bool_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Bool_struct* self);
	bool value_637;
	char* text_70[2];
	void (* _setValue_942)(struct cbcstd_Bool_struct* self, bool val);
} cbcstd_Bool_struct;
typedef cbcstd_Bool_struct* cbcstd_Bool;
extern const class_id cbcstd_Bool__classid__;
extern cbcstd_Bool cbcstd_Bool_create(bool src);
extern void cbcstd_Bool_init(cbcstd_Bool self, bool src);
extern void cbcstd_Bool_initsystem(cbcstd_Bool self);
extern void cbcstd_Bool_inituser(cbcstd_Bool self, bool src);
extern void cbcstd_Bool__setValue_942(cbcstd_Bool self, bool val);
extern int cbcstd_Bool___cmp__(cbcstd_Bool self, cbcstd_Bool other);
extern void* cbcstd_Bool___str__(cbcstd_Bool self);
extern void cbcstd_Bool_enduser(cbcstd_Bool self);
extern void cbcstd_Bool_end(cbcstd_Bool self);

extern cbcstd_Bool cbcstd_getBool(bool value);

typedef struct cbcstd_Buffer_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Buffer_struct* self);
	void* (* __getvtable__)(struct cbcstd_Buffer_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Buffer_struct* self, struct cbcstd_Buffer_struct* other);
	struct cbcstd_Buffer_struct* (* __operate__)(struct cbcstd_Buffer_struct* self, struct cbcstd_Buffer_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Buffer_struct* self);
	void* ptr_687;
	size_t (size_983);
	bool (destroy_500);
	void (* _check_523)(struct cbcstd_Buffer_struct* self, void* dest_buffer, size_t size, size_t offset);
	void (* read)(struct cbcstd_Buffer_struct* self, void* dest_buffer, size_t size, size_t offset);
	void (* write)(struct cbcstd_Buffer_struct* self, void* dest_buffer, size_t size, size_t offset);
	void (* _destroyPtr_687)(struct cbcstd_Buffer_struct* self);
	void (* setPointer)(struct cbcstd_Buffer_struct* self, void* ptr);
} cbcstd_Buffer_struct;
typedef cbcstd_Buffer_struct* cbcstd_Buffer;
extern const class_id cbcstd_Buffer__classid__;
extern cbcstd_Buffer cbcstd_Buffer_create(size_t size, void* ptr);
extern void cbcstd_Buffer_init(cbcstd_Buffer self, size_t size, void* ptr);
extern void cbcstd_Buffer_initsystem(cbcstd_Buffer self);
extern void cbcstd_Buffer_inituser(cbcstd_Buffer self, size_t size, void* ptr);
extern void cbcstd_Buffer__check_523(cbcstd_Buffer self, void* dest_buffer, size_t size, size_t offset);
extern void cbcstd_Buffer_read(cbcstd_Buffer self, void* dest_buffer, size_t size, size_t offset);
extern void cbcstd_Buffer_write(cbcstd_Buffer self, void* dest_buffer, size_t size, size_t offset);
extern void cbcstd_Buffer__destroyPtr_687(cbcstd_Buffer self);
extern void cbcstd_Buffer_setPointer(cbcstd_Buffer self, void* ptr);
extern void* cbcstd_Buffer___str__(cbcstd_Buffer self);
extern void cbcstd_Buffer_enduser(cbcstd_Buffer self);
extern void cbcstd_Buffer_end(cbcstd_Buffer self);

typedef pthread_t cbcstd_thread_t;

typedef sem_t cbcstd_sema_t;

typedef enum cbcstd_MutexType{
	cbcstd_PERMISIVE_MUTEX,
	cbcstd_CRITICAL_MUTEX,
} cbcstd_MutexType;



typedef struct cbcstd_Thread_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Thread_struct* self);
	void* (* __getvtable__)(struct cbcstd_Thread_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Thread_struct* self, struct cbcstd_Thread_struct* other);
	struct cbcstd_Thread_struct* (* __operate__)(struct cbcstd_Thread_struct* self, struct cbcstd_Thread_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Thread_struct* self);
	cbcstd_thread_t thread_id_332;
	void* start_79;
	void* arg_383;
	int (* run)(struct cbcstd_Thread_struct* self);
	void* (* waitThreadEnd)(struct cbcstd_Thread_struct* self, int timeout);
	void (* setId)(struct cbcstd_Thread_struct* self, int id);
} cbcstd_Thread_struct;
typedef cbcstd_Thread_struct* cbcstd_Thread;
extern const class_id cbcstd_Thread__classid__;
extern cbcstd_Thread cbcstd_Thread_create(void* start, void* arg);
extern void cbcstd_Thread_init(cbcstd_Thread self, void* start, void* arg);
extern void cbcstd_Thread_initsystem(cbcstd_Thread self);
extern void cbcstd_Thread_inituser(cbcstd_Thread self, void* start, void* arg);
extern int cbcstd_Thread_run(cbcstd_Thread self);
extern void* cbcstd_Thread_waitThreadEnd(cbcstd_Thread self, int timeout);
extern void cbcstd_Thread_setId(cbcstd_Thread self, int id);
extern void cbcstd_Thread_enduser(cbcstd_Thread self);
extern void cbcstd_Thread_end(cbcstd_Thread self);

typedef struct cbcstd_Semaphore_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Semaphore_struct* self);
	void* (* __getvtable__)(struct cbcstd_Semaphore_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Semaphore_struct* self, struct cbcstd_Semaphore_struct* other);
	struct cbcstd_Semaphore_struct* (* __operate__)(struct cbcstd_Semaphore_struct* self, struct cbcstd_Semaphore_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Semaphore_struct* self);
	int (counter_951);
	cbcstd_sema_t (semaphore_698);
	void (* wait)(struct cbcstd_Semaphore_struct* self);
	void (* release)(struct cbcstd_Semaphore_struct* self);
} cbcstd_Semaphore_struct;
typedef cbcstd_Semaphore_struct* cbcstd_Semaphore;
extern const class_id cbcstd_Semaphore__classid__;
extern cbcstd_Semaphore cbcstd_Semaphore_create(int counter);
extern void cbcstd_Semaphore_init(cbcstd_Semaphore self, int counter);
extern void cbcstd_Semaphore_initsystem(cbcstd_Semaphore self);
extern void cbcstd_Semaphore_inituser(cbcstd_Semaphore self, int counter);
extern void cbcstd_Semaphore_wait(cbcstd_Semaphore self);
extern void cbcstd_Semaphore_release(cbcstd_Semaphore self);
extern void cbcstd_Semaphore_enduser(cbcstd_Semaphore self);
extern void cbcstd_Semaphore_end(cbcstd_Semaphore self);

typedef struct cbcstd_Mutex_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Mutex_struct* self);
	void* (* __getvtable__)(struct cbcstd_Mutex_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Mutex_struct* self, struct cbcstd_Mutex_struct* other);
	struct cbcstd_Mutex_struct* (* __operate__)(struct cbcstd_Mutex_struct* self, struct cbcstd_Mutex_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Mutex_struct* self);
	cbcstd_thread_t (owner_871);
	cbcstd_Semaphore (sema_115);
	cbcstd_Semaphore (owner_sema_73);
	cbcstd_MutexType (type_922);
	int (ignore_9);
	void (* wait)(struct cbcstd_Mutex_struct* self);
	void (* release)(struct cbcstd_Mutex_struct* self);
} cbcstd_Mutex_struct;
typedef cbcstd_Mutex_struct* cbcstd_Mutex;
extern const class_id cbcstd_Mutex__classid__;
extern cbcstd_Mutex cbcstd_Mutex_create(cbcstd_MutexType type);
extern void cbcstd_Mutex_init(cbcstd_Mutex self, cbcstd_MutexType type);
extern void cbcstd_Mutex_initsystem(cbcstd_Mutex self);
extern void cbcstd_Mutex_inituser(cbcstd_Mutex self, cbcstd_MutexType type);
extern void cbcstd_Mutex_wait(cbcstd_Mutex self);
extern void cbcstd_Mutex_release(cbcstd_Mutex self);
extern void cbcstd_Mutex_enduser(cbcstd_Mutex self);
extern void cbcstd_Mutex_end(cbcstd_Mutex self);

typedef struct _cbcstd_ObjectLock_struct* _cbcstd_ObjectLock; ;

extern void cbcstd_exitThread(void* retval);

extern cbcstd_thread_t cbcstd_getThreadId();

extern bool cbcstd_equalThreads(cbcstd_thread_t thread1, cbcstd_thread_t thread2);

extern bool cbcstd_isSelfThread(cbcstd_Thread t);

extern void cbcstd_addObjectLock(cbcstd_Object o);

extern void cbcstd_removeObjectLock(cbcstd_Object o);

extern void cbcstd_lockObject(cbcstd_Object o);

extern void cbcstd_unlockObject(cbcstd_Object o);

typedef struct cbcstd_Exception_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Exception_struct* self);
	void* (* __getvtable__)(struct cbcstd_Exception_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Exception_struct* self, struct cbcstd_Exception_struct* other);
	struct cbcstd_Exception_struct* (* __operate__)(struct cbcstd_Exception_struct* self, struct cbcstd_Exception_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Exception_struct* self);
	cbcstd_String description_787;
} cbcstd_Exception_struct;
typedef cbcstd_Exception_struct* cbcstd_Exception;
extern const class_id cbcstd_Exception__classid__;
extern cbcstd_Exception cbcstd_Exception_create(char* description);
extern void cbcstd_Exception_init(cbcstd_Exception self, char* description);
extern void cbcstd_Exception_initsystem(cbcstd_Exception self);
extern void cbcstd_Exception_inituser(cbcstd_Exception self, char* description);
extern void* cbcstd_Exception___str__(cbcstd_Exception self);
extern void cbcstd_Exception_enduser(cbcstd_Exception self);
extern void cbcstd_Exception_end(cbcstd_Exception self);

typedef struct cbcstd_CriticalException_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_CriticalException_struct* self);
	void* (* __getvtable__)(struct cbcstd_CriticalException_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_CriticalException_struct* self, struct cbcstd_CriticalException_struct* other);
	struct cbcstd_CriticalException_struct* (* __operate__)(struct cbcstd_CriticalException_struct* self, struct cbcstd_CriticalException_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_CriticalException_struct* self);
	cbcstd_String description_787;
} cbcstd_CriticalException_struct;
typedef cbcstd_CriticalException_struct* cbcstd_CriticalException;
extern const class_id cbcstd_CriticalException__classid__;
extern cbcstd_CriticalException cbcstd_CriticalException_create(char* description);
extern void cbcstd_CriticalException_init(cbcstd_CriticalException self, char* description);
extern void cbcstd_CriticalException_initsystem(cbcstd_CriticalException self);
extern void cbcstd_CriticalException_inituser(cbcstd_CriticalException self, char* description);
extern void cbcstd_CriticalException_enduser(cbcstd_CriticalException self);
extern void cbcstd_CriticalException_end(cbcstd_CriticalException self);

typedef struct cbcstd_SystemError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_SystemError_struct* self);
	void* (* __getvtable__)(struct cbcstd_SystemError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_SystemError_struct* self, struct cbcstd_SystemError_struct* other);
	struct cbcstd_SystemError_struct* (* __operate__)(struct cbcstd_SystemError_struct* self, struct cbcstd_SystemError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_SystemError_struct* self);
	cbcstd_String description_787;
} cbcstd_SystemError_struct;
typedef cbcstd_SystemError_struct* cbcstd_SystemError;
extern const class_id cbcstd_SystemError__classid__;
extern cbcstd_SystemError cbcstd_SystemError_create(char* description);
extern void cbcstd_SystemError_init(cbcstd_SystemError self, char* description);
extern void cbcstd_SystemError_initsystem(cbcstd_SystemError self);
extern void cbcstd_SystemError_inituser(cbcstd_SystemError self, char* description);
extern void cbcstd_SystemError_enduser(cbcstd_SystemError self);
extern void cbcstd_SystemError_end(cbcstd_SystemError self);

typedef struct cbcstd_SystemExit_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_SystemExit_struct* self);
	void* (* __getvtable__)(struct cbcstd_SystemExit_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_SystemExit_struct* self, struct cbcstd_SystemExit_struct* other);
	struct cbcstd_SystemExit_struct* (* __operate__)(struct cbcstd_SystemExit_struct* self, struct cbcstd_SystemExit_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_SystemExit_struct* self);
	cbcstd_String description_787;
	int exit_status_372;
} cbcstd_SystemExit_struct;
typedef cbcstd_SystemExit_struct* cbcstd_SystemExit;
extern const class_id cbcstd_SystemExit__classid__;
extern cbcstd_SystemExit cbcstd_SystemExit_create(int exit_status);
extern void cbcstd_SystemExit_init(cbcstd_SystemExit self, int exit_status);
extern void cbcstd_SystemExit_initsystem(cbcstd_SystemExit self);
extern void cbcstd_SystemExit_inituser(cbcstd_SystemExit self, int exit_status);
extern void cbcstd_SystemExit_enduser(cbcstd_SystemExit self);
extern void cbcstd_SystemExit_end(cbcstd_SystemExit self);

typedef struct _cbcstd_JumpBuffer _cbcstd_JumpBuffer; ;

typedef struct _cbcstd_ExceptionThreadBuffer _cbcstd_ExceptionThreadBuffer; ;

typedef struct _cbcstd_CriticalExceptionHandler _cbcstd_CriticalExceptionHandler; ;

extern void cbcstd_registerException(cbcstd_Exception e);

extern cbcstd_Exception cbcstd_getRaisedException();

extern jmp_buf* cbcstd_registerExceptionBuffer();

extern jmp_buf* cbcstd_obtainNextExceptionBuffer(jmp_buf* dest_buffer);

extern void cbcstd_registerCriticalExceptionHandler(class_id classid, cbcstd_Exception (* handler)(cbcstd_CriticalException));

extern void cbcstd_unregisterCriticalExceptionHandler(class_id classid);

extern void cbcstd_printException();

typedef struct cbcstd_OutOfMemoryError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_OutOfMemoryError_struct* self);
	void* (* __getvtable__)(struct cbcstd_OutOfMemoryError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_OutOfMemoryError_struct* self, struct cbcstd_OutOfMemoryError_struct* other);
	struct cbcstd_OutOfMemoryError_struct* (* __operate__)(struct cbcstd_OutOfMemoryError_struct* self, struct cbcstd_OutOfMemoryError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_OutOfMemoryError_struct* self);
	cbcstd_String description_787;
} cbcstd_OutOfMemoryError_struct;
typedef cbcstd_OutOfMemoryError_struct* cbcstd_OutOfMemoryError;
extern const class_id cbcstd_OutOfMemoryError__classid__;
extern cbcstd_OutOfMemoryError cbcstd_OutOfMemoryError_create();
extern void cbcstd_OutOfMemoryError_init(cbcstd_OutOfMemoryError self);
extern void cbcstd_OutOfMemoryError_initsystem(cbcstd_OutOfMemoryError self);
extern void cbcstd_OutOfMemoryError_inituser(cbcstd_OutOfMemoryError self);
extern void cbcstd_OutOfMemoryError_enduser(cbcstd_OutOfMemoryError self);
extern void cbcstd_OutOfMemoryError_end(cbcstd_OutOfMemoryError self);

typedef struct cbcstd_NullPointerDelete_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_NullPointerDelete_struct* self);
	void* (* __getvtable__)(struct cbcstd_NullPointerDelete_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_NullPointerDelete_struct* self, struct cbcstd_NullPointerDelete_struct* other);
	struct cbcstd_NullPointerDelete_struct* (* __operate__)(struct cbcstd_NullPointerDelete_struct* self, struct cbcstd_NullPointerDelete_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_NullPointerDelete_struct* self);
	cbcstd_String description_787;
} cbcstd_NullPointerDelete_struct;
typedef cbcstd_NullPointerDelete_struct* cbcstd_NullPointerDelete;
extern const class_id cbcstd_NullPointerDelete__classid__;
extern cbcstd_NullPointerDelete cbcstd_NullPointerDelete_create();
extern void cbcstd_NullPointerDelete_init(cbcstd_NullPointerDelete self);
extern void cbcstd_NullPointerDelete_initsystem(cbcstd_NullPointerDelete self);
extern void cbcstd_NullPointerDelete_inituser(cbcstd_NullPointerDelete self);
extern void cbcstd_NullPointerDelete_enduser(cbcstd_NullPointerDelete self);
extern void cbcstd_NullPointerDelete_end(cbcstd_NullPointerDelete self);

typedef struct cbcstd_NoExceptionError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_NoExceptionError_struct* self);
	void* (* __getvtable__)(struct cbcstd_NoExceptionError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_NoExceptionError_struct* self, struct cbcstd_NoExceptionError_struct* other);
	struct cbcstd_NoExceptionError_struct* (* __operate__)(struct cbcstd_NoExceptionError_struct* self, struct cbcstd_NoExceptionError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_NoExceptionError_struct* self);
	cbcstd_String description_787;
} cbcstd_NoExceptionError_struct;
typedef cbcstd_NoExceptionError_struct* cbcstd_NoExceptionError;
extern const class_id cbcstd_NoExceptionError__classid__;
extern cbcstd_NoExceptionError cbcstd_NoExceptionError_create();
extern void cbcstd_NoExceptionError_init(cbcstd_NoExceptionError self);
extern void cbcstd_NoExceptionError_initsystem(cbcstd_NoExceptionError self);
extern void cbcstd_NoExceptionError_inituser(cbcstd_NoExceptionError self);
extern void cbcstd_NoExceptionError_enduser(cbcstd_NoExceptionError self);
extern void cbcstd_NoExceptionError_end(cbcstd_NoExceptionError self);

typedef struct cbcstd_NotAnExceptionError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_NotAnExceptionError_struct* self);
	void* (* __getvtable__)(struct cbcstd_NotAnExceptionError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_NotAnExceptionError_struct* self, struct cbcstd_NotAnExceptionError_struct* other);
	struct cbcstd_NotAnExceptionError_struct* (* __operate__)(struct cbcstd_NotAnExceptionError_struct* self, struct cbcstd_NotAnExceptionError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_NotAnExceptionError_struct* self);
	cbcstd_String description_787;
} cbcstd_NotAnExceptionError_struct;
typedef cbcstd_NotAnExceptionError_struct* cbcstd_NotAnExceptionError;
extern const class_id cbcstd_NotAnExceptionError__classid__;
extern cbcstd_NotAnExceptionError cbcstd_NotAnExceptionError_create(cbcstd_Object thrown);
extern void cbcstd_NotAnExceptionError_init(cbcstd_NotAnExceptionError self, cbcstd_Object thrown);
extern void cbcstd_NotAnExceptionError_initsystem(cbcstd_NotAnExceptionError self);
extern void cbcstd_NotAnExceptionError_inituser(cbcstd_NotAnExceptionError self, cbcstd_Object thrown);
extern void cbcstd_NotAnExceptionError_enduser(cbcstd_NotAnExceptionError self);
extern void cbcstd_NotAnExceptionError_end(cbcstd_NotAnExceptionError self);

typedef struct cbcstd_CastExceptionError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_CastExceptionError_struct* self);
	void* (* __getvtable__)(struct cbcstd_CastExceptionError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_CastExceptionError_struct* self, struct cbcstd_CastExceptionError_struct* other);
	struct cbcstd_CastExceptionError_struct* (* __operate__)(struct cbcstd_CastExceptionError_struct* self, struct cbcstd_CastExceptionError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_CastExceptionError_struct* self);
	cbcstd_String description_787;
} cbcstd_CastExceptionError_struct;
typedef cbcstd_CastExceptionError_struct* cbcstd_CastExceptionError;
extern const class_id cbcstd_CastExceptionError__classid__;
extern cbcstd_CastExceptionError cbcstd_CastExceptionError_create(class_id src_obj, class_id dst_obj);
extern void cbcstd_CastExceptionError_init(cbcstd_CastExceptionError self, class_id src_obj, class_id dst_obj);
extern void cbcstd_CastExceptionError_initsystem(cbcstd_CastExceptionError self);
extern void cbcstd_CastExceptionError_inituser(cbcstd_CastExceptionError self, class_id src_obj, class_id dst_obj);
extern void cbcstd_CastExceptionError_enduser(cbcstd_CastExceptionError self);
extern void cbcstd_CastExceptionError_end(cbcstd_CastExceptionError self);

typedef struct cbcstd_ObjectCompareError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_ObjectCompareError_struct* self);
	void* (* __getvtable__)(struct cbcstd_ObjectCompareError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_ObjectCompareError_struct* self, struct cbcstd_ObjectCompareError_struct* other);
	struct cbcstd_ObjectCompareError_struct* (* __operate__)(struct cbcstd_ObjectCompareError_struct* self, struct cbcstd_ObjectCompareError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_ObjectCompareError_struct* self);
	cbcstd_String description_787;
} cbcstd_ObjectCompareError_struct;
typedef cbcstd_ObjectCompareError_struct* cbcstd_ObjectCompareError;
extern const class_id cbcstd_ObjectCompareError__classid__;
extern cbcstd_ObjectCompareError cbcstd_ObjectCompareError_create(class_id id1, class_id id2);
extern void cbcstd_ObjectCompareError_init(cbcstd_ObjectCompareError self, class_id id1, class_id id2);
extern void cbcstd_ObjectCompareError_initsystem(cbcstd_ObjectCompareError self);
extern void cbcstd_ObjectCompareError_inituser(cbcstd_ObjectCompareError self, class_id id1, class_id id2);
extern void cbcstd_ObjectCompareError_enduser(cbcstd_ObjectCompareError self);
extern void cbcstd_ObjectCompareError_end(cbcstd_ObjectCompareError self);

typedef struct cbcstd_ObjectOperateError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_ObjectOperateError_struct* self);
	void* (* __getvtable__)(struct cbcstd_ObjectOperateError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_ObjectOperateError_struct* self, struct cbcstd_ObjectOperateError_struct* other);
	struct cbcstd_ObjectOperateError_struct* (* __operate__)(struct cbcstd_ObjectOperateError_struct* self, struct cbcstd_ObjectOperateError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_ObjectOperateError_struct* self);
	cbcstd_String description_787;
} cbcstd_ObjectOperateError_struct;
typedef cbcstd_ObjectOperateError_struct* cbcstd_ObjectOperateError;
extern const class_id cbcstd_ObjectOperateError__classid__;
extern cbcstd_ObjectOperateError cbcstd_ObjectOperateError_create(class_id id1, class_id id2);
extern void cbcstd_ObjectOperateError_init(cbcstd_ObjectOperateError self, class_id id1, class_id id2);
extern void cbcstd_ObjectOperateError_initsystem(cbcstd_ObjectOperateError self);
extern void cbcstd_ObjectOperateError_inituser(cbcstd_ObjectOperateError self, class_id id1, class_id id2);
extern void cbcstd_ObjectOperateError_enduser(cbcstd_ObjectOperateError self);
extern void cbcstd_ObjectOperateError_end(cbcstd_ObjectOperateError self);

typedef struct cbcstd_InvalidObjectOperation_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_InvalidObjectOperation_struct* self);
	void* (* __getvtable__)(struct cbcstd_InvalidObjectOperation_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_InvalidObjectOperation_struct* self, struct cbcstd_InvalidObjectOperation_struct* other);
	struct cbcstd_InvalidObjectOperation_struct* (* __operate__)(struct cbcstd_InvalidObjectOperation_struct* self, struct cbcstd_InvalidObjectOperation_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_InvalidObjectOperation_struct* self);
	cbcstd_String description_787;
} cbcstd_InvalidObjectOperation_struct;
typedef cbcstd_InvalidObjectOperation_struct* cbcstd_InvalidObjectOperation;
extern const class_id cbcstd_InvalidObjectOperation__classid__;
extern cbcstd_InvalidObjectOperation cbcstd_InvalidObjectOperation_create(class_id id, char op);
extern void cbcstd_InvalidObjectOperation_init(cbcstd_InvalidObjectOperation self, class_id id, char op);
extern void cbcstd_InvalidObjectOperation_initsystem(cbcstd_InvalidObjectOperation self);
extern void cbcstd_InvalidObjectOperation_inituser(cbcstd_InvalidObjectOperation self, class_id id, char op);
extern void cbcstd_InvalidObjectOperation_enduser(cbcstd_InvalidObjectOperation self);
extern void cbcstd_InvalidObjectOperation_end(cbcstd_InvalidObjectOperation self);

typedef struct cbcstd_OutOfBounds_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_OutOfBounds_struct* self);
	void* (* __getvtable__)(struct cbcstd_OutOfBounds_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_OutOfBounds_struct* self, struct cbcstd_OutOfBounds_struct* other);
	struct cbcstd_OutOfBounds_struct* (* __operate__)(struct cbcstd_OutOfBounds_struct* self, struct cbcstd_OutOfBounds_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_OutOfBounds_struct* self);
	cbcstd_String description_787;
} cbcstd_OutOfBounds_struct;
typedef cbcstd_OutOfBounds_struct* cbcstd_OutOfBounds;
extern const class_id cbcstd_OutOfBounds__classid__;
extern cbcstd_OutOfBounds cbcstd_OutOfBounds_create();
extern void cbcstd_OutOfBounds_init(cbcstd_OutOfBounds self);
extern void cbcstd_OutOfBounds_initsystem(cbcstd_OutOfBounds self);
extern void cbcstd_OutOfBounds_inituser(cbcstd_OutOfBounds self);
extern void cbcstd_OutOfBounds_enduser(cbcstd_OutOfBounds self);
extern void cbcstd_OutOfBounds_end(cbcstd_OutOfBounds self);

typedef struct cbcstd_ArrayFull_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_ArrayFull_struct* self);
	void* (* __getvtable__)(struct cbcstd_ArrayFull_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_ArrayFull_struct* self, struct cbcstd_ArrayFull_struct* other);
	struct cbcstd_ArrayFull_struct* (* __operate__)(struct cbcstd_ArrayFull_struct* self, struct cbcstd_ArrayFull_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_ArrayFull_struct* self);
	cbcstd_String description_787;
} cbcstd_ArrayFull_struct;
typedef cbcstd_ArrayFull_struct* cbcstd_ArrayFull;
extern const class_id cbcstd_ArrayFull__classid__;
extern cbcstd_ArrayFull cbcstd_ArrayFull_create();
extern void cbcstd_ArrayFull_init(cbcstd_ArrayFull self);
extern void cbcstd_ArrayFull_initsystem(cbcstd_ArrayFull self);
extern void cbcstd_ArrayFull_inituser(cbcstd_ArrayFull self);
extern void cbcstd_ArrayFull_enduser(cbcstd_ArrayFull self);
extern void cbcstd_ArrayFull_end(cbcstd_ArrayFull self);

typedef struct _cbcstd_ListNode_struct* _cbcstd_ListNode; ;

typedef struct cbcstd_List_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_List_struct* self);
	void* (* __getvtable__)(struct cbcstd_List_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_List_struct* self, struct cbcstd_List_struct* other);
	struct cbcstd_List_struct* (* __operate__)(struct cbcstd_List_struct* self, struct cbcstd_List_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_List_struct* self);
	_cbcstd_ListNode (first_616);
	_cbcstd_ListNode (last_90);
	uint (cont_902);
	_cbcstd_ListNode (iter_item_194);
	void (* insert)(struct cbcstd_List_struct* self, cbcstd_Object data, int pos);
	cbcstd_Object (* get)(struct cbcstd_List_struct* self, int pos);
	cbcstd_Object (* getLast)(struct cbcstd_List_struct* self);
	void (* push)(struct cbcstd_List_struct* self, cbcstd_Object data);
	cbcstd_Object (* pop)(struct cbcstd_List_struct* self);
	void (* enqueue)(struct cbcstd_List_struct* self, cbcstd_Object data);
	cbcstd_Object (* dequeue)(struct cbcstd_List_struct* self);
	cbcstd_Object (* remove)(struct cbcstd_List_struct* self, int pos);
	void (* removeObject)(struct cbcstd_List_struct* self, cbcstd_Object data);
	bool (* contains)(struct cbcstd_List_struct* self, cbcstd_Object data);
	uint (* size)(struct cbcstd_List_struct* self);
	void (* clear)(struct cbcstd_List_struct* self);
	void (* __iterinit__)(struct cbcstd_List_struct* self, bool reversed);
	bool (* __iternext__)(struct cbcstd_List_struct* self, cbcstd_Object* dest);
	bool (* __iterprev__)(struct cbcstd_List_struct* self, cbcstd_Object* dest);
} cbcstd_List_struct;
typedef cbcstd_List_struct* cbcstd_List;
extern const class_id cbcstd_List__classid__;
extern cbcstd_List cbcstd_List_create();
extern void cbcstd_List_init(cbcstd_List self);
extern void cbcstd_List_initsystem(cbcstd_List self);
extern void cbcstd_List_inituser(cbcstd_List self);
extern void cbcstd_List_insert(cbcstd_List self, cbcstd_Object data, int pos);
extern cbcstd_Object cbcstd_List_get(cbcstd_List self, int pos);
extern cbcstd_Object cbcstd_List_getLast(cbcstd_List self);
extern void cbcstd_List_push(cbcstd_List self, cbcstd_Object data);
extern cbcstd_Object cbcstd_List_pop(cbcstd_List self);
extern void cbcstd_List_enqueue(cbcstd_List self, cbcstd_Object data);
extern cbcstd_Object cbcstd_List_dequeue(cbcstd_List self);
extern cbcstd_Object cbcstd_List_remove(cbcstd_List self, int pos);
extern void cbcstd_List_removeObject(cbcstd_List self, cbcstd_Object data);
extern bool cbcstd_List_contains(cbcstd_List self, cbcstd_Object data);
extern uint cbcstd_List_size(cbcstd_List self);
extern void cbcstd_List_clear(cbcstd_List self);
extern void cbcstd_List___iterinit__(cbcstd_List self, bool reversed);
extern bool cbcstd_List___iternext__(cbcstd_List self, cbcstd_Object* dest);
extern bool cbcstd_List___iterprev__(cbcstd_List self, cbcstd_Object* dest);
extern void* cbcstd_List___str__(cbcstd_List self);
extern void cbcstd_List_enduser(cbcstd_List self);
extern void cbcstd_List_end(cbcstd_List self);

typedef struct cbcstd_Array_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Array_struct* self);
	void* (* __getvtable__)(struct cbcstd_Array_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Array_struct* self, struct cbcstd_Array_struct* other);
	struct cbcstd_Array_struct* (* __operate__)(struct cbcstd_Array_struct* self, struct cbcstd_Array_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Array_struct* self);
	cbcstd_Object* (elems_407);
	size_t size_871;
	size_t max_336;
	size_t (iterator_212);
	void (* _setSize_57)(struct cbcstd_Array_struct* self, size_t size);
	void (* _setMax_529)(struct cbcstd_Array_struct* self, size_t max);
	void (* _checkIndex_236)(struct cbcstd_Array_struct* self, size_t index);
	void (* _checkSize_883)(struct cbcstd_Array_struct* self);
	cbcstd_Object (* get)(struct cbcstd_Array_struct* self, size_t index);
	void (* insert)(struct cbcstd_Array_struct* self, cbcstd_Object o, size_t index);
	void (* add)(struct cbcstd_Array_struct* self, cbcstd_Object o);
	cbcstd_Object (* remove)(struct cbcstd_Array_struct* self, size_t index);
	bool (* contains)(struct cbcstd_Array_struct* self, cbcstd_Object data);
	void (* __iterinit__)(struct cbcstd_Array_struct* self, bool reversed);
	bool (* __iternext__)(struct cbcstd_Array_struct* self, cbcstd_Object* dest);
	bool (* __iterprev__)(struct cbcstd_Array_struct* self, cbcstd_Object* dest);
} cbcstd_Array_struct;
typedef cbcstd_Array_struct* cbcstd_Array;
extern const class_id cbcstd_Array__classid__;
extern cbcstd_Array cbcstd_Array_create(size_t size);
extern void cbcstd_Array_init(cbcstd_Array self, size_t size);
extern void cbcstd_Array_initsystem(cbcstd_Array self);
extern void cbcstd_Array_inituser(cbcstd_Array self, size_t size);
extern void cbcstd_Array__setSize_57(cbcstd_Array self, size_t size);
extern void cbcstd_Array__setMax_529(cbcstd_Array self, size_t max);
extern void cbcstd_Array__checkIndex_236(cbcstd_Array self, size_t index);
extern void cbcstd_Array__checkSize_883(cbcstd_Array self);
extern cbcstd_Object cbcstd_Array_get(cbcstd_Array self, size_t index);
extern void cbcstd_Array_insert(cbcstd_Array self, cbcstd_Object o, size_t index);
extern void cbcstd_Array_add(cbcstd_Array self, cbcstd_Object o);
extern cbcstd_Object cbcstd_Array_remove(cbcstd_Array self, size_t index);
extern bool cbcstd_Array_contains(cbcstd_Array self, cbcstd_Object data);
extern void cbcstd_Array___iterinit__(cbcstd_Array self, bool reversed);
extern bool cbcstd_Array___iternext__(cbcstd_Array self, cbcstd_Object* dest);
extern bool cbcstd_Array___iterprev__(cbcstd_Array self, cbcstd_Object* dest);
extern void* cbcstd_Array___str__(cbcstd_Array self);
extern void cbcstd_Array_enduser(cbcstd_Array self);
extern void cbcstd_Array_end(cbcstd_Array self);

typedef struct cbcstd_Vector_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_Vector_struct* self);
	void* (* __getvtable__)(struct cbcstd_Vector_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_Vector_struct* self, struct cbcstd_Vector_struct* other);
	struct cbcstd_Vector_struct* (* __operate__)(struct cbcstd_Vector_struct* self, struct cbcstd_Vector_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_Vector_struct* self);
	cbcstd_Object* (elems_407);
	size_t size_871;
	size_t max_336;
	size_t (iterator_212);
	void (* _setSize_57)(struct cbcstd_Vector_struct* self, size_t size);
	void (* _setMax_529)(struct cbcstd_Vector_struct* self, size_t max);
	void (* _checkIndex_236)(struct cbcstd_Vector_struct* self, size_t index);
	void (* _checkSize_883)(struct cbcstd_Vector_struct* self);
	cbcstd_Object (* get)(struct cbcstd_Vector_struct* self, size_t index);
	void (* insert)(struct cbcstd_Vector_struct* self, cbcstd_Object o, size_t index);
	void (* add)(struct cbcstd_Vector_struct* self, cbcstd_Object o);
	cbcstd_Object (* remove)(struct cbcstd_Vector_struct* self, size_t index);
	bool (* contains)(struct cbcstd_Vector_struct* self, cbcstd_Object data);
	void (* __iterinit__)(struct cbcstd_Vector_struct* self, bool reversed);
	bool (* __iternext__)(struct cbcstd_Vector_struct* self, cbcstd_Object* dest);
	bool (* __iterprev__)(struct cbcstd_Vector_struct* self, cbcstd_Object* dest);
	void (* _resize_466)(struct cbcstd_Vector_struct* self, int newSize);
	void (* fit)(struct cbcstd_Vector_struct* self);
} cbcstd_Vector_struct;
typedef cbcstd_Vector_struct* cbcstd_Vector;
extern const class_id cbcstd_Vector__classid__;
extern cbcstd_Vector cbcstd_Vector_create();
extern void cbcstd_Vector_init(cbcstd_Vector self);
extern void cbcstd_Vector_initsystem(cbcstd_Vector self);
extern void cbcstd_Vector_inituser(cbcstd_Vector self);
extern void cbcstd_Vector__checkSize_883(cbcstd_Vector self);
extern void cbcstd_Vector__resize_466(cbcstd_Vector self, int newSize);
extern void cbcstd_Vector_fit(cbcstd_Vector self);
extern void cbcstd_Vector_enduser(cbcstd_Vector self);
extern void cbcstd_Vector_end(cbcstd_Vector self);

typedef struct cbcstd_IOError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_IOError_struct* self);
	void* (* __getvtable__)(struct cbcstd_IOError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_IOError_struct* self, struct cbcstd_IOError_struct* other);
	struct cbcstd_IOError_struct* (* __operate__)(struct cbcstd_IOError_struct* self, struct cbcstd_IOError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_IOError_struct* self);
	cbcstd_String description_787;
} cbcstd_IOError_struct;
typedef cbcstd_IOError_struct* cbcstd_IOError;
extern const class_id cbcstd_IOError__classid__;
extern cbcstd_IOError cbcstd_IOError_create(char* fileName);
extern void cbcstd_IOError_init(cbcstd_IOError self, char* fileName);
extern void cbcstd_IOError_initsystem(cbcstd_IOError self);
extern void cbcstd_IOError_inituser(cbcstd_IOError self, char* fileName);
extern void cbcstd_IOError_enduser(cbcstd_IOError self);
extern void cbcstd_IOError_end(cbcstd_IOError self);

typedef struct cbcstd_File_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_File_struct* self);
	void* (* __getvtable__)(struct cbcstd_File_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_File_struct* self, struct cbcstd_File_struct* other);
	struct cbcstd_File_struct* (* __operate__)(struct cbcstd_File_struct* self, struct cbcstd_File_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_File_struct* self);
	FILE* id_56;
	cbcstd_String path_646;
	cbcstd_String mode_821;
	size_t size_765;
	void (* _setPath_528)(struct cbcstd_File_struct* self, cbcstd_String path);
	void (* _setMode_70)(struct cbcstd_File_struct* self, cbcstd_String mode);
	void (* _setId_698)(struct cbcstd_File_struct* self, FILE* id);
	void (* _setSize_163)(struct cbcstd_File_struct* self, size_t size);
	size_t (* readAll)(struct cbcstd_File_struct* self, void* ptr);
	size_t (* read)(struct cbcstd_File_struct* self, void* ptr, size_t size, size_t count);
	size_t (* write)(struct cbcstd_File_struct* self, const void* ptr, size_t size, size_t count);
	size_t (* writeString)(struct cbcstd_File_struct* self, cbcstd_String str);
	int (* seek_from)(struct cbcstd_File_struct* self, long offset, int origin);
	int (* seek)(struct cbcstd_File_struct* self, long int offset);
	long (* tell)(struct cbcstd_File_struct* self);
	long (* findNextChar)(struct cbcstd_File_struct* self, char c);
	cbcstd_String (* readline)(struct cbcstd_File_struct* self);
	cbcstd_List (* readlines)(struct cbcstd_File_struct* self);
} cbcstd_File_struct;
typedef cbcstd_File_struct* cbcstd_File;
extern const class_id cbcstd_File__classid__;
extern cbcstd_File cbcstd_File_create(char* path, char* mode);
extern void cbcstd_File_init(cbcstd_File self, char* path, char* mode);
extern void cbcstd_File_initsystem(cbcstd_File self);
extern void cbcstd_File_inituser(cbcstd_File self, char* path, char* mode);
extern void cbcstd_File__setPath_528(cbcstd_File self, cbcstd_String path);
extern void cbcstd_File__setMode_70(cbcstd_File self, cbcstd_String mode);
extern void cbcstd_File__setId_698(cbcstd_File self, FILE* id);
extern void cbcstd_File__setSize_163(cbcstd_File self, size_t size);
extern size_t cbcstd_File_readAll(cbcstd_File self, void* ptr);
extern size_t cbcstd_File_read(cbcstd_File self, void* ptr, size_t size, size_t count);
extern size_t cbcstd_File_write(cbcstd_File self, const void* ptr, size_t size, size_t count);
extern size_t cbcstd_File_writeString(cbcstd_File self, cbcstd_String str);
extern int cbcstd_File_seek_from(cbcstd_File self, long offset, int origin);
extern int cbcstd_File_seek(cbcstd_File self, long int offset);
extern long cbcstd_File_tell(cbcstd_File self);
extern long cbcstd_File_findNextChar(cbcstd_File self, char c);
extern cbcstd_String cbcstd_File_readline(cbcstd_File self);
extern cbcstd_List cbcstd_File_readlines(cbcstd_File self);
extern void cbcstd_File_enduser(cbcstd_File self);
extern void cbcstd_File_end(cbcstd_File self);

typedef struct cbcstd_ResettingGCStateException_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_ResettingGCStateException_struct* self);
	void* (* __getvtable__)(struct cbcstd_ResettingGCStateException_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_ResettingGCStateException_struct* self, struct cbcstd_ResettingGCStateException_struct* other);
	struct cbcstd_ResettingGCStateException_struct* (* __operate__)(struct cbcstd_ResettingGCStateException_struct* self, struct cbcstd_ResettingGCStateException_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_ResettingGCStateException_struct* self);
	cbcstd_String description_787;
} cbcstd_ResettingGCStateException_struct;
typedef cbcstd_ResettingGCStateException_struct* cbcstd_ResettingGCStateException;
extern const class_id cbcstd_ResettingGCStateException__classid__;
extern cbcstd_ResettingGCStateException cbcstd_ResettingGCStateException_create();
extern void cbcstd_ResettingGCStateException_init(cbcstd_ResettingGCStateException self);
extern void cbcstd_ResettingGCStateException_initsystem(cbcstd_ResettingGCStateException self);
extern void cbcstd_ResettingGCStateException_inituser(cbcstd_ResettingGCStateException self);
extern void cbcstd_ResettingGCStateException_enduser(cbcstd_ResettingGCStateException self);
extern void cbcstd_ResettingGCStateException_end(cbcstd_ResettingGCStateException self);

typedef struct cbcstd_UnsafeDeleteError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_UnsafeDeleteError_struct* self);
	void* (* __getvtable__)(struct cbcstd_UnsafeDeleteError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_UnsafeDeleteError_struct* self, struct cbcstd_UnsafeDeleteError_struct* other);
	struct cbcstd_UnsafeDeleteError_struct* (* __operate__)(struct cbcstd_UnsafeDeleteError_struct* self, struct cbcstd_UnsafeDeleteError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_UnsafeDeleteError_struct* self);
	cbcstd_String description_787;
} cbcstd_UnsafeDeleteError_struct;
typedef cbcstd_UnsafeDeleteError_struct* cbcstd_UnsafeDeleteError;
extern const class_id cbcstd_UnsafeDeleteError__classid__;
extern cbcstd_UnsafeDeleteError cbcstd_UnsafeDeleteError_create(cbcstd_Object o);
extern void cbcstd_UnsafeDeleteError_init(cbcstd_UnsafeDeleteError self, cbcstd_Object o);
extern void cbcstd_UnsafeDeleteError_initsystem(cbcstd_UnsafeDeleteError self);
extern void cbcstd_UnsafeDeleteError_inituser(cbcstd_UnsafeDeleteError self, cbcstd_Object o);
extern void cbcstd_UnsafeDeleteError_enduser(cbcstd_UnsafeDeleteError self);
extern void cbcstd_UnsafeDeleteError_end(cbcstd_UnsafeDeleteError self);

extern void cbcstd_gcFlush();

extern void cbcstd_gcSetState(bool state);

extern void cbcstd_gcIncRef(cbcstd_Object o);

extern void cbcstd_gcDecRef(cbcstd_Object o);

extern void cbcstd_gcDecRefOnly(cbcstd_Object o);

extern bool cbcstd_gcCheckRefs(cbcstd_Object o);

extern void cbcstd_gcAssign(void** dst, void* src);

extern void cbcstd_gcAssignDeclared(void** dst, void* src);

typedef struct cbcstd_PrintFormatError_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cbcstd_PrintFormatError_struct* self);
	void* (* __getvtable__)(struct cbcstd_PrintFormatError_struct* self, class_id id);
	int (* __cmp__)(struct cbcstd_PrintFormatError_struct* self, struct cbcstd_PrintFormatError_struct* other);
	struct cbcstd_PrintFormatError_struct* (* __operate__)(struct cbcstd_PrintFormatError_struct* self, struct cbcstd_PrintFormatError_struct* other, char op, bool modify);
	void* (* __str__)(struct cbcstd_PrintFormatError_struct* self);
	cbcstd_String description_787;
} cbcstd_PrintFormatError_struct;
typedef cbcstd_PrintFormatError_struct* cbcstd_PrintFormatError;
extern const class_id cbcstd_PrintFormatError__classid__;
extern cbcstd_PrintFormatError cbcstd_PrintFormatError_create(char format);
extern void cbcstd_PrintFormatError_init(cbcstd_PrintFormatError self, char format);
extern void cbcstd_PrintFormatError_initsystem(cbcstd_PrintFormatError self);
extern void cbcstd_PrintFormatError_inituser(cbcstd_PrintFormatError self, char format);
extern void cbcstd_PrintFormatError_enduser(cbcstd_PrintFormatError self);
extern void cbcstd_PrintFormatError_end(cbcstd_PrintFormatError self);

extern void cbcstd_print(char* format, ...);

extern void cbcstd_debugUseless(void* unused);

extern void cbcstd_setTraceEnd(long* trace_end);

extern void cbcstd_printStackTrace();

extern cbcstd_Array cbcstd_args;

extern void cbcstd_setArguments(int argc, char** argv);

extern bool cbcstd_isinstanceof(cbcstd_Object o, class_id classid);

extern bool cbcstd_istypeof(cbcstd_Object o, class_id classid);

extern bool cbcstd_isidof(class_id var, class_id classid);

extern void* cbcstd_alloc(size_t bytes);

extern void cbcstd_destroy(void** ptr);

extern void cbcstd_destroyObj(cbcstd_Object* o);

extern cbcstd_Object cbcstd_objectOperate(cbcstd_Object src, cbcstd_Object other, char op, bool modify, bool eliminateOther);

extern int cbcstd_objectCompare(cbcstd_Object src, cbcstd_Object other);

extern void cbcstd_init();




































#ifdef __cplusplus
};
#endif


#endif//
