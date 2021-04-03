#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A, B, V, day;

	cin >> A >> B >> V;
	day = ceil((V - A) / (double)(A - B));

	
	if (day * (A - B) + A >= V)
		cout << day + 1 << endl;

	return 0;
}