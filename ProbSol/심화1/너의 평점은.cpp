#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, double> scores = {
			{"A+", 4.5},
			{"A0", 4.0},
			{"B+", 3.5},
			{"B0", 3.0},
			{"C+", 2.5},
			{"C0", 2.0},
			{"D+", 1.5},
			{"D0", 1.0},
			{"F",  0.0}
	};
	
	double totalScore = 0.0;
	double totalCredit = 0.0;

	for (int i = 0; i < 20; i++)
	{
		string dicipline, grade;
		double credit;
		cin >> dicipline >> credit >> grade;
		if (grade == "P") continue; // Skip pass grades
		totalScore += scores[grade] * credit;
		totalCredit += credit;
		
	}
	double average = totalScore / totalCredit;
	cout.precision(6);
	cout << fixed << average << "\n";
	return 0;
}