#include <PrimeNumber.Core/PrimeNumberCalculator.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;


template<typename T>
class PrimeNumberCalculatorTestTemplate : public Test
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
TYPED_TEST_SUITE(PrimeNumberCalculatorTestTemplate, MyTypes);

TYPED_TEST(PrimeNumberCalculatorTestTemplate, Returns_6_Numbers_When_N_Equal_15)
{
	result = calc->GetPrimeNumbers<TypeParam>(15);
	EXPECT_THAT(result.size(), 6);
}

////////////////////////////////////////////////////////////////////

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
	std::vector<size_t> result;
};


class PrimeNumberCalculatorTestWithParamsBase :public PrimeNumberCalculatorTest, public WithParamInterface<size_t>
{

};

class PrimeNumberCalculatorTestWithParams1 :public PrimeNumberCalculatorTestWithParamsBase
{

};

TEST_P(PrimeNumberCalculatorTestWithParams1, Returns_6_Numbers_When_N_Equal_16_15_14_13)
{
	result = calc->GetPrimeNumbers<size_t>(GetParam());
	EXPECT_THAT(result.size(), 6);
}
INSTANTIATE_TEST_SUITE_P(Returns_6, PrimeNumberCalculatorTestWithParams1, Values(16, 15, 14, 13));


class PrimeNumberCalculatorTestWithParams2 :public PrimeNumberCalculatorTestWithParamsBase
{

};

TEST_P(PrimeNumberCalculatorTestWithParams2, Returns_0_Numbers_When_N_Equal_0_1)
{
	result = calc->GetPrimeNumbers<size_t>(GetParam());
	EXPECT_THAT(result.size(), 0);
}
INSTANTIATE_TEST_SUITE_P(Returns_6, PrimeNumberCalculatorTestWithParams2, Values(0,1));

class PrimeNumberCalculatorTestWithParams3 :public PrimeNumberCalculatorTestWithParamsBase
{

};

TEST_P(PrimeNumberCalculatorTestWithParams3, Returns_0_Numbers_When_N_Equal_0_1)
{
	result = calc->GetPrimeNumbers<size_t>(GetParam());
	EXPECT_THAT(result.size(), 25);
}
INSTANTIATE_TEST_SUITE_P(Returns_6, PrimeNumberCalculatorTestWithParams3, Values(97,98, 99,100));


TEST_F(PrimeNumberCalculatorTest, Returns_0_Numbers_When_N_Equal_0)
{
	result = calc->GetPrimeNumbers<size_t>(0);

	EXPECT_THAT(result.size(), 0);
}




