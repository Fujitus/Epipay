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
			    std::size_t l, std::size_t h)
{
  Key	k;


  k.pos.x = x;
  k.pos.y = y;
  k.c = c;
  k.height = h;
  k.lenth = l;
  k.sprite = "./img/bgKey.png";
  return (k);
}

void 	Keypad::creatKeypad()
{
  this->pad.push_back(this->creatKey(10, 10, '1', 64, 64));
  this->pad.push_back(this->creatKey(74, 10, '2', 64, 64));
  this->pad.push_back(this->creatKey(138, 10, '3', 64, 64));
  this->pad.push_back(this->creatKey(10, 74, '4', 64, 64));
  this->pad.push_back(this->creatKey(74, 74, '5', 64, 64));
  this->pad.push_back(this->creatKey(138, 74, '6', 64, 64));
  this->pad.push_back(this->creatKey(10, 138, '7', 64, 64));
  this->pad.push_back(this->creatKey(74, 138, '8', 64, 64));
  this->pad.push_back(this->creatKey(138, 138, '9', 64, 64));
  this->pad.push_back(this->creatKey(74, 202, '0', 64, 64));
}

std::vector<Key>	Keypad::getKeypad() const
{
  return (this->pad);
}