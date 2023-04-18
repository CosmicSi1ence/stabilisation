#include "filter2d.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <windows.h>

#define padIJ   (*(img_pad.data + i * img.cols + j))

using namespace cv;

void filter2d(Mat img, Fil filter) {
    int k_filter = filter.cx;     //  длина фильтра

    Mat img_pad(img.rows + k_filter - 1, img.cols + k_filter - 1, CV_8UC1); //  создание матрицы дополненного изображения

    uint8_t pad = (k_filter - 1) / 2;

    //clock_t tStart = clock();
    uint16_t ii = 0;
    uint16_t jj = 0;
    for (uint16_t i = 0; i < img_pad.rows; ++i) {     //  зеркалирование крев дополненного изображения + заполнение центра исходным
        for (uint16_t j = 0; j < img_pad.cols; ++j) {

            //  углы изображения
            if (i < pad && j < pad) {
                //padIJ = imgM[-i + (pad - 1)][-j + (pad - 1)];
                ii = -i + (pad - 1);
                jj = -j + (pad - 1);
            }
            if (i < pad && j >= img.cols + pad) {
                //padIJ = imgM[-i + (pad - 1)][(imgM.cy + pad) - j + (imgM.cy - 1)];
                ii = -i + (pad - 1);
                jj = (img.cols + pad) - j + (img.cols - 1);
            }
            if (i >= img.rows + pad && j < pad) {
                //padIJ = imgM[(imgM.cx + pad) - i + (imgM.cx - 1)][-j + (pad - 1)];
                ii = (img.rows + pad) - i + (img.rows - 1);
                jj = -j + (pad - 1);
            }
            if (i >= img.rows + pad && j >= img.cols + pad) {
                //padIJ = imgM[(imgM.cx + pad) - i + (imgM.cx - 1)][(imgM.cy + pad) - j + (imgM.cy - 1)];
                ii = (img.rows + pad) - i + (img.rows - 1);
                jj = (img.cols + pad) - j + (img.cols - 1);
            }

            //  края изображения (без углов)
            if (i < pad && j >= pad && j < img.cols + pad) {
                //padIJ = imgM[-i + (pad - 1)][j - pad];
                ii = -i + (pad - 1);
                jj = j - pad;
            }
            if (i >= pad && i < img.rows + pad && j < pad) {
                //padIJ = imgM[i - pad][-j + (pad - 1)];
                ii = i - pad;
                jj = -j + (pad - 1);
            }
            if (i >= pad && i < img.rows + pad && j >= img.cols + pad) {
                //padIJ = imgM[i - pad][(imgM.cy + pad) - j + (imgM.cy - 1)];
                ii = i - pad;
                jj = (img.cols + pad) - j + (img.cols - 1);
            }
            if (i >= img.rows + pad && j >= pad && j < img.cols + pad) {
                //padIJ = imgM[(imgM.cx + pad) - i + (imgM.cx - 1)][j - pad];
                ii = (img.rows + pad) - i + (img.rows - 1);
                jj = j - pad;
            }

            //  основная область - без отражения
            if (i >= pad && i < img.rows + pad && j >= pad && j < img.cols + pad) {
                //padIJ = imgM[i - pad][j - pad];
                ii = i - pad;
                jj = j - pad;
            }
            padIJ = *(img.data + ii * img.cols + jj);
        }
    }

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

    clock_t tStart = clock();
    static int cnt = 0;
    double local_conv = 0;
    for (uint16_t i = 0; i < img.rows; ++i) {
        for (uint16_t j = 0; j < img.cols; ++j) {
            for (uint16_t i1 = 0; i1 < k_filter; ++i1) {
                for (uint16_t j1 = 0; j1 < k_filter; ++j1) {
                    local_conv += *(img_pad.data + i * img_pad.cols + j + i1 * img_pad.cols + j1) * *(filter.pData + i1 * filter.cy + j1);
                }
            }
            *(img.data + i * img.cols + j) = local_conv;
            local_conv = 0;
        }
    }
    ++cnt;
    //printf("%d\tTime taken: %.3fs\n", cnt, (double)(clock() - tStart) / CLOCKS_PER_SEC);

}