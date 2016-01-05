#include <side.hh>

#include <map>
#include <boost/assign.hpp>

#include <scroom/assertions.hh>


namespace
{
  std::array<int, 9> Identity =
    {
      0, 1, 2,
      3, 4, 5,
      6, 7, 8,
    };
  
  std::array<int, 9> RotateHalf =
    {
      8, 7, 6,
      5, 4, 3,
      2, 1, 0,
    };

  std::array<int, 9> RotateLeft =
    {
      2, 5, 8,
      1, 4, 7,
      0, 3, 6,
    };

  std::array<int, 9> RotateRight =
    {
      6, 3, 0,
      7, 4, 1,
      8, 5, 2,
    };

  std::array<int, 9> transform(std::array<int, 9> const& transformation, std::array<int, 9> const& data)
  {
    std::array<int, 9> result;
    for(int i=0; i<9; i++)
      result[i] = data[transformation[i]];
    return result;
  }
}

namespace Rubik
{
  Orientation& Orientation::top(int t)
  {
    top_ = t;
    return *this;
  }
  
  Orientation& Orientation::bottom(int b)
  {
    bottom_ = b;
    return *this;
  }

  Orientation& Orientation::left(int l)
  {
    left_ = l;
    return *this;
  }

  Orientation& Orientation::right(int r)
  {
    right_ = r;
    return *this;
  }

  int Orientation::top() const
  {
    return *top_;
  }
  
  int Orientation::bottom() const
  {
    return *bottom_;
  }
  
  int Orientation::left() const
  {
    return *left_;
  }
  
  int Orientation::right() const
  {
    return *right_;
  }

  Orientation top(int t)
  {
    Orientation o;
    return o.top(t);
  }
  
  Orientation bottom(int b)
  {
    Orientation o;
    return o.bottom(b);
  }

  Orientation left(int l)
  {
    Orientation o;
    return o.left(l);
  }

  Orientation right(int r)
  {
    Orientation o;
    return o.right(r);
  }
  
  Side::Ptr Side::create(Side::Data const& data, Orientation const&)
  {
    return Ptr(new Side(data));
  }

  Side::Side(Side::Data const& data)
    : data_(data)
  {}

  Side::Data Side::data()
  {
    return data_;
  }

  Side::Data Side::data(int top)
  {
    std::map<int, std::array<int, 9> const> const transformations = boost::assign::map_list_of
      (1, Identity)
      (2, RotateRight)
      (3, RotateHalf)
      (4, RotateLeft);

    std::map<int, std::array<int, 9> const>::const_iterator i = transformations.find(top);
    require(i != transformations.end());

    return transform(i->second, data_);
  }

}

std::ostream& operator<<(std::ostream& os, Rubik::Side::Data const& data)
{
  os << std::endl
     << '[' << data[0] << ' ' << data[1] << ' ' << data[2] << ']' << std::endl
     << '[' << data[3] << ' ' << data[4] << ' ' << data[5] << ']' << std::endl
     << '[' << data[6] << ' ' << data[7] << ' ' << data[8] << ']' << std::endl;
    
  return os;
}
