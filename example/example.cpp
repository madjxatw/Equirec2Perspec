#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "equirec2perspec.h"

#include "common.h"

int main()
{
  std::string inputImagePath = std::string(DATADIR) + "test1.jpg";
  cv::Mat inputImage = cv::imread(inputImagePath);

  const int height = 720;
  const int width = 1080;
  float theta = 0.0f;
  float phi = 0.0f;
  float FOV = 90.0f;

  Equirec2Perspec equiParser;
  cv::Mat outputImage;

  int keycode = -1;
  bool flag = true;

  do {
    switch(keycode) {
      case 83:  // left arrow
        if ((theta += 90) == 360) {
          theta = 0.0f;
        }
        flag = true;
        break;
      case 81: // right arrow
        if ((theta -= 90) < 0) {
          theta += 360.0f;
        }
        flag = true;
        break;
      default:
        break;
    }
    if (flag) {
      equiParser.convert(inputImage, outputImage, FOV, theta, phi, height, width);
      cv::imshow("image", outputImage);
    }
    flag = false;
  } while ((keycode = cv::waitKey(0)) != 27); // Esc to quit


  cv::destroyAllWindows();
  return 0;
}
