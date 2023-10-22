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

struct BeepData {
	DWORD freq;
	DWORD time;
};
// 
// List of mapped values to each beep state. 
// 
// Format: 
// { Frequency, Duration }
//
// 

static BeepData beeps[] =
{
	// Set beep info for On state.
	{5000 , 20},

	// Set beep info for Off state.
	{1000 , 20},

	// Set beep info for Quit state.
	{300  , 20},
};

#undef DECLARE_BEEP

// This set of keys will be pressed (eg: Kiwi clicker there's some special keys to press)

static DWORD buttonsToPress[] =
{
	// Kiwi security
	'S',

	// Kiwi generator (alt)
	VK_SPACE
};