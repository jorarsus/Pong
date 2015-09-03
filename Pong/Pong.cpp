#include "stdafx.h"
#include "Pong.h"

using namespace std;

Pong::Pong()
{
	this->setup();
}


Pong::~Pong()
{
}

Pong* Pong::instance_ = NULL;

Pong* Pong::instance()
{
	if (instance_ == NULL)
		instance_ = new Pong();
	return instance_;
}

int Pong::setup()
{
	//The window we'll be rendering to
	window_ = NULL;


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	else
	{

		//Create window
		window_ = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window_ == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return -1;
		}
	}


	// Get the renderer we will use to draw objects
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
	if (renderer_ == NULL) {
		printf("Can't get window surface! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	// Create gameObjects
	gameObjectList_.push_front(new Paddle(PADDLES_OFFSET, SCREEN_HEIGHT / 2)); // Left Paddle
	gameObjectList_.push_front(new Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2)); // Ball at the center screen

	initialized_ = true;

	return 0;
}

void Pong::processInput()
{
	// Update Events
	SDL_PumpEvents();

	// Process exit event
	if (SDL_HasEvent(SDL_QUIT))
	{
		quit_ = true;
		cout << "Bye!" << endl;
	}

	// Get Keyboard state
	const Uint8* state = SDL_GetKeyboardState(NULL);

	// Pass keyboard state to bameObjects
	for (list<GameObject*>::iterator it = gameObjectList_.begin(); it != gameObjectList_.end(); it++)
	{
		if((*it)->acceptsInputEvents_)
			(*it)->handleKeyboardState(state);
	}
}

/*
	Update position of all gameObjects
*/
void Pong::update()
{
	for (list<GameObject*>::iterator it = gameObjectList_.begin(); it != gameObjectList_.end(); it++)
	{
		(*it)->update();
	}
}

/*
	Displays all gameObjects
*/
void Pong::display()
{
	// Clear screen (black)
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
	SDL_RenderClear(renderer_);

	for (list<GameObject*>::iterator it = gameObjectList_.begin(); it != gameObjectList_.end(); it++)
	{
		(*it)->display(renderer_);
	}

	// Update display
	SDL_RenderPresent(renderer_);
}


void Pong::gameLoop()
{
	Uint32 frameStartTime, frameEndTime;

	// min time to wait to keep the desired fps
	Uint32 minFrameTime = (1/(Uint32)DESIRED_FPS)*1000;
	
	if (!initialized_)
		setup();

	while (!quit_)
	{
		frameStartTime = SDL_GetTicks();

		// Loop core
		processInput();
		update();
		display();


		frameEndTime = SDL_GetTicks();
		Uint32 frameDuration = frameEndTime - frameStartTime;
		if(frameDuration < minFrameTime)
			SDL_Delay(minFrameTime - frameDuration);
			
	}
}



