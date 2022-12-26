#include "unity.h"
#include "unity_fixture.h"
#include "fff.h"
#include "vbat.h"

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(IO_MEM_WR8, uint32_t, uint8_t);
FAKE_VALUE_FUNC(uint8_t, IO_MEM_RD8, uint32_t);

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
