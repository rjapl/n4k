typedef int I;typedef long J;typedef double F;typedef const char*S;
typedef unsigned long K;

enum{KJ=8+6,KF=5*8+6};

#define R return
#define P(b,a...) if(b)R({a;});
#define N(n,a...) {I _n=(n),i=-1;while(++i<_n){a;}}
#define C(i,a...) case i:R({a;});
#define S(i,c,a...) switch(i){c default:R({a;});}

extern "C" K k(K,K);K kj(J j){R k('j',j);}K kf(F f){R k('f',*(J*)&f);}K ks(S s){R k('s',(K)s);}

#define tx (x>>56)
#define xs (S)(-1UL>>16&x)
#define xj *(J*)xs
#define xf *(F*)xs

#define xn ((I*)x)[-2]
#define Xx ((K*)x)[i]

#define EXP __attribute__ ((visibility("default")))
#define ERR(x) (16>(x))
