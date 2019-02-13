#include "Entity.h"

Entity::Entity(int id, const std::string &name, int level, int health, int attack, int defense)
    : m_ID(id), m_name(name), m_health(health), m_level(level) , m_attack(attack) , m_defense(defense),
    m_tempAttack(attack), m_tempDefense(defense), m_tempHealth(health)
{
    m_actionList.reserve(2);
    m_alive = true;
    m_action = false;
    void (Entity::*action_1)(Entity*) = &Entity::attackEntity;
    void (Entity::*action_2)(Entity*) = &Entity::blockEntity;
    m_actionList.push_back(Action("Attack", action_1));
    m_actionList.push_back(Action("Block", action_1));
    // m_actionList.push_back(action_1);
    // m_actionList.push_back(action_2);
}

Entity::~Entity() { std::cout << "Deleted Entity" << std::endl; }


int Entity::calculateAttack() {
    return (m_level * .5) + (m_attack * 1.5);
}

int Entity::calculateDefense() {
    return (m_level * 0.5) + (m_tempDefense + (m_attack * 0.5));
}

void Entity::damageHealth(int &total_damage) {
    m_health = m_health - total_damage;
    if(m_health <= 0){
        m_health = 0;
        m_alive = false;
    }
    std::cout << m_name << " current health: " << m_health << std::endl;
}

void Entity::attackEntity(Entity *opponent){
    std::cout << m_name << " attacks " << opponent->getName() << std::endl;
    int main_attack = calculateAttack();
    int opponent_defense = opponent->calculateDefense();
    int total_damage = main_attack - opponent_defense;
    if(total_damage < 0 )
        total_damage = 0;
    std::cout << m_name << " performed " << total_damage << " damage" << std::endl;
    opponent->damageHealth(total_damage);
}

void Entity::blockEntity(Entity *opponent) {
    std::cout << m_name << " braces themselves" << std::endl;
    int increase_defense = (m_defense * 1.5) + (.5 * m_level);
    m_tempDefense += increase_defense;
    std::cout << m_name << " temporary defense up: " << increase_defense << std::endl;
}

void Entity::startTurn(std::vector<Entity *> opposing_party){
    //Allow the entity to select a random target from the vector
    //of opposing entities. -> basic vector default is 3
    int enemy_selector = rand() % 3;
    int action_selector = rand() % 2;
    //If the main entity selects a opposing entity that is dead.
    //continue to randomly choose until it finds a valid target.
    while(!opposing_party.at(enemy_selector)->getAlive())
        enemy_selector = rand() % 3;
    //Tell the user which target the main entity is attacking

    // std::cout << m_name << " attacks " << opposing_party.at(enemy_selector)->getName() << std::endl;
    // attackEntity(opposing_party.at(enemy_selector));
    (this->*m_actionList.at(action_selector).m_action)(opposing_party.at(enemy_selector));

    //attacks the entity and updates the health of the entity.
}

void Entity::updateTempState() {
    if(m_tempDefense > m_defense) {
        std::cout << m_name << " temp_defense: " << m_tempDefense << " -> " << m_defense << std::endl;
        m_tempDefense = m_defense;
    }
}

void Entity::printEntityData() {
    std::cout << "EntityID: " << m_ID << "\n" << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Level: " << m_level << std::endl;
    std::cout << "Health: " << m_health << std::endl;
    std::cout << "Attack: " << m_attack << std::endl;
    std::cout << "Defense: " << m_defense << std::endl;
    std::cout << std::endl;
}