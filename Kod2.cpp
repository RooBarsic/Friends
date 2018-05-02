# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  struct Graph{
      int n;
      int color[110], arr[110][110];
      vector< int > vrr[110];
      bitset< 100100 > bita[110];

      int flag = 0;
      vector< int > gami;
      void way1(int v){
          gami.push_back(v);
          color[v] = 1;
          if((sz(gami) == n) && (arr[gami[0]][gami[sz(gami) - 1]] == 1)) flag = 1;
          for(int x : vrr[v]){
            if(color[x] == 0) way1(x);
            if(flag == 1) return ;
          }
          gami.pop_back();
          color[v] = 0;
      }
      vector< int > find_gamilt_way(){
          fill(color + 1, color + 1 + n, 0);
          gami.clear();
          flag = 0;
          way1(1);
          return gami;
      }

      void fill_bita()
      {
          for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][j] == 1) bita[i][j] = 1;
            }
          }
      }

      void outt_Graph()
      {
          for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << arr[i][j] << " \n"[j == n];
            }
          }
      }
  };
  int id[110];
  vector< int > gamilt;
  map< int, pair< int, int > > id_xy;
  map< pair< int, int >, int > xy_id;
  Graph get_Graph()
  {
      Graph g;
      cin >> g.n;
      for(int i = 1; i <= g.n; i++){
        for(int j = 1; j <= g.n; j++){
            cin >> g.arr[i][j];
            cout << g.arr[i][j] << " \n"[j == g.n];
            if(g.arr[i][j] != 0) g.vrr[i].push_back(j);
        }
      }
      return g;
  }
  Graph build_Graph_based_G1(Graph g1)
  {
      Graph g2;
      g2.n = g1.n;
      for(int i = 1; i <= g2.n; i++){
        for(int j = 1; j <= g2.n; j++){
            g2.arr[i][j] = g1.arr[id[i]][id[j]];
            if(g2.arr[i][j] == 1) g2.vrr[i].push_back(j);
        }
      }
      return g2;
  }

  pair< int, int > fib(pair< int, int > a)
  {
      if(a.first > a.second) swap(a.first, a.second);
      return a;
  }
  Graph build_G3(Graph g2)
  {
      int k = 0;
      map< int, pair< int, int > > mp_a;
      map< pair< int, int >, int > mp_b;
      set< pair< int, int > > st;
      vector< pair< int, int > > prr;
      for(int i = 2; i <= g2.n; i++){
        for(int j = i + 2; j <= g2.n; j++){
            if(g2.arr[i][j] == 0) continue ;
            for(int x = i + 1; x < j; x++){
                for(int y = 1; y < i; y++){
                    if(g2.arr[x][y] == 1){
                        st.insert({min(i, j), -max(i, j)});
                        st.insert({min(x, y), -max(x, y)});
                    }
                }
                for(int y = j + 1; y <= g2.n; y++){
                    if(g2.arr[x][y] == 1){
                        st.insert({min(i, j), -max(i, j)});
                        st.insert({min(x, y), -max(x, y)});
                    }
                }
            }
        }
      }
      k = 0;
      for(auto a : st){
        k++;
        cout << a.first << " " << -a.second << " k = " << k << '\n';
        mp_b[{a.first, -a.second}] = k;
        mp_a[k] = {a.first, -a.second};
      }
      Graph g3;
      g3.n = k;
      for(int i = 2; i <= g2.n; i++){
        for(int j = i + 2; j <= g2.n; j++){
            if(g2.arr[i][j] == 0) continue ;
            for(int x = i + 1; x < j; x++){
                for(int y = 1; y < i; y++){
                    if(g2.arr[x][y] == 1){
                        g3.arr[mp_b[fib({i, j})]][mp_b[fib({x, y})]] = 1;
                        g3.arr[mp_b[fib({x, y})]][mp_b[fib({i, j})]] = 1;
                        cout << "(" << i << " " << j << ") " << mp_b[fib({i, j})] << " ---- "
                            << "(" << x << " " << y << ") " << mp_b[fib({x, y})] << '\n';
                    }
                }
                for(int y = j + 1; y <= g2.n; y++){
                    if(g2.arr[x][y] == 1){
                        g3.arr[mp_b[fib({i, j})]][mp_b[fib({x, y})]] = 1;
                        g3.arr[mp_b[fib({x, y})]][mp_b[fib({i, j})]] = 1;
                        cout << "(" << i << " " << j << ") " << mp_b[fib({i, j})] << " ---- "
                            << "(" << x << " " << y << ") " << mp_b[fib({x, y})] << '\n';
                    }
                }
            }
        }
      }
      for(int i = 1; i <= g3.n; i++){
        g3.arr[i][i] = 1;
      }
      id_xy = mp_a;
      xy_id = mp_b;
      return g3;
  }

  Graph glob;
  vector< bitset< 100100 > > masks;
  void out_bita(int k, bitset< 100100 > mk)
  {
      for(int i = 0; i <= k; i++){
        cout << mk[i];
      }
      cout << '\n';
  }
  void find_masks()
  {
      masks.clear();
      for(int i = 1; i < glob.n; i++){
        //cout << " i = " << i << '\n';
        if(glob.bita[i].count() == glob.n){
            masks.push_back((1<<i));
            continue;
        }
        for(int j = i + 1; j <= glob.n; j++){
            if(glob.arr[i][j] == 0){
                bitset< 100100 > mask = glob.bita[i] | glob.bita[j];
                bitset< 100100 > M;
                M[i] = M[j] = 1;
                //cout << " j = " << j << " mask = ";
                //out_bita(glob.n, mask);
                while(mask.count() != glob.n){
                    int flag = 0;
                    for(int x = j + 1; x <= glob.n; x++){
                        if(mask[x] == 0){
                            flag = 1;
                            mask = mask | glob.bita[x];
                            M[x] = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        M = 0;
                        break;
                    }
                }
                if(M.count() > 0){
                    masks.push_back(M);
                    //cout << " i = " << i << " j = " << j << " M : ";
                    //out_bita(glob.n, M);
                    //cout << " Pushed !!! " << '\n';
                }
            }
        }
      }
  }

  void build_from_masks()
  {
      cout << " sfdgsdG";
      Graph g4;
      g4.n = sz(masks);
      for(int i = 0, kpf = sz(masks); i < kpf; i++){
        for(int j = 0; j < kpf; j++){
            g4.arr[i][j] = masks[i].count() + masks[j].count() - (masks[i] & masks[j]).count();
            g4.arr[j][i] = g4.arr[i][j];
        }
      }
      //return g4;
  }
  int main()
  {
      freopen("test.cpp", "r", stdin);
      Graph g1 = get_Graph();

      gamilt = g1.find_gamilt_way();
      cout << " Gamilton sykl : " << '\n';
      for(int x : gamilt) cout << x << " ";
      cout << '\n';
      for(int i = 0; i < sz(gamilt); i++){
        cout << i + 1 << " ";
        id[i + 1] = gamilt[i];
      }
      cout << '\n' << '\n';
      Graph g2 = build_Graph_based_G1(g1);
      g2.outt_Graph();

      cout << '\n' << '\n' << " Graf peresecheniy " << '\n';
      Graph g3 = build_G3(g2);
      g3.outt_Graph();

      g3.fill_bita();
      glob = g3;
      find_masks();
      cout << " Semeystvo sz = " << sz(masks) << '\n';
      for(int i = 0, kpf = sz(masks); i < kpf; i++){
        cout << " i = " << i << " : ";
        for(int j = 1; j <= g3.n; j++){
            if(masks[i][j] == 1) cout << j << " ";
        }
        cout << '\n';
      }

      Graph g4; // = build_from_masks();
      cout << " Builded Graph from family : " << '\n';
      //g4.outt_Graph();
  }
/**
    1. Poisk Gamiltonov sikl
    2. Build new Graph based on old graph and Gamilton sikl
    3. Postroit Graf Peresecheniy
    4. Nayti semeystvo
    5.
*/
