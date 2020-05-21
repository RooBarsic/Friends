#include<stdio.h>

int n, m, m_2;
int arr[1010];
int brr[1010][1010];
int crr[1010][1010];
int drr[1010][1010];
int err[1010][1010];
int dist[1010];

/* для всех чисел от 0 до (2^m - 1) - находит двоичное представление 
 * и заполняет их в crr. Зполняет именно так как сказано в задаче -
 * если например число 3 - пишется как 11 в двоичной системе, а m=10, то
 * мы получаем 0000000011 ( добавляем восемь нулей в начало, всёравно от
 * добавления лидирующих нулей - ничего не изменится ).
 */
void fill_bits(){
	m_2 = (1 << m);
	for(int i = 1; i <= m_2; i++){
		int last = m;
		int x = i - 1;
		while(x > 0){
			int ostatok = x % 2;
			x = x / 2;
			crr[i][last] = ostatok;
			last--;
		}
	}
}

/* Тут умножаем каждое двоичное число от 0 до 2^m-1 - на матрицу brr[n][m] и 
 * получаем 2^m новыйх матриц размера [1][n]. Так как матрица размера [1][n] -
 * это массив размера [n] - значит мы получим 2^m новых массивов размера n.
 * drr[1] - это первый масив размера n
 * drr[2] - это второй массив размера n
 * и так далее
 */
void mult_numbers(){
	for(int a = 1; a <= m_2; a++){

		int i = 1;
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= m; k++){
				drr[a][j] = (drr[a][j] + crr[i][k] * brr[k][j]) % 2;
			}
		}
	}
}

/* каждую строку матрицы D[m_2][n] - сложим по модулю 2 с заданным массивом.
 * Получаем новую матрицу E[m_2][n]. Типа E[i][x] = (D[i][x] + A[x])%2, где 
 * 1 <= i <= m_2 ( m_2 = 2^m )
 * 1 <= x <= n
 */
void find_summ_drrs_with_arr(){
	for(int i = 1; i <= m_2; i++){
		for(int j = 1; j <= n; j++){
			err[i][j] = (drr[i][j] + arr[j]) % 2;
		}
	}
}

/* для каждой строки в матрице E[m_2][n] - находим количество единиц и сохраним всё в
 * массиве dist[m_2]
 */
void find_number_of_1(){
	for(int i = 1; i <= m_2; i++){
		dist[i] = 0;
		for(int j = 1; j <= n; j++){
			if(err[i][j] == 1){
				dist[i]++;
			}
		}
	}
}

/* находим номер числа у которого минимальное расстояние
 */
int find_id_of_min_dist(){
	int id = 1;
	for(int i = 2; i <= m_2; i++){
		if(dist[id] > dist[i]){
			id = i;
		}
	}
	return id;
}
 
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &brr[i][j]);
		}
	}
	
	fill_bits();
	mult_numbers();
	find_summ_drrs_with_arr();
	find_number_of_1();
	int id = find_id_of_min_dist();
	printf("%d", id);
	
	return 0;
}

