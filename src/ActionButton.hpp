//
// ActionButton.hpp for Epipay in /home/costa_d/Documents/Epipay/ActionButton.hpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on jeu. avr. 27 10:58:31 2017 Arnaud Costa
// Last update jeu. avr. 27 10:58:31 2017 Arnaud Costa
//

#ifndef EPIPAY_ACTIONBUTTON_HPP
#define EPIPAY_ACTIONBUTTON_HPP

#include "Key.hpp"

class ActionButton : public Key
{
  std::vector<Button>	buttonList;
 public:
  ActionButton();
  ~ActionButton();
  void	creatKeypad();
  std::vector<Button> getKeypad() const;
};


#endif //EPIPAY_ACTIONBUTTON_HPP
