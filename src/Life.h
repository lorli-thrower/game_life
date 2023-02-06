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
	bool** newField;
	sf::Vector2i fieldSize;
	bool gameOver;
	
	void pollEvents();
	void lifeCycle();
	void update();
	void render();

};
