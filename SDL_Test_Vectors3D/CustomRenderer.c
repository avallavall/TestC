#include "CustomRenderer.h"
#include <stdio.h>

void CustomRenderer_renderPoint3D(Point3D *p, SDL_Renderer *renderer) {
    SDL_RenderDrawPoint(renderer, p->x, p->y);
}

void CustomRenderer_renderLine3D(Line3D *line, SDL_Renderer *renderer) {
    SDL_RenderDrawLine(renderer, line->p1.x, line->p1.y, line->p2.x, line->p2.y);
}

void CustomRenderer_renderAirObject3D(AirObject *obj, SDL_Renderer *renderer) {
    CustomRenderer_renderPoint3D(&(obj->position), renderer);
    CustomRenderer_renderLine3D(&(obj->dir_vector), renderer);
}
void CustomRenderer_renderText(char text[100], SDL_Renderer *renderer){
    SDL_Color color = {255, 128, 128};
}

CustomRenderer CustomRenderer_Init(){
    CustomRenderer cr;
    if (TTF_Init() != 0) {
        printf("Error initializing SDL_ttf: %s\n", TTF_GetError());
    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
    }
    cr.font = TTF_OpenFont("arial.ttf", 25);
    if (cr.font == NULL) {
        printf("CR_INIT: Error loading font: %s\n", TTF_GetError());
    }

    cr.textColor.r = 255;
    cr.textColor.g = 128;
    cr.textColor.b = 128;

    cr.lineColor.r = 128;
    cr.lineColor.g = 255;
    cr.lineColor.b = 255;
    return cr;
}

void CustomRenderer_Destroy(){
    TTF_Quit();
    SDL_Quit();
}
