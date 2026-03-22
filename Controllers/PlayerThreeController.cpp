#include "PlayerThreeController.h"

void PlayerThreeController::Update(Tank* tank, float elapsedTime)
{
    if (Play::KeyDown(Play::KEY_U))
    {
        tank->Move(2.0f);
    }
    else if (Play::KeyDown(Play::KEY_J))
    {
        tank->Move(-2.0f);
    }

    if (Play::KeyDown(Play::KEY_H))
    {
        tank->Rotate(-0.05f);
    }
    else if (Play::KeyDown(Play::KEY_K))
    {
        tank->Rotate(0.05f);
    }
    
    bool bShouldShoot = Play::KeyDown(Play::KEY_Q);
    tank->Shoot(bShouldShoot, elapsedTime);
}
