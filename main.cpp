#include "raylib.h"
#include "raymath.h"

class character
{
  public:

  Vector2 GetWorldPos()
  {
    return worldPos;
  }

  private:
  Texture2D Texture;
  Texture2D idle;
  Vector2 screenPos;
  Vector2 worldPos;
  float rightLeft{1.f};
  float runningTime{};
  int frame{};
  const int maxFrames{6};
  const float updateTime{1.f/12.f};
  const float{1.f};

};

int main()
{
   const int width = 384;
   const int height = 384;

  InitWindow(width, height, "Pixel Clash");

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  Vector2 mapPos{0.0, 0.0};

  
  Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
  Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
  Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");


  float rightLeft{1.f};
  float runningTime{};
  int frame{};
  const int maxFrames{6};
  const float updateTime{1.f/12.f};


  Vector2 knightPos{
    (width/2.0)-(4*0.5*knight_idle.width/6.0),
    (height/2.0)-(4*0.5*knight_idle.height)
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
         direction.x < 0.f ? rightLeft = 1.f : rightLeft = 1.f;
           knight = knight_run;
        }
        else
        {
            knight = knight_idle;

        }

        

        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames) frame = 0;
        }


        Rectangle source{frame * (float)knight.width/6.f, 0.f, rightLeft * (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        
        DrawTexturePro(knight_idle, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
    CloseWindow();


}