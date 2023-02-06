#include "Life.h"

// constructor & destructor
Life::Life()
{
	gameOver = false;
	// window stuff
	sf::VideoMode videoMode(900, 900);
	window = new sf::RenderWindow(videoMode, "Life", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(5);
	
	// rect stuff
	rect.setSize(sf::Vector2f(30, 30));
	rect.setFillColor(sf::Color::Green);
	
	// field stuff
	fieldSize = sf::Vector2i(window->getSize().x / rect.getSize().x, window->getSize().y / rect.getSize().y);
	field = new bool*[fieldSize.x];
	for (int i = 0; i < fieldSize.x; i++)
		field[i] = new bool[fieldSize.y];
	newField = new bool*[fieldSize.x];
	for (int i = 0; i < fieldSize.x; i++)
		newField[i] = new bool[fieldSize.y];
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

// functions
void Life::update()
{
	pollEvents();

	// life cycle
	lifeCycle();

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

void Life::lifeCycle()
{
	uint8_t neighbors;

	// calculating neighbors for every cell
	// for every cell
	for (int i = 0; i < fieldSize.x; i++)
		for (int j = 0; j < fieldSize.y; j++)
		{
			neighbors = 0;
			// calculate neighbors
			for (int k = -1; k < 2; k++)
					for (int m = -1; m < 2; m++)
						{
							// cheking if neighbor is not in array
							if (i == 0 && k == -1) break;
							if (i == fieldSize.x - 1 && k == 1) break;
							if (j == 0 && m == -1) continue;
							if (j == fieldSize.y - 1 && m == 1) continue;
							if (k == 0 && m == 0) continue;

							// if neighbor is alive, count him
							if (field[i + k][j + m])
								neighbors++;
						}
			// doing things with cell depending on amount neighbors it has
			if (neighbors == 2 && field[i][j])
				newField[i][j] = true;
			else if (neighbors == 3)
				newField[i][j] = true;
			else 
				newField[i][j] = false;
		}
	// making new fieli the real field
	for (int i = 0; i < fieldSize.x; i++)
		for (int j = 0; j < fieldSize.y; j++)
			field[i][j] = newField[i][j];
}



			

