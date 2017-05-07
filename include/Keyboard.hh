//
// Created by costa_d on 07/05/17.
//

#ifndef EPIPAY_KEYBOARD_H
#define EPIPAY_KEYBOARD_H


#include "Key.hpp"

class Keyboard : public Key
{
 public:
  Keyboard();
  ~Keyboard();
  std::vector<Button>	pad;
 public:
  void	creatKeypad();
  std::vector<Button> getKeypad() const;
};


#endif //EPIPAY_KEYBOARD_H
