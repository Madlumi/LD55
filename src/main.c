#include "util/mutil.h"
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"
#include "global.h"
#include "minion.h"
//948x533
CI sw=948,sh=533,tfps=60;
F camx, camy;
minion pl;
Camera2D camera={0};
CF Scale =.1, G = 9.81/Scale;
V plT(){
   pl.pos=goNext(pl); 
}

V tick(){
   plT();
   camera.target = (Vector2){ pl.pos.x*TS + 20.0f, pl.pos.y*TS + 20.0f };
}
V render(){
   BeginMode2D(camera);
   FOR(map_m,{if(map[i].type==BLOCK){ DrawRectangleRec((REC){ i%WW*TS,i/WW*TS,TS,TS} , RAYWHITE);}});
   Rectangle pr = { pl.pos.x*TS , pl.pos.y*TS, TS, TS };
   DrawRectangleRec((pr), RED);
   EndMode2D();

}

V startGame(I dif){
   IARR(map);
   FOR(map_m,{ 
      if(rand()%7==1){
         map[i].type=BLOCK;}else{
         map[i].type=NONE;
      }
   });

   camera.target = (Vector2){ pl.pos.x + 20.0f, pl.pos.y + 20.0f };
   camera.offset = (Vector2){ sw/2.0f, sh/2.0f };
   camera.rotation = 0.0f;
   camera.zoom = .5f;

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
