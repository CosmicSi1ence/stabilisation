#include "filter_box.h"

Fil box(int k_filter) {     //  �������� ������� ������������� ������������ �������
    Fil filter(k_filter);
    for (int i = 0; i < k_filter; ++i)
        for (int j = 0; j < k_filter; ++j)
            filter[i][j] = 1. / k_filter / k_filter;
    return filter;
}