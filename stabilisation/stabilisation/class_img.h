#pragma once

#include <opencv2/core.hpp>

class Img {         //  ����� ������� ����������� - �������� ���������
public:             //  �� ������ �������, � ����� ������� �����������
    uchar* pData;
    int cx, cy;
    uint32_t size;

    Img operator=(cv::Mat m);
    Img operator=(uchar value);

    //      ����� ���������� ��������� ���������� [ ][ ]:

    //  ������ � ��������� �������: ������  [ ] - cx - �� �����������
    //                              �����   [ ] - cy - �� ���������
    //  ������: a[2][8] - ������ �������, ������� ������

    class Iterator {
    public:
        uchar* pRow;
        uchar& operator[](int i);
        Iterator(uchar* pRow) : pRow(pRow) {}
    };

    Iterator operator[](int i);

    inline uchar get(int x, int y) {
        return *(pData + y * cx + x);
    }
    inline uchar* set(int x, int y) {
        return (pData + y * cx + x);
    }
};