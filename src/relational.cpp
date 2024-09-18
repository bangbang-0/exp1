#include "../include/relational.h"

relational::relational(Student *student, SongLingCar *songLingCar) {
    this->student = student;
    this->songLingCar = songLingCar;
}

void relational::show() {
    this->student->print();
    this->songLingCar->print();
}

ostream &operator<<(ostream &out, const relational &relational) {
    out << *relational.student;
    out << *relational.songLingCar;
    return out;
}

istream &operator>>(istream &in, relational &relational) {
    in >> *relational.student >> *relational.songLingCar;
    return in;
}

void relational::save() {
    ofstream out("relational" + to_string(time(nullptr)) + ".txt");
    out << *this->student;
    out << *this->songLingCar;
    out.close();
}

json relational::toJson() {
    json j;
    j["student"] = this->student->toJson();
    j["songLingCar"] = this->songLingCar->toJson();
    return j;
}

void relational::fromJson(json j) {
    this->student->fromJson(j["student"]);
    this->songLingCar->fromJson(j["songLingCar"]);
}