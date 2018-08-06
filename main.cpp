#include <iostream>
#include <Windows.h>

// Callback function for keyboard hook
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

// Keyboard hook
HHOOK keyboardHook;

int main() {
	puts("Starting keyboard hook...");
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, 0, 0);    // Using low level hooks. Need to be mindful of timeouts.
	puts("Keyboard hook started.");
	puts("Preparing message queue...");
	MSG msg{0}; // MSG structure that receives message information from the thread's message queue.
	puts("System message queue prepared.");
	puts("Entering system message loop...");
	while (GetMessage(&msg, NULL, 0, 0) != 0);  // Main message loop quits when function receives WM_QUIT.
	puts("Exited system message loop.");
	puts("Terminating keyboard hook.");
	UnhookWindowsHookEx(keyboardHook);
	puts("Keyboard hook terminated.");
	return 0;
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT) lParam;   // Initializing key code variable.
	printf("%c", key->vkCode);
	return CallNextHookEx(keyboardHook, nCode, wParam, lParam); // Restart the hook loop.
}