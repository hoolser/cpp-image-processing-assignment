#ifndef _IMAGE
#define _IMAGE


#include "Vec3.h"
#include "Array.h"
#include "Serializable.h"
using namespace math;

namespace imaging
{

	class Image :public Array<Vec3<float>>, public Serializable{
	public:

		// constructors and destructor
		Image();											     // default: zero dimensions, nullptr for the buffer.	
		Image(unsigned int width, unsigned int height);
		Image(unsigned int width, unsigned int height, const Vec3<float> * data_ptr);
		Image(const Image &src);
		~Image();

		Vec3<float> getPixel(unsigned int x, unsigned int y) const;    // get the color of the image at location (x,y)
		// Do any necessary bound checking. Also take into account
		// the "interleaved" flag to fetch the appropriate data
		// Return a black (0,0,0) color in case of an out-of-bounds
		// x,y pair

		void setPixel(unsigned int x, unsigned int y, Vec3<float> & value);
		// Set the RGB values for an (x,y) pixel. Do all 
		// necessary bound checks and respect the "interleaved"
		// flag when updating our data.

		void setData(const Vec3<float> * & data_ptr);            // Copy the data from data_ptr to the internal buffer.
		// The function ASSUMES a proper size for the incomming data array.

		virtual bool operator << (std::string filename);     // Read the contents of an object from the specified file
		virtual bool operator >> (std::string filename);
	};



}
#endif