#include "PlayerEntity.h"
#include <exception>

struct InputMismatchException : public std::exception {
    const char* what() const throw (){
        return "Invalid Input!";
    }
};

PlayerEntity::PlayerEntity(int id, const std::string &name, int level, int health, int attack, int defense)
    : Entity(id, name, level, health, attack, defense) {

}

void PlayerEntity::startTurn(std::vector<Entity *> opposing_party) {
    std::cout << m_name << "'s turn!" << std::endl;
    std::cout << "Which enemy would you like to attack?" << std::endl;
    bool valid_choice = false;
    int enemy_choice = 0;
    while(!valid_choice) {
        try {
            for(auto x = 1; x <= opposing_party.size(); ++x) {
                std::cout << x << ". " << opposing_party.at(x-1)->getName() << std::endl;
            }
            std::cin >> enemy_choice;
            if(std::cin.fail()){
                throw InputMismatchException();
            }
            valid_choice = true;
        } catch (InputMismatchException e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
        }
    }
    bool valid_choice2 = false;
    int action_choice = 0;
    while(!valid_choice2){
        try {
            std::cout << "Which action would you like to perform?" << std::endl;
            for(auto x = 1; x <= m_actionList.size(); ++x){
                std::cout << x << ". " << m_actionList.at(x-1).m_actionName << std::endl;
            }
            std::cin >> action_choice;
            if(std::cin.fail()) {
                throw InputMismatchException();
            }
            valid_choice2 = true;
        } catch (InputMismatchException e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
        }
    }
    (this->*m_actionList.at(action_choice-1).m_action)(opposing_party.at(enemy_choice-1));
    std::cout << "\n" << std::endl;    
}