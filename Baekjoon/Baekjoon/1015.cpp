#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[50], N, minimum;
vector<pair<int, int>> resized;

void sort(vector<pair<int, int>> vec) {
	pair<int, int> temp;
	int index;
	for (int i = 0; i < N; i++) {
		index = i;
		minimum = vec[i].first;
		for (int j = i + 1; j < N; j++) {
			if (minimum == vec[j].first) {
				if (vec[index].second > vec[j].second) {
					index = j;
					minimum = vec[j].first;
				}
			}
			if (minimum > vec[j].first) {				
				index = j;
				minimum = vec[j].first;
			}
		}
		temp = vec[i];
		vec[i] = vec[index];
		vec[index] = temp;

		resized.push_back(vec[i]);
	}
}

int main() {
	pair<int, int> p;
	vector<pair<int, int>> vec;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		vec.push_back(make_pair(arr[i], i));
	}

	sort(vec);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (resized[j].second == i) {
				cout << j << ' ';
			}
		}
	}
	return 0;
}