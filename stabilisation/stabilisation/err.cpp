#include "err.h"

int32_t err(cv::Mat& img1, cv::Mat& img2) {
	int32_t error = 0;
	//clock_t tStart = clock();
	for (uint16_t i = 0; i < img2.rows; ++i) {
		for (uint16_t j = 0; j < img2.cols; ++j) {
			error += abs(*(img1.datastart + i * img1.cols + j) - *(img2.datastart + i * img2.cols + j));
			//printf("Error:\t%d\n", abs(*(img1.data + i * img1.cols + j) - *(img2.data + i * img2.cols + j)));
		}
	}
	//printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return error;
}