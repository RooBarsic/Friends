# include <bits/stdc++.h>
  using namespace std;
  int m;
  double arr[110][110], brr[110][110], prr[110][110], res[110][110];
  void input(){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
  }

  /// prr = prr * arr
  void mult_arr_prr(){
    double crr[m + 1][m + 1];
	for(int x = 1; x <= m; x++){
		for(int y = 1; y <= m; y++){
			crr[x][y] = 0.;
			for(int j = 1; j <= m; j++){
				crr[x][y] += arr[x][j] * prr[j][y];
			}
		}
	}

	for(int x = 1; x <= m; x++){
		for(int y = 1; y <= m; y++){
			prr[x][y] = crr[x][y];
		}
	}
  }

  /// brr = prr
  void copu_prr_to_brr(){
	 for(int i = 1; i <= m; i++){
		 for(int j = 1; j <= m; j++){
			 brr[i][j] = prr[i][j];
		 }
	 }
  }

  /// brr = brr * x
  void mult_x_to_brr(double x){
	  for(int i = 1; i <= m; i++){
		 for(int j = 1; j <= m; j++){
			 brr[i][j] *= x;
		 }
	 }
  }

  /// res = res + brr
  void sum_res_brr(){
	  for(int i = 1; i <= m; i++){
		 for(int j = 1; j <= m; j++){
			 res[i][j] += brr[i][j];
		 }
	 }
  }

  /// out res
  void out_res(){
	  for(int i = 1; i <= m; i++){
		 for(int j = 1; j <= m; j++){
			 cout << fixed << setprecision(9) << res[i][j] << " ";
		 }
		 cout << '\n';
	 }
  }

  /// find max in brr
  double find_mx(){
	  double mx = brr[1][1];
	  for(int i = 1; i <= m; i++){
		 for(int j = 1; j <= m; j++){
			 mx = max(mx, brr[i][j]);
		 }
	 }
	 return mx;
 }

  /// set start settings
  void prepare(){
	  for(int i = 1; i <= m; i++){
		 for(int j = 1; j <= m; j++){
			 prr[i][j] = arr[i][j];
			 res[i][j] = 1;
		 }
	 }
  }

  int main(){
	double eps;
    cin >> m >> eps;
    input();
    prepare();
    double fact = 2.;
    double x = 2.;
    double znak = -1;
    mult_arr_prr();
    copu_prr_to_brr();
    double mx = find_mx();
    mult_x_to_brr(1./(fact * znak));
    while(true){
		if(mx < eps) break;
		sum_res_brr();

		mult_arr_prr();
		mult_arr_prr();
		copu_prr_to_brr();
		fact = fact * (x + 1.) * (x + 2.);
		x += 2.;
		znak = -znak;
		mult_x_to_brr(1./(fact * znak));

		mx = find_mx();
	}

	out_res();
  }
