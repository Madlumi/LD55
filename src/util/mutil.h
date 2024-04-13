#pragma once
#include <stdio.h>
#include <stdlib.h>

//--Raylib--------------
#include <raylib.h>
typedef Rectangle REC ;
typedef Vector2 V2;
typedef Vector3 V3;

//----------------------
//--useful typedefs-----
typedef   int         I;
typedef   float       F;
typedef   double      D;
typedef   char        C;
typedef   void        V;

typedef const  int         CI;
typedef const  float       CF;
typedef const  double      CD;
typedef const  char        CC;
typedef const  void        CV;

#define TFS typedef struct
#define BR break

#define CON const
#define R return 
#define W(x) while((x))
//----------------------
//--loopy---------------
#define FOR(n,x) {for(int i=0;i<n;++i){x;}}
#define FORX(n,a) {for(int x=0;x<n;++x){a;}}
#define FORY(n,a) {for(int y=0;y<n;++y){a;}}
#define FORYX(yN,xN,a) {for(int y=0;y<yN;++y){for(int x=0;x<xN;++x){a;}}}
#define FORIJ(iN,jN,a) {for(int i=0;i<iN;++i){for(int j=0;j<jN;++j){a;}}}
//----------------------
//--Arrays--------------
#define ARR(type,name,n) type *name; I name##_m=n; I name##_c=0;
#define IARR(name) \
    name = (typeof(name))malloc(name##_m * sizeof(*(name))); \
    if (name == NULL) { fprintf(stderr, "Memory allocation failed for %s\n", #name); exit(1); }

#define PUSH(elem, arr) if(arr##_c >= arr##_m){\
   arr##_m *= 2; arr = (typeof(arr))realloc(arr, arr##_m *sizeof(*(arr))); \
   if (arr== NULL) { fprintf(stderr, "Memory reallocation failed for %s\n", #arr); exit(1); } \
}else{ arr[arr##_c]=elem; arr##_c++;};

#define POP(arr, index) if(index >= 0 && index < arr##_c) { \
        for (int i = index; i < arr##_c - 1; i++) { arr[i] = arr[i + 1]; } arr##_c--; }

#define FREEARR(arr) free(arr)
//----------------------
//--misc----------------
#define IN(x,l,h) ((l)<=(x)&&(x)<=(h))
//----------------------
