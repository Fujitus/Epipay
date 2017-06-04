//
// ActionButton.cpp for Epipay in /home/costa_d/Documents/Epipay/ActionButton.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on jeu. avr. 27 10:58:31 2017 Arnaud Costa
// Last update jeu. avr. 27 10:58:31 2017 Arnaud Costa
//

#include "ActionButton.hh"

ActionButton::ActionButton()
{
 this->creatKeypad();
}

ActionButton::~ActionButton()
{}

void		ActionButton::creatKeypad()
{
  this->buttonList.push_back(this->creatKey(20, 388, "Add Card", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 18, 30, 398, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(143, 388, "Add Money", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 18, 148, 398, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(263, 388, "Pay", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 18, 298, 398, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(383, 388, "Stock Mod", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 18, 388, 398, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(502, 388, "Account\n\tInfo", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 17, 520, 388, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(622, 388, "Reset", 103, 43, "./img/action_button.png", "./img/action_button_hover.png", 18, 646, 398, TileType::BUTTON));
  this->buttonList.push_back(this->creatKey(700, 15, "Poweroff", 30, 30, "./img/poweroff.png", "./img/poweroff.png", 0, 0, 0, TileType::CMD));
  this->buttonList.push_back(this->creatKey(660, 13, "Reboot", 30, 30, "./img/reboot.png", "./img/reboot.png", 0, 0, 0, TileType::CMD));
}

std::vector<Button>	ActionButton::getKeypad() const
{
  return (this->buttonList);
}