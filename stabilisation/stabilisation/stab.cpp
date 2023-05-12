#include "stab.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <windows.h>
#include "err.h"

#include <time.h>
#include <iostream>

using namespace cv;

//static double ax, bx, delta_x, ay, by, delta_y;

Mat stab(Mat& img1, Mat& img1_f, Mat& img2, uint16_t delta, uint8_t k_filter) {

	Mat img2_f;						//	Создание объектa под фильтрацию
	img2.copyTo(img2_f);			//	Копирование

	//clock_t tStart = clock();
	boxFilter(img2, img2_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);	//	img2 filtering
	//img2_f = img2;
	//printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	Mat roi1_(img2_f, Rect(delta, 0, img1_f.cols, img1_f.rows));
	Mat roi2_(img2_f, Rect(0, delta, img1_f.cols, img1_f.rows));
	Mat roi3_(img2_f, Rect(delta, delta, img1_f.cols, img1_f.rows));
	Mat roi4_(img2_f, Rect(2 * delta, delta, img1_f.cols, img1_f.rows));
	Mat roi5_(img2_f, Rect(delta, 2 * delta, img1_f.cols, img1_f.rows));

	Mat roi1, roi2, roi3, roi4, roi5;
	roi1_.copyTo(roi1);
	roi2_.copyTo(roi2);
	roi3_.copyTo(roi3);
	roi4_.copyTo(roi4);
	roi5_.copyTo(roi5);

	double e1 = err(img1_f, roi1);
	double e2 = err(img1_f, roi2);
	double e3 = err(img1_f, roi3);
	double e4 = err(img1_f, roi4);
	double e5 = err(img1_f, roi5);

	double bx = (e2 - e4) / (2 * delta);
	double ax = (e2 - 2 * e3 + e4) / 2 / delta / delta;
	double delta_x = -(bx / (2 * ax));

	double by = (e1 - e5) / (2 * delta);
	double ay = (e1 - 2 * e3 + e5) / 2 / delta / delta;
	double delta_y = -(by / (2 * ay));

	printf("\tdx:%.1f\tdy:%.1f\n", delta_x, delta_y);
	uint16_t rect_start_x, rect_start_y;

	if(delta_x >= (-delta) && delta_x <= delta) {
		rect_start_x = delta + delta_x;
	}
	if (delta_x < (-delta)){
		rect_start_x = 0;
	}
	if (delta_x > delta) {
		rect_start_x = 2 * delta;
	}

	if (delta_y >= (-delta) && delta_y <= delta) {
		rect_start_y = delta + delta_y;
	}
	if (delta_y < (-delta)) {
		rect_start_y = 0;
	}
	if (delta_y > delta) {
		rect_start_y = 2 * delta;
	}

	Rect shift = Rect(rect_start_x, rect_start_y, img1_f.cols, img1_f.rows);

	Mat img_out(img2, shift);
	Mat img_f(img2_f, shift);

	img_f.copyTo(img1_f);

	return img_out;
}