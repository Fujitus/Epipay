//
// Created by costa_d on 20/05/17.
//

#ifndef EPIPAY_API_HH
# define EPIPAY_API_HH

#include <curl/curl.h>
#include <string>
#include <ostream>
#include <iostream>
#include <vector>
#include <cstring>
#include "IKey.hh"

class api
{
  std::string	apiUrl;
  std::string 	json;
 public:
  api(std::string);
  ~api();
  bool				put(std::string);
  bool				get(std::string);
  int 				updateAccount(Button, double, std::string);
  std::vector<std::string> 	getJson();
  void				CatToNewJson(double, std::vector<std::string> &);
};

static size_t 			getResponse(void *, std::size_t, std::size_t, void *);

#endif /* EPIPAY_API_HH */
