#ifndef MAINMENU_HPP
# define MAINMENU_HPP

#include <stdlib.h>
#include <stdio.h>
# include <iostream>

#include "Window.hpp"
#include "shader.hpp"

struct Input
{
    enum GameCommands{
        Start,
        Continue,
        Settings,
        Exit,
        ToggleSound,
        ToggleScreen,
    };
};

class MainMenu
{
    public:
		MainMenu();
        MainMenu(GLFWwindow *window, Window &, Graphics *g);
        ~MainMenu();

        MainMenu(MainMenu & obj);
        MainMenu& operator=(MainMenu& obj);

        void gameStart();
        void gameSettings(int input);
        void gameContinue();
        void modSound();
        int getSoundVal();
        void gameExit();
        void setWindow(GLFWwindow *, Window &, Graphics *);
        Window getGameWindow();
        void toggleCommands(int input);
        void executeCommand(int command);
        void setGraphics(Graphics *g);
        void gameHighScore();
        void initMenuImage();
        void LoadMainMenuImage();
        void menuCleanup();

        int getInput();

    private:
        int _input;
        GLFWwindow* _window;
        Window _gameWindow;
        Graphics *graphics;
        int _sound_val;
        GLuint menuVAO, menuTexture, menuEBO, menuVBO, programID;
        bool isContinue;
        std::vector<GLfloat> _w;
};

#endif
