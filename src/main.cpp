//
// main.cpp for Epipay in /home/costa_d/Documents/Epipay/main.cpp/
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 10:07:05 2017 Arnaud Costa
// Last update mar. avr. 18 10:07:05 2017 Arnaud Costa
//

#include <net.hh>
#include <RegisterUi.hh>
#include <AccountInfo.hh>
#include "Ui.hh"
#include "keypad.hh"
#include "ActionButton.hh"

int	main_loop()
{
  UI            ui;
  RegisterUi	RegUi("https://cdn.local.epitech.eu/userprofil/profilview/");
  Keypad        keypad;
  ActionButton  actionButton;
  AccountInfo	accountInfo;
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
	  ui.isClickable(ui.getClickPos(event), keypad.getKeypad());
	  tmp = ui.isClickable(ui.getClickPos(event), actionButton.getKeypad());
	  if (tmp.type == TileType::BUTTON && tmp.c == "Poweroff")
	    system("poweroff");
	  else if (tmp.type == TileType::BUTTON && tmp.c == "Reboot")
	    system("reboot");
	  if (atof(ui.getPrice().c_str()) > 100)
	    {
	      ui.printError(ErrorType::PRICELEN, "\t\tInvalide input price");
	      ui.setPrice("0.0");
	      ui.setClean();
	    }
	  if (tmp.type == TileType::BUTTON && tmp.c == "Account\n\tInfo")
	    accountInfo.printInfo(event, ui);
	  else if (tmp.type == TileType::BUTTON && tmp.c == "Reset")
	    {
	      ui.setClean();
	      ui.setPrice("0.0");
	    }
	  else if (tmp.type == TileType::BUTTON && tmp.c != "Stock Mod" && tmp.c != "Add Card")
	    ui.actionView(tmp, ui.getPrice());
	  else if (tmp.type == TileType::BUTTON && tmp.c == "Add Card")
	    RegUi.newUser(event, ui);
	  else if (tmp.type == TileType::BUTTON && tmp.c == "Stock Mod")
	    ui.printMsg("\t\t\t\t\tStock Mod\n\t\t\tWork in progress", 2);
    	}
    	ui.display();
    	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	  {
	    ui.closewin();
	    return (0);
	  }
      usleep(5000);
      ui.clear();
    }
}

int	main(int ac, char **av, char **ae)
{
  if (std::getenv("DISPLAY") == NULL || ae == NULL)
    {
      std::cerr << "[ERROR] Make sure the environment is set correctly or the DISPLAY environment variable is set correctly"<< std::endl;
      return (-1);
    }
  main_loop();
  return (0);
}