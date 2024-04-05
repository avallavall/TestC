#ifndef AIROBJECT_H
#define AIROBJECT_H

typedef struct{
    int id;
    Point3D position; // Position of the AirObject.
    double vel[3]; // Velocity of the drone
    double acc[3]; // Acceleration of the drone
    Line3D dir_vector; // Direction vector of the drone
} AirObject;

#endif
