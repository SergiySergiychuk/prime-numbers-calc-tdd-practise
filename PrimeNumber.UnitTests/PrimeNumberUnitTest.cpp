#include <PrimeNumber.Core/PrimeNumberCalculator.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;

TEST(PrimeNumberCalculator_GetPrimeNumbers, Returns_6_Numbers_When_N_Equal_15)
  {
  PrimeNumberCalculator calc;

  const auto result = calc.GetPrimeNumbers(15);

  EXPECT_THAT(result.size(),6);
  }
TEST(PrimeNumberCalculator_GetPrimeNumbers, Returns_0_Numbers_When_N_Equal_0)
{
	PrimeNumberCalculator calc;

	const auto result = calc.GetPrimeNumbers(0);

	EXPECT_THAT(result.size(), 0);
}
TEST(PrimeNumberCalculator_GetPrimeNumbers, Returns_0_Numbers_When_N_Lower_Then_2)
{
	PrimeNumberCalculator calc;

	const auto result = calc.GetPrimeNumbers(0);

	EXPECT_THAT(result.size(), 0);
}
TEST(PrimeNumberCalculator_GetPrimeNumbers, Returns_25_Numbers_When_N_Equal_100)
{
	PrimeNumberCalculator calc;

	const auto result = calc.GetPrimeNumbers(100);

	EXPECT_THAT(result.size(), 25);
}


