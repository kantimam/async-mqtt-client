#pragma once

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals {
class PubCompPacket : public Packet {
 public:
  explicit PubCompPacket(ParsingInformation* parsingInformation, OnPubCompCallback callback);
  ~PubCompPacket();

  void parseVariableHeader(const char* data, size_t* currentBytePosition);
  void parsePayload(const char* data, size_t* currentBytePosition);

 private:
  ParsingInformation* _parsingInformation;
  OnPubCompCallback _callback;

  uint8_t _bytePosition;
  char _packetIdMsb;
  uint16_t _packetId;
};
}  // namespace AsyncMqttClientInternals