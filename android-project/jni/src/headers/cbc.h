#ifndef CBC_H
#define CBC_H
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <setjmp.h>
#include <pthread.h>
#include <semaphore.h>

// this must be defined if the target system has multithreading
#define __cbc_multithreading

// this file must be found in the same place as the main namespace
// it defines possible configuration for CbC
#include <cbc_config.h>

// Global code for launching exceptions
#define EXCEPTION_CODE -1

// Defines the variable type for storing a class ID
typedef long class_id;

// Common class type checking
#define isinstanceof(x, y) cbcstd_isinstanceof((cbcstd_Object)(x), y##__classid__)
#define istypeof(x, y) cbcstd_istypeof((cbcstd_Object)(x), y##__classid__)
#define isidof(x, y) cbcstd_isidof((long)(x), y##__classid__)
#define classid(x) ((cbcstd_Object)(x))->__type__[0]

// Other functions that require the class name to be turned into the class ID
#define cbcstd_registerExceptionHandler(x, y) cbcstd_registerCriticalExceptionHandler(x##__classid__, y)
#define cbcstd_unregisterExceptionHandler(x) cbcstd_unregisterCriticalExceptionHandler(x##__classid__)

// Being a higher-level language, CbC prefers the use of words rather than symbols to express statements.
// This part of the header associates CbC statements that can be easily mapped to C symbolism.

#define and &&
#define or ||
#define not !
#define elif else if
#define pass if(0){}

// Low level try-catch implemented with set/longjmp

#define try do{switch(setjmp((struct __jmp_buf_tag*)cbcstd_registerExceptionBuffer()) ){case 0:while(1){
#define ccatch break;case EXCEPTION_CODE:
#define finally break;}default:
#define etry }}while(0)
#define cthrow(x) if(1){cbcstd_registerException(x);\
	jmp_buf exc_buf;\
	longjmp((struct __jmp_buf_tag*)(cbcstd_obtainNextExceptionBuffer(&exc_buf)),EXCEPTION_CODE);\
	}
#define cbc_catch(e) else if(isinstanceof(sys_tmp_exc, e))

// Common CbC types that can be easily mapped to C types

// data types composed of two components
#define dlong long long

// unsigned data types
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define udlong unsigned long long

// CbC protected singleton types
#define None cbcstd_getNone()
#define True cbcstd_getBool(1)
#define False cbcstd_getBool(0)

// cbc4c
// A collection of defines and API that lets you use CbC modules and objects.
// This API is designed as a replacement for manually accessing CbC code by anticipating the outcome
// that is of course a bad idea as the outcome can change from version to version, while this API
// should never change.
// This API is still in development.

// Initialize all CbC modules and standard library
#define CBC_INIT(argc, argv) cbcinit(argc, argv)

// Call the main CbC function
#define CBC_MAIN() main_main()

// Call a module's main function
#define MOD_MAIN(x) x##_main()

// Access a module global name
#define _MOD_ACCESS(mod) mod##_
#define MOD_ACCESS(mod, name) _MOD_ACCESS(mod)#name

// Create a class instance
#define CBC_CREATE_OBJECT(class, args) class##_create(args)
#define CBC_VOID_CREATE_OBJECT(class) class##_create()

// Create an interface
#define CBC_CREATE_INTERFACE(interface, implementor, args) implementor##_create_#interface(args)
#define CBC_VOID_CREATE_INTERFACE(interface, implementor) implementor##_create_#interface()

// Safely cast an instance of a type to an instance of another type
// Mainly used to access an instance as an interface
#define CBC_INTERFACE_CAST(var, class) (((cbcstd_Object)(var))->__getvtable__(var, class##__classid__))
#define CBC_LOW_CAST(var, class) ((class)CBC_INTERFACE_CAST(var, class))

// Access a class method
#define CBC_METHOD(instance, method, args) instance->method(instance, args)
#define CBC_VOID_METHOD(instance, method) instance->method(instance)

// Access a class method statically
#define CBC_STATIC_METHOD(class, method, instance, args) class##_#method(instance, args)
#define CBC_STATIC_VOID_METHOD(class, method, instance) class##_#method(instance)

// Access an interface
#define CBC_INTERFACE_METHOD(interface, instance, method, args) CBC_LOW_CAST(instance, interface)->method(instance, args)
#define CBC_INTERFACE_VOID_METHOD(interface, instance, method) CBC_LOW_CAST(instance, interface)->method(instance)

// Access a class attribute (private and property cannot be accessed)
#define CBC_ATTR(instance, attr) instance->attr

// Foreach loop
#define CBC_FOREACH(ins, var) ins->__iterinit__(ins, false);while(ins->__iternext__(ins,&var))

// Reversed foreach
#define CBC_RFOREACH(ins, var) ins->__iterinit__(ins, true);while(ins->__iterprev__(ins,&var))

// Access CbC allocator
#define CBC_NEW(type, count) (type*)cbcstd_alloc(sizeof(type)*(count))

// Access CbC deallocator
#define CBC_DELETE(x) cbcstd_destroy(&(x))
#define CBC_DELETE_OBJ(x) cbcstd_destroyObject(&(x))

#endif
