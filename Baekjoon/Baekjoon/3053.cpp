#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double r;
	cin >> r;
	cout.precision(6);
	cout << fixed;
	cout << r * r * M_PI << endl;
	cout << 2 * r * r << endl;

	return 0;
}