#ifndef CLOCK_H
#define CLOCK_H

class ITime {
public:
    virtual void display() const = 0;
    virtual ~ITime() {}
};

class Clock : public ITime {
private:
    int h, m, s;
public:
    Clock(int hours, int minutes, int seconds);
    void display() const override;

    // Оператор для демонстрації винятку
    operator ITime&();
};

#endif