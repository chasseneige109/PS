#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m;
int dist[101][101];
int via[101][101];

void print_path(int s, int e, vector<int>& path) {
    if (via[s][e] == 0) {
        path.push_back(s);
        if (s != e) path.push_back(e);
    }
    else {
        int mid = via[s][e];
        print_path(s, mid, path);
        path.pop_back(); // �߰� ��� �ߺ� ����
        print_path(mid, e, path);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // �Ÿ� �ʱ�ȭ
    for (int i = 1; i <= n; i++)
        fill(dist[i], dist[i] + n + 1, INF);

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    // ���� �Է�
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < dist[a][b]) {
            dist[a][b] = c;
        }
    }

    // �÷��̵�-����
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = k;
                }
            }

    // �Ÿ� ���
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    // ��� ���
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF || i == j) {
                cout << 0 << "\n";
            }
            else {
                vector<int> path;
                print_path(i, j, path);
                cout << path.size() << " ";
                for (int x : path) cout << x << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}
