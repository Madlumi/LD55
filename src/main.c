#include "util/mutil.h"
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"
#include "global.h"
#include "minion.h"
CI sw=550,sh=450,tfps=60;
minion pl;
CF Scale =.1, G = 9.81/Scale;

V plT(){
   pl.pos=goNext(pl); 
}
V tick(){
   plT();
}
V render(){
   FOR(map_m,{if(map[i].type==BLOCK){ DrawRectangleRec((REC){ i%WW*TS,i/WW*TS,TS,TS} , RAYWHITE);}});
   Rectangle pr = { pl.pos.x*TS , pl.pos.y*TS, TS, TS };
   DrawRectangleRec((pr), RED);
}

V startGame(I dif){
   IARR(map);
   FOR(map_m,{ 
      if(rand()%7==1){
         map[i].type=BLOCK;}else{
         map[i].type=NONE;
      }
   });
   pl=(minion){(V2){5,5},(V2){100,100}};
}
V clear(){
   FREEARR(map);
}
V init(){
   InitWindow(sw, sh, "ld55");
   SetTargetFPS(tfps);
}
V quit(){clear();CloseWindow(); }
V loop(){W(!WindowShouldClose()){
   tick();
   BeginDrawing();ClearBackground(BLACK);render();EndDrawing();
}}

I main(){
   init(); 
   startGame(1);
   loop();
   quit();
   R 0;
}
