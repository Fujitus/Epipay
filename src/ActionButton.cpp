//
// ActionButton.cpp for Epipay in /home/costa_d/Documents/Epipay/ActionButton.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on jeu. avr. 27 10:58:31 2017 Arnaud Costa
// Last update jeu. avr. 27 10:58:31 2017 Arnaud Costa
//

#include "ActionButton.hpp"

ActionButton::ActionButton()
{
 this->creatKeypad();
}

ActionButton::~ActionButton()
{}

void		ActionButton::creatKeypad()
{
  this->buttonList.push_back(this->creatKey(20, 350, "Add Card", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 25, 25, 355, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(143, 350, "Add Money", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 25, 148, 355, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(263, 350, "Pay", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 25, 268, 355, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(383, 350, "Stock Mod", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 25, 388, 355, TileType::BUTTON));
}

std::vector<Button>	ActionButton::getKeypad() const
{
  return (this->buttonList);
}