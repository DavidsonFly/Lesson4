## В этом файле приведены решения двух заданий task and task2

# task1:
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
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

# task2:
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Address
{
private:
    std::string city;
    std::string street;
    int house;
    int flat;

public:

    Address(std::string city, std::string street, int house, int flat)
    {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }

   
    std::string get_address()
    {

         return city + "," + street + "," +std:: to_string(house) + "," + std:: to_string(flat);
    }

    std::string get_city()
    {
        return city;
    }

};

void buble_sort(Address** addresses, int count)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < count - 1; i++)
        {
            if (addresses[i]->get_city() < addresses[i + 1]->get_city())
            {
                Address* temp = addresses[i];
                addresses[i] = addresses[i + 1];
                addresses[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    
    int count;
    std::string city, street;
    int house, flat;

    std::ifstream in("in.txt");
    in >> count;

    Address** adresses = new Address * [count];

    for (int i = 0; i < count; i++)
    {
        in >> city >> street >> house >> flat;
        adresses[i] = new Address(city, street, house, flat);
    }
    in.close();

    buble_sort(adresses, count);

    std::ofstream out("out.txt");
    out << count << std::endl;

    for (int i = count - 1; i >= 0; i--)
    {
        out << adresses[i]->get_address() << std::endl;
    }
    out.close();

    for (int i = 0; i < count; i++)
    {
        delete adresses[i];
    }
    delete[] adresses;

    return 0;
}