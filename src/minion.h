#include "global.h"

//GREAT pathing alogtrim
V2 goNext(minion m){
   //if(m.pos.x==m.goal.x&&m.pos.y==m.goal.y){R m.pos;}
   I mapFill[WW*WH]; 
   FOR(WW*WH,{mapFill[i]=-1;});
   mapFill[(I)m.goal.x+(I)m.goal.y*WW]=1;
   FOR(WW*WH,{ 
      FORYX(WH,WW,{
         if(mapFill[(x)+y*WW]!=-1){continue;}
         if(map[(x)+y*WW].type!=NONE){continue;}

         if(x<WW-1)if(mapFill[(x+1)+y*WW]>mapFill[(x)+y*WW]){mapFill[(x)+y*WW]=mapFill[(x+1)+y*WW]+1;}
         if(x>0 )if(mapFill[(x-1)+y*WW]>mapFill[(x)+y*WW]){mapFill[(x)+y*WW]=mapFill[(x-1)+y*WW]+1;}

         if(y<WH-1)if(mapFill[(x)+(y+1)*WW]>mapFill[(x)+y*WW]){mapFill[(x)+y*WW]=mapFill[(x)+(y+1)*WW]+1;}
         if(y>0 )if(mapFill[(x)+(y-1)*WW]>mapFill[(x)+y*WW]){mapFill[(x)+y*WW]=mapFill[(x)+(y-1)*WW]+1;}
      });
      if(mapFill[(I)m.pos.x+(I)(m.pos.y)*WW]>0){BR;}
   });
   V2 rv = m.pos; 
   I dirs[4]={
      mapFill[(I)(m.pos.x-1)+(I)(m.pos.y)*WW],
      m.pos.x>0?mapFill[(I)(m.pos.x+1)+(I)(m.pos.y)*WW]:-1,     
      mapFill[(I)(m.pos.x)+(I)(m.pos.y+1)*WW],
      mapFill[(I)(m.pos.x)+(I)(m.pos.y-1)*WW]
   };
   FOR(4,{if(dirs[i]<0){dirs[i]=999999;}});
   I min= mapFill[(I)(m.pos.x)+(I)(m.pos.y)*WW];
   I d=-1;
   FOR(4,{
      if(dirs[i]<min){d=i;min= dirs[i];}
   })
   if(d==0){rv.x--;}
   if(d==1){rv.x++;}
   if(d==2){rv.y++;}
   if(d==3){rv.y--;}
   R rv;
}
