#include "enemy.h"
#include "global.h"

#define ENEMY_1_WIDTH 57
#define ENEMY_1_HEIGHT 43
#define ENEMY_2_WIDTH 42
#define ENEMY_2_HEIGHT 60
#define ENEMY_3_WIDTH 85
#define ENEMY_3_HEIGHT 130

Enemy::Enemy()
{
    dead = false;
}

Enemy::Enemy(enum enemyType t, int x, int y, int vx, int vy)
{
    dead = false;
    
    type = t;
    posX = x;
    posY = y;
    velX = vx;
    velY = vy;

    enemyRect.x = posX;
    enemyRect.y = posY;

    switch(type){
    case ENEMY_1:
        life = 10;
        enemyRect.w = ENEMY_1_WIDTH;
        enemyRect.h = ENEMY_1_HEIGHT;
        enemyLauncher.enable = false;
        break;
    case ENEMY_2:
        life = 20;
        enemyRect.w = ENEMY_2_WIDTH;
        enemyRect.h = ENEMY_2_HEIGHT;
        enemyLauncher.enable = true;
        enemyLauncher.setLauncher(ENEMY, posX + 16, posY + enemyRect.h, velX, velY, 100);
        break;
    case ENEMY_3:
        life = 100;
        enemyRect.w = ENEMY_3_WIDTH;
        enemyRect.h = ENEMY_3_HEIGHT;
        enemyLauncher.enable = true;
        enemyLauncher.setLauncher(ENEMY, posX + 35, posY + enemyRect.h, velX, velY, 20);
        break;
    }
}

void Enemy::setEnemy(enum enemyType t, int x, int y, int vx, int vy)
{
    type = t;
    posX = x;
    posY = y;
    velX = vx;
    velY = vy;

    enemyRect.x = posX;
    enemyRect.y = posY;

    switch(type){
    case ENEMY_1:
        life = 10;
        enemyRect.w = ENEMY_1_WIDTH;
        enemyRect.h = ENEMY_1_HEIGHT;
        enemyLauncher.enable = false;
        break;
    case ENEMY_2:
        life = 20;
        enemyRect.w = ENEMY_2_WIDTH;
        enemyRect.h = ENEMY_2_HEIGHT;
        enemyLauncher.enable = true;
        enemyLauncher.setLauncher(ENEMY, posX + 16, posY + enemyRect.h, velX, velY, 100);
        break;
    case ENEMY_3:
        life = 100;
        enemyRect.w = ENEMY_3_WIDTH;
        enemyRect.h = ENEMY_3_HEIGHT;
        enemyLauncher.enable = true;
        enemyLauncher.setLauncher(ENEMY, posX + 35, posY + enemyRect.h, velX, velY, 20);
        break;
    }
}

void Enemy::move()
{
    posX += velX;
    posY += velY;

    if(posX < 0 || posX > SCREEN_WIDTH)
        posX -= velX;
    if(posY < 0 || posY > SCREEN_HEIGHT)
        dead = true;

    enemyRect.x = posX;
    enemyRect.y = posY;

    switch(type){
    case ENEMY_2:
        enemyLauncher.move(posX + 16, posY + enemyRect.h);
        break;
    case ENEMY_3:
        enemyLauncher.move(posX + 35, posY + enemyRect.h);
        break;
    }
}

void Enemy::render()
{
    switch(type){
    case ENEMY_1:
        enemy1Texture.render(posX, posY);
        break;
    case ENEMY_2:
        enemy2Texture.render(posX, posY);
        break;
    case ENEMY_3:
        enemy3Texture.render(posX, posY);
        break;
    }

    enemyLauncher.render();
}
