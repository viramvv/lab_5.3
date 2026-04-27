#include <gtest/gtest.h>
#include "Clock.h"
#include "Exceptions.h"

// 1. Тест на коректне створення (без винятків)
TEST(ClockLogic, ValidCreation) {
    EXPECT_NO_THROW({
        Clock c(12, 30, 0);
    });
}

// 2. Тест на стандартний виняток (out_of_range)
TEST(ClockExceptions, StandardExceptionOnNegative) {
    EXPECT_THROW({
        Clock c(-5, 0, 0);
    }, std::out_of_range);
}

// 3. Тест на власний виняток-нащадок (ClockValueException)
TEST(ClockExceptions, CustomChildExceptionValue) {
    try {
        Clock c(25, 0, 0);
        FAIL() << "Виняток ClockValueException мав бути згенерований";
    } catch (const ClockValueException& e) {
        // ПЕРЕВІРКА ЗНАЧЕННЯ
        EXPECT_EQ(e.getVal(), 25);

        // ПЕРЕВІРКА ТЕКСТУ (синхронізовано з Clock.cpp)
        // Використовуємо std::string для порівняння, щоб уникнути проблем з кодуванням
        EXPECT_STREQ(e.what(), "Помилка годин");
    } catch (...) {
        FAIL() << "Згенеровано невірний тип винятку";
    }
}

// 4. Тест на оператор приведення (TimeException)
TEST(ClockExceptions, ConversionOperatorThrowsBase) {
    Clock c(10, 10, 10);
    // Перевіряємо за базовим класом TimeException
    EXPECT_THROW({
        c.operator ITime&();
    }, TimeException);
}