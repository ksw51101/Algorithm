#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k, ans;
bool visit[26], flag[26]; // visit : 모든 단어를 읽기 위해 배워야 하는 글자를 true로 갖는 배열, flag : k개의 글자를 배웠을 때 k개의 true를 갖는 배열
vector<string> vec;

// k개의 글자를 배운 상태로 몇 개의 단어를 읽을 수 있는지 return 해주는 함수
int check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= vec[i].size(); j++) {
			if (j == vec[i].size())
				cnt++;
			if (!flag[vec[i][j] - 'a'])
				break;
		}
	}
	return cnt;
}

// 배워야 하는 글자 중 k개를 DFS로 선택하는 함수 (배운 글자보다 이전 index를 갖는 글자는 살펴볼 필요가 없으므로 index 사용)
void DFS(int cnt, int index) {
	if (cnt == k) { // k개의 글자를 배웠을 경우 읽을 수 있는 단어의 최댓값 ans를 갱신
		ans = max(ans, check());
		return;
	}
	for (int i = index; i < 26; i++) { // 26개의 글자 중 배워야 하는 글자를 k개 선택
		if (visit[i] && !flag[i]) { // 해당 index의 글자가 배워야 하는 글자면서 a, c, i, n, t가 아닌 경우
			flag[i] = true;
			DFS(cnt + 1, i + 1);
			flag[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;

	fill(&visit[0], &visit[26], false);
	fill(&flag[0], &flag[26], false);
	flag[0] = flag[2] = flag[8] = flag[13] = flag[19] = true; // 모든 단어가 "anta"로 시작하고 "tica"로 끝나므로 a, c, i, n, t를 먼저 배움

	int cnt = 0; // 모든 단어를 읽기 위해 배워야 하는 글자의 개수
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
		for (int j = 0; j < temp.size(); j++)
			if (!visit[temp[j] - 'a']) { // 단어를 읽기 위해 필요한 글자의 index를 true로 변경
				visit[temp[j] - 'a'] = true;
				cnt++;
			}
	}

	if (cnt <= k) // 모든 단어를 읽기 위해 필요한 글자의 수보다 배울 수 있는 글자가 많을 경우 정답은 n
		ans = n;
	else if (k < 5) // 모든 단어에 들어가는 5개의 글자 a, c, i, n, t를 배울 수 없다면 정답은 0
		ans = 0;
	else 
		DFS(5, 0); // DFS 시작

	cout << ans << '\n';

	return 0;
}