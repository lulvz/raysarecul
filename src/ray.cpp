#include <fstream>
#include <iostream>
#include <cmath>
#include <new>
#include "td.h"

using namespace std;

float ts0, ts1;       // place to store the zeros from the intersect funtion inside sphere

int main()
{
    const int h = 720;
    const int w = 1280;

    // allocating memory to store the
    Color** pixel_col = new Color*[h];
    for(int i = 0; i < h; i++){
        pixel_col[i] = new Color[w];
    };

    // defining color white
    Color white(255,255,255);

    // defining background color
    Color backg(128,0,128);

    // defining color red lol
    Color red(244, 66, 66);

    // creating a sphere
    // Sphere sphere(Vec3(w/2,h/2,10),70);
    Sphere sphere(Vec3(w/2,h/2,20), 100);
    Sphere sphere1(Vec3(w/4,h/4,30), 50);
    Plane plane(0,0,1,-0.5);

    // setting the name of the file and creating an ofstream object
    ofstream out("images/img.ppm");

    // info
    cout << "starting the writing process" << endl;

    // output info to file -.-
    out << "P3\n" << w << " " << h << "\n255" << '\n';

    // these loops go over evey pixel on the specified width and height
    for (int y=0; y<h; y++){
        for (int x=0; x<w; x++){
            // send ray for every pixel
            Ray ray(Vec3(x,y,0), Vec3(0,0,1));

            // check for intersections
            if(sphere.intersect(ray,ts0,ts1) || sphere1.intersect(ray,ts1,ts1) || plane.intersect(ray)){
                // set color to the damn pixel
                pixel_col[y][x] = white;
            } else{
                // backgtound color setting
                pixel_col[y][x] = backg;
            }
            out << pixel_col[y][x].r << " ";
            out << pixel_col[y][x].g << " ";
            out << pixel_col[y][x].b << endl;
        }
    }
    // deallocating the pixel_col thingy
    for(int i = 0; i < h; i++)
        delete[] pixel_col[i];
    delete[] pixel_col;

    return 0;
}
