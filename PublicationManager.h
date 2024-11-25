#ifndef PUBLICATIONMANAGER_H
#define PUBLICATIONMANAGER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Publication.h"

class PublicationManager {
private:
    std::vector<Publication> publications;
    std::unordered_map<std::string, std::vector<Publication*>> authorIndex;
    const std::string instituteAffiliation = "IIIT-Delhi";

    void validateEntry(const std::string& entry);
    void parseAuthors(const std::string& authorStr, std::vector<Author>& authors);
    void addToAuthorIndex(Publication& publication);

public:
    void addPublication(const Publication& publication);
    void displayPublications() const;
    void parseBibFile(const std::string& filename);
    std::vector<Publication*> searchByAuthor(const std::string& authorName);
};

#endif // PUBLICATIONMANAGER_H