#ifndef _GRAY
#define _GRAY

#include "Filter.h"

namespace imaging
{
	class Gray : public Filter {
	public:
		Gray() {};
		~Gray() {};

		virtual void filtration(Image &src);
	};
}
#endif