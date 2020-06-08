#include "Location.h"

Location::Location(double latitude, double longitude, std::string type, std::string subtype, std::string name, std::string street)
: latitude(latitude), longitude(longitude), type(type), subtype(subtype), name(name), street(street)
{
}