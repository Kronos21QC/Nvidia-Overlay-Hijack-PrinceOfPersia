#include "../lib/pch.h"
#include "../lib/memory/memory.h"


int main() {


#ifdef _DEBUG
    // Only Allocates console if compiled in DEBUG mode.
    if (AllocConsole()) {
        FILE* fp;
        freopen_s(&fp, "CONOUT$", "w", stdout);
        freopen_s(&fp, "CONIN$", "r", stdin);
        freopen_s(&fp, "CONOUT$", "w", stderr);

        std::cout << "[DEBUG] Console successfully allocated!\n";
    }
#endif

	c_overlay overlay;

    while (overlay.msg_loop() && !overlay.ready) {
        // Your Overlay loop
    }

#ifdef _DEBUG
    FreeConsole();
#endif 

	return 1;
}