#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// 충분히 작은 값값
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

	// dp_prev[k]: 이전 시각(t-1)에 온도를 k로 맞췄을 때의 최대 맛
	vector<long long> dp_prev(M + 1);

	// 기본 단계: t = 0
	// 시각 0에서는 온도를 자유롭게 설정 가능
	for (int k = 1; k <= M; ++k) {
		dp_prev[k] = (long long)M - abs(b[0] - k);
	}

	// dp_curr[k]: 현재 시각(t)에 온도를 k로 맞췄을 때의 최대 맛
	vector<long long> dp_curr(M + 1);

	// 온도 변화량(D)을 C로 나눈 값. 슬라이딩 윈도우의 반경으로 사용됨.
	int W = D / C;

	// 동적 프로그래밍: 시각 t = 1부터 N-1까지 반복
	for (int t = 1; t < N; ++t) {
		// 현재 시각의 dp 테이블을 INF로 초기화
		fill(dp_curr.begin(), dp_curr.end(), INF);

		// 온도를 C로 나눈 나머지에 따라 문제를 분할하여 해결
		for (int r = 0; r < C; ++r) {
			// 나머지가 r인 온도들의 시작점. r=0일 경우 C부터 시작
			int start_temp = (r == 0) ? C : r;
			if (start_temp > M) continue;

			// 나머지가 r인 온도들과 그에 해당하는 이전 시각의 dp값을 저장
			vector<long long> vals;  // dp_prev 값들
			vector<int> temps;       // 온도 k 값들
			for (int k = start_temp; k <= M; k += C) {
				vals.push_back(dp_prev[k]);
				temps.push_back(k);
			}

			if (vals.empty()) continue;

			int num_vals = vals.size();
			vector<long long> L(num_vals), R(num_vals);
			deque<int> dq;  // vals 벡터의 인덱스를 저장

			// 정방향 패스: L[j] = max(vals[j-W], ..., vals[j]) 계산
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

			// 역방향 패스: R[j] = max(vals[j], ..., vals[j+W]) 계산
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

			// L과 R을 결합하여 중심 윈도우 [j-W, j+W]의 최댓값을 찾고 dp_curr 갱신
			for (int j = 0; j < num_vals; ++j) {
				// max_prev_taste = max( L[j], R[j] ) = max( max(v[j-W..j]), max(v[j..j+W]) ) = max(v[j-W..j+W])
				long long max_prev_taste = max(L[j], R[j]);

				// 이전 상태가 도달 가능한 경우에만 갱신
				if (max_prev_taste > INF + 1) {
					int current_temp = temps[j];
					long long current_gain = (long long)M - abs(b[t] - current_temp);
					dp_curr[current_temp] = current_gain + max_prev_taste;
				}
			}
		}
		// 현재 시각의 계산이 끝나면 dp_prev를 dp_curr로 갱신
		dp_prev = dp_curr;
	}

	// 최종 결과: 시각 N-1에서의 모든 가능한 온도의 dp 값 중 최댓값
	long long max_total_taste = 0;  // 맛은 음수가 될 수 없으므로 0으로 초기화
	for (int k = 1; k <= M; ++k) {
		max_total_taste = max(max_total_taste, dp_prev[k]);
	}

	cout << max_total_taste << endl;

	return 0;
}