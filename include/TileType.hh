//
// TileType.hpp for Epipay in /home/costa_d/Documents/Epipay/TileType.hpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 12:52:20 2017 Arnaud Costa
// Last update mar. avr. 18 12:52:20 2017 Arnaud Costa
//

#ifndef EPIPAY_TILETYPE_HH
#define EPIPAY_TILETYPE_HH

struct 	Position
{
  std::size_t 	x;
  std::size_t 	y;
};

struct 	Size
{
  std::size_t 	lenth;
  std::size_t 	height;
};

struct 	Key
{
  std::string	c;
  std::string	sprite;
  std::string	hover;
  Position	pos;
  Size		size;
};

struct Elem
{
  std::string	sprite;
  Position	pos;
  Size		size;
};

#endif //EPIPAY_TILETYPE_HH
