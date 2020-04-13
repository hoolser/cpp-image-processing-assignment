#include<iostream>
#include<fstream>
#include<string>
#include <sstream> 
#include "ppm_format.h"
using namespace std;
using namespace imaging;

int main(int argc, char* argv[]){
	Image *img = new Image();
	if (argc <= 1){
		string file;
		cout << "File name of the image to load: ";
		cin >> file;
		if (!(*img << file)){
			delete img;
			exit(EXIT_FAILURE);
		}
	}
	else{
		const char* filename = argv[1];
		if (!(*img << filename)){
			delete img;
			exit(EXIT_FAILURE);
		}
	}
	printf("Image dimensions are: %d X %d \n", (img->getWidth()), (img->getHeight()));
	long double r2 = 0, g2 = 0, b2 = 0;
	for (int i = 0; i < (*img).getHeight(); i++){
		for (int j = 0; j < (*img).getWidth(); j++){
			r2 += ((*img).getPixel(j, i)).r;
			g2 += ((*img).getPixel(j, i)).g;
			b2 += ((*img).getPixel(j, i)).b;
		}
	}
	r2 /= ((*img).getWidth() * (*img).getHeight());
	g2 /= ((*img).getWidth() * (*img).getHeight());
	b2 /= ((*img).getWidth() * (*img).getHeight());
	printf("The average color of the image is (%f, %f, %f)\n", r2, g2, b2);
	if (argc > 2){
		const char* output = argv[2];
		if (*img >> output){
			printf("Image written to %s\n", output);
		}
	}
	delete img;
	system("pause");
	return 0;
}