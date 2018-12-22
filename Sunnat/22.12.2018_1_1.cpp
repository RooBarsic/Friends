/* Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией.
  Хранимые строки непустые и состоят из строчных латинских букв.
  Хеш-функция строки должна быть реализована с помощью вычисления значения многочлена методом Горнера.
  Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте при добавлении элементов в случае,
  когда коэффициент заполнения таблицы достигает 3/4.
  Структура данных должна поддерживать операции добавления строки в множество,
  удаления строки из множества и проверки принадлежности данной строки множеству.
  1_1. Для разрешения коллизий используйте квадратичное пробирова.*/
#include <bits/stdc++.h>
#include <functional>

#define fi first
#define se second
#define pb push_back

const int EMPTY = 0;
const int RESERVED = 1;
const int DELETED = 2;

std::hash<std::string> hsh;

struct hash_table {
    hash_table(int capacity = 8) : t(capacity) {}

    ~hash_table() {}

    bool add(const std::string& val) {
        if (get_index(val) != -1) {
            return false;
        }
        if (size * 4 >= 3 * t.size()) {
            ensure_capacity();
        }
        int h = hsh(val) % t.size();
        int64_t i = 1;
        while (t[h].se == RESERVED) {
            h = (h + i * i) % t.size();
            i++;
        }
        size += t[h].se == EMPTY;
        t[h].fi = val;
        t[h].se = RESERVED;

        return true;
    }

    bool contains(const std::string& val) {
        return get_index(val) != -1;
    }

    bool remove(const std::string& val) {
        int h = get_index(val);
        if (h != -1) {
            t[h] = {"", DELETED};
            return true;
        }
        return false;
    }

    private:
    void ensure_capacity() {
        hash_table copy(t.size() * 2);
        for (int i = 0; i < t.size(); ++i) {
            if (t[i].se == RESERVED) {
                copy.add(t[i].fi);
            }
        }
        swap(t, copy.t);
        std::swap(size, copy.size);
    }

    int get_index(const std::string &val) {
        int h = hsh(val) % t.size();
        int64_t i = 1;
        while (t[h].se != EMPTY) {
            if (t[h].se == RESERVED && t[h].first == val) {
                return h;
            }
            h = (h + i * i) % t.size();
            i++;
        }
        return -1;
    }

    std::vector<std::pair<std::string, int > > t;
    int size = 0;
};

int main() {
    char c;
    std::string s;
    hash_table t;
    std::string res[] = {"FAIL\n", "OK\n"};
    while (std::cin >> c >> s) {
        switch (c) {
            case '+': std::cout << res[t.add(s)];
                break;
            case '-': std::cout << res[t.remove(s)];
                break;
            case '?': std::cout << res[t.contains(s)];
                break;

        }
    }
    free(res);
}
