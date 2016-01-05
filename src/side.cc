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
    switch(top)
    {
    case 1:
      return data();
    case 3:
      return
        {
          data_[8], data_[7], data_[6],
          data_[5], data_[4], data_[3],
          data_[2], data_[1], data_[0],
        };
    case 4:
      return
      {
          data_[2], data_[5], data_[8],
          data_[1], data_[4], data_[7],
          data_[0], data_[3], data_[6],
        };
    default:
      defect();
    }
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
