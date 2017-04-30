//
// main.cpp for Epipay in /home/costa_d/Documents/Epipay/main.cpp/
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 10:07:05 2017 Arnaud Costa
// Last update mar. avr. 18 10:07:05 2017 Arnaud Costa
//

#include <chrono>
#include <thread>
#include "ui.hh"
#include "keypad.hh"
#include "ActionButton.hpp"

int	main()
{
  UI            ui;
  Keypad        keypad;
  ActionButton  actionButton;
  sf::Event     event;

  if (ui.loadFiles() == -1)
    return (-1);
  ui.open();
  while (ui.window.isOpen())
  {
    ui.printUi();
    ui.printButtonList(keypad.getKeypad());
    ui.printButtonList(actionButton.getKeypad());
    ui.printPrice(470, 72, ui.getPrice(), 64);
    ui.clock();
    while (ui.window.pollEvent(event))
    {
      ui.isClickable(ui.getClickPos(event), keypad.getKeypad());
      ui.isClickable(ui.getClickPos(event), actionButton.getKeypad());
    }
    ui.ip();
    ui.display();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      ui.closewin();
      return (0);
    }
    sf::milliseconds(5);
    ui.clear();
  }
}