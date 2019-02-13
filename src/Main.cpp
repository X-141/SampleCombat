#include "Combat.h"

#define log(x) std::cout << x << std::endl;

int main() {
    PlayerParty *party_1 = new PlayerParty("../partyDirectory/Party1.txt");
    Party *party_2 = new Party("../partyDirectory/Party2.txt");
    party_1->printParty();
    party_2->printParty();
    Combat *combat_1 = new Combat(party_1, party_2);
    combat_1->startFight();
    delete combat_1;
    std::cin.get();
}
