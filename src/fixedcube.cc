#include <fixedcube.hh>

#include <sstream>
#include <iomanip>

namespace Rubik
{
  namespace
  {
    void updateMax(int& max, boost::optional<Side::Data> data)
    {
      if(data)
      {
        max = std::max(max, *std::max_element(data->begin(), data->end()));
      }
    }

    int numDigits(int i)
    {
      int digits = 0;
      if(i)
      {
        while (i)
        {
          i /= 10;
          digits++;
        }
      }
      else
        digits = 1;
      
      return digits;
    }

    std::string row(int i, const int digits, boost::optional<Side::Data> const& data)
    {
      std::stringstream s;

      if(data)
      {
        Side::Data::const_iterator iter = data->begin()+3*i;
        s << std::setw(digits) << *iter++ << ' ';
        s << std::setw(digits) << *iter++ << ' ';
        s << std::setw(digits) << *iter++;
      }
      else
      {
        s << std::setw(digits) << '.' << ' ';
        s << std::setw(digits) << '.' << ' ';
        s << std::setw(digits) << '.';
      }
      
      return s.str();
    }
    
    void dumpInTheMiddle(std::ostream& os, const int digits, std::string const& name, boost::optional<Side::Data> const& data)
    {
      const int rowWidth = 2+3*digits;
      const std::string emptyRow(rowWidth+3, ' ');

      os << emptyRow << name << std::endl;
      for(int i=0; i<3; i++)
        os << emptyRow << row(i, digits, data) << std::endl;

      os << std::endl;
    }

    void dumpSideBySide(std::ostream& os, const int digits,
                        std::string const& nameOne, boost::optional<Side::Data> const& dataOne,
                        std::string const& nameTwo, boost::optional<Side::Data> const& dataTwo,
                        std::string const& nameThree, boost::optional<Side::Data> const& dataThree
                        )
    {
      int rowWidth = 2+3*digits;

      os << std::setw(rowWidth) << std::left << nameOne << "   "
         << std::setw(rowWidth) << std::left << nameTwo << "   "
         << std::setw(rowWidth) << std::left << nameThree << std::endl;

      for(int i=0; i<3; i++)
        os << row(i, digits, dataOne) << "   "
           << row(i, digits, dataTwo) << "   "
           << row(i, digits, dataThree) << std::endl;

      os << std::endl;
    }
    
  }
  
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

  int CubeData::largestValue() const
  {
    int max=0;
    updateMax(max, top_);
    updateMax(max, bottom_);
    updateMax(max, left_);
    updateMax(max, right_);
    updateMax(max, front_);
    updateMax(max, back_);

    return max;
  }

  FixedCube::FixedCube(CubeData const& data)
    : data_(data)
  {
  }
  
  FixedCube::Ptr FixedCube::create(CubeData const& data)
  {
    return Ptr(new FixedCube(data));
  }

  FixedCube:: Ptr FixedCube::create(CubeData const&, boost::function<ISide::Ptr(Side::Data)>)
  {
    return Ptr();
  }

  CubeData FixedCube::data()
  {
    return data_;
  }

  std::ostream& operator<<(std::ostream& os, CubeData const& data)
  {
    int digits = numDigits(data.largestValue());

    os << std::endl;
    dumpInTheMiddle(os, digits, "Top", data.top_);
    dumpSideBySide(os, digits, "Left", data.left_, "Front", data.front_, "Right", data.right_);
    dumpInTheMiddle(os, digits, "Bottom", data.bottom_);
    dumpInTheMiddle(os, digits, "Back", data.back_);

    return os;
  }
}

