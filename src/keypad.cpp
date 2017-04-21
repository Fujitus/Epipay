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

void 	Keypad::creatKeypad()
{
  std::size_t 	x = 500;
  std::size_t 	y;
  short 	c = '1';

  while (x < (282 + 500))
  {
    y = 70;
    while (y < 70 + 282)
    {
      this->pad.push_back(this->creatKey(x, y, c, 94, 94,"./img/kyClassic.jpg", "./img/kyHover.jpg"));
      y += 94;
      c++;
    }
    x += 94;
  }
  this->pad.push_back(this->creatKey(x - 282, y, '.', 94, 94, "./img/kyClassic.jpg", "./img/kyHover.jpg"));
  this->pad.push_back(this->creatKey(x - 188, y, '0', 94, 94, "./img/kyClassic.jpg", "./img/kyHover.jpg"));
  this->pad.push_back(this->creatKey(x - 94, y, ';', 94, 94, "./img/kyClassic.jpg", "./img/kyHover.jpg"));
}

std::vector<Key>	Keypad::getKeypad() const
{
  return (this->pad);
}