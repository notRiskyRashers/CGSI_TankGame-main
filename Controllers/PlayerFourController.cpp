#include "PlayerFourController.h"

void PlayerFourController::Update(Tank* tank, float elapsedTime)
{
    if (Play::KeyDown(Play::KEY_G))
    {
        tank->Move(2.0f);
    }
    else if (Play::KeyDown(Play::KEY_V))
    {
        tank->Move(-2.0f);
    }
    
    if (Play::KeyDown(Play::KEY_C))
    {
        tank->Rotate(-0.05f);
    }
    else if (Play::KeyDown(Play::KEY_B))
    {
        tank->Rotate(0.05f);
    }
    
    bool bShouldShoot = Play::KeyDown(Play::KEY_M);
    tank->Shoot(bShouldShoot, elapsedTime);
}
