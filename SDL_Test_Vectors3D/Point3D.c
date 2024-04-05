#include "Point3D.h"
#include <math.h>
#include <stdio.h>

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
