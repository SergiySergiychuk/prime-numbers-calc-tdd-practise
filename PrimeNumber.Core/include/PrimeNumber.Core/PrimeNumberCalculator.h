#pragma once

#include <PrimeNumber.Core/PrimeNumber.Core.API.h>

#include <vector>

class PRIMENUMBERCORE_API PrimeNumberCalculator
{
public:
	PrimeNumberCalculator()
	{

	}
	template<typename T>
	std::vector<T> GetPrimeNumbers(size_t i_till_value)
	{
		if (i_till_value < 2) return std::vector<T>();
		std::vector<T> primeNumbers = { 2 };
		bool numberIsPrimar = true;

		for (int i = 3; i <= i_till_value; i++)
		{
			for (size_t elem : primeNumbers)
			{
				if (i % elem == 0)
				{
					numberIsPrimar = false;
					break;
				}
			}
			if (numberIsPrimar) primeNumbers.push_back(i);
			numberIsPrimar = true;
		}
		return primeNumbers;
	}
};

