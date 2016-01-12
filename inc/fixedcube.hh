#ifndef FIXEDCUBE_HH
#define FIXEDCUBE_HH

#include <boost/shared_ptr.hpp>

namespace Rubik
{
  class CubeData
  {
  };

  class FixedCube
  {
  public:
    typedef boost::shared_ptr<FixedCube> Ptr;

  public:
    static Ptr create(CubeData const& data);
  };
}

#endif
