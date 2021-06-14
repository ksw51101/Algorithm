#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, a, b, p, q;

// �ִ����� ���ϴ� �Լ�
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

// node�� num�� ������ �� ���� ��ȯ�ϴ� �Լ�
int check(vector<pair<int, int>>* node, int num) {
	for (int i = 0; i < node->size(); i++) {
		if ((*node)[i].first == num)
			return (*node)[i].second;
	}
	return -1;
}

// node�� ��� ���� num�� ���ϴ� �Լ�
void change(vector<pair<int, int>>* node, int num) {
	for (int i = 0; i < node->size(); i++) {
		(*node)[i].second *= num;
	}
}

// node�� num�� ���������� ���� �����ϴ� �Լ�
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

// node b�� node a�� ���Խ�Ű�� �Լ�
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
				if (second == -1) { // �Է¹��� �� �� a, b�� ��𿡵� ���Ե��� ���� ���
					vector<pair<int, int>>* node = new vector<pair<int, int>>;
					insert(node, { a, p });
					insert(node, { b, q });
					vec.push_back(node);
				}
				else { // a�� ���ԵǾ� ���� �ʰ� b�� ���Ե� ���
					p *= check(vec[second], b);
					change(vec[second], q);
					insert(vec[second], { a, p });
				}
			}
			else { 
				if (second == -1) { // a�� ���Եǰ� b�� ���Ե��� ���� ���
					q *= check(vec[first], a);
					change(vec[first], p);
					insert(vec[first], { b, q });
				}
				else { // a, b �� �� ���Ե� ���
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
	
	// �ִ������� ����� ������ ������ ����
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