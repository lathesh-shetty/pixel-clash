#include "raylib.h"
#include "raymath.h"

int main()
{
   const int width = 384;
   const int height = 384;

  InitWindow(width, height, "Pixel Clash");

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos{0.0, 0.0};

  Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
  Vector2 knightPos{
    width/2-(4*0.5*knight.width/6.0),
    height/2-(4*0.5*knight.height)
  };

  SetTargetFPS(60);

  float speed = 4.0;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;

        if(Vector2Length(direction) != 0.0)
        {
          mapPos = Vector2Subtract(mapPos,Vector2Scale(Vector2Normalize(direction),speed)); 
        }

        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};

        
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    CloseWindow();


}