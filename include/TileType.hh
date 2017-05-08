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

enum class TileType : uint16_t
{
  NONE = 0,
  KEYPAD = 1,
  BUTTON = 2,
  EXIT = 3,
  INPUT = 4,
  SELECTE = 5,
};

struct 	Position
{
  int	 	x;
  int	 	y;
};

struct 	Size
{
  std::size_t   lenth;
  std::size_t   height;
};

struct 	Button
{
  std::string	c;
  std::string	sprite;
  std::string	hover;
  std::size_t 	fontSize;
  Position	pos;
  Position	textPos;
  Size		size;
  TileType 	type;
};

struct Elem
{
  std::string	sprite;
  Position	pos;
  Size		size;
};

#endif /* EPIPAY_TILETYPE_HH */
