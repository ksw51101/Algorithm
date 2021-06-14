#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, p, q;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

struct Node {
	int data, num;
	Node* next, * prev;
	Node() {
		next = prev = NULL;
		data = num = 0;
	}
	Node(int n, int d, Node* ptr)
	{
		num = n;
		data = d;
		prev = ptr;
		next = ptr->next;
		next->prev = prev->next = this;
	}
	void selvDelete() {
		prev->next = next;
		next->prev = prev;
		delete this;
	}
};

struct LinkedList {
	Node* head;
	Node* tail;
	LinkedList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
	~LinkedList() {
		while (head->next != tail) {
			head->next->selvDelete();
		}
		delete head;
		delete tail;
	}
	void insert(int n, int d) {
		Node* cur = head;
		while (cur->next) {
			cur = cur->next;
			if (cur == tail || cur->num > n) {
				new Node(n, d, cur->prev);
				break;
			}
		}
	}
	void linking(LinkedList* DL) {
		tail->prev->next = DL->head->next;
		tail->prev = DL->tail->prev;
		tail->prev->next = tail;
		delete DL->head;
		delete DL->tail;
	}
	void change(int n) {
		Node* cur = head;
		while (cur->next != tail) {
			cur = cur->next;
			cur->data *= n;
		}
	}
	int check(int num) {
		Node* cur = head;
		while (cur->next) {
			cur = cur->next;
			if (cur->num == num)
				return cur->data;
		}
		return -1;
	}
	void printAll() {
		Node* cur = head;
		while (cur->next != tail) {
			cur = cur->next;
			cout << cur->data << ' ';
		}
	}
	void divide_gcd() {
		int temp = 0;
		Node* cur = head;
		while (cur->next != tail) {
			cur = cur->next;
			temp = gcd(temp, cur->data);
		}
		cur = head;
		while (cur->next != tail) {
			cur = cur->next;
			cur->data /= temp;
		}
	}
};


int main() {
	cin >> n;
	vector<LinkedList*> vec;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> p >> q;
		if (vec.empty()) {
			LinkedList* list = new LinkedList();
			list->insert(a, p);
			list->insert(b, q);
			vec.push_back(list);
		}
		else {
			int first = -1, second = -1;
			for (int j = 0; j < vec.size(); j++) {
				if (first == -1 && vec[j]->check(a) != -1)
					first = j;
				if (second == -1 && vec[j]->check(b) != -1)
					second = j;
			}
			if (first == -1) {
				if (second == -1) {
					LinkedList* list = new LinkedList();
					list->insert(a, p);
					list->insert(b, q);
					vec.push_back(list);
				}
				else {
					p *= vec[second]->check(b);
					vec[second]->change(q);
					vec[second]->insert(a, p);
				}
			}
			else {
				if (second == -1) {
					q *= vec[first]->check(a);
					vec[first]->change(p);
					vec[first]->insert(b, q);
				}
				else {
					q *= vec[first]->check(a);
					vec[first]->change(p);
					vec[second]->change(q);
					vec[first]->linking(vec[second]);
					vec.erase(vec.begin() + second);
				}
			}
		}
	}
	vec[0]->divide_gcd();
	vec[0]->printAll();

	return 0;
}