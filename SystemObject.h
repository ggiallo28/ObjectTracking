#pragma once

#include <opencv2/video/background_segm.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"
#include "Intestazione.h"
#include <iostream>
#include <stdio.h>
#include "t_tracks.h"
#include "Intestazione.h"
#include <fstream>
#include <sstream>
#include "t_Mat.h"
#include <string>
#include <vector>
#include <Math.h>

#define THRESHOLD 0.7
#define INVISIBLEFORTOOLONG 20
#define AGETHRESHOLD 8
#define VISIBILITYTHRESHOLD 0.6
#define DMAX 0.5
#define MINAREA 100
#define MAXAREA 5000

using namespace cv;
using namespace std;

class SystemObject
{
private:
	Ptr<BackgroundSubtractor> pMOG;
public:
	SystemObject() {
		pMOG = createBackgroundSubtractorKNN(500, 400, false); /*history, ngaussianMixuter, shadows*/
	};
	void detectObjects(const Mat, t_Mat<double>&, t_Mat<int>&, Mat&);
	void predictNewLocationsOfTracks(vector<t_tracks>);
	void detectionToTrackAssignment(vector<t_tracks>, t_Mat<double>, t_Mat<int>&, t_Mat<int>&, t_Mat<int>&);
	void updateAssignedTracks(t_Mat<double>, t_Mat<int>, t_Mat<int>, vector<t_tracks>&);
	void updateUnassignedTracks(t_Mat<int>, vector<t_tracks>&);
	void deleteLostTracks(vector<t_tracks>);
	void createNewTracks(t_Mat<double>, t_Mat<int>, t_Mat<int>, int&, vector<t_tracks>&);
	~SystemObject();
};

