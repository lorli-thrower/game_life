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
	uint32_t cellSpeed;
	
	void pollEvents();
	void lifeCycle();
	void update();
	void render();

};
