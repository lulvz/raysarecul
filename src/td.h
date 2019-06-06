#ifndef TD_H
#define TD_H

// Vector struct
struct Vec3{
    float x,y,z;
    Vec3(){x=y=z=0;}
    Vec3(float a, float b, float c){x=a, y=b, z=c;}

    Vec3 operator - (Vec3 v){return Vec3(x-v.x, y-v.y, z-v.z);}
    Vec3 operator + (Vec3 v){return Vec3(x+v.x, y+v.y, z+v.z);}
    Vec3 operator * (float d){return Vec3(x*d, y*d, z*d);}
    Vec3 operator / (float d){return Vec3(x/d, y/d, z/d);}

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

    bool intersect(Ray ray, float &ts0, float &ts1){
        Vec3 o = ray.o - ce;        // simplify the operations by placing the sphere at the origin from what ive read
        Vec3 d = ray.d;

        const float A = dot(d, d);
        const float B = 2 * dot(o, d);
        const float C = dot(o, o) - r * r;
        float disc = B*B - 4*A*C;
        if(disc<0) return false;
        else{
            disc = sqrt(disc);
            float zero0 = (-B-disc)/2*A;
            float zero1 = (-B+disc)/2*A;

            ts0 = zero0;
            ts1 = zero1;
        }
        return true;
    }
};

struct Plane {
    Vec3 p0, n;       // a point that is in the plane and a normal
    Plane(Vec3 i, Vec3 u) {p0=i, n=u;}

    // plane is defined by ax + by + cz + d = 0 or n⃗ ⋅(k−j)=0, where k and j are points that lie on the plane
    // this last equation can be transformed to n⃗⋅k=d and n⃗⋅j=d where d-d=0

    bool intersect(Ray ray, Vec3 &tp0){
        Vec3 o = ray.o;
        Vec3 di = ray.d;
        // n ⋅ (pi-p0−)=0 where pi is what we want to determine (point of intersection)

        float k;        // number to multiply to get the point in the vector equation
        if(dot(n, di) == 0) return false;       // avoid division by zero
        if(dot(n, (p0-o)) == 0) return false;       // the ray is contained in the plane

        k = dot(n, (p0-o))/dot(n, di);
        if(k<0) return false;

        tp0 = o + di*k;
        return true;
    }
};

struct Color{
    double r,g,b;
    Color(){r=g=b=0;};
    Color(double i, double j, double k){r=i,g=j,b=k;}
    bool operator != (Color d){return (r!=d.r && g!=d.g && b!=d.b);}
};

#endif
