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
	sf::RenderWindow* window;
	sf::Event event;

	sf::RectangleShape rect;

	bool** field;
	sf::Vector2i fieldSize;
	bool gameOver;
	
	void pollEvents();
	void update();
	void render();

};
