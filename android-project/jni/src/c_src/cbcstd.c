#include <cbc.h>
// public globals
#include <cbcstd.h>
// private globals
const class_id cbcstd_Object__classid__ = -877637167666370448;
const class_id cbcstd_NoneType__classid__ = -4663083493084273847;
const class_id cbcstd_String__classid__ = 2550212425436845054;
const class_id cbcstd_Int__classid__ = 4961335359079827921;
const class_id cbcstd_Hex__classid__ = 4961334359212828405;
const class_id cbcstd_Float__classid__ = 7476372606712929682;
const class_id cbcstd_Char__classid__ = 190749352912602767;
const class_id cbcstd_Bool__classid__ = -809376647758398005;
const class_id cbcstd_Buffer__classid__ = 6625435829950324627;
const class_id cbcstd_Thread__classid__ = -9090379707872346563;
const class_id cbcstd_Semaphore__classid__ = 5933085328435303454;
const class_id cbcstd_Mutex__classid__ = -158163739585143091;
const class_id cbcstd_Exception__classid__ = 7143736340794888939;
const class_id cbcstd_CriticalException__classid__ = 5845670225932612062;
const class_id cbcstd_SystemError__classid__ = -1736802566581406411;
const class_id cbcstd_SystemExit__classid__ = -1426973790750071894;
const class_id cbcstd_OutOfMemoryError__classid__ = -2971450260061360241;
const class_id cbcstd_NullPointerDelete__classid__ = 4684775427116870887;
const class_id cbcstd_NoExceptionError__classid__ = 4630710885004494525;
const class_id cbcstd_NotAnExceptionError__classid__ = 524310300948615443;
const class_id cbcstd_CastExceptionError__classid__ = 5629177208595920035;
const class_id cbcstd_ObjectCompareError__classid__ = 6753687413457036265;
const class_id cbcstd_ObjectOperateError__classid__ = 5828251413358395306;
const class_id cbcstd_InvalidObjectOperation__classid__ = 8157800301877777374;
const class_id cbcstd_OutOfBounds__classid__ = -4541178489538158438;
const class_id cbcstd_ArrayFull__classid__ = -7844554939348106996;
const class_id cbcstd_List__classid__ = 9190911353623603763;
const class_id cbcstd_Array__classid__ = -8969464831777141981;
const class_id cbcstd_Vector__classid__ = 398200037585603112;
const class_id cbcstd_IOError__classid__ = 7574766057929006304;
const class_id cbcstd_File__classid__ = 3190857353556604009;
const class_id cbcstd_ResettingGCStateException__classid__ = 8528344343163115145;
const class_id cbcstd_UnsafeDeleteError__classid__ = -5718326853095492329;
const class_id cbcstd_PrintFormatError__classid__ = 4810669106351579541;
static cbcstd_Object (cbcstd___None__) = NULL;

static cbcstd_Bool (cbcstd___bools__)[2] = {NULL, NULL};

const class_id _cbcstd_ObjectLock__classid__ = 4927563655615894095;
typedef struct _cbcstd_ObjectLock_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct _cbcstd_ObjectLock_struct* self);
	void* (* __getvtable__)(struct _cbcstd_ObjectLock_struct* self, class_id id);
	int (* __cmp__)(struct _cbcstd_ObjectLock_struct* self, struct _cbcstd_ObjectLock_struct* other);
	struct _cbcstd_ObjectLock_struct* (* __operate__)(struct _cbcstd_ObjectLock_struct* self, struct _cbcstd_ObjectLock_struct* other, char op, bool modify);
	void* (* __str__)(struct _cbcstd_ObjectLock_struct* self);
	cbcstd_thread_t (owner_871);
	cbcstd_Semaphore (sema_115);
	cbcstd_Semaphore (owner_sema_73);
	cbcstd_MutexType (type_922);
	int (ignore_9);
	void (* wait)(struct _cbcstd_ObjectLock_struct* self);
	void (* release)(struct _cbcstd_ObjectLock_struct* self);
} _cbcstd_ObjectLock_struct;
typedef _cbcstd_ObjectLock_struct* _cbcstd_ObjectLock;
extern const class_id _cbcstd_ObjectLock__classid__;
extern _cbcstd_ObjectLock _cbcstd_ObjectLock_create();
extern void _cbcstd_ObjectLock_init(_cbcstd_ObjectLock self);
extern void _cbcstd_ObjectLock_initsystem(_cbcstd_ObjectLock self);
extern void _cbcstd_ObjectLock_inituser(_cbcstd_ObjectLock self);
extern void _cbcstd_ObjectLock_enduser(_cbcstd_ObjectLock self);
extern void _cbcstd_ObjectLock_end(_cbcstd_ObjectLock self);

typedef struct _cbcstd_JumpBuffer{
	jmp_buf buffer;
	struct _cbcstd_JumpBuffer* next;
} _cbcstd_JumpBuffer;
extern void _cbcstd_JumpBuffer_enduser(_cbcstd_JumpBuffer self);
extern void _cbcstd_JumpBuffer_end(_cbcstd_JumpBuffer self);

typedef struct _cbcstd_ExceptionThreadBuffer{
	cbcstd_thread_t thread;
	_cbcstd_JumpBuffer* cur_buf;
	cbcstd_Exception cur_exception;
	struct _cbcstd_ExceptionThreadBuffer* next;
} _cbcstd_ExceptionThreadBuffer;
extern void _cbcstd_ExceptionThreadBuffer_enduser(_cbcstd_ExceptionThreadBuffer self);
extern void _cbcstd_ExceptionThreadBuffer_end(_cbcstd_ExceptionThreadBuffer self);

typedef struct _cbcstd_CriticalExceptionHandler{
	class_id exception_id;
	cbcstd_Exception (* handler)(cbcstd_CriticalException);
	struct _cbcstd_CriticalExceptionHandler* next;
} _cbcstd_CriticalExceptionHandler;
extern void _cbcstd_CriticalExceptionHandler_enduser(_cbcstd_CriticalExceptionHandler self);
extern void _cbcstd_CriticalExceptionHandler_end(_cbcstd_CriticalExceptionHandler self);

static _cbcstd_ExceptionThreadBuffer* (cbcstd_start_buf) = NULL;

static _cbcstd_CriticalExceptionHandler* (cbcstd_handler_start) = NULL;

static cbcstd_Exception (cbcstd_std_exception) = NULL;

static cbcstd_Exception (cbcstd_critical_memory) = NULL;

static cbcstd_Mutex (cbcstd_excep_mutex) = NULL;

static void _cbcstd_waitExcepMutex();

static void _cbcstd_releaseExcepMutex();

static _cbcstd_CriticalExceptionHandler* _cbcstd_getCExceptionHandler(class_id classid);

static _cbcstd_ExceptionThreadBuffer* _cbcstd_getCurrentThreadBuffer();

static cbcstd_Exception _cbcstd_getRaisedException(_cbcstd_ExceptionThreadBuffer* cur_buffer);

static void _cbcstd_unhandledException(cbcstd_Exception e);

const class_id _cbcstd_ListNode__classid__ = -1327961035415945311;
typedef struct _cbcstd_ListNode_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct _cbcstd_ListNode_struct* self);
	void* (* __getvtable__)(struct _cbcstd_ListNode_struct* self, class_id id);
	int (* __cmp__)(struct _cbcstd_ListNode_struct* self, struct _cbcstd_ListNode_struct* other);
	struct _cbcstd_ListNode_struct* (* __operate__)(struct _cbcstd_ListNode_struct* self, struct _cbcstd_ListNode_struct* other, char op, bool modify);
	void* (* __str__)(struct _cbcstd_ListNode_struct* self);
	cbcstd_Object data_981;
	struct _cbcstd_ListNode_struct* next_266;
	struct _cbcstd_ListNode_struct* prev_568;
	void (* insert)(struct _cbcstd_ListNode_struct* self, cbcstd_Object data, int pos);
	cbcstd_Object (* get)(struct _cbcstd_ListNode_struct* self, int pos);
	struct _cbcstd_ListNode_struct* (* remove)(struct _cbcstd_ListNode_struct* self, int pos);
} _cbcstd_ListNode_struct;
typedef _cbcstd_ListNode_struct* _cbcstd_ListNode;
extern const class_id _cbcstd_ListNode__classid__;
extern _cbcstd_ListNode _cbcstd_ListNode_create(cbcstd_Object data);
extern void _cbcstd_ListNode_init(_cbcstd_ListNode self, cbcstd_Object data);
extern void _cbcstd_ListNode_initsystem(_cbcstd_ListNode self);
extern void _cbcstd_ListNode_inituser(_cbcstd_ListNode self, cbcstd_Object data);
extern void _cbcstd_ListNode_insert(_cbcstd_ListNode self, cbcstd_Object data, int pos);
extern cbcstd_Object _cbcstd_ListNode_get(_cbcstd_ListNode self, int pos);
extern _cbcstd_ListNode _cbcstd_ListNode_remove(_cbcstd_ListNode self, int pos);
extern void _cbcstd_ListNode___str__(_cbcstd_ListNode self);
extern void _cbcstd_ListNode_enduser(_cbcstd_ListNode self);
extern void _cbcstd_ListNode_end(_cbcstd_ListNode self);

static bool (cbcstd_gc_enable) = false;

static bool (cbcstd_gc_set) = false;

static cbcstd_Object (cbcstd_to_remove)[20] = {NULL};

static unsigned char (cbcstd_gc_counter) = 0;

static cbcstd_Mutex (cbcstd_gc_mutex) = NULL;

static void _cbcstd_waitGcMutex();

static void _cbcstd_releaseGcMutex();

static bool _cbcstd_objectCollected(cbcstd_Object o);

static void _cbcstd_destroyCollectedObjects();

static void _cbcstd_collectObject(cbcstd_Object o);

static void _cbcstd_gcDecRefCommon(cbcstd_Object o);

static void _cbcstd_gcAssignCommon(void** dst, void* src, bool isDeclared);

static int cbcstd__argc = 0;

static char** cbcstd__argv = NULL;

static void _cbcstd_parseArguments();

static bool _cbcstd_checkPtr(void* ptr);

//































































cbcstd_Object cbcstd_Object_create(){
	cbcstd_Object self = (cbcstd_Object)cbcstd_alloc(sizeof(cbcstd_Object_struct));
	try{
		cbcstd_Object_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Object_init(cbcstd_Object self){
	cbcstd_Object_initsystem(self);
	cbcstd_Object_inituser(self);
}
void cbcstd_Object_initsystem(cbcstd_Object self){
	const static class_id __classid__[2] = {
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Object_struct);
	self->__getvtable__ = &cbcstd_Object___getvtable__;
	self->__cmp__ = &cbcstd_Object___cmp__;
	self->__operate__ = &cbcstd_Object___operate__;
	self->__str__ = &cbcstd_Object___str__;
	self->__end__ = &cbcstd_Object_end;
}
void cbcstd_Object_end(cbcstd_Object self){
	cbcstd_Object_enduser(self);
	cbcstd_Object_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Object_decrefs(cbcstd_Object self){
}










	
	




	




	




	






void cbcstd_Object_inituser(cbcstd_Object self){
	return;



}

void cbcstd_Object_enduser(cbcstd_Object self){
	return;


}

void* cbcstd_Object___getvtable__(cbcstd_Object self, class_id id){
	return self;





}

int cbcstd_Object___cmp__(cbcstd_Object self, cbcstd_Object other){
	if (self > other){
		return 1;
	}

	return -1;


}

cbcstd_Object cbcstd_Object___operate__(cbcstd_Object self, cbcstd_Object other, char op, bool modify){
	switch (op){
		case '+': return ((size_t)self)+((size_t)other);
		case '-': return ((size_t)self)-((size_t)other);
		case '*': return ((size_t)self)*((size_t)other);
		case '/': return ((size_t)self)/((size_t)other);
		case '^': return ((size_t)self)^((size_t)other);
		case '&': return ((size_t)self)&((size_t)other);
		case '|': return ((size_t)self)|((size_t)other);
		case '~': return ~((size_t)self);
		case '%': return ((size_t)self)%((size_t)other);
		case 'i': return ((size_t)self)+1;
		case 'd': return ((size_t)self)-1;
		default:{

			cthrow((cbcstd_Exception)(cbcstd_InvalidObjectOperation_create(self->__type__[0], op)));
		}

	}

	return self;



}

void* cbcstd_Object___str__(cbcstd_Object self){
	char tmp[128];
	printf("printing object data to tmp\n");

	snprintf(tmp, 128, "<Object of type %d at 0x%zx>", self->__type__[0], (size_t)self);
	printf("returning new string\n");
	return cbcstd_String_create(tmp);

}


static bool hasNone = false;
cbcstd_NoneType cbcstd_NoneType_create(){
	cbcstd_NoneType self = (cbcstd_NoneType)cbcstd_alloc(sizeof(cbcstd_NoneType_struct));
	try{
		cbcstd_NoneType_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_NoneType_init(cbcstd_NoneType self){
	cbcstd_NoneType_initsystem(self);
	cbcstd_NoneType_inituser(self);
}
void cbcstd_NoneType_initsystem(cbcstd_NoneType self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-4663083493084273847L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_NoneType_struct);
	self->__str__ = &cbcstd_NoneType___str__;
	self->__end__ = &cbcstd_NoneType_end;
}
void cbcstd_NoneType_end(cbcstd_NoneType self){
	cbcstd_NoneType_enduser(self);
	cbcstd_NoneType_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_NoneType_decrefs(cbcstd_NoneType self){
}


void cbcstd_NoneType_inituser(cbcstd_NoneType self){
	if (hasNone){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Violation Error: You cannot create an instance of NoneType")));
	}

	hasNone = true;


}

void cbcstd_NoneType_enduser(cbcstd_NoneType self){
		cbcstd_Object_enduser((cbcstd_Object)self);
	cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Violation Error: You cannot delete an instance of NoneType")));

}

void* cbcstd_NoneType___str__(cbcstd_NoneType self){
	return cbcstd_String_create("None");

}


cbcstd_Object cbcstd_getNone(){
	return cbcstd___None__;







}

size_t cbcstd_npos = -1;

cbcstd_String cbcstd_String_create(char* orig){
	cbcstd_String self = (cbcstd_String)cbcstd_alloc(sizeof(cbcstd_String_struct));
	try{
		cbcstd_String_init(self, orig);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_String_init(cbcstd_String self, char* orig){
	cbcstd_String_initsystem(self);
	cbcstd_String_inituser(self, orig);
}
void cbcstd_String_initsystem(cbcstd_String self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		2550212425436845054L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_String_struct);
	self->c_str = &cbcstd_String_c_str;
	self->__iterinit__ = &cbcstd_String___iterinit__;
	self->__iternext__ = &cbcstd_String___iternext__;
	self->__iterprev__ = &cbcstd_String___iterprev__;
	self->_hash_661 = &cbcstd_String__hash_661;
	self->hash = &cbcstd_String_hash;
	self->size = &cbcstd_String_size;
	self->__cmp__ = &cbcstd_String___cmp__;
	self->equals = &cbcstd_String_equals;
	self->span = &cbcstd_String_span;
	self->pbrk = &cbcstd_String_pbrk;
	self->rfindChar = &cbcstd_String_rfindChar;
	self->findChar = &cbcstd_String_findChar;
	self->rfind = &cbcstd_String_rfind;
	self->find = &cbcstd_String_find;
	self->exists = &cbcstd_String_exists;
	self->charExists = &cbcstd_String_charExists;
	self->copy = &cbcstd_String_copy;
	self->substr = &cbcstd_String_substr;
	self->get = &cbcstd_String_get;
	self->cat = &cbcstd_String_cat;
	self->capitalize = &cbcstd_String_capitalize;
	self->count = &cbcstd_String_count;
	self->endswith = &cbcstd_String_endswith;
	self->startswith = &cbcstd_String_startswith;
	self->expandTabs = &cbcstd_String_expandTabs;
	self->isWhitespaceChar = &cbcstd_String_isWhitespaceChar;
	self->isNumericChar = &cbcstd_String_isNumericChar;
	self->isAlphaChar = &cbcstd_String_isAlphaChar;
	self->isAlphanumericChar = &cbcstd_String_isAlphanumericChar;
	self->isAlphaNumeric = &cbcstd_String_isAlphaNumeric;
	self->isAlpha = &cbcstd_String_isAlpha;
	self->isNumeric = &cbcstd_String_isNumeric;
	self->isHexadecimal = &cbcstd_String_isHexadecimal;
	self->isFloat = &cbcstd_String_isFloat;
	self->isBinary = &cbcstd_String_isBinary;
	self->isOctal = &cbcstd_String_isOctal;
	self->isLower = &cbcstd_String_isLower;
	self->isUpper = &cbcstd_String_isUpper;
	self->isWhitespace = &cbcstd_String_isWhitespace;
	self->ljustChar = &cbcstd_String_ljustChar;
	self->rjust = &cbcstd_String_rjust;
	self->lower = &cbcstd_String_lower;
	self->upper = &cbcstd_String_upper;
	self->swapcase = &cbcstd_String_swapcase;
	self->replace = &cbcstd_String_replace;
	self->rstrip = &cbcstd_String_rstrip;
	self->lstrip = &cbcstd_String_lstrip;
	self->strip = &cbcstd_String_strip;
	self->print = &cbcstd_String_print;
	self->println = &cbcstd_String_println;
	self->__str__ = &cbcstd_String___str__;
	self->__end__ = &cbcstd_String_end;
}
void cbcstd_String_end(cbcstd_String self){
	cbcstd_String_enduser(self);
	cbcstd_String_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_String_decrefs(cbcstd_String self){
}






	
void cbcstd_String_inituser(cbcstd_String self, char* orig){

	self->len_309 = strlen(orig)+1;


	self->cstr_267 = CBC_NEW(char, self->len_309);

	self->hash_value_431 = -1;


	strncpy(self->cstr_267, orig, self->len_309);


}

char* cbcstd_String_c_str(cbcstd_String self){

	return self->cstr_267;


}

void cbcstd_String___iterinit__(cbcstd_String self, bool reversed){
	if (reversed){


		self->iter_count_217 = self->len_309-1;
	}

	else{

		self->iter_count_217 = 0;

	}


}

bool cbcstd_String___iternext__(cbcstd_String self, char* dest){


	if (self->iter_count_217 < self->len_309){


		(*dest) = self->cstr_267[self->iter_count_217];

		self->iter_count_217++;
		return true;
	}

	return false;


}

bool cbcstd_String___iterprev__(cbcstd_String self, char* dest){

	if (self->iter_count_217 >= 0){


		(*dest) = self->cstr_267[self->iter_count_217];

		self->iter_count_217 --;
		return true;
	}

	return false;


}

long cbcstd_String__hash_661(cbcstd_String self){

	ssize_t len = self->len_309 - 1;

	unsigned char* p = self->cstr_267;

	long x = *p << 7;

	while (--len >= 0){
		x = (1000003*x) ^ *p++;

	}


	x ^= (self->len_309-1);


	self->hash_value_431 = (x == -1)? -2 : x;

	return self->hash_value_431;


}

long cbcstd_String_hash(cbcstd_String self){



	return (self->hash_value_431 != -1)? self->hash_value_431 : self->_hash_661(self);


}

size_t cbcstd_String_size(cbcstd_String self){

	return self->len_309;

}

int cbcstd_String___cmp__(cbcstd_String self, cbcstd_String other){



	return strncmp(self->cstr_267, other->c_str(other), self->len_309);


}

bool cbcstd_String_equals(cbcstd_String self, char* other){


	return strncmp(self->cstr_267, other, self->len_309) == 0;


}

size_t cbcstd_String_span(cbcstd_String self, char* chars){
	cbcstd_String Chars = cbcstd_String_create(chars);

	{int i=0; for (; i<self->len_309; i++){


		if (Chars->findChar(Chars, *(self->cstr_267+i), 0)){
			return i;
		}

	}}


	return self->len_309;

}

cbcstd_String cbcstd_String_pbrk(cbcstd_String self, char* chars){
	cbcstd_String Chars = cbcstd_String_create(chars);

	{int i=0; for (; i<self->len_309; i++){


		if (Chars->findChar(Chars, *(self->cstr_267+i), 0)){

			return cbcstd_String_create((self->cstr_267+i));
		}

	}}

	return NULL;


}

size_t cbcstd_String_rfindChar(cbcstd_String self, char search, size_t pos){

	if (pos > self->len_309){

		pos = self->len_309-1;
	
	}

	{int i=pos; for (; i>=0; i--){

		if (*(self->cstr_267+i) == search){
			return i;
		}

	}}

	return cbcstd_npos;


}

size_t cbcstd_String_findChar(cbcstd_String self, char search, size_t pos){
	if (pos < 0){
		pos = 0;
	
	}


	{int i=pos; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == search){
			return i;
		}

	}}

	return cbcstd_npos;


}

size_t cbcstd_String_rfind(cbcstd_String self, char* search, size_t pos){

	if (pos > self->len_309){

		pos = self->len_309-1;
	
	}

	{int i=pos; for (; i>=0; i--){

		if (strncmp((self->cstr_267+i), search, strlen(search)) == 0){
			return i;
		}

	}}

	return cbcstd_npos;
	

}

size_t cbcstd_String_find(cbcstd_String self, char* search, size_t pos){
	if (pos < 0){
		pos = 0;
	
	}


	{int i=pos; for (; i<self->len_309; i++){

		if (strncmp((self->cstr_267+i), search, strlen(search)) == 0){
			return i;
		}

	}}

	return cbcstd_npos;


}

bool cbcstd_String_exists(cbcstd_String self, char* search){

	return self->find(self, search, 0) < cbcstd_npos;


}

bool cbcstd_String_charExists(cbcstd_String self, char search){

	return self->findChar(self, search, 0) < cbcstd_npos;

}

cbcstd_String cbcstd_String_copy(cbcstd_String self){

	return cbcstd_String_create(self->cstr_267);


}

cbcstd_String cbcstd_String_substr(cbcstd_String self, size_t start, size_t end){


	if (start >= self->len_309){
		start = 0;
	
	}


	if (end >= self->len_309){

		end = self->len_309-1;
	
	}


	char* newStr = (char*)strndup(self->cstr_267+start, end-start);
	cbcstd_String ret = cbcstd_String_create(newStr);
	free(newStr);
	return ret;
	


}

char cbcstd_String_get(cbcstd_String self, size_t pos){

	if (pos > self->len_309){
		return 0;
	}


	return *(self->cstr_267+pos);


}

cbcstd_String cbcstd_String_cat(cbcstd_String self, char* append){

	size_t newSize = self->len_309 + strlen(append) + 1;
	
	char* newStr = CBC_NEW(char, newSize);
	

	strcpy(newStr, self->cstr_267);
	strcat(newStr, append);
	
	cbcstd_String ret = cbcstd_String_create(newStr);
	cbcstd_destroy(&(newStr));
	return ret;


}

cbcstd_String cbcstd_String_capitalize(cbcstd_String self){

	char* newStr = (char*)strdup(self->cstr_267);
	
	if (*(newStr) >= 'a' and *(newStr) <= 'z'){
		*(newStr) -= 0x20;
	
	}

	cbcstd_String ret = cbcstd_String_create(newStr);
	free(newStr);
	return ret;
	

}

size_t cbcstd_String_count(cbcstd_String self, char* str){
	size_t cont = 0;

	{int i=0; for (; i<self->len_309; i++){

		if (strncmp(self->cstr_267, str, strlen(str)) == 0){
			cont++;
			i+=strlen(str);
		}

	}}

	return cont;


}

bool cbcstd_String_endswith(cbcstd_String self, char* str){

	size_t offset = self->len_309-strlen(str)-1;

	if (offset > self->len_309){
		return false;
	}


	return strncmp((self->cstr_267+offset), str, strlen(str)) == 0;


}

bool cbcstd_String_startswith(cbcstd_String self, char* str){

	return strncmp(self->cstr_267, str, strlen(str)) == 0;


}

cbcstd_String cbcstd_String_expandTabs(cbcstd_String self, size_t tabsize){

	size_t tabs = self->count(self, "\t");

	size_t newSize = (self->len_309-tabs)+(tabs*tabsize);
	
	char* newStr = CBC_NEW(char, newSize);
	

	{size_t i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == '\t'){
			{int j=0; for (; j<tabsize; j++){
				*(newStr++) = ' ';
			}}

		}

		else{

			*(newStr++) = *(self->cstr_267+i);
	
		}

	}}

	cbcstd_String ret = cbcstd_String_create(newStr);
	cbcstd_destroy(&(newStr));
	return ret;
	


}

bool cbcstd_String_isWhitespaceChar(cbcstd_String self, char test){
	return test == ' ' or test == '\n' or test == '\t';


}

bool cbcstd_String_isNumericChar(cbcstd_String self, char test){
	return test >= '0' and test <= '9';


}

bool cbcstd_String_isAlphaChar(cbcstd_String self, char test){
	return (test >= 'a' and test <= 'z') or (test >= 'A' and test <= 'Z');


}

bool cbcstd_String_isAlphanumericChar(cbcstd_String self, char test){


	return self->isNumericChar(self, test) or self->isAlphaChar(self, test);


}

bool cbcstd_String_isAlphaNumeric(cbcstd_String self){

	{size_t i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}





		if (not self->isAlphanumericChar(self, *(self->cstr_267+i)) and not self->isWhitespaceChar(self, *(self->cstr_267+i))){
			return false;
		}

	}}

	return true;

}

bool cbcstd_String_isAlpha(cbcstd_String self){

	{int i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}





		if (not self->isAlphaChar(self, *(self->cstr_267+i)) and not self->isWhitespaceChar(self, *(self->cstr_267+i))){
			return false;
		}

	}}

	return true;

}

bool cbcstd_String_isNumeric(cbcstd_String self){

	{size_t i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (not self->isNumericChar(self, *(self->cstr_267+i))){
			return false;
		}

	}}

	return true;

}

bool cbcstd_String_isHexadecimal(cbcstd_String self){
	size_t i = 0;

	if (self->startswith(self, "0x")){
		i = 2;
	
	}


	{i; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (*(self->cstr_267+i) < 'a' or *(self->cstr_267+i) > 'f'){


			if (*(self->cstr_267+i) < 'A' or *(self->cstr_267+i) > 'F'){


				if (not self->isNumericChar(self, *(self->cstr_267+i))){
					return false;
				}

			}

		}

	}}

	return true;


}

bool cbcstd_String_isFloat(cbcstd_String self){
	size_t points = 0;

	{size_t i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (not self->isNumericChar(self, *(self->cstr_267+i))){

			if (*(self->cstr_267+i) == '.'){
				points++;
			}

			else{
				return false;
			}

		}

	}}

	return points == 1;


}

bool cbcstd_String_isBinary(cbcstd_String self){
	size_t i = 0;

	if (self->startswith(self, "0b")){
		i = 2;
	}


	{i; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (*(self->cstr_267+i) < '0' or *(self->cstr_267+i) > '1'){
			return false;
		}

	}}

	return true;

}

bool cbcstd_String_isOctal(cbcstd_String self){

	if (*(self->cstr_267) != '0'){
		return false;
	}

	int i = 1;

	if (*(self->cstr_267+1) == 'o'){
		i = 2;
	}


	{i; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (*(self->cstr_267+i) < '0' or *(self->cstr_267+i) > '7'){
			return false;
		}

	}}

	return true;


}

bool cbcstd_String_isLower(cbcstd_String self){

	{size_t i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (*(self->cstr_267+i) < 'a' or *(self->cstr_267+i) > 'z'){




			if (not self->isWhitespaceChar(self, *(self->cstr_267+i)) and not self->isNumericChar(self, *(self->cstr_267+i))){
				return false;
			}

		}

	}}

	return true;

}

bool cbcstd_String_isUpper(cbcstd_String self){

	{size_t i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (*(self->cstr_267+i) < 'A' or *(self->cstr_267+i) > 'Z'){




			if (not self->isWhitespaceChar(self, *(self->cstr_267+i)) and not self->isNumericChar(self, *(self->cstr_267+i))){
				return false;
			}

		}

	}}

	return true;


}

bool cbcstd_String_isWhitespace(cbcstd_String self){

	{size_t i=0; for (; i<self->len_309; i++){

		if (*(self->cstr_267+i) == 0){
			break;
		}



		if (not self->isWhitespaceChar(self, *(self->cstr_267+i))){
			return false;
		}

	}}

	return true;


}

cbcstd_String cbcstd_String_ljustChar(cbcstd_String self, size_t width, char fill){

	char* newStr = CBC_NEW(char, self->len_309+width);
	
	{int i=0; for (; i<width; i++){
		*(newStr+i) = fill;
	
	}}

	*(newStr+width) = '\0';
	


	strncat(newStr, self->cstr_267, self->len_309);
	
	cbcstd_String ret = cbcstd_String_create(newStr);
	cbcstd_destroy(&(newStr));
	return ret;

}

cbcstd_String cbcstd_String_rjust(cbcstd_String self, size_t width, char fill){

	char* newStr = CBC_NEW(char, self->len_309+width);
	


	strncpy(newStr, self->cstr_267, self->len_309);
	{int i=0; for (; i<width; i++){
		strncat(newStr, &fill, 1);
	
	}}

	cbcstd_String ret = cbcstd_String_create(newStr);
	cbcstd_destroy(&(newStr));
	return ret;
	


}

cbcstd_String cbcstd_String_lower(cbcstd_String self){


	char* newStr = strndup(self->cstr_267, self->len_309);

	{int i=0; for (; i<self->len_309; i++){


		if (*(self->cstr_267+i) >= 'A' and *(self->cstr_267+i) <= 'Z'){
			*(newStr+i) += 0x20;
	

		}

	}}

	cbcstd_String ret = cbcstd_String_create(newStr);
	free(newStr);
	return ret;
	

}

cbcstd_String cbcstd_String_upper(cbcstd_String self){


	char* newStr = strndup(self->cstr_267, self->len_309);

	{int i=0; for (; i<self->len_309; i++){


		if (*(self->cstr_267+i) >= 'a' and *(self->cstr_267+i) <= 'z'){
			*(newStr+i) -= 0x20;
	
		}

	}}

	cbcstd_String ret = cbcstd_String_create(newStr);
	free(newStr);
	return ret;
	

}

cbcstd_String cbcstd_String_swapcase(cbcstd_String self){


	char* newStr = strndup(self->cstr_267, self->len_309);

	{int i=0; for (; i<self->len_309; i++){


		if (*(self->cstr_267+i) >= 'a' and *(self->cstr_267+i) <= 'z'){
			*(newStr+i) -= 0x20;
		}



		if (*(self->cstr_267+i) >= 'A' and *(self->cstr_267+i) <= 'Z'){
			*(newStr+i) += 0x20;
	
		}

	}}

	cbcstd_String ret = cbcstd_String_create(newStr);
	free(newStr);
	return ret;
	


}

cbcstd_String cbcstd_String_replace(cbcstd_String self, char* oldStr, char* newStr){

	size_t occurences = self->count(self, oldStr);
	

	size_t newSize = (self->len_309-(occurences*strlen(oldStr)));
	newSize += occurences*strlen(newStr);
	
	char* retStr = CBC_NEW(char, newSize);
	

	{int i=0; for (; i<self->len_309; i++){

		if (not strncmp((self->cstr_267+i), oldStr, strlen(oldStr))){
			strncat(retStr, newStr, strlen(newStr));
			i+=strlen(oldStr)-1;
		}

		else{

			strncat(retStr, (self->cstr_267+i), 1);
	
		}

	}}

	cbcstd_String ret = cbcstd_String_create(retStr);
	cbcstd_destroy(&(retStr));
	return ret;
	


}

cbcstd_String cbcstd_String_rstrip(cbcstd_String self, char* remove){
	int i;
	cbcstd_String rem = cbcstd_String_create(remove);

	{i=self->len_309-1; for (; i>=0; i--){


		if (not rem->charExists(rem, *(self->cstr_267+i))){
			break;
	
		}

	}}


	char* aux = strndup(self->cstr_267, i+1);
	cbcstd_String ret = cbcstd_String_create(aux);

	rem->__end__(rem);
	free(aux);
	return ret;
	

}

cbcstd_String cbcstd_String_lstrip(cbcstd_String self, char* remove){
	int i;
	cbcstd_String rem = cbcstd_String_create(remove);

	{i=0; for (; i<self->len_309; i++){


		if (not rem->charExists(rem, *(self->cstr_267+i))){
			break;
	
		}

	}}



	char* aux = strndup((self->cstr_267+i), self->len_309-i);
	cbcstd_String ret = cbcstd_String_create(aux);

	rem->__end__(rem);
	free(aux);
	return ret;
	


}

cbcstd_String cbcstd_String_strip(cbcstd_String self, char* remove){
	cbcstd_String tmp_L4DK_178 = self->lstrip(self, remove);

	return tmp_L4DK_178->rstrip(tmp_L4DK_178, remove);


}

void cbcstd_String_print(cbcstd_String self){

	printf("%s", self->cstr_267);


}

void cbcstd_String_println(cbcstd_String self){

	printf("%s\n", self->cstr_267);


}

void* cbcstd_String___str__(cbcstd_String self){

	return cbcstd_String_create(self->cstr_267);


}

void cbcstd_String_enduser(cbcstd_String self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	cbcstd_destroy(&(self->cstr_267));

}


cbcstd_Int cbcstd_Int_create(ssize_t value){
	cbcstd_Int self = (cbcstd_Int)cbcstd_alloc(sizeof(cbcstd_Int_struct));
	try{
		cbcstd_Int_init(self, value);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Int_init(cbcstd_Int self, ssize_t value){
	cbcstd_Int_initsystem(self);
	cbcstd_Int_inituser(self, value);
}
void cbcstd_Int_initsystem(cbcstd_Int self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		4961335359079827921L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Int_struct);
	self->to8Bits = &cbcstd_Int_to8Bits;
	self->to16Bits = &cbcstd_Int_to16Bits;
	self->to32Bits = &cbcstd_Int_to32Bits;
	self->to64Bits = &cbcstd_Int_to64Bits;
	self->__cmp__ = &cbcstd_Int___cmp__;
	self->__str__ = &cbcstd_Int___str__;
	self->__end__ = &cbcstd_Int_end;
}
void cbcstd_Int_enduser(cbcstd_Int self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void cbcstd_Int_end(cbcstd_Int self){
	cbcstd_Int_enduser(self);
	cbcstd_Int_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Int_decrefs(cbcstd_Int self){
}


	
void cbcstd_Int_inituser(cbcstd_Int self, ssize_t value){

	self->value_527 = value;

}

int8_t cbcstd_Int_to8Bits(cbcstd_Int self){

	return (int8_t)(self->value_527);

}

int16_t cbcstd_Int_to16Bits(cbcstd_Int self){

	return (int16_t)(self->value_527);


}

int32_t cbcstd_Int_to32Bits(cbcstd_Int self){

	return (int32_t)(self->value_527);


}

int64_t cbcstd_Int_to64Bits(cbcstd_Int self){

	return (int64_t)(self->value_527);


}

int cbcstd_Int___cmp__(cbcstd_Int self, cbcstd_Int other){


	int ret = self->value_527 - other->value_527;
	if (ret < 0) ret = -1;
	elif (ret > 0) ret = 1;
	return ret;


}

void* cbcstd_Int___str__(cbcstd_Int self){
	char tmp[512];

	snprintf(tmp, 512, "%zd", self->value_527);
	return cbcstd_String_create(tmp);

}


cbcstd_Hex cbcstd_Hex_create(ssize_t value){
	cbcstd_Hex self = (cbcstd_Hex)cbcstd_alloc(sizeof(cbcstd_Hex_struct));
	try{
		cbcstd_Hex_init(self, value);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Hex_init(cbcstd_Hex self, ssize_t value){
	cbcstd_Hex_initsystem(self);
	cbcstd_Hex_inituser(self, value);
}
void cbcstd_Hex_initsystem(cbcstd_Hex self){
	cbcstd_Int_initsystem((cbcstd_Int)self);
	const static class_id __classid__[4] = {
		4961334359212828405L,
		4961335359079827921L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Hex_struct);
	self->__str__ = &cbcstd_Hex___str__;
	self->__end__ = &cbcstd_Hex_end;
}
void cbcstd_Hex_enduser(cbcstd_Hex self){
	cbcstd_Int_enduser((cbcstd_Int)self);
	return;
}
void cbcstd_Hex_end(cbcstd_Hex self){
	cbcstd_Hex_enduser(self);
	cbcstd_Hex_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Hex_decrefs(cbcstd_Hex self){
}

	
void cbcstd_Hex_inituser(cbcstd_Hex self, ssize_t value){
	cbcstd_Int_inituser((cbcstd_Int)self, value);


}

void* cbcstd_Hex___str__(cbcstd_Hex self){
	char tmp[512];

	snprintf(tmp, 512, "%zx", self->value_527);
	return cbcstd_String_create(tmp);


}


cbcstd_Float cbcstd_Float_create(double value){
	cbcstd_Float self = (cbcstd_Float)cbcstd_alloc(sizeof(cbcstd_Float_struct));
	try{
		cbcstd_Float_init(self, value);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Float_init(cbcstd_Float self, double value){
	cbcstd_Float_initsystem(self);
	cbcstd_Float_inituser(self, value);
}
void cbcstd_Float_initsystem(cbcstd_Float self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		7476372606712929682L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Float_struct);
	self->__cmp__ = &cbcstd_Float___cmp__;
	self->__str__ = &cbcstd_Float___str__;
	self->__end__ = &cbcstd_Float_end;
}
void cbcstd_Float_enduser(cbcstd_Float self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void cbcstd_Float_end(cbcstd_Float self){
	cbcstd_Float_enduser(self);
	cbcstd_Float_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Float_decrefs(cbcstd_Float self){
}


	
void cbcstd_Float_inituser(cbcstd_Float self, double value){

	self->value_528 = value;


}

int cbcstd_Float___cmp__(cbcstd_Float self, cbcstd_Float other){


	int ret = self->value_528 - other->value_528;
	if (ret < 0) ret = -1;
	elif (ret > 0) ret = 1;
	return ret;


}

void* cbcstd_Float___str__(cbcstd_Float self){
	char tmp[512];

	snprintf(tmp, 512, "%f", self->value_528);
	return cbcstd_String_create(tmp);

}


cbcstd_Char cbcstd_Char_create(char value){
	cbcstd_Char self = (cbcstd_Char)cbcstd_alloc(sizeof(cbcstd_Char_struct));
	try{
		cbcstd_Char_init(self, value);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Char_init(cbcstd_Char self, char value){
	cbcstd_Char_initsystem(self);
	cbcstd_Char_inituser(self, value);
}
void cbcstd_Char_initsystem(cbcstd_Char self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		190749352912602767L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Char_struct);
	self->__cmp__ = &cbcstd_Char___cmp__;
	self->__str__ = &cbcstd_Char___str__;
	self->__end__ = &cbcstd_Char_end;
}
void cbcstd_Char_enduser(cbcstd_Char self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void cbcstd_Char_end(cbcstd_Char self){
	cbcstd_Char_enduser(self);
	cbcstd_Char_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Char_decrefs(cbcstd_Char self){
}


	
void cbcstd_Char_inituser(cbcstd_Char self, char value){

	self->value_747 = value;


}

int cbcstd_Char___cmp__(cbcstd_Char self, cbcstd_Char other){


	int ret = self->value_747 - other->value_747;
	if (ret < 0) ret = -1;
	elif (ret > 0) ret = 1;
	return ret;


}

void* cbcstd_Char___str__(cbcstd_Char self){

	char tmp[2] = {self->value_747, 0};
	return cbcstd_String_create(tmp);

}


static bool hasBool[2] = {false, false};

cbcstd_Bool cbcstd_Bool_create(bool src){
	cbcstd_Bool self = (cbcstd_Bool)cbcstd_alloc(sizeof(cbcstd_Bool_struct));
	try{
		cbcstd_Bool_init(self, src);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Bool_init(cbcstd_Bool self, bool src){
	cbcstd_Bool_initsystem(self);
	cbcstd_Bool_inituser(self, src);
}
void cbcstd_Bool_initsystem(cbcstd_Bool self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-809376647758398005L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Bool_struct);
	self->_setValue_942 = &cbcstd_Bool__setValue_942;
	self->__cmp__ = &cbcstd_Bool___cmp__;
	self->__str__ = &cbcstd_Bool___str__;
	self->__end__ = &cbcstd_Bool_end;
}
void cbcstd_Bool_end(cbcstd_Bool self){
	cbcstd_Bool_enduser(self);
	cbcstd_Bool_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Bool_decrefs(cbcstd_Bool self){
}




	
void cbcstd_Bool_inituser(cbcstd_Bool self, bool src){

	self->value_637 = src;

	self->text_70[true] = "True";

	self->text_70[false] = "False";
	

	if (hasBool[self->value_637]){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Violation Error: You cannot create an instance of Bool, use cbcstd.getBool(value) instead.")));
	}


	hasBool[self->value_637] = true;


}

void cbcstd_Bool_enduser(cbcstd_Bool self){
		cbcstd_Object_enduser((cbcstd_Object)self);
	cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Violation Error: You cannot delete an instance of Bool.")));


}

void cbcstd_Bool__setValue_942(cbcstd_Bool self, bool val){
	if (val){

		self->value_637 = 1;
	}

	else{

		self->value_637 = 0;

	}


}

int cbcstd_Bool___cmp__(cbcstd_Bool self, cbcstd_Bool other){


	int ret = self->value_637 - other->value_637;
	if (ret < 0) ret = -1;
	elif (ret > 0) ret = 1;
	return 0;


}

void* cbcstd_Bool___str__(cbcstd_Bool self){


	return cbcstd_String_create(self->text_70[self->value_637]);

}


cbcstd_Bool cbcstd_getBool(bool value){
	return (value)? cbcstd___bools__[1] : cbcstd___bools__[0];






}

cbcstd_Buffer cbcstd_Buffer_create(size_t size, void* ptr){
	cbcstd_Buffer self = (cbcstd_Buffer)cbcstd_alloc(sizeof(cbcstd_Buffer_struct));
	try{
		cbcstd_Buffer_init(self, size, ptr);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Buffer_init(cbcstd_Buffer self, size_t size, void* ptr){
	cbcstd_Buffer_initsystem(self);
	cbcstd_Buffer_inituser(self, size, ptr);
}
void cbcstd_Buffer_initsystem(cbcstd_Buffer self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		6625435829950324627L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Buffer_struct);
	self->_check_523 = &cbcstd_Buffer__check_523;
	self->read = &cbcstd_Buffer_read;
	self->write = &cbcstd_Buffer_write;
	self->_destroyPtr_687 = &cbcstd_Buffer__destroyPtr_687;
	self->setPointer = &cbcstd_Buffer_setPointer;
	self->__str__ = &cbcstd_Buffer___str__;
	self->__end__ = &cbcstd_Buffer_end;
}
void cbcstd_Buffer_end(cbcstd_Buffer self){
	cbcstd_Buffer_enduser(self);
	cbcstd_Buffer_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Buffer_decrefs(cbcstd_Buffer self){
}




	
void cbcstd_Buffer_inituser(cbcstd_Buffer self, size_t size, void* ptr){
	if (ptr != NULL){

		self->ptr_687 = ptr;

		self->destroy_500 = false;
	}

	else{

		self->ptr_687 = CBC_NEW(unsigned char, size);

		self->destroy_500 = true;
	}


	self->size_983 = size;


}

void cbcstd_Buffer__check_523(cbcstd_Buffer self, void* dest_buffer, size_t size, size_t offset){
	if (dest_buffer == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Error: can't write from NULL pointer")));
	}




	if (self->ptr_687+self->size_983 < self->ptr_687+offset+size){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Error: can't read beyond pointer boundaries")));

	}


}

void cbcstd_Buffer_read(cbcstd_Buffer self, void* dest_buffer, size_t size, size_t offset){

	self->_check_523(self, dest_buffer,  size,  offset);

	memcpy(dest_buffer, self->ptr_687+offset, size);


}

void cbcstd_Buffer_write(cbcstd_Buffer self, void* dest_buffer, size_t size, size_t offset){

	self->_check_523(self, dest_buffer,  size,  offset);

	memcpy(self->ptr_687+offset, dest_buffer, size);


}

void cbcstd_Buffer__destroyPtr_687(cbcstd_Buffer self){

	if (self->destroy_500){

		cbcstd_destroy(self->ptr_687);

	}


}

void cbcstd_Buffer_setPointer(cbcstd_Buffer self, void* ptr){
	if (ptr == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Error: can't set pointer to NULL")));
	}


	self->_destroyPtr_687(self);

	self->ptr_687 = ptr;

	self->destroy_500 = false;


}

void* cbcstd_Buffer___str__(cbcstd_Buffer self){
	char tmp[64];

	snprintf(tmp, 64, "Buffer object at 0x%zx containing buffer at 0x%zx", self, self->ptr_687);
	return cbcstd_String_create(tmp);


}

void cbcstd_Buffer_enduser(cbcstd_Buffer self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	self->_destroyPtr_687(self);

}


typedef pthread_t cbcstd_thread_t;
typedef sem_t cbcstd_sema_t;






cbcstd_Thread cbcstd_Thread_create(void* start, void* arg){
	cbcstd_Thread self = (cbcstd_Thread)cbcstd_alloc(sizeof(cbcstd_Thread_struct));
	try{
		cbcstd_Thread_init(self, start, arg);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Thread_init(cbcstd_Thread self, void* start, void* arg){
	cbcstd_Thread_initsystem(self);
	cbcstd_Thread_inituser(self, start, arg);
}
void cbcstd_Thread_initsystem(cbcstd_Thread self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-9090379707872346563L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Thread_struct);
	self->run = &cbcstd_Thread_run;
	self->waitThreadEnd = &cbcstd_Thread_waitThreadEnd;
	self->setId = &cbcstd_Thread_setId;
	self->__end__ = &cbcstd_Thread_end;
}
void cbcstd_Thread_end(cbcstd_Thread self){
	cbcstd_Thread_enduser(self);
	cbcstd_Thread_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Thread_decrefs(cbcstd_Thread self){
}

	



	
void cbcstd_Thread_inituser(cbcstd_Thread self, void* start, void* arg){

	self->start_79 = start;

	self->arg_383 = arg;
	

}

int cbcstd_Thread_run(cbcstd_Thread self){



	return pthread_create(&(self->thread_id_332), NULL, self->start_79, self->arg_383);

}

void* cbcstd_Thread_waitThreadEnd(cbcstd_Thread self, int timeout){
	void* retval = NULL;

	pthread_join(self->thread_id_332, &retval);
	return retval;

}

void cbcstd_Thread_setId(cbcstd_Thread self, int id){
	return;


}

void cbcstd_Thread_enduser(cbcstd_Thread self){
		cbcstd_Object_enduser((cbcstd_Object)self);
	return;

}


cbcstd_Semaphore cbcstd_Semaphore_create(int counter){
	cbcstd_Semaphore self = (cbcstd_Semaphore)cbcstd_alloc(sizeof(cbcstd_Semaphore_struct));
	try{
		cbcstd_Semaphore_init(self, counter);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Semaphore_init(cbcstd_Semaphore self, int counter){
	cbcstd_Semaphore_initsystem(self);
	cbcstd_Semaphore_inituser(self, counter);
}
void cbcstd_Semaphore_initsystem(cbcstd_Semaphore self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		5933085328435303454L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Semaphore_struct);
	self->wait = &cbcstd_Semaphore_wait;
	self->release = &cbcstd_Semaphore_release;
	self->__end__ = &cbcstd_Semaphore_end;
}
void cbcstd_Semaphore_enduser(cbcstd_Semaphore self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void cbcstd_Semaphore_end(cbcstd_Semaphore self){
	cbcstd_Semaphore_enduser(self);
	cbcstd_Semaphore_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Semaphore_decrefs(cbcstd_Semaphore self){
}




	
void cbcstd_Semaphore_inituser(cbcstd_Semaphore self, int counter){

	self->counter_951 = counter;


	sem_init(&(self->semaphore_698), 0, self->counter_951);


}

void cbcstd_Semaphore_wait(cbcstd_Semaphore self){

	sem_wait(&(self->semaphore_698));


}

void cbcstd_Semaphore_release(cbcstd_Semaphore self){

	sem_post(&(self->semaphore_698));

}


cbcstd_Mutex cbcstd_Mutex_create(cbcstd_MutexType type){
	cbcstd_Mutex self = (cbcstd_Mutex)cbcstd_alloc(sizeof(cbcstd_Mutex_struct));
	try{
		cbcstd_Mutex_init(self, type);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Mutex_init(cbcstd_Mutex self, cbcstd_MutexType type){
	cbcstd_Mutex_initsystem(self);
	cbcstd_Mutex_inituser(self, type);
}
void cbcstd_Mutex_initsystem(cbcstd_Mutex self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-158163739585143091L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Mutex_struct);
	self->wait = &cbcstd_Mutex_wait;
	self->release = &cbcstd_Mutex_release;
	self->__end__ = &cbcstd_Mutex_end;
}
void cbcstd_Mutex_enduser(cbcstd_Mutex self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void cbcstd_Mutex_end(cbcstd_Mutex self){
	cbcstd_Mutex_enduser(self);
	cbcstd_Mutex_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Mutex_decrefs(cbcstd_Mutex self){
}






	
void cbcstd_Mutex_inituser(cbcstd_Mutex self, cbcstd_MutexType type){

	self->type_922 = type;

	self->sema_115 = cbcstd_Semaphore_create(1);
	cbcstd_Semaphore tmp_Q4pU_244 = self->sema_115;

	tmp_Q4pU_244->__refs__ = 1;

	self->owner_sema_73 = cbcstd_Semaphore_create(1);
	cbcstd_Semaphore tmp_iEkf_247 = self->owner_sema_73;

	tmp_iEkf_247->__refs__ = 1;

	self->owner_871 = (cbcstd_thread_t)0;

	self->ignore_9 = 0;


}

void cbcstd_Mutex_wait(cbcstd_Mutex self){
	cbcstd_Semaphore tmp_oPBc_251 = self->owner_sema_73;

	tmp_oPBc_251->wait(tmp_oPBc_251);

	if (cbcstd_getThreadId() != self->owner_871){
		cbcstd_Semaphore tmp_ZoPf_254 = self->sema_115;

		tmp_ZoPf_254->wait(tmp_ZoPf_254);

		self->owner_871 = cbcstd_getThreadId();
	}

	else{

	if (self->type_922 == cbcstd_CRITICAL_MUTEX){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Attempting to wait for mutex already owned by thread")));
	}

	else{

		self->ignore_9++;
	}

	}
	cbcstd_Semaphore tmp_9ZBp_259 = self->owner_sema_73;

	tmp_9ZBp_259->release(tmp_9ZBp_259);


}

void cbcstd_Mutex_release(cbcstd_Mutex self){
	cbcstd_Semaphore tmp_joTM_261 = self->owner_sema_73;

	tmp_joTM_261->wait(tmp_joTM_261);

	if (cbcstd_getThreadId() == self->owner_871){

		if (self->ignore_9 == 0){
			cbcstd_Semaphore tmp_W6dq_265 = self->sema_115;

			tmp_W6dq_265->release(tmp_W6dq_265);

			self->owner_871 = (cbcstd_thread_t)0;
		}

		else{

			self->ignore_9--;
		}

	}

	else{

	if (self->type_922 == cbcstd_CRITICAL_MUTEX){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Attempting to release mutex not owned by thread")));
	}

	}
	cbcstd_Semaphore tmp_pM0L_270 = self->owner_sema_73;

	tmp_pM0L_270->release(tmp_pM0L_270);

}


_cbcstd_ObjectLock _cbcstd_ObjectLock_create(){
	_cbcstd_ObjectLock self = (_cbcstd_ObjectLock)cbcstd_alloc(sizeof(_cbcstd_ObjectLock_struct));
	try{
		_cbcstd_ObjectLock_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void _cbcstd_ObjectLock_init(_cbcstd_ObjectLock self){
	_cbcstd_ObjectLock_initsystem(self);
	_cbcstd_ObjectLock_inituser(self);
}
void _cbcstd_ObjectLock_initsystem(_cbcstd_ObjectLock self){
	cbcstd_Mutex_initsystem((cbcstd_Mutex)self);
	const static class_id __classid__[4] = {
		4927563655615894095L,
		-158163739585143091L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(_cbcstd_ObjectLock_struct);
	self->__end__ = &_cbcstd_ObjectLock_end;
}
void _cbcstd_ObjectLock_enduser(_cbcstd_ObjectLock self){
	cbcstd_Mutex_enduser((cbcstd_Mutex)self);
	return;
}
void _cbcstd_ObjectLock_end(_cbcstd_ObjectLock self){
	_cbcstd_ObjectLock_enduser(self);
	_cbcstd_ObjectLock_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void _cbcstd_ObjectLock_decrefs(_cbcstd_ObjectLock self){
}

void _cbcstd_ObjectLock_inituser(_cbcstd_ObjectLock self){
	cbcstd_Mutex_inituser((cbcstd_Mutex)self, cbcstd_PERMISIVE_MUTEX);

	self->__lock__ = NULL;

}


void cbcstd_exitThread(void* retval){
	pthread_exit(retval);


}

cbcstd_thread_t cbcstd_getThreadId(){
	return pthread_self();
	

}

bool cbcstd_equalThreads(cbcstd_thread_t thread1, cbcstd_thread_t thread2){
	return pthread_equal(thread1, thread2);


}

bool cbcstd_isSelfThread(cbcstd_Thread t){

	return cbcstd_equalThreads(t->thread_id_332, cbcstd_getThreadId());
	


}

void cbcstd_addObjectLock(cbcstd_Object o){

	if (o->__lock__ != NULL or istypeof(o, _cbcstd_ObjectLock)){
		return;
	}


	o->__lock__ = _cbcstd_ObjectLock_create();

	cbcstd_Object tmp_cast_UJ3N = (cbcstd_Object)(o->__lock__);

	tmp_cast_UJ3N->__refs__ = 1;


}

void cbcstd_removeObjectLock(cbcstd_Object o){

	if (not istypeof(o, _cbcstd_ObjectLock) and o->__lock__ != NULL){
		

		cbcstd_Mutex tmp_cast_WpYQ = (cbcstd_Mutex)(o->__lock__);

		tmp_cast_WpYQ->__end__(tmp_cast_WpYQ);

	}


}

void cbcstd_lockObject(cbcstd_Object o){
	if (istypeof(o, _cbcstd_ObjectLock)){
		return;
	}


	if (o->__lock__ == NULL){
		cbcstd_addObjectLock(o);
	}


	cbcstd_Mutex tmp_cast_dNOo = (cbcstd_Mutex)(o->__lock__);

	tmp_cast_dNOo->wait(tmp_cast_dNOo);


}

void cbcstd_unlockObject(cbcstd_Object o){
	if (istypeof(o, _cbcstd_ObjectLock)){
		return;
	}


	if (o->__lock__ == NULL){
		cbcstd_addObjectLock(o);
		return;
	}


	cbcstd_Mutex tmp_cast_AeCa = (cbcstd_Mutex)(o->__lock__);

	tmp_cast_AeCa->release(tmp_cast_AeCa);







}

cbcstd_Exception cbcstd_Exception_create(char* description){
	cbcstd_Exception self = (cbcstd_Exception)cbcstd_alloc(sizeof(cbcstd_Exception_struct));
	try{
		cbcstd_Exception_init(self, description);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Exception_init(cbcstd_Exception self, char* description){
	cbcstd_Exception_initsystem(self);
	cbcstd_Exception_inituser(self, description);
}
void cbcstd_Exception_initsystem(cbcstd_Exception self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Exception_struct);
	self->__str__ = &cbcstd_Exception___str__;
	self->__end__ = &cbcstd_Exception_end;
}
void cbcstd_Exception_end(cbcstd_Exception self){
	cbcstd_Exception_enduser(self);
	cbcstd_Exception_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Exception_decrefs(cbcstd_Exception self){
}


	
void cbcstd_Exception_inituser(cbcstd_Exception self, char* description){

	self->description_787 = cbcstd_String_create(description);


}

void* cbcstd_Exception___str__(cbcstd_Exception self){
	cbcstd_String tmp_rZO8_288 = self->description_787;

	return tmp_rZO8_288->__str__(tmp_rZO8_288);


}

void cbcstd_Exception_enduser(cbcstd_Exception self){
		cbcstd_Object_enduser((cbcstd_Object)self);
	cbcstd_String tmp_kYnt_290 = self->description_787;

	tmp_kYnt_290->__end__(tmp_kYnt_290);

}


cbcstd_CriticalException cbcstd_CriticalException_create(char* description){
	cbcstd_CriticalException self = (cbcstd_CriticalException)cbcstd_alloc(sizeof(cbcstd_CriticalException_struct));
	try{
		cbcstd_CriticalException_init(self, description);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_CriticalException_init(cbcstd_CriticalException self, char* description){
	cbcstd_CriticalException_initsystem(self);
	cbcstd_CriticalException_inituser(self, description);
}
void cbcstd_CriticalException_initsystem(cbcstd_CriticalException self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		5845670225932612062L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_CriticalException_struct);
	self->__end__ = &cbcstd_CriticalException_end;
}
void cbcstd_CriticalException_enduser(cbcstd_CriticalException self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_CriticalException_end(cbcstd_CriticalException self){
	cbcstd_CriticalException_enduser(self);
	cbcstd_CriticalException_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_CriticalException_decrefs(cbcstd_CriticalException self){
}

void cbcstd_CriticalException_inituser(cbcstd_CriticalException self, char* description){
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


cbcstd_SystemError cbcstd_SystemError_create(char* description){
	cbcstd_SystemError self = (cbcstd_SystemError)cbcstd_alloc(sizeof(cbcstd_SystemError_struct));
	try{
		cbcstd_SystemError_init(self, description);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_SystemError_init(cbcstd_SystemError self, char* description){
	cbcstd_SystemError_initsystem(self);
	cbcstd_SystemError_inituser(self, description);
}
void cbcstd_SystemError_initsystem(cbcstd_SystemError self){
	cbcstd_CriticalException_initsystem((cbcstd_CriticalException)self);
	const static class_id __classid__[5] = {
		-1736802566581406411L,
		5845670225932612062L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_SystemError_struct);
	self->__end__ = &cbcstd_SystemError_end;
}
void cbcstd_SystemError_enduser(cbcstd_SystemError self){
	cbcstd_CriticalException_enduser((cbcstd_CriticalException)self);
	return;
}
void cbcstd_SystemError_end(cbcstd_SystemError self){
	cbcstd_SystemError_enduser(self);
	cbcstd_SystemError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_SystemError_decrefs(cbcstd_SystemError self){
}

void cbcstd_SystemError_inituser(cbcstd_SystemError self, char* description){
	if (description == NULL){
		description = "Generic System Error Ocurred";
	}

	cbcstd_CriticalException_inituser((cbcstd_CriticalException)self, description);

}


cbcstd_SystemExit cbcstd_SystemExit_create(int exit_status){
	cbcstd_SystemExit self = (cbcstd_SystemExit)cbcstd_alloc(sizeof(cbcstd_SystemExit_struct));
	try{
		cbcstd_SystemExit_init(self, exit_status);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_SystemExit_init(cbcstd_SystemExit self, int exit_status){
	cbcstd_SystemExit_initsystem(self);
	cbcstd_SystemExit_inituser(self, exit_status);
}
void cbcstd_SystemExit_initsystem(cbcstd_SystemExit self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		-1426973790750071894L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_SystemExit_struct);
	self->__end__ = &cbcstd_SystemExit_end;
}
void cbcstd_SystemExit_enduser(cbcstd_SystemExit self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_SystemExit_end(cbcstd_SystemExit self){
	cbcstd_SystemExit_enduser(self);
	cbcstd_SystemExit_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_SystemExit_decrefs(cbcstd_SystemExit self){
}


void cbcstd_SystemExit_inituser(cbcstd_SystemExit self, int exit_status){
	cbcstd_Exception_inituser((cbcstd_Exception)self, "System Exit Called");

	self->exit_status_372 = exit_status;

}


static void _cbcstd_waitExcepMutex(){
	if (cbcstd_excep_mutex != NULL){

		cbcstd_excep_mutex->wait(cbcstd_excep_mutex);

	}


}

static void _cbcstd_releaseExcepMutex(){
	if (cbcstd_excep_mutex != NULL){

		cbcstd_excep_mutex->release(cbcstd_excep_mutex);

	}


}

static _cbcstd_CriticalExceptionHandler* _cbcstd_getCExceptionHandler(class_id classid){
	_cbcstd_waitExcepMutex();
	_cbcstd_CriticalExceptionHandler* ret = cbcstd_handler_start;
	
	while (ret != NULL){

		if (ret->exception_id == classid){
			break;
		}

		ret = ret->next;
	}

	_cbcstd_releaseExcepMutex();
	return ret;


}

static _cbcstd_ExceptionThreadBuffer* _cbcstd_getCurrentThreadBuffer(){
	#ifdef __cbc_multithreading

	_cbcstd_waitExcepMutex();
	
	cbcstd_thread_t curThread = cbcstd_getThreadId();
	_cbcstd_ExceptionThreadBuffer* buf = cbcstd_start_buf;
	while (buf != NULL){

		if (cbcstd_equalThreads(curThread, buf->thread)){
			_cbcstd_releaseExcepMutex();
			return buf;
		}

		buf = (_cbcstd_ExceptionThreadBuffer*)(buf->next);
	}

	buf = (_cbcstd_ExceptionThreadBuffer*)malloc(sizeof(_cbcstd_ExceptionThreadBuffer));
	memset(buf, 0, sizeof(_cbcstd_ExceptionThreadBuffer));
	if (buf == NULL){
		cthrow((cbcstd_Exception)(cbcstd_critical_memory));
	}


	buf->thread = curThread;
	buf->next = (_cbcstd_ExceptionThreadBuffer*)cbcstd_start_buf;
	buf->cur_buf = NULL;

	buf->cur_exception = NULL;
	cbcstd_start_buf = buf;
	_cbcstd_releaseExcepMutex();
	return buf;
	#else
	if (cbcstd_start_buf == NULL){
		cbcstd_start_buf = (_cbcstd_ExceptionThreadBuffer*)malloc(sizeof(_cbcstd_ExceptionThreadBuffer));
		memset(cbcstd_start_buf, 0, sizeof(_cbcstd_ExceptionThreadBuffer));
		if (cbcstd_start_buf == NULL){
			cthrow((cbcstd_Exception)(cbcstd_critical_memory));
		}

		cbcstd_start_buf->next = cbcstd_start_buf;
		cbcstd_start_buf->cur_buf = NULL;

		cbcstd_start_buf->cur_exception = NULL;
	}

	return cbcstd_start_buf;
	#endif


}

void cbcstd_registerException(cbcstd_Exception e){
	if (not isinstanceof(e, cbcstd_Exception)){
		cbcstd_Object tmp_cast_LhlL = (cbcstd_Object)(e);
		cbcstd_Object aux = tmp_cast_LhlL;
		cbcstd_Object tmp_new_ut0v = (cbcstd_Object)(cbcstd_NotAnExceptionError_create(aux));
		cbcstd_Exception tmp_cast_owB2 = (cbcstd_Exception)(tmp_new_ut0v);
		e = tmp_cast_owB2;

		aux->__end__(aux);
	}

	_cbcstd_ExceptionThreadBuffer* cur_buffer = _cbcstd_getCurrentThreadBuffer();

	cur_buffer->cur_exception = e;


}

static cbcstd_Exception _cbcstd_getRaisedException(_cbcstd_ExceptionThreadBuffer* cur_buffer){

	cbcstd_Exception aux = cur_buffer->cur_exception;

	cur_buffer->cur_exception = NULL;
	
	if (aux == NULL){
		aux = cbcstd_std_exception;

	}

	_cbcstd_CriticalExceptionHandler* handler = _cbcstd_getCExceptionHandler(classid(aux));
	if (isinstanceof(aux, cbcstd_CriticalException)){

		if (handler != NULL and handler->handler != NULL){
			cbcstd_CriticalException tmp_cast_KPkI = (cbcstd_CriticalException)(aux);

			aux = handler->handler(tmp_cast_KPkI);
		}

		else{
			printf("CRITICAL EXCEPTION LAUNCHED, EXECUTION HAULTED.\n");
			_cbcstd_unhandledException(aux);
		}

	}

	else{
		if (handler != NULL){
			cbcstd_unregisterCriticalExceptionHandler(classid(aux));
	
		}

	}

	return aux;


}

cbcstd_Exception cbcstd_getRaisedException(){

	_cbcstd_ExceptionThreadBuffer* cur_buffer = _cbcstd_getCurrentThreadBuffer();

	return _cbcstd_getRaisedException(cur_buffer);


}

jmp_buf* cbcstd_registerExceptionBuffer(){

	_cbcstd_JumpBuffer* aux = (_cbcstd_JumpBuffer*)malloc(sizeof(_cbcstd_JumpBuffer));
	memset(aux, 0, sizeof(_cbcstd_JumpBuffer));
	
	if (aux == NULL){
		cthrow((cbcstd_Exception)(cbcstd_critical_memory));
	
	}

	aux->next = NULL;
	
	_cbcstd_ExceptionThreadBuffer* my_buf = _cbcstd_getCurrentThreadBuffer();
	
	if (my_buf->cur_buf == NULL){
		my_buf->cur_buf = aux;
	}

	else{
		aux->next = (_cbcstd_JumpBuffer*)(my_buf->cur_buf);
		my_buf->cur_buf = aux;
	
	}


	return &(aux->buffer);


}

static void _cbcstd_unhandledException(cbcstd_Exception e){
	class_id ret = classid(e);
	printf("Exception ID: %ld\n", (long)ret);
	printf("Exception Message:\n");

	cbcstd_String s = e->__str__(e);

	s->println(s);

	s->__end__(s);
	exit(ret);


}

jmp_buf* cbcstd_obtainNextExceptionBuffer(jmp_buf* dest_buffer){
	
	_cbcstd_ExceptionThreadBuffer* my_buf = _cbcstd_getCurrentThreadBuffer();
	
	_cbcstd_waitExcepMutex();
	if (my_buf->cur_buf == NULL){
		cbcstd_Exception e = _cbcstd_getRaisedException(my_buf);
		if (isinstanceof(e, cbcstd_SystemExit)){
			printf("Unhandled instance of SystemExit raised\n");
			cbcstd_SystemExit tmp_cast_uttA = (cbcstd_SystemExit)(e);
			cbcstd_SystemExit ret = tmp_cast_uttA;

			exit(ret->exit_status_372);
		}

		else{
			printf("Unhandled exception caught!\n");
			_cbcstd_unhandledException(e);
		}

	}

	_cbcstd_releaseExcepMutex();
	
	_cbcstd_JumpBuffer* aux = (_cbcstd_JumpBuffer*)(my_buf->cur_buf);
	my_buf->cur_buf = (_cbcstd_JumpBuffer*)(aux->next);
	

	memcpy(dest_buffer, aux->buffer, sizeof(jmp_buf));
	
	free(aux);
	return dest_buffer;


}

void cbcstd_registerCriticalExceptionHandler(class_id classid, cbcstd_Exception (* handler)(cbcstd_CriticalException)){
	_cbcstd_waitExcepMutex();
	_cbcstd_CriticalExceptionHandler* registered = _cbcstd_getCExceptionHandler(classid);
	if (registered != NULL){

		registered->handler = handler;
		return;
	}

	if (cbcstd_handler_start == NULL){
		cbcstd_handler_start = (_cbcstd_CriticalExceptionHandler*)malloc(sizeof(_cbcstd_CriticalExceptionHandler));

		cbcstd_handler_start->exception_id = classid;

		cbcstd_handler_start->handler = handler;
	}

	else{
		_cbcstd_CriticalExceptionHandler* to_insert = (_cbcstd_CriticalExceptionHandler*)malloc(sizeof(_cbcstd_CriticalExceptionHandler));

		to_insert->exception_id = classid;

		to_insert->handler = handler;
		to_insert->next = cbcstd_handler_start;
		cbcstd_handler_start = to_insert;
	}

	_cbcstd_releaseExcepMutex();


}

void cbcstd_unregisterCriticalExceptionHandler(class_id classid){
	_cbcstd_waitExcepMutex();
	_cbcstd_CriticalExceptionHandler* cur = cbcstd_handler_start;
	_cbcstd_CriticalExceptionHandler* prev = NULL;
	while (cur != NULL){

		if (cur->exception_id == classid){
			_cbcstd_CriticalExceptionHandler* next = cur->next;
			if (prev != NULL){
				prev->next = next;
			}

			if (cur == cbcstd_handler_start){
				cbcstd_handler_start = next;
			}

			cbcstd_destroy(&cur);
			break;
		}

		prev = cur;
		cur = cur->next;
		
	}

	_cbcstd_releaseExcepMutex();


}

void cbcstd_printException(){
	cbcstd_Exception e = cbcstd_getRaisedException();

	cbcstd_String s = e->__str__(e);

	s->println(s);





}

cbcstd_OutOfMemoryError cbcstd_OutOfMemoryError_create(){
	cbcstd_OutOfMemoryError self = (cbcstd_OutOfMemoryError)cbcstd_alloc(sizeof(cbcstd_OutOfMemoryError_struct));
	try{
		cbcstd_OutOfMemoryError_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_OutOfMemoryError_init(cbcstd_OutOfMemoryError self){
	cbcstd_OutOfMemoryError_initsystem(self);
	cbcstd_OutOfMemoryError_inituser(self);
}
void cbcstd_OutOfMemoryError_initsystem(cbcstd_OutOfMemoryError self){
	cbcstd_CriticalException_initsystem((cbcstd_CriticalException)self);
	const static class_id __classid__[5] = {
		-2971450260061360241L,
		5845670225932612062L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_OutOfMemoryError_struct);
	self->__end__ = &cbcstd_OutOfMemoryError_end;
}
void cbcstd_OutOfMemoryError_enduser(cbcstd_OutOfMemoryError self){
	cbcstd_CriticalException_enduser((cbcstd_CriticalException)self);
	return;
}
void cbcstd_OutOfMemoryError_end(cbcstd_OutOfMemoryError self){
	cbcstd_OutOfMemoryError_enduser(self);
	cbcstd_OutOfMemoryError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_OutOfMemoryError_decrefs(cbcstd_OutOfMemoryError self){
}

void cbcstd_OutOfMemoryError_inituser(cbcstd_OutOfMemoryError self){
	cbcstd_CriticalException_inituser((cbcstd_CriticalException)self, "CRITICAL ERROR: out of memory");

}


cbcstd_NullPointerDelete cbcstd_NullPointerDelete_create(){
	cbcstd_NullPointerDelete self = (cbcstd_NullPointerDelete)cbcstd_alloc(sizeof(cbcstd_NullPointerDelete_struct));
	try{
		cbcstd_NullPointerDelete_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_NullPointerDelete_init(cbcstd_NullPointerDelete self){
	cbcstd_NullPointerDelete_initsystem(self);
	cbcstd_NullPointerDelete_inituser(self);
}
void cbcstd_NullPointerDelete_initsystem(cbcstd_NullPointerDelete self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		4684775427116870887L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_NullPointerDelete_struct);
	self->__end__ = &cbcstd_NullPointerDelete_end;
}
void cbcstd_NullPointerDelete_enduser(cbcstd_NullPointerDelete self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_NullPointerDelete_end(cbcstd_NullPointerDelete self){
	cbcstd_NullPointerDelete_enduser(self);
	cbcstd_NullPointerDelete_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_NullPointerDelete_decrefs(cbcstd_NullPointerDelete self){
}

void cbcstd_NullPointerDelete_inituser(cbcstd_NullPointerDelete self){
	cbcstd_Exception_inituser((cbcstd_Exception)self, "ERROR: trying to delete a NULL pointer");

}


cbcstd_NoExceptionError cbcstd_NoExceptionError_create(){
	cbcstd_NoExceptionError self = (cbcstd_NoExceptionError)cbcstd_alloc(sizeof(cbcstd_NoExceptionError_struct));
	try{
		cbcstd_NoExceptionError_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_NoExceptionError_init(cbcstd_NoExceptionError self){
	cbcstd_NoExceptionError_initsystem(self);
	cbcstd_NoExceptionError_inituser(self);
}
void cbcstd_NoExceptionError_initsystem(cbcstd_NoExceptionError self){
	cbcstd_CriticalException_initsystem((cbcstd_CriticalException)self);
	const static class_id __classid__[5] = {
		4630710885004494525L,
		5845670225932612062L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_NoExceptionError_struct);
	self->__end__ = &cbcstd_NoExceptionError_end;
}
void cbcstd_NoExceptionError_enduser(cbcstd_NoExceptionError self){
	cbcstd_CriticalException_enduser((cbcstd_CriticalException)self);
	return;
}
void cbcstd_NoExceptionError_end(cbcstd_NoExceptionError self){
	cbcstd_NoExceptionError_enduser(self);
	cbcstd_NoExceptionError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_NoExceptionError_decrefs(cbcstd_NoExceptionError self){
}

void cbcstd_NoExceptionError_inituser(cbcstd_NoExceptionError self){
	static char* description =
		"CRITICAL ERROR: There doesn't seem to be a registered exception instance,\n"
		"\tbut an exception was launched anyways.\n"
		"THIS SHOULDN'T HAPPEN!";
	cbcstd_CriticalException_inituser((cbcstd_CriticalException)self, description);

}


cbcstd_NotAnExceptionError cbcstd_NotAnExceptionError_create(cbcstd_Object thrown){
	cbcstd_NotAnExceptionError self = (cbcstd_NotAnExceptionError)cbcstd_alloc(sizeof(cbcstd_NotAnExceptionError_struct));
	try{
		cbcstd_NotAnExceptionError_init(self, thrown);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_NotAnExceptionError_init(cbcstd_NotAnExceptionError self, cbcstd_Object thrown){
	cbcstd_NotAnExceptionError_initsystem(self);
	cbcstd_NotAnExceptionError_inituser(self, thrown);
}
void cbcstd_NotAnExceptionError_initsystem(cbcstd_NotAnExceptionError self){
	cbcstd_CriticalException_initsystem((cbcstd_CriticalException)self);
	const static class_id __classid__[5] = {
		524310300948615443L,
		5845670225932612062L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_NotAnExceptionError_struct);
	self->__end__ = &cbcstd_NotAnExceptionError_end;
}
void cbcstd_NotAnExceptionError_enduser(cbcstd_NotAnExceptionError self){
	cbcstd_CriticalException_enduser((cbcstd_CriticalException)self);
	return;
}
void cbcstd_NotAnExceptionError_end(cbcstd_NotAnExceptionError self){
	cbcstd_NotAnExceptionError_enduser(self);
	cbcstd_NotAnExceptionError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_NotAnExceptionError_decrefs(cbcstd_NotAnExceptionError self){
}

void cbcstd_NotAnExceptionError_inituser(cbcstd_NotAnExceptionError self, cbcstd_Object thrown){
	static char* format =
		"ERROR: attempted to throw an instance that didn't derive from the base exception class.\n"
		"Object ID: %d";
	char description[512];
	sprintf(description, format, classid(thrown));
	cbcstd_CriticalException_inituser((cbcstd_CriticalException)self, description);

}


cbcstd_CastExceptionError cbcstd_CastExceptionError_create(class_id src_obj, class_id dst_obj){
	cbcstd_CastExceptionError self = (cbcstd_CastExceptionError)cbcstd_alloc(sizeof(cbcstd_CastExceptionError_struct));
	try{
		cbcstd_CastExceptionError_init(self, src_obj, dst_obj);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_CastExceptionError_init(cbcstd_CastExceptionError self, class_id src_obj, class_id dst_obj){
	cbcstd_CastExceptionError_initsystem(self);
	cbcstd_CastExceptionError_inituser(self, src_obj, dst_obj);
}
void cbcstd_CastExceptionError_initsystem(cbcstd_CastExceptionError self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		5629177208595920035L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_CastExceptionError_struct);
	self->__end__ = &cbcstd_CastExceptionError_end;
}
void cbcstd_CastExceptionError_enduser(cbcstd_CastExceptionError self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_CastExceptionError_end(cbcstd_CastExceptionError self){
	cbcstd_CastExceptionError_enduser(self);
	cbcstd_CastExceptionError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_CastExceptionError_decrefs(cbcstd_CastExceptionError self){
}

void cbcstd_CastExceptionError_inituser(cbcstd_CastExceptionError self, class_id src_obj, class_id dst_obj){
	static char* format =
		"ERROR: cannot cast object of type %zd to object of type %zd";
	char description[128];
	sprintf(description, format, src_obj, dst_obj);
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


cbcstd_ObjectCompareError cbcstd_ObjectCompareError_create(class_id id1, class_id id2){
	cbcstd_ObjectCompareError self = (cbcstd_ObjectCompareError)cbcstd_alloc(sizeof(cbcstd_ObjectCompareError_struct));
	try{
		cbcstd_ObjectCompareError_init(self, id1, id2);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_ObjectCompareError_init(cbcstd_ObjectCompareError self, class_id id1, class_id id2){
	cbcstd_ObjectCompareError_initsystem(self);
	cbcstd_ObjectCompareError_inituser(self, id1, id2);
}
void cbcstd_ObjectCompareError_initsystem(cbcstd_ObjectCompareError self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		6753687413457036265L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_ObjectCompareError_struct);
	self->__end__ = &cbcstd_ObjectCompareError_end;
}
void cbcstd_ObjectCompareError_enduser(cbcstd_ObjectCompareError self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_ObjectCompareError_end(cbcstd_ObjectCompareError self){
	cbcstd_ObjectCompareError_enduser(self);
	cbcstd_ObjectCompareError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_ObjectCompareError_decrefs(cbcstd_ObjectCompareError self){
}

void cbcstd_ObjectCompareError_inituser(cbcstd_ObjectCompareError self, class_id id1, class_id id2){
	static char* format = 
		"ERROR: can't compare two non-compatible instances of type %zd and %zd";
	char description[128];
	sprintf(description, format, id1, id2);
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


cbcstd_ObjectOperateError cbcstd_ObjectOperateError_create(class_id id1, class_id id2){
	cbcstd_ObjectOperateError self = (cbcstd_ObjectOperateError)cbcstd_alloc(sizeof(cbcstd_ObjectOperateError_struct));
	try{
		cbcstd_ObjectOperateError_init(self, id1, id2);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_ObjectOperateError_init(cbcstd_ObjectOperateError self, class_id id1, class_id id2){
	cbcstd_ObjectOperateError_initsystem(self);
	cbcstd_ObjectOperateError_inituser(self, id1, id2);
}
void cbcstd_ObjectOperateError_initsystem(cbcstd_ObjectOperateError self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		5828251413358395306L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_ObjectOperateError_struct);
	self->__end__ = &cbcstd_ObjectOperateError_end;
}
void cbcstd_ObjectOperateError_enduser(cbcstd_ObjectOperateError self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_ObjectOperateError_end(cbcstd_ObjectOperateError self){
	cbcstd_ObjectOperateError_enduser(self);
	cbcstd_ObjectOperateError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_ObjectOperateError_decrefs(cbcstd_ObjectOperateError self){
}

void cbcstd_ObjectOperateError_inituser(cbcstd_ObjectOperateError self, class_id id1, class_id id2){
	static char* format = 
		"ERROR: can't operate on two non-compatible instances of type %zd and %zd";
	char description[128];
	sprintf(description, format, id1, id2);
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


cbcstd_InvalidObjectOperation cbcstd_InvalidObjectOperation_create(class_id id, char op){
	cbcstd_InvalidObjectOperation self = (cbcstd_InvalidObjectOperation)cbcstd_alloc(sizeof(cbcstd_InvalidObjectOperation_struct));
	try{
		cbcstd_InvalidObjectOperation_init(self, id, op);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_InvalidObjectOperation_init(cbcstd_InvalidObjectOperation self, class_id id, char op){
	cbcstd_InvalidObjectOperation_initsystem(self);
	cbcstd_InvalidObjectOperation_inituser(self, id, op);
}
void cbcstd_InvalidObjectOperation_initsystem(cbcstd_InvalidObjectOperation self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		8157800301877777374L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_InvalidObjectOperation_struct);
	self->__end__ = &cbcstd_InvalidObjectOperation_end;
}
void cbcstd_InvalidObjectOperation_enduser(cbcstd_InvalidObjectOperation self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_InvalidObjectOperation_end(cbcstd_InvalidObjectOperation self){
	cbcstd_InvalidObjectOperation_enduser(self);
	cbcstd_InvalidObjectOperation_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_InvalidObjectOperation_decrefs(cbcstd_InvalidObjectOperation self){
}

void cbcstd_InvalidObjectOperation_inituser(cbcstd_InvalidObjectOperation self, class_id id, char op){
	static char* format = 
		"ERROR: invalid operation '%c' on Object type %zd";
	char description[128];
	sprintf(description, format, op, id);
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


cbcstd_OutOfBounds cbcstd_OutOfBounds_create(){
	cbcstd_OutOfBounds self = (cbcstd_OutOfBounds)cbcstd_alloc(sizeof(cbcstd_OutOfBounds_struct));
	try{
		cbcstd_OutOfBounds_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_OutOfBounds_init(cbcstd_OutOfBounds self){
	cbcstd_OutOfBounds_initsystem(self);
	cbcstd_OutOfBounds_inituser(self);
}
void cbcstd_OutOfBounds_initsystem(cbcstd_OutOfBounds self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		-4541178489538158438L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_OutOfBounds_struct);
	self->__end__ = &cbcstd_OutOfBounds_end;
}
void cbcstd_OutOfBounds_enduser(cbcstd_OutOfBounds self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_OutOfBounds_end(cbcstd_OutOfBounds self){
	cbcstd_OutOfBounds_enduser(self);
	cbcstd_OutOfBounds_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_OutOfBounds_decrefs(cbcstd_OutOfBounds self){
}

void cbcstd_OutOfBounds_inituser(cbcstd_OutOfBounds self){
	char* description = "Array index out of bounds";
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


cbcstd_ArrayFull cbcstd_ArrayFull_create(){
	cbcstd_ArrayFull self = (cbcstd_ArrayFull)cbcstd_alloc(sizeof(cbcstd_ArrayFull_struct));
	try{
		cbcstd_ArrayFull_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_ArrayFull_init(cbcstd_ArrayFull self){
	cbcstd_ArrayFull_initsystem(self);
	cbcstd_ArrayFull_inituser(self);
}
void cbcstd_ArrayFull_initsystem(cbcstd_ArrayFull self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		-7844554939348106996L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_ArrayFull_struct);
	self->__end__ = &cbcstd_ArrayFull_end;
}
void cbcstd_ArrayFull_enduser(cbcstd_ArrayFull self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_ArrayFull_end(cbcstd_ArrayFull self){
	cbcstd_ArrayFull_enduser(self);
	cbcstd_ArrayFull_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_ArrayFull_decrefs(cbcstd_ArrayFull self){
}

void cbcstd_ArrayFull_inituser(cbcstd_ArrayFull self){
	char* description = "Error inserting element: array is full";
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


_cbcstd_ListNode _cbcstd_ListNode_create(cbcstd_Object data){
	_cbcstd_ListNode self = (_cbcstd_ListNode)cbcstd_alloc(sizeof(_cbcstd_ListNode_struct));
	try{
		_cbcstd_ListNode_init(self, data);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void _cbcstd_ListNode_init(_cbcstd_ListNode self, cbcstd_Object data){
	_cbcstd_ListNode_initsystem(self);
	_cbcstd_ListNode_inituser(self, data);
}
void _cbcstd_ListNode_initsystem(_cbcstd_ListNode self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-1327961035415945311L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(_cbcstd_ListNode_struct);
	self->insert = &_cbcstd_ListNode_insert;
	self->get = &_cbcstd_ListNode_get;
	self->remove = &_cbcstd_ListNode_remove;
	self->__str__ = &_cbcstd_ListNode___str__;
	self->__end__ = &_cbcstd_ListNode_end;
}
void _cbcstd_ListNode_end(_cbcstd_ListNode self){
	_cbcstd_ListNode_enduser(self);
	_cbcstd_ListNode_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void _cbcstd_ListNode_decrefs(_cbcstd_ListNode self){
}





	
void _cbcstd_ListNode_inituser(_cbcstd_ListNode self, cbcstd_Object data){
	cbcstd_gcIncRef(data);

	cbcstd_gcAssign(&(self->data_981), data);

	self->next_266 = NULL;

	self->prev_568 = NULL;
	cbcstd_gcDecRef(data);


}

void _cbcstd_ListNode_insert(_cbcstd_ListNode self, cbcstd_Object data, int pos){
	cbcstd_gcIncRef(data);

	if (pos == 0 or self->next_266 == NULL){
		_cbcstd_ListNode New = _cbcstd_ListNode_create(data);


		New->prev_568 = self->prev_568;

		New->next_266 = self;

		self->prev_568 = New;
	}

	else{
		_cbcstd_ListNode tmp_5jcY_310 = self->next_266;

		tmp_5jcY_310->insert(tmp_5jcY_310, data,  pos-1);
	}

	cbcstd_gcDecRef(data);


}

cbcstd_Object _cbcstd_ListNode_get(_cbcstd_ListNode self, int pos){

	if (pos == 0 or self->next_266 == NULL){

		return self->data_981;
	}

	_cbcstd_ListNode tmp_DTWS_314 = self->next_266;

	return tmp_DTWS_314->get(tmp_DTWS_314, pos-1);


}

_cbcstd_ListNode _cbcstd_ListNode_remove(_cbcstd_ListNode self, int pos){

	if (pos == 0 or self->next_266 == NULL){

		_cbcstd_ListNode tmp_zats_318 = self->prev_568;

		tmp_zats_318->next_266 = self->next_266;

		_cbcstd_ListNode tmp_uhwR_321 = self->next_266;

		tmp_uhwR_321->prev_568 = self->prev_568;

		self->prev_568 = NULL;

		self->next_266 = NULL;
		return self;
	}

	_cbcstd_ListNode tmp_FeoS_325 = self->next_266;

	return tmp_FeoS_325->remove(tmp_FeoS_325, pos-1);


}

void _cbcstd_ListNode___str__(_cbcstd_ListNode self){
	cbcstd_Object tmp_z0mN_327 = self->data_981;

	return tmp_z0mN_327->__str__(tmp_z0mN_327);


}

void _cbcstd_ListNode_enduser(_cbcstd_ListNode self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	cbcstd_gcAssign(&(self->data_981), NULL);
	return;

}


cbcstd_List cbcstd_List_create(){
	cbcstd_List self = (cbcstd_List)cbcstd_alloc(sizeof(cbcstd_List_struct));
	try{
		cbcstd_List_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_List_init(cbcstd_List self){
	cbcstd_List_initsystem(self);
	cbcstd_List_inituser(self);
}
void cbcstd_List_initsystem(cbcstd_List self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		9190911353623603763L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_List_struct);
	self->insert = &cbcstd_List_insert;
	self->get = &cbcstd_List_get;
	self->getLast = &cbcstd_List_getLast;
	self->push = &cbcstd_List_push;
	self->pop = &cbcstd_List_pop;
	self->enqueue = &cbcstd_List_enqueue;
	self->dequeue = &cbcstd_List_dequeue;
	self->remove = &cbcstd_List_remove;
	self->removeObject = &cbcstd_List_removeObject;
	self->contains = &cbcstd_List_contains;
	self->size = &cbcstd_List_size;
	self->clear = &cbcstd_List_clear;
	self->__iterinit__ = &cbcstd_List___iterinit__;
	self->__iternext__ = &cbcstd_List___iternext__;
	self->__iterprev__ = &cbcstd_List___iterprev__;
	self->__str__ = &cbcstd_List___str__;
	self->__end__ = &cbcstd_List_end;
}
void cbcstd_List_end(cbcstd_List self){
	cbcstd_List_enduser(self);
	cbcstd_List_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_List_decrefs(cbcstd_List self){
}


	




	
void cbcstd_List_inituser(cbcstd_List self){

	self->first_616 = NULL;

	self->last_90 = NULL;

	self->cont_902 = 0;

	self->iter_item_194 = NULL;


}

void cbcstd_List_insert(cbcstd_List self, cbcstd_Object data, int pos){
	cbcstd_gcIncRef(data);

	if (self->first_616 == NULL){

		self->first_616 = _cbcstd_ListNode_create(data);


		self->last_90 = self->first_616;
	}

	else{
		_cbcstd_ListNode tmp_HLcq_338 = self->first_616;

		tmp_HLcq_338->insert(tmp_HLcq_338, data,  pos);
		_cbcstd_ListNode tmp_cnM3_340 = self->first_616;

		if (tmp_cnM3_340->prev_568 != NULL){
			_cbcstd_ListNode tmp_KBll_342 = self->first_616;


			self->first_616 = tmp_KBll_342->prev_568;
		}

		_cbcstd_ListNode tmp_f2We_345 = self->last_90;

		if (tmp_f2We_345->next_266 != NULL){
			_cbcstd_ListNode tmp_xZg2_347 = self->last_90;


			self->last_90 = tmp_xZg2_347->next_266;
		}

	}


	self->cont_902++;
	cbcstd_gcDecRef(data);


}

cbcstd_Object cbcstd_List_get(cbcstd_List self, int pos){

	if (self->first_616 != NULL){
		_cbcstd_ListNode tmp_E1pd_352 = self->first_616;

		return tmp_E1pd_352->get(tmp_E1pd_352, pos);
	}

	return NULL;


}

cbcstd_Object cbcstd_List_getLast(cbcstd_List self){

	if (self->last_90 != NULL){
		_cbcstd_ListNode tmp_xHBk_355 = self->last_90;

		return tmp_xHBk_355->data_981;
	}

	else{

	if (self->first_616 != NULL){
		_cbcstd_ListNode tmp_F25Q_358 = self->first_616;

		return tmp_F25Q_358->data_981;
	}

	}
	return NULL;


}

void cbcstd_List_push(cbcstd_List self, cbcstd_Object data){
	cbcstd_gcIncRef(data);
	_cbcstd_ListNode New = _cbcstd_ListNode_create(data);
	

	if (self->first_616 == NULL){

		self->first_616 = New;


		self->last_90 = self->first_616;
	}

	else{
		_cbcstd_ListNode tmp_2YLW_364 = self->first_616;

		tmp_2YLW_364->prev_568 = New;


		New->next_266 = self->first_616;

		self->first_616 = New;
	}


	self->cont_902++;
	cbcstd_gcDecRef(data);


}

cbcstd_Object cbcstd_List_pop(cbcstd_List self){

	if (self->first_616 != NULL){

		_cbcstd_ListNode aux = self->first_616;


		self->first_616 = aux->next_266;

		if (self->first_616 == NULL){

			self->cont_902 = 0;

			self->last_90 = NULL;
		}

		else{
			_cbcstd_ListNode tmp_lwzx_377 = self->first_616;

			tmp_lwzx_377->prev_568 = NULL;

			self->cont_902--;
		}


		cbcstd_Object ret = aux->data_981;

		aux->__end__(aux);
		return ret;
	}

	return NULL;


}

void cbcstd_List_enqueue(cbcstd_List self, cbcstd_Object data){
	cbcstd_gcIncRef(data);
	_cbcstd_ListNode New = _cbcstd_ListNode_create(data);

	if (self->last_90 == NULL){

		if (self->first_616 == NULL){

			self->first_616 = New;
		}

		else{


			New->prev_568 = self->first_616;
			_cbcstd_ListNode tmp_SQg6_387 = self->first_616;

			tmp_SQg6_387->next_266 = New;

			self->last_90 = New;
		}

	}

	else{
		_cbcstd_ListNode tmp_7aq5_390 = self->last_90;

		tmp_7aq5_390->next_266 = New;


		New->prev_568 = self->last_90;

		self->last_90 = New;
	
	}


	self->cont_902++;
	cbcstd_gcDecRef(data);


}

cbcstd_Object cbcstd_List_dequeue(cbcstd_List self){

	return self->pop(self);


}

cbcstd_Object cbcstd_List_remove(cbcstd_List self, int pos){

	if (self->first_616 != NULL){

		if (pos == self->cont_902-1){
			_cbcstd_ListNode tmp_QMut_399 = self->last_90;


			self->last_90 = tmp_QMut_399->prev_568;
		}

		_cbcstd_ListNode tmp_hnIb_402 = self->first_616;

		_cbcstd_ListNode aux = tmp_hnIb_402->remove(tmp_hnIb_402, pos);

		cbcstd_Object data = aux->data_981;

		aux->__end__(aux);

		self->cont_902--;
		return data;
	}

	return NULL;


}

void cbcstd_List_removeObject(cbcstd_List self, cbcstd_Object data){

	_cbcstd_ListNode aux = self->first_616;
	while (aux != NULL){

		if (aux->data_981 == data){

			if (aux->prev_568 != NULL){

				_cbcstd_ListNode tmp_NCyK_411 = aux->prev_568;

				tmp_NCyK_411->next_266 = aux->next_266;
			}


			if (aux->next_266 != NULL){

				_cbcstd_ListNode tmp_C7sX_415 = aux->next_266;

				tmp_C7sX_415->prev_568 = aux->prev_568;
			}


			if (aux == self->first_616){


				self->first_616 = aux->next_266;
			}


			if (aux == self->last_90){


				self->last_90 = aux->prev_568;
			}

			cbcstd_destroyObj((cbcstd_Object*)&(aux));

			self->cont_902--;
			return;
		}


		aux = aux->next_266;
		
	}


}

bool cbcstd_List_contains(cbcstd_List self, cbcstd_Object data){

	_cbcstd_ListNode aux = self->first_616;
	while (aux != NULL){

		if (aux->data_981 == data){
			return true;
		}


		aux = aux->next_266;
	}

	return false;
			

}

uint cbcstd_List_size(cbcstd_List self){

	return self->cont_902;


}

void cbcstd_List_clear(cbcstd_List self){

	_cbcstd_ListNode aux = self->first_616;
	while (aux != NULL){

		_cbcstd_ListNode next = aux->next_266;

		aux->__end__(aux);
		aux = next;
	}


	aux = self->last_90;

	self->first_616 = NULL;

	self->last_90 = NULL;

	self->cont_902 = 0;


}

void cbcstd_List___iterinit__(cbcstd_List self, bool reversed){
	if (reversed){




		self->iter_item_194 = (self->last_90 == NULL)? self->first_616 : self->last_90;
	}

	else{


		self->iter_item_194 = self->first_616;

	}


}

bool cbcstd_List___iternext__(cbcstd_List self, cbcstd_Object* dest){

	if (self->iter_item_194 != NULL){
		_cbcstd_ListNode tmp_Kv9j_443 = self->iter_item_194;

		cbcstd_gcAssign(&(*dest), tmp_Kv9j_443->data_981);
		_cbcstd_ListNode tmp_eLXC_445 = self->iter_item_194;


		self->iter_item_194 = tmp_eLXC_445->next_266;
		return true;
	}

	cbcstd_gcAssign(&(*dest), NULL);
	return false;


}

bool cbcstd_List___iterprev__(cbcstd_List self, cbcstd_Object* dest){

	if (self->iter_item_194 != NULL){
		_cbcstd_ListNode tmp_JooJ_449 = self->iter_item_194;

		cbcstd_gcAssign(&(*dest), tmp_JooJ_449->data_981);
		_cbcstd_ListNode tmp_AfTf_451 = self->iter_item_194;


		self->iter_item_194 = tmp_AfTf_451->prev_568;
		return true;
	}

	cbcstd_gcAssign(&(*dest), NULL);
	return false;


}

void* cbcstd_List___str__(cbcstd_List self){

	if (self->first_616 != NULL){
		cbcstd_String ret = cbcstd_String_create("[");

		_cbcstd_ListNode node = self->first_616;
		while (node != NULL){

			cbcstd_String to_cat = node->__str__(node);


			cbcstd_String newStr = ret->cat(ret, to_cat->c_str(to_cat));

			to_cat->__end__(to_cat);

			ret->__end__(ret);
			ret = newStr;

			if (node->next_266 != NULL){

				cbcstd_String newStr = ret->cat(ret, ", ");

				ret->__end__(ret);
				ret = newStr;
			}


			node = node->next_266;
		}


		cbcstd_String newStr = ret->cat(ret, "]");

		ret->__end__(ret);
		ret = newStr;
		return ret;
		
	}

	else{
		return cbcstd_String_create("[]");

	}


}

void cbcstd_List_enduser(cbcstd_List self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	self->clear(self);

}


cbcstd_Array cbcstd_Array_create(size_t size){
	cbcstd_Array self = (cbcstd_Array)cbcstd_alloc(sizeof(cbcstd_Array_struct));
	try{
		cbcstd_Array_init(self, size);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Array_init(cbcstd_Array self, size_t size){
	cbcstd_Array_initsystem(self);
	cbcstd_Array_inituser(self, size);
}
void cbcstd_Array_initsystem(cbcstd_Array self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-8969464831777141981L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Array_struct);
	self->_setSize_57 = &cbcstd_Array__setSize_57;
	self->_setMax_529 = &cbcstd_Array__setMax_529;
	self->_checkIndex_236 = &cbcstd_Array__checkIndex_236;
	self->_checkSize_883 = &cbcstd_Array__checkSize_883;
	self->get = &cbcstd_Array_get;
	self->insert = &cbcstd_Array_insert;
	self->add = &cbcstd_Array_add;
	self->remove = &cbcstd_Array_remove;
	self->contains = &cbcstd_Array_contains;
	self->__iterinit__ = &cbcstd_Array___iterinit__;
	self->__iternext__ = &cbcstd_Array___iternext__;
	self->__iterprev__ = &cbcstd_Array___iterprev__;
	self->__str__ = &cbcstd_Array___str__;
	self->__end__ = &cbcstd_Array_end;
}
void cbcstd_Array_end(cbcstd_Array self){
	cbcstd_Array_enduser(self);
	cbcstd_Array_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Array_decrefs(cbcstd_Array self){
}





	
void cbcstd_Array_inituser(cbcstd_Array self, size_t size){

	self->max_336 = size;

	self->size_871 = 0;

	self->elems_407 = CBC_NEW(cbcstd_Object, size);


}

void cbcstd_Array_enduser(cbcstd_Array self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	{int i=0; for (; i<self->size_871; i++){

		cbcstd_gcAssign(&(self->elems_407[i]), NULL);
	}}


	cbcstd_destroy(&(self->elems_407));



}

void cbcstd_Array__setSize_57(cbcstd_Array self, size_t size){

	self->size_871 = size;


}

void cbcstd_Array__setMax_529(cbcstd_Array self, size_t max){

	self->max_336 = max;


}

void cbcstd_Array__checkIndex_236(cbcstd_Array self, size_t index){

	if (index >= self->size_871){
		cthrow((cbcstd_Exception)(cbcstd_OutOfBounds_create()));

	}


}

void cbcstd_Array__checkSize_883(cbcstd_Array self){


	if (self->size_871 >= self->max_336){
		cthrow((cbcstd_Exception)(cbcstd_ArrayFull_create()));

	}


}

cbcstd_Object cbcstd_Array_get(cbcstd_Array self, size_t index){

	self->_checkIndex_236(self, index);

	return self->elems_407[index];


}

void cbcstd_Array_insert(cbcstd_Array self, cbcstd_Object o, size_t index){
	cbcstd_gcIncRef(o);

	self->_checkIndex_236(self, index);

	cbcstd_gcAssign(&(self->elems_407[index]), o);
	cbcstd_gcDecRef(o);


}

void cbcstd_Array_add(cbcstd_Array self, cbcstd_Object o){
	cbcstd_gcIncRef(o);

	self->_checkSize_883(self);


	cbcstd_gcAssign(&(self->elems_407[self->size_871++]), o);
	cbcstd_gcDecRef(o);


}

cbcstd_Object cbcstd_Array_remove(cbcstd_Array self, size_t index){

	cbcstd_Object ret = self->get(self, index);

	{int i=index+1; for (; i<self->size_871; i++){


		cbcstd_gcAssign(&(self->elems_407[index]), self->elems_407[i]);
		index++;
	}}


	self->size_871--;


	{int i=self->size_871; for (; i<self->max_336; i++){

		cbcstd_gcAssign(&(self->elems_407[i]), NULL);
	}}

	return ret;


}

bool cbcstd_Array_contains(cbcstd_Array self, cbcstd_Object data){

	{int i=0; for (; i<self->size_871; i++){

		if (self->get(self, i) == data){
			return true;
		}

	}}

	return false;


}

void cbcstd_Array___iterinit__(cbcstd_Array self, bool reversed){
	if (reversed){


		self->iterator_212 = self->size_871-1;
	}

	else{

		self->iterator_212 = 0;

	}


}

bool cbcstd_Array___iternext__(cbcstd_Array self, cbcstd_Object* dest){


	if (self->iterator_212 < self->size_871){


		cbcstd_gcAssign(&(*dest), self->elems_407[self->iterator_212++]);
		return true;
	}

	cbcstd_gcAssign(&(*dest), NULL);
	return false;


}

bool cbcstd_Array___iterprev__(cbcstd_Array self, cbcstd_Object* dest){

	if (self->iterator_212 >= 0){


		cbcstd_gcAssign(&(*dest), self->elems_407[self->iterator_212--]);
		return true;
	}

	cbcstd_gcAssign(&(*dest), NULL);
	return false;


}

void* cbcstd_Array___str__(cbcstd_Array self){

	if (self->size_871 > 0){
		cbcstd_String ret = cbcstd_String_create("[");

		{int i=0; for (; i<self->size_871; i++){
			cbcstd_Object tmp_fb77_508 = self->elems_407[i];

			cbcstd_String to_cat = tmp_fb77_508->__str__(tmp_fb77_508);


			cbcstd_String newStr = ret->cat(ret, to_cat->c_str(to_cat));

			to_cat->__end__(to_cat);

			ret->__end__(ret);
			ret = newStr;

			if (i < self->size_871-1){

				cbcstd_String Str = ret->cat(ret, ", ");

				ret->__end__(ret);
				ret = Str;
			}

		}}


		cbcstd_String newStr = ret->cat(ret, "]");

		ret->__end__(ret);
		ret = newStr;
		return ret;
		
	}

	else{
		return cbcstd_String_create("[]");
	}


}


cbcstd_Vector cbcstd_Vector_create(){
	cbcstd_Vector self = (cbcstd_Vector)cbcstd_alloc(sizeof(cbcstd_Vector_struct));
	try{
		cbcstd_Vector_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_Vector_init(cbcstd_Vector self){
	cbcstd_Vector_initsystem(self);
	cbcstd_Vector_inituser(self);
}
void cbcstd_Vector_initsystem(cbcstd_Vector self){
	cbcstd_Array_initsystem((cbcstd_Array)self);
	const static class_id __classid__[4] = {
		398200037585603112L,
		-8969464831777141981L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_Vector_struct);
	self->_checkSize_883 = &cbcstd_Vector__checkSize_883;
	self->_resize_466 = &cbcstd_Vector__resize_466;
	self->fit = &cbcstd_Vector_fit;
	self->__end__ = &cbcstd_Vector_end;
}
void cbcstd_Vector_enduser(cbcstd_Vector self){
	cbcstd_Array_enduser((cbcstd_Array)self);
	return;
}
void cbcstd_Vector_end(cbcstd_Vector self){
	cbcstd_Vector_enduser(self);
	cbcstd_Vector_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_Vector_decrefs(cbcstd_Vector self){
}


void cbcstd_Vector_inituser(cbcstd_Vector self){
	pass;


}

void cbcstd_Vector__checkSize_883(cbcstd_Vector self){


	if (self->size_871 >= self->max_336){


		self->_resize_466(self, self->max_336+10);

	}


}

void cbcstd_Vector__resize_466(cbcstd_Vector self, int newSize){

	if (newSize < self->size_871){
		return;
	}

	cbcstd_Object* newElems = CBC_NEW(cbcstd_Object, newSize);


	memcpy(newElems, self->elems_407, self->max_336*sizeof(cbcstd_Object_struct));

	self->_setMax_529(self, newSize);

	cbcstd_destroy(&(self->elems_407));

	self->elems_407 = newElems;


}

void cbcstd_Vector_fit(cbcstd_Vector self){


	self->_resize_466(self, self->size_871);

}


cbcstd_IOError cbcstd_IOError_create(char* fileName){
	cbcstd_IOError self = (cbcstd_IOError)cbcstd_alloc(sizeof(cbcstd_IOError_struct));
	try{
		cbcstd_IOError_init(self, fileName);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_IOError_init(cbcstd_IOError self, char* fileName){
	cbcstd_IOError_initsystem(self);
	cbcstd_IOError_inituser(self, fileName);
}
void cbcstd_IOError_initsystem(cbcstd_IOError self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		7574766057929006304L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_IOError_struct);
	self->__end__ = &cbcstd_IOError_end;
}
void cbcstd_IOError_enduser(cbcstd_IOError self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_IOError_end(cbcstd_IOError self){
	cbcstd_IOError_enduser(self);
	cbcstd_IOError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_IOError_decrefs(cbcstd_IOError self){
}

void cbcstd_IOError_inituser(cbcstd_IOError self, char* fileName){
	static const char* format = "ERROR: failed to open file: %s";
	char* description = CBC_NEW(char, strlen(format)+strlen(fileName)+1);
	sprintf(description, format, fileName);
	cbcstd_Exception_inituser((cbcstd_Exception)self, description);

}


cbcstd_File cbcstd_File_create(char* path, char* mode){
	cbcstd_File self = (cbcstd_File)cbcstd_alloc(sizeof(cbcstd_File_struct));
	try{
		cbcstd_File_init(self, path, mode);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_File_init(cbcstd_File self, char* path, char* mode){
	cbcstd_File_initsystem(self);
	cbcstd_File_inituser(self, path, mode);
}
void cbcstd_File_initsystem(cbcstd_File self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		3190857353556604009L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_File_struct);
	self->_setPath_528 = &cbcstd_File__setPath_528;
	self->_setMode_70 = &cbcstd_File__setMode_70;
	self->_setId_698 = &cbcstd_File__setId_698;
	self->_setSize_163 = &cbcstd_File__setSize_163;
	self->readAll = &cbcstd_File_readAll;
	self->read = &cbcstd_File_read;
	self->write = &cbcstd_File_write;
	self->writeString = &cbcstd_File_writeString;
	self->seek_from = &cbcstd_File_seek_from;
	self->seek = &cbcstd_File_seek;
	self->tell = &cbcstd_File_tell;
	self->findNextChar = &cbcstd_File_findNextChar;
	self->readline = &cbcstd_File_readline;
	self->readlines = &cbcstd_File_readlines;
	self->__end__ = &cbcstd_File_end;
}
void cbcstd_File_end(cbcstd_File self){
	cbcstd_File_enduser(self);
	cbcstd_File_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_File_decrefs(cbcstd_File self){
}






	
void cbcstd_File_inituser(cbcstd_File self, char* path, char* mode){

	self->path_646 = cbcstd_String_create(path);

	self->mode_821 = cbcstd_String_create(mode);

	self->id_56 = fopen(path, mode);
	

	if (self->id_56 == NULL){
		cbcstd_String tmp_bTxq_535 = self->path_646;

		tmp_bTxq_535->__end__(tmp_bTxq_535);
		cbcstd_String tmp_Hixt_537 = self->mode_821;

		tmp_Hixt_537->__end__(tmp_Hixt_537);
		cthrow((cbcstd_Exception)(cbcstd_IOError_create(path)));
	
	}


	self->seek_from(self, 0,  SEEK_END);


	self->size_765 = self->tell(self);
	

	self->seek_from(self, 0,  SEEK_SET);


}

void cbcstd_File__setPath_528(cbcstd_File self, cbcstd_String path){

	if (self->path_646 != NULL){
		cbcstd_String tmp_4IAh_544 = self->path_646;

		tmp_4IAh_544->__end__(tmp_4IAh_544);
	}


	self->path_646 = path;


}

void cbcstd_File__setMode_70(cbcstd_File self, cbcstd_String mode){

	if (self->mode_821 != NULL){
		cbcstd_String tmp_WBNi_548 = self->mode_821;

		tmp_WBNi_548->__end__(tmp_WBNi_548);
	}


	self->mode_821 = mode;


}

void cbcstd_File__setId_698(cbcstd_File self, FILE* id){

	self->id_56 = id;


}

void cbcstd_File__setSize_163(cbcstd_File self, size_t size){

	self->size_765 = size;


}

size_t cbcstd_File_readAll(cbcstd_File self, void* ptr){


	return self->read(self, ptr,  1,  self->size_765);


}

size_t cbcstd_File_read(cbcstd_File self, void* ptr, size_t size, size_t count){


	return (self->id_56 == NULL)? 0 : fread(ptr, size, count, self->id_56);


}

size_t cbcstd_File_write(cbcstd_File self, const void* ptr, size_t size, size_t count){


	return (self->id_56 == NULL)? 0 : fwrite(ptr, size, count, self->id_56);


}

size_t cbcstd_File_writeString(cbcstd_File self, cbcstd_String str){




	return (self->id_56 == NULL)? 0 : fwrite(str->c_str(str), 1, str->size(str)-1, self->id_56);


}

int cbcstd_File_seek_from(cbcstd_File self, long offset, int origin){


	return (self->id_56 == NULL)? 0 : fseek(self->id_56, offset, origin);


}

int cbcstd_File_seek(cbcstd_File self, long int offset){

	return self->seek_from(self, offset,  SEEK_SET);


}

long cbcstd_File_tell(cbcstd_File self){


	return (self->id_56 == NULL)? 0 : ftell(self->id_56);


}

long cbcstd_File_findNextChar(cbcstd_File self, char c){
	char s = 0;
	


	while (s != c && self->tell(self) != self->size_765){

		self->read(self, &s,  1,  1);
	
	}


	return (s == c)? self->tell(self) : 0;


}

cbcstd_String cbcstd_File_readline(cbcstd_File self){

	long curPos = self->tell(self);

	long newline = self->findNextChar(self, '\n');
	
	if (newline == 0){

		newline = self->size_765;
	
	}

	int size = newline-curPos;
	
	if (size == 0){
		return NULL;
	
	}


	self->seek(self, curPos);
	
	char* dest = CBC_NEW(char, size+1);
	

	self->read(self, dest,  size,  1);
	
	dest[size+1] = 0;
	
	cbcstd_String ret = cbcstd_String_create(dest);
	cbcstd_destroy(dest);
	
	return ret;


}

cbcstd_List cbcstd_File_readlines(cbcstd_File self){
	cbcstd_List ret_value = cbcstd_List_create();
	
	cbcstd_String line = NULL;
	

	line = self->readline(self);
	while (line != NULL){
		cbcstd_Object tmp_cast_qteA = (cbcstd_Object)(line);

		ret_value->push(ret_value, tmp_cast_qteA);

		line = self->readline(self);
	
	}

	return ret_value;


}

void cbcstd_File_enduser(cbcstd_File self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	fclose(self->id_56);
	cbcstd_String tmp_POyz_581 = self->path_646;

	tmp_POyz_581->__end__(tmp_POyz_581);
	cbcstd_String tmp_rilo_583 = self->mode_821;

	tmp_rilo_583->__end__(tmp_rilo_583);

}


cbcstd_ResettingGCStateException cbcstd_ResettingGCStateException_create(){
	cbcstd_ResettingGCStateException self = (cbcstd_ResettingGCStateException)cbcstd_alloc(sizeof(cbcstd_ResettingGCStateException_struct));
	try{
		cbcstd_ResettingGCStateException_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_ResettingGCStateException_init(cbcstd_ResettingGCStateException self){
	cbcstd_ResettingGCStateException_initsystem(self);
	cbcstd_ResettingGCStateException_inituser(self);
}
void cbcstd_ResettingGCStateException_initsystem(cbcstd_ResettingGCStateException self){
	cbcstd_CriticalException_initsystem((cbcstd_CriticalException)self);
	const static class_id __classid__[5] = {
		8528344343163115145L,
		5845670225932612062L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_ResettingGCStateException_struct);
	self->__end__ = &cbcstd_ResettingGCStateException_end;
}
void cbcstd_ResettingGCStateException_enduser(cbcstd_ResettingGCStateException self){
	cbcstd_CriticalException_enduser((cbcstd_CriticalException)self);
	return;
}
void cbcstd_ResettingGCStateException_end(cbcstd_ResettingGCStateException self){
	cbcstd_ResettingGCStateException_enduser(self);
	cbcstd_ResettingGCStateException_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_ResettingGCStateException_decrefs(cbcstd_ResettingGCStateException self){
}

void cbcstd_ResettingGCStateException_inituser(cbcstd_ResettingGCStateException self){
	cbcstd_CriticalException_inituser((cbcstd_CriticalException)self, "CRITICAL ERROR: You cannot change the GC state once set.");

}


cbcstd_UnsafeDeleteError cbcstd_UnsafeDeleteError_create(cbcstd_Object o){
	cbcstd_UnsafeDeleteError self = (cbcstd_UnsafeDeleteError)cbcstd_alloc(sizeof(cbcstd_UnsafeDeleteError_struct));
	try{
		cbcstd_UnsafeDeleteError_init(self, o);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_UnsafeDeleteError_init(cbcstd_UnsafeDeleteError self, cbcstd_Object o){
	cbcstd_UnsafeDeleteError_initsystem(self);
	cbcstd_UnsafeDeleteError_inituser(self, o);
}
void cbcstd_UnsafeDeleteError_initsystem(cbcstd_UnsafeDeleteError self){
	cbcstd_CriticalException_initsystem((cbcstd_CriticalException)self);
	const static class_id __classid__[5] = {
		-5718326853095492329L,
		5845670225932612062L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_UnsafeDeleteError_struct);
	self->__end__ = &cbcstd_UnsafeDeleteError_end;
}
void cbcstd_UnsafeDeleteError_enduser(cbcstd_UnsafeDeleteError self){
	cbcstd_CriticalException_enduser((cbcstd_CriticalException)self);
	return;
}
void cbcstd_UnsafeDeleteError_end(cbcstd_UnsafeDeleteError self){
	cbcstd_UnsafeDeleteError_enduser(self);
	cbcstd_UnsafeDeleteError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_UnsafeDeleteError_decrefs(cbcstd_UnsafeDeleteError self){
}

void cbcstd_UnsafeDeleteError_inituser(cbcstd_UnsafeDeleteError self, cbcstd_Object o){
	static const char* format =
		"CRITICAL ERROR: trying to delete instance that is referenced multiple times.\n"
		"Instance reference: %zx\nClass ID: %zd";
	char desc[256];

	sprintf(desc, format, (size_t)o, o->__type__[0]);
	cbcstd_CriticalException_inituser((cbcstd_CriticalException)self, desc);

}


static void _cbcstd_waitGcMutex(){
	if (cbcstd_gc_mutex != NULL){

		cbcstd_gc_mutex->wait(cbcstd_gc_mutex);

	}


}

static void _cbcstd_releaseGcMutex(){
	if (cbcstd_gc_mutex != NULL){

		cbcstd_gc_mutex->release(cbcstd_gc_mutex);

	}


}

static bool _cbcstd_objectCollected(cbcstd_Object o){
	{int i=0; for (; i<20; i++){
		if (o == cbcstd_to_remove[i]){
			return true;
		}

	}}

	return false;


}

static void _cbcstd_destroyCollectedObjects(){
	{int i=0; for (; i<cbcstd_gc_counter; i++){

		cbcstd_to_remove[i]->__end__(cbcstd_to_remove[i]);
	}}

	cbcstd_gc_counter = 0;


}

static void _cbcstd_collectObject(cbcstd_Object o){
	_cbcstd_waitGcMutex();
	if (_cbcstd_objectCollected(o)){
		_cbcstd_releaseGcMutex();
		return;
	}

	if (cbcstd_gc_counter >= 20){
		_cbcstd_destroyCollectedObjects();
	}

	cbcstd_to_remove[cbcstd_gc_counter++] = o;
	_cbcstd_releaseGcMutex();


}

void cbcstd_gcFlush(){
	if (not cbcstd_gc_enable){
		return;
	}

	_cbcstd_waitGcMutex();
	_cbcstd_destroyCollectedObjects();
	_cbcstd_releaseGcMutex();


}

void cbcstd_gcSetState(bool state){
	if (cbcstd_gc_set){
		cthrow((cbcstd_Exception)(cbcstd_ResettingGCStateException_create()));
	}

	cbcstd_gc_enable = (bool)state;
	cbcstd_gc_set = true;


}

void cbcstd_gcIncRef(cbcstd_Object o){
	
	_cbcstd_waitGcMutex();
	if (cbcstd_gc_enable and o != NULL){

		o->__refs__++;
	
	}

	_cbcstd_releaseGcMutex();


}

static void _cbcstd_gcDecRefCommon(cbcstd_Object o){
	if (cbcstd_gc_enable and o != NULL){

		if (o->__refs__ > 0){

			o->__refs__--;

		}

	}


}

void cbcstd_gcDecRef(cbcstd_Object o){
	
	_cbcstd_waitGcMutex();
	_cbcstd_gcDecRefCommon(o);
	
	
	cbcstd_gcCheckRefs(o);
	_cbcstd_releaseGcMutex();


}

void cbcstd_gcDecRefOnly(cbcstd_Object o){
	
	_cbcstd_waitGcMutex();
	_cbcstd_gcDecRefCommon(o);
	
	_cbcstd_releaseGcMutex();


}

bool cbcstd_gcCheckRefs(cbcstd_Object o){
	
	_cbcstd_waitGcMutex();
	if (not cbcstd_gc_enable or o == NULL){
		
		_cbcstd_releaseGcMutex();
		return false;
	}


	if (o->__refs__ == 0 and not istypeof(o, _cbcstd_ObjectLock)){
		printf("collected object with reference 0x%zx and type %zd\n", o, classid(o));
		
		_cbcstd_collectObject(o);
		return true;
	
	}

	_cbcstd_releaseGcMutex();
	return false;


}

static void _cbcstd_gcAssignCommon(void** dst, void* src, bool isDeclared){
	
	void* prev = *dst;
	
	
		
	_cbcstd_waitGcMutex();
	
	if (not cbcstd_gc_enable){
		*dst = src;
		
			
		_cbcstd_releaseGcMutex();
		return;
	
	}

	if (prev != src){
		if (not isDeclared and prev != NULL) _cbcstd_gcDecRefCommon(prev);
		*dst = src;
		if (src != NULL) cbcstd_gcIncRef(src);
	
	
	
	}

	cbcstd_gcCheckRefs(prev);
	_cbcstd_releaseGcMutex();


}

void cbcstd_gcAssign(void** dst, void* src){
	_cbcstd_gcAssignCommon(dst, src, false);


}

void cbcstd_gcAssignDeclared(void** dst, void* src){
	_cbcstd_gcAssignCommon(dst, src, true);







































}

cbcstd_Semaphore print_sema;

cbcstd_PrintFormatError cbcstd_PrintFormatError_create(char format){
	cbcstd_PrintFormatError self = (cbcstd_PrintFormatError)cbcstd_alloc(sizeof(cbcstd_PrintFormatError_struct));
	try{
		cbcstd_PrintFormatError_init(self, format);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cbcstd_PrintFormatError_init(cbcstd_PrintFormatError self, char format){
	cbcstd_PrintFormatError_initsystem(self);
	cbcstd_PrintFormatError_inituser(self, format);
}
void cbcstd_PrintFormatError_initsystem(cbcstd_PrintFormatError self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		4810669106351579541L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cbcstd_PrintFormatError_struct);
	self->__end__ = &cbcstd_PrintFormatError_end;
}
void cbcstd_PrintFormatError_enduser(cbcstd_PrintFormatError self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void cbcstd_PrintFormatError_end(cbcstd_PrintFormatError self){
	cbcstd_PrintFormatError_enduser(self);
	cbcstd_PrintFormatError_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cbcstd_PrintFormatError_decrefs(cbcstd_PrintFormatError self){
}

void cbcstd_PrintFormatError_inituser(cbcstd_PrintFormatError self, char format){
	static char* description = "ERROR: invalid format character %c\n";
	char tmp[36];
	snprintf(tmp, 36, description, format);
	cbcstd_Exception_inituser((cbcstd_Exception)self, tmp);

}


void cbcstd_print(char* format, ...){

	print_sema->wait(print_sema);

	va_list argv;
	
	va_start(argv, format);
	
	char f;
	size_t i = 0;
	while (f = format[i++]){
		switch (f){
			case 'n':{
			}

			case 'o':{
				cbcstd_Object to_print = NULL;
				cbcstd_gcAssign(&to_print, va_arg(argv, cbcstd_Object));

				cbcstd_String s = to_print->__str__(to_print);

				printf("%s%s", s->c_str(s), (format[i]==0)? "" : " ");

				s->__end__(s);
				if (f == 'n'){

					to_print->__end__(to_print);
				}

				else{
					cbcstd_gcAssign(&to_print, NULL);
				}

				break;
			}

			case 's':{
				char* to_print = va_arg(argv, char*);
				printf("%s%s", to_print, (format[i]==0)? "" : " ");
				break;
			}

			case 'i':{
				ssize_t to_print = va_arg(argv, ssize_t);
				printf("%zd%s", to_print, (format[i]==0)? "" : " ");
				break;
			}

			case 'c':{
				char to_print = (char)(va_arg(argv, int));
				printf("%c%s", to_print, (format[i]==0)? "" : " ");
				break;
			}

			case 'f':{
				double to_print = va_arg(argv, double);
				printf("%lf%s", to_print, (format[i]==0)? "" : " ");
				break;
			}

			case 'p':{
				char* format = va_arg(argv, char*);
				size_t value = va_arg(argv, size_t);
				char dest[512];
				sprintf(dest, format, value);
				printf("%s%s", dest, (format[i]==0)? "" : " ");
				break;
			}

			default:{
				cthrow((cbcstd_Exception)(cbcstd_PrintFormatError_create(f)));
	
			}

		}

	}

	va_end(argv);
	
	printf("\n");
	

	print_sema->release(print_sema);






}

static long* stack_trace_end = NULL;
static cbcstd_thread_t main_thread;




void cbcstd_debugUseless(void* unused){
	static void* useless = NULL;
	useless = unused;







}

void cbcstd_setTraceEnd(long* trace_end){
	stack_trace_end = trace_end;


}

void cbcstd_printStackTrace(){
	return;


}

cbcstd_Array cbcstd_args = NULL;



void cbcstd_setArguments(int argc, char** argv){
	cbcstd__argc = argc;
	cbcstd__argv = argv;


}

static void _cbcstd_parseArguments(){
	if (cbcstd_args != NULL){
		return;
	
	}

	cbcstd_gcAssign(&cbcstd_args, cbcstd_Array_create(cbcstd__argc));
	{int i=0; for (; i<cbcstd__argc; i++){

		cbcstd_args->add(cbcstd_args, cbcstd_String_create(cbcstd__argv[i]));






	}}


}

bool cbcstd_isinstanceof(cbcstd_Object o, class_id classid){
	if (o == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Trying to check instance of NULL object.")));
	}

	int i=0;
	long type = 0;
	do{

		type = o->__type__[i];
		if (type == classid){
			return true;
		}

		i++;
	}

	while (type);
	
	return false;







}

bool cbcstd_istypeof(cbcstd_Object o, class_id classid){
	if (o == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("Trying to check type of NULL object.")));
	}

	return classid(o) == classid;





}

bool cbcstd_isidof(class_id var, class_id classid){
	return var == classid;






}

void* cbcstd_alloc(size_t bytes){
	void* ret = malloc(bytes);
	if (ret == NULL){
		cthrow((cbcstd_Exception)(cbcstd_OutOfMemoryError_create()));
	}

	memset(ret, 0, bytes);
	return ret;


}

static bool _cbcstd_checkPtr(void* ptr){
	if (ptr == NULL){
		#ifdef cbc_nulldeletecheck
		cthrow((cbcstd_Exception)(cbcstd_NullPointerDelete_create()));
		#else
		return false;
		#endif
	}

	return true;





}

void cbcstd_destroy(void** ptr){
	if (_cbcstd_checkPtr(*ptr)){
		free(*ptr);
		*ptr = NULL;





	}


}

void cbcstd_destroyObj(cbcstd_Object* o){
	cbcstd_Object obj = *o;
	if (_cbcstd_checkPtr(((void*)(obj)))){
		if (cbcstd_gc_enable){
			cbcstd_gcDecRef(obj);
		}

		else{

			obj->__end__(obj);
			*o = NULL;




		}

	}


}

cbcstd_Object cbcstd_objectOperate(cbcstd_Object src, cbcstd_Object other, char op, bool modify, bool eliminateOther){
	cbcstd_Object ret = NULL;

	if (other != NULL and cbcstd_isinstanceof(other, src->__type__[0])){

		ret = src->__operate__(src, other,  op,  modify);
	}

	if (eliminateOther){

		other->__end__(other);
	}

	if (ret == NULL){


		cthrow((cbcstd_Exception)(cbcstd_ObjectOperateError_create(src->__type__[0], other->__type__[0])));
	}

	return other;






}

int cbcstd_objectCompare(cbcstd_Object src, cbcstd_Object other){
	if (src == other){
		return 0;
	}


	if (not cbcstd_isinstanceof(other, src->__type__[0])){


		cthrow((cbcstd_Exception)(cbcstd_ObjectCompareError_create(src->__type__[0], other->__type__[0])));
	}


	return src->__cmp__(src, other);


}

void cbcstd_init(){

	cbcstd_Object tmp_new_1aqg = (cbcstd_Object)(cbcstd_NoneType_create());
	cbcstd_Object tmp_cast_DXhY = (cbcstd_Object)(tmp_new_1aqg);
	cbcstd_gcAssign(&cbcstd___None__, tmp_cast_DXhY);
	cbcstd_gcAssign(&(cbcstd___bools__[0]), cbcstd_Bool_create(false));
	cbcstd_gcAssign(&(cbcstd___bools__[1]), cbcstd_Bool_create(true));
	
	cbcstd_gcAssign(&cbcstd_gc_mutex, cbcstd_Mutex_create(cbcstd_PERMISIVE_MUTEX));
	cbcstd_gcAssign(&cbcstd_excep_mutex, cbcstd_Mutex_create(cbcstd_PERMISIVE_MUTEX));
	cbcstd_gcAssign(&print_sema, cbcstd_Semaphore_create(1));
	cbcstd_Object tmp_new_t3Rd = (cbcstd_Object)(cbcstd_NoExceptionError_create());
	cbcstd_Exception tmp_cast_7yeh = (cbcstd_Exception)(tmp_new_t3Rd);
	cbcstd_gcAssign(&cbcstd_std_exception, tmp_cast_7yeh);
	cbcstd_Object tmp_new_gqrS = (cbcstd_Object)(cbcstd_OutOfMemoryError_create());
	cbcstd_Exception tmp_cast_tEhc = (cbcstd_Exception)(tmp_new_gqrS);
	cbcstd_gcAssign(&cbcstd_critical_memory, tmp_cast_tEhc);
	
	_cbcstd_parseArguments();

}

