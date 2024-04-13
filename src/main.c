#include "util/mutil.h"
#include <stdio.h>
#include "raylib.h"

TFS{
   Vector2 pos;
}bee;
   CI sw=550,sh=450,tfps=60;
   bee b;
V tick(){
   b.pos=GetMousePosition();
}
V render(){
      DrawCircle(b.pos.x, b.pos.y,10, DARKBLUE);
      DrawText("base window", (sw/2)-50, (sh-20)/2, 20, LIGHTGRAY);
}
V startGame(I dif){
   b.pos=(Vector2){50,50};
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
