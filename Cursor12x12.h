#include <LedTableNxN.h>
#include <Adafruit_NeoPixel.h>

class Cursor12x12 : public LedTableNxN{
    public:
        Cursor12x12(int n, int dataPin, neoPixelType flags);
        ~Cursor12x12();
        void drawPixel(int16_t x, int16_t y, uint16_t color);
        void setCursorPos(int16_t x, int16_t y);
        uint32_t getPixel(int n);
        uint32_t getPixel(int16_t x, int16_t y);
};