#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
vector<string> vec;
ll ans;
vector<pair<int, ll>> arr; // 알파벳의 기여도 변수(A~J)

bool compare(pair<int, ll> a, pair<int, ll> b) {
	return a.second < b.second;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.emplace_back(temp);
	}

	for (int i = 0; i < 10; i++) {
		arr.emplace_back(i, 0); // 알파벳의 기여도를 0으로 초기화
	}

	bool first[10] = { false, }; // 첫번째 자리에 나오는 알파벳 체크
	for (const auto& number : vec) {
		first[number[0] - 'A'] = true;
		for (int i = 0; i < number.size(); i++) {
			arr[number[i] - 'A'].second += pow(10, number.size() - i - 1); // 알파벳의 기여도 갱신
		}
	}
	sort(arr.begin(), arr.end(), compare); // 기여도를 기준으로 오름차순 정렬

	int index = 0;
	for (int i = 0; i < 10; i++) {
		if (!first[arr[i].first]) { // 기여도가 낮은 알파벳부터 시작해 첫 번째 글자로 나오지 않은 알파벳의 index 저장
			index = i;
			break;
		}
	}

	int k = 1; // 기여도가 낮은 알파벳에 낮은 숫자부터 부여
	for (int i = 0; i < 10; i++) {
		if (index == i) // 첫 번째 글자로 나오지 않았고 기여도가 가장 낮은 알파벳에 0 부여
			continue;
		ans += arr[i].second * k++;
	}

	cout << ans << '\n';

	return 0;
}