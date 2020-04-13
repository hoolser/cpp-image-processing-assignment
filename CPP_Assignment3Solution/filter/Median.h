#ifndef _MEDIAN
#define _MEDIAN

#include "Filter.h"
#include <algorithm>

namespace imaging
{
	class Median : public Filter {
	public:
		Median() {};
		~Median() {};

		virtual void filtration(Image &src);
	};
}
#endif