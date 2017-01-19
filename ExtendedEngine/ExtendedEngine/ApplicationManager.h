
#pragma once

#include <string>


namespace extspehs
{
	class State;
	class ApplicationManager
	{
	public:
		static void init(State* _initialState);
		static void init(const std::string& _windowName, State* _initialState);
		static void uninit();

		static void setState(State* _newState);

	private:
		static void run();
	};

}
