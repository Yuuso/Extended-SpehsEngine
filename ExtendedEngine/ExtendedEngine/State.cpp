
#include "State.h"

#include <SpehsEngine/Camera2D.h>
#include <SpehsEngine/BatchManager.h>


namespace extspehs
{
	VisualState::VisualState()
	{
	}
	void VisualState::init()
	{
		camera = new spehs::Camera2D;
		batchManager = new spehs::BatchManager(camera);
		spehs::setActiveBatchManager(batchManager);
	}
	VisualState::~VisualState()
	{
		if (batchManager)
			delete batchManager;
		if (camera)
			delete camera;
	}

	void VisualState::render()
	{
		batchManager->render();
	}
}
