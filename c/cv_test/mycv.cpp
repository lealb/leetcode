#include <iostream>
#include "opencv.hpp"
using namespace cv;

int main(int argc, char const *argv[])
{
    Mat image;
    image = imread("tt.jpg", 1);
    imshow("srcImage", image);
    waitKey(0);

    return 0;
}                                                                                                                                                                          
