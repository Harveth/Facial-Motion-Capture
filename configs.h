#pragma once
#include <string>

namespace configs {
	const int points[] = { 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 37, 38, 39, 40, 41, 42, 43 ,44, 45, 46, 47, 48, 32, 34, 36, 61, 62, 63, 64, 65, 66, 
	67, 68};
	const int numPoints = (sizeof(points) / sizeof(*points));
	const std::string headers[] = { "chin", "brow18", "brow19", "brow20", "brow21", "brow22" , "brow23" , "brow24" , "brow25" ,"brow26" ,"brow27" ,
		"eye37","eye38","eye39","eye40","eye41","eye42","eye43","eye44","eye45","eye46","eye47","eye48", "noseL", "noseC", "noseR", "mouth 61", "mouth 62" ,
		"mouth 63" ,"mouth 64" ,"mouth 65" , "mouth 66" ,"mouth 67" , "mouth 68" };
	const std::string filePath = "video.mp4";
	const std::string yamlPath = "lbfmodel.yaml";
	const std::string cascadePath = "haarcascade_frontalface_alt2.xml";
	#define ADDRESS "127.0.0.1"
	#define PORT 1768
	#define OUTPUT_BUFFER_SIZE 1024
}