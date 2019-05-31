#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "3d.h"

using namespace std;

int nx;
int ny;

class Sphere{
public:
};

RGBsave RGB_test;

int main()
{
    RGB_test.r = 0.3;
    RGB_test.g = 0.1;
    RGB_test.b = 0.32;


    ::ny = 200;
    ::nx = 400;

    cout << "P3\n" << ::nx << " " << ::ny << "\n255" << '\n';

    for (int j=ny-1;j>=0;j--){
        for (int i=0; i<nx; i++){
            //float r = float(i) / float(nx);
            //float g = float(j) / float(ny);
            //float b = 0.4;
            //int ir = int(r*255.99);
            //int ig = int(g*255.99);
            //int ib = int(b*255.99);
            //  this was from the "a raytracer in a weekend " hello world code for ppm files //

            int ir = int(RGB_test.r*255.99);
            int ig = int(RGB_test.g*255.99);
            int ib = int(RGB_test.b*255.99);
            cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    

    return 0;
}
