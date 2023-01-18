#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ProductionCode)
{
  RUN_TEST_CASE(ProductionCode, DetectSignal);
  RUN_TEST_CASE(ProductionCode, TooShortSignal);
  // RUN_TEST_CASE(ProductionCode, ProperSignal);
}