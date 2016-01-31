#include <gtest/gtest.h>

#include <boost/assign.hpp>

#include <fixedcube.hh>
#include <side.hh>

using namespace Rubik;

class FixedCubeTests;

namespace
{
  typedef std::pair<Orientation, Side::Data> ExpectedInvocation;
  typedef std::set<ExpectedInvocation> ExpectedInvocations;

  ExpectedInvocations expectedInvocationsFromCubeData(CubeData const& cubeData)
  {
    return boost::assign::list_of
      (make_pair(Orientation(), cubeData.top()));
  }
}

class SideFactory
{
private:
  
private:
  ExpectedInvocations expectedInvocations;
  size_t originalInvocationCount;
  
public:
  SideFactory(CubeData const& cubeData)
    : expectedInvocations(expectedInvocationsFromCubeData(cubeData)), originalInvocationCount(expectedInvocations.size())
  {}

  ~SideFactory()
  {
    if(originalInvocationCount != expectedInvocations.size())
      EXPECT_TRUE(expectedInvocations.empty());
  }
  
  ISide::Ptr operator()(Side::Data const& data, Orientation const& orientation)
  {
    ExpectedInvocation invocation(orientation, data);
    EXPECT_TRUE(expectedInvocations.count(invocation));
    // expectedInvocations.erase(invocation);
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
  FixedCube::Ptr cube = FixedCube::create(data, Side::create);

  EXPECT_EQ(data, cube->data());
}

TEST_F(FixedCubeTests, InitializeWithMockFactory)
{
  SideFactory sideFactory(data);
  FixedCube::Ptr cube = FixedCube::create(data, sideFactory);

  EXPECT_EQ(data, cube->data());
}
