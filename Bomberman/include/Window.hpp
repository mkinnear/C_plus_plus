#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "Sound.hpp"
#include "Graphics.hpp"
#include "WindowKeyEvents.hpp"


class Window
{
public:
    Window();
    ~Window();

    void initiateSystemsFullscreen();
    void initiateSystemsWindowed();
    void terminateSystems();
    void setGraphics(Graphics g);
    bool initializeGlew();
    void changeWindowSize();
    void switchToLarge(GLFWwindow* win ,int wantedHeight, int wantedWidth);
    void switchToMedium(GLFWwindow* win ,int wantedHeight, int wantedWidth);
    void switchToWindowed(GLFWwindow* win);
    void switchToFull(GLFWwindow* win);

    Sound* getSound();
    GLFWwindow* getWindow();
    WindowKeyEvents* getEvents();

private:
    int _width;
    int _height;
    int latestHeight;
    int latestWidth;
    Sound *_sound;
    Graphics *graphics;
    GLFWwindow* _window;
    GLFWwindow* _fullWindow;
    WindowKeyEvents *_keyEvents;
};

#endif
