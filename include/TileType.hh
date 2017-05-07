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
  KEYPAD = 0,
  BUTTON = 1,
  NONE = 2
};

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

#endif //EPIPAY_TILETYPE_HH
