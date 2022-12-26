#include "unity.h"
#include "unity_fixture.h"
#include "fff.h"
#include "vbat.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(adc_raw_t, read_adc);
FAKE_VOID_FUNC(led_init);
FAKE_VOID_FUNC(led_on);
FAKE_VOID_FUNC(led_off);

#define FFF_FAKES_LIST(FAKE) \
  FAKE(read_adc) \
  FAKE(led_init) \
  FAKE(led_on) \
  FAKE(led_off)


TEST_GROUP(ProductionCode);

TEST_SETUP(ProductionCode)
{
  vbat_init();

  FFF_FAKES_LIST(RESET_FAKE);
	FFF_RESET_HISTORY();
}

TEST_TEAR_DOWN(ProductionCode)
{

}

TEST(ProductionCode, FiveSignalBelowAlarm)
{
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL-1;

  for (int i=0; i<5; i++)
  {
    vbat_check();
  }
  TEST_ASSERT_EQUAL_INT(1, vbat_check_alarm_state());
}

TEST(ProductionCode, FourSignalBelowAlarm1OverTreshold)
{
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL-1;
  for (int i=0; i<4; i++)
  {
    vbat_check();
  }
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL;
  TEST_ASSERT_EQUAL_INT(0, vbat_check_alarm_state());
}

TEST(ProductionCode, LedIsOffAfterStart)
{
  TEST_ASSERT_EQUAL_INT(1, led_init_fake.call_count);
}

