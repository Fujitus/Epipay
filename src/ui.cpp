//
// ui.cpp.cpp for Epipay in /home/costa_d/Documents/Epipay/ui.cpp.cpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mar. avr. 18 10:08:39 2017 Arnaud Costa
// Last update mar. avr. 18 10:08:39 2017 Arnaud Costa
//

#include <sstream>
#include "ui.hh"

UI::UI()
{}

UI::~UI()
{}

void	UI::open()
{
  sf::RectangleShape    rectangle(sf::Vector2f(800, 480));

  this->window.create(sf::VideoMode(800, 480), "EpiPay");
  rectangle.setSize(sf::Vector2f(800, 480));
  rectangle.setFillColor(sf::Color(150,150,150));
  this->window.draw(rectangle);
}

void	UI::close()
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

sf::Event	UI::getEvent()
{
  sf::Event	event;

  while (window.pollEvent(event))
    return (event);
}

int		UI::loadFiles()
{
  if (!this->font.loadFromFile("./font/default.ttf"))
    {
      std::cerr << "[ ERROR ] can't open font"<< std::endl;
      return (-1);
    }
  return (0);
}

void 		UI::printText(std::size_t x, std::size_t y,
				  const std::string text, std::size_t size)
{
  sf::Text entity;

  entity.setFont(this->font);
  entity.setPosition(x, y);
  entity.setString(text);
  entity.setCharacterSize(size);
  entity.setColor(sf::Color::Green);
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
      exit(84);
    --it;
  }
}

int		UI::printKey(const Key tmp)
{
  sf::Sprite    		sprite;
  sf::Texture   		texture;

  if (!texture.loadFromFile((tmp.sprite.c_str()), sf::IntRect(0, 0, 64, 64)))
    return (-1);
  sprite.setTexture(texture);
  sprite.setPosition(tmp.pos.x, tmp.pos.y);
  this->window.draw(sprite);
  this->printText(tmp.pos.x + 22, tmp.pos.y + 2, tmp.c, 45);
  return (0);
}