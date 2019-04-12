# include <bits/stdc++.h>
using namespace std;
double functionType1(double x, double eps){
	int  id = 1;
	double sum = 0.;
	double power = x;
	double factorial = 1.;
	double c = x;
	while(abs(c) >= eps){
		sum -= c;
		power *= x * x;
		id++;
		factorial *= (id * 1.);
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
	double c = (*x);
	*sum = 0.;
	while(abs(c) >= *eps){
		*sum -= c;
		power *= (*x) * (*x);
		id++;
		factorial *= (id * 1.);
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
	double c = x;
	*sum = 0.;
	while(abs(c) >= eps){
		*sum -= c;
		power *= x * x;
		id++;
		factorial *= (id * 1.);
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
			cout << functionType1(x, eps) << '\n'; 
			break;
		case 2:
			double res;
			functionType2(&res, &x, &eps);
			cout << res << '\n';
			break;
		case 3:
			cout << *functionType3(x, eps) << '\n';
			break;
		default :
			cout << "Wrong type of function" << '\n';
	}
	return 0;
}
