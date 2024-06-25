#ifndef GAME_CPP
#define GAME_CPP

#include"game.hpp"

//PRIVATE METHODSS
// initializing methods
//Initializing Variables
void Game::initVariables() {
	//WIndow variables
	windowSize.x = 800;
	windowSize.y = 600;
	videoMode.width = windowSize.x;
	videoMode.height = windowSize.y;

	allAnimated = false;

	gameState = GameState::MENU;
	menuOption = MenuOption::START;

	//Text variables
	fontMainMenu.loadFromFile("./Fonts/dpcomic.ttf");
	fontMenuOption.loadFromFile("./Fonts/RUBBBB.ttf");

	textMainMenu.setFont(fontMainMenu);
	textMainMenu.setString("FANDY'S ODYSSEY");
	textMainMenu.setFillColor(sf::Color::White);
	textMainMenu.setCharacterSize(90);
	textMainMenu.setPosition(sf::Vector2f(120.f, 80.f));

	textStart.setFont(fontMenuOption);
	textStart.setFillColor(sf::Color::Blue);
	textStart.setString("start");
	textStart.setCharacterSize(25);
	textStart.setPosition(sf::Vector2f(360.f, 280.f));

	textCredits.setFont(fontMenuOption);
	textCredits.setFillColor(sf::Color::White);
	textCredits.setString("credits");
	textCredits.setCharacterSize(25);
	textCredits.setPosition(sf::Vector2f(350.f,325.f));

	textExit.setFont(fontMenuOption);
	textExit.setFillColor(sf::Color::White);
	textExit.setString("exit");
	textExit.setCharacterSize(25);
	textExit.setPosition(sf::Vector2f(370.f, 375.f));

	textCredits_Contents.setString("\t\t\t\t\t\tCREDTIS\n\t\t\tMade with Love by Don Fandy\n\t\tPixel Panet Generator by Deep-Fold\n  Pixel Space Background Generator by Deep-Fold\n\n\n\n\nPress Enter or Escape to go back");
	textCredits_Contents.setFont(fontMainMenu);
	textCredits_Contents.setFillColor(sf::Color::White);
	textCredits_Contents.setCharacterSize(27);
	textCredits_Contents.setPosition(sf::Vector2f(140.f, 280.f));

	shapeCredits_Contents.setPosition(sf::Vector2f(125.f, 200.f));
	shapeCredits_Contents.setSize(sf::Vector2f(550.f, 300.f));
	shapeCredits_Contents.setOutlineColor(sf::Color::White);
	shapeCredits_Contents.setOutlineThickness(5.f);
	shapeCredits_Contents.setFillColor(sf::Color::Black);

	//Sprite and Texture variables
	menuPlanetSpriteCount = 0;
	menuBgSpriteCount = 0;
	
	menuPlanetTexture.loadFromFile("./sprites/menu_planet.png");
	menuPlanetSprite.setTexture(menuPlanetTexture);
	menuPlanetSprite.setTextureRect(sf::IntRect(0, 0, 100,100));
	menuPlanetSprite.setScale(sf::Vector2f(4.f, 4.f));
	menuPlanetSprite.setPosition(500.f, 200.f);

	menuBgTexture.loadFromFile("./sprites/menuBG.png");
	menuBgSprite.setTexture(menuBgTexture);
	menuBgSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	menuBgSprite.setScale(sf::Vector2f(12.5, 9.4));
	menuBgSprite.setPosition(0.f, 0.f);
	
}

//Initializing Key press states
void Game::initKeys()
{
	menuButtonPressed.UP = false;
	menuButtonPressed.DOWN = false;
	menuButtonPressed.ENTER = false;
}

//initializzing window
void Game::initWindow() {
	window.create(videoMode, "Fandy's Odyssey");
	window.setFramerateLimit(60);
}

//Runtime Methods
void Game::pollEvents()
{

	while (window.pollEvent(windowEvent))
	{
		switch (windowEvent.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
}

//Explain this function
// 
//Functions that have animations
void Game::animation()
{
	if (deltaTime >= 100.f)
	{
		if (menuPlanetSpriteCount < 49)
		{
			menuPlanetSpriteCount++;
		}
		else
		{
			menuPlanetSpriteCount -= 49;
		}
		if (menuBgSpriteCount < 3)
		{
			menuBgSpriteCount++;
		}
		else
		{
			menuBgSpriteCount -= 3;
		}
		menuPlanetSprite.setTextureRect(sf::IntRect(menuPlanetSpriteCount * 100, 0, 100, 100));
		menuBgSprite.setTextureRect(sf::IntRect(menuBgSpriteCount * 64, 0, 64, 64));
		allAnimated = true;
	}
	if (allAnimated)
	{
		allAnimated = false;
		clock.restart();
	}
	deltaTime = clock.getElapsedTime().asMilliseconds();
}

//Menu events
void Game::menuEvents()
{
	//Changing states on Up keyboard press state
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (menuButtonPressed.UP == false)
		{
			menuButtonPressed.UP = true;
			switch (menuOption)
			{
			case MenuOption::START:
				textStart.setFillColor(sf::Color::White);
				textExit.setFillColor(sf::Color::Blue);
				menuOption = MenuOption::EXIT;
				break;
			case MenuOption::CREDITS:
				textCredits.setFillColor(sf::Color::White);
				textStart.setFillColor(sf::Color::Blue);
				menuOption = MenuOption::START;
				break;
			case MenuOption::EXIT:
				textExit.setFillColor(sf::Color::White);
				textCredits.setFillColor(sf::Color::Blue);
				menuOption = MenuOption::CREDITS;
				break;
			default:
				std::cout << "MENU_EVENTS::KEY_UP_PRESSED::DEFAULT error\n";
				break;
			}
		}
	}
	else
	{
		menuButtonPressed.UP = false;
	}
	//Changing states on down keyboard press state
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (menuButtonPressed.DOWN == false)
		{
			menuButtonPressed.DOWN = true;
			switch (menuOption)
			{
			case MenuOption::START:
				textStart.setFillColor(sf::Color::White);
				textCredits.setFillColor(sf::Color::Blue);
				menuOption = MenuOption::CREDITS;
				break;
			case MenuOption::CREDITS:
				textCredits.setFillColor(sf::Color::White);
				textExit.setFillColor(sf::Color::Blue);
				menuOption = MenuOption::EXIT;
				break;
			case MenuOption::EXIT:
				textExit.setFillColor(sf::Color::White);
				textStart.setFillColor(sf::Color::Blue);
				menuOption = MenuOption::START;
				break;
			default:
				std::cout << "MENU_EVENTS::KEY_DOWN_PRESSED::DEFAULT error\n";
				break;
			}
		}
	}
	else
	{
		menuButtonPressed.DOWN = false;
	}
	//Changing states on Enter key press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (menuButtonPressed.ENTER == false)
		{
			menuButtonPressed.ENTER = true;
			switch (menuOption)
			{
			case Game::MenuOption::START:
				break;
			case Game::MenuOption::CREDITS:
				initVariables();
				gameState = GameState::CREDITS;
				break;
			case Game::MenuOption::EXIT:
				window.close();
				break;
			default:
				break;
			}
		}
	}
	else
	{
		menuButtonPressed.ENTER = false;
	}
}

//Credit Events
void Game::creditsEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) 
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (menuButtonPressed.ENTER == false)
		{
			gameState = GameState::MENU;
		}
	}
	else
	{
		menuButtonPressed.ENTER = false;
	}
}

//PUBLIC methods
//Constructor
Game::Game() {
	initVariables();
	initWindow();
};
//Destrctors
Game::~Game() {
	
};

//Updating game
void Game::update()
{
	pollEvents();
	switch (gameState)
	{
	case GameState::MENU:
		menuEvents();
		break;
	case GameState::GAMEPLAY:

		break;
	case GameState::CREDITS:
		creditsEvents();
		break;
	default:
		std::cout << "UPDATE::GAME_STATE::DEFAULT error\n";
		break;
	}

	animation();
}

//Rendering Game
void Game::render()
{
	//Clearing background as black
	window.clear(sf::Color::Black);
	//Drawing space background on menu and credit screens
	if ((gameState == GameState::MENU) || (gameState == GameState::CREDITS))
	{
		window.draw(menuBgSprite);
		window.draw(menuPlanetSprite);
	}

	//Switch case for drawing according to the game state
	switch (gameState)
	{
	case GameState::MENU:
		window.draw(textMainMenu);
		window.draw(textStart);
		window.draw(textCredits);
		window.draw(textExit);
		break;
	case GameState::GAMEPLAY:

		break;
	case GameState::CREDITS:
		window.draw(shapeCredits_Contents);
		window.draw(textCredits_Contents);
		break;
	default:
		std::cout << "RENDER::GAMESTATE(switch)::DEFAULT error";
		break;
	}
	
	//Displaying the drawing entities
	window.display();
}

//Return boolean state of Window
bool Game::isRunning()
{
	return window.isOpen();
}

#endif // !GAME.CPP
