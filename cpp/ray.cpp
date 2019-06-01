#include <fstream>
#include <iostream>
#include <cmath>
#include "td.h"

using namespace std;

int w;
int h;

int main()
{
    Color white(255,255,255);
    ::h = 500;
    ::w = 500;
    Color pixel_col[h][w];
    Sphere sphere(Vec3(::w/2,::h/2,50),20);

    ofstream out("img.ppm");

    // info
    cout << "starting the writing process" << endl;

    // output info to file -.-
    out << "P3\n" << ::w << " " << ::h << "\n255" << '\n';

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

            // send ray for every pixel
            Ray ray(Vec3(x,y,0), Vec3(0,0,1));

            float t;        // no idea why its set to 20000 lol

            // check for intersections
            if(sphere.intersect(ray,t)){

                //set color to the damn pixel
                pixel_col[y][x] = white;
            }

            out << pixel_col[y][x].r << " ";
            out << pixel_col[y][x].g << " ";
            out << pixel_col[y][x].b << endl;
        }
    }
    return 0;
}
