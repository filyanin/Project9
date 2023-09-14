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

    std::list<int> integerList(10); // ������� ������ �� 10 ���������
    std::list<int> copiedList;

    std::srand(time(NULL));


    // ���������� generate ��� ���������� ������ ���������� ����������
    std::generate(integerList.begin(), integerList.end(), []()->int {
        return int(rand())%10;
        });

    std::copy(integerList.begin(), integerList.end(), std::back_inserter(copiedList));

    std::cout << "1. generate � ��� ���������� ������ �� 10 ��������� �������������� ����������\n" <<
        "�������� ����������� ������: "<< std::endl;
    std::for_each(integerList.begin(), integerList.end(), print);


    // ������� ����� ������ � ���������������� ����������
    std::list<int> transformedList;
    // � ������� �������� ��������� 10 � ��������� � ������ ������ ������
    std::transform(integerList.begin(), integerList.end(), std::front_inserter(transformedList), [](int value) {
        return value + 10;
        });

    std::cout << "\n2.transform � ��� �������������� ������ �� 10 ���������\n" <<
        "�������� ������ ������: " << std::endl;
    std::for_each(transformedList.begin(), transformedList.end(), print);

    copiedList.erase(std::remove_if(begin(copiedList), end(copiedList), [](int value) {
        return value > 3;
        }), copiedList.end());

    std::cout << "\n3.remove � ��� ���������� ����� ������ 3 � ������������� ������ �� 10 ���������\n" <<
        "�������� ������, ������������ ����������: " << std::endl;
    std::for_each(copiedList.begin(), copiedList.end(), print);
    return 0;
}
