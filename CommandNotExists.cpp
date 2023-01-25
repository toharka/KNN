
#include "CommandNotExists.h"

/**
 * The CommandNotExists class is a subclass of Command. It has a default constructor and a destructor.
 * It has a public execute function that takes no parameters and returns nothing. The execute function
 * calls the defaultIO's write function with the string "invalid option"
 */

void CommandNotExists::execute() {
    defaultIO->write("invalid option");
}


