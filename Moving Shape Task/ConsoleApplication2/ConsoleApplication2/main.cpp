#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
	// first we want to create a window
	RenderWindow window(VideoMode(1280 , 720) , "My Program");
	window.setFramerateLimit(60);

	//create a rect shape
	RectangleShape rect;

	//spacify the position of rect
	Vector2f rectPosition(600 , 350);
	
	//set position
	rect.setPosition(rectPosition);

	//set size for rect
	rect.setSize(Vector2f(100, 100));

	float x = 3, y = 3;

	// game loop
	while (window.isOpen())
	{
		//check for the event happen at each frame(press , mouse move)
		Event event;
		while (window.pollEvent(event))
		{
			//check or detect if the x button were clicked
			if (event.type == Event::Closed)
			{
				window.close();
			}

			//check if the (esp) button is clicked?
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		// physics
		//check if the rect touch the edges (touch edges cases)
		if (rectPosition.x < 0 || rectPosition.x > 1280 - 100)
		{
			x *= -1;
		}

		if (rectPosition.y < 0 || rectPosition.y > 720 - 100)
		{
			y *= -1;
		}
		rectPosition.x += x;
		rectPosition.y += y;
		rect.setPosition(rectPosition);


		//render
		window.clear();
		//draw
		window.draw(rect);
		//display
		window.display();
	}
	
	return 0;
}