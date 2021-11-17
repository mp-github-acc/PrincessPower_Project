#include "Context.h"

Context::Context(State *s):state_(s){

}
Context::~Context(){
    delete state_;
}