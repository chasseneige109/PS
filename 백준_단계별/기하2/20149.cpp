#include <iostream>

using namespace std;

struct position {
	double x;
	double y;
}typedef Pos;

int ccw(Pos a, Pos b, Pos c);
void findIntersectionPoint(Pos a, Pos b, Pos c, Pos d);

int main() {
	Pos dot[4];

	for (int i = 0; i < 4; i++) {
		double x, y;
		cin >> x >> y;
		dot[i].x = x;
		dot[i].y = y;
	}

	int ABC = ccw(dot[0], dot[1], dot[2]);
	int ABD = ccw(dot[0], dot[1], dot[3]);
	int ACD = ccw(dot[0], dot[2], dot[3]);
	int BCD = ccw(dot[1], dot[2], dot[3]);

	if (ABC * ABD == 0 && ACD * BCD == 0) {
		if (dot[0].x > dot[1].x) {
			Pos temp;
			temp = dot[0];
			dot[0] = dot[1];
			dot[1] = temp;
		}
		else if (dot[0].x == dot[1].x && dot[0].y > dot[1].y) {
			Pos temp;
			temp = dot[0];
			dot[0] = dot[1];
			dot[1] = temp;
		}

		if (dot[2].x > dot[3].x) {
			Pos temp;
			temp = dot[2];
			dot[2] = dot[3];
			dot[3] = temp;
		}
		else if (dot[2].x == dot[3].x && dot[2].y > dot[3].y) {
			Pos temp;
			temp = dot[2];
			dot[2] = dot[3];
			dot[3] = temp;
		}

		if ((dot[0].x < dot[3].x || (dot[0].x == dot[3].x && dot[0].y <= dot[3].y))
			&& (dot[1].x > dot[2].x || (dot[1].x == dot[2].x && dot[1].y >= dot[2].y))) {
			cout << 1 << "\n";
			findIntersectionPoint(dot[0], dot[1], dot[2], dot[3]);
		}
		else {
			cout << 0 << "\n";
		}
	}
	else if (ABC * ABD <= 0 && ACD * BCD <= 0) {
		cout << 1 << "\n";
		findIntersectionPoint(dot[0], dot[1], dot[2], dot[3]);
	}
	else {
		cout << 0 << "\n";
	}
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

void findIntersectionPoint(Pos a, Pos b, Pos c, Pos d) {
	double x = (c.x - d.x) * (a.x * b.y - a.y * b.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x);
	double y = (c.y - d.y) * (a.x * b.y - a.y * b.x) - (a.y - b.y) * (c.x * d.y - c.y * d.x);
	double m = (a.x - b.x) * (c.y - d.y) - (c.x - d.x) * (a.y - b.y);

	if (m != 0) {
		x /= m;
		y /= m;

		cout << fixed;
		cout.precision(9);
		cout << x << ' ' << y << "\n";
	}
	else {
		if (b.x == c.x && b.y == c.y) {
			if (a.x < c.x || (a.x == c.x && a.y < c.y)) {
				cout << b.x << " " << b.y << "\n";
			}
		}
		else if (a.x == d.x && a.y == d.y) {
			if (c.x < a.x || (c.x == a.x && c.y < a.y)) {
				cout << a.x << " " << a.y << "\n";
			}
		}
	}
}