#include <iostream>
#include "branch.h"
#define STR(text) #text
#define PRINT_TASK(STR)                                                        \
  std::cout << STR(27.4 Practical work.Task 3. The Village of Elves\n\n)

int main()
{
    PRINT_TASK(STR);
    Branch elves;
    elves.accommodationElves();
    elves.findElves();
    std::cout << "     +-----+\n";
    std::cout << "     | END |\n";
    std::cout << "     +-----+\n";
    return 0;
}