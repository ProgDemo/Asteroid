#include "Analyze.h"

void analyzeWeight(const std::string fileName, const int& limit) {
    try {
        InFile inFile(fileName);
        inFile.init();

        Asteroid tmp;
        int num = 0;

        inFile.first();
        tmp = inFile.getCurrent();
        bool greater = tmp.getWeight() > limit;
        while (!inFile.end()) {
            inFile.next();
            if (!inFile.end() && inFile.getCurrent().getId() == tmp.getId()) {
                greater = greater && inFile.getCurrent().getWeight() > limit;
            } else {
                num += greater ? 1 : 0;

                if(!inFile.end()) {
                    tmp = inFile.getCurrent();
                    greater = tmp.getWeight() > limit;;
                }
            }
        }
        std::cout << "Limit (" << limit << "), num of asteroids: " << num << std::endl;
    } catch (InFile::InFileExceptions e) {
        if (e == InFile::FileNotFoundException) {
            std::cerr << "File not found!\n";
        } else if (e == InFile::EmptyFileException) {
            std::cerr << "File is empty!\n";
        }
    }
}

void analyzeDistance(const std::string fileName) {
    try {
        InFile inFile(fileName);
        inFile.init();

        Asteroid first;
        Asteroid last;
        Asteroid maxItem;
        int max;

        inFile.first();
        first = inFile.getCurrent();
        last = first;
        maxItem = first;
        max;
        bool l = false;

        while (!inFile.end()) {
            inFile.next();
            if (!inFile.end() && inFile.getCurrent().getId() == first.getId()) {
                last = inFile.getCurrent();
            } else {
                int actDistance = first.getDistance() - last.getDistance();
                if (!l && actDistance > 0) {
                    l = true;
                    max = actDistance;
                    maxItem = last;
                } else if (l && actDistance > 0 && actDistance > max) {
                    max = actDistance;
                    maxItem = last;
                }

                if (!inFile.end()) {
                    first = inFile.getCurrent();
                    last = first;
                }
            }
        }
        if (l) {
            std::cout << "Max distance: " << max << ", asteroid: " << maxItem << std::endl;
        } else {
            std::cout << "None of the asteroids came nearer." << std::endl;
        }
    } catch (InFile::InFileExceptions e) {
        if (e == InFile::FileNotFoundException) {
            std::cerr << "File not found!\n";
        } else if (e == InFile::EmptyFileException) {
            std::cerr << "File is empty!\n";
        }
    }
}

void analyzeDistanceFromEarth(const std::string fileName) {
    try {
        InFile inFile(fileName);
        inFile.init();

        inFile.first();
        Asteroid tmp = inFile.getCurrent();
        bool coming = true;

        std::cout << "Asteroids which are coming nearer:\n";
        while (!inFile.end()) {
            inFile.next();
            if (!inFile.end() && inFile.getCurrent().getId() == tmp.getId()) {
                coming = coming &&inFile.getCurrent().getDistance() <= tmp.getDistance();
                tmp = inFile.getCurrent();
            } else {
                if (coming) {
                    std::cout << "\t" << tmp << std::endl;
                }
                if (!inFile.end()) {
                    tmp = inFile.getCurrent();
                    coming = true;
                }
            }
        }
    } catch (InFile::InFileExceptions e) {
        if (e == InFile::FileNotFoundException) {
            std::cerr << "File not found!\n";
        } else if (e == InFile::EmptyFileException) {
            std::cerr << "File is empty!\n";
        }
    }
}
