#include <iostream>
#include <string>

struct s_coordinate
{
    double x;
    double y;
    double z;
};

class Catom
{
    private:
        std::string  name_;
        double       mass_;
        s_coordinate coordinate_;
        s_coordinate velocity_;
        bool         has_coordinate_;
        bool         has_velocity_;
        bool         has_mass_;

    public:
        atom();
        atom(Catom another_atom);
        atom(string name, s_coordinate coordinate);
        atom(string name, double mass, s_coordinate coordinate, s_coordinate velocity);
        atom(string name, double mass, s_coordiante coordinate);
        ~atom();

        void clear();
        void setName(string name);
        void setCoordiante(double x, double y, double z);
        void setVelocity(double x, double y, double z);
        void setMass(double mass);

        string       name();
        s_coordinate coordinate();
        s_coordiante velocity();
        double       mass();
        bool         has_coordinate();
        bool         has_velocity();
        bool         has_mass();

        void move(double x, double y, double z);
        void evolve(double ax, double ay, double az, double dt);

        double distance(Catom another_atom);
}

