#include <side.hh>

#include <gtest/gtest.h>

using namespace Rubik;

TEST(Side, Initialize)
{
  Side::Data data = {0};
  
  Side::Ptr side = Side::create(data);
  
  // EXPECT_EQ(1, Factorial(0));
}
