#ifndef FIXEDCUBE_HH
#define FIXEDCUBE_HH

#include <boost/shared_ptr.hpp>

namespace Rubik
{
  class CubeData
  {
  };

  /**
   * A cube that cannot be rotated
   *
   * This cube never changes orientation. I.e. the center squares of
   * each of the six sides always stay in the same place.  The only
   * operations that are supported is rotating each of the six sides a
   * quarter turn clockwise.
   */
  class FixedCube
  {
  public:
    typedef boost::shared_ptr<FixedCube> Ptr;

  public:
    static Ptr create(CubeData const& data);
  };
}

#endif
