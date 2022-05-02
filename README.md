# gfxiterm
Graphical Interface for Terminals (Very Early WIP)

Based on NCurses

# Applying to your program

## Initialize
Use the function `initialize()`, it's the same thing as `initscr()`, but with `refresh()` embeded, has also optional parameters to create a box for testing or having fun.

## Functions
So far there are just a few functions, more is planned to be implemented.

They are categorized in namespaces, it is recommended that you use namespace gfxi so it's easier to read and write the code.

## Wait Functions

* `pause()`
* `input()`
* `print()`
* `string()`

### `pause()`
A simple function to pause the program and display feedback to the user by printing "Press any key to continue".

### `input()`
The same as `getch()`. Pauses the program until user presses a key, displays no feedback.

### `print()` (soon to be removed/replaced)
The same as `string()` but for chars. Pauses the program until uses types a character, requires to press enter to continue.

### `string()`
Pauses the program and prints a prompt, it waits for a string input which is returned in the function.

## Label Functions

* `create()`

### `create()`
Creates a label(text), has option to draw a box around it and to set the position of the label

Kwown issue: the string is very limiting, makes you able to either put a string with quotes or through variables, never both.

# Building optional Test App
Make already does everything for you, just type `make` and it will compile with the necessary library.

If needed you can run `make clean` to delete the compiled program.