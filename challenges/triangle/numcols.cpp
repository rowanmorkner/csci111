#include <sys/ioctl.h>
#include <unistd.h>

int get_screen_columns()
{
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_col;
}
