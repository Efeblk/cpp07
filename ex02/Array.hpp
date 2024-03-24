#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class   Array
{
    private:
        T *array;
        unsigned int len;
    public:
        Array()
        {
            this->array = new T[0];
            this->len = 0;
        }
        ~Array()
        {
            delete this->array;
        }
        Array(unsigned int n)
        {
            this->array= new T[n];
            this->len = n;
        }
        Array(const Array &copy)
        {
            this->len = copy.len;
            this->array = new T[copy.len];
            for (unsigned int i = 0; i < this->len; i++)
                this->array[i] = copy.array[i];
        }
        Array &operator=(const Array &copy)
		{
			if (this != copy)
			{
				delete[] this->array;
				this->len = copy.len;
				this->array = new T[copy.len];
				for(unsigned int i = 0; i < this->len; i++)
				{
					this->array[i] = copy.array[i];
				}
			}
		}
        T& operator[] (unsigned int index)
        {
            if(index >= this->len)
                throw std::out_of_range("Index out of range");
            else
                return this->array[index];
        }
        unsigned int size() const
        {
            return this->len;
        }
};

#endif