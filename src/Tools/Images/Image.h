//
// Created by rdher on 17/07/2021.
//

#ifndef RAYTRACING_IMAGE_H
#define RAYTRACING_IMAGE_H

#include <vector>
#include <array>
#include <string>

#include "ImageType.h"
#include "../Color.h"

class Image {
private:
    uint8_t *data = nullptr;
    size_t size = 0;
    int width; // x
    int height; // y
    int channel;
    std::array<int, 2> leftTop;
    std::array<int, 2> rightBottom;

    std::string path;
public:


    Image(const std::string &filename);

    Image(int w, int h) : width(w), height(h), channel(3) {
        size = width * height * channel;
        data = new uint8_t[size];
    }

    Image(int w, int h, Color color) : width(w), height(h), channel(3) {
        size = width * height * channel;
        data = new uint8_t[size];

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                (*this)(x, y, color);
            }
        }
    }

    Image(const Image &img);

    ~Image();

    /**
     * Load image data
     * @param filename Path to image
     * @return success
     */
    bool read(const std::string &filename);

    /**
     * Save a new image file
     * @param filename path to destination
     * @return success
     */
    bool write(const std::string &filename);

    Color operator()(const int &x, const int &y) const;

    Color operator()(const float &x, const float &y) const;

    void operator()(const int &x, const int &y, const Color &color);

    /**
     * Get image type
     * @param filename Path to image
     * @return image type
     */
    static ImageType getImageType(const std::string &filename);

    // Begin : assessor
    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    inline int getChannel() const {
        return channel;
    }

    inline size_t getSize() const {
        return size;
    }

    inline uint8_t *getData() const {
        return data;
    }

    inline std::string getPath() const {
        return path;
    }

    inline std::array<int, 2> getLeftTop() {
        return leftTop;
    }

    inline void setLeftTop(std::array<int, 2> rt) {
        leftTop = rt;
    }

    inline std::array<int, 2> getRightBottom() {
        return rightBottom;
    }

    inline void setRightBottom(std::array<int, 2> rb) {
        rightBottom = rb;
    }
    // End : assessor
};


#endif //RAYTRACING_IMAGE_H
