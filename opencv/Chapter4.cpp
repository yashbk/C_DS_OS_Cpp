#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//Draw shapes and text functions

void main()
{
	// Create blank image              B    G     R
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	
	//Create circle
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);

	//Rectangle
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);

	//Line
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);  //Scalar is to give the color

	//Adding text
	putText(img, "Yashas", Point(190, 262), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 69, 255), 2);

	imshow("Image", img);

	waitKey(0); // 0 means infinity. The window won't close until we press close button
}

