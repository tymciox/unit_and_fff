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

TEST(ProductionCode, FiveSignalBelowAlarm)
{
  for (int i=0; i<5; i++)
  {
    vbat_check(ADC_LEVEL_BELOW_THRESHOLD);
  }
  TEST_ASSERT_EQUAL_INT(1, vbat_check_alarm_state());
}

