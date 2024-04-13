#include "util/mutil.h"
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"
#include "global.h"
#include "minion.h"
#define elif else if
CI sw=948,sh=533,tfps=60;
F camx, camy;
minion pl;
Camera2D camera={0};
CF Scale =.1, G = 9.81/Scale;

V plT(){
   if(Vector2Distance(pl.pos,pl.next)<pl.ms){
      pl.pos=pl.next;
      pl.next=pl.pos;
      if (IsKeyDown(KEY_D)){pl.next.x++;}
      if (IsKeyDown(KEY_A)){pl.next.x--;}
      if (IsKeyDown(KEY_S)){pl.next.y++;}
      if (IsKeyDown(KEY_W)){pl.next.y--;}
      // pl.pos=pl.next; pl.next=goNext(pl); 
   }
   else if(Vector2Distance(pl.pos,pl.next)>2){ pl.next=pl.pos; }

   if(pl.pos.x<pl.next.x){pl.pos.x+=pl.ms;}
   if(pl.pos.x>pl.next.x){pl.pos.x-=pl.ms;}
   if(pl.pos.y<pl.next.y){pl.pos.y+=pl.ms;}
   if(pl.pos.y>pl.next.y){pl.pos.y-=pl.ms;}
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
   camera.zoom = 1.f;

   pl=(minion){(V2){(I)(WW/2),WH-2},(V2){(I)(WW/2),1}};
   pl.ms=.1;
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
