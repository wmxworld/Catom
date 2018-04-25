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
        bool         has_velocity_;
        bool         has_mass_;

    public:
        // Catom(const Catom& another_atom);
        Catom(std::string name, double coordinate_x, double coordinate_y, double coordinate_z);
        Catom(std::string name, double mass, double coordinate_x, double coordinate_y, double coordinate_z, double velocity_x, double velocity_y, double velocity_z);
        Catom(std::string name, double mass, double coordinate_x, double coordinate_y, double coordinate_z);
        ~Catom();

        void clear();
        void setName(std::string name);
        void setCoordinate(double x, double y, double z);
        void setVelocity(double x, double y, double z);
        void setMass(double mass);

        std::string       name();
        s_coordinate coordinate();
        s_coordinate velocity();
        double       mass();
        bool         has_coordinate();
        bool         has_velocity();
        bool         has_mass();

        void move(double x, double y, double z);
        void evolve(double ax, double ay, double az, double dt);

        double distance(Catom another_atom);
};

