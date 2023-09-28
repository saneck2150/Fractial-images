#pragma once

namespace FractialImages
{
	class MandelbrotClass
	{
	public:

		static const int MAX_ITERATIONS = 100;

		MandelbrotClass();
		~MandelbrotClass();

		static int getIterations(double x, double y);
	};
}


