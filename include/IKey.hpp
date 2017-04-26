//
// IButton.hpp for Epipay in /home/costa_d/Documents/Epipay/IButton.hpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mer. avr. 26 17:44:57 2017 Arnaud Costa
// Last update mer. avr. 26 17:44:57 2017 Arnaud Costa
//

#ifndef EPIPAY_IBUTTON_HPP
#define EPIPAY_IBUTTON_HPP

#include <vector>
#include <cstddef>
#include <string>
#include <iostream>
#include "TileType.hh"

class IKey
{
 public:
  virtual 	~IKey() {}
  virtual Button	creatKey(std::size_t x, std::size_t y, const char c,
			      std::size_t l, std::size_t h, std::string imgPath, std::string hoverPath) = 0;
  virtual Button	creatKey(std::size_t x, std::size_t y, std::string c,
			      std::size_t l, std::size_t h, std::string imgPath, std::string hoverPath) = 0;
};

#endif //EPIPAY_IBUTTON_HPP
