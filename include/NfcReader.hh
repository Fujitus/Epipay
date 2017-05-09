//
// Created by costa_d on 09/05/17.
//

#ifndef EPIPAY_NFCREADER_HH
# define EPIPAY_NFCREADER_HH

# include <iostream>
# include <nfc/nfc-types.h>
# include <nfc/nfc.h>

class NfcReader
{
  std::string			cardId;
  nfc_device 			*pnd;
  nfc_target 			nt;
  nfc_context 			*context;
  nfc_modulation 		nmMifare;
 public:
  NfcReader();
  ~NfcReader();
  int 				initNfcReader();
  int				readCard();
  void				toHex(const uint8_t*, const size_t);
  std::string			getIdCard() const;
};


#endif /* EPIPAY_NFCREADER_HH */
