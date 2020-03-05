#include "StudentPreProcessing.h"
#include <iostream>
#include <algorithm>
#include <cmath>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	auto intens = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (size_t i = 0; i < intens->pixelStorage.size(); i++) {
		auto tmp = image.getPixel(i);
		intens->pixelStorage[i] = (tmp.r + tmp.g + tmp.b)/3; // Intensity
		// intens->pixelStorage[i] = std::max(tmp.r,tmp.g,tmp.b); // Value
		// intens->pixelStorage[i] = (std::min(tmp.r,tmp.g,tmp.b) + std::max(tmp.r,tmp.g,tmp.b))/2; // Luster
		// intens->pixelStorage[i] = 0.3*tmp.r + 0.59*tmp.g + 0.11*tmp.b; // Luminance
		// intens->pixelStorage[i] = std::pow(0.2126*tmp.r,1/2.2) + std::pow(0.7152*tmp.g,1/2.2) + std::pow(0.0722*tmp.b,1/2.2); // Luma
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