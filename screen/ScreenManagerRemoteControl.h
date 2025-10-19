#ifndef SCREENMANAGERREMOTECONTROL_H
#define SCREENMANAGERREMOTECONTROL_H

#include <string>

class ScreenManagerRemoteControl {
public:
    virtual void switchScreen(std::string screenToSwitchTo) = 0;
    virtual void playLevel(std::string level) = 0;
};

#endif // SCREENMANAGERREMOTECONTROL_H
