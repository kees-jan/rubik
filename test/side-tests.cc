#include <side.hh>

#include <tuple>

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
  PerspectiveData()
  {}
  
  PerspectiveData(Side::Data const& top, Side::Data const& bottom, Side::Data const& left, Side::Data const& right)
    :top(top), bottom(bottom), left(left), right(right)
  {}
};

std::ostream& operator<<(std::ostream& os, PerspectiveData const& data)
{
  os << std::endl;
  os << "Top:    " << data.top ;
  os << "Bottom: " << data.bottom;
  os << "Left:   " << data.left;
  os << "Right:  " << data.right;
  return os;
}

class SidePerspective : public testing::TestWithParam<std::tr1::tuple<Orientation,PerspectiveData> >
{
protected:
  Orientation const orientation;
  PerspectiveData const data;
  Side::Ptr const side;
  
public:
  SidePerspective()
    : orientation(std::tr1::get<0>(GetParam())),
      data(std::tr1::get<1>(GetParam())),
      side(Side::create(data.top, orientation))
  {}
};

INSTANTIATE_TEST_CASE_P
(Combinatorial, SidePerspective,
 testing::Combine(
                  testing::Values(top(1).left(2).bottom(3).right(4),
                                  top(5).left(3).bottom(1).right(0)),
                  testing::Values(PerspectiveData(SideData::top, SideData::bottom, SideData::left, SideData::right),
                                  PerspectiveData(SideData::left, SideData::right, SideData::bottom, SideData::top)
                                  )));
                                                               
TEST_P(SidePerspective, Top)
{
  EXPECT_EQ(data.top, side->data(orientation.top()));
}

TEST_P(SidePerspective, Bottom)
{
  EXPECT_EQ(data.bottom, side->data(orientation.bottom()));
}

TEST_P(SidePerspective, Right)
{
  EXPECT_EQ(data.right, side->data(orientation.right()));
}

TEST_P(SidePerspective, Left)
{
  EXPECT_EQ(data.left, side->data(orientation.left()));
}

TEST_P(SidePerspective, TopRowLeft)
{
  std::array<int, 3> expected = { data.left[0], data.left[1], data.left[2] };

  EXPECT_EQ(expected, side->topRow(orientation.left()));
}
