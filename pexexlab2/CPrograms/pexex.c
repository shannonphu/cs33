#include <limits.h>
  int big = INT_MAX;
  int testovf (void)
  {
    return big + 1 < big;
  }

int main(void) {
  return testovf();
}
