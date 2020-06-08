#include "RTree.h"

RTree::RTree() {
    this->root = nullptr;
}

void RTree::readFile(std::string fileName) {
    ifstream in("ukraine_poi.csv");
    if (in.is_open()) {
        string latitude, lontitude, type, subtype, name, street;
        while (!in.eof()) {
            getline(in, latitude, ';');
            if (latitude == "\n") {
                break;
            }
            getline(in, lontitude, ';');
            for (int i = 0; i < latitude.size(); i++) {
                if (latitude[i] == ',') {
                    latitude[i] = '.';
                }
            }
            for (int i = 0; i < lontitude.size(); i++) {
                if (lontitude[i] == ',') {
                    lontitude[i] = '.';
                }
            }
            getline(in, type, ';');
            getline(in, subtype, ';');
            getline(in, name, ';');
            getline(in, street, ';');
            Location location(stod(latitude), stod(lontitude), type, subtype, name, street);
            if (this->root == nullptr) {
                this->root = new Rect(location, location, location, location);
                this->root->addLocation(location);
            }
            this->root->addLocation(location);
        }
        this->root->devideRoot();
        in.close();
    }
    else {
        cout << "File wasn't opened" << endl;
    }
}

Rect* RTree::getRoot() {
    return this->root;
}