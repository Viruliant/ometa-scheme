/* generated by Id 1.0 at 2007-04-24 00:11:57 Z */
/* with the command: -I../stage1/ -I. -I../st80 -c SlotVariableNode.st -o ../stage2/SlotVariableNode.o.c */

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

static oop s_generate_location_= 0;
static oop s_type_receiver_= 0;
static oop s_withName_position_scope_= 0;
static oop s__5fdebugName= 0;
static oop s_new= 0;
static oop s__5fimport_= 0;
static oop s_isGlobal= 0;
static oop s_isFree= 0;
static oop s_freeWithin_= 0;
static oop s_loadSlot_type_location_= 0;
static oop s_generateStore_location_= 0;
static oop s_initialize= 0;
static oop s_storeSlot_type_location_= 0;
static oop s_generate_freeIn_location_= 0;
static oop s_loadFreeSlot_type_scope_outer_offset_location_= 0;
static oop s_scope= 0;
static oop s_tag= 0;
static oop s_name= 0;
static oop s__2d= 0;
static oop s_generateStore_freeIn_location_= 0;
static oop s_offset= 0;
static oop s_storeFreeSlot_type_scope_outer_offset_location_= 0;
static oop s__5fsizeof= 0;
static oop s_level= 0;
static struct _Selector { const char *name; oop *addr; } _Selectors[]= {
  { "generate:location:", &s_generate_location_ },
  { "type:receiver:", &s_type_receiver_ },
  { "withName:position:scope:", &s_withName_position_scope_ },
  { "_debugName", &s__5fdebugName },
  { "new", &s_new },
  { "_import:", &s__5fimport_ },
  { "isGlobal", &s_isGlobal },
  { "isFree", &s_isFree },
  { "freeWithin:", &s_freeWithin_ },
  { "loadSlot:type:location:", &s_loadSlot_type_location_ },
  { "generateStore:location:", &s_generateStore_location_ },
  { "initialize", &s_initialize },
  { "storeSlot:type:location:", &s_storeSlot_type_location_ },
  { "generate:freeIn:location:", &s_generate_freeIn_location_ },
  { "loadFreeSlot:type:scope:outer:offset:location:", &s_loadFreeSlot_type_scope_outer_offset_location_ },
  { "scope", &s_scope },
  { "tag", &s_tag },
  { "name", &s_name },
  { "-", &s__2d },
  { "generateStore:freeIn:location:", &s_generateStore_freeIn_location_ },
  { "offset", &s_offset },
  { "storeFreeSlot:type:scope:outer:offset:location:", &s_storeFreeSlot_type_scope_outer_offset_location_ },
  { "_sizeof", &s__5fsizeof },
  { "level", &s_level },
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
struct t_SlotVariableNode {
  struct _vtable *_vtable[0];
  oop v_name;
  oop v_position;
  oop v_scope;
  oop v_receiver;
  oop v_type;
};
static oop v__object= 0;
static oop v_Object= 0;
static oop v_UndefinedObject= 0;
static oop v_StaticBlockClosure= 0;
static oop v_Magnitude= 0;
static oop v_Number= 0;
static oop v_Integer= 0;
static oop v_LargePositiveInteger= 0;
static oop v_Collection= 0;
static oop v_SequenceableCollection= 0;
static oop v_ArrayedCollection= 0;
static oop v_Array= 0;
static oop v_WordArray= 0;
static oop v_ByteArray= 0;
static oop v_String= 0;
static oop v_ImmutableString= 0;
static oop v_nil= 0;
static oop v_false= 0;
static oop v_SlotVariableNode= 0;
static size_t SlotVariableNode___5fsizeof(oop _closure, oop v_self) { return sizeof(struct t_SlotVariableNode); }
static char *SlotVariableNode___5fdebugName(oop _closure, oop v_self) { return "SlotVariableNode"; }
static oop SlotVariableNode__initialize(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_self;
  _1=_super(v_Object, s_initialize, _1);
  _1= v_nil;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_type= _1;
  _1= v_self;
  return _1;
 }
static oop SlotVariableNode__withName_position_scope_(oop v__closure, oop v_stateful_self, oop v_self, oop v_nameString, oop v_scannerPosition, oop v_aScope)
 {
  oop _1= 0;
  _1= v_self;
  _1=_send(s_new, _1);
  v_self= _1;
  v_stateful_self= _1;
  _1= v_nameString;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_name= _1;
  _1= v_scannerPosition;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_position= _1;
  _1= v_aScope;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_scope= _1;
  _1= v_nil;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_receiver= _1;
  _1= v_nil;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_type= _1;
  _1= v_self;
  return _1;
 }
static oop SlotVariableNode__type_receiver_(oop v__closure, oop v_stateful_self, oop v_self, oop v_aType, oop v_selfNode)
 {
  oop _1= 0;
  _1= v_aType;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_type= _1;
  _1= v_selfNode;
  ((struct t_SlotVariableNode *)v_stateful_self)->v_receiver= _1;
  _1= v_self;
  return _1;
 }
static oop SlotVariableNode__name(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= ((struct t_SlotVariableNode *)v_stateful_self)->v_name;
  return _1;
 }
static oop SlotVariableNode__scope(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= ((struct t_SlotVariableNode *)v_stateful_self)->v_scope;
  return _1;
 }
static oop SlotVariableNode__isGlobal(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= v_false;
  return _1;
 }
static oop SlotVariableNode__isFree(oop v__closure, oop v_stateful_self, oop v_self)
 {
  oop _1= 0;
  _1= ((struct t_SlotVariableNode *)v_stateful_self)->v_receiver;
  _1=_send(s_isFree, _1);
  return _1;
 }
static oop SlotVariableNode__freeWithin_(oop v__closure, oop v_stateful_self, oop v_self, oop v_innerScope)
 {
  oop _1= 0;
  oop _2= 0;
  _1= ((struct t_SlotVariableNode *)v_stateful_self)->v_receiver;
  _2= v_innerScope;
  _1=_send(s_freeWithin_, _1, _2);
  _1= v_self;
  return _1;
 }
static oop SlotVariableNode__generate_location_(oop v__closure, oop v_stateful_self, oop v_self, oop v_gen, oop v_location)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  _1= v_gen;
  _2= v_self;
  _3= ((struct t_SlotVariableNode *)v_stateful_self)->v_type;
  _4= v_location;
  _1=_send(s_loadSlot_type_location_, _1, _2, _3, _4);
  return _1;
 }
static oop SlotVariableNode__generateStore_location_(oop v__closure, oop v_stateful_self, oop v_self, oop v_gen, oop v_location)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  _1= v_gen;
  _2= v_self;
  _3= ((struct t_SlotVariableNode *)v_stateful_self)->v_type;
  _4= v_location;
  _1=_send(s_storeSlot_type_location_, _1, _2, _3, _4);
  return _1;
 }
static oop SlotVariableNode__generate_freeIn_location_(oop v__closure, oop v_stateful_self, oop v_self, oop v_gen, oop v_innerLevel, oop v_location)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  oop _5= 0;
  oop _6= 0;
  oop _7= 0;
  _1= v_gen;
  _2= ((struct t_SlotVariableNode *)v_stateful_self)->v_name;
  _3= ((struct t_SlotVariableNode *)v_stateful_self)->v_type;
  _3=_send(s_name, _3);
  _4= ((struct t_SlotVariableNode *)v_stateful_self)->v_scope;
  _4=_send(s_tag, _4);
  _5= v_innerLevel;
  _6= ((struct t_SlotVariableNode *)v_stateful_self)->v_scope;
  _6=_send(s_level, _6);
  {
    int _l= (int)_5 >> 1;
    int _r= (int)_6 >> 1;
    int _s= (_l - _r);
    if ((1 & (int)_5 & (int)_6) && ((_s ^ (_s << 1)) >= 0))  _5= (oop)(_s << 1 | 1);  else _5= _send(s__2d, _5, _6);
  }
  _6= ((struct t_SlotVariableNode *)v_stateful_self)->v_receiver;
  _6=_send(s_offset, _6);
  _7= v_location;
  _1=_send(s_loadFreeSlot_type_scope_outer_offset_location_, _1, _2, _3, _4, _5, _6, _7);
  return _1;
 }
static oop SlotVariableNode__generateStore_freeIn_location_(oop v__closure, oop v_stateful_self, oop v_self, oop v_gen, oop v_innerLevel, oop v_location)
 {
  oop _1= 0;
  oop _2= 0;
  oop _3= 0;
  oop _4= 0;
  oop _5= 0;
  oop _6= 0;
  oop _7= 0;
  _1= v_gen;
  _2= ((struct t_SlotVariableNode *)v_stateful_self)->v_name;
  _3= ((struct t_SlotVariableNode *)v_stateful_self)->v_type;
  _3=_send(s_name, _3);
  _4= ((struct t_SlotVariableNode *)v_stateful_self)->v_scope;
  _4=_send(s_tag, _4);
  _5= v_innerLevel;
  _6= ((struct t_SlotVariableNode *)v_stateful_self)->v_scope;
  _6=_send(s_level, _6);
  {
    int _l= (int)_5 >> 1;
    int _r= (int)_6 >> 1;
    int _s= (_l - _r);
    if ((1 & (int)_5 & (int)_6) && ((_s ^ (_s << 1)) >= 0))  _5= (oop)(_s << 1 | 1);  else _5= _send(s__2d, _5, _6);
  }
  _6= ((struct t_SlotVariableNode *)v_stateful_self)->v_receiver;
  _6=_send(s_offset, _6);
  _7= v_location;
  _1=_send(s_storeFreeSlot_type_scope_outer_offset_location_, _1, _2, _3, _4, _5, _6, _7);
  return _1;
 }

void __id__init__SlotVariableNode(void)
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

  _send(s__5fimport_, _local_object, "Object", "__id__init__Object");
  _send(s__5fimport_, _local_object, "_object", "__id__init___5fobject");
  v__object= _id_import("_object");
  v_Object= _id_import("Object");
  v_UndefinedObject= _id_import("UndefinedObject");
  v_StaticBlockClosure= _id_import("StaticBlockClosure");
  v_Magnitude= _id_import("Magnitude");
  v_Number= _id_import("Number");
  v_Integer= _id_import("Integer");
  v_LargePositiveInteger= _id_import("LargePositiveInteger");
  v_Collection= _id_import("Collection");
  v_SequenceableCollection= _id_import("SequenceableCollection");
  v_ArrayedCollection= _id_import("ArrayedCollection");
  v_Array= _id_import("Array");
  v_WordArray= _id_import("WordArray");
  v_ByteArray= _id_import("ByteArray");
  v_String= _id_import("String");
  v_ImmutableString= _id_import("ImmutableString");
  v_nil= _id_import("nil");
  v_false= _id_import("false");
  _send(s__5fimport_, _local_object, "BlockClosure", "__id__init__BlockClosure");
  _send(s__5fimport_, _local_object, "SmallInteger", "__id__init__SmallInteger");
  _send(s__5fimport_, _local_object, "Integer", "__id__init__Integer");
  _send(s__5fimport_, _local_object, "Number", "__id__init__Number");
  _send(s__5fimport_, _local_object, "Magnitude", "__id__init__Magnitude");
  _send(s__5fimport_, _local_object, "Array", "__id__init__Array");
  _send(s__5fimport_, _local_object, "ArrayedCollection", "__id__init__ArrayedCollection");
  _send(s__5fimport_, _local_object, "SequenceableCollection", "__id__init__SequenceableCollection");
  _send(s__5fimport_, _local_object, "Collection", "__id__init__Collection");
  _send(s__5fimport_, _local_object, "Character", "__id__init__Character");
  _send(s__5fimport_, _local_object, "String", "__id__init__String");
  _send(s__5fimport_, _local_object, "ByteArray", "__id__init__ByteArray");
  _send(s__5fimport_, _local_object, "WordArray", "__id__init__WordArray");
  v_SlotVariableNode= _proto(v_Object);
  _method(v_SlotVariableNode, s__5fsizeof, SlotVariableNode___5fsizeof);
  _method(v_SlotVariableNode, s__5fdebugName, SlotVariableNode___5fdebugName);
  _id_export("SlotVariableNode", v_SlotVariableNode);
  _method(v_SlotVariableNode, s_initialize, SlotVariableNode__initialize);
  _method(v_SlotVariableNode, s_withName_position_scope_, SlotVariableNode__withName_position_scope_);
  _method(v_SlotVariableNode, s_type_receiver_, SlotVariableNode__type_receiver_);
  _method(v_SlotVariableNode, s_name, SlotVariableNode__name);
  _method(v_SlotVariableNode, s_scope, SlotVariableNode__scope);
  _method(v_SlotVariableNode, s_isGlobal, SlotVariableNode__isGlobal);
  _method(v_SlotVariableNode, s_isFree, SlotVariableNode__isFree);
  _method(v_SlotVariableNode, s_freeWithin_, SlotVariableNode__freeWithin_);
  _method(v_SlotVariableNode, s_generate_location_, SlotVariableNode__generate_location_);
  _method(v_SlotVariableNode, s_generateStore_location_, SlotVariableNode__generateStore_location_);
  _method(v_SlotVariableNode, s_generate_freeIn_location_, SlotVariableNode__generate_freeIn_location_);
  _method(v_SlotVariableNode, s_generateStore_freeIn_location_, SlotVariableNode__generateStore_freeIn_location_);
}
