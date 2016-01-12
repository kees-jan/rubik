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

  std::array<int, 3> TopRow = {0, 1, 2};

  template<unsigned long n>
  std::array<int, n> transform(std::array<int, n> const& transformation, std::array<int, 9> const& data)
  {
    std::array<int, n> result;
    for(int i=0; i<n; i++)
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

  std::array<int, 9> Orientation::transformation(int top) const
  {
    std::map<int, std::array<int, 9> const> const transformations = boost::assign::map_list_of
      (this->top(), Identity)
      (this->left(), RotateRight)
      (this->bottom(), RotateHalf)
      (this->right(), RotateLeft);

    return transformations.at(top);
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

  Side::Ptr Side::create(Side::Data const& data, Orientation const& orientation)
  {
    return Ptr(new Side(data, orientation));
  }

  Side::Side(Side::Data const& data, Orientation const& orientation)
    : data_(data), orientation_(orientation)
  {}

  Side::Data Side::data()
  {
    return data_;
  }

  Side::Data Side::data(int top)
  {
    return transform(orientation_.transformation(top), data_);
  }

  Side::Row Side::topRow(int top)
  {
    return transform(TopRow, data(top));
  }

  std::ostream& operator<<(std::ostream& os, Side::Data const& data)
  {
    os << std::endl
       << '[' << data[0] << ' ' << data[1] << ' ' << data[2] << ']' << std::endl
       << '[' << data[3] << ' ' << data[4] << ' ' << data[5] << ']' << std::endl
       << '[' << data[6] << ' ' << data[7] << ' ' << data[8] << ']' << std::endl;
    
    return os;
  }

  std::ostream& operator<<(std::ostream& os, Orientation const& o)
  {
    os << '('
       << "Top: " << o.top_ << ", "
       << "Left: " << o.left_ << ", "
       << "Bottom: " << o.bottom_ << ", "
       << "Right: " << o.right_
       << ')';

    return os;
  }
}

