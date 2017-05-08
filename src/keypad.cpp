//
// keypad.cpp for Epipay in /home/costa_d/Documents/Epipay/keypad.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 12:37:41 2017 Arnaud Costa
// Last update mar. avr. 18 12:37:41 2017 Arnaud Costa
//

#include "keypad.hh"

Keypad::Keypad()
{
  this->creatKeypad();
}

Keypad::~Keypad()
{}

void 	Keypad::creatKeypad()
{
  std::size_t 	x = 550;
  std::size_t 	y;
  short 	c = '1';

  while (x < 183 + 550)
  {
    y = 90;
    while (y < 110 + 183)
    {
      this->pad.push_back(this->creatKey(x, y, c, 61, 61,"./img/kyClassic.png", "./img/kyHover.png", 45, x + 20, y + 5, TileType::KEYPAD));
      y += 61 + 10;
      c++;
    }
    x += 61 + 10;
  }
  this->pad.push_back(this->creatKey(x - 213, y, '.', 61, 61, "./img/kyClassic.png", "./img/kyHover.png", 45, x + 25 - 213, y + 5, TileType::KEYPAD));
  this->pad.push_back(this->creatKey(x - 142, y, '0', 61, 61, "./img/kyClassic.png", "./img/kyHover.png", 45, x + 20 - 142, y + 5, TileType::KEYPAD));
  this->pad.push_back(this->creatKey(x - 72, y, "<-", 61, 61, "./img/kyClassic.png", "./img/kyHover.png", 45, x + 10 - 72, y,  TileType::KEYPAD));
}

std::vector<Button>	Keypad::getKeypad() const
{
  return (this->pad);
}