//
// Created by nikit on 20.03.2026.
//

#ifndef ZHESTKOZABOTATSMENU_V_TBANK_PROPERTIES_H
#define ZHESTKOZABOTATSMENU_V_TBANK_PROPERTIES_H


class Properties {
private:
    bool isFavourite;
    bool isRead;
public:
    Properties();
    Properties(bool isFavourite, bool isRead);
    bool getIsFavourite();
    bool getIsRead();
    void changeFavourite();
    void changeReadStatus();
};


#endif //ZHESTKOZABOTATSMENU_V_TBANK_PROPERTIES_H
