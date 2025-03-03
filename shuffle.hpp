#ifndef __CGE_SHUFFLE_H__
#define __CGE_SHUFFLE_H__

#include "deck.hpp"

// inital thoughts: maybe accept a deck object and 
// return a deck object? I see no other real way to 
// do this without explicitly being a part of the class.

std::vector<std::shared_ptr<Card>> Riffle(std::vector<std::shared_ptr<Card>> input);
std::vector<std::shared_ptr<Card>> Hindu(std::vector<std::shared_ptr<Card>> input);

#endif
