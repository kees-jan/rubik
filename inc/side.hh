#ifndef SIDE_HH
#define SIDE_HH

#include <array>
#include <boost/shared_ptr.hpp>
#include <boost/optional.hpp>

namespace Rubik
{
  class Orientation;
}

std::ostream& operator<<(std::ostream& os, Rubik::Orientation const & o);

namespace Rubik
{
  class Orientation
  {
  private:
    boost::optional<int> top_;
    boost::optional<int> bottom_;
    boost::optional<int> left_;
    boost::optional<int> right_;
    
  public:
    Orientation& top(int t);
    Orientation& bottom(int b);
    Orientation& left(int l);
    Orientation& right(int r);

    int top() const;
    int bottom() const;
    int left() const;
    int right() const;

    friend std::ostream& ::operator<<(std::ostream& os, Rubik::Orientation const & o);
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

    /**
     * Retrieve side data from different perspectives.
     *
     * Side is oriented relative to the center squares of its
     * neighbouring sides. This function allows you to "rotate the
     * cube" by specifying what is the color of the center square of
     * the top neighbouring side. This function will then return the
     * colors of the squares properly adjusted for this new
     * orientation.
     */
    Data data(int top);
  };
}

std::ostream& operator<<(std::ostream& os, Rubik::Side::Data const& data);

template<typename T>
std::ostream& operator<<(std::ostream& os, boost::optional<T> const& v)
{
  if(v)
    os << *v;
  else
    os << '-';
  
  return os;
}


#endif
