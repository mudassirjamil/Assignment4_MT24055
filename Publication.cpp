// Publication.cpp
#include "Publication.h"
#include <iostream>

Publication::Publication(const std::string& title, const std::string& venue, const std::vector<Author>& authors, int year, const std::string& doi)
: title(title), venue(venue), authors(authors), year(year), doi(doi) {}

void Publication::display() const {
    std::cout << "Title: " << title << "\nVenue: " << venue << "\nYear: " << year << "\nDOI: " << doi << "\nAuthors:\n";
    for (const auto& author : authors) {
        std::cout << "- " << author.getName() << " (" << author.getAffiliation() << ")\n";
    }
}

// Getter for authors implementation
const std::vector<Author>& Publication::getAuthors() const {
    return authors; // Return the authors vector
}