#include "Brain.h"

#include <iostream>

Brain::Brain() { std::cout << "(Brain) Default constructor called\n"; }

Brain::Brain(const Brain&) { std::cout << "(Brain) Copy constructor called\n"; }

Brain& Brain::operator=(const Brain&) { return *this; }

Brain::~Brain() { std::cout << "(Brain) Destructor called\n"; }
