#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/calib3d.hpp>
#include <opencv2/opencv.hpp>
#include <QImage>

using namespace cv;
using namespace std;

class AIV
{
public:
    AIV();
    void static test();
    Mat static _bin(Mat src, int upper = 127, int lower = 127, int forecolor = 255, int backcolor = 0);
    Mat static _binadapt(Mat img);
    Mat static _add(Mat src1, Mat src2);
    Mat static _addWeighted(Mat src1, double w1, Mat src2, double w2, double gamma = 0);
    Mat static _erode(Mat img, Mat kernel, int iterations = 1, Point anchor = Point(-1, -1));
    Mat static _dilate(Mat img, Mat kernel, int iterations = 1, Point anchor = Point(-1, -1));
    Mat static QImage2cvMat(QImage& image, bool clone, bool rb_swap);
    QImage static cvMat2QImage(const cv::Mat& mat, bool clone, bool rb_swap);
    Mat static _sub(Mat src1, Mat src2);
    Mat static _mul(Mat src1, Mat src2);
    Mat static _div(Mat src1, Mat src2);
    Mat static _absdiff(Mat src1, Mat src2);
    Mat static _and(Mat src1, Mat src2);
    Mat static _or(Mat src1, Mat src2);
    Mat static _not(Mat src1);
    Mat static _xor(Mat src1, Mat src2);
    vector<KeyPoint> static _BlobDetector(Mat image, SimpleBlobDetector::Params params);
    vector<Vec4i> static _LineDector(Mat Image, double rho, double theta, int threshold, double minLineLength = 0, double maxLineGap = 0);
    Mat static convertTo3Channels(const Mat& binImg);
    Mat static gray2disColor(const Mat& scaledGray);
    double static distanceBtwPoints(double Ax, double Ay, double Bx, double By);
    double static contourArea(vector<Point> contour);

};

