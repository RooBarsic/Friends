# include <bits/stdc++.h>
  using namespace std;
  
  struct PlanetInfo {
      string name;
      int diameter;
      bool haslife;
      int moons;
  };
  
  class Planet {
      public : 
        Planet(){
            infoAboutPlanet.name = "";
            infoAboutPlanet.diameter = 0;
            infoAboutPlanet.haslife = 0;
            infoAboutPlanet.moons = 0;
        }
        
        Planet(PlanetInfo info){
            infoAboutPlanet = info;
        }
        
        Planet(string name, int diameter, bool haslife, int moons){
            infoAboutPlanet.name = name;
            infoAboutPlanet.diameter = diameter;
            infoAboutPlanet.haslife = haslife;
            infoAboutPlanet.moons = moons;
        }
        
        ~Planet(){
            
        }
        
        void getPlanet(){
            cout << "Введите имя планеты : ";
            cin >> infoAboutPlanet.name;
            cout << "Введите диаметр планеты : ";
            cin >> infoAboutPlanet.diameter;
            cout << "На планете есть жизнь ? ( 1 - да, 0 - нет ) : ";
            cin >> infoAboutPlanet.haslife;
            cout << "Введите количество спутников планеты : ";
            cin >> infoAboutPlanet.moons;
        }
        
        void print(){
            cout << "Информация о планете { ";
            cout << " Имя: " << infoAboutPlanet.name << "; "
                 << " Диаметр: " << infoAboutPlanet.diameter << "; "
                 << (infoAboutPlanet.haslife ? "Есть жизнь" : "Нет жизни") << "; "
                 << " Количество спутников: " << infoAboutPlanet.moons 
                 << " } " << '\n';
        }
        
        friend bool operator<(const Planet& left, const Planet& right){
			if(left.infoAboutPlanet.diameter < right.infoAboutPlanet.diameter) return true;
			else if(left.infoAboutPlanet.diameter == right.infoAboutPlanet.diameter){
				if(left.infoAboutPlanet.moons < right.infoAboutPlanet.moons) return true;
				else if(left.infoAboutPlanet.moons == right.infoAboutPlanet.moons){
					if(left.infoAboutPlanet.name < right.infoAboutPlanet.name) return true;
				}
			}
			return false;
		}
      
      private :
        PlanetInfo infoAboutPlanet;
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
