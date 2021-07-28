#include <PrimeNumber.Core/PrimeNumberCalculator.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;


template<typename T>
class PrimeNumberCalculatorTest : public Test
{
protected:
	void SetUp() override
	{
		calc = new PrimeNumberCalculator();
	}
	void TearDown() override
	{
		delete calc;
	}

	PrimeNumberCalculator* calc;
	std::vector<T> result;
};

using MyTypes = ::testing::Types<size_t, int, float, double>;
TYPED_TEST_SUITE(PrimeNumberCalculatorTest, MyTypes);

TYPED_TEST(PrimeNumberCalculatorTest, Returns_6_Numbers_When_N_Equal_15)
{
	result = calc->GetPrimeNumbers<TypeParam>(15);
	EXPECT_THAT(result.size(), 6);
}

////////////////////////////////////////////////////////////////////

class PrimeNumberCalculatorTestNotTemplate : public Test
{
protected:
	void SetUp() override
	{
		calc = new PrimeNumberCalculator();
	}
	void TearDown() override
	{
		delete calc;
	}

	PrimeNumberCalculator* calc;
	std::vector<size_t> result;
};


class PrimeNumberCalculatorTestWithParams :public PrimeNumberCalculatorTestNotTemplate, public WithParamInterface<size_t>
{

};

TEST_P(PrimeNumberCalculatorTestWithParams, Returns_6_Numbers_When_N_Equal_16_15_14_13)
{
	result = calc->GetPrimeNumbers<size_t>(GetParam());
	EXPECT_THAT(result.size(), 6);
}
INSTANTIATE_TEST_SUITE_P(Returns_6, PrimeNumberCalculatorTestWithParams, Values(16, 15, 14, 13));


class PrimeNumberCalculatorTestWithParams2 :public PrimeNumberCalculatorTestNotTemplate, public WithParamInterface<size_t>
{

};

TEST_P(PrimeNumberCalculatorTestWithParams2, Returns_0_Numbers_When_N_Equal_0_1)
{
	result = calc->GetPrimeNumbers<size_t>(GetParam());
	EXPECT_THAT(result.size(), 0);
}
INSTANTIATE_TEST_SUITE_P(Returns_6, PrimeNumberCalculatorTestWithParams2, Values(0,1));


TEST_F(PrimeNumberCalculatorTestNotTemplate, Returns_0_Numbers_When_N_Equal_0)
{
	result = calc->GetPrimeNumbers<size_t>(0);

	EXPECT_THAT(result.size(), 0);
}




