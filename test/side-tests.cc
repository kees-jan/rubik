#include <side.hh>

#include <gtest/gtest.h>

using namespace Rubik;

namespace SideData
{
  const Side::Data top =
    {
      1, 2, 3,
      4, 5, 6,
      7, 8, 9,
    };
  const Side::Data bottom =
    {
      9, 8, 7,
      6, 5, 4,
      3, 2, 1,
    };
  const Side::Data right =
    {
      3, 6, 9,
      2, 5, 8,
      1, 4, 7,
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

TEST(Side, Perspective_bottom)
{
  Orientation orientation = top(1).left(2).bottom(3).right(4);

  Side::Ptr side = Side::create(SideData::top, orientation);

  EXPECT_EQ(SideData::bottom, side->data(3));
}

TEST(Side, Perspective_right)
{
  Orientation orientation = top(1).left(2).bottom(3).right(4);

  Side::Ptr side = Side::create(SideData::top, orientation);

  EXPECT_EQ(SideData::right, side->data(4));
}

