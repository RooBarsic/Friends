# include <bits/stdc++.h>
  using namespace std;
  int get_max(multiset< int > st){
      auto it = st.end();
      it--;
      return *(it);
  }
  int main()
  {
      int arr[100000010];
      multiset< int > st1;
      int n, k;
      cin >> n;
      for(int i = 0; i < n; i++){
          cin >> arr[i];
      }
      cin >> k;
      for(int i = 0; i < k; i++){
          st1.insert(arr[i]);
      }
      
      cout << get_max(st1) << " ";
      for(int i = k; i < n; i++){
          st1.erase(st1.find(arr[i - k]));
          
          st1.insert(arr[i]);
          
          cout << get_max(st1) << " ";
      }
      
      return 0;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
