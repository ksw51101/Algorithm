#include <iostream>
#include <vector>
using namespace std;

int x;

// 현재 모든 막대의 길이의 합을 return하는 함수
int check(vector<int>& vec) {
	int len = 0;
	for (int i = 0; i < vec.size(); i++)
		len += vec[i];
	return len;
}

// 행동 1번(가장 작은 막대를 반으로 자르고 잘린 막대 중 하나를 제외한 모든 막대의 합을 x와 비교하여 크거나 같으면 잘린 막대 중 한개를 버린다)
void cut(vector<int>& vec) {
	int temp = vec.back() / 2;
	vec.pop_back();
	vec.push_back(temp);

	if (x > check(vec))
		vec.push_back(temp);
}

int main() {
	vector<int> vec;
	cin >> x;

	vec.push_back(64); // 64cm 막대 하나만 들고 시작

	while (check(vec) != x) // 막대의 합이 x와 같으면 반복 종료
		cut(vec);
	
	cout << vec.size() << '\n'; // 막대의 수 출력

	return 0;
}