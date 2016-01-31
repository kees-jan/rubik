#include <gtest/gtest.h>

#include <fixedcube.hh>
#include <side.hh>


using namespace Rubik;

class FixedCubeTests;

class SideFactory
{
private:
  int numberOfCalls_;
  
public:
  SideFactory()
    : numberOfCalls_(0)
  {}

  ~SideFactory()
  {
    if(numberOfCalls())
      EXPECT_EQ(6, numberOfCalls());
  }
  
  ISide::Ptr operator()(Side::Data const&, Orientation const&)
  {
    numberOfCalls_++;
    return ISide::Ptr();
  }

  int numberOfCalls()
  {
    return numberOfCalls_;
  }
};

class FixedCubeTests : public testing::Test
{
private:
  static int n;

public:
  CubeData data;
  
public:
  FixedCubeTests()
    : data(top(generateSideData()).
           left(generateSideData()).
           front(generateSideData()).
           right(generateSideData()).
           bottom(generateSideData()).
           back(generateSideData()))
  {
  }

  ~FixedCubeTests()
  {
    // Keep square values relatively small
    n=0;
  }
  
  int generateInteger()
  {
    return n++;
  }
  
  Side::Data generateSideData()
  {
    Side::Data result;
    for(unsigned int i=0; i<result.size(); i++)
      result[i] = generateInteger();

    return result;
  }
};

int FixedCubeTests::n = 0;

TEST_F(FixedCubeTests, Initialize)
{
  FixedCube::Ptr cube = FixedCube::create(data);

  EXPECT_EQ(data, cube->data());
}

TEST_F(FixedCubeTests, InitializeWithFactory)
{
  FixedCube::Ptr cube = FixedCube::create(data, Side::create);

  EXPECT_EQ(data, cube->data());
}

TEST_F(FixedCubeTests, InitializeWithMockFactory)
{
  SideFactory sideFactory;
  FixedCube::Ptr cube = FixedCube::create(data, SideFactory());

  EXPECT_EQ(data, cube->data());
}
