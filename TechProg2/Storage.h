﻿#pragma once
#include "Aeroflot.h"
#include <iostream>
/*Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа TRAIN.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по времени отправления поезда;
● вывод на экран информации о поездах, направляющихся в пункт,
название которого введено с клавиатуры;
● если таких поездов нет, выдать на дисплей соответствующее
сообщение.*/

class Keeper {

private:

    class Element {        //  one Element in keeper
    public:
        Aeroflot* value;
        Element* prev;

        Element(Aeroflot* data, Element* prev = nullptr) {

            // std::cout << "Constructor Element\n";

            this->value = data;
            this->prev = prev;
        }
        ~Element() {

            //std::cout << "Destructor Element\n";

            delete this->value;
        }
    };
    int count;
    Element* head;
    Element* help;

public:
    Keeper() {

        //std::cout << "Constuctor Storage\n";

        count = 0;
        head = nullptr;
        help = nullptr;
    }


    ~Keeper() {

        // std::cout << "Destructor Storage\n";

        while (head != nullptr && count != 0) {
            help = head;
            head = head->prev;
            delete help;
            count--;
        }
        delete head;
    }

    int getCount() { return count; }

    Aeroflot& operator[] (const int index) {
        int cnt = getCount();
        Element* cur;
        cur = this->head;

        while (cur != nullptr) {
            if (cnt == index) {
                return  *(cur->value);
            }
            cur = cur->prev;
            cnt--;
        }
    }

    void addElement(Aeroflot* x) {
        if (head == nullptr) {
            head = new Element(x);
            head->value = x;
        }
        else {
            help = new Element(x);
            help->prev = head;
            head = help;
            head->value = x;
        }
        count++;
    }

    void deleteElement(const int index) {	//

        if (getCount() == 1) {	//1 elem = head
            delete this->head;
            head = nullptr;
            count--;
        }
        else if (index == getCount()) {	//last
            Element* cur = this->head;
            head = head->prev;
            delete cur;
            count--;
        }
        else {		//not last and >1 elem
            Element* cur = this->head;
            Element* current1 = this->head;
            int c = getCount();
            bool flag = 0;
            while (flag != 1) {
                if (c == index) {
                    int r = getCount();
                    while (r != (c + 1)) {
                        current1 = current1->prev;
                        r--;
                    }
                    Element* temp = cur;
                    cur = cur->prev;
                    current1->prev = cur;
                    delete temp;
                    flag = 1;
                    count--;

                }
                else {
                    cur = cur->prev;
                    c--;
                }
            }
        }
    }

    void sortTimeDeparture() {

        for (int i = 1;i < getCount() + 1;++i) {
            for (int j = 1;j < getCount();++j) {
                if (((*this)[j].getNameDestination()) > ((*this)[j + 1].getNameDestination())) {

                    std::swap((*this)[j], (*this)[j + 1]);

                }
            }
        }
    }

    void displayByTypeAerocraft() {
        try {
            if (getCount() == 0) throw std::exception("Storage is empty\n");

            std::string name = "";
            std::cout << "Required Type Aerocraft: ";
            while (!(std::cin >> name)) {
                std::cout << "Type Aerocraft: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                if (std::cin >> name)
                    break;
            }

            std::cout << "\nElements with Type Aerocraft = " << name << " :" << std::endl;

            int num = 0;
            for (int i = 1;i < getCount() + 1;i++) {
                if ((*this)[i].getTypeAerocraft() == name) {
                    std::cout << "Element #" << num << std::endl;
                    (*this)[i].getData();
                    num++;
                }
            }
            if (num == 0)
                std::cout << "\nNo Elements with Type Aerocraft = " << name << std::endl << std::endl;

        }
        catch (const std::exception& ex) {

            std::cout << ex.what() << '\n';
        }
    }

    void displayKeep() {
        try {
            if (getCount() == 0) throw std::exception("Storage is empty\n");

            for (int i = 1;i < getCount() + 1;i++) {                          //display from 1 to Count //slower
                std::cout << "Element #" << i << std::endl;
                (*this)[i].getData();
            }

            //std::cout << "\nCount of Elements: " << getCount() << std::endl << std::endl;
        }
        catch (const std::exception& ex) {

            std::cout << ex.what() << '\n';
        }
    }

    void editElement(const int index) {
        std::cout << "\nData\n";
        (*this)[index].setData();
    }
};