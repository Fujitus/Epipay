//
// Created by costa_d on 20/05/17.
//

#ifndef EPIPAY_API_HH
# define EPIPAY_API_HH

# include <curl/curl.h>
# include <string>
# include <ostream>
# include <iostream>
# include <vector>
# include <cstring>
# include "IKey.hh"

# define APIURL "http://epipay.eu-3.evennode.com/"

class api
{
  std::string	apiUrl;
  std::string 	json;
  std::string	cmd = "ping -c 1 ";
  std::string	dns = "epipay.eu-3.evennode.com";
 public:
  api(std::string);
  ~api();
  ErrorType			put(std::string);
  ErrorType			post();
  ErrorType			get(std::string);
  ErrorType 			updateAccount(Button, double, std::string);
  std::vector<std::string> 	getJson();
  void				CatToNewJson(double, std::vector<std::string> &);
  ErrorType			makeJson(std::string, std::string, std::string, std::string);
};

static size_t 			getResponse(void *, std::size_t, std::size_t, void *);

#endif /* EPIPAY_API_HH */
