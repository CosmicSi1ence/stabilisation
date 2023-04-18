#pragma once

class Fil {         //  ����� ������� ����������� - �������� ���������
public:             //  �� ������ �������, � ����� ������� �����������
    double* pData;
    int cx, cy;

    Fil(int cx);

    Fil operator=(double value);

    class Iterator {
    public:
        double* pRow;
        double& operator[](int i);
        Iterator(double* pRow) : pRow(pRow) {}
    };

    Iterator operator[](int i);

    //inline double get(int x, int y) {
    //    return *(pData + y * cx + x);
    //}

    ~Fil();
};