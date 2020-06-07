#include <cmath>

#include "Rect.h"
#include "Location.h"

Rect::Rect(Location leftDown, Location leftUp, Location rightDown, Location rightUp) : leftUp(leftUp),
                                                                                       rightDown(rightDown),
                                                                                       rightUp(rightUp),
                                                                                       leftDown(leftDown) {

}

void Rect::restrucher(Location location) {
    double up = min(this->leftUp.longitude, location.longitude);
    double down = max(this->leftDown.longitude, location.longitude);
    double left = min(this->leftDown.latitude, location.latitude);
    double right = max(this->rightDown.latitude, location.latitude);
    this->leftUp.longitude = up;
    this->rightUp.longitude = up;
    this->leftDown.longitude = down;
    this->rightDown.longitude = down;
    this->leftDown.latitude = left;
    this->leftUp.latitude = left;
    this->rightDown.latitude = right;
    this->rightUp.latitude = right;
}

bool Rect::checkSituation(Location location) {
    return this->leftUp.latitude >= location.latitude && this->leftUp.longitude >= location.longitude
           && this->leftDown.longitude <= location.longitude && this->rightUp.latitude <= location.latitude;
}

void Rect::addLocation(Location location) {
    if (!this->checkSituation(location)) {
        this->restrucher(location);
    }
    locations.push_back(location);
}
