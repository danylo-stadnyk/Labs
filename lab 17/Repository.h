#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include "Microcontroller.h"



template <typename T>
class Repository
{
private:
    T m_value;

public:
    Repository(const T& value);
    ~Repository();

    const T& get() const;
    void set(const T& value);

    void print() const; 
};



template <typename T>
Repository<T>::Repository(const T& value)
    : m_value(value)
{
}

template <typename T>
Repository<T>::~Repository()
{
}

template <typename T>
const T& Repository<T>::get() const
{
    return m_value;
}

template <typename T>
void Repository<T>::set(const T& value)
{
    m_value = value;
}

template <typename T>
void Repository<T>::print() const
{
    std::cout << "[Загальний шаблон Repository<T>] Значення: " << m_value << "\n";
}





template <typename T>
class Repository<T*>
{
private:
    T* m_ptr;

public:
    Repository(T* ptr);
    ~Repository();

    T* get() const;
    void set(T* ptr);

    void print() const; 
};



template <typename T>
Repository<T*>::Repository(T* ptr)
    : m_ptr(ptr)
{
}

template <typename T>
Repository<T*>::~Repository()
{
  
}

template <typename T>
T* Repository<T*>::get() const
{
    return m_ptr;
}

template <typename T>
void Repository<T*>::set(T* ptr)
{
    m_ptr = ptr;
}

template <typename T>
void Repository<T*>::print() const
{
    std::cout << "[Часткова спеціалізація Repository<T*>]\n";
    if (m_ptr)
    {
        std::cout << "  Адреса об'єкта: " << static_cast<const void*>(m_ptr) << "\n";
    }
    else
    {
        std::cout << "  Вказівник дорівнює nullptr\n";
    }
}





template <>
class Repository<Microcontroller>
{
private:
    Microcontroller m_value;

public:
    Repository(const Microcontroller& value);
    ~Repository();

    const Microcontroller& get() const;
    void set(const Microcontroller& value);

    void print() const; 
};



inline Repository<Microcontroller>::Repository(const Microcontroller& value)
    : m_value(value)
{
}

inline Repository<Microcontroller>::~Repository()
{
}

inline const Microcontroller& Repository<Microcontroller>::get() const
{
    return m_value;
}

inline void Repository<Microcontroller>::set(const Microcontroller& value)
{
    m_value = value;
}

inline void Repository<Microcontroller>::print() const
{
    std::cout << "[Повна спеціалізація Repository<Microcontroller>]\n";
    m_value.printInfo();
}





template <typename T>
T maxValue(const T& a, const T& b)
{
    return (a > b) ? a : b;
}


template <>
inline double maxValue<double>(const double& a, const double& b)
{
    std::cout << "[Спеціалізація maxValue<double>]: обчислення максимуму для double\n";
    return (a > b) ? a : b;
}

#endif 
