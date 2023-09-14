#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <random>

void print(int element) {
    std::cout << element << " ";
}

int main() {

    setlocale(LC_ALL, "RUSSIAN");

    std::list<int> integerList(10); // —оздаем список из 10 элементов
    std::list<int> copiedList;

    std::srand(time(NULL));


    // »спользуем generate дл€ заполнени€ списка случайными значени€ми
    std::generate(integerList.begin(), integerList.end(), []()->int {
        return int(rand())%10;
        });

    std::copy(integerList.begin(), integerList.end(), std::back_inserter(copiedList));

    std::cout << "1. generate Ч дл€ заполнени€ списка из 10 элементов целочисленными значени€ми\n" <<
        "Ёлементы полученного списка: "<< std::endl;
    std::for_each(integerList.begin(), integerList.end(), print);


    // —оздаем новый список с преобразованными значени€ми
    std::list<int> transformedList;
    // к каждому элементу добавл€ем 10 и вставл€ем в начало нового списка
    std::transform(integerList.begin(), integerList.end(), std::front_inserter(transformedList), [](int value) {
        return value + 10;
        });

    std::cout << "\n2.transform Ч дл€ целочисленного списка из 10 элементов\n" <<
        "Ёлементы нового списка: " << std::endl;
    std::for_each(transformedList.begin(), transformedList.end(), print);

    copiedList.erase(std::remove_if(begin(copiedList), end(copiedList), [](int value) {
        return value > 3;
        }), copiedList.end());

    std::cout << "\n3.remove Ч дл€ фильтрации чисел больше 3 в целочисленном списке из 10 элементов\n" <<
        "»сходный список, подвергнутый фильтрации: " << std::endl;
    std::for_each(copiedList.begin(), copiedList.end(), print);
    return 0;
}
