//
// Created by costa_d on 09/05/17.
//

#include <sstream>
#include <iomanip>
#include "NfcReader.hh"

NfcReader::NfcReader()
{
  this->cardId = "00:00:00:00:00:00";
  this->nmMifare.nmt = NMT_ISO14443A;
  this->nmMifare.nbr = NBR_106;
}

NfcReader::~NfcReader()
{
  nfc_close(this->pnd);
  nfc_exit(this->context);
}

int 	NfcReader::initNfcReader()
{
  nfc_init(&this->context);
  if (this->context == NULL)
    {
      std::cerr << "[ERROR] Unable to init libnfc" << std::endl;
      exit(-1);
    }
  if ((this->pnd = nfc_open(this->context, NULL)) == NULL)
    {
      std::cerr << "[ERROR] Unable to open NFC device." << std::endl;
      return (-1);
    }
  if (nfc_initiator_init(this->pnd) < 0)
    {
      nfc_perror(this->pnd, "nfc_initiator_init");
      return (-1);
    }
  std::cerr << "[OK] NFC Reader initialize" << std::endl;
  return (0);
}

void	NfcReader::toHex(const uint8_t *pbtData, const size_t szBytes)
{
  size_t  	szPos;
  std::stringstream	ss;

  for (szPos = 0; szPos < szBytes; szPos++)
    {
      ss << std::setfill ('0') << std::setw(2) << std::hex << (int)pbtData[szPos];
      if (szPos < szBytes - 1)
      	ss << ":";
    }
  this->cardId = ss.str();
  std::cout << ss.str() << std::endl;
}

int 	NfcReader::readCard()
{
  if (nfc_initiator_select_passive_target(this->pnd, this->nmMifare, NULL, 0, &this->nt) > 0)
    {
      this->toHex(this->nt.nti.nai.abtUid, this->nt.nti.nai.szUidLen);
      return (0);
    }
  return (-1);
}

std::string	NfcReader::getIdCard() const
{
  return (this->cardId);
}