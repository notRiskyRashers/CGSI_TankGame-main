#pragma once

#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "CoreTank/TankController.h"
#include "CoreTank/Tank.h"
#include "Play.h"


class AIController : public ITankController
{
    
   
public:
    void Update(Tank* tank, float elapsedTime) override;
    
    enum TankState
    {
        IDLE,
        SEEKPLAYER,
        SHOOT,
    };
protected:
   
    
    void idle();
    void StoreEnemyTanks(Tank* tank);
    void testfunc();
    void testfuncRotateTillFacingDown(Tank* tank);


public:
    
};

#endif
