#include "../include/Car.h"

Car::Car() = default;

Car::Car(string id, BasePlate basePlate, vector<AGXKit> agxKit, vector<Camera> camera,
         vector<Lidar> lidar, vector<Gyroscope> gyroscope, vector<LCD> lcd,
         vector<Battery> battery) {
    this->id = id;
    this->basePlate = basePlate;
    this->agxKit = agxKit;
    this->camera = camera;
    this->lidar =lidar;
    this->gyroscope = gyroscope;
    this->lcd = lcd;
    this->battery = battery;
}

Car::~Car() = default;

void Car::setid(string id) {
    this->id = id;
}

string Car::getid() {
    return this->id;
}

void Car::setBasePlateid(string id) {
    this->basePlate.setID(id);
}

void Car::setBasePlate(BasePlate basePlate) {
    this->basePlate = basePlate;
}

BasePlate Car::getBasePlate() {
    return this->basePlate;
}

void Car::setagxKit(vector<AGXKit> agxKit) {
    this->agxKit = agxKit;
}

vector<AGXKit> Car::getagxKit() {
    return this->agxKit;
}

void Car::setCamera(vector<Camera> Camera) {
    this->camera = Camera;
}

vector<Camera> Car::getCamera() {
    return this->camera;
}

void Car::setLidar(vector<Lidar> Lidar) {
    this->lidar = Lidar;
}

vector<Lidar> Car::getLidar() {
    return this->lidar;
}

void Car::setGyroscope(vector<Gyroscope> Gyroscope) {
    this->gyroscope = Gyroscope;
}

vector<Gyroscope> Car::getGyroscope() {
    return this->gyroscope;
}

void Car::setLcd(vector<LCD> lcd) {
    this->lcd = lcd;
}

vector<LCD> Car::getLcd() {
    return this->lcd;
}

void Car::setBattery(vector<Battery> battery) {
    this->battery = battery;
}

vector<Battery> Car::getBattery() {
    return this->battery;
}

void Car::print() {
    cout << "编号：" << this->id << endl;
    cout << "底盘：" << endl;
    basePlate.print();
    cout << "AGX套件(" << agxKit.size() << "个)：" << endl;
    for (AGXKit x : agxKit) {
        x.print();
    }
    cout << "双目摄像头(" << camera.size() << "个)：" << endl;
    for (Camera x : camera) {
        x.print();
    }
    cout << "多线激光雷达(" << lidar.size() << "个)：" << endl;
    for (Lidar x : lidar) {
        x.print();
    }
    cout << "9轴陀螺仪(" << gyroscope.size() << "个)：" << endl;
    for (Gyroscope x : gyroscope) {
        x.print();
    }
    cout << "液晶显示屏(" << lcd.size() << "个)：" << endl;
    for (LCD x : lcd) {
        x.print();
    }
    cout << "电池模块(" << battery.size() << "个)：" << endl;
    for (Battery x : battery) {
        x.print();
    }
}

ostream &operator<<(ostream &out, const Car &Car) {
    out << "编号：" << Car.id << endl;
    out << "底盘：" << endl;
    out << Car.basePlate;
    out << "AGX套件(" << Car.agxKit.size() << "个)：\n";
    for (const auto &x : Car.agxKit) {
        out << x;
    }
    out << "双目摄像头(" << Car.camera.size() << "个)：\n";
    for (const auto &x : Car.camera) {
        out << x;
    }
    out << "多线激光雷达(" << Car.lidar.size() << "个)：\n";
    for (const auto &x : Car.lidar) {
        out << x;
    }
    out << "9轴陀螺仪(" << Car.gyroscope.size() << "个)：\n";
    for (const auto &x : Car.gyroscope) {
        out << x;
    }
    out << "液晶显示屏(" << Car.lcd.size() << "个)：\n";
    for (const auto &x : Car.lcd) {
        out << x;
    }
    out << "电池模块(" << Car.battery.size() << "个)：\n";
    for (const auto &x : Car.battery) {
        out << x;
    }
    return out;
}

istream &operator>>(istream &in, Car &Car) {
    in >> Car.id >> Car.basePlate;
    int agxKitSize;
    in >> agxKitSize;
    for (int i = 0; i < agxKitSize; i++) {
        AGXKit agxKit;
        in >> agxKit;
        Car.agxKit.push_back(agxKit);
    }
    int CameraSize;
    in >> CameraSize;
    for (int i = 0; i < CameraSize; i++) {
        Camera Camera;
        in >> Camera;
        Car.camera.push_back(Camera);
    }
    int LidarSize;
    in >> LidarSize;
    for (int i = 0; i < LidarSize; i++) {
        Lidar Lidar;
        in >> Lidar;
        Car.lidar.push_back(Lidar);
    }
    int GyroscopeSize;
    in >> GyroscopeSize;
    for (int i = 0; i < GyroscopeSize; i++) {
        Gyroscope Gyroscope;
        in >> Gyroscope;
        Car.gyroscope.push_back(Gyroscope);
    }
    int lcdSize;
    in >> lcdSize;
    for (int i = 0; i < lcdSize; i++) {
        LCD lcd;
        in >> lcd;
        Car.lcd.push_back(lcd);
    }
    int BatterySize;
    in >> BatterySize;
    for (int i = 0; i < BatterySize; i++) {
        Battery Battery;
        in >> Battery;
        Car.battery.push_back(Battery);
    }
    return in;
}

void Car::save() {
    ofstream out("Car" + to_string(time(nullptr)) + ".txt");
    out << "编号：" << this->id << endl;
    out << "底盘：" << endl;
    this->basePlate.save();
    out << "AGX套件(" << this->agxKit.size() << "个)：\n";
    for (AGXKit x : this->agxKit) {
        x.save();
    }
    out << "双目摄像头(" << this->camera.size() << "个)：\n";
    for (Camera x : this->camera) {
        x.save();
    }
    out << "多线激光雷达(" << this->lidar.size() << "个)：\n";
    for (Lidar x : this->lidar) {
        x.save();
    }
    out << "9轴陀螺仪(" << this->gyroscope.size() << "个)：\n";
    for (Gyroscope x : this->gyroscope) {
        x.save();
    }
    out << "液晶显示屏(" << this->lcd.size() << "个)：\n";
    for (LCD x : this->lcd) {
        x.save();
    }
    out << "电池模块(" << this->battery.size() << "个)：\n";
    for (Battery x : this->battery) {
        x.save();
    }
    out.close();
}

json Car::toJson() {
    json j;
    j["id"] = this->id;
    j["basePlate"] = this->basePlate.toJson();
    json agxKitJson;
    for (AGXKit x : this->agxKit) {
        agxKitJson.push_back(x.toJson());
    }
    j["agxKit"] = agxKitJson;
    json CameraJson;
    for (Camera x : this->camera) {
        CameraJson.push_back(x.toJson());
    }
    j["Camera"] = CameraJson;
    json LidarJson;
    for (Lidar x : this->lidar) {
        LidarJson.push_back(x.toJson());
    }
    j["Lidar"] = LidarJson;
    json GyroscopeJson;
    for (Gyroscope x : this->gyroscope) {
        GyroscopeJson.push_back(x.toJson());
    }
    j["Gyroscope"] = GyroscopeJson;
    json lcdJson;
    for (LCD x : this->lcd) {
        lcdJson.push_back(x.toJson());
    }
    j["lcd"] = lcdJson;
    json BatteryJson;
    for (Battery x : this->battery) {
        BatteryJson.push_back(x.toJson());
    }
    j["Battery"] = BatteryJson;
    return j;
}

void Car::fromJson(json j) {
    this->id = j["id"];
    this->basePlate.fromJson(j["basePlate"]);
    for (const auto &x : j["agxKit"]) {
        AGXKit agxKit;
        agxKit.fromJson(x);
        this->agxKit.push_back(agxKit);
    }
    for (const auto &x : j["Camera"]) {
        Camera Camera;
        Camera.fromJson(x);
        this->camera.push_back(Camera);
    }
    for (const auto &x : j["Lidar"]) {
        Lidar Lidar;
        Lidar.fromJson(x);
        this->lidar.push_back(Lidar);
    }
    for (const auto &x : j["Gyroscope"]) {
        Gyroscope Gyroscope;
        Gyroscope.fromJson(x);
        this->gyroscope.push_back(Gyroscope);
    }
    for (const auto &x : j["lcd"]) {
        LCD lcd;
        lcd.fromJson(x);
        this->lcd.push_back(lcd);
    }
    for (const auto &x : j["Battery"]) {
        Battery Battery;
        Battery.fromJson(x);
        this->battery.push_back(Battery);
    }
}