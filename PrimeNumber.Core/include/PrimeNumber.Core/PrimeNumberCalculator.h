#pragma once

#include <PrimeNumber.Core/PrimeNumber.Core.API.h>

#include <vector>

class PRIMENUMBERCORE_API PrimeNumberCalculator
  {
  public:
    PrimeNumberCalculator();

    std::vector<size_t> GetPrimeNumbers(size_t i_till_value);
  };

