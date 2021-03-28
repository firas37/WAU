#include "enemie.h"
#include "outils.h"

void initEnnemi(Ennemi* e)
{
    Uint16 width, height;
    e->image = chargerImage("ressources/ENEMIE.png");
    width = e->image->w / 10; 
    height = e->image->h / 3; 

    e->animFrame = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
    e->pos = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
    e->direction = 0;
    e->etat = 0;
    e->collision = 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface* fenetre)
{
    SDL_FillRect(fenetre, &e.pos, SDL_MapRGB(e.image->format, 0, 0, 0));
   
    SDL_BlitSurface(e.image, &(e.animFrame), fenetre, &e.pos);
}

void animerEnnemi(Ennemi* e)
{
    int currentFrame = 1;
    currentFrame = (int)(((SDL_GetTicks() / 100) % 9)) + 1;
   
    e->animFrame.x = currentFrame * (e->animFrame.w); 
}




void deplacer(Ennemi* e)
{
    animerEnnemi(e);
    e->pos.x += e->xSpeed;
    e->pos.y += e->ySpeed;
}




int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
    int top1, top2;
    int bottom1, bottom2;
    int rightSide1, rightSide2;
    int leftSide1, leftSide2;

    leftSide1 = posp.x;
    rightSide1 = posp.x + posp.w;
    top1 = posp.y;
    bottom1 = posp.y + posp.h;

    leftSide2 = pose.x;
    rightSide2 = pose.x + pose.w;
    top2 = pose.y;
    bottom2 = pose.y + pose.h;

    if (rightSide1 <= leftSide2)
        return 0;
    if (leftSide1 >= rightSide2)
        return 0;
    if (bottom1 <= top2)
        return 0;
    if (top1 >= bottom2)
        return 0;
        
        else 
        

    return 1;
}




