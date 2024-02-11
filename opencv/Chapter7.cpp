#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//Shape detection

void getContours(Mat imgDil,Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		string objectType;
		//cout << area << endl;
		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 10);
			boundRect[i] = boundingRect(conPoly[i]);
			//cout << conPoly[i].size() << endl;
			int objCor = (int)conPoly[i].size();

			if (objCor == 3)
			{
				objectType = "Tri";
			}
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width/ (float)boundRect[i].height;
				cout << "Ration is :" << (float)boundRect[i].width << "  " << (float)boundRect[i].height << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			else if (objCor > 4)
				objectType = "Circle";

			boundRect[i] = boundingRect(conPoly[i]);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255), 1);
		}
	}
}

void main()
{

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil;

	//Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil,img);

	imshow("Image", img);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Gray", imgGray);
	//imshow("Image Canny", imgCanny);
	//imshow("Image imgDil", imgDil);

	waitKey(0); // 0 means infinity. The window won't close until we press close button

}
