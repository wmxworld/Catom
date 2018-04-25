#include <iostream>
#include <string>
#include <cmath>
#include "atom.hpp"

using namespace std;


/*Catom::Catom(const Catom& another_atom)
{
    // name_ = another_atom.name_; <- name_ field is private.
    name_       = another_atom.name();
    coordinate_ = another_atom.coordinate();
    if(another_atom.has_velocity())
    {
        velocity_    = another_atom.velocity();
        has_velocity_   = true;
    }
    if(another_atom.has_mass())
    {
        mass_        = another_atom.mass();
        has_mass_       = true;
    }
}*/

Catom::Catom(std::string name, double coordinate_x, double coordinate_y, \
double coordinate_z)
{
    name_       = name;
    coordinate_.x = coordinate_x;
    coordinate_.y = coordinate_y;
    coordinate_.z = coordinate_z;
    has_velocity_   = false;
    has_mass_       = false;
}

Catom::Catom(std::string name, double mass, double coordinate_x, \
double coordinate_y, double coordinate_z)
{
    name_       = name;
    coordinate_.x = coordinate_x;
    coordinate_.y = coordinate_y;
    coordinate_.z = coordinate_z;
    mass_       = mass;
    has_velocity_   = false;
    has_mass_       = true;
}

Catom::Catom(std::string name, double mass, double coordinate_x, \
double coordinate_y, double coordinate_z, double velocity_x, double velocity_y, double velocity_z)
{
    name_       = name;
    coordinate_.x = coordinate_x;
    coordinate_.y = coordinate_y;
    coordinate_.z = coordinate_z;
    mass_       = mass;
    velocity_.x   = velocity_x;
    velocity_.y   = velocity_y;
    velocity_.z   = velocity_z;
    has_velocity_   = true;
    has_mass_       = true;
}

Catom::~Catom()
{
}

void Catom::clear()
{
    name_ = "";
    has_velocity_   = false;
    has_mass_       = false;
}

void Catom::setName(std::string name)
{
    name_ = name;
}

void Catom::setCoordinate(double x, double y, double z)
{
    coordinate_.x = x;
    coordinate_.y = y;
    coordinate_.z = z;
}

void Catom::setVelocity(double x, double y, double z)
{
    velocity_.x = x;
    velocity_.y = y;
    velocity_.z = z;
    has_velocity_ = true;
}

void Catom::setMass(double mass)
{
    mass_ = mass;
    has_mass_ = true;
}

std::string Catom::name()
{
    return name_;
}

s_coordinate Catom::coordinate()
{
    return coordinate_;
}

s_coordinate Catom::velocity()
{
    if (!has_velocity())
    {
        cerr << "Error message : velocity not set yet" << endl;
        exit(1);
    }
    return velocity_;
}

double Catom::mass()
{
    if(!has_mass())
    {
        cerr << "Error message : mass not set yet" << endl;
        exit(1);
    }
    return mass_;
}

bool Catom::has_mass()
{
    return has_mass_;
}

bool Catom::has_velocity()
{
    return has_velocity_;
}

void Catom::move(double x, double y, double z)
{
    coordinate_.x += x; 
    coordinate_.y += y; 
    coordinate_.z += z; 
}

void Catom::evolve(double ax, double ay, double az, double dt)
{
    if(!has_velocity())
    {
        cerr << "Error message : velocity not set yet" << endl;
        exit(1);
    }
    coordinate_.x += velocity_.x * dt;
    coordinate_.y += velocity_.y * dt;
    coordinate_.z += velocity_.z * dt;

    velocity_.x    += ax * dt;
    velocity_.y    += ay * dt;
    velocity_.z    += az * dt;
}

double Catom::distance(Catom another_atom)
{
    s_coordinate coor_another = another_atom.coordinate();
    return sqrt( pow( coordinate_.x - coor_another.x, 2  )\
            +  pow( coordinate_.y - coor_another.y, 2  )\
            +  pow( coordinate_.z - coor_another.z, 2  ));
}

