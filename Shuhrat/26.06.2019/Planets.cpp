#include<bits/stdc++.h>
using namespace std;
struct PlanetInfo
{
    char *name;
    int diameter;
    bool haslife;
    int moons;
};
class Planet {
    private:
        PlanetInfo planetinfo;
    public:
        Planet(){   // конструктор без параметров
               // planetinfo.name = "";
                planetinfo.diameter = 0;
                planetinfo.haslife = 0;
                planetinfo.moons = 0;
            }
        //конструктор
        Planet(char name[20], int diameter, bool haslife, int moons){
            planetinfo.name=name;
            planetinfo.diameter=diameter;
            planetinfo.haslife=haslife;
            planetinfo.moons=moons;
        }
        ~Planet(){ //Деструктор
			free(planetinfo.name);
        }
     
    void getPlanet(){    // функция для ввода данных о планете
                cout << "Введите имя планеты : ";
                char name[20];
                cin >> name;
                planetinfo.name = name;
                cout << "Введите диаметр планеты : ";
                cin >> planetinfo.diameter;
                cout << "На планете есть жизнь ? ( 1 - да, 0 - нет ) : ";
                cin >> planetinfo.haslife;
                cout << "Введите количество спутников планеты : ";
                cin >> planetinfo.moons;
            }
    void print(){    // функция для вывода данных о планете
                cout << "Информация о планете { ";
                cout << " Имя: " << planetinfo.name << "; "
                     << " Диаметр: " << planetinfo.diameter << "; "
                     << (planetinfo.haslife ? "Есть жизнь" : "Нет жизни") << "; "
                     << " Количество спутников: " << planetinfo.moons
                     << " } " << '\n';
            }
    friend bool operator<(const Planet& left, const Planet& right){
                if(left.planetinfo.diameter < right.planetinfo.diameter) return true; // сравниваем диаметры
                else if(left.planetinfo.diameter == right.planetinfo.diameter){   // если диаметры равны
                    if(left.planetinfo.moons < right.planetinfo.moons) return true;  // сравниваем количество спутников
                    else if(left.planetinfo.moons == right.planetinfo.moons){  // если количество спутников тоже равны
                        if(left.planetinfo.name < right.planetinfo.name) return true;  // сравниваем названия планет
                    }
                }
                return false;
            }
};

int main(){
    setlocale(0, "Russian");
     //freopen("test.txt", "r", stdin);
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
