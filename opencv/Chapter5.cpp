#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


//Warping 

void main()
{
	Mat matrix, imgKing,imgQueen, imgJ, img9;
	float w = 250, h = 350;

	string path = "Resources/cards.jpg";
	Mat img = imread(path);  //Mat is matrix data types to handle all images.

	Point2f srcKing[4] = { {529,142},{771,190},{405,395},{674,457}};
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(srcKing, dst);
	warpPerspective(img, imgKing, matrix, Point(w, h));


	Point2f srcQueen[4] = { {64,323},{339,273},{89,636},{404,573} };
	matrix = getPerspectiveTransform(srcQueen, dst);
	warpPerspective(img, imgQueen, matrix, Point(w, h));


	Point2f srcJ[4] = { {772,109},{1018,80},{840,358},{1118,328} };
	matrix = getPerspectiveTransform(srcJ, dst);
	warpPerspective(img, imgJ, matrix, Point(w, h));

	Point2f src9[4] = { {737,383},{1024,434},{642,709},{971,784} };
	matrix = getPerspectiveTransform(src9, dst);
	warpPerspective(img, img9, matrix, Point(w, h));

	for (int i = 0; i < 4; i++)
	{
		circle(img, srcKing[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("ImageKing", imgKing);
	imshow("ImageQueen", imgQueen);
	imshow("ImageJ", imgJ);
	imshow("Image9", img9);
	waitKey(0); // 0 means infinity. The window won't close until we press close button
}
