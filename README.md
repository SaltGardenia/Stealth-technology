# 语言：C++

# 库：OpenCV

# 环境配置：

1、对opencv_3.4.2_Qt.rar进行解压，复制x86/bin里所有.dll文件，粘贴到c/windows.syswow64中。

2、在QT Creator中创建Non-QT Project Plain C++ Application类型项目。

3、并在Stealth-technology.pro文件中添加OpenCV库相关文件路径。(视实际路径而定)
```
INCLUDEPATH += E:\OpenCV\opencv_3.4.2_Qt\include
LIBS += E:\OpenCV\opencv_3.4.2_Qt\x86\bin\libopencv_*.dll
```
并在main.cpp文件中包括头文件。
```
#include <opencv2/opencv.hpp>
using namespace cv;
```

4、拍摄一张背景图片放置于该项目根目录下，并在
```
Mat first = imread("D:/Project/Stealth-technology/");
```
处更改对应路径。(视实际路径而定，防止转义字符冲突，将"`\`"改为"`/`")

5、参考hsv色彩空间调整具体参数
![[Pasted image 20250506170147.png]]
```
inRange(hsv, Scalar(102, 43, 180), Scalar(124, 255, 255), mask);
```
第二参数位分别填入hsv的最小值，第三参数为分别填入hsv的最大值。

6、确保电脑默认摄像头可调用，不与其他应用程序访问权限冲突，运行程序即可在对应颜色区域显示背景图片所对应的区域，实现隐身。
