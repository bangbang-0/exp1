//
// Created by 29789 on 24-9-17.
//

#ifndef Battery_H
#define Battery_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Battery {
private:
    string parameter;
    string externalPowerSupply;
    int chargingTime;

public:
    Battery();
    Battery(string parameter, string externalPowerSupply, int chargingTime);
    ~Battery();

    void setparameter(string parameter);
    string getparameter();
    void setexternalPowerSupply(string externalPowerSupply);
    string getexternalPowerSupply();
    void setchargingTime(int chargingTime);
    int getchargingTime();

    void print();

    friend ostream &operator<<(ostream &out, const Battery &Battery);
    friend istream &operator>>(istream &in, Battery &Battery);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // Battery_H