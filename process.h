#pragma once
#include <opencv2/core/types.hpp>
#include <vector>

using namespace cv;

namespace process {
	extern int Fcount, Nx, Ny, prevX, prevY,Ex, Ey, Fx, Fy, prevFx,  prevFy, EFx, EFy;

	void processLandmarks(std::vector< std::vector<Point2f>> &landmarks);

	void resetVars();
	
}