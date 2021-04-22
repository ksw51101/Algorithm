#include <iostream>
#define M 100001
using namespace std;

int n, m, team[M];

int check_team(int s) {
	if (team[s] = s)
		return s;
	else
		return team[s] = check_team(team[s]);
}

void uni(int s1, int s2) {
	s1 = check_team(s1);
	s2 = check_team(s2);
	if (s1 > s2)
		team[s1] = s2;
	else
		team[s2] = s1;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		team[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) 
			uni(b, c);
		else {
			if (check_team(b) == check_team(c))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}