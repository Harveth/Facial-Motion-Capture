#include "process.h"
#include "configs.h"
#include <iostream>
#include "packetTransfer.h"


int process::Fcount = 0, process::Nx = 0, process::Ny = 0, process::prevX = 0, process::prevY = 0, process::Ex = 0, process::Ey = 0, process::Fx = 0, process::Fy = 0, process::prevFx = 0, process::prevFy = 0, process::EFx = 0, process::EFy = 0;

void process::processLandmarks(std::vector<std::vector<Point2f>>& landmarks)
{
	
	//for (int i : configs::points) {
	//	Nx = landmarks[0][i].x;
	//	Ny = landmarks[0][i].y;

	//	if (Fcount == 0) {
	//		prevX = Nx;
	//		prevY = Ny;
	//	}

	//	Ex = Nx - prevX - EFx;
	//	Ey = Ny - prevY - EFy;

	//	//std::cout <<"point " << i << " " << Ex << " " << Ey << std::endl;
	//	packetTransfer::sendPacket("header", Ex, Ey);

	//	prevX = Nx;
	//	prevY = Ny;

	//	Fcount++;
	//}

	for (int i = 0; i < configs::numPoints; i++) {
		Nx = landmarks[0][i].x;
		Ny = landmarks[0][i].y;

		if (Fcount == 0) {
			prevX = Nx;
			prevY = Ny;
		}

		Ex = Nx - prevX - EFx;
		Ey = Ny - prevY - EFy;

		//std::cout <<"point " << i << " " << Ex << " " << Ey << std::endl;
		packetTransfer::sendPacket(configs::headers[i], Ex, Ey);

		prevX = Nx;
		prevY = Ny;

		Fcount++;
	}
}

void process::resetVars()
{
	Fcount = 0;
	Nx = 0;
	Ny = 0;
	prevX = 0;
	prevY = 0;
	Ex = 0;
	Ey = 0;
	Fx = 0;
	Fy = 0;
	prevFx = 0;
	prevFy = 0;
	EFx = 0;
	EFx = 0;
}
