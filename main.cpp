#include "RTree.cpp"


int main() {
 RTree tree;
    tree.readFile("ukraine_poi.csv");
    cout<<tree.getRoot()->leftUp.latitude<<endl;

	return 0;
}
