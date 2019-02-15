#include "PlayerParty.h"

PlayerParty::PlayerParty(const std::string& filename) {
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
       m_PartyRoster.push_back(new PlayerEntity(std::stoi(values.at(0)), values.at(1), std::stoi(values.at(2)), 
            std::stoi(values.at(3)), std::stoi(values.at(4)), std::stoi(values.at(5))));
    }
    file.close();
}

PlayerParty::~PlayerParty() {
    for(Entity *entity : m_PartyRoster) {
        delete entity;
    }
    std::cout << "Player party deleted" << std::endl;
}
