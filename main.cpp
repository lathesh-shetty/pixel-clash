#include "raylib.h"
#include "raymath.h"
#include "character.h"

int main()
{
  const int width = 384;
  const int height = 384;

  InitWindow(width, height, "Pixel Clash");

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos{0.0, 0.0};

  SetTargetFPS(60);

  character knight;
  knight.setScreenPos(width, height);

  float speed = 4.0;
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(knight.GetWorldPos(), -1.f);
    DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
    knight.tick(GetFrameTime());

    EndDrawing();
  }
  CloseWindow();
}