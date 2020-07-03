#include "napi.h"
#include"k.h"

#define EE(s) {TypeError::New(e, s).ThrowAsJavaScriptException(); R e.Null();}

using namespace Napi;

static inline I ii(Value v){F d=v.As<Number>().DoubleValue(); R (I)d==d;}
Value oi(Value v, I i){Array a=v.As<Array>(); R a[i];}I to(Value v){if(v.IsNumber()){P(ii(v), 'j'); R 'f';} P(v.IsArray(), ' ') R 0;}
K ko(Value v){S(to(v),C(0,0)C('j',kj(v.As<Number>().Int64Value()))C('f',kf(v.As<Number>().DoubleValue())),K x=k(' ',v.As<Array>().Length());N(xn, Xx=ko(oi(v,i));P(!Xx,0))x)}
Value ok(Env e, K x){S(tx,C(KJ,Number::New(e, (F)xj))C(KF,Number::New(e, xf)),Array v=Array::New(e, xn);N(xn,v[i]=ok(e, Xx))v)}
Value _(const CallbackInfo& i){
  Env e=i.Env(); if(i.Length()!=2) EE("format: k(function name, args array)"); if(!i[0].IsString()||!i[1].IsObject()) EE("Wrong args"); Value v;
  S cf=i[0].ToString().Utf8Value().c_str(); K x=ko(i[1]);R!x||ERR(x=k((K)cf,x))?TypeError::New(e, "ex").ThrowAsJavaScriptException(), e.Null():(v=ok(e, x),k(0,x),v);
}
Object Init(Env e, Object exp){exp.Set(String::New(e, "k"), Function::New(e, _)); R exp;}
NODE_API_MODULE(k, Init);
