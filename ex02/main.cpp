#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main()
{
    {
		Array<int> a;
		Array<int> b(5);
		for (unsigned int i = 0; i < b.size(); i++)
		{
			b[i] = i;
		}
		try
		{
			std::cout << "size A = " << a.size() << std::endl;
			std::cout << "size B = " << b.size() << std::endl;
			for (unsigned int i = 0; i < b.size(); i++)
			{
				std::cout << "B[" << i << "] = " << b[i] << std::endl;
			}
			std::cout << b[5] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }
    return 0;
}