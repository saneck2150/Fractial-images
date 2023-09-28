#include <complex>
#include "MandelbrotClass.h"

using namespace std;

int FractialImages::MandelbrotClass::getIterations(double x, double y) // algorythm was taken from Google search
{
	complex<double> z = 0;
	complex<double> c(x, y);
	int iterations = 0;

	while (iterations < MAX_ITERATIONS)
	{
		z = z * z + c;

		if (abs(z) > 2) break;
		iterations++;
	}
	return iterations;
}
