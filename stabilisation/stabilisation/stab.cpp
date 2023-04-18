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

Mat stab(Mat img1, Mat img2, int delta) {
	uint32_t e1, e2, e3, e4, e5;

	Fil filter = box(10);		//	Задание фильтра
	Mat img1_f, img2_f;			//	Создание объектов под фильтрацию
	img1.copyTo(img1_f);		//	Копирование
	img2.copyTo(img2_f);		//	Копирование

	//clock_t tStart = clock();
	filter2d(img1_f, filter);	//	Фильтрация
	//printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	filter2d(img2_f, filter);	//	Фильтрация

	//Mat kernel = Mat::ones(10, 10, CV_64F);
	//kernel = kernel / 100;
	//clock_t tStart = clock();
	//filter2D(img1, img1_f, -1, kernel, Point(-1, -1));
	//printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	//filter2D(img2, img2_f, -1, kernel, Point(-1, -1));

	Img im1_f;
	im1_f = img1_f;

	Mat roi1(img2_f, Rect(delta, 0, img1.cols - 2 * delta, img1.rows - 2 * delta));				//	????направление cols rows????
	Mat roi2(img2_f, Rect(0, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));				//	????направление cols rows????
	Mat roi3(img2_f, Rect(delta, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));			//	????направление cols rows????
	Mat roi4(img2_f, Rect(2 * delta, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));		//	????направление cols rows????
	Mat roi5(img2_f, Rect(delta, 2 * delta, img1.cols - 2 * delta, img1.rows - 2 * delta));		//	????направление cols rows????
	Img im2_f;
	
	im2_f = roi1;
	e1 = err(im1_f, im2_f);
	im2_f = roi2;
	e2 = err(im1_f, im2_f);
	im2_f = roi3;
	e3 = err(im1_f, im2_f);
	im2_f = roi4;
	e4 = err(im1_f, im2_f);
	im2_f = roi5;
	e5 = err(im1_f, im2_f);
	
	double ax = (e2 - e4) / (2 * delta);
	double bx = pow(1 / delta, 2) * (e2 - e3 + (e4 - e2) / 2);
	double delta_x = - (bx / (2 * ax));

	double ay = (e1 - e5) / (2 * delta);
	double by = pow(1 / delta, 2) * (e1 - e3 + (e5 - e1) / 2);
	double delta_y = -(by / (2 * ay));
	
	Mat img_out(img2, Rect(delta_x, delta_y, img2.cols - 2 * delta, img2.rows - 2 * delta));
	
	return img_out;
}