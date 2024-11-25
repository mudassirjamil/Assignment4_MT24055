// Publication.h
#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>
#include <vector>
#include "Author.h"

class Publication
{
private:
    std::string title;
    std::string venue;
    std::vector<Author> authors;
    std::string doi;
    int year;

public:
    Publication(const std::string &title, const std::string &venue, const std::vector<Author> &authors, int year, const std::string &doi = "");
    void display() const;

    // Getter for authors
    const std::vector<Author> &getAuthors() const;
};

#endif // PUBLICATION_H