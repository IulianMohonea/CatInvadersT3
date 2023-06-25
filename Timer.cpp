template<typename T>
Timer<T>::Timer(T timer_) : timer(timer_) {}

template<typename T>
Timer<T>::Timer(const Timer& other) : timer(other.timer) {}

template<typename T>
Timer<T>& Timer<T>::operator=(const Timer& other) {
    timer = other.timer;
    return *this;
}

template<typename T>
T Timer<T>::get_time() {
    return timer;
}

template<typename T>
void Timer<T>::set_time(T dt) {
    timer = dt;
}

template<typename T>
Timer<T>::~Timer() = default;
