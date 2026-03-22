#include "PlayerTwoController.h"

void PlayerTwoController::Update(Tank* tank, float elapsedTime)
{
    if (Play::KeyDown(Play::KEY_W))
    {
        tank->Move(2.0f);
    }
    else if (Play::KeyDown(Play::KEY_S))
    {
        tank->Move(-2.0f);
    }

    if (Play::KeyDown(Play::KEY_A))
    {
        tank->Rotate(-0.05f);
    }
    else if (Play::KeyDown(Play::KEY_D))
    {
        tank->Rotate(0.05f);
    }
    
    bool bShouldShoot = Play::KeyDown(Play::KEY_SPACE);
    tank->Shoot(bShouldShoot, elapsedTime);
}
