#include "Gray.h"

namespace imaging
{
	void Gray::filtration(Image &src){
		float mi = 0;
		for (int i = 0; i < src.getHeight(); i++){
			for (int j = 0; j < src.getWidth(); j++){
				mi = ((src.getPixel(j, i)).r + (src.getPixel(j, i)).g + (src.getPixel(j, i)).b) / 3;
				src.setPixel(j, i, Vec3<float>(mi, mi, mi));
			}
		}
	}

}