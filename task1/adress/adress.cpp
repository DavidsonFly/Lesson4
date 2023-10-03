// adress.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int flat;
public:
    Address(std::string city, std::string street, int house, int flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }

    std::string get_address() {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
    }
};

int main() {
    int count;
    std::string city, street;
    int house, flat;

    std::ifstream in("in.txt");
    
    if (in.is_open())
    {
        std::cout << "in file is opened" << std::endl;
    }
    else
    {
        std::cout << "in file do not open" << std::endl;
    }
    in >> count;

    Address** addresses = new Address * [count];

    for (int i = 0; i < count; i++) {
        in >> city >> street >> house >> flat;
        addresses[i] = new Address(city, street, house, flat);
    }

    in.close();

    std::ofstream out("out.txt");

    if (out.is_open())
    {
        std::cout << "out file is opened" << std::endl;
    }
    else
    {
        std::cout << "out file do not open" << std::endl;
    }

    out << count << std::endl;
    for (int i = count - 1; i >= 0; i--) {
        out << addresses[i]->get_address() << std::endl;
    }

    out.close();

    for (int i = 0; i < count; i++) {
        delete addresses[i];
    }
    delete[] addresses;

    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
