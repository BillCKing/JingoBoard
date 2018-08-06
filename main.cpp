#include <iostream>
#include <Windows.h>

// Callback function for keyboard hook
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

// Keyboard hook
HHOOK keyboardHook;

int main() {
	printf("Starting keyboard hook...");
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, 0, 0);    // Using low level hooks. Need to be mindful of timeouts.

	MSG msg{0}; // MSG structure that receives message information from the thread's message queue.
	while (GetMessage(&msg, NULL, 0, 0) != 0);  // Main message loop quits when function receives WM_QUIT.
	UnhookWindowsHookEx(keyboardHook);
	return 0;
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {


}