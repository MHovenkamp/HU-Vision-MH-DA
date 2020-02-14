#include "RGBImageStudent.h"

std::vector<RGB> RGBImageStudent::getPixelStorage() const {
	return pixelStorage;
}

RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.getPixelStorage();
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixelStorage.reserve(getWidth() * getHeight());
}

RGBImageStudent::~RGBImageStudent() {
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	pixelStorage.resize(getWidth() * getHeight());
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	pixelStorage = other.getPixelStorage();
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int row = y * getWidth();
	if(row+x < pixelStorage.size()){
		pixelStorage[row + x] = pixel;
	}
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (!i >= pixelStorage.size()) {
		pixelStorage[i] = pixel;
	}
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int row = y * getWidth();
	if(!row+x >= pixelStorage.size()){
		return pixelStorage[row+x];
	}
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	if (!i >= pixelStorage.size()) {
		return pixelStorage[i];
	}
	return 0;
}