#include <side.hh>

#include <scroom/assertions.hh>

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

  Orientation top(int t)
  {
    Orientation o;
    o.top_ = t;
    return o;
  }
  
  Orientation bottom(int b)
  {
    Orientation o;
    o.bottom_ = b;
    return o;
  }

  Orientation left(int l)
  {
    Orientation o;
    o.left_ = l;
    return o;
  }

  Orientation right(int r)
  {
    Orientation o;
    o.right_ = r;
    return o;
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
    switch(top)
    {
    case 1:
      return data();
    case 3:
      return
        {
          9, 8, 7,
          6, 5, 4,
          3, 2, 1,
        };
    default:
      defect();
    }
  }

}
