# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  int cmpString(string a, string b){
	  int k = min(sz(a), sz(b));
	  for(int i = 0; i < k; i++){
		  if(a[i] < b[i]) return -1;
		  if(a[i] > b[i]) return 1;
	  }
	  return 0;
  }
  void InsertionSort(int n, string srr[]) 
    { 
		for( int i = 1; i < n; i++ ) 
		{ 
			string tmp = srr[i]; 
			int j = i - 1;
			for(; (j >= 0) && (cmpString(srr[j], tmp) == 1); j--) 
				srr[j + 1] = srr[j]; 
			srr[j + 1] = tmp;
		} 
	}
  int main(){
	 int n;
	 cin >> n;
	 string arr[n];
	 getline(cin, arr[0]);
	 for(int i = 0; i < n; i++){
		 getline(cin, arr[i]);
	 }
	 InsertionSort(n, arr);
	 for(int i = 0; i < n; i++){
		 cout << arr[i] << '\n';
	 }
	 return 0;
  }

