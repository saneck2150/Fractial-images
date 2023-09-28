#pragma once
#include <iostream>
#include <cstring>
using namespace std;

namespace FractialImages
{
	class BitMap
	{
	private:
		int _height{0};// member height
		int _width{0};  // member width
		unique_ptr<uint8_t[]> _pixelPtr{ nullptr }; // operate pointer for pixels allocation
	public:
		BitMap(int width, int height);
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); // method sets the colour for pixel
		bool write(string filename); // method to write data to file. Returns 1 if writing successful
		~BitMap();
	};
}


