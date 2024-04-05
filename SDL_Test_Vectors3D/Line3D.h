#ifndef LINE3D_H  // This checks if LINE3D_H has not been defined yet
#define LINE3D_H  // This defines LINE3D_H

#include "Point3D.h"
#include <SDL.h>

typedef struct{
    Point3D p1;
    Point3D p2;
} Line3D;

Line3D      Line3D_create(Point3D *p1, Point3D *p2);
void        Line3D_print(Line3D *line);
void        Line3D_scale(Line3D *line, double scalar);

#endif  // This ends the check for LINE3D_H
