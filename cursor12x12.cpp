#include <LedTableNxN.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Cursor12x12.h>

Cursor12x12::Cursor12x12(int n, int dataPin, neoPixelType flags) : LedTableNxN(n)
{
    this->table = new Adafruit_NeoPixel(144, dataPin, flags);
    this->table->begin();
#if MESA == 1
    this->table->show();
#endif
}

Cursor12x12::~Cursor12x12()
{
    free(table);
    free(buffer);
}

void Cursor12x12::drawPixel(int16_t x, int16_t y, uint16_t color)
{
    if (buffer)
    {
        if ((x < 0) || (y < 0) || (x >= _width) || (y >= _height))
            return;

        int16_t t;
        switch (rotation)
        {
        case 1:
            t = x;
            x = WIDTH - 1 - y;
            y = t;
            break;
        case 2:
            x = WIDTH - 1 - x;
            y = HEIGHT - 1 - y;
            break;
        case 3:
            t = x;
            x = y;
            y = HEIGHT - 1 - t;
            break;
        }
        uint8_t red = (color >> 11) << 3;
        uint8_t green = ((color << 5) >> 10) << 2;
        uint8_t blue = ((color << 11) >> 11) << 3;
        uint16_t n = x + (WIDTH * y);
        uint32_t RGBW888 = ((uint32_t)red << 16) | ((uint32_t)green << 8) | (uint32_t)blue;
        this->buffer[n] = RGBW888;
    }
}

void Cursor12x12::setCursorPos(int16_t x, int16_t y)
{
    if (table)
    {
        x = x < 0 ? 0 : (x > WIDTH - 12 ? WIDTH - 12 : x);
        y = y < 0 ? 0 : (y > HEIGHT - 12 ? HEIGHT - 12 : y);
        for (int i = y; i < y + 12; i++)
        {
            for (int j = x; j < x + 12; j++)
            {
                int jc = j;
                if ((i % 2) == ((y + 1) % 2))
                {
                    jc = (12 - (j - x) - 1) ;
                }
                else
                {
                    jc = (j - x);
                }
                int16_t nbuffer = j + (WIDTH * i);
                int16_t n12x12 = jc + 12 * (i - y);
                this->table->setPixelColor(n12x12, buffer[nbuffer]);
            }
        }
    }
}

uint32_t Cursor12x12::getPixel(int n)
{
    return this->table->getPixelColor(n);
}

uint32_t Cursor12x12::getPixel(int16_t x, int16_t y)
{
    uint16_t n = x + (WIDTH * y);
    return this->buffer[n];
}
