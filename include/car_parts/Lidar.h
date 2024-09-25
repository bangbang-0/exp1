//
// Created by 29789 on 24-9-17.
//

#ifndef Lidar_H
#define Lidar_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Lidar {
private:
    string model;
    int channel;
    int testRange;
    int powerConsumption;

public:
    Lidar();
    Lidar(string model, int channel, int testRange, int powerConsumption);
    ~Lidar();

    void setmodel(string model);
    string getmodel();
    void setchannel(int channel);
    int getchannel();
    void settestRange(int testRange);
    int gettestRange();
    void setpowerConsumption(int powerConsumption);
    int getpowerConsumption();

    void print();
    friend ostream &operator<<(ostream &out, const Lidar &Lidar);
    friend istream &operator>>(istream &in, Lidar &Lidar);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // Lidar_H