#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER

#include "CoreBullet/Bullet.h"
#include "Play.h"
#include "Globals.h"
#include "Controllers/AIController.h"
#include "Controllers/PlayerFourController.h"
#include "Controllers/PlayerOneController.h"
#include "Controllers/PlayerThreeController.h"
#include "Controllers/PlayerTwoController.h"
#include "Controllers/AIController.h"
#include "CoreTank/TankController.h"
#include "Obstacles/Structures.h"

//std::vector<Tank> Tanks;
std::vector<std::unique_ptr<ITankController>> Controllers;

// Tank spawn positions (1 - 4)
std::vector<Play::Vector2D> SpawnPositions = {
    {375, 100},
    {895, 625},
    {895, 100},
    {375, 625}
};

// ************************************************
// Set Number of Tanks in Game
// ************************************************
constexpr int NUM_PLAYERS = 2;
constexpr int NUM_AI_TANKS = 1;
constexpr bool BOB_AI = false;
// ************************************************
// ************************************************

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	Play::CentreAllSpriteOrigins();
    Play::LoadBackground("Data/Backgrounds/TankBackground.png");

    // Initialize structures
    InitStructures();
	
    // Create Tanks
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        Tank::CreateTank(SpawnPositions[i], i);
    }

    // Set Tank Sprites
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        std::string TankImageName   = "Tank"   + std::to_string(i + 1);
        std::string BulletImageName = "Bullet" + std::to_string(i + 1);

        Play::Graphics::LoadSpriteSheet("Data/Sprites/", TankImageName.c_str());
        Play::Graphics::LoadSpriteSheet("Data/Sprites/", BulletImageName.c_str());
    }

	// Create New Tank Controller
	Controllers.push_back(std::make_unique<PlayerOneController>());
	Controllers.push_back(std::make_unique<AIController>());
    Controllers.push_back(std::make_unique<PlayerThreeController>());
    Controllers.push_back(std::make_unique<PlayerFourController>());
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	// Play::ClearDrawingBuffer( Play::cWhite );
    Play::DrawBackground();

	// Update All Tanks
	for (size_t i = 0; i < Tank::GetAllTanks().size(); ++i)
	{
		Controllers[i]->Update(Tank::GetAllTanks()[i], elapsedTime);
		Tank::GetAllTanks()[i]->Update(elapsedTime);
	}

    // Update bullets belonging to all tanks
    for (auto* Bullet : Bullet::GetAllBullets())
    {
        Bullet->Update(elapsedTime);
        if (Bullet->IsAlive())
        {
            Bullet->Draw();
        }            
    }

    // Remove dead bullets
    Bullet::GetAllBullets().erase(
        std::ranges::remove_if(Bullet::GetAllBullets(),
                               [](const Bullet* b) { return !b->IsAlive(); }).begin(),
        Bullet::GetAllBullets().end());
	
	Play::PresentDrawingBuffer();
	return Play::KeyDown( KEY_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}

