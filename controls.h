#include <vector>
#include <map>
#include <tuple>

#pragma once

// Use VK_ prefix for all keyboard shortcuts.
// For letters just place in single quote instead (eg: 'A')

// This key will toggle on/off click spam.
#define TOGGLE_KEY VK_F2

// This key will terminate loop and exit program.
#define QUIT_KEY VK_F4

// Uncomment this if you wanna auto start autoclicker bot enabled.
// #define ENABLE_AUTOSTART

// Comment this above if you don't want hear an beep when clicker is on/off or quitting.
#define ENABLE_BEEP 1

enum BeepState
{
	On,
	Off,
	Quit
};

#define DECLARE_BEEP(State, Freq, Time) { BeepState:: State, std::make_pair<DWORD, DWORD>(Freq, Time) }

static std::map<BeepState, std::pair<DWORD, DWORD>> beeps =
{
	// Set beep info for all states. 
	// DECLARE_BEEP(Type, Frequency, Time)
	// Each state must be only set once!!!
	// Beep types are: On, Off and Quit

	DECLARE_BEEP(On   , 5000 , 20),
	DECLARE_BEEP(Off  , 1000 , 20),
	DECLARE_BEEP(Quit , 300  , 20),
};

#undef DECLARE_BEEP

// This set of keys will be pressed (eg: Kiwi clicker there's some special keys to press)
std::vector<DWORD> keyboard =
{
	// Kiwi security
	'S',

	// Kiwi generator (alt)
	VK_SPACE
};