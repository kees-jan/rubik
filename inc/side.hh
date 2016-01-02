#ifndef SIDE_HH
#define SIDE_HH

#include <array>
#include <boost/shared_ptr.hpp>
#include <boost/optional.hpp>

namespace Rubik
{
  class Orientation
  {
  public:
    boost::optional<int> top_;
    boost::optional<int> bottom_;
    boost::optional<int> left_;
    boost::optional<int> right_;
    
  public:
    Orientation& top(int t);
    Orientation& bottom(int b);
    Orientation& left(int l);
    Orientation& right(int r);
  };

  Orientation top(int t);
  Orientation bottom(int b);
  Orientation left(int l);
  Orientation right(int r);
  
  /**
   * Represents one side of a cube.
   *
   * Since a side of a cube has no natural orientation (top, bottom,
   * left and right pretty soon become meaningless), a side is orented
   * relative to the color of the center square of their adjacent
   * sides.
   */
  class Side
  {
  public:
    typedef boost::shared_ptr<Side> Ptr;
    typedef std::array<int,9> Data;

  private:
    Data data_;
    
  public:
    static Ptr create(Data const& data, Orientation const& orientation);
    Side(Data const& data);

    Data data();
    Data data(int top);
  };
}

#endif
