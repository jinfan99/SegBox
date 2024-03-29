// The code was modified from the photomontage project
// https://grail.cs.washington.edu/projects/photomontage/release/

#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>

#include "maxflow/graph.h"
#include "data.h"

using namespace std;
using namespace cv;

enum INSIDE_MODE {DESIGNATED_SOURCE};
enum OUTSIDE_MODE {COLORS, GRADIENTS, COLORS_AND_GRADIENTS};

class Collage {

private:
	int nImages;
	Data* D;

	
public:
	Collage(Data* Dat);

	int getNImages();
	int getImageHeight();
	int getImageWidth();
	cv::Mat computePhotomontage(INSIDE_MODE insideMode, OUTSIDE_MODE outsideMode);

	static bool isInImage(int x, int y, int offsetX, int offsetY, const Mat &I) {
	return (x - offsetX >= 0 && y - offsetY >= 0 && x - offsetX < I.rows && y - offsetY < I.cols);
}
};

