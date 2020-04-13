#include<iostream>
#include<fstream>
#include<string>
#include <sstream> 
#include "ppm_format.h"
#include "Gray.h"
#include "Color.h"
#include "Blur.h"
#include "Median.h"
#include "Diff.h"
using namespace std;
using namespace imaging;


bool isFloat(string myString);

int main(int argc, char* argv[]){
	Image *img = new Image();
	const char* filename = argv[argc - 1];
	if (!(*img << filename)){
		delete img;
		exit(EXIT_FAILURE);
	}
	int count = 1;
	if (argc == 1){
		printf("wasn't given any arguments\n");
		delete img;
		system("pause");
		exit(EXIT_FAILURE);
	}
	while (count<(argc - 1)){
		string str = argv[count];
		if (str.compare("-f") == 0){
			count++;
			string str = argv[count];
			if (str.compare("gray") == 0){
				Gray gr = Gray();
				gr.filtration(*img);
			}
			else if (str.compare("color") == 0){
				float red, green, blue;
				if (count < (argc - 1)){
					count++;
					if (isFloat(argv[count])){
						red = stof(argv[count]);
					}
					else{
						printf("not have been given correctly the arguments of filter color.\n");
						delete img;
						system("pause");
						exit(EXIT_FAILURE);
					}
				}
				else{
					printf("not have been given correctly the arguments of filter color.\n");
					delete img;
					system("pause");
					exit(EXIT_FAILURE);
				}
				if (count < (argc - 1)){
					count++;
					if (isFloat(argv[count])){
						green = stof(argv[count]);
					}
					else{
						printf("not have been given correctly the arguments of filter color.\n");
						delete img;
						system("pause");
						exit(EXIT_FAILURE);
					}
				}
				else{
					printf("not have been given correctly the arguments of filter color.\n");
					delete img;
					system("pause");
					exit(EXIT_FAILURE);
				}
				if (count < (argc - 1)){
					count++;
					if (isFloat(argv[count])){
						blue = stof(argv[count]);
					}
					else{
						printf("not have been given correctly the arguments of filter color.\n");
						delete img;
						system("pause");
						exit(EXIT_FAILURE);
					}
				}
				else{
					printf("not have been given correctly the arguments of filter color.\n");
					delete img;
					system("pause");
					exit(EXIT_FAILURE);
				}
				Color gr = Color(red, green, blue);
				gr.filtration(*img);
			}
			else if (str.compare("blur") == 0){
				Blur gr = Blur();
				gr.filtration(*img);
			}
			else if (str.compare("median") == 0){
				Median gr = Median();
				gr.filtration(*img);
			}
			else if (str.compare("diff") == 0){
				Diff gr = Diff();
				gr.filtration(*img);
			}
			else{
				printf("typo in a filter name.\n");
				delete img;
				system("pause");
				exit(EXIT_FAILURE);
			}

		}
		else{
			printf("There is no \"-f\" tag.\n");
			delete img;
			system("pause");
			exit(EXIT_FAILURE);
		}
		count++;
	}
	if (argc > 2){
		string str = filename;
		str = str.substr(0, str.size() - 3);
		str += "filtered.ppm";
		const char* output = str.c_str();
		if (*img >> output){
			printf("Image written to %s\n", output);
		}
	}
	else{
		printf("there exists no filter in arguments.\n");
	}
	delete img;
	system("pause");
	return 0;
}


bool isFloat(string myString) {
	std::istringstream iss(myString);
	float f;
	iss >> noskipws >> f;
	return iss.eof() && !iss.fail();
}