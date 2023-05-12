#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <windows.h>

#include "stab.h"
#include "stab2.h"

#include "err.h"

//#include <time.h>

//#include <string>

using namespace cv;
using namespace std;

int main() {
    //clock_t tStart = clock();

    ShowWindow(GetConsoleWindow(), SW_SHOW);    //     вкл/выкл назойливую консоль (переключение SW_SHOW / SW_HIDE)

    uint16_t delta = 20;
    uint8_t k_filter = 1;

    //char filename1[] = "Resources/image1.jpg";
    //char fullFilename1[MAX_PATH];
    //GetFullPathNameA(filename1, MAX_PATH, fullFilename1, nullptr);
    //Mat img = imread(fullFilename1, IMREAD_GRAYSCALE);
    //string img_label = "img " + to_string(img.cols) + "x" + to_string(img.rows);
    //namedWindow(img_label, WINDOW_AUTOSIZE);
    //imshow(img_label, img);
    //moveWindow(img_label, 0, 65);

    //Mat img1_(img, Rect(delta, delta, img.cols - 2 * delta, img.rows - 2 * delta));
    //Mat img1;
    //img1_.copyTo(img1);
    //string img1_label = "img1 " + to_string(img1.cols) + "x" + to_string(img1.rows);
    //namedWindow(img1_label, WINDOW_AUTOSIZE);
    //imshow(img1_label, img1);
    //moveWindow(img1_label, img.cols+1, 65);

    //Mat img2_(img, Rect(delta, 0, img.cols - 2 * delta, img.rows - 2 * delta));
    //Mat img2;
    //img2_.copyTo(img2);
    //string img2_label = "img2 " + to_string(img2.cols) + "x" + to_string(img2.rows);
    //namedWindow(img2_label, WINDOW_AUTOSIZE);
    //imshow(img2_label, img2);
    //moveWindow(img2_label, img.cols + 1 + img1.cols + 1, 65);



    ////////////////////////////////////////////////////////////////////////////////////////

    //Mat img1_roi_(img1, Rect(0, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));
    //Mat img1_roi;
    //img1_roi_.copyTo(img1_roi);
    //string img1_roi_label = "img1_roi " + to_string(img1_roi.cols) + "x" + to_string(img1_roi.rows);
    //namedWindow(img1_roi_label, WINDOW_AUTOSIZE);
    //imshow(img1_roi_label, img1_roi);
    //moveWindow(img1_roi_label, 0, 65);

    //Mat img1_f;
    //img1_roi.copyTo(img1_f);
    //boxFilter(img1_roi, img1_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT);
    //Mat img2_st;
    //stab2(img1_roi, img1_f, img2, delta, k_filter).copyTo(img2_st);
    //string img2_st_label = "img2_st " + to_string(img2_st.cols) + "x" + to_string(img2_st.rows);
    //namedWindow(img2_st_label, WINDOW_AUTOSIZE);
    //imshow(img2_st_label, img2_st);
    //moveWindow(img2_st_label, img1_roi.cols + 1, 65);



    //char filename1[] = "Resources/image1.jpg";
    //char filename2[] = "Resources/image2.jpg";
    //char filename3[] = "Resources/image3.jpg";
    //char fullFilename1[MAX_PATH];
    //char fullFilename2[MAX_PATH];
    //char fullFilename3[MAX_PATH];
    //GetFullPathNameA(filename1, MAX_PATH, fullFilename1, nullptr);
    //GetFullPathNameA(filename2, MAX_PATH, fullFilename2, nullptr);
    //GetFullPathNameA(filename3, MAX_PATH, fullFilename3, nullptr);

    //cout << "Image file path:\t" << fullFilename1 << endl << endl;
    //cout << "Image file path:\t" << fullFilename2 << endl << endl;
    //cout << "Image file path:\t" << fullFilename3 << endl << endl;
    //Mat img1 = imread(fullFilename1, IMREAD_GRAYSCALE);   //  считываем изображение из файла
    //Mat img2 = imread(fullFilename2, IMREAD_GRAYSCALE);
    //Mat img3 = imread(fullFilename3, IMREAD_GRAYSCALE);
    ////  в формате градаций серого (одноканальный режим)

    //string img1_label = "img1 " + to_string(img1.cols) + "x" + to_string(img1.rows);
    //namedWindow(img1_label, WINDOW_AUTOSIZE);
    //imshow(img1_label, img1);
    //moveWindow(img1_label, 0, 65);

    //string img2_label = "img2 " + to_string(img2.cols) + "x" + to_string(img2.rows);
    //namedWindow(img2_label, WINDOW_AUTOSIZE);
    //imshow(img2_label, img2);
    //moveWindow(img2_label, img1.cols + 1, 65);

    //string img3_label = "img3 " + to_string(img3.cols) + "x" + to_string(img3.rows);
    //namedWindow(img3_label, WINDOW_AUTOSIZE);
    //imshow(img3_label, img3);
    //moveWindow(img3_label, img1.cols + img2.cols + 1, 65);

    //Mat roi1(img1, Rect(delta, delta, img1.cols - 2 * delta, img1.rows - 2 * delta));
    //Mat img1_st_f = img1;

    //Mat img2_st = stab(img1, img1_st_f, img2, delta, k_filter);
    //string img2_st_label = "img2 stabilised " + to_string(img2_st.cols) + "x" + to_string(img2_st.rows);
    //namedWindow(img2_st_label, WINDOW_AUTOSIZE);
    //imshow(img2_st_label, img2_st);                         //  выводим изображение после фильтрации
    //moveWindow(img2_st_label, img1.cols + 1, 65 + img1.rows + 30);

    //Mat img2_st_f = img2_st;

    //Mat img3_st = stab(img2_st, img2_st_f, img3, delta, k_filter);
    //string img3_st_label = "img3 stabilised " + to_string(img3_st.cols) + "x" + to_string(img3_st.rows);
    //namedWindow(img3_st_label, WINDOW_AUTOSIZE);
    //imshow(img3_st_label, img3_st);                         //  выводим изображение после фильтрации
    //moveWindow(img3_st_label, img1.cols + img2.cols + 1, 65 + img3.rows + 30);


    //Mat roi1_(img2, Rect(delta, 0, img2.cols - 2 * delta, img2.rows - 2 * delta));
    //Mat roi2_(img3, Rect(0, delta, img3.cols - 2 * delta, img3.rows - 2 * delta));
    //for (uint16_t i = 0; i < img2.rows; ++i) {
    //    for (uint16_t j = 0; j < img2.cols; ++j) {
    //        *(roi1_.data + i * roi1_.cols + j) = *(roi2_.datastart + i * roi2_.cols + j);
    //    }
    //}
    //namedWindow("tst " + to_string(roi1_.cols) + "x" + to_string(roi1_.rows), WINDOW_AUTOSIZE);
    //imshow("tst " + to_string(roi1_.cols) + "x" + to_string(roi1_.rows), roi1_);                         //  выводим изображение после фильтрации




    char filenameVid1[] = "Resources/vid1.mp4";
    char fullFilenameVid1[MAX_PATH];
    GetFullPathNameA(filenameVid1, MAX_PATH, fullFilenameVid1, nullptr);
    VideoCapture cap(fullFilenameVid1);
    Mat img_vid1, img_vid1_f, img_vid2;
    cap.read(img_vid1);
    //cvtColor(img_vid1, img_vid1, COLOR_BGR2GRAY);
    img_vid1 = img_vid1(Rect(delta, 0, img_vid1.cols - 2 * delta, img_vid1.rows - 2 * delta));          //  cropping  the first frame
    boxFilter(img_vid1, img_vid1_f, -1, Size(k_filter, k_filter), Point(-1, -1), true, BORDER_REFLECT); //  filtering the first frame
    int count = 0;
    while (true) {
        clock_t tStart = clock();
        cap.read(img_vid2);
        //cvtColor(img_vid2, img_vid2, COLOR_BGR2GRAY);
        stab2(img_vid1, img_vid1_f, img_vid2, delta, k_filter).copyTo(img_vid2);

        imshow("Video " + to_string(img_vid2.cols) + "x" + to_string(img_vid2.rows), img_vid1);

        //imshow("Video " + to_string(img_vid1.cols) + "x" + to_string(img_vid1.rows), img_vid1);

        img_vid1 = img_vid2;
        waitKey(1);
        printf("%d\tTime taken: %.3fs", count, (double)(clock() - tStart) / CLOCKS_PER_SEC);
        ++count;
    }




    //Fil filter = box(10);
    //Fil filter = gaussian(13, 2.5);

    //Mat img1_f, img2_f, img3_f;
    //img1.copyTo(img1_f);
    //img2.copyTo(img2_f);
    //img3.copyTo(img3_f);

    //filter2d(img1_f, filter);       //  фильтрация
    //filter2d(img2_f, filter);       //  фильтрация
    //filter2d(img3_f, filter);       //  фильтрация

    //string img1_label_f = img1_label + " filtered";
    //namedWindow(img1_label_f, WINDOW_AUTOSIZE);
    //imshow(img1_label_f, img1_f);                         //  выводим изображение после фильтрации
    //moveWindow(img1_label_f, 0, 65+img1.rows+30);
    //
    //string img2_label_f = img2_label + " filtered";
    //namedWindow(img2_label_f, WINDOW_AUTOSIZE);
    //imshow(img2_label_f, img2_f);                         //  выводим изображение после фильтрации
    //moveWindow(img2_label_f, img1.cols + 1, 65 + img2.rows + 30);
    //
    //string img3_label_f = img3_label + " filtered";
    //namedWindow(img3_label_f, WINDOW_AUTOSIZE);
    //imshow(img3_label_f, img3_f);                         //  выводим изображение после фильтрации
    //moveWindow(img3_label_f, img1.cols + img2.cols + 1, 65 + img3.rows + 30);

    waitKey(0);
    destroyAllWindows();
    //printf("\n\n\nMAIN Time taken: %.3fs\n\n\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;

}
