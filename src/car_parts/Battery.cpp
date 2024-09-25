#include "car_parts/Battery.h"

Battery::Battery() {
    this->parameter = "";
    this->externalPowerSupply = "";
    this->chargingTime = 0;
}

Battery::Battery(string parameter, string externalPowerSupply, int chargingTime) {
    this->parameter = parameter;
    this->externalPowerSupply = externalPowerSupply;
    this->chargingTime = chargingTime;
}

Battery::~Battery() = default;

void Battery::setparameter(string parameter) {
    this->parameter = parameter;
}

string Battery::getparameter() {
    return this->parameter;
}

void Battery::setexternalPowerSupply(string externalPowerSupply) {
    this->externalPowerSupply = externalPowerSupply;
}

string Battery::getexternalPowerSupply() {
    return this->externalPowerSupply;
}

void Battery::setchargingTime(int chargingTime) {
    this->chargingTime = chargingTime;
}

int Battery::getchargingTime() {
    return this->chargingTime;
}

void Battery::print() {
    cout << "参数：" << this->parameter << endl;
    cout << "对外供电：" << this->externalPowerSupply << endl;
    cout << "充电时长：" << this->chargingTime << "H" << endl;
}

ostream &operator<<(ostream &out, const Battery &Battery) {
    out << "参数：" << Battery.parameter << endl;
    out << "对外供电：" << Battery.externalPowerSupply << endl;
    out << "充电时长：" << Battery.chargingTime << "H" << endl;
    return out;
}

istream &operator>>(istream &in, Battery &Battery) {
    in >> Battery.parameter >> Battery.externalPowerSupply >> Battery.chargingTime;
    return in;
}

void Battery::save() {
    ofstream out("Battery" + to_string(time(nullptr)) + ".txt");
    out << "参数：" << this->parameter << endl;
    out << "对外供电：" << this->externalPowerSupply << endl;
    out << "充电时长：" << this->chargingTime << "H" << endl;
    out.close();
}

json Battery::toJson() {
    json j;
    j["parameter"] = this->parameter;
    j["externalPowerSupply"] = this->externalPowerSupply;
    j["chargingTime"] = this->chargingTime;
    return j;
}

void Battery::fromJson(json j) {
    this->parameter = j["parameter"];
    this->externalPowerSupply = j["externalPowerSupply"];
    this->chargingTime = j["chargingTime"];
}