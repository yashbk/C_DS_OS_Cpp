#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//Resize and crop functions

void main()
{
	string path = "Resources/lambo.png";
	Mat img = imread(path);  //Mat is matrix data types to handle all images.

	Mat imgResize, imgCrop;

	cout << img.size() << endl;

	//resize(img, imgResize, Size(1024,768));  // Resizes the image
	resize(img,imgResize,Size(),0.5,0.5);  // Resizes the image

	Rect roi(0, 0, 200, 462);  //Crop rectangle
	
	imgCrop = img(roi);

	imshow("Imagecar", img);
	imshow("Resize", imgResize);
	imshow("Recrop", imgCrop);

	waitKey(0); // 0 means infinity. The window won't close until we press close button
}

