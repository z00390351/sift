// opencvTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "stdlib.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include <iostream>
//#include <stdio.h>
#include <vector>

using namespace cv;
using namespace std;

#pragma comment(lib,"opencv_core231d.lib")  

int _tmain(int argc, _TCHAR* argv[])
{
	const char* imagename1 = "..\\img\\1.jpg";
	const char* imagename2 = "..\\img\\2.jpg";

	//IplImage * src1 = cvLoadImage(imagename1);
	//IplImage * src2 = cvLoadImage(imagename2);

	Mat img_1 = imread( imagename1, CV_LOAD_IMAGE_GRAYSCALE );    
	Mat img_2 = imread( imagename2, CV_LOAD_IMAGE_GRAYSCALE );     
	if( !img_1.data || !img_2.data )    
	{ std::cout<< " --(!) Error reading images " << std::endl; return -1; }    
	//-- Step 1: Detect the keypoints using SURF Detector    
	int minHessian = 400;    
	SurfFeatureDetector detector( minHessian );    
	std::vector<KeyPoint> keypoints_1, keypoints_2;    
	detector.detect( img_1, keypoints_1 );    
	detector.detect( img_2, keypoints_2 );    
	//-- Draw keypoints    
	Mat img_keypoints_1; Mat img_keypoints_2;     
	drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );    
	drawKeypoints( img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );     
	//-- Show detected (drawn) keypoints    
	imshow("Keypoints 1", img_keypoints_1 );    
	imshow("Keypoints 2", img_keypoints_2 );    
	waitKey(0);    
	return 0;   

	/*Mat input1=imread(imagename1,1);
	Mat input2=imread(imagename2,1);
	SiftFeatureDetector detector;
	vector<KeyPoint> keypoint1,keypoint2;
	detector.detect(input1,keypoint1);

	Mat output1;
	drawKeypoints(input1,keypoint1,output1);
	imshow("sift_result1.jpg",output1);
	imwrite("sift_result1.jpg",output1);

	Mat output2;
	SiftDescriptorExtractor extractor;
	Mat descriptor1,descriptor2;
	BruteForceMatcher<L2<float>> matcher;

	vector<DMatch> matches;
	Mat img_matches;
	detector.detect(input2,keypoint2);
	drawKeypoints(input2,keypoint2,output2);

	imshow("sift_result2.jpg",output2);
	imwrite("sift_result2.jpg",output2);

	extractor.compute(input1,keypoint1,descriptor1);
	extractor.compute(input2,keypoint2,descriptor2);

	matcher.match(descriptor1,descriptor2,matches);

	drawMatches(input1,keypoint1,input2,keypoint2,matches,img_matches);
	imshow("matches",img_matches);
	imwrite("matches.jpg",img_matches);

	waitKey();*/
	return 0;
}

