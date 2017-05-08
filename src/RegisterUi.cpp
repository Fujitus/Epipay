//
// Created by costa_d on 07/05/17.
//

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
  this->pad.push_back(this->creatKey(546, 121, "", 143, 70, "./img/money-cadre.png", "", 0, 0, 0,  TileType::NONE));
  this->pad.push_back(this->creatKey(31, 256, "", 737, 3, "./img/barre_separation_gris-fonce.png", "", 0, 0, 0,  TileType::NONE));
  this->pad.push_back(this->creatKey(111, 90, "", 111, 131, "./img/photo-cadre.png", "", 0, 0, 0,  TileType::NONE));
  this->pad.push_back(this->creatKey(236, 99, "", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236 + 5, 99 + 2, TileType::INPUT));
  this->pad.push_back(this->creatKey(236, 99 + 28 + 15, "", 250, 28, "./img/cadre-texte-photo.png", "", 0, 236, 99 + 15  + 28 + 2, TileType::INPUT));
  this->pad.push_back(this->creatKey(246, 193, "USER", 11 + 15 + 5, 11, "./img/statut-on.png", "", 15, 246 + 15, 189, TileType::SELECTE));
  this->pad.push_back(this->creatKey(311, 193, "BDE", 11 + 15 + 4, 11, "./img/statut-off.png", "", 15, 311 + 15, 189, TileType::SELECTE));
  this->pad.push_back(this->creatKey(377, 193, "HUB", 11 + 15 + 4, 11, "./img/statut-off.png", "", 15, 377 + 15, 189, TileType::SELECTE));
  this->pad.push_back(this->creatKey(236, 99 + 28 + 28 + 15 + 15, "", 250, 28, "./img/cadre-texte-photo.png", "", 0, 0, 0,  TileType::NONE));
  this->pad.push_back(this->creatKey(751, 73, "", 32, 34, "./img/quit.png", "", 0, 0, 0, TileType::EXIT));
}

std::vector<Button>	RegisterUi::getKeypad() const
{
  return (this->pad);
}