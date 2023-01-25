

#include "CommandExit.h"
/**
 * The function executes the command by writing the exit description to the default IO and then closing
 * the socket
 */

void CommandExit::execute() {
    defaultIO->write(Globals::EXIT_DESCRIPTION);
    defaultIO->sendData();
    defaultIO->closeSocket();
}

