#include "IntensityImageStudent.h"

std::vector<Intensity> IntensityImageStudent::getPixelStorage() const {
	return pixelStorage;
}

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = other.getPixelStorage();
}

IntensityImageStudent::IntensityImageStudent(const RGBImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage.reserve(getWidth() * getHeight());
	auto rgbPixels = other.getPixelStorage();
	for (size_t i = 0; i < pixelStorage.size(); i++){
		auto tmp = rgbPixels[i];
		pixelStorage[i] = (tmp.r + tmp.g + tmp.b)/3; //Averaging
		//pixelStorage[i] = (tmp.r * 0.2126 + tmp.g * 0.7152 + tmp.b * 0.0722); //Luma
	}
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
	int index = y * getWidth() + x;
	if (index < pixelStorage.size()) {
		pixelStorage[index] = pixel;
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if(!i >= pixelStorage.size()){
		pixelStorage[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int index = y * getWidth() + x;
	if(!index >= pixelStorage.size()){
		return pixelStorage[index];
	}
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if(!i >= pixelStorage.size()){
		return pixelStorage[i];
	}
	return 0;
}