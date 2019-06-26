# include <bits/stdc++.h>
  using namespace std;
  // базовый класс работник
  class Worker {    
    public:
        // Конструктор класса human
        Worker(std::string last_name, std::string name, std::string second_name)
        {
            this->last_name = last_name;
            this->name = name;
            this->second_name = second_name;
        }

        // Получение ФИО человека
        std::string get_full_name()
        {
            std::ostringstream full_name;
            full_name << this->last_name << " "
                << this->name << " "
                << this->second_name;
            return full_name.str();
        }

    private:
        std::string name; // имя
        std::string last_name; // фамилия
        std::string second_name; // отчество
  };
  
  // служащий с почасовой оплатой
  class HourlyEmployee : public Worker {
    public:
        // Конструктор класса HourlyEmployee
        HourlyEmployee(std::string last_name, std::string name, std::string second_name) 
            : Worker(last_name, name, second_name) {
            
        }
  };
  
  // служащий в штате
  class StateEmployee : public Worker {
    public:
        // Конструктор класса StateEmployee
        StateEmployee(std::string last_name, std::string name, std::string second_name) 
            : Worker(last_name, name, second_name) {
            
        }
  };
  
  // служащий с процентной ставкой
  class InterestRateEmployee : public Worker {
    public:
        // Конструктор класса InterestRateEmployee
        InterestRateEmployee(std::string last_name, std::string name, std::string second_name) 
            : Worker(last_name, name, second_name) {
            
        }
  };
  
  int main(){
    return 0;
  }
