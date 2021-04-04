#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt = 0;
vector<pair<int, int>> connect;
vector<int> LIS;

void start(int crossed) {
	for (int i = 0; i < connect.size(); i++) {
		if (LIS.size() == 0) {
			LIS.push_back(connect[i].second);
			cnt++;
		}
		else {
			if (connect[i].second > LIS.back()) {
				LIS.push_back(connect[i].second);
				cnt++;
			}
			else 
				LIS[lower_bound(LIS.begin(), LIS.end(), connect[i].second) - LIS.begin()] = connect[i].second;
			
		}
	}

}

int main() {
	int A, B;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A >> B;
		connect.push_back(make_pair(A, B));
	}
	sort(connect.begin(), connect.end());

	start(0);

	cout << n - cnt << '\n';

	return 0;
}