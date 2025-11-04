#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <sys/ioctl.h>
#include <unistd.h>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
using namespace std;

const char *VERSION = "1.0.0";
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
    // Fallback to default values if ioctl fails
    rows = 24;
    cols = 80;
    return -1;
}

char gray_to_ascii(int gray)
{
    int len = static_cast<int>(strlen(GRAYSCALE_CHARS));
    int idx = gray * (len - 1) / 255;
    return GRAYSCALE_CHARS[idx];
}

void print_usage(const char *program_name)
{
    cout << "imgview - ASCII Image Viewer" << endl;
    cout << "Version: " << VERSION << endl << endl;
    cout << "Usage: " << program_name << " <image_file>" << endl;
    cout << "       " << program_name << " --version" << endl;
    cout << "       " << program_name << " --help" << endl << endl;
    cout << "Supported formats: JPEG, PNG, BMP, GIF, PSD, TGA, HDR, PIC, PNM" << endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        print_usage(argv[0]);
        return 1;
    }

    // Handle command line arguments
    string arg = argv[1];
    if (arg == "--version" || arg == "-v")
    {
        cout << "imgview version " << VERSION << endl;
        return 0;
    }
    if (arg == "--help" || arg == "-h")
    {
        print_usage(argv[0]);
        return 0;
    }

    int img_w, img_h, channels;
    unsigned char *img = stbi_load(argv[1], &img_w, &img_h, &channels, 3);
    if (!img)
    {
        cerr << "Error: Failed to load image: " << argv[1] << endl;
        cerr << "Please check if the file exists and is a valid image format." << endl;
        return 1;
    }

    int term_rows, term_cols;
    if (get_terminal_size(term_rows, term_cols) != 0)
    {
        cerr << "Warning: Failed to get terminal size, using defaults (24x80)." << endl;
    }

    // Ensure we have reasonable terminal dimensions
    if (term_rows <= 0 || term_cols <= 0)
    {
        term_rows = 24;
        term_cols = 80;
    }

    float char_aspect = 2.0f;
    int term_px_w = term_cols;
    int term_px_h = static_cast<int>(term_rows * char_aspect);

    float scale = std::min(
        static_cast<float>(term_px_w) / img_w,
        static_cast<float>(term_px_h) / img_h);

    int target_w = static_cast<int>(img_w * scale);
    int target_h = static_cast<int>(img_h * scale / char_aspect);

    for (int y = 0; y < target_h; ++y)
    {
        float src_y = y * static_cast<float>(img_h) / target_h;
        for (int x = 0; x < target_w; ++x)
        {
            float src_x = x * static_cast<float>(img_w) / target_w;
            int ix = static_cast<int>(src_x);
            int iy = static_cast<int>(src_y);
            
            // Bounds checking
            if (ix >= img_w) ix = img_w - 1;
            if (iy >= img_h) iy = img_h - 1;
            
            int index = (iy * img_w + ix) * 3;
            unsigned char r = img[index];
            unsigned char g = img[index + 1];
            unsigned char b = img[index + 2];
            int gray = static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);
            char ch = gray_to_ascii(gray);
            cout << ch;
        }
        cout << endl;
    }

    stbi_image_free(img);
    return 0;
}
