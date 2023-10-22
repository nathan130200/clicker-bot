#include <Windows.h>
#include <vector>

bool bSendInput = false;
POINT mousePos;

void _SimulateMouseInput(DWORD event)
{
	/*INPUT input{ 0 };
	memset(&input, 0, sizeof(INPUT));
	input.type = INPUT_MOUSE;

	memset(&input.mi, 0, sizeof(INPUT));
	input.mi.dx = mousePos.x;
	input.mi.dy = mousePos.y;
	input.mi.mouseData = 0;
	input.mi.dwFlags = event;

	{
		INPUT* inputs = new INPUT[1];
		inputs[0] = input;
		::SendInput(1, inputs, sizeof(INPUT));
	}*/

	mouse_event(event, mousePos.x, mousePos.y, 0, 0);
}

static std::vector<DWORD> keyboardKeys =
{
	VK_SPACE,
	'S'
};

#define TOGGLE_KEY VK_F2
#define EXIT_KEY VK_F4

int main()
{
	printf("Clicker bot %9s\n", bSendInput ? ": ativado" : ": desativado");

	while (TRUE)
	{
		GetCursorPos(&mousePos);
		Sleep(1);

		if (GetAsyncKeyState(TOGGLE_KEY))
		{
			bSendInput = !bSendInput;

			Beep(bSendInput ? 7000 : 14000, 10);

			while (GetAsyncKeyState(TOGGLE_KEY))
				Sleep(1);

			printf("Clicker bot %9s\n", bSendInput ? ": ativado" : ": desativado");
		}

		if (GetAsyncKeyState(EXIT_KEY))
			break;

		if (bSendInput) {
			for (auto& key : keyboardKeys) {
				keybd_event(key, 0, 0, 0);
			}

			_SimulateMouseInput(MOUSEEVENTF_LEFTDOWN);
			Sleep(0);
			_SimulateMouseInput(MOUSEEVENTF_LEFTUP);

			for (auto& key : keyboardKeys) {
				keybd_event(key, 0, 2, 0);
			}
		}
	}

	return 0;
}