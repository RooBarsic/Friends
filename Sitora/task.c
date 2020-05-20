#include<iostream>

#define sz(s) int(s.size())

int arr[1010];
int brr[1010][1010];
int crr[1010][1010];

/* для всех чисел от 0 до (m - 1) - находит двоичное представление 
 * и заполняет их в crr. Зполняет именно так как сказано в задаче -
 * если например число 3 - пишется как 11 в двоичной системе, а n=10, то
 * мы получаем 0000000011 ( добавляем восемь нулей в начало, всёравно от
 * добавления лидирующих нулей - ничего не изменится ).
 */
void fill_bits(int m, int n){
	for(int i = 0; i < m; i++){
		int last = n;
		int x = i;
		while(x > 0){
			int ostatok = x % 2;
			x = x / 2;
			crr[i][last] = ostatok;
			last--;
		}
	}
}
 
int main(){
	int 
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> brr[i][j];
		}
	}
	fill_bits(m, n);
	return 0;
}

