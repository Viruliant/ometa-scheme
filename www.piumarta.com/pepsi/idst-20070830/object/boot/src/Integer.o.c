/* generated by Id 1.0 at 2007-04-24 00:11:09 Z */
/* with the command: -I../stage1/ -I. -c Integer.st -o ../stage2/Integer.o.c */

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

static oop s_asFloat= 0;
static oop s_value_5f_= 0;
static oop s_negative= 0;
static oop s__5fimport_= 0;
static oop s_print_= 0;
static oop s_print= 0;
static oop s_put= 0;
static oop s_negated= 0;
static oop s_normalize= 0;
static oop s_ifTrue_= 0;
static oop s__2b= 0;
static oop s__2f_2f= 0;
static oop s__2f= 0;
static oop s_nextPut_= 0;
static oop s_abs= 0;
static oop s__3d= 0;
static oop s__5c_5c= 0;
static oop s_digitDiv_neg_= 0;
static oop s_ifTrue_ifFalse_= 0;
static oop s_numerator_denominator_= 0;
static oop s_adaptToInteger_andSend_= 0;
static oop s_size_5f_value_5f_= 0;
static oop s__3c= 0;
static oop s_digitValue_= 0;
static oop s_printOn_radix_= 0;
static oop s_reduced= 0;
static oop s__3e_3d= 0;
static oop s_at_= 0;
static oop s__7e_7e= 0;
static oop s_isInteger= 0;
static oop s_asInteger= 0;
static struct _Selector { const char *name; oop *addr; } _Selectors[]= {
  { "asFloat", &s_asFloat },
  { "value_:", &s_value_5f_ },
  { "negative", &s_negative },
  { "_import:", &s__5fimport_ },
  { "print:", &s_print_ },
  { "print", &s_print },
  { "put", &s_put },
  { "negated", &s_negated },
  { "normalize", &s_normalize },
  { "ifTrue:", &s_ifTrue_ },
  { "+", &s__2b },
  { "//", &s__2f_2f },
  { "/", &s__2f },
  { "nextPut:", &s_nextPut_ },
  { "abs", &s_abs },
  { "=", &s__3d },
  { "\\\\", &s__5c_5c },
  { "digitDiv:neg:", &s_digitDiv_neg_ },
  { "ifTrue:ifFalse:", &s_ifTrue_ifFalse_ },
  { "numerator:denominator:", &s_numerator_denominator_ },
  { "adaptToInteger:andSend:", &s_adaptToInteger_andSend_ },
  { "size_:value_:", &s_size_5f_value_5f_ },
  { "<", &s__3c },
  { "digitValue:", &s_digitValue_ },
  { "printOn:radix:", &s_printOn_radix_ },
  { "reduced", &s_reduced },
  { ">=", &s__3e_3d },
  { "at:", &s_at_ },
  { "~~", &s__7e_7e },
  { "isInteger", &s_isInteger },
  { "asInteger", &s_asInteger },
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
static oop l_4= 0;
static oop l_5= 0;
static oop l_6= 0;
static oop l_7= 0;
static oop l_8= 0;
static oop l_9= 0;
static oop l_10= 0;
static oop v__object= 0;
static oop v_Object= 0;
static oop v_UndefinedObject= 0;
static oop v_StaticBlockClosure= 0;
static oop v_Magnitude= 0;
static oop v_Character= 0;
static oop v_Number= 0;
static oop v_Fraction= 0;
static oop v_Float= 0;
static oop v_Integer= 0;
static oop v_SmallInteger= 0;
static oop v_LargePositiveInteger= 0;
static oop v_Collection= 0;
static oop v_SequenceableCollection= 0;
static oop v_ArrayedCollection= 0;
static oop v_Array= 0;
static oop v_WordArray= 0;
static oop v_ByteArray= 0;
static oop v_String= 0;
static oop v_ImmutableString= 0;
static oop v_Symbol= 0;
static oop v_true= 0;
static oop v_false= 0;
static oop Object__isInteger(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_false;
  return _1;
 }
static oop Integer__isInteger(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_true;
  return _1;
 }
static oop Integer__asInteger(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_self;
  return _1;
 }
static oop Integer__normalize(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_self;
  return _1;
 }
static oop Integer___2f(oop v__closure, oop v_stateful_self, oop v_self, oop v_aNumber)
 {
  oop v_quoRem= 0;
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  (void)v_quoRem;
  /* ifTrue: */
  _1= 0;
  _2= v_aNumber;
  _2=_send(s_isInteger, _2);
  if (!_2) goto _l1;
 {
  _1= v_self;
  _2= v_aNumber;
  _2=_send(s_abs, _2);
  _3= v_self;
  _3=_send(s_negative, _3);
  _4= v_aNumber;
  _4=_send(s_negative, _4);
  _3= (_3 != _4) ? v_true : v_false;
  _1=_send(s_digitDiv_neg_, _1, _2, _3);
  v_quoRem= _1;
  /* ifTrue:ifFalse: */
  _1= v_quoRem;
  _2= l_1;
  _1=_send(s_at_, _1, _2);
  _2= l_2;
  if (1 & (int)_1) {
    _1= (((int)_1 == (int)_2) ? v_true : v_false);
  } else _1= _send(s__3d, _1, _2);
  if (!_1) goto _l2;
 {
  _1= v_quoRem;
  _2= l_3;
  _1=_send(s_at_, _1, _2);
  _1=_send(s_normalize, _1);
 }
  goto _l3;
 _l2:;
 {
  _1= v_Fraction;
  _2= v_self;
  _3= v_aNumber;
  _1=_send(s_numerator_denominator_, _1, _2, _3);
  _1=_send(s_reduced, _1);
 }
 _l3:;
  return _1;
 }
 _l1:;
  _1= v_aNumber;
  _2= v_self;
  _3= l_4;
  _1=_send(s_adaptToInteger_andSend_, _1, _2, _3);
  return _1;
 }
static oop Integer__print(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop v_n= 0;
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  (void)v_n;
  _1= l_5;
  v_n= _1;
  /* ifTrue: */
  _1= 0;
  _2= v_self;
  _3= l_5;
  if (1 & (int)_2) {
    _2= (((int)_2 < (int)_3) ? v_true : v_false);
  } else _2= _send(s__3c, _2, _3);
  if (!_2) goto _l4;
 {
  _1= l_6;
  _1=_send(s_put, _1);
  _1= l_7;
  _2= v_self;
  _2=_send(s_negated, _2);
  _2=_send(s_print, _2);
  {
    int _l= (int)_1 >> 1;
    int _r= (int)_2 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _1= (oop)(_s << 1 | 1);  else _1= _send(s__2b, _1, _2);
  }
  return _1;
 }
 _l4:;
  /* ifTrue: */
  _1= 0;
  _2= v_self;
  _3= l_8;
  if (1 & (int)_2) {
    _2= (((int)_2 >= (int)_3) ? v_true : v_false);
  } else _2= _send(s__3e_3d, _2, _3);
  if (!_2) goto _l5;
 {
  _1= v_n;
  _2= v_self;
  _3= l_8;
  _2= _send(s__2f_2f, _2, _3);
  _2=_send(s_print, _2);
  {
    int _l= (int)_1 >> 1;
    int _r= (int)_2 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _1= (oop)(_s << 1 | 1);  else _1= _send(s__2b, _1, _2);
  }
  v_n= _1;
 }
 _l5:;
  _1= v_n;
  _2= v_Character;
  _3= v_self;
  _4= l_8;
  _3= _send(s__5c_5c, _3, _4);
  _2=_send(s_digitValue_, _2, _3);
  _2=_send(s_put, _2);
  {
    int _l= (int)_1 >> 1;
    int _r= (int)_2 >> 1;
    int _s= _l + _r;
    if ((1 & (int)_1 & (int)_2) && ((_s ^ (_s << 1)) >= 0))  _1= (oop)(_s << 1 | 1);  else _1= _send(s__2b, _1, _2);
  }
  return _1;
 }
static oop Integer__printOn_radix_(oop v__closure, oop v_stateful_self, oop v_self, oop v_aStream, oop v_radix)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  /* ifTrue: */
  _1= 0;
  _2= v_self;
  _3= l_9;
  if (1 & (int)_2) {
    _2= (((int)_2 < (int)_3) ? v_true : v_false);
  } else _2= _send(s__3c, _2, _3);
  if (!_2) goto _l6;
 {
  _1= v_aStream;
  _2= l_10;
  _send(s_nextPut_, _1, _2);
  _2= v_self;
  _2=_send(s_negated, _2);
  _1=_send(s_print_, _1, _2);
  return _1;
 }
 _l6:;
  /* ifTrue: */
  _1= 0;
  _2= v_self;
  _3= v_radix;
  if (1 & (int)_2 & (int)_3) {
    _2= (((int)_2 >= (int)_3) ? v_true : v_false);
  } else _2= _send(s__3e_3d, _2, _3);
  if (!_2) goto _l7;
 {
  _1= v_self;
  _2= v_radix;
  _1= _send(s__2f_2f, _1, _2);
  _2= v_aStream;
  _3= v_radix;
  _1=_send(s_printOn_radix_, _1, _2, _3);
 }
 _l7:;
  _1= v_aStream;
  _2= v_Character;
  _3= v_self;
  _4= v_radix;
  _3= _send(s__5c_5c, _3, _4);
  _2=_send(s_digitValue_, _2, _3);
  _1=_send(s_nextPut_, _1, _2);
  _1= v_self;
  return _1;
 }
static oop Fraction__numerator_denominator_(oop v__closure, oop v_stateful_self, oop v_self, oop v_n, oop v_d)
 {
  oop _1= 0;
  oop _2= 0;
  _1= v_n;
  _1=_send(s_asFloat, _1);
  _2= v_d;
  _2=_send(s_asFloat, _2);
  _1=_send(s__2f, _1, _2);
  return _1;
 }
static oop Float__reduced(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_self;
  return _1;
 }

void __id__init__Integer(void)
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

  _send(s__5fimport_, _local_object, "Number", "__id__init__Number");
  _send(s__5fimport_, _local_object, "Magnitude", "__id__init__Magnitude");
  _send(s__5fimport_, _local_object, "Object", "__id__init__Object");
  _send(s__5fimport_, _local_object, "_object", "__id__init___5fobject");
  v__object= _id_import("_object");
  v_Object= _id_import("Object");
  v_UndefinedObject= _id_import("UndefinedObject");
  v_StaticBlockClosure= _id_import("StaticBlockClosure");
  v_Magnitude= _id_import("Magnitude");
  v_Character= _id_import("Character");
  v_Number= _id_import("Number");
  v_Fraction= _id_import("Fraction");
  v_Float= _id_import("Float");
  v_Integer= _id_import("Integer");
  v_SmallInteger= _id_import("SmallInteger");
  v_LargePositiveInteger= _id_import("LargePositiveInteger");
  v_Collection= _id_import("Collection");
  v_SequenceableCollection= _id_import("SequenceableCollection");
  v_ArrayedCollection= _id_import("ArrayedCollection");
  v_Array= _id_import("Array");
  v_WordArray= _id_import("WordArray");
  v_ByteArray= _id_import("ByteArray");
  v_String= _id_import("String");
  v_ImmutableString= _id_import("ImmutableString");
  v_Symbol= _id_import("Symbol");
  v_true= _id_import("true");
  v_false= _id_import("false");
  _send(s__5fimport_, _local_object, "BlockClosure", "__id__init__BlockClosure");
  _send(s__5fimport_, _local_object, "SmallInteger", "__id__init__SmallInteger");
  _send(s__5fimport_, _local_object, "Integer", "__id__init__Integer");
  _send(s__5fimport_, _local_object, "Array", "__id__init__Array");
  _send(s__5fimport_, _local_object, "ArrayedCollection", "__id__init__ArrayedCollection");
  _send(s__5fimport_, _local_object, "SequenceableCollection", "__id__init__SequenceableCollection");
  _send(s__5fimport_, _local_object, "Collection", "__id__init__Collection");
  _send(s__5fimport_, _local_object, "Character", "__id__init__Character");
  _send(s__5fimport_, _local_object, "String", "__id__init__String");
  _send(s__5fimport_, _local_object, "ByteArray", "__id__init__ByteArray");
  _send(s__5fimport_, _local_object, "WordArray", "__id__init__WordArray");
  _method(v_Object, s_isInteger, Object__isInteger);
  _method(v_Integer, s_isInteger, Integer__isInteger);
  _method(v_Integer, s_asInteger, Integer__asInteger);
  _method(v_Integer, s_normalize, Integer__normalize);
  l_1= _send(s_value_5f_, v_SmallInteger, 2);
  l_2= _send(s_value_5f_, v_SmallInteger, 0);
  l_3= _send(s_value_5f_, v_SmallInteger, 1);
  l_4= _send(s_size_5f_value_5f_, v_Symbol, 1, "/");
  _method(v_Integer, s__2f, Integer___2f);
  l_5= _send(s_value_5f_, v_SmallInteger, 0);
  l_6= _send(s_value_5f_, v_Character, 45);
  l_7= _send(s_value_5f_, v_SmallInteger, 1);
  l_8= _send(s_value_5f_, v_SmallInteger, 10);
  _method(v_Integer, s_print, Integer__print);
  l_9= _send(s_value_5f_, v_SmallInteger, 0);
  l_10= _send(s_value_5f_, v_Character, 45);
  _method(v_Integer, s_printOn_radix_, Integer__printOn_radix_);
  _method(v_Fraction, s_numerator_denominator_, Fraction__numerator_denominator_);
  _method(v_Float, s_reduced, Float__reduced);
}
