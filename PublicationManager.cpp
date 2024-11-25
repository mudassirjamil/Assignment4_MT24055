// PublicationManager.cpp
#include "PublicationManager.h"
#include <iostream>
#include <unordered_set>
#include <regex>

void PublicationManager::addPublication(const Publication &publication)
{
    publications.push_back(publication);
    addToAuthorIndex(publications.back());
}

void PublicationManager::displayPublications() const
{
    for (const auto &pub : publications)
    {
        pub.display();
        std::cout << "------------------------\n";
    }
}
void PublicationManager::parseBibFile(const std::string &filename)
{
    std::ifstream file(filename);
    assert(file.is_open() && "Could not open the BibTeX file.");

    std::string line;
    std::string entry;

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '%')
            continue; // Skip empty lines and comments

        entry += line + "\n"; // Add line to current entry

        if (line.find("}") != std::string::npos)
        {                         // End of an entry
            validateEntry(entry); // Validate the complete entry
            entry.clear();        // Reset for next entry
        }
    }

    file.close();
}

void PublicationManager::validateEntry(const std::string &entry)
{
    std::cout << "Processing entry:\n"
              << entry << std::endl;

    // Check for valid entry format with braces
    assert(entry.find("{") != std::string::npos && entry.find("}") != std::string::npos && "Invalid format: Missing braces.");

    // Use regex to extract the author field
    std::regex authorRegex(R"(author\s*=\s*\{([^}]+)\})"); // Matches "author = { ... }"
    std::smatch match;

    if (std::regex_search(entry, match, authorRegex))
    {
        std::string authorsStr = match[1]; // Extract the contents inside the braces
        std::cout << "Authors found: " << authorsStr << std::endl;

        std::unordered_set<std::string> authorSet;
        bool hasInstituteAuthor = false;
        std::vector<Author> authors;

        parseAuthors(authorsStr, authors);

        for (const auto &author : authors)
        {
            if (!authorSet.insert(author.getName()).second)
            {
                assert(false && "Invalid entry: Duplicate authors found.");
            }
            if (author.getAffiliation() == instituteAffiliation)
            {
                hasInstituteAuthor = true;
            }
        }

        assert(hasInstituteAuthor && "Invalid entry: No author belongs to the institute's affiliation.");
    }
    else
    {
        assert(false && "Invalid format: No author field found.");
    }
}
void PublicationManager::parseAuthors(const std::string &authorStr, std::vector<Author> &authors)
{
    std::istringstream stream(authorStr);
    std::string authorName;

    while (std::getline(stream, authorName, ','))
    { // Split by comma
        // Trim whitespace
        size_t start = authorName.find_first_not_of(" \t");
        size_t end = authorName.find_last_not_of(" \t");

        if (start != std::string::npos && end != std::string::npos)
        {
            authorName = authorName.substr(start, end - start + 1);
            authors.emplace_back(authorName, "Unknown Affiliation"); // Placeholder for affiliation
        }
    }
}
void PublicationManager::addToAuthorIndex(Publication &publication)
{
    for (const auto &author : publication.getAuthors())
    { // Now this works correctly
        authorIndex[author.getName()].push_back(&publication);
    }
}

std::vector<Publication *> PublicationManager::searchByAuthor(const std::string &authorName)
{
    return authorIndex[authorName];
}