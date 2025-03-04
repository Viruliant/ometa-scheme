/* generated by Id 1.0 at 2007-04-24 00:11:19 Z */
/* with the command: -I../stage1/ -I. -c String.st -o ../stage2/String.o.c */

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

static oop s_new_= 0;
static oop s__3c_3d= 0;
static oop s_new_5f_= 0;
static oop s_byteAt_= 0;
static oop s_value_5f_= 0;
static oop s_species= 0;
static oop s__5fimport_= 0;
static oop s_ifFalse_= 0;
static oop s__5fbytes= 0;
static oop s_collect_= 0;
static oop s_to_do_= 0;
static oop s_size= 0;
static oop s__3d_3d= 0;
static oop s__5fclone= 0;
static oop s_min_= 0;
static oop s_isString= 0;
static oop s__3d= 0;
static oop s_asUppercase= 0;
static oop s_function_5f_arity_5f_= 0;
static oop s_asLowercase= 0;
static oop s__5fstringValue= 0;
static oop s__3c= 0;
static oop s_strncmp_5f__5f__5f_= 0;
static oop s__5fintegerValue= 0;
static oop s_and_= 0;
static oop s__3e= 0;
static oop s_asByteArray= 0;
static oop s_function_5f_arity_5f_outer_state_nlr_5f_= 0;
static oop s_errorImmutable= 0;
static oop s_or_= 0;
static oop s_writeStream= 0;
static oop s_value_= 0;
static oop s__3e_3d= 0;
static oop s_at_= 0;
static oop s_copyFrom_to_= 0;
static oop s_asciiValue= 0;
static oop s_at_put_= 0;
static struct _Selector { const char *name; oop *addr; } _Selectors[]= {
  { "new:", &s_new_ },
  { "<=", &s__3c_3d },
  { "new_:", &s_new_5f_ },
  { "byteAt:", &s_byteAt_ },
  { "value_:", &s_value_5f_ },
  { "species", &s_species },
  { "_import:", &s__5fimport_ },
  { "ifFalse:", &s_ifFalse_ },
  { "_bytes", &s__5fbytes },
  { "collect:", &s_collect_ },
  { "to:do:", &s_to_do_ },
  { "size", &s_size },
  { "==", &s__3d_3d },
  { "_clone", &s__5fclone },
  { "min:", &s_min_ },
  { "isString", &s_isString },
  { "=", &s__3d },
  { "asUppercase", &s_asUppercase },
  { "function_:arity_:", &s_function_5f_arity_5f_ },
  { "asLowercase", &s_asLowercase },
  { "_stringValue", &s__5fstringValue },
  { "<", &s__3c },
  { "strncmp_:_:_:", &s_strncmp_5f__5f__5f_ },
  { "_integerValue", &s__5fintegerValue },
  { "and:", &s_and_ },
  { ">", &s__3e },
  { "asByteArray", &s_asByteArray },
  { "function_:arity_:outer:state:nlr_:", &s_function_5f_arity_5f_outer_state_nlr_5f_ },
  { "errorImmutable", &s_errorImmutable },
  { "or:", &s_or_ },
  { "writeStream", &s_writeStream },
  { "value:", &s_value_ },
  { ">=", &s__3e_3d },
  { "at:", &s_at_ },
  { "copyFrom:to:", &s_copyFrom_to_ },
  { "asciiValue", &s_asciiValue },
  { "at:put:", &s_at_put_ },
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
static oop l_8= 0;
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
static oop v_WordArray= 0;
static oop v_ByteArray= 0;
static oop v_String= 0;
static oop v_ImmutableString= 0;
static oop v_true= 0;
static oop v_false= 0;
static oop String__species(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_String;
  return _1;
 }
static oop String__at_(oop v__closure, oop v_stateful_self, oop v_self, oop v_anInteger)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_Character;
  _2= v_self;
  _3= v_anInteger;
  _2=_super(v_ByteArray, s_at_, _2, _3);
  _1=_send(s_value_, _1, _2);
  return _1;
 }
static oop String__at_put_(oop v__closure, oop v_stateful_self, oop v_self, oop v_anInteger, oop v_aChar)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_self;
  _2= v_anInteger;
  _3= v_aChar;
  _3=_send(s_asciiValue, _3);
  _1=_super(v_ByteArray, s_at_put_, _1, _2, _3);
  _1= v_aChar;
  return _1;
 }
static oop b_1(oop v__closure, oop v__self, oop v_char)
 {
  oop _1= 0;
  _1= v_char;
  _1=_send(s_asUppercase, _1);
  return _1;
 }
static oop String__asUppercase(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  _1= v_self;
  _2= l_1;
  _1=_send(s_collect_, _1, _2);
  return _1;
 }
static oop b_2(oop v__closure, oop v__self, oop v_char)
 {
  oop _1= 0;
  _1= v_char;
  _1=_send(s_asLowercase, _1);
  return _1;
 }
static oop String__asLowercase(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  _1= v_self;
  _2= l_2;
  _1=_send(s_collect_, _1, _2);
  return _1;
 }
static oop String___5fstringValue(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop v__string= 0;
  oop _1= 0;
  (void)v__string;
 {
# define self ((struct t_String *)v_self)

      int len= (int)(self->v_size) >> 1;
      v__string= _balloc(len + 1);
      memcpy(v__string, self->v__bytes, len);
      ((char *)v__string)[len]= '\0';
    
# undef self
 }
  _1= 0;
  _1= v__string;
  return _1;
 }
static oop String__value_5f_(oop v__closure, oop v_stateful_self, oop v_self, oop v__cString)
 {
  oop _1= 0;
  _1= v_self;
  _1=_send(s__5fclone, _1);
  v_self= _1;
  v_stateful_self= _1;
 {
# define self ((struct t_String *)v_self)

      int len= strlen((char *)v__cString);
      self->v_size= (oop)((len << 1) | 1);
      self->v__bytes= _balloc(len);
      memcpy(self->v__bytes, v__cString, len);
    
# undef self
 }
  _1= 0;
  _1= v_self;
  return _1;
 }
static oop Object__isString(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_false;
  return _1;
 }
static oop String__isString(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_true;
  return _1;
 }
static oop String___3c(oop v__closure, oop v_stateful_self, oop v_self, oop v_aString)
 {
  oop v_cmp= 0;
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  oop _5= 0;
  (void)v_cmp;
  /* ifFalse: */
  _1= 0;
  _2= v_aString;
  _2=_send(s_isString, _2);
  if (_2) goto _l1;
 {
  _1= v_false;
  return _1;
 }
 _l1:;
  _1= v_self;
  _2= ((struct t_String *)v_stateful_self)->v__bytes;
  _3= v_aString;
  _3=_send(s__5fbytes, _3);
  _4= v_self;
  _4=_send(s_size, _4);
  _5= v_aString;
  _5=_send(s_size, _5);
  _4=_send(s_min_, _4, _5);
  _4=_send(s__5fintegerValue, _4);
  _1=_send(s_strncmp_5f__5f__5f_, _1, _2, _3, _4);
  v_cmp= _1;
  /* or: */
  _1= v_cmp;
  _2= l_3;
  if (1 & (int)_1) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
  if (_1) goto _l2;
 {
  /* and: */
  _1= v_cmp;
  _2= l_3;
  _1= (_1 == _2) ? v_true : v_false;
  if (!_1) goto _l3;
 {
  _1= v_self;
  _1=_send(s_size, _1);
  _2= v_aString;
  _2=_send(s_size, _2);
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
 }
 _l3:;
 }
 _l2:;
  return _1;
 }
static oop String___3d(oop v__closure, oop v_stateful_self, oop v_self, oop v_aString)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  oop _5= 0;
  /* ifFalse: */
  _1= 0;
  /* and: */
  _2= v_aString;
  _2=_send(s_isString, _2);
  if (!_2) goto _l5;
 {
  _2= v_self;
  _2=_send(s_size, _2);
  _3= v_aString;
  _3=_send(s_size, _3);
  _2= (_2 == _3) ? v_true : v_false;
 }
 _l5:;
  if (_2) goto _l4;
 {
  _1= v_false;
  return _1;
 }
 _l4:;
  _1= l_4;
  _2= v_self;
  _3= ((struct t_String *)v_stateful_self)->v__bytes;
  _4= v_aString;
  _4=_send(s__5fbytes, _4);
  _5= v_self;
  _5=_send(s_size, _5);
  _5=_send(s__5fintegerValue, _5);
  _2=_send(s_strncmp_5f__5f__5f_, _2, _3, _4, _5);
  _1= (_1 == _2) ? v_true : v_false;
  return _1;
 }
static oop String___3e(oop v__closure, oop v_stateful_self, oop v_self, oop v_aString)
 {
  oop v_cmp= 0;
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  oop _5= 0;
  (void)v_cmp;
  /* ifFalse: */
  _1= 0;
  _2= v_aString;
  _2=_send(s_isString, _2);
  if (_2) goto _l6;
 {
  _1= v_false;
  return _1;
 }
 _l6:;
  _1= v_self;
  _2= ((struct t_String *)v_stateful_self)->v__bytes;
  _3= v_aString;
  _3=_send(s__5fbytes, _3);
  _4= v_self;
  _4=_send(s_size, _4);
  _5= v_aString;
  _5=_send(s_size, _5);
  _4=_send(s_min_, _4, _5);
  _4=_send(s__5fintegerValue, _4);
  _1=_send(s_strncmp_5f__5f__5f_, _1, _2, _3, _4);
  v_cmp= _1;
  /* or: */
  _1= v_cmp;
  _2= l_5;
  if (1 & (int)_1) {
    _1= (((int)_1 > (int)_2) ? v_true : v_false);
  } else _1= _send(s__3e, _1, _2);
  if (_1) goto _l7;
 {
  /* and: */
  _1= v_cmp;
  _2= l_5;
  _1= (_1 == _2) ? v_true : v_false;
  if (!_1) goto _l8;
 {
  _1= v_self;
  _1=_send(s_size, _1);
  _2= v_aString;
  _2=_send(s_size, _2);
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 > (int)_2) ? v_true : v_false);
  } else _1= _send(s__3e, _1, _2);
 }
 _l8:;
 }
 _l7:;
  return _1;
 }
static oop String___3c_3d(oop v__closure, oop v_stateful_self, oop v_self, oop v_aString)
 {
  oop _1= 0;
  oop _2= 0;
  /* or: */
  _1= v_self;
  _2= v_aString;
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 == (int)_2) ? v_true : v_false);
  } else _1= _send(s__3d, _1, _2);
  if (_1) goto _l9;
 {
  _1= v_self;
  _2= v_aString;
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 < (int)_2) ? v_true : v_false);
  } else _1= _send(s__3c, _1, _2);
 }
 _l9:;
  return _1;
 }
static oop String___3e_3d(oop v__closure, oop v_stateful_self, oop v_self, oop v_aString)
 {
  oop _1= 0;
  oop _2= 0;
  /* or: */
  _1= v_self;
  _2= v_aString;
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 == (int)_2) ? v_true : v_false);
  } else _1= _send(s__3d, _1, _2);
  if (_1) goto _l10;
 {
  _1= v_self;
  _2= v_aString;
  if (1 & (int)_1 & (int)_2) {
    _1= (((int)_1 > (int)_2) ? v_true : v_false);
  } else _1= _send(s__3e, _1, _2);
 }
 _l10:;
  return _1;
 }
static oop String__strncmp_5f__5f__5f_(oop v__closure, oop v_stateful_self, oop v_self, oop v__s1, oop v__s2, oop v__length)
 {
  oop _1= 0;
 {
# define self ((struct t_String *)v_self)
 return (oop)(strncmp((char *)v__s1, (char *)v__s2, (int)v__length) << 1 | 1); 
# undef self
 }
  _1= 0;
  _1= v_self;
  return _1;
 }
static oop b_7(oop v__closure, oop v__self, oop v_index)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  _1= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[1];  /* byteArray */
  _2= v_index;
  _3= ((oop *)((struct t_BlockClosure *)((struct t_BlockClosure *)v__self)->v_state))[2];  /* self */
  _4= v_index;
  _3=_send(s_byteAt_, _3, _4);
  _1=_send(s_at_put_, _1, _2, _3);
  return _1;
 }
static oop String__asByteArray(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _state1= _send(s_new_5f_, v__vector, 6);
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  ((oop *)_state1)[3]= v_stateful_self;
  ((oop *)_state1)[2]= v_self;
  _1= v_ByteArray;
  _2= ((oop *)_state1)[2];  /* self */
  _2=_send(s_size, _2);
  _1=_send(s_new_, _1, _2);
  ((oop *)_state1)[1]= _1;  /* byteArray */
  _1= l_6;
  _2= ((oop *)_state1)[2];  /* self */
  _2=_send(s_size, _2);
  /* Scope('index'->ArgumentVariableNode) */
  /* Scope('size'->SlotVariableNode 'self'->ArgumentVariableNode '_bytes'->SlotVariableNode 'stateful_self'->ArgumentVariableNode 'byteArray'->TemporaryVariableNode) */
  /* nil */
  /* 2 */
  /* 1 */
  _3= _send(s_function_5f_arity_5f_outer_state_nlr_5f_, v_BlockClosure, (oop)b_7, 1, 0, ((oop *)_state1), 0);
  _1=_send(s_to_do_, _1, _2, _3);
  _1= ((oop *)_state1)[1];  /* byteArray */
  return _1;
 }
static oop ImmutableString__at_put_(oop v__closure, oop v_stateful_self, oop v_self, oop v_anInteger, oop v_aChar)
 {
  oop _1= 0;
  _1= v_self;
  _1=_send(s_errorImmutable, _1);
  return _1;
 }
static oop ImmutableString__value_5f_(oop v__closure, oop v_stateful_self, oop v_self, oop v__cString)
 {
  oop _1= 0;
  _1= v_self;
  _1=_send(s__5fclone, _1);
  v_self= _1;
  v_stateful_self= _1;
 {
# define self ((struct t_ImmutableString *)v_self)

      self->v_size= (oop)((strlen((char *)v__cString) << 1) | 1);
      self->v__bytes= v__cString;
    
# undef self
 }
  _1= 0;
  _1= v_self;
  return _1;
 }
static oop ImmutableString__writeStream(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  _1= v_String;
  _2= ((struct t_ImmutableString *)v_stateful_self)->v_size;
  _1=_send(s_new_, _1, _2);
  _2= l_8;
  _3= ((struct t_ImmutableString *)v_stateful_self)->v_size;
  _1=_send(s_copyFrom_to_, _1, _2, _3);
  _1=_send(s_writeStream, _1);
  return _1;
 }

void __id__init__String(void)
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

  _send(s__5fimport_, _local_object, "ByteArray", "__id__init__ByteArray");
  _send(s__5fimport_, _local_object, "ArrayedCollection", "__id__init__ArrayedCollection");
  _send(s__5fimport_, _local_object, "SequenceableCollection", "__id__init__SequenceableCollection");
  _send(s__5fimport_, _local_object, "Collection", "__id__init__Collection");
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
  _send(s__5fimport_, _local_object, "Magnitude", "__id__init__Magnitude");
  _send(s__5fimport_, _local_object, "Array", "__id__init__Array");
  _send(s__5fimport_, _local_object, "Character", "__id__init__Character");
  _send(s__5fimport_, _local_object, "String", "__id__init__String");
  _send(s__5fimport_, _local_object, "WordArray", "__id__init__WordArray");
  _method(v_String, s_species, String__species);
  _method(v_String, s_at_, String__at_);
  _method(v_String, s_at_put_, String__at_put_);
  l_1= _send(s_function_5f_arity_5f_, v_StaticBlockClosure, b_1, 1);
  _method(v_String, s_asUppercase, String__asUppercase);
  l_2= _send(s_function_5f_arity_5f_, v_StaticBlockClosure, b_2, 1);
  _method(v_String, s_asLowercase, String__asLowercase);
  _method(v_String, s__5fstringValue, String___5fstringValue);
  _method(v_String, s_value_5f_, String__value_5f_);
  _method(v_Object, s_isString, Object__isString);
  _method(v_String, s_isString, String__isString);
  l_3= _send(s_value_5f_, v_SmallInteger, 0);
  _method(v_String, s__3c, String___3c);
  l_4= _send(s_value_5f_, v_SmallInteger, 0);
  _method(v_String, s__3d, String___3d);
  l_5= _send(s_value_5f_, v_SmallInteger, 0);
  _method(v_String, s__3e, String___3e);
  _method(v_String, s__3c_3d, String___3c_3d);
  _method(v_String, s__3e_3d, String___3e_3d);
  _method(v_String, s_strncmp_5f__5f__5f_, String__strncmp_5f__5f__5f_);
  l_6= _send(s_value_5f_, v_SmallInteger, 1);
  _method(v_String, s_asByteArray, String__asByteArray);
  _method(v_ImmutableString, s_at_put_, ImmutableString__at_put_);
  _method(v_ImmutableString, s_value_5f_, ImmutableString__value_5f_);
  l_8= _send(s_value_5f_, v_SmallInteger, 1);
  _method(v_ImmutableString, s_writeStream, ImmutableString__writeStream);
}
