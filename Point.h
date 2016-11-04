
#pragma once
#include <vector>
class Point
{
public:
  Point(float, float, float);
  Point Calculate_Point2Cam(float, float, float);
  Point Calculate_Point2Board(Point, float, float);
  void PrintPoint(Point);
  float x;
  float y;
  float z;
};