// InstitutePublicationManager.cpp
#include "InstitutePublicationManager.h"
#include <iostream>

void InstitutePublicationManager::addPublication(const Publication& publication) {
    publications.push_back(publication);
}

void InstitutePublicationManager::displayPublications() const {
    for (const auto& pub : publications) {
        pub.display();
        std::cout << "------------------------\n";
    }
}