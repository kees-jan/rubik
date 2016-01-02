#include <side.hh>

namespace Rubik
{
  Side::Ptr Side::create(Side::Data const& data)
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

}
