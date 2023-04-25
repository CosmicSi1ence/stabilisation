#include "stab.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "filter2d.h"
#include "filter_box.h"
#include "class_img.h"
#include <windows.h>
#include "err.h"

#include <time.h>
#include <iostream>

using namespace cv;

//static double ax, bx, delta_x, ay, by, delta_y;

Mat stab(Mat &img1, Mat &img1_f, Mat &img2, int delta) {

	uint8_t k_filter = 11;
	Mat img2_f;						//	Создание объектa под фильтрацию
	img2.copyTo(img2_f);			//	Копирование

	clock_t tStart = clock();
	boxFilter(img2, img2_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);	//	img2 filtering
	//printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	Mat roi1(img2_f, Rect(delta, 0, img1.cols - 2 * delta, img1.rows - 2 * delta));
	Mat roi2(img2_f, Rect(0, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));
	Mat roi3(img2_f, Rect(delta, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));
	Mat roi4(img2_f, Rect(2 * delta, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));
	Mat roi5(img2_f, Rect(delta, 2 * delta, img1.cols - 2 * delta, img1.rows - 2 * delta));

	namedWindow("t", WINDOW_AUTOSIZE);
	imshow("t", roi5);

	double e1 = err(img1_f, roi1);
	double e2 = err(img1_f, roi2);
	double e3 = err(img1_f, roi3);
	double e4 = err(img1_f, roi4);
	double e5 = err(img1_f, roi5);
	
	double ax = (e2 - e4) / (2 * delta);
	double bx = (1.0 / delta) * (1.0 / delta) * ((e2 - e3 + (e4 - e2))/ 2);
	double delta_x = - (bx / (2 * ax));

	double ay = (e1 - e5) / (2 * delta);
	double by = (1.0 / delta) * (1.0 / delta) * ((e1 - e3 + (e5 - e1)) / 2);
	double delta_y = -(by / (2 * ay));
	
	Mat img_out(img2, Rect(delta_x, delta_y, img2.cols - 2 * delta, img2.rows - 2 * delta));
	Mat img_f(img2_f, Rect(delta_x, delta_y, img2.cols - 2 * delta, img2.rows - 2 * delta));

	img_f.copyTo(img1_f);
	
	return img_out;
}