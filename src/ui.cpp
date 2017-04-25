//
// ui.cpp.cpp for Epipay in /home/costa_d/Documents/Epipay/ui.cpp.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 10:08:39 2017 Arnaud Costa
// Last update mar. avr. 18 10:08:39 2017 Arnaud Costa
//

#include "ui.hh"
#include "net.hpp"

UI::UI()
{
  this->creatElemList();
  this->price = 0.0;
  this->ss << "0.0";
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

sf::Event	UI::getEvent() {
  sf::Event	event;

  while (window.pollEvent(event))
    return (event);
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
  //std::cout << "Text len " << text.length() << std::endl;
  entity.setPosition(x - (text.length() * 31), y);
  entity.setString(text);
  entity.setCharacterSize(size);
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
  entity.setCharacterSize(size);
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
  entity.setCharacterSize(size);
  entity.setColor(color);
  entity.setStyle(sf::Text::Regular);
  window.draw(entity);
}

void 		UI::printKeypad()
{
  std::vector<Key>		tmpPad = this->keypad.getKeypad();
  std::vector<Key>::iterator	it = tmpPad.end() - 1;

  while (it >= tmpPad.begin())
  {
    if (this->printKey(*it) == -1)
      return ;
    --it;
  }
}

int		UI::printKey(const Key tmp)
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
  this->printDefaultText(tmp.pos.x + 25, tmp.pos.y + 3, tmp.c, 45);
  return (0);
}

int		UI::printKey(const Key tmp, std::string hover)
{
  sf::Sprite    		sprite;
  sf::Texture   		texture;
  std::map<std::string, sf::Texture>::iterator it;

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
  this->printDefaultText(tmp.pos.x + 25, tmp.pos.y + 3, tmp.c, 45);
  return (0);
}

void 		UI::printElemList()
{
  std::vector<Elem>::iterator	it = this->elemList.begin();

  while (it != this->elemList.end())
  {
    if (this->printElem(*it) == -1)
      return ;
    ++it;
  }
}

int		UI::printElem(const Elem tmp)
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
  e.size.height = h;
  e.size.lenth = l;
  e.sprite = imgPath;
  return (e);
}

void 	UI::creatElemList()
{
  this->elemList.push_back(this->creatElem(0, 0, 800, 480, "./img/background.png"));
  this->elemList.push_back(this->creatElem(10, 10, 101, 35, "./img/logo_epipay.png"));
  this->elemList.push_back(this->creatElem(20, 90, 477, 92, "./img/priceRec.png"));
  this->elemList.push_back(this->creatElem(20, 165, 475, 178, "./img/billRec.png"));
}

Position	UI::getClickPos()
{
  sf::Event e = this->getEvent();
  Position	pos;

  if (e.type == sf::Event::MouseButtonPressed)
  {
    if (e.mouseButton.button == sf::Mouse::Left)
    {
      std::cout << e.mouseButton.x << std::endl;
      std::cout << e.mouseButton.y << std::endl;
      pos.x = e.mouseButton.x;
      pos.y = e.mouseButton.y;
    }
  }
  return (pos);
}

void 	UI::isClickable(Position mouse)
{
  std::vector<Key> tmpKey = this->keypad.getKeypad();
  std::vector<Key>::iterator it = tmpKey.begin();

  while (it != tmpKey.end())
  {
    if (mouse.y >= (*it).pos.y && mouse.y <= (*it).pos.y + (*it).size.lenth &&
     	mouse.x >= (*it).pos.x && mouse.x <= (*it).pos.x + (*it).size.height)
    {
      if (this->clean == 0)
      {
	this->ss.str("");
	this->clean = 1;
      }
      std::cout << "Click on " << (*it).c << std::endl;
      this->printKey(*it, (*it).hover);
      this->ss << (*it).c;
    }
    ++it;
  }
}

std::string	UI::getPrice() const
{
  std::string		s;

  s = ss.str();
  return (s);
};

void 	UI::clock()
{
  time_t 	rawtime;
  struct tm 	*timeinfo;
  char 		buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y\n    %I:%M",timeinfo);
  std::string str(buffer);
  this->printDefaultText(350, 5, str, 20, sf::Color::White);
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
    this->printElem(this->creatElem(750, 15, 31, 25,"./img/wifi.png"));
  else
    this->printElem(this->creatElem(760, 35, 31, 25,"./img/wifi_no.png"));
}