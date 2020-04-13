#include "ppm_format.h"
#include<iostream>
#include<fstream>
#include<string>
#include <sstream> 
#include <algorithm>  
using namespace std;

namespace imaging
{
	Image * ReadPPM(const char * filename){
		ifstream ifs;
		string s1;
		int i = 0;
		while (filename[i] != '\0'){
			s1 += filename[i];
			i++;
		}
		ifs.open(s1, ios::binary);
		try {
			if (ifs.fail()) { throw("Can't open input file"); }
			string header;
			int w = 0, h = 0, b;
			float red, green, blue;
			ifs >> header;
			if (strcmp(header.c_str(), "P6") != 0) throw("Can't read input file");
			ifs >> w;
			ifs >> h;
			ifs >> b;
			if (w <= 0)throw("Missing the horizontal dimension");
			if (h <= 0)throw("Missing the vertical dimension");
			if (b <= 0)throw("Missing the maximum value storage");
			if (b > 255)throw("the maximum value storage is greater than 255");
			char kati = ifs.peek();
			while (kati == ' ' || kati == '\n'){
				if (kati == ' '){
					ifs.ignore(256, ' ');
				}
				else{
					ifs.ignore(256, '\n');
				}
				kati = ifs.peek();
			}
			unsigned char pixel[3];
			int j = 0;
			Vec3<float> * buffer2 = new Vec3<float>[w*h];
			for (int i = 0; i < w*h; ++i) {
				ifs.read(reinterpret_cast<char *>(pixel), 3);
				red = pixel[0] / 255.f;
				green = pixel[1] / 255.f;
				blue = pixel[2] / 255.f;
				Vec3<float> k = Vec3<float>(red, green, blue);
				*(buffer2 + i) = k;

			}
			ifs.close();
			Image *img = new Image(w, h, buffer2);
			return img;
		}
		catch (const char *err) {
			fprintf(stderr, "%s\n", err);
			ifs.close();
			system("pause");
			return new Image();
		}
	}

	bool WritePPM(Image & image, const char * filename){
		if (image.getWidth() == 0 || image.getHeight() == 0) {
			fprintf(stderr, "Can't save an empty image\n");
			return false;
		}
		ofstream ofs;
		try {
			ofs.open(filename, ios::binary);
			if (ofs.fail()) throw("Can't open output file");
			int h = image.getHeight(), w = image.getWidth();
			ofs << "P6\n" << w << " " << h << "\n255\n";
			unsigned char r, g, b;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++){
					r = static_cast<unsigned char>(std::min(1.f, image.getPixel(j, i).r) * 255);
					g = static_cast<unsigned char>(std::min(1.f, image.getPixel(j, i).g) * 255);
					b = static_cast<unsigned char>(std::min(1.f, image.getPixel(j, i).b) * 255);
					ofs << r << g << b;
				}
			}
			ofs.close();
			return true;
		}
		catch (const char *err) {
			fprintf(stderr, "%s\n", err);
			ofs.close();
			return false;
		}
	}
}