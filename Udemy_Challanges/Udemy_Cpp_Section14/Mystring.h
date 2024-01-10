#pragma once
#include <iostream>
class Mystring
{
private:
    char* str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char* s);                                     // Overloaded constructor
    Mystring(const Mystring& source);                    // Copy constructor
    Mystring(Mystring&& source) noexcept;                         // Move constructor
    ~Mystring();                                                     // Destructor

    Mystring& operator=(const Mystring& rhs);     // Copy assignment
    Mystring& operator=(Mystring&& rhs) noexcept;           // Move assignment

    void display() const;

    int get_length() const;                                      // getters
    const char* get_str() const;

    // Overloaded operators
    Mystring operator-() const;
    Mystring& operator++();
    Mystring operator++(int);

    bool operator==(const Mystring& rhs) const;
    bool operator!=(const Mystring& rhs) const;
    bool operator<(const Mystring& rhs) const;
    bool operator>(const Mystring& rhs) const;

    Mystring operator+(const Mystring& rhs) const;
    Mystring& operator+=(const Mystring& rhs);
    Mystring operator*(int value) const;
    Mystring& operator*=(int value);


    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);
};

