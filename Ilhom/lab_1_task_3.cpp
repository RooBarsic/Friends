// full solution
# include <bits/stdc++.h>
using namespace std;
struct STUDENT{
	string surname, initials, groupNumber;
	vector<double> examResults;
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
		    double mark;
			cin >> mark;
			stud[i].examResults.push_back(mark);
		}
	}
	int numberOfAswers = 0;
	for(int i = 0; i < n; i++){
		int kol_ne_4_i_5 = 0;
		for(int j = 0; j < stud[i].examResults.size(); j++){
			if((stud[i].examResults[j] != 4) && 
				(stud[i].examResults[j] != 5)) kol_ne_4_i_5++;
		}
		if(kol_ne_4_i_5 == 0){
			numberOfAswers++;
			cout << stud[i].surname << " " << stud[i].groupNumber << '\n';
		}
	}
	if(numberOfAswers == 0){
		cout << "No students with marks only 4 or 5 ";
	}
	return 0;
}
