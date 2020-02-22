#include "StudentPreProcessing.h"
#include <iostream>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	auto intens = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (size_t i = 0; i < intens->pixelStorage.size(); i++) {
		auto tmp = image.getPixel(i);
		intens->pixelStorage[i] = (tmp.r + tmp.g + tmp.b)/3; //Averaging
		//intens->pixelStorage[i] = (tmp.r * 0.2126 + tmp.g * 0.7152 + tmp.b * 0.0722); //Luma
	};
	return intens;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}