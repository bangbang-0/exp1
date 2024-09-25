#include "../include/relational.h"

relational::relational(Student *student, Car *car) {
    this->student = student;
    this->car = car;
}

void relational::show() {
    this->student->print();
    this->car->print();
}

ostream &operator<<(ostream &out, const relational &relational) {
    out << *relational.student;
    out << *relational.car;
    return out;
}

istream &operator>>(istream &in, relational &relational) {
    in >> *relational.student >> *relational.car;
    return in;
}

void relational::save() {
    ofstream out("relational" + to_string(time(nullptr)) + ".txt");
    out << *this->student;
    out << *this->car;
    out.close();
}

json relational::toJson() {
    json j;
    j["student"] = this->student->toJson();
    j["Car"] = this->car->toJson();
    return j;
}

void relational::fromJson(json j) {
    this->student->fromJson(j["student"]);
    this->car->fromJson(j["Car"]);
}