#ifndef TIMER_H
#define TIMER_H

template<typename T>
class Timer {
private:
    T timer;

public:
    explicit Timer(T timer_);

    Timer(const Timer& other);

    Timer& operator=(const Timer& other);

    T get_time();

    void set_time(T dt);

    ~Timer();
};

#include "Timer.cpp" // Includem fisierul .cpp pentru a evita erorile de linker

#endif // TIMER_H
