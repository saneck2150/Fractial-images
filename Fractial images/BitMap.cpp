#include<fstream>

#include "BitMap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace FractialImages;

FractialImages::BitMap::BitMap(int width, int height) : _height(height), _width(width), _pixelPtr(new uint8_t[width * height * 3]{})
{

}

void FractialImages::BitMap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t* pPixel = _pixelPtr.get(); // pointer for current pixel
	pPixel += ((y * 3) * _width) + (3 * x);  // All raws covered by y and specifyed by x || *3 - for every RGB colour

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;

}

bool FractialImages::BitMap::write(string filename)
{
	BitmapFileHeader bitmapFile;
	BitmapInfoHeader bitmapInfo;

	bitmapFile.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (_height*_width*3); // (File) + (Info) + (AreaOfPixelPlane * NumbOfColoursForEachPixel)
	bitmapFile.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	bitmapInfo.height = _height;
	bitmapInfo.width = _width;
	
	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if(!file) return false;
///////////////////// writing in file section

	file.write((char*)&bitmapFile, sizeof(bitmapFile)); // writing BitmapFileHeader to file
	file.write((char*)&bitmapInfo, sizeof(bitmapInfo)); // writing BitmapInfoHeader to file
	file.write((char*)_pixelPtr.get(), _height * _width * 3);

////////////////////
	file.close();

	if (!file) return false;

	return true;

	
}

FractialImages::BitMap::~BitMap()
{

}
