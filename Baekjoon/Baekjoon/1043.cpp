#include <iostream>
#include <vector>
using namespace std;

int n, m, num, gnum = 0;
vector<int> truth; // 진실을 아는 사람
vector<int> party[50]; // 파티에 참여하는 사람

// 진실을 아는 사람과 같은 그룹인지 확인하는 함수
bool check(int pnum, vector<int> &belonged) {
	for (int i = 0; i < truth.size(); i++) {
		if (belonged[pnum] == belonged[truth[i]])
			return true;
	}
	return false;
}

int main() {
	cin >> n >> m >> num;
	vector<int> belonged(n + 1, -1); // n번째 사람이 속하는 그룹

	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		truth.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		int obj; // 파티에 참여하는 첫번째 사람
		cin >> num;
		if (num) { // 파티에 1명 이상 참여할 경우
			cin >> obj;
			party[i].push_back(obj); // i번째 파티에 obj번째 사람 참가
			if (belonged[obj] == -1) // 첫번째 참여자가 그룹에 속하지 않을 경우 그룹 생성, 소속
				belonged[obj] = gnum++;
		}
		for (int j = 1; j < num; j++) { // i번째 파티에 참여하는 나머지 사람에 대하여 그룹이 없을 경우 첫번째 참가자와 같은 그룹에 소속, 그룹이 있을 경우 해당 그룹원 모두 첫번째 참가자와 같은 그룹으로 변경
			int temp;
			cin >> temp;
			party[i].push_back(temp);
			if (belonged[temp] == -1)
				belonged[temp] = belonged[obj];
			else {
				int target = belonged[temp];
				for (int i = 1; i <= n; i++) {
					if (belonged[i] == target)
						belonged[i] = belonged[obj];
				}
			}
		}
	}
	int cnt = 0; // 진실을 아는 사람이 없는 파티의 수

	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= party[i].size(); j++) {
			if (j == party[i].size()) { // 각 파티마다 진실을 아는 사람이 한명도 없을 경우 cnt++
				cnt++;
				break;
			}
			int pnum = party[i][j];
			if (check(pnum, belonged)) 
				break;
		}
	}
	cout << cnt << '\n';

	return 0;
}