#include <iostream>
#include "Clock.h"
#include "Exceptions.h"

int main() {
    // --- 1. ПЕРХОПЛЕННЯ ЗА ПОСИЛАННЯМ  ---
    // Дозволяє уникнути копіювання та зберегти поліморфізм
    try {
        std::cout << "Спроба 1 (Валідація): ";
        Clock c(25, 0, 0);
    }
    catch (const ClockValueException& e) {
        std::cout << "Спіймано [За посиланням на нащадка]: " << e.what()
                  << " Значення: " << e.getVal() << std::endl;
    }

    // --- 2. ПЕРХОПЛЕННЯ ЗА ЗНАЧЕННЯМ  ---
    // Об'єкт копіюється, дані нащадка "зрізаються"
    try {
        std::cout << "Спроба 2 (Зрізання): ";
        throw ClockValueException("Тест зрізання", 99);
    }
    catch (TimeException e) {
        // Тут ми втратили доступ до .getVal(), бо e - це копія базового класу
        std::cout << "Спіймано [За значенням]: " << e.what() << std::endl;
    }

    // --- 3. ПЕРХОПЛЕННЯ ЗА ОБ'ЄКТОМ ВИНЯТКУ  ---
    try {
        std::cout << "Спроба 3 (Оператор): ";
        Clock c(12, 30, 0);
        c.operator ITime&(); // Функціональний виклик
    }
    catch (const TimeException& e) {
        std::cout << "Спіймано [Власний базовий виняток]: " << e.what() << std::endl;
    }

    // --- 4. ПЕРХОПЛЕННЯ ЗА СТАНДАРТНИМ ВИНИТКОМ ---
    try {
        std::cout << "Спроба 4 (Стандарт): ";
        Clock c(-1, 0, 0);
    }
    catch (const std::exception& e) {
        std::cout << "Спіймано [Стандартний std::exception]: " << e.what() << std::endl;
    }

    // --- 5. ПЕРХОПЛЕННЯ ЗА БУДЬ-ЯКИМ ТИПОМ ---
    try {
        throw "Неочікувана помилка";
    }
    catch (...) {
        std::cout << "Спіймано [Універсальний catch(...)]" << std::endl;
    }

    return 0;
}