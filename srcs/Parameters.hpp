#pragma once

/*GAME STEP*/
enum GameStep {
	INTRO = 0x00,
	MAINMENU = 0x01,
	INGAME = 0x02,
	QUIT = 0x04,
};

/*MENU STEP*/
enum MenuStep {
	RESET_M = 0x00,
	TITLE = 0x01,
	MENU = 0x02,
	NEWGAME = 0x04,
	OPTION = 0x08,
	ABOUTME = 0x10,
	QUIT_M = 0x20,
	RUNGAME = 0x40,
};

/*COLOR*/
#define SKYBLUE "#77B5FE"
#define ORANGE "#884A01"
#define BLACK "#000000"
#define OCREYELLOW "#DFAF2C"
#define BRUN "#5B3C11"