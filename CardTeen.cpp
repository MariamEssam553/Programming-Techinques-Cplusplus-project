//check first time to add this card
//check on card malhosh lazma hena 
// already msh hay-apply 8yr mn el switch case


//ezay lma ygy y-excutes el add cardteen tani el owner yb2a hwa hwa??????
//lw he doesn/t have money
//how to make player own all cards having same number
//

#include "CardTeen.h"

CardTeen::CardTeen(const CellPosition& pos) :Card(pos)
{
	cardNumber = 10;
	Owner = NULL;
}
void CardTeen::ReadCardParameters(Grid* pGrid)
{
	//Card::ReadCardParameters(pGrid);
	pGrid->PrintErrorMessage("Enter Card price:");
	double PRICE = (pGrid->GetInput())->GetInteger((pGrid->GetOutput()));
	price = (PRICE > 0) ? PRICE : 100;

	pGrid->PrintErrorMessage("Enter Card fees:");
	double FEES = (pGrid->GetInput())->GetInteger((pGrid->GetOutput()));
	fees = (FEES > 0) ? FEES : 100;

	(pGrid->GetOutput())->ClearStatusBar();
}

void CardTeen::Apply(Grid* pGrid, Player* pPlayer)
{
	//Card::Apply(pGrid, pPlayer);

	//bool CheckCard;
	//CheckCard = pGrid->CheckGameObjectLoopOnGrid(this); //make sure no similar card
	//false means no similar card
	//CheckCard == false &&
	if (Owner == NULL && pPlayer->GetWallet() >= price)
	{
		pGrid->PrintErrorMessage("you have reached a station. Do you want to buy it? (y/n) ");
		string ans;
		ans = (pGrid->GetInput())->GetString(pGrid->GetOutput());
		if (ans == "y" || ans == "Y")
		{
			//bool CheckGameObj = pGrid->AddObjectToCell(this);
			//if (CheckGameObj == true)
			//{

		 if ( pPlayer->GetWallet() < price)
		{
			 pGrid->PrintErrorMessage("Sorry you don't have enough money");
			 return;
		}
			Owner = pPlayer;
			Owner->SetWallet(Owner->GetWallet() - price);

			//Owner->SetCardArray(this);
			return;
			//}
			//else
			/*{
				pGrid->PrintErrorMessage("Invalid. A game object already exists here.Click to discard. ");
				pIn->GetPointClicked(x, y);
				return;
			}*/
		}
		else
			return;
	}
	else
	{
		//bool CheckStation;
		//CheckStation = pGrid->CheckOnStations(this);
		//if (Owner == NULL) //false means not bought
		//{
		//	//ReadCardParameters(pGrid);
		//	Owner = pPlayer;
		//	Owner->SetWallet(Owner->GetWallet() - price);
		//	//Owner->SetCardArray(this);
		//	return;
		//}
		//else
		
		pGrid->PrintErrorMessage("you have reached bought a station. Click to continue. ");
		if (pPlayer->GetWallet() < fees)
		{
			pPlayer->setjustRolledDiceNum(0);
			pPlayer->Move(pGrid, pPlayer->getjustRolledDiceNum());
		}
		else 
			pPlayer->SetWallet(pPlayer->GetWallet() - fees);
		Owner->SetWallet(fees);
		return;
	}
}
CardTeen::~CardTeen()
{

}