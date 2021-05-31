#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> vec;

int main() {
	cin >> n>>c;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	// �̺�Ž���� ���� vector ����
	sort(vec.begin(), vec.end());

	int start = 1; // ���� ��ġ�� ���� �����Ƿ� ������ �ּ� �Ÿ��� 1
	int end = vec.back() - vec.front(); // �ִ� �Ÿ��� ������ ���� ù��° ������ �Ÿ�
	int ans = 0;

	while (start<=end) {
		int mid = (start + end) / 2; // �� �������� �ּҰŸ�
		int now = vec[0]; // ���������� �����Ⱑ ��ġ�� ���� ��ġ(ù��° ���� ��ġ�Ǿ� �ִٰ� ����)
		int cnt = 1; // ��ġ�� �������� ����

		for (int i = 1; i < vec.size(); i++) {
			if (vec[i] < now + mid) continue; // ���������� �����Ⱑ ��ġ�� ������ �Ÿ��� �ּҰŸ����� ���� ��� continue
			now = vec[i];
			cnt++;
		}
		if (cnt < c) // c���� �����Ⱑ ��ġ���� ���ߴٸ� �ּҰŸ��� �ٿ� �ٽ� �õ�
			end = mid - 1;
		else { // c�� �̻��� �����Ⱑ ��ġ�Ǿ��ٸ� �ּҰŸ��� �÷� �õ�
			start = mid + 1;
			ans = mid;
		}
	}
	cout << ans << '\n';

	return 0;
}
