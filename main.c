#include <stdio.h>
#include <math.h>

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
//-------------------DECLARATIONS---------------------
Point3D Point3D_create(double x, double y, double z);
Line3D Line3D_create(Point3D p1, Point3D p2);
Triange3D Triangle3D_create(Point3D p1, Point3D p2, Point3D p3);
//--------------------DEFINITIONS--------------------
Point3D Point3D_create(double x, double y, double z){
    Point3D p;

    p.x = x;
    p.y = y;
    p.z = z;

    return p;
}
Line3D Line3D_create(Point3D p1, Point3D p2){
    Line3D l;

    l.p1.x = p1.x;
    l.p1.y = p1.y;
    l.p1.z = p1.z;

    l.p2.x = p2.x;
    l.p2.y = p2.y;
    l.p2.z = p2.z;

    return l;
}
Triange3D Triangle3D_create(Point3D p1, Point3D p2, Point3D p3){
    Triange3D t;

    t.p1.x = p1.x;
    t.p1.y = p1.y;
    t.p1.z = p1.z;

    t.p2.x = p2.x;
    t.p2.y = p2.y;
    t.p2.z = p2.z;

    t.p3.x = p3.x;
    t.p3.y = p3.y;
    t.p3.z = p3.z;

    return t;
}

//---------------------CONSTANTS-----------------------------

//---------------------MAI-----------------------------------
int main()
{
    printf("The size of the Triangle3D structure is: %lld Bytes", sizeof(Triange3D));

    return 0;
}
