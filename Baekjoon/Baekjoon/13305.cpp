#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, len[100000], pr,  index;
long long sum = 0, len_sum = 0;
vector<pair<int, int>> price;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++)
		cin >> len[i];

	for (int i = 0; i < n; i++) {
		cin >> pr;
		price.push_back(make_pair(pr, i));
	}
	sort(price.begin(), price.end(), compare);

	index = price[0].second;
	for (int i = index; i < n - 1; i++)
		len_sum += len[i];
	sum += len_sum * price[0].first;

	for (int i = 1; i < price.size(); i++) {
		len_sum = 0;
		if (price[i].second > index)
			continue;
		else {
			for (int j = price[i].second; j < index; j++)
				len_sum += len[j];
			sum += len_sum * price[i].first;
			index = price[i].second;
		}
	}


	cout << sum << '\n';


	return 0;
}