//
// Key.cpp for Epipay in /home/costa_d/Documents/Epipay/Key.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mer. avr. 26 17:53:46 2017 Arnaud Costa
// Last update mer. avr. 26 17:53:46 2017 Arnaud Costa
//

#include "Key.hpp"

Key::Key()
{}

Key::~Key()
{}

Button 	Key::creatKey(std::size_t x, std::size_t y, const char c,
			    std::size_t l, std::size_t h, std::string imgPath, std::string hoverPath)
{
  Button	k;

  k.pos.x = x;
  k.pos.y = y;
  k.c = c;
  k.size.height = h;
  k.size.lenth = l;
  k.sprite = imgPath;
  k.hover = hoverPath;
  return (k);
}

Button 	Key::creatKey(std::size_t x, std::size_t y, std::string c,
			    std::size_t l, std::size_t h, std::string imgPath, std::string hoverPath)
{
  Button	k;

  k.pos.x = x;
  k.pos.y = y;
  k.c = c;
  k.size.height = h;
  k.size.lenth = l;
  k.sprite = imgPath;
  k.hover = hoverPath;
  return (k);
}