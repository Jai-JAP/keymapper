#pragma once

#include <cstdint>
#include <vector>

// Async means that the key can be pressed/released any time afterwards (but
// does not have to). A normal up/down can follow, to "synchronize" the state.
// So *A *B +A +B means that A can be pressed, then B can also be pressed,
// but finally both A and B have to be pressed.
// "Not" in input means, that the key must not be pressed to match.
// In output it ensures the key is released while the command is applied.

enum class KeyState : uint16_t {
  Up,
  Down,
  Not,
  UpAsync,     // internally (in input expression)
  DownAsync,   // internally (in input expression)
  DownMatched, // internally (in sequence)
};

// correspond to Linux keys (see: /usr/include/linux/input-event-codes.h)
enum class Key : uint16_t {
  NONE             = 0,

  ESC              = 1,
  _1               = 2,
  _2               = 3,
  _3               = 4,
  _4               = 5,
  _5               = 6,
  _6               = 7,
  _7               = 8,
  _8               = 9,
  _9               = 10,
  _0               = 11,
  MINUS            = 12,
  EQUAL            = 13,
  BACKSPACE        = 14,
  TAB              = 15,
  Q                = 16,
  W                = 17,
  E                = 18,
  R                = 19,
  T                = 20,
  Y                = 21,
  U                = 22,
  I                = 23,
  O                = 24,
  P                = 25,
  LEFTBRACE        = 26,
  RIGHTBRACE       = 27,
  ENTER            = 28,
  LEFTCTRL         = 29,
  A                = 30,
  S                = 31,
  D                = 32,
  F                = 33,
  G                = 34,
  H                = 35,
  J                = 36,
  K                = 37,
  L                = 38,
  SEMICOLON        = 39,
  APOSTROPHE       = 40,
  GRAVE            = 41,
  LEFTSHIFT        = 42,
  BACKSLASH        = 43,
  Z                = 44,
  X                = 45,
  C                = 46,
  V                = 47,
  B                = 48,
  N                = 49,
  M                = 50,
  COMMA            = 51,
  DOT              = 52,
  SLASH            = 53,
  RIGHTSHIFT       = 54,
  KPASTERISK       = 55,
  LEFTALT          = 56,
  SPACE            = 57,
  CAPSLOCK         = 58,
  F1               = 59,
  F2               = 60,
  F3               = 61,
  F4               = 62,
  F5               = 63,
  F6               = 64,
  F7               = 65,
  F8               = 66,
  F9               = 67,
  F10              = 68,
  NUMLOCK          = 69,
  SCROLLLOCK       = 70,
  KP7              = 71,
  KP8              = 72,
  KP9              = 73,
  KPMINUS          = 74,
  KP4              = 75,
  KP5              = 76,
  KP6              = 77,
  KPPLUS           = 78,
  KP1              = 79,
  KP2              = 80,
  KP3              = 81,
  KP0              = 82,
  KPDOT            = 83,
  ZENKAKUHANKAKU   = 85,
  _102ND           = 86,
  F11              = 87,
  F12              = 88,
  RO               = 89,
  KATAKANA         = 90,
  HIRAGANA         = 91,
  HENKAN           = 92,
  KATAKANAHIRAGANA = 93,
  MUHENKAN         = 94,
  KPJPCOMMA        = 95,
  KPENTER          = 96,
  RIGHTCTRL        = 97,
  KPSLASH          = 98,
  SYSRQ            = 99,
  RIGHTALT         = 100,
  LINEFEED         = 101,
  HOME             = 102,
  UP               = 103,
  PAGEUP           = 104,
  LEFT             = 105,
  RIGHT            = 106,
  END              = 107,
  DOWN             = 108,
  PAGEDOWN         = 109,
  INSERT           = 110,
  DELETE           = 111,
  MACRO            = 112,
  MUTE             = 113,
  VOLUMEDOWN       = 114,
  VOLUMEUP         = 115,
  POWER            = 116,
  KPEQUAL          = 117,
  KPPLUSMINUS      = 118,
  PAUSE            = 119,
  SCALE            = 120,
  KPCOMMA          = 121,
  HANGEUL          = 122,
  HANJA            = 123,
  YEN              = 124,
  LEFTMETA         = 125,
  RIGHTMETA        = 126,
  COMPOSE          = 127,
  STOP             = 128,
  AGAIN            = 129,
  PROPS            = 130,
  UNDO             = 131,
  FRONT            = 132,
  COPY             = 133,
  OPEN             = 134,
  PASTE            = 135,
  FIND             = 136,
  CUT              = 137,
  HELP             = 138,
  MENU             = 139,
  CALC             = 140,
  SETUP            = 141,
  SLEEP            = 142,
  WAKEUP           = 143,
  FILE             = 144,
  SENDFILE         = 145,
  DELETEFILE       = 146,
  XFER             = 147,
  PROG1            = 148,
  PROG2            = 149,
  WWW              = 150,
  MSDOS            = 151,
  SCREENLOCK       = 152,
  DIRECTION        = 153,
  CYCLEWINDOWS     = 154,
  MAIL             = 155,
  BOOKMARKS        = 156,
  COMPUTER         = 157,
  BACK             = 158,
  FORWARD          = 159,
  CLOSECD          = 160,
  EJECTCD          = 161,
  EJECTCLOSECD     = 162,
  NEXTSONG         = 163,
  PLAYPAUSE        = 164,
  PREVIOUSSONG     = 165,
  STOPCD           = 166,
  RECORD           = 167,
  REWIND           = 168,
  PHONE            = 169,
  ISO              = 170,
  CONFIG           = 171,
  HOMEPAGE         = 172,
  REFRESH          = 173,
  EXIT             = 174,
  MOVE             = 175,
  EDIT             = 176,
  SCROLLUP         = 177,
  SCROLLDOWN       = 178,
  KPLEFTPAREN      = 179,
  KPRIGHTPAREN     = 180,
  NEW              = 181,
  REDO             = 182,
  F13              = 183,
  F14              = 184,
  F15              = 185,
  F16              = 186,
  F17              = 187,
  F18              = 188,
  F19              = 189,
  F20              = 190,
  F21              = 191,
  F22              = 192,
  F23              = 193,
  F24              = 194,
  PLAYCD           = 200,
  PAUSECD          = 201,
  PROG3            = 202,
  PROG4            = 203,
  DASHBOARD        = 204,
  SUSPEND          = 205,
  CLOSE            = 206,
  PLAY             = 207,
  FASTFORWARD      = 208,
  BASSBOOST        = 209,
  PRINT            = 210,
  HP               = 211,
  CAMERA           = 212,
  SOUND            = 213,
  QUESTION         = 214,
  EMAIL            = 215,
  CHAT             = 216,
  SEARCH           = 217,
  CONNECT          = 218,
  FINANCE          = 219,
  SPORT            = 220,
  SHOP             = 221,
  ALTERASE         = 222,
  CANCEL           = 223,
  BRIGHTNESSDOWN   = 224,
  BRIGHTNESSUP     = 225,
  MEDIA            = 226,
  SWITCHVIDEOMODE  = 227,
  KBDILLUMTOGGLE   = 228,
  KBDILLUMDOWN     = 229,
  KBDILLUMUP       = 230,
  SEND             = 231,
  REPLY            = 232,
  FORWARDMAIL      = 233,
  SAVE             = 234,
  DOCUMENTS        = 235,
  BATTERY          = 236,
  BLUETOOTH        = 237,
  WLAN             = 238,
  UWB              = 239,
  UNKNOWN          = 240,
  VIDEO_NEXT       = 241,
  VIDEO_PREV       = 242,
  BRIGHTNESS_CYCLE = 243,
  BRIGHTNESS_ZERO  = 244,
  DISPLAY_OFF      = 245,
  WIMAX            = 246,
  RFKILL           = 247,
  MICMUTE          = 248,

  ANY,
  SHIFT,
  CTRL,
  META,

  VIRTUAL1,
  VIRTUAL2,
  VIRTUAL3,
  VIRTUAL4,
  VIRTUAL5,
  VIRTUAL6,
  VIRTUAL7,
  VIRTUAL8,

  COUNT,
};

struct KeyEvent {
  Key key{ Key::NONE };
  KeyState state{ KeyState::Down };

  KeyEvent() = default;
  KeyEvent(Key key, KeyState state)
    : key(key), state(state) {
  }
  bool operator==(const KeyEvent& b) const {
    return (key == b.key && state == b.state);
  }
  bool operator!=(const KeyEvent& b) {
    return !(*this == b);
  }
};

class KeySequence : public std::vector<KeyEvent> {
public:
  KeySequence() = default;
  KeySequence(std::initializer_list<KeyEvent> keys)
    : std::vector<KeyEvent>(keys) {
  }
};

