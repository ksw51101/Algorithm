#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, a, b, p, q;

// 최대공약수 구하는 함수
int get_gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

// node에 num이 있으면 그 값을 반환하는 함수
int check(vector<pair<int, int>>* node, int num) {
	for (int i = 0; i < node->size(); i++) {
		if ((*node)[i].first == num)
			return (*node)[i].second;
	}
	return -1;
}

// node의 모든 값에 num을 곱하는 함수
void change(vector<pair<int, int>>* node, int num) {
	for (int i = 0; i < node->size(); i++) {
		(*node)[i].second *= num;
	}
}

// node에 num을 오름차순에 맞춰 삽입하는 함수
void insert(vector<pair<int, int>>* node, pair<int, int> num) {
	if (node->empty()) {
		node->push_back(num);
		return;
	}
	for (int i = 0; i < node->size(); i++) {
		if ((*node)[i].first > num.first) {
			node->insert(node->begin() + i, num);
			return;
		}
	}
	node->push_back(num);
}

// node b를 node a에 포함시키는 함수
void linking(vector<pair<int, int>>* a, vector<pair<int, int>>* b) {
	for (int i = 0; i < b->size(); i++) {
		insert(a, (*b)[i]);
	}
	delete b;
}

int main() {
	cin >> n;

	vector<vector<pair<int, int>>*> vec;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> p >> q;
		if (vec.empty()) {
			vector<pair<int, int>>* node = new vector<pair<int, int>>;
			insert(node, { a, p });
			insert(node, { b, q });
			vec.push_back(node);
		}
		else {
			int first = -1, second = -1;
			for (int j = 0; j < vec.size(); j++) {
				if (first == -1 && check(vec[j], a) != -1)
					first = j;
				if (second == -1 && check(vec[j], b) != -1)
					second = j;
			}
			if (first == -1) {
				if (second == -1) { // 입력받은 두 수 a, b가 어디에도 포함되지 않을 경우
					vector<pair<int, int>>* node = new vector<pair<int, int>>;
					insert(node, { a, p });
					insert(node, { b, q });
					vec.push_back(node);
				}
				else { // a는 포함되어 있지 않고 b는 포함된 경우
					p *= check(vec[second], b);
					change(vec[second], q);
					insert(vec[second], { a, p });
				}
			}
			else { 
				if (second == -1) { // a는 포함되고 b는 포함되지 않은 경우
					q *= check(vec[first], a);
					change(vec[first], p);
					insert(vec[first], { b, q });
				}
				else { // a, b 둘 다 포함된 경우
					q *= check(vec[first], a);
					change(vec[first], p);
					change(vec[first], check(vec[second], b));
					change(vec[second], q);
					linking(vec[first], vec[second]);
					vec.erase(vec.begin() + second);
				}
			}
		}
	}
	
	// 최대공약수로 나누어서 문제의 조건을 맞춤
	int gcd = 0;
	for (int i = 0; i < vec[0]->size(); i++) {
		gcd = get_gcd(gcd, (*vec[0])[i].second);
	}

	for (int i = 0; i < vec[0]->size(); i++) {
		(*vec[0])[i].second /= gcd;
		cout << (*vec[0])[i].second << ' ';
	}

	return 0;
}