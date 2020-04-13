#include "Color.h"

namespace imaging
{
	void Color::filtration(Image &src){
		Vec3<float> temp;
		for (int i = 0; i < src.getHeight(); i++){
			for (int j = 0; j < src.getWidth(); j++){
				temp = Vec3<float>((src.getPixel(j, i)).r, (src.getPixel(j, i)).g, (src.getPixel(j, i)).b);
				temp = temp*col;
				src.setPixel(j, i, temp);
			}
		}
	}

}