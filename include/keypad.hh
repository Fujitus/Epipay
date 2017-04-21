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

#include <vector>
#include <cstddef>
#include <string>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include "TileType.hh"

class	Keypad
{
  std::vector<Key>	pad;
 public:
  Keypad();
  ~Keypad();
  void	creatKeypad();
  Key 	creatKey(std::size_t, std::size_t, const char, std::size_t, std::size_t, std::string, std::string hoverPath);
  std::vector<Key> getKeypad() const;
};

#endif /* EPIPAY_KEYPAD_HH */
