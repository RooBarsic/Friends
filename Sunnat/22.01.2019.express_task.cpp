#include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if(sz(a) != sz(b)) cout << "NO";
    else {
        int last_b = sz(b) - 1;
		deque< char > deq;
        for(int i = sz(a) - 1; i >= 0; i--){
            deq.push_back(a[i]);
            if(a[i] == b[last_b]){
				while(sz(deq) > 0){
					if(deq.back() != b[last_b]){
						cout << "NO";
						return 0;
					}
					last_b--;
					deq.pop_back();
				}
            }
        }
        cout << "YES";
    }
    return 0;
}
