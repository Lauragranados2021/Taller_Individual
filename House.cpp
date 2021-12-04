//
// Created by lauri on 2/12/2021.
//

#include "House.h"

House::House() {}

House::House(const std::string &id, const std::string &direccion, const std::string &area, short windows,
             const std::string &color) : id(id), direccion(direccion), area(area), windows(windows), color(color) {}

 std::ostream &operator<<(std::ostream &os, const House &house) {
    os << "id: " << house.id << " direccion: " << house.direccion << " area: " << house.area << " windows: "
       << house.windows << " color: " << house.color;
    return os;
}

const std::string &House::getId() const {
    return id;
}

void House::setId(const std::string &id) {
    House::id = id;
}

const std::string &House::getDireccion() const {
    return direccion;
}

void House::setDireccion(const std::string &direccion) {
    House::direccion = direccion;
}

const std::string &House::getArea() const {
    return area;
}

void House::setArea(const std::string &area) {
    House::area = area;
}

short House::getWindows() const {
    return windows;
}

void House::setWindows(short windows) {
    House::windows = windows;
}

const std::string &House::getColor() const {
    return color;
}

void House::setColor(const std::string &color) {
    House::color = color;
}

House::~House() {

}
