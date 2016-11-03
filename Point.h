#pragma once
#include <vector>
class Point
{
  public:
    Point(float, float);
    std::vector<float> Calculate_Point2Cam(float, float, float);
    std::vector<float> Calculate_Point2Board(std::vector<float>); //TODO
    void PrintPoint(std::vector<float>);
 private:
    float width; //人体的宽度
    float y;     //人体质心在图像上的位置（已yaw到y轴）*/
};