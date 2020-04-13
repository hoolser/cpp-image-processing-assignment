#ifndef _DIFF
#define _DIFF

#include "Filter.h"
#include <algorithm>

namespace imaging
{
	class Diff : public Filter {
	public:
		Diff() {};
		~Diff() {};

		virtual void filtration(Image &src);
	};
}
#endif