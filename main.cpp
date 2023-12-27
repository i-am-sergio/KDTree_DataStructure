#include "KDTree.hpp"
#include "KMeans.hpp"
#include "Reader.hpp"

#include <iostream>
#include <vector>

using namespace std;
using namespace kdt;
using namespace rdr;
using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    KMeans kmeans;
    CSVReader reader("pca_result.csv");
    vector<Point3D> data = reader.readCSV();
    vector<Point3D> all_centroides = kmeans.obtenerTresPuntosAleatorios(data);
    kmeans.printVector(all_centroides);
    vector<vector<Point3D>> Cluster = kmeans.KMeans_def(all_centroides, data);
    // kmeans.printVV(Cluster);
    cout << "FINISH\n";
    return 0;
}