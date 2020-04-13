#include "Image.h"
#include<iostream>
#include "ppm_format.h"
using namespace std;

namespace imaging{

	Image::Image() : Array(0, 0){}


	Image::Image(unsigned int width, unsigned int height) : Array(width, height) {}


	Image::Image(unsigned int width, unsigned int height, const Vec3<float> * data_ptr) : Array(width, height) {
		setData(data_ptr);
	}

	Image::Image(const Image &src) : Array(src){}


	void Image::setData(const Vec3<float> * & data_ptr){
		int i;
		for (i = 0; i < (height*width); i++){
			*(buffer + i) = *(data_ptr + i);
		}
	}

	Image::~Image(){
		if (buffer != nullptr)
			delete[]buffer;
	}

	Vec3<float> Image::getPixel(unsigned int x, unsigned int y) const{
		if (!(x >= width || y >= height)){
			return (*this)(x, y);
		}
		else{
			return Vec3<float>();
		}
	}

	void Image::setPixel(unsigned int x, unsigned int y, Vec3<float> & value){
		if (!(x > width || y > height)){
			buffer[(y*width + x)] = value;
		}
	}


	bool Image::operator << (std::string filename) {
		const char* filename2 = filename.c_str();
		Image *img = ReadPPM(filename2);
		if ((*img).getHeight() == 0 || (*img).getWidth() == 0){
			return false;
		}
		width = (*img).getWidth();
		height = (*img).getHeight();
		buffer = new Vec3<float>[width*height];
		memcpy(buffer, (*img).getRawDataPtr(), (width*height*sizeof(Vec3<float>)));
		delete[] img;
		return true;
	}



	bool Image::operator >> (std::string filename){
		const char* filename2 = filename.c_str();
		return WritePPM(*this, filename2);
	}

}