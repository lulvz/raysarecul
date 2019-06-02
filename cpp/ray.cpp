#include <fstream>
#include <iostream>
#include <cmath>
#include <new>
#include "td.h"

using namespace std;

int main()
{
    const int h = 600;
    const int w = 600;

    // allocating memory to store the
    Color** pixel_col = new Color*[h];
    for(int i = 0; i < h; i++){
        pixel_col[i] = new Color[w];
    };

    // defining color white
    Color white(255,255,255);

    // creating a sphere
    Sphere sphere(Vec3(w/2,h/2,50),70);

    // setting the name of the file and creating an ofstream object
    ofstream out("img.ppm");

    // info
    cout << "starting the writing process" << endl;

    // output info to file -.-
    out << "P3\n" << w << " " << h << "\n255" << '\n';

    // these loops go over evey pixel on the specified width and height
    for (int y=0; y<h; y++){
        for (int x=0; x<w; x++){
            // send ray for every pixel
            Ray ray(Vec3(x,y,0), Vec3(0,0,1));

            float t;        // place to store the zero from the intersect funtion inside sphere

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
    // deallocating the pixel_col thingy
    for(int i = 0; i < h; i++)
        delete[] pixel_col[i];
    delete[] pixel_col;

    return 0;
}
