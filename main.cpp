#include "RTree.h"

int main() {
    setlocale(LC_CTYPE, "");
    RTree tree;
    tree.readFile("ukraine_poi.csv");
    /*tree.findPlace(50.39195, 30.45944, 500, tree.root->children[0]);
    tree.findPlace(50.39195, 30.45944, 500, tree.root->children[1]);*/
    tree.findPlace(48.50099, 35.95139, 500, tree.root->children[0]);
    tree.findPlace(48.50099, 35.95139, 500, tree.root->children[1]);
    return 0;
}