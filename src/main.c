#include "util/mutil.h"
#include <stdio.h>
#include "raylib.h"

I main(){
   CI sw=550,sh=450,tfps=60;
   InitWindow(sw, sh, "ld55");
   SetTargetFPS(tfps);
   W(!WindowShouldClose()){
      BeginDrawing();
      ClearBackground(BLACK);
      DrawText("base window", (sw/2)-50, (sh-20)/2, 20, LIGHTGRAY);
      EndDrawing();
   }
   CloseWindow(); 
   R 0;
}
