#include "AIController.h"
#include "CoreTank/Tank.h"
#include "Play.h"


std::vector<Tank*> EnemyTanks;

void AIController::StoreEnemyTanks(Tank* tank)
{
    int MyID = tank->GetID();
    for (size_t i = 0; i < Tank::GetAllTanks().size(); ++i)
    {
        Tank* TankPlaceholder = Tank::GetAllTanks()[i];
        if (TankPlaceholder->GetID() == MyID)
        {
            
        }
        else
        {
            EnemyTanks.push_back(TankPlaceholder);
        }
        
    }
}

void AIController::testfunc()
{
    for (int i = 0; i < EnemyTanks.size(); i++)
    {
       Play::Vector2D CurrentEnemyPosition = EnemyTanks[i]->GetPosition();
        std::cout << std::endl << CurrentEnemyPosition.x << std::endl << CurrentEnemyPosition.y << std::endl;
    }
}

void  AIController::testfuncRotateTillFacingDown(Tank* tank)
{
    //tank->GetRotation();
    std::cout << tank->GetRotation() << std::endl;
    if (tank->GetRotation() >= 6.28)
    {
        tank->ResetRotation();
    }
}



void AIController::Update(Tank* tank, float elapsedTime)
{
    StoreEnemyTanks(tank);
    testfuncRotateTillFacingDown(tank);
    switch (TankState tank_state = IDLE)
    {
    case IDLE:
        tank->Rotate(-0.05f);
       
        break;
    case SEEKPLAYER:
        break;
    case SHOOT:
        break;
    }
}
