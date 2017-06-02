//
// Created by costa_d on 20/05/17.
//

#include <sstream>
#include "api.hh"

api::api(std::string url)
{
  this->apiUrl = url;
  this->json = "";
}

api::~api()
{}

static size_t getResponse(void *contents, std::size_t size, std::size_t nmemb, void *userp)
{
  (static_cast<std::string*>(userp))->append((char*)contents, size * nmemb);
  return (size * nmemb);
}

ErrorType 	api::get(std::string card_id)
{
  CURL          *curl;
  std::string   url;

  curl = curl_easy_init();
  if (!curl)
    return (ErrorType::API);
  std::cout << "ID = " << card_id << std::endl;
  url = this->apiUrl + "api/people/" + card_id;
  std::cout << "URL = " << url << std::endl;
  if (curl_easy_setopt(curl, CURLOPT_URL, url.c_str()) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponse) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->json) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_perform(curl) != CURLE_OK)
    return (ErrorType::API);
  curl_easy_cleanup(curl);
  if (this->json == "[]" || this->json.length() == 0)
    return (ErrorType::API);
  std::cout << "API = " << this->json << std::endl;
  return (ErrorType::NONE);
}

ErrorType	     api::put(std::string card_id)
{
  CURL               *curl;
  struct curl_slist  *json_struct = NULL;
  std::string        url;

  std::cout << "ID = " << card_id << std::endl;
  url = this->apiUrl + "api/people/" + card_id;
  std::cout << "URL = " << url << std::endl;
  json_struct = curl_slist_append(json_struct, "Content-Type: application/json");
  curl = curl_easy_init();
  if (!curl)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_URL, url.c_str()) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_POSTFIELDS, this->json.c_str()) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.38.0") != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_HTTPHEADER, json_struct) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT") != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_perform(curl) != CURLE_OK)
    return (ErrorType::API);
  curl_easy_cleanup(curl);
  curl_slist_free_all(json_struct);
  return (ErrorType::NONE);
}

ErrorType 	    api::post()
{
  CURL              *curl;
  struct curl_slist *json_struct = NULL;
  std::string       url;

  url = this->apiUrl + "api/people/";
  std::cout << "URL = " << url << std::endl;
  json_struct = curl_slist_append(json_struct, "Content-Type: application/json");
  curl = curl_easy_init();
  if (!curl)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_URL, url.c_str()) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_POSTFIELDS, this->json.c_str()) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.38.0") != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_HTTPHEADER, json_struct) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST") != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L) != CURLE_OK)
    return (ErrorType::API);
  if (curl_easy_perform(curl) != CURLE_OK)
    return (ErrorType::API);
  curl_easy_cleanup(curl);
  curl_slist_free_all(json_struct);
  return (ErrorType::NONE);
}

ErrorType           	api::updateAccount(Button action, double balance, std::string card_id)
{
  std::vector<std::string>	newJson;
  double 			price;
  std::string			tmp;
  ErrorType 			error;

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
  std::cout << "New Balance = " << price << std::endl;
  this->CatToNewJson(price, newJson);
  if ((error = this->put(card_id)) != ErrorType::NONE)
    return (error);
  return (error);
}

void		api::CatToNewJson(double price, std::vector<std::string> &newJson)
{
  std::stringstream ss;

  this->json = "{";
  for (std::vector<std::string>::iterator it = newJson.begin(); it != newJson.end(); ++it)
    {
      std::string token = (*it).substr(0, (*it).find(':'));
      if (token == "\"balance\"")
	{
	  ss << price;
	  (*it) = "\"balance\":" + ss.str();
	}
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

ErrorType	api::makeJson(std::string email, std::string cardId, std::string balance, std::string privilege)
{
  if (email.find("@epitech.eu"))
    return (ErrorType::BADEMAIL);
  if (email == "<Get Card ID>")
    return (ErrorType::NOID);
  this->json = "{";
  this->json += "\"email\":";
  this->json += "\"" + email + "\",";
  this->json += "\"card_id\":";
  this->json += "\"" + cardId + "\",";
  this->json += "\"privilege\":";
  this->json += "\"" + privilege + "\",";
  this->json += "\"balance\":";
  this->json += "\"" + balance + "\"";
  this->json += "}";
  std::cout << "New json = " << this->json << std::endl;
  return (ErrorType::NONE);
}