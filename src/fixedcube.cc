#include <fixedcube.hh>

namespace Rubik
{
  CubeData top(Side::Data const& data)
  {
    CubeData c;
    return c.top(data);
  }
  
  CubeData bottom(Side::Data const& data)
  {
    CubeData c;
    return c.bottom(data);
  }
  
  CubeData left(Side::Data const& data)
  {
    CubeData c;
    return c.left(data);
  }
  
  CubeData right(Side::Data const& data)
  {
    CubeData c;
    return c.right(data);
  }
  
  CubeData front(Side::Data const& data)
  {
    CubeData c;
    return c.front(data);
  }
  
  CubeData back(Side::Data const& data)
  {
    CubeData c;
    return c.back(data);
  }

  CubeData& CubeData::top(Side::Data const& data)
  {
    top_ = data;
    return *this;
  }
  
  CubeData& CubeData::bottom(Side::Data const& data)
  {
    bottom_ = data;
    return *this;
  }
  
  CubeData& CubeData::left(Side::Data const& data)
  {
    left_ = data;
    return *this;
  }
  
  CubeData& CubeData::right(Side::Data const& data)
  {
    right_ = data;
    return *this;
  }
  
  CubeData& CubeData::front(Side::Data const& data)
  {
    front_ = data;
    return *this;
  }
  
  CubeData& CubeData::back(Side::Data const& data)
  {
    back_ = data;
    return *this;
  }

  bool CubeData::operator==(CubeData const& other) const
  {
    return
      top_ == other.top_ &&
      front_ == other.front_ &&
      left_ == other.left_ &&
      right_ == other.right_ &&
      bottom_ == other.bottom_ &&
      back_ == other.back_;
  }

  FixedCube::FixedCube(CubeData const& data)
    : data_(data)
  {
  }
  
  FixedCube::Ptr FixedCube::create(CubeData const& data)
  {
    return Ptr(new FixedCube(data));
  }

  CubeData FixedCube::data()
  {
    return data_;
  }
}
