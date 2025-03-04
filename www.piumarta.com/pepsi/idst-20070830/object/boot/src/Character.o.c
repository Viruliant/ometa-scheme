/* generated by Id 1.0 at 2007-04-24 00:11:04 Z */
/* with the command: -I../stage1/ -I. -c Character.st -o ../stage2/Character.o.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <assert.h>
#define GC_DLL 1
#include <gc/gc.h>
#if defined(WIN32)
# include <malloc.h>
# include <windows.h>
  typedef HINSTANCE dlhandle_t;
# define dlopen(path, mode)	LoadLibrary(path)
# define dlsym(handle, name)	((void *)GetProcAddress(handle, name))
# define dlclose(handle)	FreeLibrary(handle)
# include <winbase.h>
  inline int gettimeofday(struct timeval *tp, void *tzp)
  {
     union {
       long long ns100;
       FILETIME ft;
     } _now;
     GetSystemTimeAsFileTime(&_now.ft);
     tp->tv_usec= (long)((_now.ns100 / 10LL) % 1000000LL);
     tp->tv_sec= (long)((_now.ns100 - (116444736000000000LL)) / 10000000LL);
     return 0;
   }
#else
# include <dlfcn.h>
  typedef void *dlhandle_t;
#endif
#ifndef O_BINARY
# define O_BINARY 0
#endif

typedef struct t__object *oop;

typedef oop (*_imp_t)(oop _thunk, oop receiver, ...);

struct __closure
{
  _imp_t method;
  oop	 data;
};

static void              *(*_local_param   )(int index)= 0;
static oop  		  (*_local_intern  )(const char *string)= 0;
static oop  		  (*_local_proto   )(oop base)= 0;
static oop  		  (*_local_import  )(const char *name)= 0;
static oop  		  (*_local_export  )(const char *name, oop value)= 0;
static void 		  (*_local_method  )(oop type, oop selector, _imp_t method)= 0;
static oop  		  (*_local_alloc   )(oop type, size_t size)= 0;
static oop  		 *(*_local_palloc  )(size_t size)= 0;
static void  		 *(*_local_balloc  )(size_t size)= 0;
static struct __closure  *(*_local_bind    )(oop selector, oop receiver)= 0;
static oop                (*_local_nlreturn)(oop nlr, oop result)= 0;
static oop                (*_local_nlresult)(void)= 0;
static oop  		    _local_object= 0;
static oop  		   *_local_tag_vtable= 0;
static oop  		   *_local_nil_vtable= 0;
static void               (*_local_gc_addRoots)(char *lo, char *hi)= 0;
static void	          (*_local_gc_unregisterDisappearingLink)(void *ptr)= 0;
static void		  (*_local_gc_generalRegisterDisappearingLink)(void *link, void *ptr)= 0;
static void		  (*_local_gc_gcollect)(void)= 0;

#define _param(INDEX)		_local_param(INDEX)
#define _selector(NAME)		_local_intern(NAME)
#define _proto(BASE)		_local_proto(BASE)
#define _id_import(NAME)	_local_import(NAME)
#define _id_export(NAME, VAL)	_local_export((NAME), (VAL))
#define _method(TYPE, SEL, IMP)	_local_method((TYPE), (SEL), (_imp_t)(IMP))
#define _alloc(RCV, LBS)	_local_alloc((RCV), (LBS))
#define _palloc(LBS)		_local_palloc((LBS))
#define _balloc(LBS)		_local_balloc((LBS))
#define _nlreturn(NLR, ARG)	_local_nlreturn((NLR), (ARG))
#define _nlresult()		_local_nlresult()

#define _send(MSG, RCV, ARG...) ({					\
  register oop _r= (RCV);						\
  struct __closure *_c= (struct __closure *)_local_bind((MSG), _r);	\
  (_c->method)((oop)_c, _r, _r, ##ARG);					\
})

#define _super(TYP, MSG, RCV, ARG...) ({				\
  register oop _r= (RCV);						\
  struct __closure *_c= (struct __closure *)_local_bind((MSG), (TYP));	\
  (_c->method)((oop)_c, _r, _r, ##ARG);					\
})

static oop s_negated= 0;
static oop s_nextPut_= 0;
static oop s_asString= 0;
static oop s__5c_5c= 0;
static oop s__5fdebugName= 0;
static oop s__2a= 0;
static oop s_peek= 0;
static oop s_new= 0;
static oop s_with_= 0;
static oop s_not= 0;
static oop s__5fvalue_= 0;
static oop s_isLetter= 0;
static oop s_error_= 0;
static oop s_asciiValue= 0;
static oop s__5fsizeof= 0;
static oop s_new_= 0;
static oop s_next= 0;
static oop s_hash= 0;
static oop s_new_5f_= 0;
static oop s_value_5f_= 0;
static oop s__5fimport_= 0;
static oop s_atEnd= 0;
static oop s_skip_= 0;
static oop s__2d= 0;
static oop s_to_do_= 0;
static oop s__2b= 0;
static oop s__2f_2f= 0;
static oop s_ifTrue_= 0;
static oop s__2c= 0;
static oop s_isDigit= 0;
static oop s__3d_3d= 0;
static oop s_digitValue= 0;
static oop s__3d= 0;
static oop s_readFrom_base_= 0;
static oop s_whileFalse_= 0;
static oop s_isCharacter= 0;
static oop s_function_5f_arity_5f_= 0;
static oop s_and_= 0;
static oop s__3c= 0;
static oop s__3e= 0;
static oop s_asUppercase= 0;
static oop s_ifTrue_ifFalse_= 0;
static oop s_asLowercase= 0;
static oop s_digitValue_= 0;
static oop s_size_5f_value_5f_= 0;
static oop s_or_= 0;
static oop s_between_and_= 0;
static oop s_value_= 0;
static oop s_printOctalOn_= 0;
static oop s_at_= 0;
static oop s_function_5f_arity_5f_outer_state_nlr_5f_= 0;
static oop s__3e_3d= 0;
static oop s_value= 0;
static oop s_asInteger= 0;
static oop s_at_put_= 0;
static oop s_contents= 0;
static struct _Selector { const char *name; oop *addr; } _Selectors[]= {
  { "negated", &s_negated },
  { "nextPut:", &s_nextPut_ },
  { "asString", &s_asString },
  { "\\\\", &s__5c_5c },
  { "_debugName", &s__5fdebugName },
  { "*", &s__2a },
  { "peek", &s_peek },
  { "new", &s_new },
  { "with:", &s_with_ },
  { "not", &s_not },
  { "_value:", &s__5fvalue_ },
  { "isLetter", &s_isLetter },
  { "error:", &s_error_ },
  { "asciiValue", &s_asciiValue },
  { "_sizeof", &s__5fsizeof },
  { "new:", &s_new_ },
  { "next", &s_next },
  { "hash", &s_hash },
  { "new_:", &s_new_5f_ },
  { "value_:", &s_value_5f_ },
  { "_import:", &s__5fimport_ },
  { "atEnd", &s_atEnd },
  { "skip:", &s_skip_ },
  { "-", &s__2d },
  { "to:do:", &s_to_do_ },
  { "+", &s__2b },
  { "//", &s__2f_2f },
  { "ifTrue:", &s_ifTrue_ },
  { ",", &s__2c },
  { "isDigit", &s_isDigit },
  { "==", &s__3d_3d },
  { "digitValue", &s_digitValue },
  { "=", &s__3d },
  { "readFrom:base:", &s_readFrom_base_ },
  { "whileFalse:", &s_whileFalse_ },
  { "isCharacter", &s_isCharacter },
  { "function_:arity_:", &s_function_5f_arity_5f_ },
  { "and:", &s_and_ },
  { "<", &s__3c },
  { ">", &s__3e },
  { "asUppercase", &s_asUppercase },
  { "ifTrue:ifFalse:", &s_ifTrue_ifFalse_ },
  { "asLowercase", &s_asLowercase },
  { "digitValue:", &s_digitValue_ },
  { "size_:value_:", &s_size_5f_value_5f_ },
  { "or:", &s_or_ },
  { "between:and:", &s_between_and_ },
  { "value:", &s_value_ },
  { "printOctalOn:", &s_printOctalOn_ },
  { "at:", &s_at_ },
  { "function_:arity_:outer:state:nlr_:", &s_function_5f_arity_5f_outer_state_nlr_5f_ },
  { ">=", &s__3e_3d },
  { "value", &s_value },
  { "asInteger", &s_asInteger },
  { "at:put:", &s_at_put_ },
  { "contents", &s_contents },
  { 0, 0 }
};
struct t__object {
  struct _vtable *_vtable[0];
};
struct t__selector {
  struct _vtable *_vtable[0];
  oop v__size;
  oop v__elements;
};
struct t__assoc {
  struct _vtable *_vtable[0];
  oop v_key;
  oop v_value;
};
struct t__closure {
  struct _vtable *_vtable[0];
  oop v__method;
  oop v_data;
};
struct t__vector {
  struct _vtable *_vtable[0];
  oop v__size;
};
struct t__vtable {
  struct _vtable *_vtable[0];
  oop v__tally;
  oop v_bindings;
  oop v_delegate;
};
struct t_Object {
  struct _vtable *_vtable[0];
};
struct t_UndefinedObject {
  struct _vtable *_vtable[0];
};
struct t_StaticBlockClosure {
  struct _vtable *_vtable[0];
  oop v__function;
  oop v__arity;
};
struct t_BlockClosure {
  struct _vtable *_vtable[0];
  oop v__function;
  oop v__arity;
  oop v_outer;
  oop v_state;
  oop v__nlr;
};
struct t_Magnitude {
  struct _vtable *_vtable[0];
};
struct t_Character {
  struct _vtable *_vtable[0];
  oop v_value;
};
struct t_Number {
  struct _vtable *_vtable[0];
};
struct t_Fraction {
  struct _vtable *_vtable[0];
  oop v_numerator;
  oop v_denominator;
};
struct t_Float {
  struct _vtable *_vtable[0];
};
struct t_Integer {
  struct _vtable *_vtable[0];
};
struct t_SmallInteger {
  struct _vtable *_vtable[0];
};
struct t_LargePositiveInteger {
  struct _vtable *_vtable[0];
  oop v_bytes;
};
struct t_LargeNegativeInteger {
  struct _vtable *_vtable[0];
  oop v_bytes;
};
struct t_Collection {
  struct _vtable *_vtable[0];
};
struct t_SequenceableCollection {
  struct _vtable *_vtable[0];
};
struct t_ArrayedCollection {
  struct _vtable *_vtable[0];
  oop v_size;
};
struct t_Array {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__pointers;
};
struct t_ImmutableArray {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__pointers;
};
struct t_WordArray {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__words;
};
struct t_ImmutableWordArray {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__words;
};
struct t_ByteArray {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__bytes;
};
struct t_ImmutableByteArray {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__bytes;
};
struct t_String {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__bytes;
};
struct t_ImmutableString {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__bytes;
};
struct t_Symbol {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__bytes;
};
struct t_nil {
  struct _vtable *_vtable[0];
};
struct t_true {
  struct _vtable *_vtable[0];
};
struct t_false {
  struct _vtable *_vtable[0];
};
struct t_CharacterTable {
  struct _vtable *_vtable[0];
  oop v_size;
  oop v__pointers;
};
static oop l_1= 0;
static oop l_2= 0;
static oop l_3= 0;
static oop l_5= 0;
static oop l_4= 0;
static oop l_6= 0;
static oop l_7= 0;
static oop l_8= 0;
static oop l_9= 0;
static oop l_10= 0;
static oop l_11= 0;
static oop l_12= 0;
static oop l_13= 0;
static oop l_14= 0;
static oop l_15= 0;
static oop l_16= 0;
static oop l_17= 0;
static oop l_18= 0;
static oop l_19= 0;
static oop l_20= 0;
static oop l_21= 0;
static oop l_22= 0;
static oop l_23= 0;
static oop l_24= 0;
static oop l_25= 0;
static oop l_26= 0;
static oop l_27= 0;
static oop l_28= 0;
static oop l_29= 0;
static oop l_30= 0;
static oop l_31= 0;
static oop l_32= 0;
static oop l_33= 0;
static oop l_34= 0;
static oop l_35= 0;
static oop l_36= 0;
static oop l_37= 0;
static oop l_38= 0;
static oop l_39= 0;
static oop l_40= 0;
static oop l_41= 0;
static oop l_42= 0;
static oop l_43= 0;
static oop l_44= 0;
static oop l_45= 0;
static oop l_46= 0;
static oop l_47= 0;
static oop l_48= 0;
static oop l_49= 0;
static oop l_50= 0;
static oop l_51= 0;
static oop l_52= 0;
static oop l_53= 0;
static oop l_54= 0;
static oop l_55= 0;
static oop l_56= 0;
static oop l_57= 0;
static oop l_58= 0;
static oop l_59= 0;
static oop l_60= 0;
static oop l_61= 0;
static oop l_62= 0;
static oop l_63= 0;
static oop l_64= 0;
static oop l_65= 0;
static oop l_66= 0;
static oop l_67= 0;
static oop l_70= 0;
static oop l_71= 0;
static oop l_72= 0;
static oop l_73= 0;
static oop v__object= 0;
static oop v__vector= 0;
static oop v_Object= 0;
static oop v_UndefinedObject= 0;
static oop v_StaticBlockClosure= 0;
static oop v_BlockClosure= 0;
static oop v_Magnitude= 0;
static oop v_Character= 0;
static oop v_Number= 0;
static oop v_Integer= 0;
static oop v_SmallInteger= 0;
static oop v_LargePositiveInteger= 0;
static oop v_Collection= 0;
static oop v_SequenceableCollection= 0;
static oop v_ArrayedCollection= 0;
static oop v_Array= 0;
static oop v_ImmutableArray= 0;
static oop v_WordArray= 0;
static oop v_ByteArray= 0;
static oop v_String= 0;
static oop v_ImmutableString= 0;
static oop v_true= 0;
static oop v_false= 0;
static oop v_CharacterTable= 0;
static oop al_54[256]= {
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_18,
  
(oop)&l_19,
  
(oop)&l_20,
  
(oop)&l_21,
  
(oop)&l_22,
  
(oop)&l_23,
  
(oop)&l_24,
  
(oop)&l_25,
  
(oop)&l_26,
  
(oop)&l_27,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_28,
  
(oop)&l_29,
  
(oop)&l_30,
  
(oop)&l_31,
  
(oop)&l_32,
  
(oop)&l_33,
  
(oop)&l_34,
  
(oop)&l_35,
  
(oop)&l_36,
  
(oop)&l_37,
  
(oop)&l_38,
  
(oop)&l_39,
  
(oop)&l_40,
  
(oop)&l_41,
  
(oop)&l_42,
  
(oop)&l_43,
  
(oop)&l_44,
  
(oop)&l_45,
  
(oop)&l_46,
  
(oop)&l_47,
  
(oop)&l_48,
  
(oop)&l_49,
  
(oop)&l_50,
  
(oop)&l_51,
  
(oop)&l_52,
  
(oop)&l_53,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_28,
  
(oop)&l_29,
  
(oop)&l_30,
  
(oop)&l_31,
  
(oop)&l_32,
  
(oop)&l_33,
  
(oop)&l_34,
  
(oop)&l_35,
  
(oop)&l_36,
  
(oop)&l_37,
  
(oop)&l_38,
  
(oop)&l_39,
  
(oop)&l_40,
  
(oop)&l_41,
  
(oop)&l_42,
  
(oop)&l_43,
  
(oop)&l_44,
  
(oop)&l_45,
  
(oop)&l_46,
  
(oop)&l_47,
  
(oop)&l_48,
  
(oop)&l_49,
  
(oop)&l_50,
  
(oop)&l_51,
  
(oop)&l_52,
  
(oop)&l_53,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17,
  
(oop)&l_17
};
static oop Character__isCharacter(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_true;
  return _1;
 }
static oop Object__isCharacter(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_false;
  return _1;
 }
static oop Character___5fvalue_(oop v__closure, oop v_stateful_self, oop v_self, oop v_anInteger)
 {
  oop _1= 0;
  _1= v_self;
  _1=_super(v_Magnitude, s_new, _1);
  v_self= _1;
  v_stateful_self= _1;
  _1= v_anInteger;
  ((struct t_Character *)v_stateful_self)->v_value= _1;
  _1= v_self;
  return _1;
 }
static size_t CharacterTable___5fsizeof(oop _closure, oop v_self) { return sizeof(struct t_CharacterTable); }
static char *CharacterTable___5fdebugName(oop _closure, oop v_self) { return "CharacterTable"; }
static oop b_4(oop v__closure, oop v__self, oop v_i)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  _1= v_CharacterTable;
  _2= v_i;
  _3= l_5;
  {
    int _l= (int)_2 >> 1;
    int _r= (int)_3 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _2= (oop)(_s << 1 | 1);  else _2= _send(s__2b, _2, _3);
  }
  _3= v_Character;
  _4= v_i;
  _3=_send(s__5fvalue_, _3, _4);
  _1=_send(s_at_put_, _1, _2, _3);
  return _1;
 }
static oop Character__value_(oop v__closure, oop v_stateful_self, oop v_self, oop v_anInteger)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_CharacterTable;
  _2= v_anInteger;
  _3= l_6;
  {
    int _l= (int)_2 >> 1;
    int _r= (int)_3 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _2= (oop)(_s << 1 | 1);  else _2= _send(s__2b, _2, _3);
  }
  _1=_send(s_at_, _1, _2);
  return _1;
 }
static oop Character__value_5f_(oop v__closure, oop v_stateful_self, oop v_self, oop v__int)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_self;
  _2= v_SmallInteger;
  _3= v__int;
  _2=_send(s_value_5f_, _2, _3);
  _1=_send(s_value_, _1, _2);
  return _1;
 }
static oop Character__asciiValue(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  return _1;
 }
static oop Character__value(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  return _1;
 }
static oop Character__asInteger(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  return _1;
 }
static oop Character__hash(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  _2= l_7;
  {
    int _l= (int)_1 >> 1;
    int _r= (int)_2 >> 1;
    int _s= (_l * _r);
    if ((1 & (int)_1) && ((_r == 0) || (_s / _r == _l)) && ((_s ^ (_s << 1)) >= 0))  _1= (oop)(_s << 1 | 1);  else _1= _send(s__2a, _1, _2);
  }
  return _1;
 }
static oop Character___3d(oop v__closure, oop v_stateful_self, oop v_self, oop v_aCharacter)
 {
  oop _1= 0;
  oop _2= 0;
  /* and: */
  _1= v_aCharacter;
  _1=_send(s_isCharacter, _1);
  if (!_1) goto _l1;
 {
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  _2= v_aCharacter;
  _2=_send(s_asciiValue, _2);
  _1= (_1 == _2) ? v_true : v_false;
 }
 _l1:;
  return _1;
 }
static oop Character___3c(oop v__closure, oop v_stateful_self, oop v_self, oop v_aCharacter)
 {
  oop _1= 0;
  oop _2= 0;
  /* and: */
  _1= v_aCharacter;
  _1=_send(s_isCharacter, _1);
  if (!_1) goto _l2;
 {
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  _2= v_aCharacter;
  _2=_send(s_asciiValue, _2);
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
 }
 _l2:;
  return _1;
 }
static oop Character___3e(oop v__closure, oop v_stateful_self, oop v_self, oop v_aCharacter)
 {
  oop _1= 0;
  oop _2= 0;
  /* and: */
  _1= v_aCharacter;
  _1=_send(s_isCharacter, _1);
  if (!_1) goto _l3;
 {
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  _2= v_aCharacter;
  _2=_send(s_asciiValue, _2);
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 > (int)_2) ? v_true : v_false);
  } else _1= _send(s__3e, _1, _2);
 }
 _l3:;
  return _1;
 }
static oop Character__asUppercase(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  /* ifTrue:ifFalse: */
  /* and: */
  _1= l_8;
  _2= ((struct t_Character *)v_stateful_self)->v_value;
  if (1 & (int)_2) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
  if (!_1) goto _l6;
 {
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  _2= l_9;
  if (1 & (int)_1) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
 }
 _l6:;
  if (!_1) goto _l4;
 {
  _1= v_Character;
  _2= ((struct t_Character *)v_stateful_self)->v_value;
  _3= l_10;
  {
    int _l= (int)_2 >> 1;
    int _r= (int)_3 >> 1;
    int _s= (_l - _r);
    if ((1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _2= (oop)(_s << 1 | 1);  else _2= _send(s__2d, _2, _3);
  }
  _1=_send(s_value_, _1, _2);
 }
  goto _l5;
 _l4:;
 {
  _1= v_self;
 }
 _l5:;
  return _1;
 }
static oop Character__asLowercase(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  /* ifTrue:ifFalse: */
  /* and: */
  _1= l_11;
  _2= ((struct t_Character *)v_stateful_self)->v_value;
  if (1 & (int)_2) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
  if (!_1) goto _l9;
 {
  _1= ((struct t_Character *)v_stateful_self)->v_value;
  _2= l_12;
  if (1 & (int)_1) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
 }
 _l9:;
  if (!_1) goto _l7;
 {
  _1= v_Character;
  _2= ((struct t_Character *)v_stateful_self)->v_value;
  _3= l_13;
  {
    int _l= (int)_2 >> 1;
    int _r= (int)_3 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _2= (oop)(_s << 1 | 1);  else _2= _send(s__2b, _2, _3);
  }
  _1=_send(s_value_, _1, _2);
 }
  goto _l8;
 _l7:;
 {
  _1= v_self;
 }
 _l8:;
  return _1;
 }
static oop Character__asString(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  _1= v_String;
  _2= v_self;
  _1=_send(s_with_, _1, _2);
  return _1;
 }
static oop Character__digitValue_(oop v__closure, oop v_stateful_self, oop v_self, oop v_anInteger)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_self;
  /* ifTrue:ifFalse: */
  _2= v_anInteger;
  _3= l_14;
  if (1 & (int)_2) {
    _2= (((int)_2 < (int)_3) ? v_true : v_false);
  } else _2= _send(s__3c, _2, _3);
  if (!_2) goto _l10;
 {
  _2= l_15;
 }
  goto _l11;
 _l10:;
 {
  _2= l_16;
 }
 _l11:;
  _3= v_anInteger;
  {
    int _l= (int)_2 >> 1;
    int _r= (int)_3 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_2 & (int)_3) && ((_s ^ (_s << 1)) >= 0))  _2= (oop)(_s << 1 | 1);  else _2= _send(s__2b, _2, _3);
  }
  _1=_send(s_value_, _1, _2);
  return _1;
 }
static oop Character__digitValue(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= l_54;
  _2= l_19;
  _3= v_self;
  _3=_send(s_asciiValue, _3);
  {
    int _l= (int)_2 >> 1;
    int _r= (int)_3 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_3) && ((_s ^ (_s << 1)) >= 0))  _2= (oop)(_s << 1 | 1);  else _2= _send(s__2b, _2, _3);
  }
  _1=_send(s_at_, _1, _2);
  return _1;
 }
static oop Character__isLetter(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  /* or: */
  _1= v_self;
  _2= l_55;
  _3= l_56;
  _1=_send(s_between_and_, _1, _2, _3);
  if (_1) goto _l12;
 {
  _1= v_self;
  _2= l_57;
  _3= l_58;
  _1=_send(s_between_and_, _1, _2, _3);
 }
 _l12:;
  return _1;
 }
static oop Character__isDigit(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_self;
  _2= l_59;
  _3= l_60;
  _1=_send(s_between_and_, _1, _2, _3);
  return _1;
 }
static oop Character__printOctalOn_(oop v__closure, oop v_stateful_self, oop v_self, oop v_aStream)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  _1= v_aStream;
  _2= v_Character;
  _3= v_self;
  _3=_send(s_asciiValue, _3);
  _4= l_61;
  _3= _send(s__2f_2f, _3, _4);
  _4= l_62;
  _3= _send(s__5c_5c, _3, _4);
  _2=_send(s_digitValue_, _2, _3);
  _send(s_nextPut_, _1, _2);
  _2= v_Character;
  _3= v_self;
  _3=_send(s_asciiValue, _3);
  _4= l_62;
  _3= _send(s__2f_2f, _3, _4);
  _4= l_62;
  _3= _send(s__5c_5c, _3, _4);
  _2=_send(s_digitValue_, _2, _3);
  _send(s_nextPut_, _1, _2);
  _2= v_Character;
  _3= v_self;
  _3=_send(s_asciiValue, _3);
  _4= l_63;
  _3= _send(s__2f_2f, _3, _4);
  _4= l_62;
  _3= _send(s__5c_5c, _3, _4);
  _2=_send(s_digitValue_, _2, _3);
  _1=_send(s_nextPut_, _1, _2);
  _1= v_self;
  return _1;
 }
static oop b_68(oop v__closure, oop v__self)
 {
  oop _1= 0;
  _1= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[1];  /* aStream */
  _1=_send(s_atEnd, _1);
  return _1;
 }
static oop b_69(oop v__closure, oop v__self)
 {
  oop v_digit= 0;
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  (void)v_digit;
  _1= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[1];  /* aStream */
  _1=_send(s_next, _1);
  v_digit= _1;
  /* ifTrue:ifFalse: */
  _1= v_digit;
  _2= l_70;
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 == (int)_2) ? v_true : v_false);
  } else _1= _send(s__3d, _1, _2);
  if (!_1) goto _l13;
 {
  /* ifTrue: */
  _1= 0;
  _2= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[2];  /* value */
  _3= l_71;
  if (1 & (int)_2) {
    _2= (((int)_2 < (int)_3) ? v_true : v_false);
  } else _2= _send(s__3c, _2, _3);
  if (!_2) goto _l15;
 {
  _1= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[3];  /* self */
  _2= l_72;
  _1=_send(s_error_, _1, _2);
 }
 _l15:;
  _1= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[2];  /* value */
  ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[5]= _1;  /* base */
  _1= l_64;
  ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[2]= _1;  /* value */
 }
  goto _l14;
 _l13:;
 {
  _1= v_digit;
  _1=_send(s_digitValue, _1);
  v_digit= _1;
  /* ifTrue: */
  _1= 0;
  /* or: */
  _2= v_digit;
  _3= l_64;
  if (1 & (int)_2) {
    _2= (((int)_2 < (int)_3) ? v_true : v_false);
  } else _2= _send(s__3c, _2, _3);
  if (_2) goto _l17;
 {
  _2= v_digit;
  _3= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[5];  /* base */
  if (1 & (int)_2 & (int)_3) {
    _2= (((int)_2 >= (int)_3) ? v_true : v_false);
  } else _2= _send(s__3e_3d, _2, _3);
 }
 _l17:;
  if (!_2) goto _l16;
 {
  _1= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[3];  /* self */
  _2= l_73;
  _3= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[1];  /* aStream */
  _3=_send(s_contents, _3);
  _2=_send(s__2c, _2, _3);
  _1=_send(s_error_, _1, _2);
 }
 _l16:;
  _1= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[2];  /* value */
  _2= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[5];  /* base */
  {
    int _l= (int)_1 >> 1;
    int _r= (int)_2 >> 1;
    int _s= (_l * _r);
    if ((1 & (int)_1 & (int)_2) && ((_r == 0) || (_s / _r == _l)) && ((_s ^ (_s << 1)) >= 0))  _1= (oop)(_s << 1 | 1);  else _1= _send(s__2a, _1, _2);
  }
  _2= v_digit;
  {
    int _l= (int)_1 >> 1;
    int _r= (int)_2 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _1= (oop)(_s << 1 | 1);  else _1= _send(s__2b, _1, _2);
  }
  ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[2]= _1;  /* value */
 }
 _l14:;
  return _1;
 }
static oop Integer__readFrom_base_(oop v__closure, oop v_stateful_self, oop v_self, oop v_aStream, oop v_base)
 {
  oop _state1= _send(s_new_5f_, v__vector, 6);
  oop v_negative= 0;
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  (void)v_negative;
  ((oop *)_state1)[4]= v_stateful_self;
  ((oop *)_state1)[3]= v_self;
  ((oop *)_state1)[1]= v_aStream;
  ((oop *)_state1)[5]= v_base;
  _1= v_false;
  v_negative= _1;
  _1= l_64;
  ((oop *)_state1)[2]= _1;  /* value */
  /* ifTrue:ifFalse: */
  _1= ((oop *)_state1)[1];  /* aStream */
  _1=_send(s_peek, _1);
  _2= l_65;
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 == (int)_2) ? v_true : v_false);
  } else _1= _send(s__3d, _1, _2);
  if (!_1) goto _l18;
 {
  _1= ((oop *)_state1)[1];  /* aStream */
  _2= l_66;
  _1=_send(s_skip_, _1, _2);
 }
  goto _l19;
 _l18:;
 {
  /* ifTrue: */
  _1= 0;
  _2= ((oop *)_state1)[1];  /* aStream */
  _2=_send(s_peek, _2);
  _3= l_67;
  if (1 & (int)_2 & (int)_3) {
    _2= (((int)_2 == (int)_3) ? v_true : v_false);
  } else _2= _send(s__3d, _2, _3);
  if (!_2) goto _l20;
 {
  _1= v_negative;
  _1=_send(s_not, _1);
  v_negative= _1;
  _1= ((oop *)_state1)[1];  /* aStream */
  _2= l_66;
  _1=_send(s_skip_, _1, _2);
 }
 _l20:;
 }
 _l19:;
  /* Scope() */
  /* Scope('negative'->TemporaryVariableNode 'self'->ArgumentVariableNode 'base'->ArgumentVariableNode 'value'->TemporaryVariableNode 'stateful_self'->ArgumentVariableNode 'aStream'->ArgumentVariableNode) */
  /* nil */
  /* 2 */
  /* 1 */
  _1= _send(s_function_5f_arity_5f_outer_state_nlr_5f_, v_BlockClosure, (oop)b_68, 0, 0, ((oop *)_state1), 0);
  /* Scope('digit'->TemporaryVariableNode) */
  /* Scope('negative'->TemporaryVariableNode 'self'->ArgumentVariableNode 'base'->ArgumentVariableNode 'value'->TemporaryVariableNode 'stateful_self'->ArgumentVariableNode 'aStream'->ArgumentVariableNode) */
  /* nil */
  /* 2 */
  /* 1 */
  _2= _send(s_function_5f_arity_5f_outer_state_nlr_5f_, v_BlockClosure, (oop)b_69, 0, 0, ((oop *)_state1), 0);
  _1=_send(s_whileFalse_, _1, _2);
  /* ifTrue:ifFalse: */
  _1= v_negative;
  if (!_1) goto _l21;
 {
  _1= ((oop *)_state1)[2];  /* value */
  _1=_send(s_negated, _1);
 }
  goto _l22;
 _l21:;
 {
  _1= ((oop *)_state1)[2];  /* value */
 }
 _l22:;
  return _1;
 }

void __id__init__Character(void)
{
  if (_local_object) return;
  { 
    dlhandle_t global= dlopen(0, RTLD_LAZY);
    _local_object= *(oop *)dlsym(global, "_libid_object");
    _local_param= dlsym(global, "_libid_param");
    _local_intern= dlsym(global, "_libid_intern");
    _local_proto= dlsym(global, "_libid_proto");
    _local_import= dlsym(global, "_libid_import");
    _local_export= dlsym(global, "_libid_export");
    _local_method= dlsym(global, "_libid_method");
    _local_alloc= dlsym(global, "_libid_alloc");
    _local_palloc= dlsym(global, "_libid_palloc");
    _local_balloc= dlsym(global, "_libid_balloc");
    _local_bind= dlsym(global, "_libid_bind");
    _local_nlreturn= dlsym(global, "_libid_nlreturn");
    _local_nlresult= dlsym(global, "_libid_nlresult");
    _local_tag_vtable= dlsym(global, "_libid_tag_vtable");
    _local_nil_vtable= dlsym(global, "_libid_nil_vtable");
    _local_gc_addRoots= dlsym(global, "GC_add_roots");
    _local_gc_unregisterDisappearingLink= dlsym(global, "GC_unregister_disappearing_link");
    _local_gc_generalRegisterDisappearingLink= dlsym(global, "GC_general_register_disappearing_link");
    _local_gc_gcollect= dlsym(global, "GC_gcollect");
    dlclose(global);
  }
# define GC_add_roots _local_gc_addRoots
  GC_INIT();
  {
    struct _Selector *s= 0;
    for (s= _Selectors;  s->name;  ++s)
      *s->addr= _selector(s->name);
  }

  _send(s__5fimport_, _local_object, "Magnitude", "__id__init__Magnitude");
  _send(s__5fimport_, _local_object, "Object", "__id__init__Object");
  _send(s__5fimport_, _local_object, "_object", "__id__init___5fobject");
  v__object= _id_import("_object");
  v__vector= _id_import("_vector");
  v_Object= _id_import("Object");
  v_UndefinedObject= _id_import("UndefinedObject");
  v_StaticBlockClosure= _id_import("StaticBlockClosure");
  v_BlockClosure= _id_import("BlockClosure");
  v_Magnitude= _id_import("Magnitude");
  v_Character= _id_import("Character");
  v_Number= _id_import("Number");
  v_Integer= _id_import("Integer");
  v_SmallInteger= _id_import("SmallInteger");
  v_LargePositiveInteger= _id_import("LargePositiveInteger");
  v_Collection= _id_import("Collection");
  v_SequenceableCollection= _id_import("SequenceableCollection");
  v_ArrayedCollection= _id_import("ArrayedCollection");
  v_Array= _id_import("Array");
  v_ImmutableArray= _id_import("ImmutableArray");
  v_WordArray= _id_import("WordArray");
  v_ByteArray= _id_import("ByteArray");
  v_String= _id_import("String");
  v_ImmutableString= _id_import("ImmutableString");
  v_true= _id_import("true");
  v_false= _id_import("false");
  _send(s__5fimport_, _local_object, "BlockClosure", "__id__init__BlockClosure");
  _send(s__5fimport_, _local_object, "SmallInteger", "__id__init__SmallInteger");
  _send(s__5fimport_, _local_object, "Integer", "__id__init__Integer");
  _send(s__5fimport_, _local_object, "Number", "__id__init__Number");
  _send(s__5fimport_, _local_object, "Array", "__id__init__Array");
  _send(s__5fimport_, _local_object, "ArrayedCollection", "__id__init__ArrayedCollection");
  _send(s__5fimport_, _local_object, "SequenceableCollection", "__id__init__SequenceableCollection");
  _send(s__5fimport_, _local_object, "Collection", "__id__init__Collection");
  _send(s__5fimport_, _local_object, "Character", "__id__init__Character");
  _send(s__5fimport_, _local_object, "String", "__id__init__String");
  _send(s__5fimport_, _local_object, "ByteArray", "__id__init__ByteArray");
  _send(s__5fimport_, _local_object, "WordArray", "__id__init__WordArray");
  _method(v_Character, s_isCharacter, Character__isCharacter);
  _method(v_Object, s_isCharacter, Object__isCharacter);
  _method(v_Character, s__5fvalue_, Character___5fvalue_);
  v_CharacterTable= _proto(v_Array);
  _method(v_CharacterTable, s__5fsizeof, CharacterTable___5fsizeof);
  _method(v_CharacterTable, s__5fdebugName, CharacterTable___5fdebugName);
  _id_export("CharacterTable", v_CharacterTable);
  l_1= _send(s_value_5f_, v_SmallInteger, 256);
  l_2= _send(s_value_5f_, v_SmallInteger, 0);
  l_3= _send(s_value_5f_, v_SmallInteger, 255);
  l_5= _send(s_value_5f_, v_SmallInteger, 1);
  l_4= _send(s_function_5f_arity_5f_, v_StaticBlockClosure, b_4, 1);
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_Array;
  _2= l_1;
  _1=_send(s_new_, _1, _2);
  v_CharacterTable= _1;
  _id_export("CharacterTable", v_CharacterTable);
  _1= l_2;
  _2= l_3;
  _3= l_4;
  _1=_send(s_to_do_, _1, _2, _3);
 }
  l_6= _send(s_value_5f_, v_SmallInteger, 1);
  _method(v_Character, s_value_, Character__value_);
  _method(v_Character, s_value_5f_, Character__value_5f_);
  _method(v_Character, s_asciiValue, Character__asciiValue);
  _method(v_Character, s_value, Character__value);
  _method(v_Character, s_asInteger, Character__asInteger);
  l_7= _send(s_value_5f_, v_SmallInteger, 6653);
  _method(v_Character, s_hash, Character__hash);
  _method(v_Character, s__3d, Character___3d);
  _method(v_Character, s__3c, Character___3c);
  _method(v_Character, s__3e, Character___3e);
  l_8= _send(s_value_5f_, v_SmallInteger, 96);
  l_9= _send(s_value_5f_, v_SmallInteger, 123);
  l_10= _send(s_value_5f_, v_SmallInteger, 32);
  _method(v_Character, s_asUppercase, Character__asUppercase);
  l_11= _send(s_value_5f_, v_SmallInteger, 64);
  l_12= _send(s_value_5f_, v_SmallInteger, 91);
  l_13= _send(s_value_5f_, v_SmallInteger, 32);
  _method(v_Character, s_asLowercase, Character__asLowercase);
  _method(v_Character, s_asString, Character__asString);
  l_14= _send(s_value_5f_, v_SmallInteger, 10);
  l_15= _send(s_value_5f_, v_SmallInteger, 48);
  l_16= _send(s_value_5f_, v_SmallInteger, 87);
  _method(v_Character, s_digitValue_, Character__digitValue_);
  l_17= _send(s_value_5f_, v_SmallInteger, -1);
  l_18= _send(s_value_5f_, v_SmallInteger, 0);
  l_19= _send(s_value_5f_, v_SmallInteger, 1);
  l_20= _send(s_value_5f_, v_SmallInteger, 2);
  l_21= _send(s_value_5f_, v_SmallInteger, 3);
  l_22= _send(s_value_5f_, v_SmallInteger, 4);
  l_23= _send(s_value_5f_, v_SmallInteger, 5);
  l_24= _send(s_value_5f_, v_SmallInteger, 6);
  l_25= _send(s_value_5f_, v_SmallInteger, 7);
  l_26= _send(s_value_5f_, v_SmallInteger, 8);
  l_27= _send(s_value_5f_, v_SmallInteger, 9);
  l_28= _send(s_value_5f_, v_SmallInteger, 10);
  l_29= _send(s_value_5f_, v_SmallInteger, 11);
  l_30= _send(s_value_5f_, v_SmallInteger, 12);
  l_31= _send(s_value_5f_, v_SmallInteger, 13);
  l_32= _send(s_value_5f_, v_SmallInteger, 14);
  l_33= _send(s_value_5f_, v_SmallInteger, 15);
  l_34= _send(s_value_5f_, v_SmallInteger, 16);
  l_35= _send(s_value_5f_, v_SmallInteger, 17);
  l_36= _send(s_value_5f_, v_SmallInteger, 18);
  l_37= _send(s_value_5f_, v_SmallInteger, 19);
  l_38= _send(s_value_5f_, v_SmallInteger, 20);
  l_39= _send(s_value_5f_, v_SmallInteger, 21);
  l_40= _send(s_value_5f_, v_SmallInteger, 22);
  l_41= _send(s_value_5f_, v_SmallInteger, 23);
  l_42= _send(s_value_5f_, v_SmallInteger, 24);
  l_43= _send(s_value_5f_, v_SmallInteger, 25);
  l_44= _send(s_value_5f_, v_SmallInteger, 26);
  l_45= _send(s_value_5f_, v_SmallInteger, 27);
  l_46= _send(s_value_5f_, v_SmallInteger, 28);
  l_47= _send(s_value_5f_, v_SmallInteger, 29);
  l_48= _send(s_value_5f_, v_SmallInteger, 30);
  l_49= _send(s_value_5f_, v_SmallInteger, 31);
  l_50= _send(s_value_5f_, v_SmallInteger, 32);
  l_51= _send(s_value_5f_, v_SmallInteger, 33);
  l_52= _send(s_value_5f_, v_SmallInteger, 34);
  l_53= _send(s_value_5f_, v_SmallInteger, 35);
  l_54= _send(s_size_5f_value_5f_, v_ImmutableArray, 256, al_54);
  _method(v_Character, s_digitValue, Character__digitValue);
  l_55= _send(s_value_5f_, v_Character, 97);
  l_56= _send(s_value_5f_, v_Character, 122);
  l_57= _send(s_value_5f_, v_Character, 65);
  l_58= _send(s_value_5f_, v_Character, 90);
  _method(v_Character, s_isLetter, Character__isLetter);
  l_59= _send(s_value_5f_, v_Character, 48);
  l_60= _send(s_value_5f_, v_Character, 57);
  _method(v_Character, s_isDigit, Character__isDigit);
  l_61= _send(s_value_5f_, v_SmallInteger, 64);
  l_62= _send(s_value_5f_, v_SmallInteger, 8);
  l_63= _send(s_value_5f_, v_SmallInteger, 1);
  _method(v_Character, s_printOctalOn_, Character__printOctalOn_);
  l_64= _send(s_value_5f_, v_SmallInteger, 0);
  l_65= _send(s_value_5f_, v_Character, 43);
  l_66= _send(s_value_5f_, v_SmallInteger, 1);
  l_67= _send(s_value_5f_, v_Character, 45);
  l_70= _send(s_value_5f_, v_Character, 114);
  l_71= _send(s_value_5f_, v_SmallInteger, 2);
  l_72= _send(s_size_5f_value_5f_, v_ImmutableString, 33, "illegal radix in integer constant");
  l_73= _send(s_size_5f_value_5f_, v_ImmutableString, 35, "illegal digit in integer constant: ");
  _method(v_Integer, s_readFrom_base_, Integer__readFrom_base_);
}
