#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long minimum, maximum;

int main() {


	cin >> minimum >> maximum;
	long long num = 2, count = 0, ans = maximum - minimum + 1;
	vector<bool> vec(ans, false);

	while (num * num <= maximum) {
		long long sNum = 0;
		if (minimum % (num * num) != 0)
			sNum = num * num - (minimum % (num * num));
		while (sNum + minimum <= maximum) {

			if (vec[sNum] == false) {
				vec[sNum] = true;
				ans--;
			}
			sNum += num * num;
		}
		num++;
	}

	cout << ans << endl;

	return 0;
}