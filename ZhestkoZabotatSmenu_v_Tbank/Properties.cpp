//
// Created by nikit on 20.03.2026.
//

#include "Properties.h"

Properties::Properties() {
    this->isFavourite = false;
    this->isRead = false;
}

Properties::Properties(bool isFavourite, bool isRead) {
    this->isFavourite = isFavourite;
    this->isRead = isRead;
}

bool Properties::getIsFavourite() {
    return this->isFavourite;
}

bool Properties::getIsRead() {
    return this->isRead;
}

void Properties::changeFavourite() {
    this->isFavourite = !this->isFavourite;
}

void Properties::changeReadStatus() {
    this->isRead = !this->isRead;
}


