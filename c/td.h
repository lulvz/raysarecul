#ifndef TD_H
#define TD_H

// Vector struct
struct Vec3{
    float x,y,z;
    Vec3(){x=y=z=0;}
    Vec3(float a, float b, float c){x=a, y=b, z=c;}

    Vec3 operator - (Vec3& v){return Vec3(x-v.x, y-v.y, z-v.z);}
    Vec3 operator + (Vec3& v){return Vec3(x+v.x, y+v.y, z+v.z);}

    Vec3 normalize() {
        float len = sqrt(x*x+y*y+z*z);
        return Vec3(x/len, y/len, z/len);
    };
};

// Ray struct
struct Ray{
    Vec3 o;     // origin
    Vec3 d;     // direction
    Ray(Vec3 i, Vec3 j){o=i, d=j;}
};

// where to save rgb color data i guess
struct RGBsave{
    float r;
    float g;
    float b;
};

struct Sphere{
    Vec3 c;     // cemter
    float r;        // radius

    Sphere(Vec3 i, float j){c=i,r=j;}

    bool intersect(Ray ray, float &t){
        Vec3 o=ray.o;
        Vec3 d=ray.d;
        Vec3 oc = o-c;
    };
};

int test(float a){
    float result = exp(a);
    return result;
};

#endif
