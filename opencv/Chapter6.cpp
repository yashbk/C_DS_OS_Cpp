#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


//Color detection

void main()
{
	int hmin = 0, smin = 110, vmin = 153;
	int hmax = 19, smax = 240, vmax = 255;

	string path = "Resources/lambo.png";
	Mat img = imread(path);
	Mat imgHSV, imgmask;

	cvtColor(img, imgHSV, COLOR_BGR2HSV);  //For color detection we should convert image to HSV i.e. Hue saturation value
	
	namedWindow("Trackbars", (640, 200));

	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmax, 255);
	createTrackbar("Val Max", "Trackbars", &vmin, 255);

	while (1) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, imgmask);

		imshow("Image", img);
		imshow("ImageHSV", imgHSV);
		imshow("ImageMask", imgmask);
		waitKey(1); // 0 means infinity. The window won't close until we press close button
	}
}
