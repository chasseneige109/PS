#include <iostream>
#include <cmath>

using namespace std;

struct position {
	double x;
	double y;
}typedef Pos;

double convertX[8] = { 0, sqrt(2) / 2, 1, sqrt(2) / 2 , 0, -sqrt(2) / 2 , -1, -sqrt(2) / 2 };
double convertY[8] = { 1, sqrt(2) / 2, 0, -sqrt(2) / 2 , -1, -sqrt(2) / 2 , 0, sqrt(2) / 2 };

int ccw(Pos a, Pos b, Pos c);
void dfs(int index);
bool check();

int dots[8];
int selectedDots[8];
bool visited[8];
Pos dotsPoint[8];
int possibeMakeCount;

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> dots[i];
	}

	possibeMakeCount = 0;
	dfs(0);

	cout << possibeMakeCount;
}

int ccw(Pos a, Pos b, Pos c) {
	double value = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (value > 0) {
		return 1;
	}
	else if (value < 0) {
		return -1;
	}
	return 0;
}

void dfs(int index) {
	if (index == 8) {
		if (check()) {
			possibeMakeCount++;
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (visited[i]) continue;

			selectedDots[index] = dots[i];
			visited[i] = true;
			dfs(index + 1);
			visited[i] = false;
		}
	}
}

bool check() {
	for (int i = 0; i < 8; i++) {
		dotsPoint[i].x = selectedDots[i] * convertX[i];
		dotsPoint[i].y = selectedDots[i] * convertY[i];
	}

	bool result = true;
	for (int i = 0; i < 8; i++) {
		if (ccw(dotsPoint[i], dotsPoint[(i + 1) % 8], dotsPoint[(i + 2) % 8]) != -1) {
			result = false;
			break;
		}
	}

	return result;
}