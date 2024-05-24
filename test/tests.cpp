#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "concrete_component.h"

using namespace testing;

// Тест для проверки имени напитка
TEST(HouseBlendTest, NameTest) {
    HouseBlend houseBlend;
    EXPECT_EQ(houseBlend.Name(), "HouseBlend");
}

// Тест для проверки стоимости напитка
TEST(HouseBlendTest, CostTest) {
    HouseBlend houseBlend;
    EXPECT_DOUBLE_EQ(houseBlend.Cost(), 30.0);
}

// Тест для проверки, что класс HouseBlend является наследником интерфейса IBeverage
TEST(HouseBlendTest, InheritanceTest) {
    HouseBlend houseBlend;
    IBeverage* beverage = dynamic_cast<IBeverage*>(&houseBlend);
    EXPECT_TRUE(beverage != nullptr);
}
