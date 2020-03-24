# OpenCV3 编程入门
## 第二章，官网实例<暂略>


# 第四章 OpenCV的数据结构和基本绘图
    1.Mat
    OpenCV函数中输出图像的内存分配是自动完成的（如果不特别指定的话）
    使用OpenCV的C++接口时不需要考虑内存释放的问题，（1.0的CV结构C接口使用IplImage）
    赋值运算符和拷贝构造函数（构造函数）只复制信息头
        Mat A,C;
        A=imread("1.jpg,CV_LOAD_IMAGE_COLOR);
        Mat (B)A; // 拷贝构造函数
        C=A;  // 赋值运算
    使用函数clone或copyTo()复制图像的矩阵
        Mat F=A.clone();
        Mat G;
        A.coptTo(G);
# 第五章- core
    1.傅里叶变换
    2.ROI
    
