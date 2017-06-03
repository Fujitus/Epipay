//
// Created by costa_d on 03/06/17.
//

#include <net.hh>
#include <api.hh>
#include <NfcReader.hh>
#include "AccountInfo.hh"

AccountInfo::AccountInfo()
{
  this->creatInfo();
}

AccountInfo::~AccountInfo()
{}

void	AccountInfo::creatInfo()
{
  this->info.push_back(this->creatKey(546, 121, "price", 143, 70, "./img/money-cadre.png", "", 0, 650, 115,  TileType::INPUT));
  this->info.push_back(this->creatKey(111, 90, "photo", 111, 131, "./img/photo-cadre.png", "", 0, 0, 0,  TileType::NONE));
  this->info.push_back(this->creatKey(236, 99, "email", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236 + 5, 99 + 2, TileType::INPUT));
  this->info.push_back(this->creatKey(236, 99 + 28 + 15, "cardid", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236 + 5, 99 + 15 + 28 + 2, TileType::INPUT));
  this->info.push_back(this->creatKey(751, 73, "exit", 32, 34, "./img/quit.png", "", 0, 0, 0, TileType::EXIT));
}

std::vector<Button> 	AccountInfo::getInfo() const
{
  return (this->info);
}

void    AccountInfo::printInfo(sf::Event event, UI &ui)
{
  NfcReader			nfc;
  api				api(APIURL);
  std::vector<std::string>	json;
  std::string   		email;
  std::string   		cardId;
  std::string			balance;
  std::string			privilege;
  ErrorType 			error;

  if ((error = nfc.initNfcReader()) != ErrorType::NONE)
    {
      ui.printError(error, "\t\tCard Reader no init");
      ui.setClean();
      ui.setPrice("0.0");
      return ;
    }
  else
    {
      ui.printMsg("\t\t\tReading Card", 2);
      nfc.readCard();
    }
  if ((error = api.get(nfc.getIdCard())) == ErrorType::NONE)
    json = api.getJson();
  else
    {
      ui.printError(error, "\t\tAPI not responding\n\t\t\tOr not find user");
      ui.setClean();
      ui.setPrice("0.0");
      return ;
    }
  ui.clear();
  ui.printUiList(ui.getSmallUiList());
  ui.printButtonList(this->getInfo());
  ui.printDefaultText(this->getInfo()[2].textPos.x, this->getInfo()[2].textPos.y, json[1].substr(json[1].find(":") + 1), 18, sf::Color::White);
  ui.printDefaultText(this->getInfo()[3].textPos.x, this->getInfo()[3].textPos.y, json[2].substr(json[2].find(":") + 1), 18, sf::Color::White);
  ui.printDefaultText(246, 188, json[3].substr(json[3].find(":") + 1), 18, sf::Color::White);
  ui.printPrice(this->getInfo()[0].textPos.x, this->getInfo()[0].textPos.y, json[4].substr(json[4].find(":") + 1), 64);
  ui.display();
  while (42)
    {
      while (ui.window.pollEvent(event))
	{
	  Button tmp = ui.isClickable(ui.getClickPos(event), this->getInfo());
	  if (tmp.type == TileType::EXIT)
	    {
	      //ui.display();
	      ui.setClean();
	      ui.setPrice("0.0");
	      return ;
	    }
	}
      usleep(5000);
    }
}