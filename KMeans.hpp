#pragma once
#include "Node.hpp"
#include "KDTree.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <random>

using namespace std;

class KMeans
{
public:
    void printVV(const std::vector<std::vector<Point3D>> &vectorOfVectors)
    {
        for (const auto &innerVector : vectorOfVectors)
        {
            for (const auto &element : innerVector)
            {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }
    int generateRandomInteger(int lowerLimit, int upperLimit)
    {
        // Use a random device to seed the random number generator
        std::random_device rd;

        // Use the random device to seed the random engine
        std::mt19937 gen(rd());

        // Use the uniform distribution to generate a random integer in the specified range
        std::uniform_int_distribution<int> distribution(lowerLimit, upperLimit);

        return distribution(gen);
    }

    // obtener 3 centroides random
    vector<Point3D> obtenerTresPuntosAleatorios(const vector<Point3D> &puntos)
    {
        std::vector<Point3D> all_centroides;

        if (puntos.size() < 3)
        {
            return all_centroides;
        }

        std::srand(std::time(0));

        int indice1 = generateRandomInteger(0, puntos.size() - 1);
        int indice2, indice3;
        do
        {
            indice2 = generateRandomInteger(0, puntos.size() - 1);
        } while (indice2 == indice1);

        do
        {
            indice3 = generateRandomInteger(0, puntos.size() - 1);
        } while (indice3 == indice1 || indice3 == indice2);

        all_centroides.push_back(puntos[indice1]);
        all_centroides.push_back(puntos[indice2]);
        all_centroides.push_back(puntos[indice3]);
        std::cout << "INDICE  1: " << indice1 << std::endl;
        std::cout << "INDICE  2: " << indice2 << std::endl;
        std::cout << "INDICE  3: " << indice3 << std::endl;
        return all_centroides;
    }

    // insertar los centrodides dentro de KDTree y usar la funcion KNN
    // para encontrar a que centroide est[a mas cercano
    void printVector(const vector<Point3D> &vec)
    {
        std::cout << "Vector Elements: ";
        for (const auto &element : vec)
        {

            std::cout << element << std::endl;
        }
        std::cout << std::endl;
    }

    vector<vector<Point3D>> KMeans_def(const vector<Point3D> &all_centroides, vector<Point3D> &all_points)
    {
        kdt::KDTree<3> kdtree_centroides;
        int c = 0;
        for (auto &row : all_centroides)
        {
            kdtree_centroides.insert(row);
            c++;
        }
        // Point3D pip = {0.0012, 0.00023, 0.00002};
        // printVector(all_centroides);
        // vector<Point3D> num = kdtree_centroides.searchKNN(pip, 1);
        //
        vector<Point3D> cluster_1;
        vector<Point3D> cluster_2;
        vector<Point3D> cluster_3;
        for (int i = 0; i < all_points.size(); i++)
        {
            vector<Point3D> num = kdtree_centroides.searchKNN(all_points[i], 1);
            if (num[0] == all_centroides[0])
            {
                cluster_1.push_back(all_points[i]);
            }
            else if (num[0] == all_centroides[1])
            {
                cluster_2.push_back(all_points[i]);
            }
            else
            {
                cluster_3.push_back(all_points[i]);
            }
            // printVector(num);
        }

        // printVector(cluster_1);
        std::cout << "/////////////////// 1 :" << cluster_1.size() << std::endl;
        std::cout << "/////////////////// 2 :" << cluster_2.size() << std::endl;
        // printVector(cluster_2);
        std::cout << "/////////////////// 3 :" << cluster_3.size() << std::endl;
        // printVector(cluster_3);
        vector<vector<Point3D>> Cluster;
        Cluster.push_back(cluster_1);
        Cluster.push_back(cluster_2);
        Cluster.push_back(cluster_3);

        // printVector(all_centroides);

        // cout << "INSERTED " << c << " NODES\n";
        return Cluster;
    }
};
