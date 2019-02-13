#ifndef PLAYERPARTY_H
#define PLAYERPARTY_H

#include "Party.h"


class PlayerParty : public Party {
    public:
        PlayerParty(const std::string& filename);
        ~PlayerParty();
};

#endif