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
Camera cam3={0};
#define FS  10 
#define MTS 8
TFS {
   REC r;
   I active;
   V2 shape[MTS];
}box;
TFS {
   I Fill;
}build;
ARR(build, builds, FS*FS);
ARR(box, leftbar, 10);
    Vector3 g0 = (Vector3){ -5.0f, 0.0f, -5.0f };
    Vector3 g1 = (Vector3){ -5.0f, 0.0f,  5.0f };
    Vector3 g2 = (Vector3){  5.0f, 0.0f,  5.0f };
    Vector3 g3 = (Vector3){  5.0f, 0.0f, -5.0f };
V tick(){
}

      I sel=0;
RayCollision mpin3d;
V render(){
   V2 m = GetMousePosition();
   //BeginMode2D(camera);
   //
   FOR(leftbar_c,{DrawRectangleRec(leftbar[i].r,leftbar[i].active*CheckCollisionPointRec(m,leftbar[i].r)?BLUE:RED ); });
   Rectangle pr = { pl.pos.x*TS , pl.pos.y*TS, TS, TS };
   DrawRectangleRec((pr), RED);
   //EndMode2D();
   BeginMode3D(cam3);
   DrawGrid(10,1);
   Ray ray = GetScreenToWorldRay(GetMousePosition(), cam3);
   mpin3d = GetRayCollisionQuad(ray, g0, g1, g2, g3);
   FOR(builds_m, {if(builds[i].Fill==1){
      DrawCube((V3){(i%FS)+.5-FS/2,.5,(i/FS)+.5-FS/2}, .9, .5, .9, RED); }
   });
   if ((mpin3d.hit) ){
      I valid = 1;
         I i = (I)round(mpin3d.point.x-.5)+FS/2+((I)round(mpin3d.point.z-.5)+FS/2)*FS;
      FORX(MTS,{
         if(builds[i + (I)leftbar[sel].shape[x].x+FS*(I)leftbar[sel].shape[x].y ].Fill>0){valid=0;}
         if(i%FS + (I)leftbar[sel].shape[x].x<0){valid=0;}
         if(i%FS + (I)leftbar[sel].shape[x].x>=FS){valid=0;}
         if(i/FS + (I)leftbar[sel].shape[x].y<0){valid=0;}
         if(i/FS + (I)leftbar[sel].shape[x].y>=FS){valid=0;}
      })
      if(IsMouseButtonPressed(0)){
         if(valid){
      FORX(MTS,{
         builds[i + (I)leftbar[sel].shape[x].x+FS*(I)leftbar[sel].shape[x].y ].Fill=1;
      })
         
      }
      }
      F X=round(mpin3d.point.x-.5)+.5;
      F Z=round(mpin3d.point.z-.5)+.5 ;
      F Y=round(mpin3d.point.y);

      FORX(MTS,{
      DrawCube( (V3){X+(I)leftbar[sel].shape[x].x,Y,Z+(I)leftbar[sel].shape[x].y}, 0.3f, 0.3f, 0.3f,valid? GREEN:RED);
      });
        }
   EndMode3D();
if(IsKeyPressed(KEY_ONE)){sel=0;}
if(IsKeyPressed(KEY_ONE+1)){sel=1;}
if(IsKeyPressed(KEY_R)){

      FOR(MTS,{
         I t=leftbar[sel].shape[i].x;
         leftbar[sel].shape[i].x=-leftbar[sel].shape[i].y;
         leftbar[sel].shape[i].y=t;
      });
   }
}

V startGame(I dif){
   IARR(map);
   IARR(builds);
   IARR(leftbar);
   #define uwu (box){(REC){5, 5+i*55 , 200 , 50}, 1, (V2){ 0 }}
   FOR(10,{ PUSH(uwu,leftbar);leftbar[i].active++; }) ;
    cam3.position = (Vector3){ 0.0f, 10.0f, 10.0f }; // Camera position
    cam3.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    cam3.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    cam3.fovy = 45.0f;                                // Camera field-of-view Y
    cam3.projection = CAMERA_PERSPECTIVE;             // Camera projection type
   //
       Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };
    Vector3 cubeSize = { 2.0f, 2.0f, 2.0f };
   Ray ray = { 0 };                    // Picking line ray
    RayCollision collision = { 0 };     // Ray collision hit info
   //
   FOR(builds_m, {builds[i].Fill=0;});

   leftbar[0].shape[1]=(V2){1,0};
   leftbar[0].shape[3]=(V2){2,0};
   leftbar[0].shape[2]=(V2){0,1};

   leftbar[1].shape[2]=(V2){1,1};
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
   BeginDrawing();ClearBackground(RAYWHITE);render();EndDrawing();
}}

I main(){
   init(); 
   startGame(1);
   loop();
   quit();
   R 0;
}
