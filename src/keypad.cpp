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
  this->pad.push_back(this->creatKey(10, 10, '1', 10, 10));
  this->pad.push_back(this->creatKey(20, 10, '2', 10, 10));
  this->pad.push_back(this->creatKey(30, 10, '3', 10, 10));
  this->pad.push_back(this->creatKey(10, 20, '4', 10, 10));
  this->pad.push_back(this->creatKey(20, 20, '5', 10, 10));
  this->pad.push_back(this->creatKey(30, 20, '6', 10, 10));
  this->pad.push_back(this->creatKey(10, 30, '7', 10, 10));
  this->pad.push_back(this->creatKey(20, 30, '8', 10, 10));
  this->pad.push_back(this->creatKey(30, 30, '9', 10, 10));
  this->pad.push_back(this->creatKey(20, 40, '0', 10, 10));
}

std::vector<Key>	Keypad::getKeypad() const
{
  return (this->pad);
}