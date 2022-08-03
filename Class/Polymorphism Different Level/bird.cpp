#include "bird.h"
#include <string>

using namespace std;

Bird::Bird(string wing_color, string description): Animal(description){
    this->m_wing_color = wing_color;
}