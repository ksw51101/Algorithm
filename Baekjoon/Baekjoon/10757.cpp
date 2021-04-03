#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B, answer, temp;
	int add;
	bool over = false;

	cin >> A >> B;

	for (int i = 0; i < max(A.length(), B.length()); i++) {
		if ((int)A.length() - i - 1 >= 0 && (int)B.length() - i - 1 >= 0)
			add = A[A.length() - i - 1] - '0' + B[B.length() - i - 1] - '0' + over;
		else if (A.length() > B.length())
			add = A[A.length() - i - 1] - '0' + over;
		else
			add = B[B.length() - i - 1] - '0' + over;

		if (add >= 10) {
			over = true;
			add -= 10;
		}
		else
			over = false;
		answer = to_string(add) + answer;
		if(i == max(A.length(), B.length()) - 1)
			if(over == true)
				answer = "1" + answer;

	}
	cout << answer << endl;

	return 0;
}