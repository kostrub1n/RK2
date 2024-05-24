#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "concrete_component.h"
#include "decorator.h"

TEST(HouseBlendTest, NameTest) {
    HouseBlend houseBlend;
    EXPECT_EQ(houseBlend.Name(), "HouseBlend");
}

TEST(HouseBlendTest, CostTest) {
    HouseBlend houseBlend;
    EXPECT_DOUBLE_EQ(houseBlend.Cost(), 30.0);
}

TEST(DarkRoastTest, NameTest) {
    DarkRoast darkRoast;
    EXPECT_EQ(darkRoast.Name(), "DarkRoast");
}

TEST(DarkRoastTest, CostTest) {
    DarkRoast darkRoast;
    EXPECT_DOUBLE_EQ(darkRoast.Cost(), 28.5);
}

class MockBeverage : public IBeverage {
public:
    MOCK_METHOD0(Name, string());
    MOCK_METHOD0(Cost, double());
};

TEST(CondimentDecoratorTest, NameTest) {
    MockBeverage mockBeverage;
    CondimentDecorator condimentDecorator(&mockBeverage);

    EXPECT_CALL(mockBeverage, Name())
        .WillOnce(testing::Return("MockBeverage"));

    EXPECT_EQ(condimentDecorator.Name(), "MockBeverage");
}

TEST(CondimentDecoratorTest, CostTest) {
    MockBeverage mockBeverage;
    CondimentDecorator condimentDecorator(&mockBeverage);

    EXPECT_CALL(mockBeverage, Cost())
        .WillOnce(testing::Return(10.0));

    EXPECT_DOUBLE_EQ(condimentDecorator.Cost(), 10.0);
    
}
