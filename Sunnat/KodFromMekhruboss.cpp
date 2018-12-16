#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back 

const int EMPTY = 0;
const int RESERVED = 1;
const int DELETED = 2;

std::hash<string> hsh;

struct hash_table {
    hash_table(int capacity = 8) : t(capacity) {}
    
    ~hash_table() {}
    
    bool add(const string& val) {
        if (get_index(val) != -1) {
            return false;
        }
        if (size * 4 >= 3 * t.size()) {
            ensure_capacity();
        }
        int h = hsh(val) % t.size();
        int64_t i = 1;
        while (t[h].se == RESERVED) {
            h = (h + i * i) % t.size();
            i++;
        }
        size += t[h].se == EMPTY;
        t[h].fi = val;
        t[h].se = RESERVED;
        
        return true;
    }
    
    bool contains(const string& val) {
        return get_index(val) != -1;
    }
    
    bool remove(const string& val) {
        int h = get_index(val);
        if (h != -1) {
            t[h] = {"", DELETED};
            return true;
        }
        return false;
    }
    
    private:
    void ensure_capacity() {
        hash_table copy(t.size() * 2);
        for (int i = 0; i < t.size(); ++i) {
            if (t[i].se == RESERVED) {
                copy.add(t[i].fi);
            }
        }
        swap(t, copy.t);
        swap(size, copy.size);
    }
    
    int get_index(const string &val) {
        int h = hsh(val) % t.size();
        int64_t i = 1;
        while (t[h].se != EMPTY) {
            if (t[h].se == RESERVED && t[h].first == val) {
                return h;
            }
            h = (h + i * i) % t.size();
            i++;
        }
        return -1;
    }
    
    vector<pair<string, int > > t;
    int size = 0;
};

int main() {
    freopen("input.txt", "r", stdin);
    char c;
    string s;
    hash_table t;
    string res[] = {"FAIL\n", "OK\n"};
    while (cin >> c >> s) {
        switch (c) {
            case '+': cout << res[t.add(s)];
                break;
            case '-': cout << res[t.remove(s)];
                break;
            case '?': cout << res[t.contains(s)];
                break;
            
        }
    }
}
