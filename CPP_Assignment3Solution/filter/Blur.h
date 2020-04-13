#ifndef _BLUR
#define _BLUR

#include "Filter.h"

namespace imaging
{
	class Blur : public Filter {
	public:
		Blur() {};
		~Blur() {};

		virtual void filtration(Image &src);
	};
}
#endif