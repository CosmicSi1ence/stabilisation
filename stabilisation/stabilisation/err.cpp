#include "err.h"

int32_t err(cv::Mat &img1, cv::Mat &img2) {
	int32_t error = 0;
	//clock_t tStart = clock();
	for (uint16_t i = 0; i < img2.rows; ++i) {
		for (uint16_t j = 0; j < img2.cols; ++j) {
			error += abs(*(img1.data + j * img1.rows + i)  - *(img2.data + j * img2.rows + i));	// 0-1 ms
			//error += abs(img1.get(i, j) - img2.get(i, j));	// 1-2 ms
		}
	}
	//printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return error;
}