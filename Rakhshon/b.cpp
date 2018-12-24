# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;

bool color[200100];
vector< int > words[30];
int tree[800800];

int get_sum(int v, int tl, int tr, int le, int ri){
    if((tr < le) || (ri < tl)) return 0;
    if((le <= tl) && (tr <= ri)) return tree[v];
    int a = (v << 1);
    int b = a + 1;
    int tm = ((tl + tr) >> 1);
    return get_sum(a, tl, tm, le, ri) + get_sum(b, tm + 1, tr, le, ri);
}

void upd(int v, int tl, int tr, int x){
    //cout << " v = " << v << " tl = " << tl << " tr = " << tr << " x = " << x << '\n';
    if((tr < x) || (x < tl)) return ;
    if(tl == tr) tree[x]++;
    else {
        int a = (v << 1);
        int b = a + 1;
        int tm = ((tl + tr) >> 1);
        upd(a, tl, tm, x);
        upd(b, tm + 1, tr, x);
        tree[v] = tree[a] + tree[b];
    }
}

void solve(){
    int m;
    string s;
    cin >> s >> m;
    s = "=" + s;
    for(int i = 0, k1 = sz(s); i < k1; i++){
        if(s[i] != '=') words[int(s[i]) - int('a')].push_back(i);
    }

    int l = 1;
    string t = "";
    int n = sz(s) - 1;
    int ex_pos = -1, ex_char = 0;
    for(int i = 0; i < 27; i++){
        //cout << " i = : " << i << '\n';
        if(m == 0) break;

        if(sz(words[i]) > 0){
            sort(words[i].begin(), words[i].end());
            for(int pos : words[i]){
                if(m == 0) break;

                int x = pos + get_sum(1, l, n, pos, n);
                if(x == l){
                    l++;
                    color[pos] = 1;
                    t += char(int('a') + i);
                    //cout << " 2t = " << t << '\n';
                    upd(1, 1, n, pos);
                    //cout << " doe " << '\n';
                }
                else {
                    if(x - l <= m){
                        m -= (x - l);
                        color[pos] = 1;

                        l++;
                        t += char(int('a') + i);

                        //cout << " t = " << t << '\n';
                        upd(1, 1, n, pos);
                    }
                    else {
                        //cout << " c = " << char(i + int('a'));
                        goto endi;
                    }
                }
            }

            //cout << " good i = " << i << '\n';
        }
    }
    endi:;
    //cout << " t = " << t << " m = " << m << '\n';

    for(int i = 1, k1 = sz(s); i < k1; i++){
        if(color[i] == 0){
            t += s[i];
        }
    }

    int p = sz(t);

        int x = 1;
    while(m > 0){
        while(x < p){
            if(t[x - 1] > t[x]) break;
            x++;
        }
        if(x == p) break;
        swap(t[x - 1], t[x]);
        m--;
    }

    cout << t;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int k = 1;
    while(k > 0){
        solve();
        cout << '\n';
        k--;
    }
}
