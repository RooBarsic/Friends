# include <bits/stdc++.h>
  using namespace std;
// get_max - возврашает максимальный ( последний ) элемент из сета ( который мы ему даём )
  int get_max(multiset< int > st){
      auto it = st.end(); // берём указатель на конец сета ( не на последний элемент сета )
      it--;               // т.к it - указывает на конец сета, то (it--) - будет указывать на последний элемент сета 
      return *(it);       // т.к. it - это указатель, то *(it) - даёт нам число в сете на которое указывает it
  }
  int main()
  {
      int arr[100000010];     
      multiset< int > st1;    // возьмём сет
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
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
