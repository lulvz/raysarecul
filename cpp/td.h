#ifndef TD_H
#define TD_H

// Vector struct
struct Vec3{
    float x,y,z;
    Vec3(){x=y=z=0;}
    Vec3(float a, float b, float c){x=a, y=b, z=c;}

    Vec3 operator - (Vec3& v){return Vec3(x-v.x, y-v.y, z-v.z);}
    Vec3 operator + (Vec3& v){return Vec3(x+v.x, y+v.y, z+v.z);}
    Vec3 operator * (double d){return Vec3(x*d, y*d, z*d);}
    Vec3 operator / (double d){return Vec3(x/d, y/d, z/d);}

    Vec3 normalize() {
        float len = sqrt(x*x+y*y+z*z);
        return Vec3(x/len, y/len, z/len);
    };
};

// dot product specification
float dot(Vec3 v, Vec3 b){
    return (v.x*b.x + v.y*b.y + v.z*b.z);
};

// Ray struct
struct Ray{
    Vec3 o;     // origin
    Vec3 d;     // direction
    Ray(Vec3 i, Vec3 j){o=i, d=j;}
};

struct Sphere{
    Vec3 ce;     // center
    float r;        // radius

    Sphere(Vec3 i, float j){ce=i,r=j;}

    bool intersect(Ray ray, float &t0, float &t1){
        Vec3 o = ray.o;
        Vec3 d = ray.d;
        float a = dot(d-o, d-o);
        float b = 2*dot(d-o, o-ce);
        float c = dot(ce, ce) + dot(o, o) - 2*(dot(ce, o)) - r*r;
        float disc = (b*b-4*a*c)/2;
        if(disc < 0) return false;
        else{
            disc = sqrt(disc);
            float zero0 = -b - disc;
            float zero1 = -b + disc;
            t0 = zero0;
            t1 = zero1;
        }
        return true;
    }
};

struct Color{
    double r,g,b;
    Color(){r=g=b=0;};
    Color(double i, double j, double k){r=i,g=j,b=k;}
};

#endif
