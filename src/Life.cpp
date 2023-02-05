#include "Life.h"

// constructor & destructor
Life::Life()
{
	gameOver = false;
	// window stuff
	sf::VideoMode videoMode(900, 900);
	window = new sf::RenderWindow(videoMode, "Life", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
	
	// rect stuff
	rect.setSize(sf::Vector2f(30, 30));
	rect.setFillColor(sf::Color::Green);
	
	// field stuff
	fieldSize = sf::Vector2i(window->getSize().x / rect.getSize().x, window->getSize().y / rect.getSize().y);
	field = new bool*[fieldSize.x];
	for (int i = 0; i < fieldSize.x; i++)
		field[i] = new bool[fieldSize.y];
	// randomizing field
	for (int i = 0; i < fieldSize.x; i++)
		for (int j = 0; j < fieldSize.y; j++)
			field[i][j] = (rand() % 3 == 0);

}
Life::~Life()
{
	delete window;
}

// start function
void Life::start()
{
	while(!gameOver && window->isOpen())
	{
		update();
		render();
	}
}

// main functions
void Life::update()
{
	pollEvents();

}
void Life::render()
{
	// clearing
	window->clear();

	// drawing
	for (int i = 0; i < fieldSize.x; i++)
		for (int j = 0; j < fieldSize.y; j++)
			if (field[i][j])
			{
				rect.setPosition(sf::Vector2f(i * rect.getSize().x, j * rect.getSize().y));
				window->draw(rect);
			}

	// displaing
	window->display();
}
void Life::pollEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

// other functions
