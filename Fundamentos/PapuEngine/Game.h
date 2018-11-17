#pragma once
#include "Window.h"
#include "InputManager.h"
#include <memory>
class ScreenList;
class IGameScreen;


class Game
{
public:
	Game();
	virtual ~Game();
	void run();
	void exit();
	virtual void onInit() = 0;
	virtual void addScreen() = 0;
	virtual void onExit() = 0;
	void onSDLEvent(SDL_Event& event);
protected:
	bool init();
	void update();
	void draw();
	bool initSystems();
	std::unique_ptr<ScreenList> 
			_screenList = nullptr;
	bool _isRunning = false;
	Window _window;
	InputManager _inputManager;
	IGameScreen* _currentScreen = nullptr;
};

