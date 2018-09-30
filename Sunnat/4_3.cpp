#include<bits/stdc++.h>
  using namespace std;
  struct ochered{
	  stack< int > stak1, stak2;
	  void push_back(int a){
		  stak1.push(a);
	  }
	  int pop_front(){
		  if(stak2.size() == 0){
			  while(stak1.size() > 0){
				  int a = stak1.top();
				  stak1.pop();
				  stak2.push(a);
			  }
		  }
		  if(stak2.size() == 0) return -1;
		  else {
			  int a = stak2.top();
			  stak2.pop();
			  return a;
		  }
	   }
  };
  int main()
  {
	  ochered my_ochered;
	  int n;
	  cin >> n;
	  for(int i = 1; i <= n; i++){
		  int command, x;
		  cin >> command >> x;
		  if(command == 3) my_ochered.push_back(x);
		  else if(command == 2){
			  if(x != my_ochered.pop_front()){
				  cout << "NO";
				  return 0;
			  }
		  }
	  }
	  cout << "YES";
	  return 0;
}
