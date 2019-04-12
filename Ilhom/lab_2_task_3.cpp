// full solution
# include <bits/stdc++.h>
#define MAX 100
using namespace std;
double countVolume(double a, double b, double c, double Height){ 
	double pi = 3.14;
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	double v = s * Height;
	return v;
}

void printWords(int id, char s[]){ // выделяем слова в строке и выводим их, рекурсивно, в обратном порядке
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
char* getString(){ // берём строку из stdin
    char *str = (char*) malloc(MAX * sizeof(char));
    cin >> str;
    return str;
}
void printString(char s[]){ // чтобы вывести строку
    int k = strlen(s);
    for(int i = 0; i < k; i++){
        cout << s[i];
    }
}
int main(){
	double a, b, c, height;
	cout << " print base triangle parameters : " << '\n';
	cout << " print a : ";
	cin >> a;
	cout << " print b : ";
	cin >> b;
	cout << " print c : ";
	cin >> c;
	cout << " print Height : ";
	cin >> height;
	cout << " triangular prism volume = " << countVolume(a, b, c, height) << '\n';
	
	// test string
	char *crr = getString();
    cout << "for char, result : ";
	printWords(0, crr);
	cout << '\n';
	return 0;
}
