# include <bits/stdc++.h>
  using namespace std;
  char get_rever(char a){
      switch(a){
          case '(': return ')';
          case ')': return '(';
          case '[': return ']';
          case ']': return '[';
          case '{': return '}';
          case '}': return '{';
      }
  }
  bool is_open(char a){
      switch(a){
          case '(' : return 1;
          case '[' : return 1;
          case '{' : return 1;
      }
      return 0;
  }
  bool is_close(char a){
      switch(a){
          case ')' : return 1;
          case ']' : return 1;
          case '}' : return 1;
      }
      return 0;
  }
  int main()
  {
      deque< char > deq1;
      string s;
      cin >> s;
      int len = s.size();
      for(int i = 0; i < len; i++){
          if((deq1.size() == 0) || (is_open(s[i]) == 1)) deq1.push_back(s[i]);
          else {
              if(deq1.back() == get_rever(s[i])) deq1.pop_back();
              else if(is_close(deq1.back())) deq1.push_back(s[i]);
              else {
                  cout << "IMPOSSIBLE";
                  return 0;
              }
          }
      }
      while((deq1.size() > 0) && (is_open(deq1.back()))){
          s += get_rever(deq1.back());
          deq1.pop_back();
      }
      while((deq1.size() > 0) && (is_close(deq1.back()))){
          s = get_rever(deq1.front()) + s;
          deq1.pop_front();
      }
      cout << s;
      return 0;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
