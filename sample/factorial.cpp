#include "vuint.hpp"
#include <iostream>
#include <cstdlib>

static const int iterations = 100;

int main(int argc, char * argv[])
{
	vuint<1024> factorial = 1;

	std::cout << "Calculating..." << std::endl;

	for (int i = 2; i < iterations; i++)
		factorial *= i;

	std::cout << "Factorial (" << iterations << ") = " << factorial << std::endl;

	system("PAUSE");

	return 0;
}