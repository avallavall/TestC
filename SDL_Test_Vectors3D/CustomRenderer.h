#include "Point3D.h"
#include "Line3D.h"
#include "AirObject.h"
#include <SDL.h>

typedef struct{
    int a;
} CustomRenderer;

void CustomRenderer_renderPoint3D(Point3D *p, SDL_Renderer *renderer);
void CustomRenderer_renderLine3D(Line3D *line, SDL_Renderer *renderer);
void CustomRenderer_renderAirObject3D(AirObject *obj, SDL_Renderer *renderer);
