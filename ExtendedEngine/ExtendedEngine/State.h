
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
		~VisualState() override;

		void init() override;
		bool update() override = 0;
		void render() override;

		const spehs::Camera2D& getCamera() const { return *camera; }

	protected:
		spehs::Camera2D* camera;
		spehs::BatchManager* batchManager;
	};
}

