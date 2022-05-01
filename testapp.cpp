#include "gfxiterm.h"

using namespace gfxi;

int main (int argc, char ** argv)
{
    //Initalize screen
    initialize();


    label::create("LOGIN SCREEN\n");
    std::string username = wait::string("Username: ");
    std::string password = wait::string("Password: ",true);
    clear();
    label::create(username , true, 1, 1);
    label::create("Your password is: ", true, 1, 3);
    label::create(password, true, 1+strlen("Your password is: ")+1, 3);
    label::create("Welcome. Press any key to continue..." , true, 1, 5);
    wait::input();

    endwin();
    return 0;
}