#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

class Life
{
public:
	Life();
	~Life();

	void start();

private:
	// Windowing
	uint32_t fps;
	sf::RenderWindow* window;
	sf::Event event;

	sf::RectangleShape rect;

	// timer
	uint16_t timerMax;
	uint16_t timer;

	// field
	bool** field;
	bool** newField;
	sf::Vector2i fieldSize;
	
	bool gameOver;
	bool pause;
	bool pauseHeld; // If you hold space key it will pause and not do a slow-mo
	uint32_t cellSpeed;
	
	void pollEvents();
	void lifeCycle();
	void update();
	void render();

};
