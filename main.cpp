#include <iostream>
#include <fstream>
#include <vector>

#include "Student.h"
#include "car_parts/BasePlate.h"
#include "car_parts/AGXKit.h"
#include "car_parts/Camera.h"
#include "car_parts/Lidar.h"
#include "car_parts/Gyroscope.h"
#include "Car.h"
#include "relational.h"

using namespace std;
using namespace nlohmann;

int main() {
    int choice;
    cout << "1.保存学生信息和松灵小车信息" << endl;
    cout << "2.读取学生信息和松灵小车信息" << endl;
    cout << "0.退出" << endl;
    cout << "请选择：";
    cin >> choice;
    while (choice < 1 || choice > 3) {
        cout << "输入错误，请重新输入：";
        cin >> choice;
    }
    while (choice) {
        if (choice == 1) { //造零件
            Tire tire("公路轮、麦克纳姆轮", 175);
            vector<Tire> tires;
            for (int i = 0; i < 4; i++) {
                tires.push_back(tire);
            }
            BasePlate basePlate("dp12345678", "SCOUT MINI", 451, 490, 115, 0, "四轮四驱", 10, tires);
            AGXKit agxKit("AGX Xavier", 32, 512, 64, 32, 32);
            Camera camera("RealSense D435i", "D430", "1920 1080", 30, 8758, 90);
            Lidar lidar("RS-Helios-16p", 16, 100, 8);
            Gyroscope gyroscope("CH110", "NXP");
            LCD lcd("11.6", "super");
            Battery battery("24V/15Ah", "24V", 2);

            //造零件集合
            vector<AGXKit> agxKits;
            agxKits.push_back(agxKit);
            vector<Camera> Cameras;
            Cameras.push_back(camera);
            vector<Lidar> Lidars;
            Lidars.push_back(lidar);
            vector<Gyroscope> Gyroscopes;
            Gyroscopes.push_back(gyroscope);
            vector<LCD> lcds;
            lcds.push_back(lcd);
            vector<Battery> Batterys;
            Batterys.push_back(battery);

            //造10台松灵小车
            vector<Car> Cars;
            for (int i = 1; i <= 10; i++) {
                string id = "cqusn" + to_string(i).insert(0, 16 - to_string(i).length(), '0');
                basePlate.setID("dp" + to_string(i).insert(0, 8 - to_string(i).length(), '0'));
                Car Car(id, basePlate, agxKits, Cameras, Lidars, Gyroscopes,
                                lcds,
                                Batterys);
                Cars.push_back(Car);
            }
            vector<Student> students;
            for (int i = 1; i <= 10; ++i) {
                string id = "E202" + to_string(i).insert(0, 4 - to_string(i).length(), '0');
                string name = "学生" + to_string(i);
                students.emplace_back(id, name);
            }

            //关联学生和松灵小车
            vector<relational> relationals;
            for (int i = 0; i < 10; i++) {
                relational relational(&students[i], &Cars[i]);
                relationals.push_back(relational);
            }

            //保存为json
            json j;
            for (auto x: relationals) {
                j.push_back(x.toJson());
            }
            ofstream out("out.json");
            out << j;
            out.close();
            cout << "保存成功" << endl;
        }
        if (choice == 2) {
            //in
            try {
                ifstream in("out.json");
                json j;
                in >> j;
                vector<relational> relationals;
                for (auto x: j) {
                    relational relational(new Student(), new Car());
                    relational.fromJson(x);
                    relationals.push_back(relational);
                }
                //一次显示1辆小车信息，按n键显示下一辆小车信息，按p显示上一辆小车信息。请注意：显示第1台显示按p无效，显示第10台小车，按n无效。
                int index = 0;
                char c;
                relationals[index].show();
                cout << "按n键显示下一辆小车信息，按p显示上一辆小车信息" << endl;
                cin >> c;
                while (c == 'n' || c == 'p') {
                    if (c == 'n') {
                        if (index == 9) {
                            cout << "已经是最后一辆小车了,按0返回" << endl;
                        }
                        if (index < 9) {
                            index++;
                            relationals[index].show();
                        }
                    } else if (c == 'p') {
                        if (index == 0) {
                            cout << "已经是第一辆小车了,按0返回" << endl;
                        }
                        if (index > 0) {
                            index--;
                            relationals[index].show();
                        }
                    }
                    cin >> c;
                }
            }
            catch (exception &e) {
                cout << "文件读取错误" << endl;
                cout << e.what() << endl;
                exit(1);
            }
        }
        cout << "1.保存学生信息和松灵小车信息" << endl;
        cout << "2.读取学生信息和松灵小车信息" << endl;
        cout << "0.退出" << endl;
        cout << "请选择：";
        cin >> choice;
    }
}