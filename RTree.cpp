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

void RTree::findPlace(double latitude, double longitude, double radius, Rect rect) {
    if (rect.checkSituation(Location(latitude, longitude, "", "", "", "")) ||
        rect.distance(latitude, longitude, rect.leftUp.latitude, longitude) < radius ||
        rect.distance(latitude, longitude, rect.rightUp.latitude, longitude) < radius ||
        rect.distance(latitude, longitude, latitude, rect.leftUp.longitude) < radius ||
        rect.distance(latitude, longitude, latitude, rect.leftDown.longitude) < radius) 
    {
        for (int i = 0; i < rect.locations.size(); i++) {
            if (rect.distance(latitude, longitude, rect.locations[i].latitude, rect.locations[i].longitude) < radius) {
                cout << rect.locations[i].name << " " << rect.locations[i].type << " " << rect.locations[i].subtype << " "
                    << rect.locations[i].street << " " << rect.locations[i].latitude << " " << rect.locations[i].longitude << endl;
            }
        }
        if (!rect.children.empty()) {
            findPlace(latitude, longitude, radius, rect.children[0]);
            findPlace(latitude, longitude, radius, rect.children[1]);
        }
    }
}