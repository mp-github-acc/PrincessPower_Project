#include "Command.h"

Command::Command(Rocket* r) : rocket_(r){

}

Command::~Command(){
    delete this->rocket_;
}

Rocket *Command::getRocket(){
    return this->rocket_;
}