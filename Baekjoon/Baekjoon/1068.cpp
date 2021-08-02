#include <iostream>
#include <vector>
using namespace std;

int n, d, cnt;
vector<int> parent; // 부모 노드 저장
vector<bool> live; // 제거 여부 저장

// 처음 입력받은 num부터 트리를 거슬러 올라가 target이 있을 경우 true를 return하는 함수
bool find_target(int num, int target) {
	if (parent[num] == -1)
		return false;
	else if (parent[num] == target)
		return true;
	return find_target(parent[num], target);
}

// num을 포함한 하위의 노드를 제거하는 함수
void delete_node(int num) {
	live[num] = false;
	for (int i = 0; i < n; i++) {
		if (find_target(i, num))
			live[i] = false;
	}
}

// leaf 노드를 count하는 함수
void find_leaf() {
	vector<bool> node = live;
	for (int i = 0; i < n; i++) {
		if (!live[i])
			continue;
		int p = parent[i];
		if (p == -1)
			continue;
		node[p] = false;
	}
	for (int i = 0; i < n; i++)
		if (node[i])
			cnt++;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		parent.push_back(temp);
		live.push_back(true);
	}
	cin >> d;

	delete_node(d);
	find_leaf();

	cout << cnt << '\n';

	return 0;
}