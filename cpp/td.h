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
    Vec3 c;     // center
    float r;        // radius

    Sphere(Vec3 i, float j){c=i,r=j;}

    bool intersect(Ray ray, float &t){      // tis is goddamn fucking with my spirit ;_;
        Vec3 o=ray.o;
        Vec3 d=ray.d;
        Vec3 oc=o-c;        // vector with direction from sphere to camera
        float b = 2*dot(oc,d);
        float c = dot(oc,oc) - r*r;
        float disc = (b*b-4*1*c)/2;
        if(disc<0) return false;        // se o delta dentro da raiz for negativo quer dizer que nao ha zeros, como em matematica assim nao ha intersecoes com a esfera
        else{
            disc = sqrt(disc);      // se o delta for maior que zero calcula-se os valores ou o valor se for 0
            float zero0 = -b-disc;      // continuase a formula resolvente
            float zero1 = -b+disc;      // continuase a formula resolvente
            if (zero0<zero1) t=zero0;       // retornase o valor mais baixo para o valor zero
            else{
                t=zero1;
            };
        return true;
        };
    };
};

struct Color{
    double r,g,b;
    Color(){r=g=b=0;};
    Color(double i, double j, double k){r=i,g=j,b=k;}
};

#endif
