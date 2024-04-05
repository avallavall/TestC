#ifndef POINT3D_H  // This checks if POINT3D_H has not been defined yet
#define POINT3D_H  // This defines POINT3D_H

typedef struct{
    double x;
    double y;
    double z;
} Point3D;

Point3D Point3D_create(double x, double y, double z);
void Point3D_print(Point3D *p1);
double Point3D_distance(Point3D *p1, Point3D *p2);

#endif  // This ends the check for POINT3D_H
