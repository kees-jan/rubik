#include <gtest/gtest.h>

#include <fixedcube.hh>
#include <side.hh>


using namespace Rubik;

class FixedCubeTests : public testing::Test
{
private:
  static int n;
  
public:
  int generateInteger()
  {
    return n++;
  }
  
  Side::Data generateSideData()
  {
    Side::Data result;
    for(unsigned int i=0; i<result.size(); i++)
      result[i] = generateInteger();
    n+=9;

    return result;
  }
};

int FixedCubeTests::n = 0;

TEST_F(FixedCubeTests, Initialize)
{
  CubeData data =
    top(generateSideData()).
    left(generateSideData()).
    front(generateSideData()).
    right(generateSideData()).
    bottom(generateSideData()).
    back(generateSideData());
  
  FixedCube::Ptr cube = FixedCube::create(data);

  // EXPECT_EQ(data, cube->data());
}
