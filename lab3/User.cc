#include "User.h"

std::ostream& operator<<(std::ostream& os, const User& u)
{
    return os  << "(" << u.getCardNbr() << ") "<< u.getName();
}
