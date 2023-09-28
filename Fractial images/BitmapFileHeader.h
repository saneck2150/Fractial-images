#pragma once
#include <iostream>

using namespace std;

#pragma pack(2)

namespace FractialImages
{
	class BitmapFileHeader
	{
	public:
		char header[2]{ 'B','M' };  // BMP file signature
		int32_t fileSize;  // size of file
		int32_t reserved{ 0 }; 
		int32_t dataOffset; // start of pixel datas in BMP file
		//All parameters are taken from google search
	};
}
