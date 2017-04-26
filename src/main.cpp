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

int	main()
{
  UI      ui;
  Keypad  keypad;


  if (ui.loadFiles() == -1)
    return (-1);
  ui.open();
  while (42)
  {
    ui.printUi();
    ui.printButtonList(keypad.getKeypad());
    ui.printPrice(470, 72, ui.getPrice(), 64);
    ui.clock();
    ui.isClickable(ui.getClickPos(), keypad.getKeypad());
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