#include "Blur.h"

namespace imaging
{
	void Blur::filtration(Image &src){
		int count = 0;
		Vec3<float> tmp = Vec3<float>();
		Image temp = src;
		Vec3<float> mi[9];
		for (int i = 0; i < src.getHeight(); i++){
			for (int j = 0; j < src.getWidth(); j++){
				if ((j == 0 && i == 0)){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(0, 1);
					mi[2] = temp.getPixel(1, 0);
					mi[3] = temp.getPixel(1, 1);
					count = 4;
				}
				else if ((j == 0 && i == src.getHeight())){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(0, i - 1);
					mi[2] = temp.getPixel(1, i);
					mi[3] = temp.getPixel(1, i - 1);
					count = 4;
				}
				else if ((j == src.getWidth() && i == src.getHeight())){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(j, i - 1);
					mi[2] = temp.getPixel(j - 1, i);
					mi[3] = temp.getPixel(j - 1, i - 1);
					count = 4;
				}
				else if ((j == src.getWidth() && i == 0)){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(0, 1);
					mi[2] = temp.getPixel(1, 0);
					mi[3] = temp.getPixel(1, 1);
					count = 4;
				}
				else if ((i == 0)){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(j - 1, i);
					mi[2] = temp.getPixel(j, i + 1);
					mi[3] = temp.getPixel(j + 1, i);
					mi[4] = temp.getPixel(j - 1, i + 1);
					mi[5] = temp.getPixel(j + 1, i + 1);
					count = 6;
				}
				else if ((j == src.getWidth())){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(j - 1, i);
					mi[2] = temp.getPixel(j - 1, i - 1);
					mi[3] = temp.getPixel(j, i - 1);
					mi[4] = temp.getPixel(j - 1, i + 1);
					mi[5] = temp.getPixel(j, i + 1);
					count = 6;
				}
				else if ((i == src.getHeight())){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(j - 1, i - 1);
					mi[2] = temp.getPixel(j, i - 1);
					mi[3] = temp.getPixel(j + 1, i - 1);
					mi[4] = temp.getPixel(j - 1, i);
					mi[5] = temp.getPixel(j + 1, i);
					count = 6;
				}
				else if ((j == 0)){
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(j, i - 1);
					mi[2] = temp.getPixel(j, i + 1);
					mi[3] = temp.getPixel(j + 1, i - 1);
					mi[4] = temp.getPixel(j + 1, i);
					mi[5] = temp.getPixel(j + 1, i + 1);
					count = 6;
				}
				else{
					mi[0] = temp.getPixel(j, i);
					mi[1] = temp.getPixel(j - 1, i - 1);
					mi[2] = temp.getPixel(j, i - 1);
					mi[3] = temp.getPixel(j + 1, i - 1);
					mi[4] = temp.getPixel(j - 1, i);
					mi[5] = temp.getPixel(j + 1, i);
					mi[6] = temp.getPixel(j - 1, i + 1);
					mi[7] = temp.getPixel(j, i + 1);
					mi[8] = temp.getPixel(j + 1, i + 1);
					count = 9;
				}
				for (int k = 0; k < count; k++){
					tmp = tmp + mi[k];
				}
				tmp = tmp / count;
				src.setPixel(j, i, tmp);
			}
		}
	}

}