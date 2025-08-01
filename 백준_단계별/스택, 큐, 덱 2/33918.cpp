#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// ����� ���� ����
const long long INF = -1e18;

int main() 
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M, C, D;
	cin >> N >> M >> C >> D;

	vector<int> b(N);
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}

	// dp_prev[k]: ���� �ð�(t-1)�� �µ��� k�� ������ ���� �ִ� ��
	vector<long long> dp_prev(M + 1);

	// �⺻ �ܰ�: t = 0
	// �ð� 0������ �µ��� �����Ӱ� ���� ����
	for (int k = 1; k <= M; ++k) {
		dp_prev[k] = (long long)M - abs(b[0] - k);
	}

	// dp_curr[k]: ���� �ð�(t)�� �µ��� k�� ������ ���� �ִ� ��
	vector<long long> dp_curr(M + 1);

	// �µ� ��ȭ��(D)�� C�� ���� ��. �����̵� �������� �ݰ����� ����.
	int W = D / C;

	// ���� ���α׷���: �ð� t = 1���� N-1���� �ݺ�
	for (int t = 1; t < N; ++t) {
		// ���� �ð��� dp ���̺��� INF�� �ʱ�ȭ
		fill(dp_curr.begin(), dp_curr.end(), INF);

		// �µ��� C�� ���� �������� ���� ������ �����Ͽ� �ذ�
		for (int r = 0; r < C; ++r) {
			// �������� r�� �µ����� ������. r=0�� ��� C���� ����
			int start_temp = (r == 0) ? C : r;
			if (start_temp > M) continue;

			// �������� r�� �µ���� �׿� �ش��ϴ� ���� �ð��� dp���� ����
			vector<long long> vals;  // dp_prev ����
			vector<int> temps;       // �µ� k ����
			for (int k = start_temp; k <= M; k += C) {
				vals.push_back(dp_prev[k]);
				temps.push_back(k);
			}

			if (vals.empty()) continue;

			int num_vals = vals.size();
			vector<long long> L(num_vals), R(num_vals);
			deque<int> dq;  // vals ������ �ε����� ����

			// ������ �н�: L[j] = max(vals[j-W], ..., vals[j]) ���
			for (int j = 0; j < num_vals; ++j) {
				if (!dq.empty() && dq.front() < j - W) {
					dq.pop_front();
				}
				while (!dq.empty() && vals[dq.back()] <= vals[j]) {
					dq.pop_back();
				}
				dq.push_back(j);
				L[j] = vals[dq.front()];
			}

			dq.clear();

			// ������ �н�: R[j] = max(vals[j], ..., vals[j+W]) ���
			for (int j = num_vals - 1; j >= 0; --j) {
				if (!dq.empty() && dq.front() > j + W) {
					dq.pop_front();
				}
				while (!dq.empty() && vals[dq.back()] <= vals[j]) {
					dq.pop_back();
				}
				dq.push_back(j);
				R[j] = vals[dq.front()];
			}

			// L�� R�� �����Ͽ� �߽� ������ [j-W, j+W]�� �ִ��� ã�� dp_curr ����
			for (int j = 0; j < num_vals; ++j) {
				// max_prev_taste = max( L[j], R[j] ) = max( max(v[j-W..j]), max(v[j..j+W]) ) = max(v[j-W..j+W])
				long long max_prev_taste = max(L[j], R[j]);

				// ���� ���°� ���� ������ ��쿡�� ����
				if (max_prev_taste > INF + 1) {
					int current_temp = temps[j];
					long long current_gain = (long long)M - abs(b[t] - current_temp);
					dp_curr[current_temp] = current_gain + max_prev_taste;
				}
			}
		}
		// ���� �ð��� ����� ������ dp_prev�� dp_curr�� ����
		dp_prev = dp_curr;
	}

	// ���� ���: �ð� N-1������ ��� ������ �µ��� dp �� �� �ִ�
	long long max_total_taste = 0;  // ���� ������ �� �� �����Ƿ� 0���� �ʱ�ȭ
	for (int k = 1; k <= M; ++k) {
		max_total_taste = max(max_total_taste, dp_prev[k]);
	}

	cout << max_total_taste << endl;

	return 0;
}