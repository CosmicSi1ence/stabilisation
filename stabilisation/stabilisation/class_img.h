#pragma once

#include <opencv2/core.hpp>

class Img {         //  Класс матрицы изображения - содержит указатель
public:             //  на первый пиксель, а также размеры изображения
    uchar* pData;
    int cx, cy;
    uint32_t size;

    Img operator=(cv::Mat m);
    Img operator=(uchar value);

    //      далее реализация оператора индексации [ ][ ]:

    //  доступ к элементам матрицы: первые  [ ] - cx - по горизонтали
    //                              вторе   [ ] - cy - по вертикали
    //  пример: a[2][8] - третий столбец, девятая строка

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