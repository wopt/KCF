#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "kcftracker.hpp"

#include <dirent.h>

using namespace std;
using namespace cv;


int main(int argc, char* argv[]){

    // Create KCFTracker object
    bool HOG = true;
	bool FIXEDWINDOW = false;
	bool MULTISCALE = true;
	bool LAB = false;
	KCFTracker tracker(HOG, FIXEDWINDOW, MULTISCALE, LAB);

	// Read Images
	ifstream listFramesFile;
	string listFrames = "../images/IMG_2345.txt";
	listFramesFile.open(listFrames);
	string frameName;

    // Groundtruth
    float xMin = 325.0;
    float yMin = 5.0;
    float width = 440.0 - xMin;
    float height = 280.0 - yMin;
    
    // Frame counter
	int nFrames = 0;
    Mat frame;
	Rect result;
    while ( getline(listFramesFile, frameName) ){
        frameName = frameName;
        cout << frameName << endl;
        frame = imread(frameName, CV_LOAD_IMAGE_COLOR);

		// Track init
		if (nFrames == 0) {
			tracker.init(Rect(xMin, yMin, width, height), frame);
			rectangle(frame, Point(xMin, yMin), Point(xMin + width, yMin + height), Scalar(0, 255, 255), 1, 8);
            imwrite("frame0.bmp", frame);
		}
        // Update
		else{
			result = tracker.update(frame);
			rectangle(frame, Point(result.x, result.y), Point(result.x + result.width, result.y + result.height), Scalar( 0, 255, 255 ), 1, 8);
		}
        nFrames++;
        imshow("Image", frame);
        waitKey(1);
    }
}

// Write Results
// ofstream resultsFile;
// string resultsPath = "output.txt";
// resultsFile.open(resultsPath);

// resultsFile << xMin << "," << yMin << "," << width << "," << height << endl;
// resultsFile.close();
