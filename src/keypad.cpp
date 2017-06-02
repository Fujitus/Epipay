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
  this->creatSmallKeypad();
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
  this->pad.push_back(this->creatKey(x - 72, y, "<-", 61, 61, "./img/kyClassic_entree.png", "./img/kyHover_entree.png", 45, x + 10 - 72, y,  TileType::KEYPAD));
}

std::vector<Button>	Keypad::getKeypad() const
{
  return (this->pad);
}

void 	Keypad::creatSmallKeypad()
{
  std::size_t 	x = 270;
  std::size_t 	y;
  short 	c = '1';

  while (x < 222 + 270)
    {
      y = 270;
      while (y < 112 + 270)
        {
          this->smallpad.push_back(this->creatKey(x, y, c, 55, 54,"./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 45, x + 20, y, TileType::KEYPAD));
          y += 55 + 5;
          c++;
        }
      x += 54 + 5;
    }
  this->smallpad.push_back(this->creatKey(x - (54 + 5 + 54 + 5 + 54 + 5 + 54 + 5), y, '.', 55, 54, "./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 45, x - (54 + 5 + 54 + 5 + 54 + 5 + 54 + 5) + 20, y, TileType::KEYPAD));
  this->smallpad.push_back(this->creatKey(x - (54 + 5 + 54 + 5 + 54 + 5), y, '9', 55, 54, "./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 45, x - (54 + 5 + 54 + 5 + 54 + 5) + 20, y, TileType::KEYPAD));
  this->smallpad.push_back(this->creatKey(x - (54 + 5 + 54 + 5), y, '0', 55, 54, "./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 45, x - (54 + 5 + 54 + 5) + 20, y, TileType::KEYPAD));
  this->smallpad.push_back(this->creatKey(x - (54 + 5), y, "<-", 55 , 54, "./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 45, x - (54 + 5) + 20, y,  TileType::KEYPAD));
}

std::vector<Button>	Keypad::getSmallKeypad() const
{
  return (this->smallpad);
}