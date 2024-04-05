#include "Line3D.h"
#include <math.h>
#include <stdio.h>

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
void        Line3D_scale(Line3D *line, double scalar) {
    line->p1.x *= scalar;
    line->p1.y *= scalar;
    line->p1.z *= scalar;

    line->p2.x *= scalar;
    line->p2.y *= scalar;
    line->p2.z *= scalar;
}
