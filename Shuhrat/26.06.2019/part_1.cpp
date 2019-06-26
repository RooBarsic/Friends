# include <bits/stdc++.h>
  using namespace std;
  // базовый класс работник
  class Worker {    
    public:
        // Конструктор класса human
        Worker(std::string lastName, std::string name, std::string secondName)
        {
            this->lastName = lastName;
            this->name = name;
            this->secondName = secondName;
            this->money = 0;
        }

        // Получение ФИО человека
        std::string getFullName()
        {
            std::ostringstream fullName;
            fullName << this->lastName << " "
                << this->name << " "
                << this->secondName;
            return fullName.str();
        }
        
        // функция для начисления зарплаты
        addSallary(int sum){
            this->money += sum;
        }

    private:
        std::string name; // имя
        std::string lastName; // фамилия
        std::string secondName; // отчество
        int money.
  };
  
  // служащий с почасовой оплатой
  class HourlyEmployee : public Worker {
    public:
        // Конструктор класса HourlyEmployee
        HourlyEmployee(std::string lastName, std::string name, std::string secondName) 
            : Worker(lastName, name, secondName) {
            
        }
  };
  
  // служащий в штате
  class StateEmployee : public Worker {
    public:
        // Конструктор класса StateEmployee
        StateEmployee(std::string lastName, std::string name, std::string secondName) 
            : Worker(lastName, name, secondName) {
            
        }
  };
  
  // служащий с процентной ставкой
  class InterestRateEmployee : public Worker {
    public:
        // Конструктор класса InterestRateEmployee
        InterestRateEmployee(std::string lastName, std::string name, std::string secondName) 
            : Worker(lastName, name, secondName) {
            
        }
  };
  
  int main(){
    return 0;
  }
