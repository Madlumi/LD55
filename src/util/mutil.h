#pragma once

typedef   int         I;
typedef   float       F;
typedef   double      D;
typedef   char        C;
typedef   void        V;


#define CON const
#define R return 

#define W(x) while((x))

#define FOR(n,x) {for(int i=0;i<n;++i){x;}}
#define FORX(n,a) {for(int x=0;x<n;++x){a;}}
#define FORY(n,a) {for(int y=0;y<n;++y){a;}}
#define FORYX(yN,xN,a) {for(int y=0;y<yN;++y){for(int x=0;x<xN;++x){a;}}}
#define FORIJ(iN,jN,a) {for(int i=0;i<iN;++i){for(int j=0;j<jN;++j){a;}}}

#define IN(x,l,h) ((l)<=(x)&&(x)<=(h))

