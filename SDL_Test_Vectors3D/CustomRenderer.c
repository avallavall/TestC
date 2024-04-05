#include "CustomRenderer.h"

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
