#include <gtest/gtest.h>

#include <fixedcube.hh>
#include <side.hh>


using namespace Rubik;

class FixedCubeTests;

class SideFactory
{
public:
  ISide::Ptr operator()(Side::Data const&)
  {
    return ISide::Ptr();
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
  FixedCube::Ptr cube = FixedCube::create(data, SideFactory());

  // EXPECT_EQ(data, cube->data());
}
