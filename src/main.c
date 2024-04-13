#include "util/mutil.h"
#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
TFS{ V2 pos; V2 vel;}minion;
CI sw=550,sh=450,tfps=60;
TFS{
   REC r;
}block;
#define IF if
ARR(minion , bb, 10);
ARR(block, w, 10);
minion pl;
CF Scale =.1, G = 9.81/Scale;
V plT(){
   pl.vel.x = 0;
   pl.vel.y += G*GetFrameTime();
   IF(IsKeyDown(KEY_A)){pl.vel.x = -3;}
   IF(IsKeyDown(KEY_D)){pl.vel.x = 3;}

#define IN(x,l,h) ((l)<=(x)&&(x)<=(h))
   V2 npx=Vector2Add(pl.pos,(V2){pl.vel.x,0});
   V2 npy=Vector2Add(pl.pos,(V2){0,pl.vel.y});
   V2 npxy=Vector2Add(pl.pos,pl.vel);
   Rectangle prx = { npx.x , npx.y, 40, 40 };
   Rectangle pry = { npy.x , npy.y, 40, 40 };
   I COLX=0,COLY=0;
   FOR(w_c,{
      COLX+=CheckCollisionRecs(prx, w[i].r);
      COLY+=CheckCollisionRecs(pry, w[i].r);
   });
   if(COLX){pl.vel.x=0;}
   if(COLY){pl.vel.y=0;}
   pl.pos=Vector2Add(pl.pos, pl.vel);
}
V tick(){
   plT();
   if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
      PUSH((minion){GetMousePosition()},bb); 
   }
   FOR(bb_c,{
      if(Vector2Distance(bb[i].pos, (V2){(F)sw/2, (F)sh/2}) < .01){ POP(bb, i);BR; }
      if(bb[i].pos.x>(F)sw/2)bb[i].pos.x-=1;
      if(bb[i].pos.x<(F)sw/2)bb[i].pos.x+=1;
      if(bb[i].pos.y>(F)sh/2)bb[i].pos.y-=1;
      if(bb[i].pos.y<(F)sh/2)bb[i].pos.y+=1;
   });
}
V render(){
   FOR(bb_c,{ DrawCircle(bb[i].pos.x, bb[i].pos.y,6, YELLOW); });
   FOR(w_c,{ DrawRectangleRec(w[i].r , RAYWHITE);});
   Rectangle pr = { pl.pos.x , pl.pos.y, 40, 40 };
   DrawRectangleRec((pr), RED);
}

V startGame(I dif){
   IARR(bb); IARR(w);
   block b=(block){(REC){10,sh-50,sw-200,40}};
   PUSH(b,w);
   b=(block){(REC){10,100,5,sh}}; PUSH(b,w);
   pl=(minion){(V2){100,333}};
}
V clear(){
   FREEARR(bb);
   FREEARR(w);
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
