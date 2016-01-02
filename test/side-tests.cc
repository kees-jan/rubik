#include <side.hh>

#include <gtest/gtest.h>

using namespace Rubik;

namespace SideData
{
  const Side::Data top =
    {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9
    };
}

TEST(Side, Initialize)
{
  Side::Data data = {0};
  Orientation orientation = top(1).left(2).bottom(3).right(4);
  
  Side::Ptr side = Side::create(data, orientation);

  EXPECT_EQ(data, side->data());
}

TEST(Side, Perspective_top)
{
  Orientation orientation = top(1).left(2).bottom(3).right(4);
  
  Side::Ptr side = Side::create(SideData::top, orientation);

  EXPECT_EQ(SideData::top, side->data(1));
}

