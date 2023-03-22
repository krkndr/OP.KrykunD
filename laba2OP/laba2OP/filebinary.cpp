#define _CRT_SECURE_NO_WARNINGS
#define _XOPEN_SOURCE
#include "filebinary.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <chrono>

using namespace std;

struct Car {
    char name[100];
    char manufacture_date[11];
    char sale_date[11];
};

struct Date {
    int year;
    int month;
    int day;
};

void writeBinary()
{
    ofstream output("input.dat", ios::out | ios::binary | ios::trunc);
    if (!output.is_open()) {
        cout << "Error opening the file!\n";
        return;
    }
    do {
        char c;
        Car Wcar;
        cout << "Enter the name: ";
        cin >> Wcar.name;
        cout << "Enter the manufacture date: ";
        cin >> Wcar.manufacture_date;
        cout << "Enter the sale date: ";
        cin >> Wcar.sale_date;
        output.write(reinterpret_cast<const char*>(&Wcar), sizeof(Wcar));
        cout << "Continiue? y/n: ";
        cin >> c;
        if (c == 'n' || c == 'N') {
            break;
        }
    } while (true);
    output.close();
}

void readBinary(string name)
{
    ifstream file(name, ios::binary);
    if (!file.is_open()) {
        cout << "Failed to open file.\n";
        return;
    }
    cout << "---------------------------------------------------\n";
    cout << "Name\t\tManufacture Date\tSale Date\n";
    cout << "---------------------------------------------------\n";
    Car rCar;
    while (file.read(reinterpret_cast<char*>(&rCar), sizeof(rCar))) {
        // Виводимо дані структури у форматі таблиці
        cout << rCar.name << "\t\t"
            << rCar.manufacture_date << "\t\t"
            << rCar.sale_date << endl;
    }
    cout << "---------------------------------------------------\n\n";
    file.close();
}

time_t parseDate(const std::string& dateStr)
{
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%d.%m.%Y");
    return std::mktime(&tm);
}

void data(string inputName, string outputName)
{
    ifstream in(inputName, ios::binary);
    if (!in.is_open()) {
        cout << "Failed to open input file.\n";
        return;
    }
    ofstream out(outputName, ios::binary);
    if (!out.is_open()) {
        cout << "Failed to create output file.\n";
        in.close();
        return;
    }
    Car car;
    while (in.read(reinterpret_cast<char*>(&car), sizeof(car))) {
        int daysDiff = (int)difftime(parseDate(car.sale_date), parseDate(car.manufacture_date)) / (24 * 3600);
        if (daysDiff <= 60) {
            out.write(reinterpret_cast<char*>(&car), sizeof(car));
        }
    }
    in.close();
    out.close();
}

int inputYear()
{
    int year;
    cout << "Enter year: ";
    cin >> year;
    return year;
}

void findCar(string inputName, int inputYear)
{
    ifstream in(inputName, ios::binary);
    if (!in.is_open()) {
        cout << "Failed to open input file.\n";
        return;
    }
    cout << "A list of machines that were manufactured no earlier than the specified year:" << endl;
    cout << "---------------------------------------------------\n";
    cout << "Name\t\tManufacture Date\tSale Date\n";
    cout << "---------------------------------------------------\n";
    Car car;
    while (in.read(reinterpret_cast<char*>(&car), sizeof(car))) {
        int year = stoi(string(car.manufacture_date + 6, 4));
        if (year >= inputYear) {
            cout << car.name << "\t\t"
                << car.manufacture_date << "\t\t"
                << car.sale_date << endl;
        }
    }
    cout << "---------------------------------------------------\n\n";
    in.close();
}

void addBinary(string addName)
{
    ofstream add(addName, ios::binary | ios::app);
    if (!add.is_open()) {
        cout << "Failed to open input file.\n";
        return;
    }
    do {
        char c;
        Car Acar;
        cout << "Enter the name: ";
        cin >> Acar.name;
        cout << "Enter the manufacture date: ";
        cin >> Acar.manufacture_date;
        cout << "Enter the sale date: ";
        cin >> Acar.sale_date;
        add.write(reinterpret_cast<const char*>(&Acar), sizeof(Acar));
        cout << "Continiue? y/n: ";
        cin >> c;
        if (c == 'n' || c == 'N') {
            break;
        }
    } while (true);
    add.close();
    

}