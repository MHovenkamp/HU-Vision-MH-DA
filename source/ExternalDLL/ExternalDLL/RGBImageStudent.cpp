#include "RGBImageStudent.h"
#include <iostream>
RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.pixelStorage;
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixelStorage.resize(getWidth() * getHeight());
}

RGBImageStudent::~RGBImageStudent() {
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	pixelStorage.resize(getWidth() * getHeight());
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	pixelStorage = other.pixelStorage;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int index = y * getWidth() + x;
	if(index < pixelStorage.size()){
		pixelStorage[index] = pixel;
	}
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (i < pixelStorage.size()) {
		pixelStorage[i] = pixel;
	}
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int index = y * getWidth() + x;
	if(index < pixelStorage.size()){
		return pixelStorage[index];
	}
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	if (i < pixelStorage.size()) {
		return pixelStorage[i];
	}
	return 0;
}