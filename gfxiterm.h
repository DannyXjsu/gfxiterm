/*
Graphical Interface for Terminal Emulators using the library NCURSES. Made by DannyXjsu(dannyxjsu@gmail.com) -  VERSION ALPHA 0.1
It features simple graphical interface features such as creating buttons, labels, events, tabs, progress bars, scrolling, more tba.
*/
#pragma once
#include <cstddef>
#include <cstring>
#include <sstream>
#include <ncurses.h>
#include <string>
#include <strings.h>

/*QUICK GUIDE:
    Initialize library with initialize() and end it with ncurses function endwin()
    It is recommended to use namespace gfxi
*/
namespace gfxi {
//Initializes screen function, same as initscr() but just does things all at once. Optional: Create a window, requires height, width, position x and y, also option to draw box around window
    inline void initialize(bool CreateWin = false, int winh = 0, int winw = 0, int winy = 0, int winx = 0, bool DrawBoxWin = false, int boxx = 0, int boxy = 0)
    {
        initscr();
        if(CreateWin){
            WINDOW * win = newwin(winh, winw, winx, winy);
            refresh();
            if(DrawBoxWin)
            {
                box(win,boxx,boxy);
            }
            wrefresh(win);
        }
        refresh();
        noecho();
        cbreak();
    }

    namespace label {
        //Creates label (text). Needs position and text (string)
        inline void create(std::string text, bool DrawBox = false, int x = 0, int y = 0)
        {
            if(DrawBox){
                WINDOW * labelwin = newwin(3, std::strlen(text.c_str()) + 2, y, x);
                refresh();
                box(labelwin, 0, 0);
                mvwprintw(labelwin, 1, 1, "%s", text.c_str());
                wrefresh(labelwin);
            }
            else{
                mvprintw(y, x, "%s", text.c_str());
            }
            refresh();
        }
    }

    namespace wait {
        //Pauses the program and waits for input. Prints on the screen "Press any key to continue"
        inline void pause()
        {
            printw("\nPress any key to continue...");
            refresh();
            getch();
        }

        //Pauses the program and waits for input. Doesn't print anything on the screen
        inline void input()
        {
            getch();
        }

        //Pauses the program and waits for input. Needs a prompt. Prints character input
        inline char print(std::string prompt)
        {   
            printw("%s", prompt.c_str());
            return printw("%c", getch()) && refresh();
        }    
        inline std::string string(std::string prompt, bool hide = false){
            if(hide){
                noecho();
            } else{
            echo();
            }
            nocbreak();
            std::string input;
            printw("%s", prompt.c_str());
            int ch = getch();

            while ( ch != '\n' )
            {
                input.push_back( ch );
                ch = getch();
            }
            cbreak();
            noecho();
            return input;
        }
    }
}