//#pragma warning(disable : 4996)
# pragma comment(lib, "secur32.lib")
# pragma comment(lib, "winmm.lib")
# pragma comment(lib, "dmoguids.lib")
# pragma comment(lib, "wmcodecdspuuid.lib")
# pragma comment(lib, "msdmo.lib")
# pragma comment(lib, "Strmiids.lib")
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/face.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <chrono>
#include <ctime>
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"
#include <opencv2/dnn/dnn.hpp>
#include "process.h"


using namespace cv;
using namespace std;
using namespace cv::face;


void main() {
	string path = "";
	VideoCapture cap(1); // change video device.
	Mat frame;
	Mat imgGrey;

	CascadeClassifier faceCascade;
	faceCascade.load("haarcascade_frontalface_alt2.xml");
	//faceCascade.load("L:/program files/libs/opencv/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");

	Ptr<Facemark> facemark = FacemarkLBF::create();
	facemark->loadModel("lbfmodel.yaml");

	if (faceCascade.empty()) {
		cout << "error "; 
		return;
	}

	vector<Rect> faces;

	Ptr<Facemark>;


	do {
		cap.read(frame);

		cvtColor(frame, imgGrey, COLOR_BGR2GRAY);


		faceCascade.detectMultiScale(imgGrey, faces, 1.1, 10);

		vector< vector<Point2f>> landmarks;

		bool faceFit = facemark->fit(frame, faces, landmarks);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(255, 255, 255), 3);
			string str = to_string(faces[i].tl().x);
			str += ", ";
			str += to_string(faces[i].tl().y);


			process::Fx = faces[i].x;
			process::Fy = faces[i].y;

			if (process::Fcount == 0) {
				process::prevFx = process::Fx;
				process::prevFy = process::Fy;
			}

			process::EFx = process::Fx - process::prevFx;
			process::EFy = process::Fy - process::prevFy;


			cout << "Face has moved " << process::EFx << " " << process::EFy << endl;

			process::prevFx = process::Fx;
			process::prevFy = process::Fy;
			

		}

		if (faceFit) {

			process::processLandmarks(landmarks);

			drawFacemarks(frame, landmarks[0]);
		}


		imshow("Process", frame);
		waitKey(1);
	} while (true);

}