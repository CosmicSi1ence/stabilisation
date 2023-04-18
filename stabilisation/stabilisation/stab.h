#pragma once

#include <opencv2/core.hpp>

#include "class_filter.h"

cv::Mat stab(cv::Mat img1, cv::Mat img2, int delta);
