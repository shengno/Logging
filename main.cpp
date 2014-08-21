#include <iostream>

#include <fstream>

#include "opencv2/opencv.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello OpenCV!\n";

    std::fstream File("E:/test.txt", std::ios_base::out);

    cv::Mat Image(2,2, CV_8UC1, cv::Scalar(10));

    File << Image;

    File.close();

    return 0;
}

