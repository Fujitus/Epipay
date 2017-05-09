//
// Created by costa_d on 07/05/17.
//

#ifndef EPIPAY_REGISTERUI_HH
#define EPIPAY_REGISTERUI_HH

# include <Key.hh>

class RegisterUi : public Key
{
  std::string	photoPath;
 public:
  RegisterUi(std::string);
  ~RegisterUi();
  std::vector<Button>	pad;
 public:
  void	creatKeypad();
  std::vector<Button> getKeypad() const;
};

#endif /* EPIPAY_REGISTERUI_HH */