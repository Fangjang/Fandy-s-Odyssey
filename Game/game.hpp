#ifndef GAME_HPP
#define GAME_HPP

#include"directive.hpp"

class Game {
private:
	//Private Varaibles
	//WIndow varaibles
	sf::RenderWindow window;
	sf::Vector2u windowSize;
	sf::VideoMode videoMode;
	sf::Event windowEvent;

	//Game clock
	sf::Clock clock;
	float deltaTime;
	bool allAnimated;


	//Game varaibles
	//Gamestate enum
	enum class GameState {
		MENU = 0,
		GAMEPLAY,
		CREDITS
	};
	GameState gameState;
	
	//Main Menu Variables
	//Mennuoption Enum
	enum class MenuOption {
		START = 0,
		CREDITS,
		EXIT
	};
	MenuOption menuOption;
	//Menu button Pressed state
	struct MenuButtonPressed
	{
		bool UP;
		bool DOWN;
		bool ENTER;
	};
	MenuButtonPressed menuButtonPressed;
	
	//Animation Variables
	//Intro animation state ENUM
	enum class Intro_Animation_State {
		FIRST,
		SECOND
	};
	Intro_Animation_State intro_anim_State;

	//Texts 
	sf::Text textMainMenu;
	sf::Text textStart;
	sf::Text textCredits;
	sf::Text textCredits_Contents;
	sf::Text textExit;

	//Fonts
	sf::Font fontMainMenu;
	sf::Font fontMenuOption;

	//Shapes
	sf::RectangleShape shapeCredits_Contents;

	//Textures
	sf::Texture menuPlanetTexture;
	sf::Texture menuBgTexture;

	//Sprites
	//Main menu Sprites
	sf::Sprite menuPlanetSprite;
	sf::Sprite menuBgSprite;
	int menuPlanetSpriteCount;
	int menuBgSpriteCount;


	//Private Methods
	//INitializing Methods
	void initVariables();
	void initKeys();
	void initWindow();

	//Runtime methods
	void pollEvents();
	void animation();
	void menuEvents();
	void creditsEvents();

public:
	//Constructor and Destructors
	Game();
	~Game();

	//Public Methods
	void update();
	void render();
	bool isRunning();
};

#endif // !GAME