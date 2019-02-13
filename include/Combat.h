#ifndef COMBAT_H
#define COMBAT_H

#include "Party.h"
#include "PlayerParty.h"

class Combat {
private:
    Party *m_party_1;
    Party *m_party_2;
    
public:
    Combat(Party *party_1, Party *party_2);
    ~Combat();
    void startFight();
    // bool& getEndFight() { return m_end_fight; }
    // void setEndFight(bool end) { m_end_fight = end; }
};

#endif
