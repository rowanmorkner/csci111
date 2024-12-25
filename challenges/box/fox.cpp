#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
using namespace std;

// Function to get terminal width
int get_screen_columns()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

// Function to draw the top of the fox's face (including ears)
void draw_top(int w)
{
    for (int i = 0; i < get_screen_columns() / 2 - w / 2; i++)
        cout << ' ';
    cout << " /\\_/\\ " << endl;  // Ears

    for (int i = 0; i < get_screen_columns() / 2 - w / 2; i++)
        cout << ' ';
    cout << "( o.o )" << endl;  // Eyes
}

// Function to draw the snout and lower part of the fox's face
void draw_bottom(int w)
{
    for (int i = 0; i < get_screen_columns() / 2 - w / 2; i++)
        cout << ' ';
    cout << " > ^ < " << endl;  // Snout
}

int main()
{
    int width = 10;  // Fixed width for our fox
    int screen_width = get_screen_columns();

    // Check if the fox fits on the screen
    if (screen_width < width)
    {
        cout << "That fox is too wide!" << endl;
        exit(0);
    }

    // Draw the fox's face
    draw_top(width);
    draw_bottom(width);

    return 0;
}
