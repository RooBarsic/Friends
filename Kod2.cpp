# include <iostream>
# include <algorithm>
  using namespace std;
  int sum, kol;
  long long arr[100100], brr[100100], crr[100100];
  void count_kol(long long x){
      int a;
      kol = 0;
      while(x > 0){
        a = x % 10;
        x = x / 10;
        if(a % 2 != 0) kol++;
      }
  }
  void count_sum(long long x){
      int a;
      sum = 0;
      while(x > 0){
        a = x % 10;
        x = x / 10;
        if(a % 2 != 0) sum += a;
      }
  }
  int main()
  {
      long long n, k;
      cin >> n;
      for(int i = 1; i <= n; i++){
        cin >> arr[i];
        count_kol(arr[i]);
        count_sum(arr[i]);
        brr[i] = kol;
        crr[i] = sum;
      }
      sort(brr + 1, brr + 1 + n);
      sort(crr + 1, crr + 1 + n);
      for(int i = 1; i <= n; i++){
        cout << brr[i] << " " << crr[i] << " ";
      }
      return 0;
  }
