//
// Created by costa_d on 09/05/17.
//

#include <sstream>
#include <iomanip>
#include "TileType.hh"
#include "NfcReader.hh"

NfcReader::NfcReader()
{
  this->cardId = "00:00:00:00:00:00";
  this->nmMifare.nmt = NMT_ISO14443A;
  this->nmMifare.nbr = NBR_106;
}

NfcReader::~NfcReader()
{
//  if (this->pnd)
//    nfc_close(this->pnd);
//  if (this->context)
//    nfc_exit(this->context);
}

ErrorType 	NfcReader::initNfcReader()
{
  nfc_init(&this->context);
  if (this->context == NULL)
    {
      std::cerr << "[ERROR] Unable to init libnfc" << std::endl;
      exit(ErrorType::NFC);
    }
  if ((this->pnd = nfc_open(this->context, NULL)) == NULL)
    {
      std::cerr << "[ERROR] Unable to open NFC device." << std::endl;
      return (ErrorType::NFC);
    }
  if (nfc_initiator_init(this->pnd) < 0)
    {
      nfc_perror(this->pnd, "nfc_initiator_init");
      return (ErrorType::NFC);
    }
  return (ErrorType::NONE);
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
  std::cout << "NFC "<< ss.str() << std::endl;
}

ErrorType 	NfcReader::readCard()
{
  if (nfc_initiator_select_passive_target(this->pnd, this->nmMifare, NULL, 0, &this->nt) > 0)
    {
      this->toHex(this->nt.nti.nai.abtUid, this->nt.nti.nai.szUidLen);
      return (ErrorType::NONE);
    }
  return (ErrorType::NFC);
}

std::string	NfcReader::getIdCard() const
{
  return (this->cardId);
}