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
}

TEST_TEAR_DOWN(ProductionCode)
{
  FFF_FAKES_LIST(RESET_FAKE);
	FFF_RESET_HISTORY();
}

TEST(ProductionCode, FiveSignalBelowAlarm)
{
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL-1;

  for (int i=0; i<5; i++)
  {
    vbat_check();
  }
  TEST_ASSERT_EQUAL_INT(1, led_on_fake.call_count);
}

TEST(ProductionCode, FourSignalBelowAlarm1OverTreshold)
{
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL-1;
  for (int i=0; i<4; i++)
  {
    vbat_check();
  }
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL;
  vbat_check();
  TEST_ASSERT_EQUAL_INT(0, led_on_fake.call_count);
}

TEST(ProductionCode, FiveSignalBelowAlarm5OverTreshold)
{
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL-1;
  for (int i=0; i<5; i++)
  {
    vbat_check();
  }
  read_adc_fake.return_val = ALARM_THRESHOLD_LEVEL;
  for (int i=0; i<5; i++)
  {
    vbat_check();
  }
  TEST_ASSERT_EQUAL_INT(1, led_off_fake.call_count);
  TEST_ASSERT_TRUE(led_on_fake.call_count > 0);
}

TEST(ProductionCode, LedIsOffAfterStart)
{
  TEST_ASSERT_EQUAL_INT(1, led_off_fake.call_count);
}

