#include "stdafx.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <math.h>
#include <set>

bool is_pentnum(int x) {

	//	Test if parameter "x" is a pentagonal number.

	//	http://www.divye.in/2012/07/how-do-you-determine-if-number-n-is.html

	float testval = (float)(sqrt(24.0f*(float)(x)+1.0f) + 1.0f) / 6.0f;
	return (((testval - trunc(testval)) == 0.0) ? true : false);
};

int main() {

	int i = 2, j;
	int ptNum1 = 0, ptNum2 = 0, ptNumSum = 0, ptNumDiff = 0;
	bool first = true;

	bool notFound = true;

	auto startTime = std::chrono::high_resolution_clock::now();

	while (notFound) {
		i++;
		ptNum1 = i * ((3 * i) - 1) / 2;

		for (j = (i - 1); j > 0; j--) {
			ptNum2 = j * ((3 * j) - 1) / 2;
			if (is_pentnum(ptNum1 - ptNum2) && is_pentnum(ptNum1 + ptNum2)) {
				ptNumSum = ptNum1 + ptNum2;
				ptNumDiff = ptNum1 - ptNum2;
				notFound = false;
				break;
			}
		}
	}

	std::cout << std::boolalpha;

	//	For std::cout, format the boolean values as "true" or "false":

	auto endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeDifference = endTime - startTime;


	std::cout << "\n\tLoop solution for Euler Project #44: pentagonal numbers: ";
	std::cout << "\n\n";
	std::cout << "\ti = " << i << " --> pentNum(i) = pentNum(" << i << ") = ";
	std::cout << ptNum1 << "\n";
	std::cout << "\tj = " << j << " --> pentNum(j) = pentNum(" << j << ") = ";
	std::cout << ptNum2 << "\n\n";

	std::cout << "\t\t\t\t     pentNumSum =\n";
	std::cout << "\t\t  pentNum(" << i << ") + pentNum(" << j << ") =\n";
	std::cout << "\t\t\t      " << ptNum1 << " + " << ptNum2 << " = ";
	std::cout << (ptNum1 + ptNum2) << "\n\n";

	std::cout << "\t\t" << (ptNum1 + ptNum2) << " is a pentagonal number: ";
	std::cout << is_pentnum(ptNum1 + ptNum2) << "\n\n";

	std::cout << "\t______________________________________________\n";
	std::cout << "\t______________________________________________\n\n\n";

	std::cout << "\t\t\t\t    pentNumDiff =\n";
	std::cout << "\t\t  pentNum(" << i << ") - pentNum(" << j << ") =\n";
	std::cout << "\t\t\t      " << ptNum1 << " - " << ptNum2 << " = ";
	std::cout << (ptNum1 - ptNum2) << "\n\n";

	std::cout << "\t\t" << (ptNum1 - ptNum2) << " is a pentagonal number: ";
	std::cout << is_pentnum(ptNum1 - ptNum2) << "\n\n";

	std::cout << "\n\tCalculation Time = " << timeDifference.count();
	std::cout << " seconds\n\n";
}