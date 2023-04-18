#include "class_img.h"

Img Img::operator=(cv::Mat m) {  //  ��� ������������� Mat ���������� �������
    pData = m.data;     //  ����������� � ��������� �� ������ �������
    cx = m.rows;
    cy = m.cols;
    return *this;
}

Img Img::operator=(uchar value) {        //  ��� ������������� uchar ��������
    for (int i = 0; i < cx * cy; ++i)    //  ������������ �� ��� ������ �������
        *(pData + i) = value;
    return *this;
}

uchar& Img::Iterator::operator[](int i) {
    return pRow[i];
}

Img::Iterator Img::operator[](int i) {
    return pData + i * cy;
}