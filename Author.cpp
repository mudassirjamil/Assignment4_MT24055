#include "Author.h"

Author::Author(const std::string& name, const std::string& affiliation) : name(name), affiliation(affiliation) {}

std::string Author::getName() const {
    return name;
}

std::string Author::getAffiliation() const {
    return affiliation;
}