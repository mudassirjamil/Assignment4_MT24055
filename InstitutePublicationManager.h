// InstitutePublicationManager.h
#ifndef INSTITUTEPUBLICATIONMANAGER_H
#define INSTITUTEPUBLICATIONMANAGER_H

#include <vector>
#include "Publication.h"

class InstitutePublicationManager {
private:
    std::vector<Publication> publications;

public:
    void addPublication(const Publication& publication);
    void displayPublications() const;
};

#endif // INSTITUTEPUBLICATIONMANAGER_H