#include "atom.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Catom::atom()
{
    has_coordinate_ = false;
    has_velocity_   = false;
    has_mass_       = false;
}

Catom::atom(Catom another_atom)
{
    // this.name_ = another_atom.name_; <- name_ field is private.
    this.name_       = another_atom.name();
    if(another_atom.has_coordinate())
    {
        this.coordinate_ = another_atom.coordinate();
    }
    if(another_atom.has_velocity())
    {
        this.velocity    = another_atom.velocity();
    }
    if(another_atom.has_mass())
    {
        this.mass        = another_atom.mass();
    }
}

Catom::atom(string name, s_coordinate coordinate)
{
    this.name_       = name;
    this.coordinate_ = coordinate;
    has_coordinate_ = true;
    has_velocity_   = false;
    has_mass_       = false;
}

//////TODO: other constructers
//

Catom::~atom()
{
}

void Catom::clear()
{
    name = "";
    has_coordinate_ = false;
    has_velocity_   = false;
    has_mass_       = false;
}

void Catom::setName(string name)
{
    this.name_ = name;
}

// TODO: other 'set' functions

void Catom::move(double x, double y, double z)
{
    this.coordinate_.x += x; 
    this.coordinate_.y += y; 
    this.coordinate_.z += z; 
}

void Catom::evolve(double ax, double ay, double az,   double dt)
{
    this.coordinate_.x += this.velocity_.x * dt;
    this.coordinate_.y += this.velocity_.y * dt;
    this.coordinate_.z += this.velocity_.z * dt;

    this.velocity_x    += ax * dt;
    this.velocity_y    += ay * dt;
    this.velocity_z    += az * dt;
}

void Catom::distance(Catom another_atom)
{
    s_coordinate coor_another = another_atom.coordinate();
    return sqrt( pow( this.coordinate.x - coor_another.coordinate.x, 2  )\
            +  pow( this.coordinate.y - coor_another.coordinate.y, 2  )\
            +  pow( this.coordinate.z - coor_another.coordinate.z, 2  ));
}

