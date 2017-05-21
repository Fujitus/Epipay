//
// Created by costa_d on 20/05/17.
//

#include <sstream>
#include "api.hh"

api::api(std::string url)
{
  this->apiUrl = url;
}

api::~api()
{}

static size_t getResponse(void *contents, std::size_t size, std::size_t nmemb, void *userp)
{
  (static_cast<std::string*>(userp))->append((char*)contents, size * nmemb);
  return (size * nmemb);
}

bool 		api::get(std::string card_id)
{
  CURL *curl;
  CURLcode res;
  std::string url;

  curl = curl_easy_init();
  std::cout << "ID = " << card_id << std::endl;
  url = this->apiUrl + "api/people/" + card_id;
  std::cout << "URL = " << url << std::endl;
  if (curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponse);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->json);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      if (this->json == "[]" || this->json.length() == 0)
	return (false);
      std::cout << "API = " << this->json << std::endl;
      return (true);
    }
  return (false);
}

bool 		api::put(std::string card_id)
{
  CURL *curl;
  CURLcode res;
  struct curl_slist *json_struct = NULL;
  std::string url;

  std::cout << "ID = " << card_id << std::endl;
  url = this->apiUrl + "api/people/" + card_id;
  std::cout << "URL = " << url << std::endl;
  json_struct = curl_slist_append(json_struct, "Content-Type: application/json");
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, this->json.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, json_struct);
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
  curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  curl_slist_free_all(json_struct);
}

int            api::updateAccount(Button action, double balance, std::string card_id)
{
  std::vector<std::string>	newJson;
  double 			price;
  std::string			tmp;

  newJson = this->getJson();
  for (std::vector<std::string>::iterator it = newJson.begin(); it != newJson.end(); ++it)
    {
      std::cout << *it << std::endl;
      std::string token = (*it).substr(0, (*it).find(':'));
      if (token == "\"balance\"")
	tmp = (*it).substr((*it).find(':') + 1, (*it).length());
    }
  if (action.c == "Add Money")
    price = std::atof(tmp.c_str()) + balance;
  else if (action.c == "Pay")
    price = std::atof(tmp.c_str()) - balance;
  else
    price = balance;
  std::cout << "Price = " << price << std::endl;
  this->creatJson(price, newJson);
  this->put(card_id);
}

std::string		api::creatJson(double price, std::vector<std::string> newJson)
{
  std::stringstream ss;

  this->json.clear();
  for (std::vector<std::string>::iterator it = newJson.begin(); it != newJson.end(); ++it)
    {
      std::string token = (*it).substr(0, (*it).find(':'));
      if (token == "\"balance\"")
	{
	  ss << price;
	  (*it) = "\"balance\":" + ss.str();
	}
    }
  json += "{";
  for (std::vector<std::string>::iterator it = newJson.begin(); it != newJson.end(); ++it)
    {
      this->json += (*it);
      if (it != newJson.end() - 1)
	this->json += ",";
    }
  this->json += "}";
  std::cout << "New json = " << this->json << std::endl;
}

std::vector<std::string>		api::getJson()
{
  std::size_t 			curs = 0;
  std::size_t 			last = 2;
  std::vector<std::string>	tab;

  while (curs < this->json.length())
    {
      if (this->json.c_str()[curs] == ',' || curs == this->json.length() -2)
	{
	  char 	buff[curs - last + 1];
	  memset(buff, '\0', curs - last + 1);
	  this->json.copy((char *)buff, curs - last, last);
	  tab.push_back(std::string(buff));
	  last = curs + 1;
	}
      curs++;
    }
  return (tab);
}