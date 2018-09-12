//included libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
	//-----------------------------------------------------------
    //game setup
    //--------------------------------------------------------------
	
	
	//Rendom Window creation
	sf::RenderWindow gameWindow; //Makes a variable called gameWindow of the type renderwindow
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
	sf::Style::Titlebar | sf::Style::Close);

	//seed our random number generation
	srand(time(NULL));


	//Timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimerUpperLimit = 10.0f;

	sf::Time timeTilsignal = sf::seconds(signalTimeLowerLimit);
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock; //game clock

	//create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	//center sprite in the middle of the screen, you have to realign it as the anchor point is the top left
	buttonSprite.setPosition(gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);


	//----------------------------------------------
	//-----------end game setup--------------------
	//---------------------------------------------



	//----------------------------------------------
    //Game loop
    //----------------------------------------------
    //Runs every frame untile the game is closed
	while (gameWindow.isOpen()) // while continues to loop while the (condition) is true
	{
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			//Process events


			//check if event is a mouse button pressed
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					//we did
					int range =(int)(signalTimerUpperLimit - signalTimeLowerLimit);
					float signalSeconds = rand() % range + signalTimerUpperLimit;

					timeTilsignal = sf::seconds(signalSeconds);
				}
			}




			if (gameEvent.type == sf::Event::Closed)
				gameWindow.close();
		}
		
		
	
	//------------------------------------------------
	//-----------------=End Inputs=-------------------
	//------------------------------------------------


	//----------------------------------------------
	//-----------------=UPDATE=---------------------
	//----------------------------------------------
	
	//update time
	sf::Time frameTime = gameClock.restart();

	//update time till signal
	timeTilsignal = timeTilsignal - frameTime;


	if (timeTilsignal.asSeconds() <= 0.0f)
	{
		buttonSprite.setColor(sf::Color::Blue);

	}
	//----------------------------------------------
	//----------------=End Update=-------------------
	//------------------------------------------------


	//------------------------------------------------
	//----------------=Draw=--------------------------
	//------------------------------------------------

	//clear the screen
	gameWindow.clear(sf::Color::Cyan);

	// Draw everything
	gameWindow.draw(buttonSprite);
	gameWindow.display();

	//------------------------------------------------
	//-----------------=end draw=---------------------
	//-------------------------------------------------
	}
	return 0;
}
