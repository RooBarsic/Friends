#include<bits/stdc++.h>
  using namespace std;
  struct ochered{
	  stack< int > stak1, stak2;
	  void push_back(int a){
		  stak1.push(a);
	  }
	  int pop_front(){
		  if(stak1.size() == 0) return -1;
		  while(stak1.size() > 1){
			  int a = stak1.top();
			  stak1.pop();
			  stak2.push(a);
		  }
		  int ans = stak1.top();
		  stak1.pop();
		  while(stak2.size() > 0){
			  int a = stak2.top();
			  stak1.push(a);
			  stak2.pop();
		  }
		  return ans;
	  }
  };
  int main()
  {
	  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
