#include "unity.h"
#include "unity_fixture.h"
#include "fff.h"
#include "vbat.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(adc_raw_t, adc_read);
FAKE_VOID_FUNC(IO_MEM_RD8, uint32_t);

TEST_GROUP(ProductionCode);

TEST_SETUP(ProductionCode)
{

}

TEST_TEAR_DOWN(ProductionCode)
{

}

TEST(ProductionCode, FiveSignalBelowAlarm)
{
  adc_read_fake.return_val = ALARM_THRESHOLD_LEVEL-1;

  for (int i=0; i<5; i++)
  {
    vbat_check();
  }
  TEST_ASSERT_EQUAL_INT(1, vbat_check_alarm_state());
}

TEST(ProductionCode, FourSignalBelowAlarm1OverTreshold)
{
  adc_read_fake.return_val = ALARM_THRESHOLD_LEVEL-1;
  for (int i=0; i<4; i++)
  {
    vbat_check();
  }
  adc_read_fake.return_val = ALARM_THRESHOLD_LEVEL;
  TEST_ASSERT_EQUAL_INT(0, vbat_check_alarm_state());
}

