//#include"/home/clei/tools/py382/include/python3.8/Python.h"
#include <stdio.h>
#include <assert.h>
#include "node_api.h"

#include"k.h"

typedef napi_value O;
/*O oi(O o,I i){R PyTuple_GetItem(o,i);}I to(O o){S s="iftl",t=strchr(s,*(S)o->ob_type->tp_name);R t?"jf  "[t-s]:0;}

K ko(O o){S(to(o),C(0,0)C('j',kj(PyLong_AsLong(o)))C('f',kf(PyFloat_AsDouble(o))),K x=k(' ',PyObject_Length(o));N(xn,Xx=ko(oi(o,i));P(!Xx,0))x)}

O ok(K x){S(tx,C(KJ,PyLong_FromLong(xj))C(KF,PyFloat_FromDouble(xf)),O o=PyTuple_New(xn);N(xn,PyTuple_SetItem(o,i,ok(Xx)))o)}

O _(O n,O o){S s=PyUnicode_AsUTF8(oi(o,0));K x=ko(oi(o,1));R!x||ERR(x=k((K)s,x))?PyErr_SetString(PyExc_TypeError,""),NULL:(o=ok(x),k(0,x),o);}

PyMethodDef M[]={{"k",_,METH_VARARGS,""},{}};struct PyModuleDef m={PyModuleDef_HEAD_INIT,"k","",-1,M};EXP PyMODINIT_FUNC PyInit_k(){R PyModule_Create(&m);}
*/
O _(napi_env e, napi_callback_info i){
  napi_status status;
  size_t argc=0; O args[2];
  status=napi_get_cb_info(e, i, &argc, args, nullptr, nullptr); assert(status==napi_ok);
  if(argc!=2){
    napi_throw_type_error(e, nullptr, "function_name args");
    return nullptr;
  }
  napi_valuetype vtf; status=napi_typeof(e, args[0], &vtf); assert(status == napi_ok);
  fprintf(stderr, "argc: %ld, vtf: %d\n", argc, vtf);
  napi_valuetype vta; status=napi_typeof(e, args[1], &vta); assert(status == napi_ok);
  fprintf(stderr, "argc: %ld, vta: %d\n", argc, vta);
  if(vtf!=napi_string||vta!=napi_object){
    napi_throw_type_error(e, nullptr, "Wrong arguments");
    return nullptr;
  }
  char f[16]; size_t len=0; status=napi_get_value_string_utf8(e, args[0], NULL, sizeof f-1, &len); assert(status == napi_ok);
  fprintf(stderr, "len: %ld\n", len);
  //char f[16]; size_t len=0; status=napi_get_value_string_utf8(e, args[0], f, sizeof f-1, &len); assert(status == napi_ok);
  f[len]='\0'; printf("f:%s\n", f);
  O r; status=napi_create_string_utf8(e, f, len, &r); assert(status == napi_ok);
  R r;
}

O Init(napi_env env, O exports) {
  napi_status status;
  napi_property_descriptor addDescriptor = {"k", 0, _, 0, 0, 0, napi_default, 0 };
  status = napi_define_properties(env, exports, 1, &addDescriptor); assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);
