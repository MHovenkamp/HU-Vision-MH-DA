#include "IntensityImageStudent.h"
#include <iostream>
IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.pixelStorage;
}


IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage.resize(getWidth() * getHeight());
}

IntensityImageStudent::~IntensityImageStudent() {
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	pixelStorage.resize(getWidth() * getHeight());
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	pixelStorage = other.pixelStorage;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int index = y * getWidth() + x;
	if (index < pixelStorage.size()) {
		pixelStorage[index] = pixel;
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if(i < pixelStorage.size()){
		pixelStorage[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int index = y * getWidth() + x;
	if(index < pixelStorage.size()){
		return pixelStorage[index];
	}
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if(i < pixelStorage.size()){
		return pixelStorage[i];
	}
	return 0;
}