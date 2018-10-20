#include<iostream>
using namespace std;
void isort(int n, int *params, int *index){
	for(int i = 0; i < n; i++){
		for(int j = i; j >= 1; j--){
			if(params[j - 1] < params[j]) break;
			swap(params[j - 1], params[j]);
			swap(index[j - 1], index[j]);
		}
	}
}
int main(){
	int k;
	cin >> k;
	int *params = new int[k];
	int *index = new int[k];
	for(int i = 0; i < k; i++){
		int a, b, c;
		cin >> a >> b >> c;
		params[i] = a + b + c;
		index[i] = i;
	}
	isort(k, params, index);
	cout << index[0];
	for(int i = 1; i < k; i++){
		cout << " " << index[i];
	}
	delete[] params;
	delete[] index;
	return 0;
}
