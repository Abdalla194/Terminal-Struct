# Terminal Drawing Library

A small C++ library for controlling text output in a terminal using ANSI escape
sequences. It provides simple functions for printing text at a chosen terminal
position and changing its foreground color.

The project currently includes a demonstration program that displays a small
menu with colored text.

## Features

- Position text at a specific terminal coordinate.
- Change the terminal text color.
- Print text using a simple function call.
- Build the library from source or as a static library (`.a`).
- Uses standard C++ and ANSI escape sequences; no third-party library is
  required.

## Project Structure

```text
Terminal/
├── include/
│   └── mylib.h          # Public function declarations
├── src/
│   ├── main.cpp         # Demonstration program
│   └── mylib.cpp        # Library implementation
├── libmylib.a           # Prebuilt static library (if included)
└── .vscode/             # VS Code build/debug configuration
```

## Requirements

- A C++ compiler such as `g++`.
- GNU `ar` if you want to create the static library.
- A terminal emulator that supports ANSI escape sequences.

The included commands use GCC/G++ and are suitable for Linux. Windows users
should use a terminal that supports ANSI escape sequences, such as a recent
Windows Terminal, and a compatible C++ toolchain.

## Build and Run from Source

From the project root directory, run:

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/mylib.cpp -o terminal-demo
./terminal-demo
```

This compiles the demonstration program together with the library
implementation.

## Build a Static Library

You can compile the library implementation into an object file and package it
as a static library:

```bash
g++ -std=c++17 -Iinclude -c src/mylib.cpp -o mylib.o
ar rcs libmylib.a mylib.o
```

Then compile the demonstration program and link it against the static library:

```bash
g++ -std=c++17 -Iinclude src/main.cpp -L. -lmylib -o terminal-demo
./terminal-demo
```

Keep the library option (`-lmylib`) after the source/object files that use it,
as shown above.

## API Reference

Include the public header in your C++ source file:

```cpp
#include "mylib.h"
```

### `setColor`

```cpp
void setColor(std::string color);
```

Changes the terminal foreground text color. The currently supported color
names are:

| Color | Appearance |
|---|---|
| `red` | Red |
| `green` | Green |
| `yellow` | Yellow |
| `blue` | Blue |
| `magenta` | Magenta |
| `cyan` | Cyan |
| `white` | White |

Example:

```cpp
setColor("blue");
display(5, 3, "Menu");
```

Color names are lowercase. The current implementation does not report an
error for an unsupported color name; it simply emits no new color sequence.

### `display`

```cpp
void display(int x, int y, std::string message);
```

Moves the terminal cursor to the requested position and prints the message.

- `x` is the horizontal position (column).
- `y` is the vertical position (row).
- Positions are 1-based: `(1, 1)` is the top-left cell.

Example:

```cpp
display(5, 3, "Menu");
```

This prints `Menu` beginning at column 5, row 3.

## Example

The demonstration in `src/main.cpp` clears the terminal, prints a blue
"Menu" heading, and displays two menu entries:

```cpp
#include <iostream>
#include "mylib.h"

int main() {
    std::cout << "\033[2J\033[H";

    setColor("blue");
    display(5, 3, "Menu");
    display(5, 4, "Screen 1");

    setColor("white");
    display(5, 5, "Screen 2");

    return 0;
}
```

## ANSI Escape Sequences Used

The library uses these terminal control sequences:

| Sequence | Purpose |
|---|---|
| `\033[y;xH` | Move cursor to row `y`, column `x` |
| `\033[31m` | Set foreground color to red |
| `\033[32m` | Set foreground color to green |
| `\033[33m` | Set foreground color to yellow |
| `\033[34m` | Set foreground color to blue |
| `\033[35m` | Set foreground color to magenta |
| `\033[36m` | Set foreground color to cyan |
| `\033[37m` | Set foreground color to white |
| `\033[2J` | Clear the terminal screen |
| `\033[H` | Move cursor to the home position |

## Current Limitations

- The library currently supports foreground colors only.
- It does not yet provide keyboard input handling or interactive menu
  navigation.
- It does not currently expose a screen-clearing function; the demo writes
  the clear-screen sequence directly.
- Color state is not automatically reset after printing. Set another color
  explicitly or emit the ANSI reset sequence (`\033[0m`) when needed.
- ANSI escape-sequence support depends on the terminal emulator.
- The library does not currently validate coordinates or color names.

## Possible Future Improvements

- Add a function to reset text formatting.
- Add background colors and text styles (bold, underline, etc.).
- Add screen-clearing and cursor-visibility functions.
- Add keyboard input and menu navigation.
- Add input validation and error handling.
- Add a cross-platform abstraction for terminal control.

## License

No license is currently specified. Add a `LICENSE` file before distributing
the project if you want to define how others may use, modify, or redistribute
it.
