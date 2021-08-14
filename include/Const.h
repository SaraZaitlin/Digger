#pragma once

const char MONSTER = '!';
const char PLAYER = '/';
const char EmptyLocation = ' ';
const char STON = '@';
const char DIAMOND= 'D';
const char WALL= '#';
const char GIFT='+';
const auto Length=600;
const auto Width=1000;
const auto Speed=150;
const auto SpeedMonster = 130;


enum  NameButtons
{
	player, orginalMonster, smartMonster,daimond,ston,wall,giftSton,giftTime,giftpointing,
	background,start,exitGame, backgroundGame, gameOver,win
};

enum Direction
{
	up, dawn, left, right
};