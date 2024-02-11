#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//Basic functions

void main()
{
	string path = "Resources/lambo.png";
	Mat img = imread(path);  //Mat is matrix data types to handle all images.
	Mat imgGray, imgBlur, imgCanny,imgDia,imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7, 7), 3, 0); //Adding blur
	Canny(imgBlur, imgCanny, 25, 75); //Edge detection algorithm

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDia, kernel); //Increase thickness of edge lines
	erode(imgDia, imgErode, kernel); // Decrease thickness of edge lines

	imshow("Imagecar", img);
	imshow("ImageGray", imgGray);
	imshow("ImageBlur", imgBlur);
	imshow("ImageCanny", imgCanny);
	imshow("ImageDia", imgDia);
	imshow("ImageErode", imgErode);
	waitKey(0); // 0 means infinity. The window won't close until we press close button
}

