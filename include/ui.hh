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
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include "keypad.hh"

class 	UI
{
  sf::Font      	font;
  Keypad		keypad;
 public:
  UI();
  ~UI();
  sf::RenderWindow	window;
  void		open();
  void		close();
  void		display();
  void		clear();
  int		loadFiles();
  void		printText(std::size_t, std::size_t, const std::string, std::size_t);
  sf::Event	getEvent();
  void 		printKeypad();
  int		printKey(const	Key);
};

#endif /* EPIPAY_UI_HH */
