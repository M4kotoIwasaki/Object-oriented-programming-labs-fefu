#include <iostream>
#include <fstream>
#include <vector>

struct Pixel
{
    uint8_t b;
    uint8_t g;
    uint8_t r;
};

#pragma pack(push, 1) // we don't need data alligment cause we can break BMP headers structure, so we turn it off
struct BMPHeader
{
    uint16_t fileType;        //"BM" type of file
    uint32_t fileSize;        // Size of the file (in bytes)
    uint16_t reserved1;       // reserved
    uint16_t reserved2;       // reserved
    uint32_t offsetData;       // Offset where the pixel array (bitmap data) can be found
};

struct DIBHeader
{
    uint32_t Size;        // Size of this DIB header (in bytes)
    int32_t Width;        // width of bitmap in pixels
    int32_t Height;       // Height of the bitmap in pixels.Positive for bottom to top pixel order.
    uint16_t Planes;      // Number of color planes being used
    uint16_t bitCount;    // Number of bits per pixel
    uint32_t Compression; // compression
    uint32_t bitMapDataSize;   // 0 - for uncompressed images
    int32_t X_PixelsPerMeter; // resolution of the image
    int32_t Y_PixelsPerMeter; // resolution of the image
    uint32_t colorsUsed;     // Number of colors in the palette
    uint32_t importantColors; // important colors
};
#pragma pack(pop)

int main()
{
    std::string imageFile = "image.bmp";

    const int width = 2;
    const int height = 2;

    //row size with padding (Alignment 4 bytes)
    const int rowSize = (width * 4); // 4 байта на пиксель
    const int dataSize = rowSize * height;   // Размер данных изображения

    std::vector<std::vector<Pixel>> pixels = {
        { {180, 105, 255}, {127, 255, 0} },  // First row (pink & green)
        { {255, 191, 0}, {0, 255, 255} } // Secons row (blue & yellow)
    };

    BMPHeader bmpHeader;
    DIBHeader dibHeader;

    // Filling BMPheader
    bmpHeader.fileType = 0x4D42; // 'BM' type of file
    bmpHeader.fileSize = sizeof(BMPHeader) + sizeof(DIBHeader) + dataSize;  // Complete file size
    bmpHeader.reserved1 = 0; // reserved
    bmpHeader.reserved2 = 0; // reserved
    bmpHeader.offsetData = sizeof(BMPHeader) + sizeof(DIBHeader); // Move to actual image data

    // Filling DIBheader
    dibHeader.Size = sizeof(DIBHeader);
    dibHeader.Width = width;
    dibHeader.Height = height;
    dibHeader.Planes = 1;
    dibHeader.bitCount = 24;  // 24 bits per pixel for colorful pics
    dibHeader.Compression = 0; // no compression
    dibHeader.bitMapDataSize = dataSize;
    dibHeader.X_PixelsPerMeter = 2835;
    dibHeader.Y_PixelsPerMeter = 2835;
    dibHeader.colorsUsed = 0;
    dibHeader.importantColors = 0;

    std::ofstream file(imageFile, std::ios::binary);

    // Headers writing
    file.write(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    file.write(reinterpret_cast<char*>(&dibHeader), sizeof(dibHeader));

    // writing pixels
    for (int y = height - 1; y >= 0; --y)
        {
        for (int x = 0; x < width; ++x)
        {
            const Pixel& pixel = pixels[y][x];
            file.write(reinterpret_cast<const char*>(&pixel), sizeof(Pixel));
        }

        // padding up to 4 bytes
        if (rowSize - width * 3 > 0)
        {
            uint8_t padding[3] = { 0, 0, 0 };
            file.write(reinterpret_cast<const char*>(padding), rowSize - width * 3);
        }
    }

    file.close();
    return 0;
}
