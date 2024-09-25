//
// Created by 29789 on 24-9-17.
//

#ifndef Car_H
#define Car_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../nlohmann/json.hpp"
#include "car_parts/BasePlate.h"
#include "car_parts/AGXKit.h"
#include "car_parts/Camera.h"
#include "car_parts/Lidar.h"
#include "car_parts/Gyroscope.h"
#include "car_parts/LCD.h"
#include "car_parts/Battery.h"

using namespace std;
using json = nlohmann::json;

class Car {
private:
    string id;
    BasePlate basePlate;
    vector<AGXKit> agxKit;
    vector<Camera> camera;
    vector<Lidar> lidar;
    vector<Gyroscope> gyroscope;
    vector<LCD> lcd;
    vector<Battery> battery;

public:
    Car();
    Car(string id, BasePlate basePlate, vector<AGXKit> agxKit, vector<Camera> camera,
        vector<Lidar> lidar, vector<Gyroscope> gyroscope, vector<LCD> lcd,
        vector<Battery> battery);
    ~Car();

    void setid(string id);
    string getid();
    void setBasePlateid(string id);
    void setBasePlate(BasePlate basePlate);
    BasePlate getBasePlate();
    void setagxKit(vector<AGXKit> agxKit);
    vector<AGXKit> getagxKit();
    void setCamera(vector<Camera> Camera);
    vector<Camera> getCamera();
    void setLidar(vector<Lidar> Lidar);
    vector<Lidar> getLidar();
    void setGyroscope(vector<Gyroscope> Gyroscope);
    vector<Gyroscope> getGyroscope();
    void setLcd(vector<LCD> lcd);
    vector<LCD> getLcd();
    void setBattery(vector<Battery> Battery);
    vector<Battery> getBattery();

    void print();
    friend ostream &operator<<(ostream &out, const Car &Car);
    friend istream &operator>>(istream &in, Car &Car);

    void save();
    json toJson();
    void fromJson(json j);
};

#endif // Car_H