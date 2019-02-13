#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>




class Entity {

struct Action {
    Action(std::string name, void(Entity::*pointer)(Entity*)){
        m_actionName = name;
        m_action = pointer;
    }
    std::string m_actionName;
    void (Entity::*m_action)(Entity*);
};

protected:
    int m_ID;
    std::string m_name;
    int m_level , m_health, m_attack, m_defense;
    int m_tempHealth, m_tempAttack, m_tempDefense;
    bool m_alive, m_action;
    //std::vector<void (Entity::*)(Entity*)> m_actionList;
     std::vector<Action> m_actionList;
    
public:
    Entity(int id, const std::string &name, int level, int health, int attack, int defense);
    ~Entity();
    std::string& getName() { return m_name; }
public:
    int& getLevel() { return m_level; }
    int& getHealth() { return m_health; }
    int& getAttack() { return m_attack; }
    int& getDefense() { return m_defense; }
    bool& getAlive() { return m_alive; }
    bool& getAction() { return m_action; }
    void setHealth(int &health) { m_health = health; }
    void setLevel(int &level) { m_level = level; }
    void setAttack(int &attack) { m_attack = attack; }
    void setDefense(int &defense) { m_defense = defense; }
    void setAlive(bool &alive) { m_alive = alive; }
    void setAction(bool &action) { m_action = action; }
public:
    void damageHealth(int &total_damage);
    int calculateAttack();
    int calculateDefense();

    //Note since this is base class that other classes
    //in this program is including. This class can only
    //see entity objects. vv
    void attackEntity(Entity *opponent);
    void blockEntity(Entity *opponent);
    virtual void startTurn(std::vector<Entity *> opposing_party);
    void updateTempState();
    void printEntityData();
};
#endif