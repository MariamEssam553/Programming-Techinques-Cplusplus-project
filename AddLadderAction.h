#pragma once
#include "Action.h"

class AddLadderAction : public Action
{

	CellPosition startPos; 
	CellPosition endPos;  
	int flag;
public:

	AddLadderAction(ApplicationManager *pApp); 
	virtual void ReadActionParameters(); 
	virtual void Execute(); 
	virtual ~AddLadderAction(); 
};

