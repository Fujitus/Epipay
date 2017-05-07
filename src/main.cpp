//
// main.cpp for Epipay in /home/costa_d/Documents/Epipay/main.cpp/
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 10:07:05 2017 Arnaud Costa
// Last update mar. avr. 18 10:07:05 2017 Arnaud Costa
//

#include <net.hpp>
#include "ui.hh"
#include "keypad.hh"
#include "ActionButton.hpp"

int	main()
{
  UI            ui;
  Keypad        keypad;
  ActionButton  actionButton;
  sf::Event     event;
  Button	tmp;

  if (ui.loadFiles() == -1)
    return (-1);
  ui.open();
  while (ui.window.isOpen())
    {
      ui.printUiList(ui.getUiList());
      ui.printButtonList(keypad.getKeypad());
      ui.printButtonList(actionButton.getKeypad());
      ui.printPrice(460, 72, ui.getPrice(), 64);
      while (ui.window.pollEvent(event))
    	{
	  tmp = ui.isClickable(ui.getClickPos(event), keypad.getKeypad());
	  if (tmp.type != TileType::NONE)
	    std::cout << "{MAIN} click on = " << tmp.c << std::endl;
	  tmp = ui.isClickable(ui.getClickPos(event), actionButton.getKeypad());
	  if (tmp.type != TileType::NONE)
	    std::cout << "{MAIN} click on = " << tmp.c << std::endl;
	  if (tmp.type == TileType::BUTTON && tmp.c != "Stock Mod" && tmp.c != "Add Card")
	    ui.actionView(tmp, ui.getPrice());
	  else if (tmp.type == TileType::BUTTON && tmp.c == "Add Card")
	    ui.newUser(event);
    	}
    	ui.display();
    	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    	{
	    ui.closewin();
	    return (0);
    	}
      usleep(10);
      ui.clear();
    }
}