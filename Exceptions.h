#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

// Власний БАЗОВИЙ клас винятку
class TimeException : public std::runtime_error {
public:
    explicit TimeException(const std::string& msg) 
        : std::runtime_error(msg) {}
};

// Власний клас-НАЩАДОК
class ClockValueException : public TimeException {
private:
    int invalidValue;
public:
    ClockValueException(const std::string& msg, int val) 
        : TimeException(msg), invalidValue(val) {}
    
    int getVal() const { return invalidValue; }
};

#endif