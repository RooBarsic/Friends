#include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if(sz(a) != sz(b)) cout << "NO";
    else {
        int left_b = 0;
		deque< char > deq;
        for(int i = 0, k = sz(a); i < k; i++){
            deq.push_back(a[i]);
            while((sz(deq) > 0) && (deq.back() == b[left_b])){
                left_b++;
                deq.pop_back();
            }
        }
        if(sz(deq) == 0) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
