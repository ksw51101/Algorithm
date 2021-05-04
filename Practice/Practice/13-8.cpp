#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class node {
public:
    int pos1_X;
    int pos1_Y;
    int pos2_X;
    int pos2_Y;

    node(int pos1_X, int pos1_Y, int pos2_X, int pos2_Y) {
        this->pos1_X = pos1_X;
        this->pos1_Y = pos1_Y;
        this->pos2_X = pos2_X;
        this->pos2_Y = pos2_Y;
    }
};

vector<node> get_next_pos(node now, vector<vector<int>> newboard) {
    vector<node> possible;
    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { -1, 1, 0, 0 };
    for (int i = 0; i < 4; i++) {
        int pos1_nx = now.pos1_X + dx[i];
        int pos1_ny = now.pos1_Y + dy[i];
        int pos2_nx = now.pos2_X + dx[i];
        int pos2_ny = now.pos2_Y + dy[i];
        if (newboard[pos1_nx][pos1_ny] == 0 && newboard[pos2_nx][pos2_ny] == 0)
            possible.push_back(node(pos1_nx, pos1_ny, pos2_nx, pos2_ny));
    }
    if (now.pos1_X == now.pos2_X) {
        if (newboard[now.pos1_X - 1][now.pos1_Y] == 0 && newboard[now.pos2_X - 1][now.pos1_Y] == 0) {
            possible.push_back(node(now.pos1_X, now.pos1_Y, now.pos1_X - 1, now.pos1_Y));
            possible.push_back(node(now.pos2_X - 1, now.pos2_Y, now.pos2_X, now.pos2_Y));
        }
        if (newboard[now.pos1_X + 1][now.pos1_Y] == 0 && newboard[now.pos2_X + 1][now.pos1_Y] == 0) {
            possible.push_back(node(now.pos1_X, now.pos1_Y, now.pos1_X + 1, now.pos1_Y));
            possible.push_back(node(now.pos2_X + 1, now.pos2_Y, now.pos2_X, now.pos2_Y));
        }
    }
    if (now.pos1_Y == now.pos2_Y) {
        if (newboard[now.pos1_X][now.pos1_Y-1] == 0 && newboard[now.pos2_X][now.pos1_Y-1] == 0) {
            possible.push_back(node(now.pos1_X, now.pos1_Y, now.pos1_X, now.pos1_Y - 1));
            possible.push_back(node(now.pos2_X, now.pos2_Y - 1, now.pos2_X, now.pos2_Y));
        }
        if (newboard[now.pos1_X][now.pos1_Y+1] == 0 && newboard[now.pos2_X][now.pos1_Y + 1] == 0) {
            possible.push_back(node(now.pos1_X, now.pos1_Y, now.pos1_X, now.pos1_Y + 1));
            possible.push_back(node(now.pos2_X, now.pos2_Y + 1, now.pos2_X, now.pos2_Y));
        }
    }
    return possible;
}

int solution(vector<vector<int>> board) {
    int n = board.size();

    vector<vector<int>> newboard(n + 2, vector<int>(n + 2, 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            newboard[i][j] = board[i - 1][j - 1];

    queue<pair<node, int>> q;
    vector<node> visited;
    node pos = node(1, 1, 1, 2);
    q.push({ pos, 0 });
    visited.push_back(pos);
    while (!q.empty()) {
        node now = q.front().first;
        int cost = q.front().second;
        q.pop();
        if ((now.pos1_X == n && now.pos1_Y == n) || (now.pos2_X == n && now.pos2_Y == n))
            return cost;
        vector<node> next_pos = get_next_pos(now, newboard);
        for (int i = 0; i < next_pos.size(); i++) {
            bool flag = true;
            node pos = next_pos[i];
            for (int j = 0; j < visited.size(); j++) {
                if (visited[j].pos1_X == pos.pos1_X && visited[j].pos1_Y == pos.pos1_Y && visited[j].pos2_X == pos.pos2_X && visited[j].pos2_Y == pos.pos2_Y) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                visited.push_back(next_pos[i]);
                q.push({ next_pos[i], cost + 1 });
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> vec;
    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    vec.push_back(a);
    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    vec.push_back(a);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    vec.push_back(a);
    a.clear();
    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    vec.push_back(a);
    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    vec.push_back(a);
    a.clear();

    cout << solution(vec) << '\n';

    return 0;
}