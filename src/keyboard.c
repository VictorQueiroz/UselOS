/*
 *  UselOS
 *  By M-374 LX <http://m374lx.users.sourceforge.net/>
 *  
 *  keyboard.c - Functions to read the keyboard
 */

#include "keyboard.h"

#include "ioports.h"

static const u8 set1_map[] =
{
	//0x00
	0,
	KEY_ESC,
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',

	//0x08
	'7',
	'8',
	'9',
	'0',
	'-',
	'=',
	'\b',
	'\t',

	//0x10
	'q',
	'w',
	'e',
	'r',
	't',
	'y',
	'u',
	'i',

	//0x18
	'o',
	'p',
	'[',
	']',
	'\n',
	KEY_LCTRL,
	'a',
	's',

	//0x20
	'd',
	'f',
	'g',
	'h',
	'j',
	'k',
	'l',
	';',

	//0x28
	'\'',
	'`',
	KEY_LSHIFT,
	'\\',
	'z',
	'x',
	'c',
	'v',

	//0x30
	'b',
	'n',
	'm',
	',',
	'.',
	'/',
	KEY_RSHIFT,
	0,

	//0x38
	KEY_LALT,
	' ',
	KEY_CAPSLOCK,
	KEY_F1,	
	KEY_F2,	
	KEY_F3,	
	KEY_F4,	
	KEY_F5,

	//0x40
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_NUMLOCK,
	KEY_SCROLLLOCK,
	KEY_HOME,

	//0x48
	KEY_UP,
	KEY_PGUP,
	'-',
	KEY_LEFT,
	'5',
	KEY_RIGHT,
	'+',
	KEY_END,

	//0x50
	KEY_DOWN,
	KEY_PGDOWN,
	KEY_INS,
	KEY_DEL,
	0,
	0,
	0,
	KEY_F11,

	//0x58
	KEY_F12
};

//Read the keyboard by polling. A better idea is to use an IRQ, but this may be
//implemented in the future
u8 keyboard_read()
{
	//Wait while the PS/2 output buffer is full
	while (!(inb(PS2_STATUS_PORT) & PS2_OUTPUT_FULL))
	{
	}

	return inb(PS2_DATA_PORT);
}

u8 keyboard_map_entry(u8 key)
{
	return set1_map[key];
}

