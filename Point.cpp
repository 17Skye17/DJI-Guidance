#include "Point.h"
#include <math.h>
#include <iostream>
#define BODY_WIDTH 40.0       //cm  人体宽度
#define FOCUS 15.0            //mm  摄像头焦距
#define VERTICAL_ANGLE 72.0   //水平角
#define HORIZONTAL_ANGLE 72.0 //俯仰角
#define PICTURE_WIDTH 640.0   //图片水平宽度
#define PICTURE_HEIGHT 320.0  //图片垂直高度
using namespace std;
Point::Point(float width, float y) : width(width), y(y)
{
}

//计算人体质心相对于摄像头的坐标(前提是质心位于图片y轴上)
vector<float> Point::Calculate_Point2Cam(float width, float y, float pitch) ///pitch云台俯角，直接从机器读出
{
    vector<float> Point2Cam(2, 0.0);
    float angularSize = (VERTICAL_ANGLE * width / PICTURE_WIDTH) * M_PI / 180.0; //计算水平张角(单位：弧度)

    float distanceFromCameraToPeople = BODY_WIDTH / (2 * tan(angularSize / 2));   //计算质心与相机的距离
    float beta = y * HORIZONTAL_ANGLE / PICTURE_HEIGHT;                           //y方向与坐标系中心成的角（单位：角度）
    float downAngle = pitch - beta;                                               //计算俯角（单位：角度）
    float AbsoluteX = distanceFromCameraToPeople * cos(downAngle * M_PI / 180.0); //坐标系定义：相机正前方为x轴，左方为y轴
    Point2Cam[0] = AbsoluteX;                                                     //focus物体到y轴上，默认AbsoluteY = 0.0 cm
    return Point2Cam;
}

//将相对于摄像头的坐标转化为相对于机体的坐标
vector<float> Point::Calculate_Point2Board(vector<float> Point2Cam)
{
    //TODO
    vector<float> Point2Board = Point2Cam;
    return Point2Board;
}

void Point::PrintPoint(vector<float> Point)
{
    std::cout << "Point.x = " << Point[0] << "   "
              << "Point.y= " << Point[1] << std::endl;
}
