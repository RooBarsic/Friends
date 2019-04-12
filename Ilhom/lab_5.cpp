/*
Взяли условие подзадачи из "Лабораторная работа №2 ( Строки )" :
Строка, введенная пользователем, состоит из слов, разделенных запятой. 
Вывести на экран слова в обратной последовательности. 
*/
# include <bits/stdc++.h>
using namespace std;
#define MAX 100
void printWords(int id, string s){
	int k = int(s.size());
	if(id < k){
		string word = "";
		for(int i = id; i < k; i++){
			if(s[i] == ','){
				printWords(i + 1, s);
				cout << word << " ";
				return;
			}
			else word += s[i];
		}
		cout << word << " ";
	}
}

void printWords(int id, char s[]){
	int k = int(strlen(s));
	if(id < k){
		string word = "";
		for(int i = id; i < k; i++){
			if(s[i] == ','){
				printWords(i + 1, s);
				cout << word << " ";
				return;
			}
			else word += s[i];
		}
		cout << word << " ";
	}
}
void printWords(int id, int s[]){
	cout << " it's int array! ";
}
void printWords(int id, double s[]){
    cout << " it's double array! ";
}
int main(){
    string s;
    cin >> s;
    cout << "for string, result : ";
    printWords(0, s);
    cout << '\n';

	char crr[MAX];
	cin >> crr;
    cout << "for char, result : ";
	printWords(0, crr);
	cout << '\n';
	
	int arr[12];
	cout << "for int, result : ";
	printWords(0, arr);
	cout << '\n';
	
	double brr[12];
	cout << "for double, result : ";
	printWords(0, brr);
	return 0;
}
