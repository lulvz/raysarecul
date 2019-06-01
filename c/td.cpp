// implementation of the 3d classes we need and its functions
#include "td.h"

Vec3::Vec3(float a, float b, float c){x=a,y=b,z=c};

Ray::Ray(Vec i, Vec j){o=i, d=j};
