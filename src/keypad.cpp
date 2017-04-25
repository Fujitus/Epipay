//
// keypad.cpp for Epipay in /home/costa_d/Documents/Epipay/keypad.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 12:37:41 2017 Arnaud Costa
// Last update mar. avr. 18 12:37:41 2017 Arnaud Costa
//

#include <SFML/Graphics/Sprite.hpp>
#include <sstream>
#include "keypad.hh"

Keypad::Keypad()
{
  this->creatKeypad();
}

Keypad::~Keypad()
{}

Key 	Keypad::creatKey(std::size_t x, std::size_t y, const char c,
			    std::size_t l, std::size_t h, std::string imgPath, std::string hoverPath)
{
  Key	k;

  k.pos.x = x;
  k.pos.y = y;
  k.c = c;
  k.size.height = h;
  k.size.lenth = l;
  k.sprite = imgPath;
  k.hover = hoverPath;
  return (k);
}

Key 	Keypad::creatKey(std::size_t x, std::size_t y, std::string c,
			    std::size_t l, std::size_t h, std::string imgPath, std::string hoverPath)
{
  Key	k;

  k.pos.x = x;
  k.pos.y = y;
  k.c = c;
  k.size.height = h;
  k.size.lenth = l;
  k.sprite = imgPath;
  k.hover = hoverPath;
  return (k);
}

void 	Keypad::creatKeypad()
{
  std::size_t 	x = 550;
  std::size_t 	y;
  short 	c = '1';

  while (x < (183 + 550))
  {
    y = 90;
    while (y < 110 + 183)
    {
      this->pad.push_back(this->creatKey(x, y, c, 61, 61,"./img/kyClassic.png", "./img/kyHover.png"));
      y += 61 + 10;
      c++;
    }
    x += 61 + 10;
  }
  this->pad.push_back(this->creatKey(x - 213, y, '.', 61, 61, "./img/kyClassic.png", "./img/kyHover.png"));
  this->pad.push_back(this->creatKey(x - 142, y, '0', 61, 61, "./img/kyClassic.png", "./img/kyHover.png"));
  this->pad.push_back(this->creatKey(x - 72, y, "DEL", 61, 61, "./img/kyClassic.png", "./img/kyHover.png"));
}

std::vector<Key>	Keypad::getKeypad() const
{
  return (this->pad);
}