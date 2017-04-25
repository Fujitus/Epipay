//
// ui.hh for Epipay in /home/costa_d/Documents/Epipay/ui.hpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 10:08:45 2017 Arnaud Costa
// Last update mar. avr. 18 10:08:45 2017 Arnaud Costa
//

#ifndef EPIPAY_UI_HH
#define EPIPAY_UI_HH

# include <iostream>
# include <cstddef>
# include <sstream>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <ctime>
# include "keypad.hh"
# include "TileType.hh"

class 	UI
{
  sf::Font      	priceFont;
  sf::Font      	defaultFont;
  Keypad		keypad;
  std::vector<Elem>	elemList;
  std::stringstream	ss;
  std::map<std::string, sf::Texture> textureList;
  sf::RenderWindow	window;
  float 		price;
 public:
  UI();
  ~UI();
  void		open();
  void		close();
  void		display();
  void		clear();
  int		loadFiles();
  void		printPrice(std::size_t, std::size_t, const std::string, std::size_t);
  void		printDefaultText(std::size_t, std::size_t, const std::string, std::size_t);
  void		printDefaultText(std::size_t, std::size_t, const std::string, std::size_t, sf::Color);
  sf::Event	getEvent();
  void 		printKeypad();
  int		printKey(const	Key);
  int		printKey(const	Key, std::string);
  int		printElem(const	Elem);
  void 		printElemList();
  void 		creatElemList();
  Elem 		creatElem(std::size_t x, std::size_t y, std::size_t l, std::size_t h, std::string imgPath);
  Position	getClickPos();
  void 		isClickable(Position);
  std::string	getPrice() const;
  void 		clock();
};

#endif /* EPIPAY_UI_HH */
