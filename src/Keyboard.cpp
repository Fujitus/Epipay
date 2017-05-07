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
  std::size_t 	x = 0;
  std::size_t 	y;
  std::string	keylist = "azertyuiopqsdfghjklmwxcvbn";
  int 		i = 0;

  while (x < 122)
    {
      y = 0;
      while (y < 610)
	{
	  this->pad.push_back(this->creatKey(y, x, keylist.c_str()[i], 61, 61,"./img/kyClassic.png", "./img/kyHover.png", 45, y + 20, x + 5, TileType::KEYPAD));
	  y += 61;
	  i++;
	}
      x += 61;
    }
  this->pad.push_back(this->creatKey(61, x, '@', 61, 61, "./img/kyClassic.png", "./img/kyHover.png", 45, x + 25, y + 5, TileType::KEYPAD));
  y = 122;
  while (y < 488)
    {
      this->pad.push_back(this->creatKey(y, x, keylist.c_str()[i], 61, 61, "./img/kyClassic.png", "./img/kyHover.png", 45, y + 25, x + 5, TileType::KEYPAD));
      y += 61;
      i++;
    }
  this->pad.push_back(this->creatKey(y, x, "<-", 61, 61, "./img/kyClassic.png", "./img/kyHover.png", 45, y + 10, x,  TileType::KEYPAD));
}

std::vector<Button>	Keyboard::getKeypad() const
{
  return (this->pad);
}