#ifndef SIDE_HH
#define SIDE_HH

#include <array>
#include <boost/shared_ptr.hpp>
#include <boost/optional.hpp>

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

    std::array<int, 9> transformation(int top) const;
    bool operator==(Orientation const& other) const;
    bool operator<(Orientation const& other) const;

    friend std::ostream& operator<<(std::ostream& os, Rubik::Orientation const & o);

  private:
    std::array<boost::optional<int>, 4> toArray() const;
  };

  Orientation top(int t);
  Orientation bottom(int b);
  Orientation left(int l);
  Orientation right(int r);

  /**
   * Represents one side of a cube.
   *
   * This is an abstract class representing one side of a
   * cube. Concrete implementations should inherit from it.
   */
  class ISide
  {
  public:
    typedef boost::shared_ptr<ISide> Ptr;
  };
  
  /**
   * Represents one side of a cube.
   *
   * Since a side of a cube has no natural orientation (top, bottom,
   * left and right pretty soon become meaningless), a side is orented
   * relative to the color of the center square of their adjacent
   * sides.
   */
  class Side : public ISide
  {
  public:
    typedef boost::shared_ptr<Side> Ptr;
    typedef std::array<int,9> Data;
    typedef std::array<int,3> Row;

  private:
    Data data_;
    Orientation orientation_;
    
  public:
    static Ptr create(Data const& data, Orientation const& orientation);
    Side(Data const& data, Orientation const& orientation);

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

    /**
     * Retrieve the top row, from different perspectives.
     *
     * Similar to the data(int) function, this returns the top row,
     * adjacent to the center square color specified.
     */
    Row topRow(int top);
  };

  std::ostream& operator<<(std::ostream& os, Side::Data const& data);
  std::ostream& operator<<(std::ostream& os, Orientation const & o);
}

namespace boost
{
  using Rubik::operator<<;
  
  template<typename T>
  std::ostream& operator<<(std::ostream& os, optional<T> const& v)
  {
    if(v)
      os << *v;
    else
      os << '-';
  
    return os;
  }
}

#endif
