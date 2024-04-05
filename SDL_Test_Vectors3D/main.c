#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include <stdbool.h>
#include <SDL_ttf.h>

#include "Point3D.h"
#include "Line3D.h"
#include "AirObject.h"
#include "CustomRenderer.h"
//---------------------CONSTANTS-----------------------------
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 30000;
const int frameDelay = 1000 / FPS;
//---------------------VARIABLES-------------------------------
Point3D p1, p2, p3;
Line3D line1;
CustomRenderer cr;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;
bool running = true;
//---------------------3DWORLD INIT---------------------------
void World_initializer();
void World_initializer(){
    p1 = Point3D_create(1, 2, 0);
    p2 = Point3D_create(4, 5, 0);
    p3 = Point3D_create(21, 90, 0);
    line1 = Line3D_create(&p1, &p2);

    window = SDL_CreateWindow("A line", 100, 100, 1300, 700, false);
    renderer = SDL_CreateRenderer(window, -1, 0);
    cr = CustomRenderer_Init();
}
//----------------------KEY EVENT HANDLER---------------------
void Key_eventHandler();
void Key_eventHandler(){
    while( SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    Line3D_scale(&line1, 1.01);
                    printf("UP\n");
                    break;
                case SDLK_DOWN:
                    printf("DOWN\n");
                    Line3D_scale(&line1, 0.99);
                    break;
                case SDLK_LEFT:
                    printf("LEFT\n");
                    break;
                case SDLK_RIGHT:
                    printf("RIGHT\n");
                    break;
                case 7:
                    running = false;
                    break;
                default:
                    printf("%d %c\n", event.key.keysym.sym, event.key.keysym.sym);
                    break;
            }
        }
    }
}
//---------------------MAIN-----------------------------------
int main( int argc, char* args[] )
{

    World_initializer();
    Uint32 frameCount = 0;
    Uint32 timerFPS = SDL_GetTicks();
    Uint32 frameStart;
    int frameTime;
    //Point3D_print(&p1);
    //Point3D_print(&p2);
    //Point3D_print(&p3);
    //Line3D_print(&line1);
    //printf("Distance between points (%.2f, %.2f, %.2f)(%.2f, %.2f, %.2f) is: %f\n", p2.x, p2.y, p2.z, p3.x, p3.y, p3.z, Point3D_distance(&p2, &p3));
    //printf("The size of the Triangle3D structure is: %lld Bytes", sizeof(Triange3D));

    Line3D_scale(&line1, 100);
    Line3D_print(&line1);


    SDL_Surface *surface = TTF_RenderText_Solid(cr.font, "Hola, mundo!", cr.textColor);
    if (surface == NULL) {
        printf("Error creating surface: %s\n", TTF_GetError());
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        printf("Error creating texture: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(surface);
    SDL_Rect dstrect = {0, 0, surface->w, surface->h};
    //SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);


    char text[100]; // Buffer for your text
    while (running)
    {
        frameStart = SDL_GetTicks();
        Key_eventHandler();

        // Update the text and recreate the texture
        if (SDL_GetTicks() - timerFPS >= 1000) {
            sprintf(text, "FPS: %d", frameCount);
            frameCount = 0;
            timerFPS = SDL_GetTicks();
        }
        surface = TTF_RenderText_Solid(cr.font, text, cr.textColor);
        if (surface == NULL) {
            printf("Error creating surface: %s\n", TTF_GetError());
        }
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == NULL) {
            printf("Error creating texture: %s\n", SDL_GetError());
        }
        SDL_FreeSurface(surface); // Don't forget to free the old surface
        dstrect.x = 0;
        dstrect.y = 0;
        dstrect.w = surface->w;
        dstrect.h = surface->h;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        CustomRenderer_renderLine3D(&line1, renderer);
        CustomRenderer_renderPoint3D(&p1, renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect); // Render the text
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(texture); // Don't forget to destroy the old texture

        frameCount++;
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_DestroyTexture(texture);
    TTF_CloseFont(cr.font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    CustomRenderer_Destroy();
    return 0;
}
