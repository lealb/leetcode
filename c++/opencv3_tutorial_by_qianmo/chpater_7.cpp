#include <iostream>
#include <opencv.hpp>
using namespace std;
using namespace cv;

void testCanny(string img)
{

    Mat srcImg = imread(img);
    imshow("srcImg", srcImg);

    Mat dstImg, edge, grayImg;
    //1. 创建同类型大小的矩阵
    dstImg.create(srcImg.size(), srcImg.type());
    //2. 灰度化处理
    cvtColor(srcImg, grayImg, COLOR_BGR2GRAY);
    //3.使用kernel3*3 降噪
    blur(grayImg, edge, Size(3, 3));
    //4. 执行Canny算子
    Canny(edge, edge, 3, 9, 3);
    // 5.灰度图
    imshow("grayImg", edge);
    dstImg = Scalar::all(0);
    // 6.恢复彩色图
    srcImg.copyTo(dstImg, edge);
    imshow("dstImage", dstImg);
    waitKey(0);
}
int main()
{
    string img = "file/img/tt.jpg";
    testCanny(img);
    return 0;
}