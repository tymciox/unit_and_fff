#include "unity.h"
#include "unity_fixture.h"
#include "fff.h"
#include "vbat.h"
#include "gpio_control.h"

// Początkowo stan niski
// Trzy sygnały prostokątne w ciągu 3s
// Każdy stan wysoki i niski trwa co najmniej 200 ms
// Po wykryciu sygnału moduł kończy działanie i zawsze zwraca informację o wykryciu
// Przed wykryciem sygnału moduł zwraca informację, że sygnał nie został wykryty
// Pamiętaj o szczególnych przypadkach np. zakłócenie + reszta sygnału

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(IO_MEM_WR8, uint32_t, uint8_t);
FAKE_VALUE_FUNC(gpio_state_t, get_gpio_state, uint32_t);

TEST_GROUP(ProductionCode);

TEST_SETUP(ProductionCode)
{
  detection_init();
  get_gpio_state_fake.return_val = GPIO_LOW_STATE;
}

TEST_TEAR_DOWN(ProductionCode)
{

}

#define MS_TO_TICK(a) (a/TICK_MS)

void wait_ms(int duration)
{
  for (int i = 0; i < MS_TO_TICK(duration); i++)
  {
    detection();
  }
}

TEST(ProductionCode, DetectSignal)
{
  get_gpio_state_fake.return_val = GPIO_HIGH_STATE;
  wait_ms(200);
  get_gpio_state_fake.return_val = GPIO_LOW_STATE;
  wait_ms(200);
  TEST_ASSERT_EQUAL_INT(1, detection());
}

TEST(ProductionCode, TooShortSignal)
{
  get_gpio_state_fake.return_val = GPIO_HIGH_STATE;
  wait_ms(100);
  get_gpio_state_fake.return_val = GPIO_LOW_STATE;
  wait_ms(200);
  TEST_ASSERT_EQUAL_INT(0, detection());
}

// TEST(ProductionCode, ProperSignal)
// {
//   for (int i=0; i<3; i++)
//   {
//     get_gpio_state_fake.return_val = GPIO_HIGH_STATE;
//     wait_ms(200);
//     get_gpio_state_fake.return_val = GPIO_LOW_STATE;
//     wait_ms(200);
//   }
//   TEST_ASSERT_EQUAL_INT(1, detection());
// }

