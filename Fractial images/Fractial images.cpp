#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "BitMap.h"
#include "MandelbrotClass.h"

#include <cstdint>

using namespace FractialImages;

int main()
{
    constexpr int WIDTH = 1200;
    constexpr int HEIGHT = 1200;
    double min = 999999; // Scaling for tests
    double max = -999999; // Scaling for tests

    BitMap bitmap(WIDTH, HEIGHT);

    
    ////////////////// For scaling test
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double xFractial = (x - WIDTH/2 - 200) * 3.0/WIDTH;   // Offset from 1 to -1, not from 0 to 1
            double yFractial = (y - HEIGHT/2) * 3.0/HEIGHT;   // Offset from 1 to -1, not from 0 to 1

            int iterations = MandelbrotClass::getIterations(xFractial, yFractial);

            uint8_t colour = (uint8_t)(256 * (double)iterations / MandelbrotClass::MAX_ITERATIONS);

            bitmap.setPixel(x, y, colour, 0, 0);
            if (colour < min) min = colour;
            if (colour > max) max = colour;
        }
    }
    //////////////////

    cout << "min: " << min << "\t" << "max: " << max << endl;

    bitmap.write("test.bmp");
    cout << "Done!" << endl;
}