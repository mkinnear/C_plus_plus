#ifndef SETTINGS_HPP
# define SETTINGS_HPP
#include <stdlib.h>
#include <stdio.h>
# include <iostream>

#include "Window.hpp"
#include "shader.hpp"

struct settingsInput
{
    enum GameCommands{
        Sound,
        Screen,
        Volume,
        Keys,
        Return,

    };
};

class Settings
{
    public:
		Settings();
        Settings(GLFWwindow *window, Window &, Graphics *g);
        ~Settings();

        Settings(Settings& obj);
        Settings& operator=(Settings& obj);
        void Music();
        void Screen(/*int input*/);
        void Return();
        void modSound();
        void modVolume();
        void modDisplay();
        int getSoundVal();
        bool getDispChange();
        void setWindow(GLFWwindow *, Window &, Graphics *);
        Window getGameWindow();
        void toggleCommands(/*GLFWwindow* window, */int key);
        void executeCommand(int command);
        void setGraphics(Graphics *g);
        void initSettingsImage();
        void LoadSettingsImage();
        void SettingsCleanup();
        int getInput();

    private:
        int _volumeLevel;
        int _input;
        bool _dispChange;
        int _sound_val;
        GLFWwindow* _window;
        Window _gameWindow;
        Graphics *graphics;
        GLuint menuVAO, menuTexture, menuEBO, menuVBO, programID;
};

#endif
