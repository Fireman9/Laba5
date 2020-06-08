#include "RTree.h"

int main(int argc, char* argv[]) {
    setlocale(LC_CTYPE, "");
    RTree tree;
    tree.readFile("ukraine_poi.csv");
    if (argc != 4) {
        cout << "Wrong parametres!" << endl;
        return 0;
    }
    double latitude = atof(argv[1]);
    double longitude = atof(argv[2]);
    double radius = atof(argv[3]);
    tree.findPlace(latitude, longitude, radius, tree.root->children[0]);
    tree.findPlace(latitude, longitude, radius, tree.root->children[1]);
    /*tree.findPlace(50.39195, 30.45944, 500, tree.root->children[0]);
    tree.findPlace(50.39195, 30.45944, 500, tree.root->children[1]);
    tree.findPlace(48.50099, 35.95139, 500, tree.root->children[0]);
    tree.findPlace(48.50099, 35.95139, 500, tree.root->children[1]);*/
    return 0;
}