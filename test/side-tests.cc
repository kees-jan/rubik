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
  const Side::Data left =
    {
      7, 4, 1,
      8, 5, 2,
      9, 6, 3,
    };
}

TEST(Side, Initialize)
{
  Side::Data data = {0};
  Orientation orientation = top(1).left(2).bottom(3).right(4);
  
  Side::Ptr side = Side::create(data, orientation);

  EXPECT_EQ(data, side->data());
}

class PerspectiveData
{
public:
  Side::Data top;
  Side::Data bottom;
  Side::Data left;
  Side::Data right;

public:
  PerspectiveData(Side::Data const& top, Side::Data const& bottom, Side::Data const& left, Side::Data const& right)
    :top(top), bottom(bottom), left(left), right(right)
  {}
};

class SidePerspective : public testing::TestWithParam<PerspectiveData>
{
};

INSTANTIATE_TEST_CASE_P(Combinatorial, SidePerspective,
                        testing::Values(PerspectiveData(SideData::top, SideData::bottom, SideData::left, SideData::right)));
                                                               

TEST_P(SidePerspective, Top)
{
  PerspectiveData const& data = GetParam();
  Orientation orientation = top(1).left(2).bottom(3).right(4);
  
  Side::Ptr side = Side::create(data.top, orientation);

  EXPECT_EQ(data.top, side->data(1));
}

TEST_P(SidePerspective, Bottom)
{
  PerspectiveData const& data = GetParam();
  Orientation orientation = top(1).left(2).bottom(3).right(4);

  Side::Ptr side = Side::create(data.top, orientation);

  EXPECT_EQ(data.bottom, side->data(3));
}

TEST_P(SidePerspective, Right)
{
  PerspectiveData const& data = GetParam();
  Orientation orientation = top(1).left(2).bottom(3).right(4);

  Side::Ptr side = Side::create(data.top, orientation);

  EXPECT_EQ(data.right, side->data(4));
}

