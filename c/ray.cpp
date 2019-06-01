#include <fstream>
#include <iostream>
#include <cmath>
#include "td.h"

using namespace std;

int w;
int h;

RGBsave RGB_test;

int main()
{
    RGB_test.r = 1.0;
    RGB_test.g = 1.0;
    RGB_test.b = 1.0;


    ::h = 200;
    ::w = 400;

    ofstream out("img.ppm");
    // output info to file -.-
    out << "P3\n" << ::w << " " << ::h << "\n255" << '\n';

    // info
    cout << "starting the writing process" << endl;

    // these loops go over evey pixel on the specified width and height
    for (int y=0; y<h; y++){
        for (int x=0; x<w; x++){

            //  this was from the "a raytracer in a weekend " hello world code for ppm files //
            //float r = float(i) / float(w);
            //float g = float(j) / float(h);
            //float b = 0.4;
            //int ir = int(r*255.99);
            //int ig = int(g*255.99);
            //int ib = int(b*255.99);

            // test code
            /*
            int ir = int(RGB_test.r*255.99);
            int ig = int(RGB_test.g*255.99);
            int ib = int(RGB_test.b*255.99);
            out << ir << " " << ig << " " << ib << "\n";
            */

            Ray ray(Vec3(x,y,0), Vec3(0,0,1));

        }
    }
    return 0;
}
