#include "class_filter.h"

Fil::Fil(int cx) {
    this->cx = cx;
    this->cy = cx;
    pData = new double[cx * cy];
}

Fil Fil::operator=(double value) {        //  ��� ������������� uchar ��������
    for (int i = 0; i < cx * cy; ++i)    //  ������������ �� ��� ������ �������
        *(pData + i) = value;
    return *this;
}

double& Fil::Iterator::operator[](int i) {
    return pRow[i];
}

Fil::Iterator Fil::operator[](int i) {
    return pData  + i * cy;
}

Fil::~Fil() {
    //delete[] pData;
}