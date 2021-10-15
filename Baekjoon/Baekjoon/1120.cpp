#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int len;

// 두 문자열 s1, s2의 차이를 구하는 함수
int check(string s1, string s2) {
	int cnt = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i])
			cnt++;
	}
	return cnt;
}
 
int main() {
	cin >> A >> B;
	len = B.size() - A.size(); // 두 문자열의 길이의 차이
	
	int minimum = 50;
	for (int i = 0; i <= len; i++) {
		string temp = B.substr(i, A.size()); // temp : B의 i번째 문자부터 A의 길이만큼 자른 문자열
		minimum = min(minimum, check(temp, A)); // 차이의 최솟값을 저장
	}
	cout << minimum << '\n'; // 나머지는 알맞은 알파벳을 앞뒤로 추가하면 구한 minimum이 최소 차이가 됨

	return 0;
}