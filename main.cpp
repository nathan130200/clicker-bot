#include <Windows.h>
#include <iostream>
#include "controls.h"

bool bSendInput = false;
POINT mousePos;

BOOL IsKeyDown(DWORD key) {
	return GetAsyncKeyState(key) & 0x8000;
}

void pressMouse(DWORD event) {
	mouse_event(event, mousePos.x, mousePos.y, 0, 0);
}

void emitBeepSound(const BeepState state) {
#if ENABLE_BEEP

	auto it = beeps.find(state);

	if (it == beeps.end()) {
		std::string type = state == 0 ? "On" : state == 1 ? "Off" : "Quit";
		printf("error: Beep not found for state: %s (%d)", type.c_str(), state);
		return;
	}
	else {
		Beep(it->second.freq, it->second.time);
	}

#endif
}

void changeState(bool newState) {
	emitBeepSound(newState ? BeepState::On : BeepState::Off);
	printf("Clicker bot %s\n", newState ? ":  on" : ": off");
	bSendInput = newState;
}

int main()
{

#ifdef ENABLE_AUTOSTART
	changeState(true);
#else
	changeState(false);
#endif

	while (TRUE)
	{
		GetCursorPos(&mousePos);
		Sleep(1);

		if (IsKeyDown(TOGGLE_KEY))
		{
			changeState(!bSendInput);

			while (IsKeyDown(TOGGLE_KEY))
				Sleep(1);
		}

		if (IsKeyDown(QUIT_KEY))
			break;

		if (bSendInput) {
			for (auto& key : g_keyboard) {
				keybd_event(key, 0, 0, 0);
			}

			pressMouse(MOUSEEVENTF_LEFTDOWN);
			Sleep(0);
			pressMouse(MOUSEEVENTF_LEFTUP);

			for (auto& key : g_keyboard) {
				keybd_event(key, 0, 2, 0);
			}
		}
	}

	emitBeepSound(BeepState::Quit);

	return 0;
}