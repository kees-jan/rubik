#ifndef FIXEDCUBE_HH
#define FIXEDCUBE_HH

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

#include <side.hh>

namespace Rubik
{
  class CubeData
  {
  private:
    boost::optional<Side::Data> top_;
    boost::optional<Side::Data> bottom_;
    boost::optional<Side::Data> left_;
    boost::optional<Side::Data> right_;
    boost::optional<Side::Data> front_;
    boost::optional<Side::Data> back_;

  public:
    CubeData& top(Side::Data const& data);
    CubeData& bottom(Side::Data const& data);
    CubeData& left(Side::Data const& data);
    CubeData& right(Side::Data const& data);
    CubeData& front(Side::Data const& data);
    CubeData& back(Side::Data const& data);

    Side::Data top() const;
    Side::Data bottom() const;
    Side::Data left() const;
    Side::Data right() const;
    Side::Data front() const;
    Side::Data back() const;

    bool operator==(CubeData const& other) const;

    int largestValue() const;

    friend std::ostream& operator<<(std::ostream& os, CubeData const& data);
  };

  CubeData top(Side::Data const& data);
  CubeData bottom(Side::Data const& data);
  CubeData left(Side::Data const& data);
  CubeData right(Side::Data const& data);
  CubeData front(Side::Data const& data);
  CubeData back(Side::Data const& data);

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
    typedef boost::function<ISide::Ptr(Side::Data const&, Orientation const&)> SideFactory;
  private:
    CubeData data_;
    
  private:
    FixedCube(CubeData const& data, SideFactory const& sideFactory);
    
  public:
    static Ptr create(CubeData const& data);
    static Ptr create(CubeData const& data, SideFactory const& sideFactory);

    CubeData data();
  };

  std::ostream& operator<<(std::ostream& os, CubeData const& data);
}

#endif
