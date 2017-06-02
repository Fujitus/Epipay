//
// Created by costa_d on 07/05/17.
//

#ifndef EPIPAY_REGISTERUI_HH
#define EPIPAY_REGISTERUI_HH

# include <Key.hh>
# include "Ui.hh"

class RegisterUi : public Key
{
  std::string	photoPath;
 public:
  RegisterUi(std::string);
  ~RegisterUi();
  std::vector<Button>	form;
 public:
  void			creatKeypad();
  std::vector<Button> 	getForm() const;
  void			newUser(sf::Event, UI &);
  std::string   	cardManager(UI &);
};

#endif /* EPIPAY_REGISTERUI_HH */
