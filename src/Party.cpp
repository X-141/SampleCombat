#include "Party.h"

#define log(x) std::cout << x << std::endl;


Party::Party(const std::string &filename) {
    std::ifstream file;
    file.open(filename);
    std::string line;
    std::getline(file, line);
    m_PartyID = std::stoi(line);
    m_partyKO = false;
    while(std::getline(file, line)) {
       std::vector<std::string> values;
       for(int x = 0; x < line.size(); ++x) {
           if(line[x] == ':' || x == (line.size() - 1)){
               if(x == (line.size() - 1))
                   x++;
               int count = (x-1);
               while(count > 0 && line[count] != ':')
                   count--;
               if(line[count] == ':')
                   count++;
               values.push_back(line.substr(count, (x - count)));
           }
       }
       m_PartyRoster.push_back(new Entity(std::stoi(values.at(0)), values.at(1), std::stoi(values.at(2)), 
            std::stoi(values.at(3)), std::stoi(values.at(4)), std::stoi(values.at(5))));
    }
    file.close();
}

Party::~Party() {
    for(Entity *entity : m_PartyRoster) {
        delete entity;
    }
    std::cout << "Party deleted" << std::endl;
}

std::vector<Entity *>& Party::getPartyRoster() { return m_PartyRoster; }

int& Party::getPartyID() { return m_PartyID; }

bool Party::beginTurn(Party *opposing_party) {
    for(Entity * current_members : m_PartyRoster) {
        if(current_members->getAlive()){
            current_members->startTurn(opposing_party->getPartyRoster());
            opposing_party->checkPartyStatus();
        }
        if(opposing_party->getPartyKOStatus())
            return opposing_party->getPartyKOStatus();
    }
    //After fighting the opposing team, check the status to flag whether or not
    //they have been defeated
    return opposing_party->getPartyKOStatus();
    //party status will return a boolean value to where it was called. If the value
    //returned is true, then combat will stop. If it returns false, it will continue.
}

void Party::checkPartyStatus() {
    //boolean flag is set to true by default to indicate
    //the assumption that the party has been defeated
    bool status = true;
    for(Entity *entity : m_PartyRoster) {
        if(entity->getAlive()){
            //As long as one member lives,
            //status of the partyKO == false meaning alive
            status = false;
            break;
        }
    }
    //set the flag of the party object to the given function flag
    m_partyKO = status;
}

void Party::updatePartyState(){
    for(Entity *entity: m_PartyRoster)
        entity->updateTempState();
}

void Party::printParty() {
    std::cout << "PartyID: " << m_PartyID << std::endl;
    for(Entity * entity : m_PartyRoster)
        entity->printEntityData();
}