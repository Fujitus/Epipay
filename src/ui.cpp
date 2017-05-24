//
// ui.cpp.cpp for Epipay in /home/costa_d/Documents/Epipay/ui.cpp.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 10:08:39 2017 Arnaud Costa
// Last update mar. avr. 18 10:08:39 2017 Arnaud Costa
//

#include <iomanip>
#include "ui.hh"
#include "net.hh"
#include "RegisterUi.hh"
#include "NfcReader.hh"
#include "api.hh"

UI::UI(char **ae)
{
  this->creatUiList();
  this->creatSmalUiList();
  this->price = "0.0";
  this->clean = 0;
}

UI::~UI()
{}

void	UI::open()
{
  this->window.create(sf::VideoMode(800, 480), "EpiPay");
}

void	UI::closewin()
{
  this->window.close();
}

void	UI::display()
{
  this->window.display();
}

void	UI::clear()
{
  this->window.clear();
}

void    UI::clearPrice(std::string set)
{
  this->price = set;
}

int		UI::loadFiles()
{
  if (!this->priceFont.loadFromFile("./font/price.ttf"))
    {
      std::cerr << "[ ERROR ] can't open price font"<< std::endl;
      return (-1);
    }
  if (!this->defaultFont.loadFromFile("./font/default.ttf"))
  {
    std::cerr << "[ ERROR ] can't open default font"<< std::endl;
    return (-1);
  }
  return (0);
}

void 		UI::printPrice(std::size_t x, std::size_t y,
				  const std::string text, std::size_t size)
{
  sf::Text entity;

  entity.setFont(this->priceFont);
  entity.setPosition(x - (text.length() * 31), y);
  entity.setString(text);
  entity.setCharacterSize(static_cast<unsigned int>(size));
  entity.setColor(sf::Color::White);
  entity.setStyle(sf::Text::Regular);
  window.draw(entity);
}

void 		UI::printDefaultText(std::size_t x, std::size_t y,
				  const std::string text, std::size_t size)
{
  sf::Text entity;

  entity.setFont(this->defaultFont);
  entity.setPosition(x, y);
  entity.setString(text);
  entity.setCharacterSize(static_cast<unsigned int>(size));
  entity.setColor(sf::Color::Black);
  entity.setStyle(sf::Text::Regular);
  window.draw(entity);
}


void 		UI::printDefaultText(std::size_t x, std::size_t y,
					 const std::string text, std::size_t size, sf::Color color)
{
  sf::Text entity;

  entity.setFont(this->defaultFont);
  entity.setPosition(x, y);
  entity.setString(text);
  entity.setCharacterSize(static_cast<unsigned int>(size));
  entity.setColor(color);
  entity.setStyle(sf::Text::Regular);
  window.draw(entity);
}

void 		UI::printButtonList(std::vector<Button> tmpList)
{
  std::vector<Button>::iterator	it = tmpList.end() - 1;

  while (it >= tmpList.begin())
  {
    if (this->printButton(*it) == -1)
      return ;
    --it;
  }
}

int		UI::printButton(const Button tmp)
{
  sf::Sprite    		sprite;
  sf::Texture   		texture;
  std::map<std::string, sf::Texture>::iterator it;

  it = this->textureList.find(tmp.sprite);
  if (it == this->textureList.end())
  {
    if (!texture.loadFromFile((tmp.sprite.c_str()), sf::IntRect(0, 0, tmp.size.lenth, tmp.size.height)))
      return (-1);
    this->textureList[tmp.sprite] = texture;
  }
  else
    texture = (*it).second;
  sprite.setTexture(texture);
  sprite.setPosition(tmp.pos.x, tmp.pos.y);
  this->window.draw(sprite);
  if (tmp.c != "<-" && tmp.c != "AddAcount")
    this->printDefaultText(tmp.textPos.x, tmp.textPos.y, tmp.c, tmp.fontSize);
  return (0);
}

int		UI::printButton(const Button tmp, std::string hover)
{
  sf::Sprite    		sprite;
  sf::Texture   		texture;
  std::map<std::string, sf::Texture>::iterator it;

  if (hover == "")
    return (0);
  it = this->textureList.find(hover);
  if (it == this->textureList.end())
  {
    if (!texture.loadFromFile((hover.c_str()), sf::IntRect(0, 0, tmp.size.lenth, tmp.size.height)))
      return (-1);
    this->textureList[hover] = texture;
  }
  else
    texture = (*it).second;
  sprite.setTexture(texture);
  sprite.setPosition(tmp.pos.x, tmp.pos.y);
  this->window.draw(sprite);
  if (tmp.c != "<-" && tmp.c != "AddAcount")
    this->printDefaultText(tmp.textPos.x, tmp.textPos.y, tmp.c, tmp.fontSize);
  return (0);
}

void 		UI::printUiList(std::vector<Elem> List)
{
  std::vector<Elem>::iterator	it = List.begin();

  while (it != List.end())
  {
    if (this->printUiElem(*it) == -1)
      return ;
    ++it;
  }
  this->clock();
  this->ip();
}

int		UI::printUiElem(const Elem tmp)
{
  sf::Sprite    		sprite;
  sf::Texture   		texture;

  if (!texture.loadFromFile((tmp.sprite.c_str()), sf::IntRect(0, 0, tmp.size.lenth, tmp.size.height)))
    return (-1);
  sprite.setTexture(texture);
  sprite.setPosition(tmp.pos.x, tmp.pos.y);
  this->window.draw(sprite);
  return (0);
}

Elem 	UI::creatElem(std::size_t x, std::size_t y, std::size_t l,
			  std::size_t h, std::string imgPath)
{
  Elem	e;

  e.pos.x = x;
  e.pos.y = y;
  e.size.height = static_cast<int>(h);
  e.size.lenth = static_cast<int>(l);
  e.sprite = imgPath;
  return (e);
}

void 	UI::creatUiList()
{
  this->UiList.push_back(this->creatElem(0, 0, 800, 480, "./img/background.png"));
  this->UiList.push_back(this->creatElem(20, 90, 477, 92, "./img/priceRec.png"));
  this->UiList.push_back(this->creatElem(20, 165, 475, 178, "./img/billRec.png"));
}

void 	UI::creatSmalUiList()
{
  this->SmalUiList.push_back(this->creatElem(0, 0, 800, 480, "./img/background.png"));
}

Position	UI::getClickPos(sf::Event e) const
{
  Position pos = Position();


  pos.x = -1;
  pos.y = -1;
  if (e.type == sf::Event::MouseButtonPressed)
    {
      if (e.mouseButton.button == sf::Mouse::Left)
        {
          pos.x = e.mouseButton.x;
          pos.y = e.mouseButton.y;
        }
    }
  return (pos);
}

std::vector<Elem> UI::getUiList() const
{
  return (this->UiList);
}

Button 	UI::isClickable(Position mouse, std::vector<Button> tmpButton)
{
  std::vector<Button>::iterator it = tmpButton.end() - 1;
  Button  k;

  k.type = TileType::NONE;
  while (it >= tmpButton.begin())
  {
    if (mouse.y >= (*it).pos.y && mouse.y <= (*it).pos.y + (*it).size.height &&
     	mouse.x >= (*it).pos.x && mouse.x <= (*it).pos.x + (*it).size.lenth)
    {
        if ((*it).type == TileType::KEYPAD)
          {
            if (this->clean == 0)
              {
                this->price.clear();
                this->clean = 1;
              }
	    else if ((*it).c == "<-" && this->price.length() > 0)
              this->price.pop_back();
            if ((*it).c != "<-")
              {
                if (isalpha((*it).c[0]))
                  this->price += (*it).c[0] + 32;
                else
                  this->price += (*it).c;
              }
          }
        std::cout << "{CLICK FUNC} Click on " << (*it).c << std::endl;
        this->printButton(*it, (*it).hover);
        this->display();
        usleep(30000);
        return ((*it));
    }
    --it;
  }
  return (k);
}

std::string	UI::getPrice() const
{
  return (this->price);
};

void 	UI::clock()
{
  time_t 	rawtime;
  struct tm 	*timeinfo;
  char 		buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y\n     %I:%M",timeinfo);
  std::string str(buffer);
  this->printDefaultText(350, 5, str, 18, sf::Color::White);
}

void	UI::ip()
{
  int fd;
  struct ifreq ifr;

  fd = socket(AF_INET, SOCK_DGRAM, 0);
  ifr.ifr_addr.sa_family = AF_INET;
  strncpy(ifr.ifr_name, "wlo1", IFNAMSIZ-1);
  ioctl(fd, SIOCGIFADDR, &ifr);
  close(fd);
  std::string str(inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
  if (str != "0.0.0.0")
    this->printUiElem(this->creatElem(750, 15, 31, 25,"./img/wifi.png"));
  else
    this->printUiElem(this->creatElem(760, 35, 31, 25,"./img/wifi_no.png"));
}

void    UI::actionView(Button button, std::string price)
{
  NfcReader		nfc;
  api			api("http://localhost:3042/");
  sf::RectangleShape  	rectangle(sf::Vector2f(300, 150));
  double              	balance = std::atof(this->price.c_str());

  rectangle.setFillColor(sf::Color::White);
  rectangle.setPosition(250, 100);
  this->window.draw(rectangle);
  this->printDefaultText(378 - button.c.length() * 2, 108, button.c, 25);
  if (price == "0.0")
    {
      this->printDefaultText(315, 138, "Error no price define", 20);
      this->display();
      sleep(2);
      return ;
    }
  this->printDefaultText(280, 138, "Waiting API for update acount", 18);
  this->display();
  if (nfc.initNfcReader() == -1)
    std::cerr << "[ERROR] Card Reader no init" << std::endl;
  else
    nfc.readCard();
  if (api.get(nfc.getIdCard()))
    api.updateAccount(button, balance, nfc.getIdCard());
  else
    {
      rectangle.setFillColor(sf::Color::White);
      rectangle.setPosition(250, 100);
      this->window.draw(rectangle);
      this->printDefaultText(378 - button.c.length() * 2, 108, button.c, 25);
      this->printDefaultText(295, 138, "Error API not responding", 20);
      this->display();
      sleep(2);
    }
  this->clear();
  this->clearPrice("0.0");
  this->clean = 0;
}

void    UI::newUser(sf::Event event)
{
  Keyboard	keyboard;
  RegisterUi	registerUi("img/beta_photo.png");
  api		api("http://localhost:3042/");
  Button        tmp;
  NfcReader	nfc;
  short         pos = 3;
  std::string   email = "";
  std::string   cardId = "";
  std::string	balance = "0.0";
  std::string	privilege = "USER";

  this->clear();
  this->clearPrice("");
  if (nfc.initNfcReader() == -1)
    std::cerr << "[ERROR] Card Reader no init" << std::endl;
  else
    nfc.readCard();
  cardId = nfc.getIdCard();
  while (42)
    {
      this->printUiList(this->SmalUiList);
      this->printButtonList(keyboard.getKeypad());
      this->printButtonList(registerUi.getKeypad());
      printDefaultText(registerUi.getKeypad()[pos].textPos.x, registerUi.getKeypad()[pos].textPos.y, this->price, 18, sf::Color::White);
      if (pos == 3)
        printDefaultText(registerUi.getKeypad()[4].textPos.x, registerUi.getKeypad()[4].textPos.y, cardId, 18, sf::Color::White);
      else if (pos == 4)
        printDefaultText(registerUi.getKeypad()[3].textPos.x, registerUi.getKeypad()[3].textPos.y, email, 18, sf::Color::White);
      while (this->window.pollEvent(event))
        {
          tmp = this->isClickable(this->getClickPos(event), registerUi.getKeypad());
          if (tmp.type == TileType::EXIT)
            {
              this->clearPrice("0.0");
              this->clean = 0;
              return ;
            }
          else if (tmp.type == TileType::INPUT)
            {
              if (pos == 3 && tmp.pos.x == registerUi.getKeypad()[4].pos.x &&
                  tmp.pos.y == registerUi.getKeypad()[4].pos.y)
                {
                  email = this->price;
                  this->clearPrice("");
                  this->clearPrice(cardId);
                  pos = 4;
                }
              else if (pos == 4 && tmp.pos.x == registerUi.getKeypad()[3].pos.x &&
                       tmp.pos.y == registerUi.getKeypad()[3].pos.y)
                {
		  cardId = this->price;
                  this->clearPrice("");
                  this->clearPrice(email);
                  pos = 3;
                }
	      else if (tmp.pos.x == registerUi.getKeypad()[0].pos.x &&
		       tmp.pos.y == registerUi.getKeypad()[0].pos.y)
		{
		  std::cout << "Print Key pad" << std::endl;
		}
	      else if (tmp.c == "AddAcount")
		{
		  email = this->price;
		  api.makeJson(email, cardId, balance, privilege);
		  api.post();
		  this->clear();
		  this->clearPrice("");
		  return ;
		}
            }
          this->isClickable(this->getClickPos(event), keyboard.getKeypad());
        }
      this->display();
      usleep(10);
      this->clear();
    }
}