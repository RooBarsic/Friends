# include <bits/stdc++.h>
  using namespace std;
  long long arr[100100], brr[100100], crr[100100];
  int kol(long long x)
  {
      int a, k = 0;
      while(x > 0){
        a = x % 10;
        x = x / 10;
        if(a % 2 != 0) k++;
      }
      return  k;
  }
  int sum(long long x)
  {
      int a, s = 0;
      while(x > 0){
        a = x % 10;
        x = x / 10;
        if(a % 2 != 0) s += a;
      }
      return a;
  }
  int main()
  {
      long long n, k;
      cin >> n;
      for(int i = 1; i <= n; i++){
        cin >> arr[i];
        brr[i] = kol(arr[i]);
        crr[i] = sum(arr[i]);
      }
      sort(brr + 1, brr + 1 + n);
      sort(crr + 1, crr + 1 + n);
      for(int i = 1; i <= n; i++){
        cout << brr[i] << " " << crr[i] << " ";
      }
      return 0;
  }
