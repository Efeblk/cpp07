#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class   Array
{
    private:
        T *Arr;
        unsigned int size;
    public:
        Array()
        {
            this->Arr = new T[0];
        }
        ~Array()
        {
            delete this->Arr;
        }
        Array(unsigned int n)
        {
            this->Arr = new T[n];
            this->size = n;
        }
        Array(const Array &copy, unsigned int n)
        {
            this->Arr = new T[n];
            for (unsigned int i = 0; i < n; i++)
                this->Arr[i] = copy.Arr[i];
        }
        Array& operator= (const Array &copy)
        {
            this->Arr = new T[this->size];
            for (int i = 0; i < this->size ; i++)
                this->Arr[i] = copy.Arr[i];
            return *this;
        }
        T& operator[] (unsigned int index)
        {
            if(index >= this->size)
                throw std::out_of_range("Index out of range");
            else
                return this->Arr[index];
        }
};

#endif