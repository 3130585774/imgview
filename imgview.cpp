#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sys/ioctl.h>
#include <unistd.h>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
using namespace std;

const char *GRAYSCALE_CHARS = " .:-=+*#%@";

int get_terminal_size(int &rows, int &cols)
{
    struct winsize w{};
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
    {
        rows = w.ws_row;
        cols = w.ws_col;
        return 0;
    }
    return -1;
}

char gray_to_ascii(int gray)
{
    int len = strlen(GRAYSCALE_CHARS);
    int idx = gray * (len - 1) / 255;
    return GRAYSCALE_CHARS[idx];
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <image_file>" << endl;
        return 1;
    }

    int img_w, img_h, channels;
    unsigned char *img = stbi_load(argv[1], &img_w, &img_h, &channels, 3);
    if (!img)
    {
        cerr << "Failed to load image: " << argv[1] << endl;
        return 1;
    }

    int term_rows, term_cols;
    if (get_terminal_size(term_rows, term_cols) != 0)
    {
        cerr << "Failed to get terminal size." << endl;
        stbi_image_free(img);
        return 1;
    }

    float char_aspect = 2.0f;
    int term_px_w = term_cols;
    int term_px_h = term_rows * char_aspect;

    float scale = std::min(
        (float)term_px_w / img_w,
        (float)term_px_h / img_h);

    int target_w = img_w * scale;
    int target_h = img_h * scale / char_aspect;

    for (int y = 0; y < target_h; ++y)
    {
        float src_y = y * (float)img_h / target_h;
        for (int x = 0; x < target_w; ++x)
        {
            float src_x = x * (float)img_w / target_w;
            int ix = (int)src_x;
            int iy = (int)src_y;
            int index = (iy * img_w + ix) * 3;
            unsigned char r = img[index];
            unsigned char g = img[index + 1];
            unsigned char b = img[index + 2];
            int gray = (int)(0.299 * r + 0.587 * g + 0.114 * b);
            char ch = gray_to_ascii(gray);
            cout << ch;
        }
        cout << endl;
    }

    stbi_image_free(img);
    return 0;
}
