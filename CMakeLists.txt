cmake_minimum_required(VERSION 3.10)
project(ClockProject)

# Встановлюємо стандарт C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Пошук Google Test (має бути встановлений через brew або apt)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 2. Створення бібліотеки з логікою (Clock.cpp + Exceptions.h)
# Це дозволяє не комбілювати одні й ті самі файли двічі
add_library(ClockLib Clock.cpp)

# 3. Основна програма (Ваш main.cpp для демонстрації лаби)
add_executable(clock_app main.cpp)
target_link_libraries(clock_app ClockLib)

# 4. Модульні тести (UnitTest.cpp)
add_executable(UnitTest UnitTest.cpp)

# Важливо: лінкуємо з GTest::gtest та GTest::gtest_main
# GTest::gtest_main автоматично додає функцію main() для запусків тестів
target_link_libraries(UnitTest
        ClockLib
        GTest::gtest
        GTest::gtest_main
        pthread
)

# 5. Реєстрація тестів у системі
enable_testing()
add_test(NAME AllClockTests COMMAND UnitTest)