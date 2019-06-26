# include <bits/stdc++.h>
  using namespace std;
  // базовый класс работник
  class Worker {    
    public:
        // Конструктор класса human
        Worker(char* lastName, char* name, char* secondName)
        {
            this->lastName = lastName;
            this->name = name;
            this->secondName = secondName;
            this->money = 0;
        }

        char* getLastName()
        {
            return lastName;
        }
        char* getName()
        {
            return name;
        }
        char* getSecondName()
        {
            return secondName;
        }
        
        // функция для начисления зарплаты
        addSallary(int sum){
            this->money += sum;
        }
        
        ~Worker(){     // деструктор
            //free(name);
            //free(lastName);
            //free(secondName);
            cout << " kunku ";
        }

    private:
        char* name; // имя
        char* lastName; // фамилия
        char* secondName; // отчество
        int money;
  };
  
  // служащий с почасовой оплатой
  class HourlyEmployee : public Worker {
    public:
        // Конструктор класса HourlyEmployee
        HourlyEmployee(char* lastName, char* name, char* secondName) 
            : Worker(lastName, name, secondName) {
            
        }
  };
  
  // служащий в штате
  class StateEmployee : public Worker {
    public:
        // Конструктор класса StateEmployee
        StateEmployee(char* lastName, char* name, char* secondName) 
            : Worker(lastName, name, secondName) {
            
        }
  };
  
  // служащий с процентной ставкой
  class InterestRateEmployee : public Worker {
    public:
        // Конструктор класса InterestRateEmployee
        InterestRateEmployee(char* lastName, char* name, char* secondName) 
            : Worker(lastName, name, secondName) {
            
        }
  };
  
  int main(){
      char *a;
      char *b;
      char *c;
     cin >> a >> b >> c;
     Worker *ww = new Worker(a, b, c);
    cout << " sdg";
    return 0;
  }
