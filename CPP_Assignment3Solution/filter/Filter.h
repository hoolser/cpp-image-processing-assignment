//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2014
//
//
//-------------------------------------------------------------

#ifndef _FILTER
#define _FILTER

#include "Image.h"

namespace imaging
{
	class Filter
	{
		// ��������� �� ������ ����� ��� ��������
	public:

		Filter() {};
		virtual ~Filter() {};
		virtual void filtration(Image &src) = 0;
	};

}
#endif