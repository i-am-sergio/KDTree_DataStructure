#include "KDTree.hpp"
#include "Reader.hpp"

#include <iostream>
#include <vector>

using namespace std;
using namespace kdt;
using namespace rdr;

int main(){
    CSVReader reader("pca_result.csv");
    vector<Point3D> data = reader.readCSV();
    KDTree<3> kdtree;
    int c = 0;
    for (auto &row : data){
        kdtree.insert(row);
        c++;
    }
    cout<<"INSERTED "<<c<<" NODES\n";
    
    // Call other functions here ...
    
    
    
    cout<<"FINISH\n";
    return 0;
}