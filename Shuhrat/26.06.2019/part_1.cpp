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
            std::cout << "start deleting" << '\n';
            free(name);
            free(lastName);
            free(secondName);
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
      char a[10];
      char b[10];
      char c[10];
     cin >> a >> b >> c;
     Worker *ww = new Worker(a, b, c);
    cout << " sdg";
    delete ww;
    return 0;
}
