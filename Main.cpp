//included libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

int main()
{
	//-----------------------------------------------------------
    //game setup
    //--------------------------------------------------------------
	//variables
	sf::RenderWindow gameWindow; //Makes a variable called gameWindow of the type renderwindow
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
	sf::Style::Titlebar | sf::Style::Close);

	//Timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimerUpperLimit = 10.0f;

	sf::Time timeTilsignal = sf::seconds(0.0f);
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock; //game clock


	//----------------------------------------------
	//-----------end game setup--------------------
	//---------------------------------------------



	//----------------------------------------------
    //Game loop
    //----------------------------------------------
    //Runs every frame untile the game is closed
	while (gameWindow.isOpen()) // while continues to loop while the (condition) is true
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{

			//Process events

			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		gameWindow.clear();
		gameWindow.display();
	}
	//------------------------------------------------
	//------------------end inputs--------------------
	//------------------------------------------------


	//----------------------------------------------
	//------------------UPDATE=---------------------
	//----------------------------------------------


	//----------------------------------------------
	//-----------------end update--------------------
	//------------------------------------------------


	//------------------------------------------------
	//-----------------draw---------------------------
	//------------------------------------------------

	//------------------------------------------------
	//------------------end draw----------------------
	//-------------------------------------------------
	return 0;
}
