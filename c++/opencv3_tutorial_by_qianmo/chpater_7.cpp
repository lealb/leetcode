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

void testSobel(string img)
{
    Mat srcImg = imread(img);
    imshow("srcImg", srcImg);

    Mat gradX, gradY;
    Mat absGradX, absGradY, dstImg;
    // x
    Sobel(srcImg, gradX, CV_16S, 1, 0, 3, 1, 1);
    convertScaleAbs(gradX, absGradX);
    imshow("absGradX", absGradX);
    //Y
    Sobel(srcImg, gradY, CV_16S, 0, 1, 3, 1, 1);
    convertScaleAbs(gradY, absGradY);
    imshow("absGradY", absGradY);
    // merge x and y
    addWeighted(absGradX, 0.5, absGradY, 0.5, 0, dstImg);
    imshow("dstImg", dstImg);
    waitKey(0);
}

void testLaplacian(string img)
{
    Mat srcImg = imread(img);
    imshow("srcImg", srcImg);

    Mat dstImg, grayImg, absDstImg;
    // 高斯滤波消除噪声
    GaussianBlur(srcImg, srcImg, Size(3, 3), 0, 0);
    //灰度图
    cvtColor(srcImg, grayImg, COLOR_BGR2GRAY);
    // Laplacian
    Laplacian(grayImg, dstImg, CV_16S, 3, 1, 0);
    // 计算绝对值
    convertScaleAbs(dstImg, absDstImg);
    imshow("absDstImg", absDstImg);
    waitKey(0);
}

void testScarr(string img)
{
    Mat srcImg = imread(img);
    imshow("srcImg", srcImg);

    Mat gradX, gradY;
    Mat absGradX, absGradY, dstImg;
    // x
    Scharr(srcImg, gradX, CV_16S, 1, 0, 1, 0, 1);
    convertScaleAbs(gradX, absGradX);
    imshow("absGradX", absGradX);
    //Y
    Scharr(srcImg, gradY, CV_16S, 0, 1, 1, 0, 1);
    convertScaleAbs(gradY, absGradY);
    imshow("absGradY", absGradY);
    // merge x and y
    addWeighted(absGradX, 0.5, absGradY, 0.5, 0, dstImg);
    imshow("dstImg", dstImg);
    waitKey(0);
}
int main()
{
    string img = "file/img/tt.jpg";
    // testCanny(img);
    // testSobel(img);
    // testLaplacian(img);
    testScarr(img);
    return 0;
}