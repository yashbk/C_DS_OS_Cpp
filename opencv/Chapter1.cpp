#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#define WEBCAM
#define CAMERA 0

using namespace std;
using namespace cv;

//Importing images
#ifdef IMAGE
void main()
{
	string path = "Resources/lambo.png";
	Mat img = imread(path);  //Mat is matrix data types to handle all images.
	imshow("Imagecar", img);
	waitKey(0); // 0 means infinity. The window won't close until we press close button
}
#elif defined(VIDEO)

//Importing Videos

void main()
{

	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;

	while (1) {
		cap.read(img);
		imshow("Image", img);
		waitKey(20); // 0 means infinity. The window won't close until we press close button
	}
}

#elif defined(WEBCAM)

void main()
{
	VideoCapture cap(CAMERA); //If you have one camera then use 0 otherwise 1. 0 for primary camera 1 for other one
	Mat img;

	while (1) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1); // 0 means infinity. The window won't close until we press close button
	}
}
#endif