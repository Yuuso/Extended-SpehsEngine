
#include "ApplicationManager.h"

#include "State.h"

#include <SpehsEngine/SpehsEngine.h>
#include <SpehsEngine/Window.h>
#include <SpehsEngine/InputManager.h>
#include <SpehsEngine/Time.h>

#include <thread>
#include <chrono>
#include <vector>


namespace appVar
{
	bool initWithSpehs = false;

	extspehs::State* currentState = nullptr;
	std::vector<extspehs::State*> stateQueue; //timers
}

namespace extspehs
{
	void ApplicationManager::init(State* _initialState)
	{
		appVar::currentState = _initialState;
		ApplicationManager::run();
	}
	void ApplicationManager::init(const std::string& _windowName, State* _initialState)
	{
		appVar::initWithSpehs = true;
		spehs::initialize(_windowName);
		spehs::getMainWindow()->clearColor(0, 0, 0, 0);
		ApplicationManager::init(_initialState);
	}
	void ApplicationManager::uninit()
	{
		if (appVar::initWithSpehs)
		{
			spehs::uninitialize();
		}
	}
	void ApplicationManager::run()
	{
		appVar::currentState->init();
		while (true)
		{
			if (appVar::initWithSpehs)
			{
				inputManager->update();
				if (inputManager->isQuitRequested())
					break;
			}
			spehs::time::update();

			if (!appVar::currentState->update())
				break;

			if (appVar::stateQueue.size())
			{
				delete appVar::currentState;
				appVar::currentState = appVar::stateQueue[0];
				appVar::stateQueue.erase(appVar::stateQueue.begin());
				appVar::currentState->init();
			}
			else
			{
				if (appVar::initWithSpehs)
				{
					spehs::getMainWindow()->renderBegin();
					appVar::currentState->render();
					spehs::getMainWindow()->renderEnd();
				}
			}
		}

		//clean up todo
	}


	void ApplicationManager::setState(State* _newState)
	{
		appVar::stateQueue.push_back(_newState);
	}
}