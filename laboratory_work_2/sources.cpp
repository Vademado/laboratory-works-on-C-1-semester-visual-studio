#include "sources.hpp"

void laba()
{
	for (float eps = 1e-2; eps > 1e-7; eps /= 10)
	{
		int quantity_iteration = 1;
		float x = 1;
		float lim = sin(x) / x;
		double a = 1 - lim;
		while (fabs(1 - lim) >= eps)
		{
			quantity_iteration++;
			x /= 2;
			lim = sin(x) / x;
			std::cout << fabs(1 - lim) << "   " << eps << std::endl;
		}
		std::cout << "Error rate eps=" << eps << " number of iterations:" << quantity_iteration << std::endl;
	}
}