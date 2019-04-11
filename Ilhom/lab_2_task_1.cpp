// partial solution
# include <bits/stdc++.h>
using namespace std;
double countVolume(double Radius, double Height){
	double pi = 3.14l
	double V = (pi * Radius * Radius) * Height;
	return V;
}
int main(){
	double radius, height;
	cout << " print Radius : ";
	cin >> radius;
	cout << " print Height : ";
	cin >> height;
	cout << " Cylinder volume = " << countVolume(radius, height);
	return 0;
}
