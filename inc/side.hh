#ifndef SIDE_HH
#define SIDE_HH

#include <array>
#include <boost/shared_ptr.hpp>

namespace Rubik
{
  class Side
  {
  public:
    typedef boost::shared_ptr<Side> Ptr;
    typedef std::array<int,9> Data;

  private:
    Data data_;
    
  public:
    static Ptr create(Data const& data);
    Side(Data const& data);

    Data data();
  };
}

#endif
