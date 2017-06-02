//
// Key.hpp for Epipay in /home/costa_d/Documents/Epipay/Key.hpp
//
// Made by Arnaud Costa
// Login   <costa_d@epitech.net>
//
// Started on mer. avr. 26 17:53:46 2017 Arnaud Costa
// Last update mer. avr. 26 17:53:46 2017 Arnaud Costa
//

#ifndef EPIPAY_KEY_HH
#define EPIPAY_KEY_HH

#include "IKey.hh"

class Key : public IKey
{;
 public:
  Key();
  ~Key();
  virtual Button 	creatKey(std::size_t, std::size_t, const char, std::size_t, std::size_t,
					 std::string, std::string, std::size_t, std::size_t, std::size_t, TileType);
  virtual Button 	creatKey(std::size_t, std::size_t, std::string, std::size_t, std::size_t,
					 std::string, std::string, std::size_t, std::size_t, std::size_t, TileType);
};


#endif /* EPIPAY_KEY_HH */
