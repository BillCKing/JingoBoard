#include <iostream>
#include <Windows.h>

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

HHOOK keyboardHook;

int main() {
	puts("Starting keyboard hook...");
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, 0, 0);    // Using low level hooks. Need to be mindful of timeouts.
	MSG msg{0};
	puts("Entering system message loop...");
	while (GetMessage(&msg, NULL, 0, 0) != 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};
	UnhookWindowsHookEx(keyboardHook);
	puts("Keyboard hook ended.");
	return 0;
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT) lParam;


	if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
		puts("");
		//		Beep(523,10);
		printf("Key pressed: %x", key->vkCode);
	} else if (key->vkCode == VK_ESCAPE) {


	}
	return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}