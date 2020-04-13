#ifndef _COLOR
#define _COLOR

#include "Filter.h"

namespace imaging
{
	class Color : public Filter {
	private:
		Vec3<float> col;
	public:
		// constructors
		Color() :col(Vec3<float>()){}
		Color(float r, float g, float b) :col(Vec3<float>(r, g, b)){}
		Color(Vec3<float> val) :col(val){}
		~Color() {};

		virtual void filtration(Image &src);
	};
}
#endif