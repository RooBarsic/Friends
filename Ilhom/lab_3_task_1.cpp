# include <bits/stdc++.h>
using namespace std;
double functionType1(double x, double eps){
	int  id = 1;
	double sum = 1.;
	double power = x;
	double factorial = 1.;
	double c = power / factorial;
	while(abs(c) >= eps){
		sum += c;
		power *= x;
		id++;
		factorial *= (id * 1.);
		c = power / factorial;
	}
	return sum;
}
void functionType2(double *sum, double *x, double *eps){
	int  id = 1;
	double power = (*x);
	double factorial = 1.;
	double c = power / factorial;
	*sum = 1.;
	while(abs(c) >= *eps){
		*sum += c;
		power *= (*x);
		id++;
		factorial *= (id * 1.);
		c = power / factorial;
	}
}
double* functionType3(double &x, double &eps){
	int  id = 1;
	double *sum = (double*) malloc(sizeof(double)); // чтобы память не отчистилась при выходе с функции
	double power = x;
	double factorial = 1.;
	double c = power / factorial;
	*sum = 1.;
	while(abs(c) >= eps){
		*sum += c;
		power *= x;
		id++;
		factorial *= (id * 1.);
		c = power / factorial;
	}
	return sum;
}
int main(){
	int functionType;
	double x, eps;
	cout << " print functionType : ";
	cin >> functionType;
	cout << " print x : ";
	cin >> x;
	cout << " print eps : ";
	cin >> eps;
	switch(functionType){
		case 1:
			cout << functionType1(x, eps); 
			break;
		case 2:
			double res;
			functionType2(&res, &x, &eps);
			cout << res;
			break;
		case 3:
			cout << *functionType3(x, eps);
			break;
		default :
			cout << "Wrong type of function";
	}
	return 0;
}
