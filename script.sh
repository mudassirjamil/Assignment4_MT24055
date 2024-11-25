#!/bin/bash

# Create project directory
mkdir ResearchPublications

# Navigate into the project directory
cd ResearchPublications || exit

# Create source and header directories
mkdir src include

# Create C++ source files in src directory
touch src/Author.cpp src/Publication.cpp src/InstitutePublicationManager.cpp src/q1.cpp

# Create header files in include directory
touch include/Author.h include/Publication.h include/InstitutePublicationManager.h

echo "Directory structure created successfully."