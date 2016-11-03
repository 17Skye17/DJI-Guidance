#include <iostream>
#include <vector>
#include <math.h>
#include "Point.h"
using namespace std;

int main()
{
  float width = 100.0;
  float y = 60.0;
  float pitch = 20.0;
  Point point(width, y);
  vector<float> Point2Cam = point.Calculate_Point2Cam(width, y, pitch);
  vector<float> Point2Board = point.Calculate_Point2Board(Point2Cam);
  point.PrintPoint(Point2Cam);
  point.PrintPoint(Point2Board);

  return 0;
}
