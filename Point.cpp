#include "Point.h"
#include <math.h>
#include <iostream>
#define BODY_WIDTH 6.0        //cm  人体的真实宽度
#define VERTICAL_ANGLE 72.0   //水平角
#define HORIZONTAL_ANGLE 72.0 //俯仰角
#define PICTURE_WIDTH 640.0   //图片水平宽度
#define PICTURE_HEIGHT 360.0  //图片垂直高度
#define CAM_K 388.41
using namespace std;
Point::Point(float x, float y, float z) : x(x), y(y), z(z)
{
}

//计算人体质心相对于摄像头的坐标(前提是质心位于图片y轴上)
//图片坐标系：右为x轴，上为y轴

Point Point::Calculate_Point2Cam(float width, float y, float Cam_pitch) ///pitch云台俯角，直接从机器读出
{
    Point Point2Cam(0.0, 0.0, 0.0);
    y = PICTURE_HEIGHT/2 - y;
   /* float tan_alpha = (width / PICTURE_WIDTH) * tan((VERTICAL_ANGLE / 2) * M_PI / 180); //alpha是图像中投影点水平角

    //11-11 TODO FIX DISTANCE
    float Distance = BODY_WIDTH / (2 * tan_alpha); //相机与人体距离(cm)*/
    float Distance=CAM_K*BODY_WIDTH*2/width;
    cout << "Distance=" << Distance << endl;
    float tan_beta = 2 * y * tan((HORIZONTAL_ANGLE / 2) * M_PI / 180) / PICTURE_WIDTH; //beta是图像中投影点与图像中心夹角
    cout << "beta=" << atan(tan_beta) * 180 / M_PI << endl;
    float theta = Cam_pitch * M_PI / 180.0 - atan(tan_beta); //x轴与相机人体连线的夹角rad
    cout << "theta=" << theta * 180 / M_PI << endl;
    Point2Cam.x = Distance * cos(theta);
    Point2Cam.y = 0.0; //理论值
    Point2Cam.z = Distance * sin(theta);
    /* float angularSize = (VERTICAL_ANGLE * width / PICTURE_WIDTH) * M_PI / 180.0; //计算水平张角(单位：弧度)

    float distanceFromCameraToPeople = BODY_WIDTH / (2 * tan(angularSize / 2)); //计算质心与相机的距离
    float beta = y * HORIZONTAL_ANGLE / PICTURE_HEIGHT;                         //y方向与坐标系中心成的角（单位：角度）
    float downAngle = Cam_pitch - beta;                                         //计算俯角（单位：角度）
    Point2Cam.x = distanceFromCameraToPeople * cos(downAngle * M_PI / 180.0);   //坐标系定义：相机正前方为x轴，右方为y轴，下方为z轴
    Point2Cam.y = 0.0;
    Point2Cam.z = distanceFromCameraToPeople * sin(downAngle * M_PI / 180.0); //坐标系定义：相机正前方为x轴，右方为y轴，下方为z轴*/
    return Point2Cam;
}

//考虑云台坐标系旋转，将相对于摄像头的坐标转化为相对于机体的坐标,经误差分析可以忽略坐标系平移仅考虑坐标系旋转
Point Point::Calculate_Point2Board(Point Point2Cam, float Cam_yaw, float Cam_pitch)
{
    //以下坐标旋转顺序不影响最终结果
    //首先云台Yaw（绕z轴转）
    float theta = atan(Point2Cam.y / Point2Cam.x) - Cam_yaw * M_PI / 180.0; //rad

    float length = sqrt(Point2Cam.x * Point2Cam.x + Point2Cam.y * Point2Cam.y);

    Point Point2Board(0, 0, 0);
    Point2Board.x = length * cos(theta);

    Point2Board.y = length * sin(theta);
    Point2Board.z = Point2Cam.z;

    //然后云台pitch（绕y轴转）
    float length2 = sqrt(Point2Board.x * Point2Board.x + Point2Board.z * Point2Board.z);
    float theta2 = atan(Point2Board.z / Point2Board.x) + Cam_pitch * M_PI / 180;
    Point2Board.x = length2 * cos(theta2);
    Point2Board.z = length2 * sin(theta2);

    return Point2Board;
}

void Point::PrintPoint(Point point)
{
    cout << "Point.x = " << point.x << "   "
         << "Point.y = " << point.y << "   "
         << "Point.z = " << point.z << endl;
}
