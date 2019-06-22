# include <bits/stdc++.h>
  using namespace std;
  int main(){
    int n;
    int d = 2;
    cin >> n;
    stack< int > stk;
    while(n > 1){
        if(n % d == 0){
            n = n / d;
            stk.push(d);
        }
        else d++;
    }
    stack< int > stk2;
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk2.push(stk.top());
        stk.pop();
        if(stk.size() > 0) cout << "* ";
    }    
    cout << '\n';
    while(!stk2.empty()){
        cout << stk2.top() << " ";
        stk2.pop();
        if(stk2.size() > 0) cout << "* ";
    }
    return 0;
  }
