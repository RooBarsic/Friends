# include <bits/stdc++.h>
  using namespace std;
  
  struct PlanetInfo {
      string name;   // имя планеты
      int diameter;  // диаметр планеты
      bool haslife; // есть ли жизнь на этой планете ( да/нет )
      int moons;   // количество спутников планеты
  };
  
  class Planet {
      public : 
        Planet(){   // конструктор без параметров
            infoAboutPlanet.name = "";
            infoAboutPlanet.diameter = 0;
            infoAboutPlanet.haslife = 0;
            infoAboutPlanet.moons = 0;
        }
        
        Planet(PlanetInfo info){   // конструктор который принимает обект PlanetInfo
            infoAboutPlanet = info;
        }
        
        Planet(string name, int diameter, bool haslife, int moons){    // конструктор с параметрами Имя, Диаметр, Есть ли жизнь, количество спутников 
            infoAboutPlanet.name = name;
            infoAboutPlanet.diameter = diameter;
            infoAboutPlanet.haslife = haslife;
            infoAboutPlanet.moons = moons;
        }
        
        ~Planet(){     // деструктор
            
        }
        
        void getPlanet(){    // функция для ввода данных о планете
            cout << "Введите имя планеты : ";
            cin >> infoAboutPlanet.name;
            cout << "Введите диаметр планеты : ";
            cin >> infoAboutPlanet.diameter;
            cout << "На планете есть жизнь ? ( 1 - да, 0 - нет ) : ";
            cin >> infoAboutPlanet.haslife;
            cout << "Введите количество спутников планеты : ";
            cin >> infoAboutPlanet.moons;
        }
        
        void print(){    // функция для вывода данных о планете
            cout << "Информация о планете { ";
            cout << " Имя: " << infoAboutPlanet.name << "; "
                 << " Диаметр: " << infoAboutPlanet.diameter << "; "
                 << (infoAboutPlanet.haslife ? "Есть жизнь" : "Нет жизни") << "; "
                 << " Количество спутников: " << infoAboutPlanet.moons 
                 << " } " << '\n';
        }
        
	  // перегружаем оператор < . Чтобы сравнение < - происходило так-как мы хотим
        friend bool operator<(const Planet& left, const Planet& right){
			if(left.infoAboutPlanet.diameter < right.infoAboutPlanet.diameter) return true; // сравниваем диаметры
			else if(left.infoAboutPlanet.diameter == right.infoAboutPlanet.diameter){   // если диаметры равны
				if(left.infoAboutPlanet.moons < right.infoAboutPlanet.moons) return true;  // сравниваем количество спутников
				else if(left.infoAboutPlanet.moons == right.infoAboutPlanet.moons){  // если количество спутников тоже равны
					if(left.infoAboutPlanet.name < right.infoAboutPlanet.name) return true;  // сравниваем названия планет
				}
			}
			return false;
		}
      
      private :
        PlanetInfo infoAboutPlanet;   // тут храним информацию о планете
  };
  
  int main()
  {
	  freopen("test.txt", "r", stdin);
      int numberOfPlanets = 9;
      Planet planets[10];
      cout << '\n' << "----------- Вводим данные о 9 планетах ------------ " << '\n';
      for(int i = 1; i <= 9; i++){
		  cout << " Введите информацию о планете № " << i << ' ';
          planets[i].getPlanet();
          cout << '\n';
      }
	  
      cout << '\n' << "----------- Выводим данные о планетах ------------ " << '\n';
      for(int i = 1; i <= numberOfPlanets; i++){
	  cout << " Планета № " << i << ' ';
	  planets[i].print();
      }
	  
      cout << '\n' << "----------- Сортируем данные о планетах ------------ " << '\n';
      sort(planets + 1, planets + 1 + numberOfPlanets);
	  
      cout << '\n' << "----------- Выводим данные о планетах - после сортировки ------------ " << '\n';
      for(int i = 1; i <= numberOfPlanets; i++){
		  cout << " Планета № " << i << ' ';
		  planets[i].print();
	  }
      
      return 0;
  }
