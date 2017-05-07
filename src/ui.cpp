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
  this->printDefaultText(tmp.textPos.x, tmp.textPos.y, tmp.c, tmp.fontSize);
  return (0);
}

int		UI::printButton(const Button tmp, std::string hover)
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
  this->UiList.push_back(this->creatElem(10, 10, 101, 35, "./img/logo_epipay.png"));
  this->UiList.push_back(this->creatElem(20, 90, 477, 92, "./img/priceRec.png"));
  this->UiList.push_back(this->creatElem(20, 165, 475, 178, "./img/billRec.png"));
}

void 	UI::creatSmalUiList()
{
  this->SmalUiList.push_back(this->creatElem(0, 0, 800, 480, "./img/background.png"));
  this->SmalUiList.push_back(this->creatElem(10, 10, 101, 35, "./img/logo_epipay.png"));
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
          pos.x = static_cast<std::size_t >(e.mouseButton.x);
          pos.y = static_cast<std::size_t >(e.mouseButton.y);
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
            if ((*it).c == "<-")
              this->price.pop_back();
            else
              this->price += (*it).c;
          }
        std::cout << "{CLICK FUNC} Click on " << (*it).c << std::endl;
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
    this->printUiElem(this->creatElem(750, 15, 31, 25,"./img/wifi.png"));
  else
    this->printUiElem(this->creatElem(760, 35, 31, 25,"./img/wifi_no.png"));
}

void    UI::actionView(Button button, std::string price)
{
  sf::RectangleShape  rectangle(sf::Vector2f(300, 150));
  std::size_t         balnce = std::atof(this->price.c_str());

  rectangle.setFillColor(sf::Color::White);
  rectangle.setPosition(250, 100);
  this->window.draw(rectangle);\
  this->printDefaultText(378 - button.c.length() * 2, 108, button.c, 25);
  if (price == "0.0")
    {
      this->printDefaultText(320, 138, "Error no price define", 20);
      this->display();
      sleep(2);
      return ;
    }
  this->printDefaultText(280, 138, "Waiting API for update acount", 20);
  this->display();
  while (42)
    {
      std::cout << "Waiting API " << balnce << std::endl;
    }
  this->clear();
}

void    UI::newUser(sf::Event event)
{
  Keyboard	keyboard;
  Button        tmp;

  this->clear();
  while (tmp.type != TileType::EXIT)
    {
      this->printUiList(this->SmalUiList);
      this->printButtonList(keyboard.getKeypad());
      while (this->window.pollEvent(event))
        {
          tmp = this->isClickable(this->getClickPos(event), keyboard.getKeypad());
            if (tmp.type != TileType::NONE)
              std::cout << "{MAIN} click on = " << tmp.c << std::endl;
        }
      this->display();
      usleep(10);
      this->clear();
    }
}

