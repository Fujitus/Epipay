//
// Created by costa_d on 03/06/17.
//

#ifndef EPIPAY_ACCOUNTINFO_HH
#define EPIPAY_ACCOUNTINFO_HH


#include <SFML/Window/Event.hpp>
#include "Key.hh"
#include "Ui.hh"

class AccountInfo : public Key
{
  std::vector<Button>	info;
 public:
  AccountInfo();
  ~AccountInfo();
  void			creatInfo();
  std::vector<Button> 	getInfo() const;
  void			printInfo(sf::Event, UI &);
};


#endif //EPIPAY_ACCOUNTINFO_HH
