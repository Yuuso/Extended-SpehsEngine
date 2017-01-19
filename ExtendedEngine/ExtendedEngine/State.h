
#pragma once


namespace spehs{ class Camera2D; class BatchManager; }

namespace extspehs
{
	class State
	{
	public:
		State(){}
		virtual ~State(){}

		virtual void init(){}
		virtual bool update() = 0;
		virtual void render(){}
	};

	class VisualState : public State
	{
	public:
		VisualState();
		virtual ~VisualState();

		virtual void init();
		virtual bool update() = 0;
		virtual void render();

	protected:
		spehs::Camera2D* camera;
		spehs::BatchManager* batchManager;
	};
}

