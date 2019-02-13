#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H
#include "Entity.h"

class PlayerEntity : public Entity {
    public:
        PlayerEntity(int id, const std::string &name, int level, int health, int attack, int defense);
        ~PlayerEntity();
        void startTurn(std::vector<Entity *> opposing_party);
        //Based on the virtual function of the parent class
};

#endif