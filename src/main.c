#include "util/mutil.h"
#include <stdio.h>
#include "raylib.h"
#include "raymath.h"


TFS{
   V2 pos;
}bee;
CI sw=550,sh=450,tfps=60;


ARR(bee , bb, 10);

bee b;

V tick(){
   if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
      AARR((bee){GetMousePosition()},bb); 
   }
   b.pos=GetMousePosition();
   FOR(bb_c,{
      if (Vector2Distance(bb[i].pos, (V2){(F)sw/2, (F)sh/2}) < .01) {
         RMARR(bb, i);BR;
      }
      if(bb[i].pos.x>(F)sw/2 )bb[i].pos.x-=1;
      if(bb[i].pos.x<(F)sw/2 )bb[i].pos.x+=1;
      if(bb[i].pos.y>(F)sh/2 )bb[i].pos.y-=1;
      if(bb[i].pos.y<(F)sh/2 )bb[i].pos.y+=1;
   });
}
V render(){
   FOR(bb_c,{
      DrawCircle(bb[i].pos.x, bb[i].pos.y,6, YELLOW);
   });
      DrawCircle(b.pos.x, b.pos.y,10, DARKBLUE);
      DrawText("base window", (sw/2)-50, (sh-20)/2, 20, LIGHTGRAY);
}
V startGame(I dif){
   IARR(bb);
   b.pos=(V2){50,50};
}
V init(){
   InitWindow(sw, sh, "ld55");
   SetTargetFPS(tfps);
}
V quit(){
   CloseWindow(); 
}
I main(){
   init(); 
   startGame(1);
   W(!WindowShouldClose()){
      tick();
      BeginDrawing();ClearBackground(BLACK);render();EndDrawing();
   }
   quit();
   R 0;
}
