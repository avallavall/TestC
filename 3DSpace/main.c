#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include <stdbool.h>

//---------------------CONSTANTS-----------------------------
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//-------------------------STRUCTS------------------------
typedef struct{
    double x;
    double y;
    double z;
} Point3D;

typedef struct{
    Point3D p1;
    Point3D p2;
} Line3D;

typedef struct{
    Point3D p1;
    Point3D p2;
    Point3D p3;
} Triange3D;

typedef struct{
    int id;
    Point3D position; // Position of the AirObject.
    double vel[3]; // Velocity of the drone
    double acc[3]; // Acceleration of the drone
    Line3D dir_vector; // Direction vector of the drone
} AirObject;
//-------------------DECLARATIONS---------------------
Point3D     Point3D_create(double x, double y, double z);
void        Point3D_print(Point3D *p1);
double      Point3D_distance(Point3D *p1, Point3D *p2);

Line3D      Line3D_create(Point3D *p1, Point3D *p2);
void        Line3D_print(Line3D *line);
void        Line3D_render(Line3D *line, SDL_Renderer *renderer);
void        Line3D_scale(Line3D *line, double scalar);

Triange3D   Triangle3D_create(Point3D *p1, Point3D *p2, Point3D *p3);

//--------------------DEFINITIONS--------------------
Point3D     Point3D_create(double x, double y, double z){
    Point3D p;

    p.x = x;
    p.y = y;
    p.z = z;

    return p;
}
void        Point3D_print(Point3D *p1){
    printf("Point data: (%.2f, %.2f, %.2f)\n", p1->x, p1->y, p1->z);
}
// Function to calculate the distance between two points
double      Point3D_distance(Point3D *p1, Point3D *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
}
Line3D      Line3D_create(Point3D *p1, Point3D *p2){
    Line3D l;

    l.p1.x = p1->x;
    l.p1.y = p1->y;
    l.p1.z = p1->z;

    l.p2.x = p2->x;
    l.p2.y = p2->y;
    l.p2.z = p2->z;

    return l;
}
void        Line3D_print(Line3D *line){
    printf("Line data: (%.2f, %.2f, %.2f)(%.2f, %.2f, %.2f)\n", line->p1.x, line->p1.y, line->p1.z, line->p2.x, line->p2.y, line->p2.z);
}
void        Line3D_render(Line3D *line, SDL_Renderer *renderer){
    SDL_RenderDrawLine(renderer, line->p1.x, line->p1.y, line->p2.x, line->p2.y);
}
void        Line3D_scale(Line3D *line, double scalar) {
    line->p1.x *= scalar;
    line->p1.y *= scalar;
    line->p1.z *= scalar;

    line->p2.x *= scalar;
    line->p2.y *= scalar;
    line->p2.z *= scalar;
}
Triange3D   Triangle3D_create(Point3D *p1, Point3D *p2, Point3D *p3){
    Triange3D t;

    t.p1.x = p1->x;
    t.p1.y = p1->y;
    t.p1.z = p1->z;

    t.p2.x = p2->x;
    t.p2.y = p2->y;
    t.p2.z = p2->z;

    t.p3.x = p3->x;
    t.p3.y = p3->y;
    t.p3.z = p3->z;

    return t;
}
//---------------------MAIN-----------------------------------
int main( int argc, char* args[] )
{
    Point3D p1 = Point3D_create(1, 2, 0);
    Point3D p2 = Point3D_create(4, 5, 0);
    Point3D p3 = Point3D_create(21, 90, 0);

    Line3D line1 = Line3D_create(&p1, &p2);

    //Point3D_print(&p1);
    //Point3D_print(&p2);
    //Point3D_print(&p3);

    Line3D_print(&line1);

    printf("Distance between points (%.2f, %.2f, %.2f)(%.2f, %.2f, %.2f) is: %f\n", p2.x, p2.y, p2.z, p3.x, p3.y, p3.z, Point3D_distance(&p2, &p3));

    //printf("The size of the Triangle3D structure is: %lld Bytes", sizeof(Triange3D));

    SDL_Window* window = SDL_CreateWindow("A line", 10, 10, 1200, 600, false);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Line3D_scale(&line1, 100);
    Line3D_print(&line1);

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while( SDL_PollEvent(&event) )
        {
            if (event.type == SDL_QUIT)
                running = false;
            else if (event.type == SDL_KEYDOWN) // This is the new line
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        printf("UP\n");
                        break;
                    case SDLK_DOWN:
                        printf("DOWN\n");
                        break;
                    case SDLK_LEFT:
                        printf("LEFT\n");
                        break;
                    case SDLK_RIGHT:
                        printf("RIGHT\n");
                        break;
                    default:
                        printf("%d %c\n", event.key.keysym.sym, event.key.keysym.sym);
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        Line3D_render(&line1, renderer);
        SDL_RenderPresent( renderer );
    }

    SDL_Quit();
    return 0;
}
