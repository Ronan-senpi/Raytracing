//
// Created by rdher on 17/07/2021.
//

#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <string>
#include "stb_image.h"
#include "stb_image_write.h"
#include "../Helpers/Debug.h"
#include "../Helpers/StringHelpers.h"
#include "../Helpers/Serializer.h"


Image::Image(const std::string &filename) {
    if (read(filename)) {
        Debug::log("Read " + filename);
        path = filename;
        size = width * height * channel;
    } else {
        Debug::log("Can not read " + filename);
    }
}

Image::Image(const Image &img) : Image(img.getWidth(), img.getHeight()) {
    data = new uint8_t[img.getSize()];
    for (int i = 0; i < img.getSize(); ++i) {
        data[i] = img.getData()[i];
    }
    leftTop = img.leftTop;
    rightBottom = img.rightBottom;
    path = img.path;
}

Image::~Image() {
    stbi_image_free(data);
}

bool Image::read(const std::string &filename) {
    data = stbi_load(filename.c_str(), &width, &height, &channel, 0);
    return data != nullptr;
}

bool Image::write(const std::string &filename) {
    ImageType t = Image::getImageType(filename);
    int success;
    if (t == ImageType::PNG) {
        success = stbi_write_png(filename.c_str(), width, height, channel, data, width * channel);
    } else if (t == ImageType::JPG) {
        success = stbi_write_jpg(filename.c_str(), width, height, channel, data, 100);
    }
    return success != 0;
}

ImageType Image::getImageType(const std::string &filename) {
    int pos = filename.find_last_of('.');
    if (pos != -1) {
        std::string ext = filename.substr(pos);
        StringHelper::toLower(&ext);
        if (ext == ".png") {
            return ImageType::PNG;
        } else if (ext == ".jpg") {
            return ImageType::JPG;
        }
    } else {
        Debug::log("Can not find ext of " + filename);
    }
    return ImageType::PNG;
}

Color Image::operator()(const int &x, const int &y) const {
    Color pixel;
    if (channel == 1) {
        pixel[0] = Serializer::serialize(data[(x * 1 * width) + (y * 1)], 0, 255);
    } else if (channel == 2) {
        pixel[0] = Serializer::serialize(data[(x * 2 * width) + (y * 2)], 0, 255);
        pixel[1] = Serializer::serialize(data[(x * 2 * width) + (y * 2) + 1], 0, 255);
    } else if (channel == 3) {
        pixel[0] = Serializer::serialize(data[(x * 3 * width) + (y * 3)], 0, 255);
        pixel[1] = Serializer::serialize(data[(x * 3 * width) + (y * 3) + 1], 0, 255);
        pixel[2] = Serializer::serialize(data[(x * 3 * width) + (y * 3) + 2], 0, 255);
    } else if (channel == 4) {
        pixel[0] = Serializer::serialize(data[(x * 4 * width) + (y * 4)], 0, 255);
        pixel[1] = Serializer::serialize(data[(x * 4 * width) + (y * 4) + 1], 0, 255);
        pixel[2] = Serializer::serialize(data[(x * 4 * width) + (y * 4) + 2], 0, 255);
        pixel.A(Serializer::serialize(data[(x * 4 * width) + (y * 4) + 3], 0, 255));
    }
    return pixel;
}

Color Image::operator()(const float &x, const float &y) const {
    return (*this)(Serializer::deserialize(x, 0, height - 1), Serializer::deserialize(y, 0, width - 1));
}

void Image::operator()(const int &x, const int &y, const Color &color) {
    if (channel == 1) {
        data[(x * 1 * width) + (y * 1)] = Serializer::deserialize(color[0], 0, 255);
    } else if (channel == 2) {
        data[(x * 2 * width) + (y * 2)] = Serializer::deserialize(color[0], 0, 255);
        data[(x * 2 * width) + (y * 2) + 1] = Serializer::deserialize(color[1], 0, 255);
    } else if (channel == 3) {
        data[(x * 3 * width) + (y * 3)] = Serializer::deserialize(color[0], 0, 255);
        data[(x * 3 * width) + (y * 3) + 1] = Serializer::deserialize(color[1], 0, 255);
        data[(x * 3 * width) + (y * 3) + 2] = Serializer::deserialize(color[2], 0, 255);
    } else if (channel == 4) {
        data[(x * 4 * width) + (y * 4)] = Serializer::deserialize(color[0], 0, 255);
        data[(x * 4 * width) + (y * 4) + 1] = Serializer::deserialize(color[1], 0, 255);
        data[(x * 4 * width) + (y * 4) + 2] = Serializer::deserialize(color[2], 0, 255);
        data[(x * 4 * width) + (y * 4) + 3] = Serializer::deserialize(color.A(), 0, 255);
    }
}

