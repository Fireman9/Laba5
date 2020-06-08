#include "RTree.h"
/*#include "Location.cpp"
#include "Rect.cpp"*/

RTree::RTree() {
    this->root = nullptr;
}

void RTree::readFile(std::string fileName) {
    ifstream in;
    in.open("ukraine_poi.csv");

    Location location(50, 50, "type", "subtype", "name", "street");
    if (this->root == nullptr) {
        this->root = new Rect(location, location, location, location);
    }
    this->root->addLocation(location);
    Location location2(20,20,"","","","");
    this->root->addLocation(location2);
     Location location3(50, 40, "type1", "subtype1", "name1", "street1");
    this->root->addLocation(location3);
    this->root->devideRoot();
    /*if (in.is_open()) {
              int t =0;
       std::string latitude, lontitude, type, subtype, name, street;
       while (!in.eof()) {cout<<111111111111111;
            std::getline(in, latitude, ';');
            std::getline(in, lontitude, ';');
            std::getline(in, type, ';');
            std::getline(in, subtype, ';');
            std::getline(in, name, ';');
            std::getline(in, street, ';');
            Location location(std::stod(latitude), std::stod(lontitude), type, subtype, name, street);
            if (this->root == nullptr) {
                this->root = new Rect(location, location, location, location);
                               this->root->addLocation(location);
            }
            this->root->addLocation(location);

        }
        in.close();
    } else {
        std::cout << "File wasn't opened" << std::endl;
    }*/
}



Rect *RTree::getRoot() {
    return this->root;
}


//bool RTree::checkSituated(double A, double B, Rect rect) {
//  double latitude, longitude, leftDown, rightUp;
//  latitude = rect.getLatitude();
//  longitude = rect.getLongitude();
//  leftDown = longitude + rect.getHeight();
//  rightUp = latitude + rect.getWidth();
//  if (A > latitude && A < rightUp && B > longitude && B < leftDown) {
//    return true;
//  }
//  return false;
//}
