#ifndef SIDE_HH
#define SIDE_HH

#include <boost/shared_ptr.hpp>

namespace Rubik
{
  class Side
  {
  public:
    typedef boost::shared_ptr<Side> Ptr;

  public:
    static Ptr create();
  };
}

#endif
