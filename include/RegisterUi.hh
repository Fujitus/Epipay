//
// Created by costa_d on 07/05/17.
//

#ifndef EPIPAY_REGISTERUI_HH
#define EPIPAY_REGISTERUI_HH

# include <Key.hh>
# include "Ui.hh"

class 	RegisterUi : public Key
{
  std::string		photoPath;
  std::vector<Button>	form;
 public:
  RegisterUi(std::string);
  ~RegisterUi();
  void			creatForm();
  std::vector<Button> 	getForm() const;
  void			setPhoto(std::string);
  void			newUser(sf::Event, UI &);
  std::string   	cardManager(UI &);
  std::string		updatePrivilege(UI &, Button);
  int			printPhotoIntra(const std::string file, UI &);
};

#endif /* EPIPAY_REGISTERUI_HH */
