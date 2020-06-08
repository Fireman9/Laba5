#include "Rect.h"

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

double Rect::distance(double& A1, double& B1, double& A2, double& B2) {
    double result, a1, b1, a2, b2, delta1, delta2;
    double radius = 6367444.65;
    a1 = (A1 * 2 * acos(0.0)) / 180;
    b1 = (B1 * 2 * acos(0.0)) / 180;
    a2 = (A2 * 2 * acos(0.0)) / 180;
    b2 = (B2 * 2 * acos(0.0)) / 180;
    delta1 = a2 - a1;
    delta2 = b2 - b1;
    double squereRoot = sqrt(pow(sin(delta1 / 2), 2) + cos(a2) * cos(a1) * pow(sin(delta2 / 2), 2));
    result = 2 * asin(squereRoot) * radius;
    return result;
}

void Rect::devideRoot() {
    if (this->locations.size() > 5) {
        double width = distance(this->leftUp.latitude, this->leftUp.longitude, this->rightUp.latitude, this->rightUp.longitude);
        double height = distance(this->leftUp.latitude, this->leftUp.longitude, this->leftDown.latitude, this->leftDown.longitude);
        if (width > height) {
            double halfWidth = this->leftUp.latitude + abs(this->leftUp.latitude - this->rightUp.latitude) / 2;
            Location  up(halfWidth, this->leftUp.longitude, this->leftUp.type, this->leftUp.subtype, this->leftUp.name, this->leftUp.street);
            Location down(halfWidth, this->leftDown.longitude, this->leftUp.type, this->leftUp.subtype, this->leftUp.name, this->leftUp.street);
            Rect rectLeft(this->leftDown, this->leftUp, down, up);
            Rect rectRight(down, up, this->rightDown, this->rightUp);
            while (this->locations.size() > 0) {

                if (rectLeft.checkSituation(this->locations[this->locations.size() - 1]))
                    rectLeft.addLocation(this->locations[this->locations.size() - 1]);
                else
                    rectRight.addLocation(this->locations[this->locations.size() - 1]);
                this->locations.pop_back();
            }
            this->children.push_back(rectLeft);
            this->children.push_back(rectRight);
            rectLeft.devideRoot();
            rectRight.devideRoot();
        }
        else {
            double halfHight = this->leftUp.longitude + abs(this->leftUp.longitude - this->leftDown.longitude) / 2;
            Location  left(this->leftUp.latitude, halfHight, this->leftUp.type, this->leftUp.subtype, this->leftUp.name, this->leftUp.street);
            Location right(this->rightUp.latitude, halfHight, this->leftUp.type, this->leftUp.subtype, this->leftUp.name, this->leftUp.street);
            Rect rectUp(left, this->leftUp, right, this->rightUp);
            Rect rectDown(this->leftDown, left, this->rightDown, right);
            while (this->locations.size() > 0) {
                if (rectUp.checkSituation(this->locations[this->locations.size() - 1]))
                    rectUp.addLocation(this->locations[this->locations.size() - 1]);
                else
                    rectDown.addLocation(this->locations[this->locations.size() - 1]);
                this->locations.pop_back();
            }
            this->children.push_back(rectUp);
            this->children.push_back(rectDown);
            this->children[0].devideRoot();
            this->children[1].devideRoot();
        }
    }
}

bool Rect::checkSituation(Location location) {
    return location.longitude >= this->leftUp.longitude  && location.longitude <= this->leftDown.longitude
        && location.latitude >= this->leftUp.latitude && location.latitude <= this->rightUp.latitude;
}

void Rect::addLocation(Location location) {
    if (!this->checkSituation(location)) {
        this->restrucher(location);
    }
    locations.push_back(location);
}