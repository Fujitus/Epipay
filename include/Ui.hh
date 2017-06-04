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
# include "TileType.hh"
# include "Keyboard.hh"

class 	UI
{
  sf::Font      			priceFont;
  sf::Font      			defaultFont;
  std::vector<Elem>			UiList;
  std::vector<Elem>			SmallUiList;
  std::map<std::string, sf::Texture> 	textureList;
  int 					clean;
  std::string				price;
 public:
  sf::RenderWindow			window;
  UI();
  ~UI();
  void		open();
  void		closewin();
  void		display();
  void		clear();
  void		setPrice(std::string);
  int		loadFiles();
  void		setClean();
  void		printPrice(std::size_t, std::size_t, const std::string, std::size_t);
  void		printDefaultText(std::size_t, std::size_t, const std::string, std::size_t);
  void		printDefaultText(std::size_t, std::size_t, const std::string, std::size_t, sf::Color);
  void 		printButtonList(std::vector<Button>);
  int		printButton(const Button);
  int		printButton(const Button, std::string);
  int		printUiElem(const Elem);
  void 		printUiList(std::vector<Elem>);
  void 		creatUiList();
  void 		creatSmalUiList();
  Elem 		creatElem(std::size_t x, std::size_t y, std::size_t l, std::size_t h, std::string imgPath);
  Position	getClickPos(sf::Event) const;
  Button 	isClickable(Position, std::vector<Button>);
  std::string	getPrice() const;
  std::vector<Elem> getUiList() const;
  std::vector<Elem> getSmallUiList() const;
  void 		clock();
  void		ip();
  void 		actionView(Button, std::string);
  void		printError(ErrorType, std::string);
  void		printMsg(std::string, unsigned int);
  void 		systemExec(std::string);
};

#endif /* EPIPAY_UI_HH */
