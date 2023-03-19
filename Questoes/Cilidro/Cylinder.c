#include <stdio.h>
#include <stdlib.h>
#include "Cylinder.h"
#include <math.h>

struct cylinder {
  float radius;
  float height;
};

Cylinder * newCylinder(float radius, float height) {
  Cylinder *cylinder = (Cylinder *) malloc(sizeof(Cylinder));
  if(cylinder != NULL) {
    cylinder->radius = radius;
    cylinder->height = height;
  }
  return cylinder;
}

float getHeight(Cylinder *cylinder) {
  if(cylinder == NULL) return -1;
  return cylinder->height;
}

float getRadius(Cylinder *cylinder) {
  if(cylinder == NULL) return -1;
  return cylinder->radius;
}

float getTotalArea(Cylinder * cylinder) {
  if(cylinder == NULL) return -1;
  float baseArea = 3.14 * pow(cylinder->radius, 2);
  float sideArea = 2 * 3.14 * cylinder->radius * cylinder->height;
  return 2 * baseArea + sideArea;
}

float getVolume(Cylinder * cylinder) {
  if(cylinder == NULL) return -1;
  float baseArea = 3.14 * pow(cylinder->radius, 2);
  return baseArea * cylinder->height;
}

void freeCylinder(Cylinder *cylinder) {
  free(cylinder);
}