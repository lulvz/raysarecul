#include <fstream>
#include <iostream>
#include <cmath>
#include "td.h"
#include <stdbool.h>

#define FALSE false
#define TRUE true

using namespace std;

double
 ABS(double a){
    if(a<0){
        return -a;
    } else{
        return a;
    }
}

int RaySphere(Vec3 origin, Vec3 dir, Vec3 center ,double r ,double *mu1,double *mu2)
{
   double a,b,c;
   double bb4ac;
   Vec3 o_d;

   o_d.x = dir.x - origin.x;
   o_d.y = dir.y - origin.y;
   o_d.z = dir.z - origin.z;
   a = o_d.x * o_d.x + o_d.y * o_d.y + o_d.z * o_d.z;
   b = 2 * (o_d.x * (origin.x - center.x) + o_d.y * (origin.y - center.y) + o_d.z * (origin.z - center.z));
   c = center.x * center.x + center.y * center.y + center.z * center.z;
   c += origin.x * origin.x + origin.y * origin.y + origin.z * origin.z;
   c -= 2 * (center.x * origin.x + center.y * origin.y + center.z * origin.z);
   c -= r * r;
   bb4ac = b * b - 4 * a * c;
   if (bb4ac < 0) {
      *mu1 = 0;
      *mu2 = 0;
      return(FALSE);
   }

   *mu1 = (-b + sqrt(bb4ac)) / (2 * a);
   *mu2 = (-b - sqrt(bb4ac)) / (2 * a);

   return(TRUE);
}

int main(){
    double mu1,mu2;
    //               vector origin       dir       center   radius
    bool i = RaySphere(Vec3(0,0,0), Vec3(0,0,1), Vec3(0,0,2), 4, &mu1, &mu2);
    if (i){
        cout << mu1 << " " << mu2 << endl;
    } else{
        cout << "doesnt intersect lol bitch" << endl;
    }

    return 0;
}
