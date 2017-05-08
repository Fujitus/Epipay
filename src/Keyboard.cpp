//
// Created by costa_d on 07/05/17.
//

#include "Keyboard.hh"

Keyboard::Keyboard()
{
  this->creatKeypad();
}

Keyboard::~Keyboard()
{}

void 	Keyboard::creatKeypad()
{
  std::size_t 	x = 285;
  std::size_t 	y;
  std::string	keylist = "AZERTYUIOPQSDFGHJKLMWXCVBN.";
  int 		i = 0;

  while (x < 110 + 285)
    {
      y = 100;
      while (y < 550 + 100)
	{
	  this->pad.push_back(this->creatKey(y, x, keylist.c_str()[i], 55, 54,"./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 28, y + 15, x + 5, TileType::KEYPAD));
	  y += 55 + 5;
	  i++;
	}
      x += 54 + 5;
    }
  this->pad.push_back(this->creatKey(100, x, '@', 55, 54, "./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 28, 100 + 13, x + 10, TileType::KEYPAD));
  y = 100 + 55 + 5;
  while (y < 385 + 100 + 55)
    {
      this->pad.push_back(this->creatKey(y, x, keylist.c_str()[i], 55, 55, "./img/bouton-clavier.png", "./img/bouton-clavier-hover.png", 28, y + 15, x + 5, TileType::KEYPAD));
      y += 55 + 5;
      i++;
    }
  this->pad.push_back(this->creatKey(y, x, "<-", 168, 55, "./img/bouton-entree.png", "./img/bouton-entree-hover.png", 45, y + 35, x,  TileType::KEYPAD));
}

std::vector<Button>	Keyboard::getKeypad() const
{
  return (this->pad);
}