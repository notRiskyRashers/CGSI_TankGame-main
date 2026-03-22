#include "PlayerOneController.h"

void PlayerOneController::Update(Tank* tank, float elapsedTime)
{
    if (Play::KeyDown(Play::KEY_UP))
    {
        tank->Move(2.0f);
    }
    else if (Play::KeyDown(Play::KEY_DOWN))
    {
        tank->Move(-2.0f);
    }

    if (Play::KeyDown(Play::KEY_LEFT))
    {
        tank->Rotate(-0.05f);
    }
    else if (Play::KeyDown(Play::KEY_RIGHT))
    {
        tank->Rotate(0.05f);
    }

    bool bShouldShoot = Play::KeyDown(Play::KEY_ENTER);
    tank->Shoot(bShouldShoot, elapsedTime);
}
