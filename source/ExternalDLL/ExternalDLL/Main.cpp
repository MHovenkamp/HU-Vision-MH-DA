/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include <iostream> //std::cout
#include "ImageIO.h" //Image load and save functionality
#include "HereBeDragons.h"
#include "ImageFactory.h"
#include "DLLExecution.h"
#include <fstream>
#include <map>

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features);
bool executeSteps(DLLExecution * executor);

int main(int argc, char * argv[]) {

	std::string path = "C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\";

	ImageFactory::setImplementation(ImageFactory::DEFAULT);
	//ImageFactory::setImplementation(ImageFactory::STUDENT);

	std::vector<std::string> picturesOrg;
	std::vector<std::string> picturesA;
	std::vector<std::string> picturesB;
	std::vector<std::string> picturesC;
	std::vector<std::string> picturesD;
	std::vector<std::string> picturesE;
	std::vector<std::string> picturesF;

	std::map<std::string, std::vector<std::string>> pictures;

	std::ifstream infileOrg("C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\SetA.txt");
	std::ifstream infileA("C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\RandomA.txt");
	std::ifstream infileB("C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\RandomB.txt");
	std::ifstream infileC("C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\RandomC.txt");
	std::ifstream infileD("C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\RandomD.txt");
	std::ifstream infileE("C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\RandomE.txt");
	std::ifstream infileF("C:\\Users\\mhove\\Documents\\GitHub\\HU-Vision-MH-DA\\testsets\\RandomF.txt");

	std::string temp;
	while (infileOrg >> temp) {
		picturesOrg.push_back(temp);
	}
	while (infileA >> temp) {
		picturesA.push_back(temp);
	}
	while (infileB >> temp) {
		picturesB.push_back(temp);
	}
	while (infileC >> temp) {
		picturesC.push_back(temp);
	}
	while (infileD >> temp) {
		picturesD.push_back(temp);
	}
	while (infileE >> temp) {
		picturesE.push_back(temp);
	}
	while (infileF >> temp) {
		picturesF.push_back(temp);
	}

	//pictures["Set A"] = picturesOrg;
	//pictures["Random A"] = picturesA;
	//pictures["Random B"] = picturesB;
	//pictures["Random C"] = picturesC;
	//pictures["Random D"] = picturesD;
	//pictures["Random E"] = picturesE;
	pictures["Random F"] = picturesF;

	for (auto & key : pictures) {
		std::cout << key.first << std::endl;
		for (auto & item: key.second) {
			std::string name = item.substr(0,item.size()-4);
			std::string tmp = path + "Results\\" + key.first + "\\" + name;
			ImageIO::debugFolder = tmp;
			std::cout << key.first << " | " << item << std::endl;
			ImageIO::isInDebugMode = true;

			RGBImage * input = ImageFactory::newRGBImage();
			if (!ImageIO::loadImage(path + key.first + "\\"+ item, *input)) {
				std::cout << "Image could not be loaded!" << std::endl;
				system("pause");
				return 0;
			}

			ImageIO::saveRGBImage(*input, ImageIO::getDebugFileName(item));

			DLLExecution * executor = new DLLExecution(input);


			if (executeSteps(executor)) {
				std::cout << "Face recognition successful!" << std::endl;
				std::cout << "Facial parameters: " << std::endl;
				for (int i = 0; i < 16; i++) {
					std::cout << (i + 1) << ": " << executor->facialParameters[i] << std::endl;
				}
			}

			delete executor;
			std::cout << "finished one \n";
		}
	}
		system("pause");
		return 1;
	}










bool executeSteps(DLLExecution * executor) {

	//Execute the four Pre-processing steps
	if (!executor->executePreProcessingStep1(true)) {
		std::cout << "Pre-processing step 1 failed!" << std::endl;
		return false;
	}

	if (!executor->executePreProcessingStep2(false)) {
		std::cout << "Pre-processing step 2 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep2, ImageIO::getDebugFileName("Pre-processing-2.png"));

	if (!executor->executePreProcessingStep3(false)) {
		std::cout << "Pre-processing step 3 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep3, ImageIO::getDebugFileName("Pre-processing-3.png"));

	if (!executor->executePreProcessingStep4(false)) {
		std::cout << "Pre-processing step 4 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep4, ImageIO::getDebugFileName("Pre-processing-4.png"));



	//Execute the localization steps
	if (!executor->prepareLocalization()) {
		std::cout << "Localization preparation failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep1(false)) {
		std::cout << "Localization step 1 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep2(false)) {
		std::cout << "Localization step 2 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep3(false)) {
		std::cout << "Localization step 3 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep4(false)) {
		std::cout << "Localization step 4 failed!" << std::endl;
		return false;
	}

	if (!executor->executeLocalizationStep5(false)) {
		std::cout << "Localization step 5 failed!" << std::endl;
		return false;
	}



	//Execute the extraction steps
	if (!executor->prepareExtraction()) {
		std::cout << "Extraction preparation failed!" << std::endl;
		return false;
	}

	if (!executor->executeExtractionStep1(false)) {
		std::cout << "Extraction step 1 failed!" << std::endl;
		return false;
	}

	if (!executor->executeExtractionStep2(false)) {
		std::cout << "Extraction step 2 failed!" << std::endl;
		return false;
	}

	if (!executor->executeExtractionStep3(false)) {
		std::cout << "Extraction step 3 failed!" << std::endl;
		return false;
	}


	//Post processing and representation
	if (!executor->executePostProcessing()) {
		std::cout << "Post-processing failed!" << std::endl;
		return false;
	}

	drawFeatureDebugImage(*executor->resultPreProcessingStep1, executor->featuresScaled);

	if (!executor->executeRepresentation()) {
		std::cout << "Representation failed!" << std::endl;
		return false;
	}
	return true;
}

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features) {
	RGB colorRed(244, 67, 54);
	RGBImage * debug = ImageFactory::newRGBImage(image.getWidth(), image.getHeight());
	ImageIO::intensityToRGB(image, *debug);

	//Nose
	Point2D<double> noseLeft = features.getFeature(Feature::FEATURE_NOSE_END_LEFT)[0];
	Point2D<double> noseRight = features.getFeature(Feature::FEATURE_NOSE_END_RIGHT)[0];
	Point2D<double> nostrilLeft = features.getFeature(Feature::FEATURE_NOSTRIL_LEFT)[0];
	Point2D<double> nostrilRight = features.getFeature(Feature::FEATURE_NOSTRIL_RIGHT)[0];
	Point2D<double> noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM)[0];


	//These (weird) methods can be used to draw debug points
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseBottom, colorRed);

	//Chin
	std::vector<Point2D<double>> points = features.getFeature(Feature::FEATURE_CHIN_CONTOUR).getPoints();
	for (size_t i = 0; i < points.size(); i++) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, points[i], colorRed);
	}

	//Eye
	Feature leftEye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature rightEye = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);


	//These (weird) methods can be used to draw debug rects
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, leftEye[0], leftEye[1], colorRed);
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, rightEye[0], rightEye[1], colorRed);


	//Head
	Feature headTop = features.getFeature(Feature::FEATURE_HEAD_TOP);
	Feature headLeftNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_MIDDLE);
	Feature headLeftNoseBottom = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM);
	Feature headRightNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_MIDDLE);
	Feature headRightNoseBottom = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headTop[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseBottom[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseBottom[0], colorRed);

	//Mouth
	Point2D<double> mouthTop = features.getFeature(Feature::FEATURE_MOUTH_TOP)[0];
	Point2D<double> mouthBottom = features.getFeature(Feature::FEATURE_MOUTH_BOTTOM)[0];
	Point2D<double> mouthLeft = features.getFeature(Feature::FEATURE_MOUTH_CORNER_LEFT)[0];
	Point2D<double> mouthRight = features.getFeature(Feature::FEATURE_MOUTH_CORNER_RIGHT)[0];

	//This (weird) method can be used to draw a debug line
	HereBeDragons::ButRisingAtThyNameDothPointOutThee(*debug, mouthLeft, mouthRight, colorRed);

	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthTop, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthBottom, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthRight, colorRed);

	ImageIO::saveRGBImage(*debug, ImageIO::getDebugFileName("feature-points-debug.png"));
	delete debug;
}