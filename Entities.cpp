

#include "Entities.h"


Entity ::Entity(int hp_) :hp{hp_}{

}

void Entity::hit(){
    hp -= 1;
}
int Entity::get_hp()const{
    return hp;
}


