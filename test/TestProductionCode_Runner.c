#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ProductionCode)
{
  RUN_TEST_CASE(ProductionCode, FiveSignalBelowAlarm);
  RUN_TEST_CASE(ProductionCode, FourSignalBelowAlarm1OverTreshold);
  RUN_TEST_CASE(ProductionCode, LedIsOffAfterStart);
}