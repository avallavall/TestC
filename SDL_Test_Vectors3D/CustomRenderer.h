#include "Point3D.h"
#include "Line3D.h"
#include "AirObject.h"
#include <SDL.h>
#include <SDL_ttf.h>

typedef struct{
    TTF_Font *font;
    SDL_Color textColor;
    SDL_Color lineColor;
} CustomRenderer;

void CustomRenderer_renderPoint3D(Point3D *p, SDL_Renderer *renderer);
void CustomRenderer_renderLine3D(Line3D *line, SDL_Renderer *renderer);
void CustomRenderer_renderAirObject3D(AirObject *obj, SDL_Renderer *renderer);
void CustomRenderer_renderText(char text[100], SDL_Renderer *renderer);
CustomRenderer CustomRenderer_Init();
void CustomRenderer_Destroy();
