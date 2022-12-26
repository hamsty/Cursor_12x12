# Cursor 12x12


## Introdução

    Essa biblioteca permite navegar em um espaço NxN criado pela biblioteca [Led_Table_NxN](https://github.com/hamsty/Led_Table_NxN) usando apenas uma mesa de LED 12x12. Ela também usa a biblioteca [Adafruit Neopixel](https://github.com/adafruit/Adafruit_NeoPixel) para endereçar os LEDs na mesa.

## Funções

    Como a classe principal é filha da classe principal de Led_Table_NxN, ele possui todas suas funções, mais duas:

- `void setCursorPos(int16_t x, int16_t y);` 

    É usada para setar qual posição da matrix NxN será mapeada para o cursor 12x12, sendo o mapeamento feito como o desenho de um retângulo começando pela ponta alta a esquerda.

- `uint32_t getPixel(int16_t x, int16_t y);`

    É usada para identificar a cor do pixel (x,y) para diversos fins.

## Casos de uso

É usado no projeto [Labirinto](https://github.com/hamsty/Labirinto/).

