#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs(int start, int target) {
    set<int> visited;
    queue<pair<int, vector<pair<int, int>>>> q;
    q.push({start, {}});

    while (!q.empty()) {
        int current = q.front().first;
        vector<pair<int, int>> jumps = q.front().second;
        q.pop();

        if (current == target) {
            cout << jumps.size() << endl;
            for (const auto &jump : jumps) {
                cout << jump.first << " " << jump.second << endl;
            }
            return 0;
        }

        if (visited.count(current)) {
            continue;
        }

        visited.insert(current);

        for (int i = 1; i <= 15; ++i) {
            if (current & (1 << i)) {
                for (int j = i + 1; j <= 15; ++j) {
                    if (current & (1 << j) && !(current & (1 << (i + j)))) {
                        int next_state = current ^ (1 << i) ^ (1 << j);
                        vector<pair<int, int>> next_jumps = jumps;
                        next_jumps.push_back({i, j});
                        q.push({next_state, next_jumps});
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}

int main() {
    int initial_state;
    cin >> initial_state;

    int target_state = (1 << 16) - 1;
    bfs(initial_state, target_state);

    return 0;
}
