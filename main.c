#include "rogue.h"

int main ()
{
    Player * user;
    int ch;
    Position * newPosition;

    char ** level;

    screenSetUp();

    mapSetUp();

    level = saveLevelPositions();

    user = playerSetUp();

    /* main game loop */
    while ((ch = getch()) != 'q')
    {
        newPosition = handleInput(ch, user);
        checkPostion(newPosition, user, level);
    }
    endwin();

    return 0;
}


int screenSetUp()
{
    initscr();
    noecho();
    refresh();

    srand(time(NULL));

    return 1;

}