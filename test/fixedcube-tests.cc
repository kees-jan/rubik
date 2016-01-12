#include <gtest/gtest.h>

#include <fixedcube.hh>
#include <side.hh>


using namespace Rubik;

class FixedCubeTests : public testing::Test
{
private:
  static int n;
  
public:
  Side::Data generateSideData()
  {
    Side::Data result;
    for(int i=0; i<9; i++)
      result[i] = n+i;
    n+=9;

    return result;
  }
};

int FixedCubeTests::n = 0;

TEST_F(FixedCubeTests, Initialize)
{
  CubeData data;
  FixedCube::Ptr cube = FixedCube::create(data);
}
