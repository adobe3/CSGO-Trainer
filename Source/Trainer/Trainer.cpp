#include "Trainer.h"
#include "../Stdafx.h"

bool Trainer::Initialize() 
{
	/* Setup Triggerbot*/
	std::thread triggerbotThread(&Trainer::Triggerbot);
	triggerbotThread.detach();

	return true;
}