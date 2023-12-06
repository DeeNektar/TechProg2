#pragma once

/*Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает из текстового файла три предложения и выводит их в
обратном порядке*/

#include <sstream>
#include <fstream>
#include <iostream>
void threeSentence() {
    std::ifstream in;

    in.open("Text.txt");

    try {
        if (!in.is_open()) throw std::exception("File don't open\n");

        setlocale(LC_ALL, "rus");

        std::string str0;
        std::string str1;
        std::string str2;

        getline(in, str0);
        getline(in, str1);
        getline(in, str2);

        std::cout << str2 << '\n';
        std::cout << str1 << '\n';
        std::cout << str0 << '\n';

        in.close();
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
        in.close();
    }
}