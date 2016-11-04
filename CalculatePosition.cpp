#include <iostream>
#include <vector>
#include <math.h>
#include "Point.h"

#include <LinuxSerialDevice.h>
#include <LinuxThread.h>
#include <LinuxSetup.h>
#include <LinuxCleanup.h>
#include <ReadUserConfig.h>

#include <LinuxWaypoint.h>
#include <LinuxCamera.h>

#include <LinuxCamera.h>
#include <DJI_Camera.h>
#include <DJI_API.h>
#include <DJI_Type.h>
using namespace std;
using namespace DJI;
using namespace DJI::onboardSDK;
int main()
{
  float width = 100.0;    //人体在图像中的宽度(px)
  float y = 60.0;         //人体质心在图像中的y坐标(px)
  float Cam_yaw = 30.0;   //云台绕z轴旋转的角度 （degree)
  float Cam_pitch = 30.0; //云台绕y轴旋转的角度 (degree)
  /* LinuxSerialDevice* serialDevice = new LinuxSerialDevice(UserConfig::deviceName, UserConfig::baudRate);
  CoreAPI* api = new CoreAPI(serialDevice);

  Camera* camera = new Camera(api);
  //get Gimbal current rotation
  RotationAngle rotation = getGimbalAngle(camera,20);*/
  Point point(0.0, 0.0, 0.0);
  Point point2Cam = point.Calculate_Point2Cam(width, y, Cam_pitch);
  Point point2Board = point.Calculate_Point2Board(point2Cam, Cam_yaw, Cam_pitch);
  point2Cam.PrintPoint(point2Cam);
  point2Board.PrintPoint(point2Board);

  return 0;
}
