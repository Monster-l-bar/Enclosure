#include "global.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;

Mix_Music *music = NULL;
Mix_Chunk *heroBullet = NULL;
Mix_Chunk *bombBullet = NULL;
Mix_Chunk *enemyDead = NULL;
Mix_Chunk *getUfo = NULL;

Scheduler *scheduler = new Scheduler();

Texture mainTexture;

Texture heroTexture;

Texture enemy1Texture;

Texture enemy2Texture;

Texture enemy3Texture;

Texture heroBulletTexture;
Texture enemyBulletTexture;
Texture bombBulletTexture;
Texture ufo1Texture;
Texture ufo2Texture;
Texture pauseTexture;
Texture resumeTexture;
Texture scoreTexture;
Texture restartTexture;
Texture quitTexture;

bool isInRect(int x, int y, SDL_Rect rect)
{
    bool inside = true;
    if(x < rect.x)
        inside = false;
    else if(x > (rect.x + rect.w))
        inside = false;
    else if(y < rect.y)
        inside = false;
    else if(y > (rect.y + rect.h))
        inside = false;
    return inside;
}
