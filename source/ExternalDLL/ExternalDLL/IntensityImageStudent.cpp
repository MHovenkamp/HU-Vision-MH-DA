#include "IntensityImageStudent.h"

std::vector<Intensity> IntensityImageStudent::getPixelStorage() const {
	return pixelStorage;
}

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.getPixelStorage();
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage.reserve(getWidth() * getHeight());
}

IntensityImageStudent::~IntensityImageStudent() {
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	pixelStorage.resize(getWidth() * getHeight());
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	pixelStorage = other.getPixelStorage();
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int row = y * getWidth();
	if (row + x < pixelStorage.size()) {
		pixelStorage[row + x] = pixel;
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if(!i >= pixelStorage.size()){
		pixelStorage[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int row = y * getWidth();
	return pixelStorage[row + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if(!i >= pixelStorage.size()){
		return pixelStorage[i];
	}
	return 0;
}