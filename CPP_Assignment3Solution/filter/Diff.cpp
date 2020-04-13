#include "Diff.h"

namespace imaging
{
	void Diff::filtration(Image &src){
		int count = 0;
		Vec3<float> tmp = Vec3<float>();
		Image temp = src;
		float red[9], green[9], blue[9];
		for (int i = 0; i < src.getHeight(); i++){
			for (int j = 0; j < src.getWidth(); j++){
				if ((j == 0 && i == 0)){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(0, 1).r;
					red[2] = temp.getPixel(1, 0).r;
					red[3] = temp.getPixel(1, 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(0, 1).g;
					green[2] = temp.getPixel(1, 0).g;
					green[3] = temp.getPixel(1, 1).g;
					blue[0] = temp.getPixel(j, i).r;
					blue[1] = temp.getPixel(0, 1).r;
					blue[2] = temp.getPixel(1, 0).r;
					blue[3] = temp.getPixel(1, 1).r;
					count = 4;
				}
				else if ((j == 0 && i == src.getHeight())){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(0, i - 1).r;
					red[2] = temp.getPixel(1, i).r;
					red[3] = temp.getPixel(1, i - 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(0, i - 1).g;
					green[2] = temp.getPixel(1, i).g;
					green[3] = temp.getPixel(1, i - 1).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(0, i - 1).b;
					blue[2] = temp.getPixel(1, i).b;
					blue[3] = temp.getPixel(1, i - 1).b;
					count = 4;
				}
				else if ((j == src.getWidth() && i == src.getHeight())){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(j, i - 1).r;
					red[2] = temp.getPixel(j - 1, i).r;
					red[3] = temp.getPixel(j - 1, i - 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(j, i - 1).g;
					green[2] = temp.getPixel(j - 1, i).g;
					green[3] = temp.getPixel(j - 1, i - 1).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(j, i - 1).b;
					blue[2] = temp.getPixel(j - 1, i).b;
					blue[3] = temp.getPixel(j - 1, i - 1).b;
					count = 4;
				}
				else if ((j == src.getWidth() && i == 0)){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(0, 1).r;
					red[2] = temp.getPixel(1, 0).r;
					red[3] = temp.getPixel(1, 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(0, 1).g;
					green[2] = temp.getPixel(1, 0).g;
					green[3] = temp.getPixel(1, 1).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(0, 1).b;
					blue[2] = temp.getPixel(1, 0).b;
					blue[3] = temp.getPixel(1, 1).b;
					count = 4;
				}
				else if ((i == 0)){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(j - 1, i).r;
					red[2] = temp.getPixel(j, i + 1).r;
					red[3] = temp.getPixel(j + 1, i).r;
					red[4] = temp.getPixel(j - 1, i + 1).r;
					red[5] = temp.getPixel(j + 1, i + 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(j - 1, i).g;
					green[2] = temp.getPixel(j, i + 1).g;
					green[3] = temp.getPixel(j + 1, i).g;
					green[4] = temp.getPixel(j - 1, i + 1).g;
					green[5] = temp.getPixel(j + 1, i + 1).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(j - 1, i).b;
					blue[2] = temp.getPixel(j, i + 1).b;
					blue[3] = temp.getPixel(j + 1, i).b;
					blue[4] = temp.getPixel(j - 1, i + 1).b;
					blue[5] = temp.getPixel(j + 1, i + 1).b;
					count = 6;
				}
				else if ((j == src.getWidth())){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(j - 1, i).r;
					red[2] = temp.getPixel(j - 1, i - 1).r;
					red[3] = temp.getPixel(j, i - 1).r;
					red[4] = temp.getPixel(j - 1, i + 1).r;
					red[5] = temp.getPixel(j, i + 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(j - 1, i).g;
					green[2] = temp.getPixel(j - 1, i - 1).g;
					green[3] = temp.getPixel(j, i - 1).g;
					green[4] = temp.getPixel(j - 1, i + 1).g;
					green[5] = temp.getPixel(j, i + 1).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(j - 1, i).b;
					blue[2] = temp.getPixel(j - 1, i - 1).b;
					blue[3] = temp.getPixel(j, i - 1).b;
					blue[4] = temp.getPixel(j - 1, i + 1).b;
					blue[5] = temp.getPixel(j, i + 1).b;
					count = 6;
				}
				else if ((i == src.getHeight())){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(j - 1, i - 1).r;
					red[2] = temp.getPixel(j, i - 1).r;
					red[3] = temp.getPixel(j + 1, i - 1).r;
					red[4] = temp.getPixel(j - 1, i).r;
					red[5] = temp.getPixel(j + 1, i).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(j - 1, i - 1).g;
					green[2] = temp.getPixel(j, i - 1).g;
					green[3] = temp.getPixel(j + 1, i - 1).g;
					green[4] = temp.getPixel(j - 1, i).g;
					green[5] = temp.getPixel(j + 1, i).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(j - 1, i - 1).b;
					blue[2] = temp.getPixel(j, i - 1).b;
					blue[3] = temp.getPixel(j + 1, i - 1).b;
					blue[4] = temp.getPixel(j - 1, i).b;
					blue[5] = temp.getPixel(j + 1, i).b;
					count = 6;
				}
				else if ((j == 0)){
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(j, i - 1).r;
					red[2] = temp.getPixel(j, i + 1).r;
					red[3] = temp.getPixel(j + 1, i - 1).r;
					red[4] = temp.getPixel(j + 1, i).r;
					red[5] = temp.getPixel(j + 1, i + 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(j, i - 1).g;
					green[2] = temp.getPixel(j, i + 1).g;
					green[3] = temp.getPixel(j + 1, i - 1).g;
					green[4] = temp.getPixel(j + 1, i).g;
					green[5] = temp.getPixel(j + 1, i + 1).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(j, i - 1).b;
					blue[2] = temp.getPixel(j, i + 1).b;
					blue[3] = temp.getPixel(j + 1, i - 1).b;
					blue[4] = temp.getPixel(j + 1, i).b;
					blue[5] = temp.getPixel(j + 1, i + 1).b;
					count = 6;
				}
				else{
					red[0] = temp.getPixel(j, i).r;
					red[1] = temp.getPixel(j - 1, i - 1).r;
					red[2] = temp.getPixel(j, i - 1).r;
					red[3] = temp.getPixel(j + 1, i - 1).r;
					red[4] = temp.getPixel(j - 1, i).r;
					red[5] = temp.getPixel(j + 1, i).r;
					red[6] = temp.getPixel(j - 1, i + 1).r;
					red[7] = temp.getPixel(j, i + 1).r;
					red[8] = temp.getPixel(j + 1, i + 1).r;
					green[0] = temp.getPixel(j, i).g;
					green[1] = temp.getPixel(j - 1, i - 1).g;
					green[2] = temp.getPixel(j, i - 1).g;
					green[3] = temp.getPixel(j + 1, i - 1).g;
					green[4] = temp.getPixel(j - 1, i).g;
					green[5] = temp.getPixel(j + 1, i).g;
					green[6] = temp.getPixel(j - 1, i + 1).g;
					green[7] = temp.getPixel(j, i + 1).g;
					green[8] = temp.getPixel(j + 1, i + 1).g;
					blue[0] = temp.getPixel(j, i).b;
					blue[1] = temp.getPixel(j - 1, i - 1).b;
					blue[2] = temp.getPixel(j, i - 1).b;
					blue[3] = temp.getPixel(j + 1, i - 1).b;
					blue[4] = temp.getPixel(j - 1, i).b;
					blue[5] = temp.getPixel(j + 1, i).b;
					blue[6] = temp.getPixel(j - 1, i + 1).b;
					blue[7] = temp.getPixel(j, i + 1).b;
					blue[8] = temp.getPixel(j + 1, i + 1).b;
					count = 9;
				}
				sort(red, red + count);
				sort(green, green + count);
				sort(blue, blue + count);
				tmp.r = red[count - 1] - red[0];
				tmp.g = green[count - 1] - green[0];
				tmp.b = blue[count - 1] - blue[0];
				src.setPixel(j, i, tmp);
			}
		}
	}

}