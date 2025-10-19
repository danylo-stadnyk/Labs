#include <windows.h>
#include "microcontroler.h"

int main() {
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001);
    Microcontroler mc;
    mc.inputData();
    mc.outputData();

    return 0;
}
