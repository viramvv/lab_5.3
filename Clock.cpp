#include "Clock.h"
#include "Exceptions.h"
#include <iostream>
#include <iomanip>

Clock::Clock(int hours, int minutes, int seconds) : h(hours), m(minutes), s(seconds) {
    if (hours < 0 || minutes < 0 || seconds < 0)
        throw std::out_of_range("Від'ємний час!"); 

    if (hours > 23) throw ClockValueException("Помилка годин", hours);
    if (minutes > 59) throw ClockValueException("Помилка хвилин", minutes);
    if (seconds > 59) throw ClockValueException("Помилка секунд", seconds);
}

void Clock::display() const {
    std::cout << std::setfill('0') << std::setw(2) << h << ":" 
              << std::setw(2) << m << ":" << std::setw(2) << s << std::endl;
}

Clock::operator ITime&() {
    // Викидаємо базовий виняток для демонстрації
    throw TimeException("Виняток при приведенні типу через operator ITime&");
}