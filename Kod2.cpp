# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  struct Graph{
      int n;
      int color[25], arr[25][25];
      vector< int > vrr[25];
      bitset< 25 > bita[25];

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

      pair< int, int > find_max()
      {
          int x = 1, y = 1;
          for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[x][y] < arr[i][j]){
                    x = i;
                    y = j;
                }
            }
          }
          return {x, y};
      }
  };
  int id[25];
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
  vector< bitset< 25 > > masks;
  void out_bita(int k, bitset< 25 > mk)
  {
      for(int i = 0; i <= k; i++){
        cout << mk[i];
      }
      cout << '\n';
  }
  void out_bita_1(int k, bitset< 25 > mk)
  {
      for(int i = 0; i <= k; i++){
        if(mk[i] == 1) cout << i << " ";
      }
      cout << '\n';
  }
  void out_roads(int k, bitset< 25 > mk)
  {
      for(int i = 0; i <= k; i++){
        if(mk[i] == 1) cout << "(" << id_xy[i].first << "; " << id_xy[i].second << ") ";
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
                bitset< 25 > mask = glob.bita[i] | glob.bita[j];
                bitset< 25 > M;
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

  Graph build_from_masks()
  {
      //cout << " sfdgsdG      Graph build_from_masks()  " << '\n';
      Graph g4;
      g4.n = sz(masks);
      for(int i = 0, kpf = sz(masks); i < kpf; i++){
        for(int j = 0; j < kpf; j++){
            g4.arr[i + 1][j + 1] = masks[i].count() + masks[j].count() - (masks[i] & masks[j]).count();
            g4.arr[j + 1][i + 1] = g4.arr[i + 1][j + 1];
        }
      }
      return g4;
  }
  bitset< 25 > dell_bita(int n, bitset< 25 > a, bitset< 25 > b)
  {
      for(int i = 0; i <= n; i++){
        if(b[i] == 1) a[i] = 0;
      }
      return a;
  }

  void add_new_mask(vector< bitset< 25 > > &mas, bitset< 25 > m)
  {
      if(m.count() == 0) return ;
      for(auto a : mas){
        if(a == m) return ;
      }
      mas.push_back(m);
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

      Graph g4;
      while(sz(masks) > 0){
        g4 = build_from_masks();
        cout << " Builded Graph from family : " << '\n';
        g4.outt_Graph();

        if(sz(masks) <= 1){
            int x = g4.find_max().first;
            cout << " x = " << x << '\n';
            out_bita_1(g3.n, masks[x - 1]);
            out_roads(g3.n, masks[x - 1]);
            break;
        }
        int x = g4.find_max().first;
        int y = g4.find_max().second;
        cout << " x = " << x << " y = " << y << '\n';
        out_bita_1(g3.n, masks[x - 1]);
        out_bita_1(g3.n, masks[y - 1]);
        out_roads(g3.n, masks[x - 1]);
        out_roads(g3.n, masks[y - 1]);

        /// Dell x, y, Build new masks
        bitset< 25 > mm = masks[x - 1] | masks[y - 1];
        vector< bitset< 25 > > new_masks;
        for(int i = 0, kpf = sz(masks); i < kpf; i++){
            add_new_mask(new_masks, dell_bita(g3.n, dell_bita(g3.n, masks[i], masks[y - 1]), masks[x - 1]));
        }
        masks = new_masks;
        cout << " ------------------------------ " << '\n';
      }
  }
/**
    1. Poisk Gamiltonov sikl
    2. Build new Graph based on old graph and Gamilton sikl
    3. Postroit Graf Peresecheniy
    4. Nayti semeystvo
    5. Build Graph from semeystvo
    6. find max
    7. dell max, build new family
    8. goto 5
    
    
7
0 1 1 1 0 0 0
1 0 1 0 1 0 1
1 1 0 1 1 1 1
1 0 1 0 1 1 1
0 1 1 1 0 1 0
0 0 1 1 1 0 1
0 1 1 1 0 1 0
*/
