//
// Created by lauri on 2/12/2021.
//

#ifndef TALLER_INDIVIDUAL_HOUSE_H
#define TALLER_INDIVIDUAL_HOUSE_H
#include<string>
#include <ostream>

class House {
public:
    House(const std::string &id, const std::string &direccion, const std::string &area, short windows,
          const std::string &color);

private:
public:
    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getDireccion() const;

    void setDireccion(const std::string &direccion);

    const std::string &getArea() const;

    void setArea(const std::string &area);

    short getWindows() const;

    void setWindows(short windows);

    const std::string &getColor() const;

    void setColor(const std::string &color);

public:
    friend std::ostream &operator<<(std::ostream &os, const House &house);

private:
    std::string id;
    std::string direccion;
    std::string area;
    short windows;
public:
    House();

    virtual ~House();

private:
    std::string color;
};


#endif //TALLER_INDIVIDUAL_HOUSE_H
