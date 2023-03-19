typedef struct cylinder Cylinder;

Cylinder* newCylinder(float radius, float height);

float getHeight(Cylinder *cylinder);

float getRadius(Cylinder *cylinder);

float getTotalArea(Cylinder * cylinder);

float getVolume(Cylinder * cylinder);

void freeCylinder(Cylinder *cylinder);