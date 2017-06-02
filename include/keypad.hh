//
// keypab.hpp for Epipay in /home/costa_d/Documents/Epipay/keypab.hpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 12:37:33 2017 Arnaud Costa
// Last update mar. avr. 18 12:37:33 2017 Arnaud Costa
//

#ifndef EPIPAY_KEYPAD_HH
#define EPIPAY_KEYPAD_HH

# include "Key.hh"

class	Keypad : public Key
{
  std::vector<Button>	pad;
  std::vector<Button>	smallpad;
 public:
  Keypad();
  ~Keypad();
  void	creatKeypad();
  void	creatSmallKeypad();
  std::vector<Button> getKeypad() const;
  std::vector<Button> getSmallKeypad() const;
};

#endif /* EPIPAY_KEYPAD_HH */
