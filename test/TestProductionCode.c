#include "unity.h"
#include "unity_fixture.h"
#include "vbat.h"

TEST_GROUP(ProductionCode);

TEST_SETUP(ProductionCode)
{

}

TEST_TEAR_DOWN(ProductionCode)
{

}

TEST(ProductionCode, TestFunctionShouldDoBlahAndBlah)
{
  TEST_ASSERT_EQUAL_INT(2, 2);
}
TEST(ProductionCode, TestFunctionShouldAlsoDoBlah)
{
  TEST_ASSERT_EQUAL_INT(4, 2);
}
