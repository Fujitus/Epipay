//
// Created by costa_d on 07/05/17.
//

#include "net.hh"
#include "NfcReader.hh"
#include "api.hh"
#include "RegisterUi.hh"

RegisterUi::RegisterUi(std::string _photoPath)
{
  this->photoPath = _photoPath;
  this->creatKeypad();
}

RegisterUi::~RegisterUi()
{}

void 	RegisterUi::creatKeypad()
{
  this->pad.push_back(this->creatKey(546, 121, "price", 143, 70, "./img/money-cadre.png", "", 0, 0, 0,  TileType::INPUT));
  this->pad.push_back(this->creatKey(31, 256, "", 737, 3, "./img/barre_separation_gris-fonce.png", "", 0, 0, 0,  TileType::NONE));
  this->pad.push_back(this->creatKey(111, 90, "", 111, 131, "./img/photo-cadre.png", "", 0, 0, 0,  TileType::NONE));
  this->pad.push_back(this->creatKey(236, 99, "email", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236 + 5, 99 + 2, TileType::INPUT));
  this->pad.push_back(this->creatKey(236, 99 + 28 + 15, "cardid", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236 + 5, 99 + 15 + 28 + 2, TileType::INPUT));
  this->pad.push_back(this->creatKey(246, 193, "USER", 11 + 15 + 5, 11, "./img/statut-on.png", "./img/statut-off.png", 15, 246 + 15, 189, TileType::SELECTE));
  this->pad.push_back(this->creatKey(311, 193, "BDE", 11 + 15 + 4, 11, "./img/statut-off.png", "./img/statut-on.png", 15, 311 + 15, 189, TileType::SELECTE));
  this->pad.push_back(this->creatKey(377, 193, "HUB", 11 + 15 + 4, 11, "./img/statut-off.png", "./img/statut-on.png", 15, 377 + 15, 189, TileType::SELECTE));
  this->pad.push_back(this->creatKey(236, 99 + 28 + 28 + 15 + 15, "", 250, 28, "./img/cadre-texte-photo.png", "", 0, 0, 0,  TileType::NONE));
  this->pad.push_back(this->creatKey(751, 73, "", 32, 34, "./img/quit.png", "", 0, 0, 0, TileType::EXIT));
  this->pad.push_back(this->creatKey(710, 300, "AddAcount", 70, 144, "./img/newUser.png", "", 17, 717, 335, TileType::INPUT));
}

std::vector<Button>	RegisterUi::getKeypad() const
{
  return (this->pad);
}

void    RegisterUi::newUser(sf::Event event, UI &ui)
{
  Keyboard	keyboard;
  api		api("http://192.168.43.26:3000/");
  std::string   email = "";
  std::string   cardId = "<Get Card ID>";
  std::string	balance = "0.0";
  std::string	privilege = "USER";

  ui.clear();
  ui.clearPrice("");
  while (42)
    {
      ui.printUiList(ui.getSmallUiList());
      ui.printButtonList(keyboard.getKeypad());
      ui.printButtonList(this->getKeypad());
      ui.printDefaultText(this->getKeypad()[4].textPos.x, this->getKeypad()[4].textPos.y, cardId, 18, sf::Color::White);
      ui.printDefaultText(this->getKeypad()[3].textPos.x, this->getKeypad()[3].textPos.y, email, 18, sf::Color::White);
      while (ui.window.pollEvent(event))
	{
	  Button tmp = ui.isClickable(ui.getClickPos(event), this->getKeypad());
	  if (tmp.type == TileType::EXIT)
	    {
	      ui.clearPrice("0.0");
	      ui.setClean();
	      return ;
	    }
	  else if (tmp.type == TileType::INPUT)
	    {
	      if (tmp.c == "cardid")
		cardId = this->cardManager(ui);
	      else if (tmp.c == "price")
		{
		  std::cout << "Print Key pad" << std::endl;
		}
	      else if (tmp.c == "AddAcount")
		{
		  email = ui.getPrice();
		  api.makeJson(email, cardId, balance, privilege);
		  api.post();
		  ui.clear();
		  ui.clearPrice("");
		  return ;
		}
	    }
	  email = ui.getPrice();
	  ui.isClickable(ui.getClickPos(event), keyboard.getKeypad());
	}
      ui.display();
      usleep(5000);
      ui.clear();
    }
}

std::string     RegisterUi::cardManager(UI &ui)
{
  NfcReader	nfc;
  std::string   cardId;
  sf::RectangleShape rectangle(sf::Vector2f(300, 150));

  rectangle.setFillColor(sf::Color::White);
  rectangle.setPosition(250, 100);
  ui.window.draw(rectangle);
  if (nfc.initNfcReader() == -1)
    {
      ui.printDefaultText(270, 138, "[ERROR] Card Reader no init", 20);
      ui.display();
      sleep(2);
      return ("<Get Card ID>");
    }
  else
    {
      ui.printDefaultText(315, 138, "[OK] Get Card ID", 20);
      ui.display();
      nfc.readCard();
      sleep(1);
    }
  cardId = nfc.getIdCard();
  return (cardId);
}