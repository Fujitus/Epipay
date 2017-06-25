//
// Created by costa_d on 07/05/17.
//

#include <keypad.hh>
#include <chrono>
#include <thread>
#include "net.hh"
#include "NfcReader.hh"
#include "api.hh"
#include "RegisterUi.hh"

RegisterUi::RegisterUi(std::string _photoPath)
{
  this->photoPath = _photoPath;
  this->creatForm();
}

RegisterUi::~RegisterUi()
{}

void 	RegisterUi::creatForm()
{
  this->form.push_back(this->creatKey(546, 121, "price", 143, 70, "./img/money-cadre.png", "", 0, 650, 115,  TileType::INPUT));
  this->form.push_back(this->creatKey(31, 256, "sep", 737, 3, "./img/barre_separation_gris-fonce.png", "", 0, 0, 0,  TileType::NONE));
  this->form.push_back(this->creatKey(111, 90, "photo", 111, 131, "./img/photo-cadre.png", "", 0, 0, 0,  TileType::NONE));
  this->form.push_back(this->creatKey(236, 99, "email", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236 + 5, 99 + 2, TileType::INPUT));
  this->form.push_back(this->creatKey(236, 99 + 28 + 15, "cardid", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236 + 5, 99 + 15 + 28 + 2, TileType::INPUT));
  this->form.push_back(this->creatKey(246, 193, "USER", 11 + 15 + 5, 11, "./img/statut-on.png", "", 15, 246 + 15, 189, TileType::SELECTE));
  this->form.push_back(this->creatKey(311, 193, "BDE", 11 + 15 + 4, 11, "./img/statut-off.png", "", 15, 311 + 15, 189, TileType::SELECTE));
  this->form.push_back(this->creatKey(377, 193, "HUB", 11 + 15 + 4, 11, "./img/statut-off.png", "", 15, 377 + 15, 189, TileType::SELECTE));
  this->form.push_back(this->creatKey(751, 73, "exit", 32, 34, "./img/quit.png", "", 0, 0, 0, TileType::EXIT));
  this->form.push_back(this->creatKey(710, 300, "AddAcount", 70, 144, "./img/newUser.png", "", 17, 717, 335, TileType::INPUT));
}

std::vector<Button>	RegisterUi::getForm() const
{
  return (this->form);
}

void    RegisterUi::newUser(sf::Event event, UI &ui)
{
  Keypad	keypad;
  Keyboard	keyboard;
  api		api(APIURL);
  std::string   email = "";
  std::string   cardId = "<Get Card ID>";
  std::string	balance = "0.0";
  std::string	privilege = "USER";
  std::string	status = "getEmail";
  ErrorType 	error;

  ui.clear();
  ui.setPrice("");
  while (42)
    {
      ui.printUiList(ui.getSmallUiList());
      if (status == "getEmail")
	ui.printButtonList(keyboard.getKeypad());
      else if (status == "getPrice")
	ui.printButtonList(keypad.getSmallKeypad());
      ui.printButtonList(this->getForm());
      ui.printPrice(this->getForm()[0].textPos.x, this->getForm()[0].textPos.y, balance, 64);
      ui.printDefaultText(this->getForm()[4].textPos.x, this->getForm()[4].textPos.y, cardId, 18, sf::Color::White);
      ui.printDefaultText(this->getForm()[3].textPos.x, this->getForm()[3].textPos.y, email, 18, sf::Color::White);
      while (ui.window.pollEvent(event))
	{
//	  this->printPhotoIntra(this->photoPath + email + ".jpg", ui);
	  if (atof(balance.c_str()) > 100)
	    {
	      ui.printError(ErrorType::PRICELEN, "\t\tInvalide input price");
	      ui.setPrice("");
	      balance = "0.0";
	      ui.setClean();
	    }
	  Button tmp = ui.isClickable(ui.getClickPos(event), this->getForm());
	  if (tmp.type == TileType::EXIT)
	    {
	      ui.setPrice("0.0");
	      ui.setClean();
	      return ;
	    }
	  else if (tmp.type == TileType::INPUT)
	    {
	      if (tmp.c == "cardid")
		cardId = this->cardManager(ui);
	      else if (tmp.c == "price")
		{
		  status = "getPrice";
		  if (balance == "0.0")
		    ui.setPrice("");
		}
	      else if (tmp.c == "email")
		status = "getEmail";
	      else if (tmp.c == "AddAcount")
		{
		  email = ui.getPrice();
		  if ((error = api.makeJson(email, cardId, balance, privilege)) != ErrorType::NONE)
		    {
		      ui.printError(error, "Incorrecte register schemas");
		      ui.setPrice("");
		    }
		  else
		    {
		      api.post();
		      ui.setPrice("0.0");
		      ui.printMsg("Account registered\n\t\t\tsuccessfully", 0);
		      return ;
		    }
		  ui.setPrice("0.0");
		}
	    }
	  else if (tmp.type == TileType::SELECTE)
	    privilege = this->updatePrivilege(ui, tmp);
	  if (status == "getEmail")
	    {
	      ui.setPrice(email);
	      ui.isClickable(ui.getClickPos(event), keyboard.getKeypad());
	      email = ui.getPrice();
	    }
	  else if (status == "getPrice")
	    {
	      ui.setPrice(balance);
	      ui.isClickable(ui.getClickPos(event), keypad.getSmallKeypad());
	      balance = ui.getPrice();
	    }
	}
      ui.display();
      std::this_thread::sleep_for(std::chrono::microseconds(5000));
      ui.clear();
    }
}

std::string     RegisterUi::cardManager(UI &ui)
{
  ErrorType 	error;
  NfcReader	nfc;
  std::string   cardId;

  if ((error = nfc.initNfcReader()) != ErrorType::NONE)
    {
      ui.printError(error, "\t\tCard Reader no init");
      return ("<Get Card ID>");
    }
  else
    {
      ui.printMsg("\t\t[OK] Get Card ID", 0);
      nfc.readCard();
      sleep(1);
    }
  cardId = nfc.getIdCard();
  return (cardId);
}

std::string	RegisterUi::updatePrivilege(UI &ui, Button select)
{
  if (select.c == "USER")
    {
      this->form[5].sprite = "./img/statut-on.png";
      this->form[6].sprite = "./img/statut-off.png";
      this->form[7].sprite = "./img/statut-off.png";
    }
  if (select.c == "BDE")
    {
      this->form[5].sprite = "./img/statut-off.png";
      this->form[6].sprite = "./img/statut-on.png";
      this->form[7].sprite = "./img/statut-off.png";
    }
  if (select.c == "HUB")
    {
      this->form[5].sprite = "./img/statut-off.png";
      this->form[6].sprite = "./img/statut-off.png";
      this->form[7].sprite = "./img/statut-on.png";
    }
  return (select.c);
}

int		RegisterUi::printPhotoIntra(const std::string file, UI &ui)
{
  sf::Sprite    		sprite;
  sf::Texture   		texture;

  if (!texture.loadFromFile(file.c_str(), sf::IntRect(0, 0, 160, 190)))
    return (-1);
  sprite.setTexture(texture);
  sprite.setPosition(111, 90);
  ui.window.draw(sprite);
  return (0);
}