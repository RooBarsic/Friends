// full solution
# include <bits/stdc++.h>
using namespace std;
struct STUDENT{
	string surname, initials, groupNumber;
	vector<double> examResults;
	double sredniBall = 0;
};
int main(){
	int n = 5;
	STUDENT stud[5];
	for(int i = 0; i < n; i++){
		int numberOfExams;
		cin >> stud[i].surname;
		cin >> stud[i].initials;
		cin >> stud[i].groupNumber;
		cin >> numberOfExams;
		for(int j = 0; j < numberOfExams; j++){
		    double point;
			cin >> point;
			stud[i].examResults.push_back(point);
			stud[i].sredniBall += point;
		}
		stud[i].sredniBall /= (numberOfExams * 1.);
	}
	int numberOfAswers = 0;
	for(int i = 0; i < n; i++){
		if(stud[i].sredniBall > 4.0){
			numberOfAswers++;
			cout << stud[i].surname << " " << stud[i].groupNumber << '\n';
		}
	}
	if(numberOfAswers == 0){
		cout << "No students with sredni ball > 4.0 ";
	}
	return 0;
}
