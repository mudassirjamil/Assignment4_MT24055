#include <iostream>
#include <vector>
#include <string>
#include "PublicationManager.h"

int main(int argc, char *argv[])
{
    // Check if author names are provided as command-line arguments
    if (argc < 2)
    {
        std::cerr << "Error: At least one author name must be provided." << std::endl;
        return 1;
    }

    // Create an instance of PublicationManager
    PublicationManager manager;

    // Load publication data from the BibTeX file
    manager.parseBibFile("publist.bib");

    // Process each author name provided in the arguments
    for (int i = 1; i < argc; ++i)
    {
        std::string authorName = argv[i];
        std::cout << "\nPublications for author: " << authorName << std::endl;

        // Fetch the publications associated with the current author
        auto publications = manager.searchByAuthor(authorName);

        if (publications.empty())
        {
            std::cout << "No publications found for " << authorName << "." << std::endl;
            continue;
        }

        // Initialize counters for average co-author calculation
        double totalCoAuthors = 0;
        int publicationCount = 0;

        // Iterate over the author's publications
        for (const auto &publication : publications)
        {
            publication->display();
            std::cout << "------------------------\n";

            // Determine the number of co-authors (excluding the main author)
            const auto &authors = publication->getAuthors();
            totalCoAuthors += (authors.size() - 1);
            publicationCount++;
        }

        // Calculate and display the average number of co-authors
        if (publicationCount > 0)
        {
            double averageCoAuthors = totalCoAuthors / publicationCount;
            std::cout << "Average co-authors for " << authorName << ": "
                      << averageCoAuthors << std::endl;
        }
    }

    return 0;
}
