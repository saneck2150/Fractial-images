#pragma once
#include <iostream>

using namespace std;

#pragma pack(2)

namespace FractialImages
{
	class BitmapInfoHeader
	{
	public:
		int32_t headerSize{ 40 };  // size of whole header
		int32_t width; // width of bitmap
		int32_t height; // height of bitmap
		int16_t planes{ 1 };  // number of image planes 
		int16_t bitsPerPixel{ 24 }; // reserved bits for pixel (8 bits for each RGB colour)
		int32_t compression{ 0 }; // image compression (0 - no compression)
		int32_t dataSize{ 0 }; // data size of image 
		int32_t horizontalResolution{ 2400 };
		int32_t verticalResolution{ 2400 };
		int32_t colors{ 0 }; // number of colours in pixel (0 - all colours)
		int32_t importantColors{ 0 }; // number of important colours (0 - all are important)
		//All parameters are taken from google search
	};
}
