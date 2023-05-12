#include "stab2.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <windows.h>
#include "err.h"

#include <time.h>
#include <iostream>

using namespace cv;

//static double ax, bx, delta_x, ay, by, delta_y;

Mat stab2(Mat& img1, Mat& img1_f, Mat& img2, uint16_t delta, uint8_t k_filter) {

	Mat img2_f;						//	Создание объектa под фильтрацию
	img2.copyTo(img2_f);			//	Копирование

	//boxFilter(img2, img2_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);	//	img2 filtering
	img2.copyTo(img2_f);

	uint16_t shift_x = 0;
	uint16_t shift_y = 0;
	uint32_t error = 0;
	uint32_t min = img2_f.rows * img2_f.cols * 255;
	for (uint32_t i = 0; i < 2 * delta+1; ++i) {
		for (uint32_t j = 0; j < 2 * delta+1; ++j) {
			Mat img2_f_roi_(img2_f, Rect(j, i, img1_f.cols, img1_f.rows));
			Mat img2_f_roi;
			img2_f_roi_.copyTo(img2_f_roi);
			error = err(img1_f, img2_f_roi);
			//printf("%d\n", error);
			if (error < min) {
				min = error;
				shift_x = j;
				shift_y = i;
				//printf("MIN: %d, shift_x = %d, shift_y = %d\n", min, shift_x, shift_y);
			}
		}
	}
	int dx = shift_x - delta;
	int dy = shift_y - delta;
	printf("\tdx:%d\tdy:%d\n", dx, dy);
	Rect shift = Rect(shift_x, shift_y, img1_f.cols, img1_f.rows);

	Mat img_out(img2, shift);
	Mat img_f(img2_f, shift);

	img_f.copyTo(img1_f);

	return img_out;
}