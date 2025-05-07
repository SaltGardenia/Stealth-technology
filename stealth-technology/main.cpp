#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat first = imread("./Stealth-technology/");
    Mat frame;
    VideoCapture capture(0);
    while(capture.read(frame)) {
        //转换hsv格式
        Mat hsv;
        cvtColor(frame, hsv, COLOR_BGR2HSV);
        //识别蓝色区域
        Mat mask;
        inRange(hsv, Scalar(102, 43, 180), Scalar(124, 255, 255), mask);
        //取反
        Mat umask;
        bitwise_not(mask, umask);
        //处理原背景图片
        Mat bkMask;
        bitwise_and(first, first, bkMask, mask);
        //处理视频图片
        Mat bkUMask;
        bitwise_and(frame, frame, bkUMask, umask);
        //合并
        Mat final;
        add(bkMask, bkUMask, final);
        imshow("video", final);
        waitKey(30);
    }
    waitKey(0);
    return 0;
}
