# include <bits/stdc++.h>
  using namespace std;
  class ProblemSolver {
    public :
        void solveProblem(int n){
            int d = 2;
            std::stack< int > stk;
            while(n > 1){
                if(n % d == 0){
                    n = n / d;
                    stk.push(d);
                }
                else d++;
            }
            std::stack< int > stk2;
            while(!stk.empty()){
                std::cout << stk.top() << " ";
                stk2.push(stk.top());
                stk.pop();
                if(stk.size() > 0) std::cout << "* ";
            }    
            std::cout << '\n';
            while(!stk2.empty()){
                std::cout << stk2.top() << " ";
                stk2.pop();
                if(stk2.size() > 0) std::cout << "* ";
            }
        }
  };
  int main(){
    ProblemSolver prob;
    prob.solveProblem(156);
    return 0;
}
