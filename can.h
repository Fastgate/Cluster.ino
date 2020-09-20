#ifndef CAN_H_
#define CAN_H_

#include <carduinotest.h>
#include <FlexCAN_T4.h>

static SerialPacket canInitError(0x65, 0x30);

static SerialPacket canNotInitializedError(0x65, 0x31);
static SerialPacket canTransactionError(0x65, 0x32);

static SerialPacket canSendBufferFull(0x65, 0x33);
static SerialPacket canSendTimeout(0x65, 0x34);

static SerialPacket canControlError(0x65, 0x35);

class Can {
public:
    Can(Stream * serial) {
        this->sourceCan = new FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16>();
        this->targetCan = new FlexCAN_T4<CAN0, RX_SIZE_256, TX_SIZE_16>();
        this->serial = serial;
    }
    ~Can() {
        //delete this->sourceCan;
        //delete this->targetCan;
        for (int i = 0; i < this->canIdCount; i++) {
            this->canIds[i] = 0;
        }
    }
    boolean setup(uint32_t sourceBaudRate, uint32_t targetBaudRate) {
        this->sourceCan->begin();
        this->sourceCan->setBaudRate(sourceBaudRate);
        this->targetCan->begin();
        this->targetCan->setBaudRate(targetBaudRate);
        
        this->isInitialized = true;
        return this->isInitialized;
    }

    void startSniffer() {
        this->isSniffing = true;
    }

    void stopSniffer() {
        this->isSniffing = false;
    }

    bool addCanId(uint32_t canId) {
        this->removeCanId(canId);
      
        if (this->canIdCount < 50) {
            this->canIds[this->canIdCount] = canId;
            this->canIdCount++;
            return true;
        }

        return false;
    }

    void removeCanId(uint32_t canId) {
        for (int index = 0; index < this->canIdCount; index++) {
            if (this->canIds[index] == canId) {
                for (int moveIndex = index; moveIndex < this->canIdCount - 1; moveIndex++) {
                    this->canIds[moveIndex] = this->canIds[moveIndex + 1];
                }
                this->canIdCount--;
            }
        }
    }

    void update(void (*canCallback)(const CAN_message_t &message)) {
        if (!this->isInitialized) {
            canNotInitializedError.serialize(this->serial, 1000);
            return;
        }
        if (this->sourceCan->read(this->msg)) {
          if (this->msg.id == 0x0233) 
          {
           Serial.println(this->msg.buf[3], HEX);
          }
          if (this->isSniffing) {
            this->sniff(this->msg);
          }

          for (uint8_t i = 0; i < this->canIdCount; i++) {
            if (this->canIds[i] == this->msg.id) {
            //Serial.println(this->msg.id, HEX);
            this->write(this->msg);
            //return;
          }
          }

          canCallback(this->msg);
        }
    }

    template<uint8_t BYTE_INDEX, uint8_t BIT_MASK, uint8_t COMPARE_VALUE>
    static bool readFlag(uint8_t * data) {
        return (data[BYTE_INDEX] & BIT_MASK) == COMPARE_VALUE;
    }
    template<uint8_t BYTE_INDEX, uint8_t BIT_MASK>
    static inline bool readFlag(uint8_t * data) {
        return Can::readFlag<BYTE_INDEX, BIT_MASK, BIT_MASK>(data);
    }

    void write(const CAN_message_t &message) {
        if (!this->isInitialized) {
            canNotInitializedError.serialize(this->serial, 1000);
            return;
        }

        this->targetCan->write(message);
    }
private:
    FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> * sourceCan;
    FlexCAN_T4<CAN0, RX_SIZE_256, TX_SIZE_16> * targetCan;
    CAN_message_t msg;

    Stream * serial;
    uint32_t canIds[50];
    uint8_t canIdCount = 0;

    boolean isInitialized = false;
    boolean isSniffing = false;

    void sniff(const CAN_message_t &message) {
        uint32_t flippedCanId = htonl(message.id);
        this->serial->write("{");
        this->serial->write(0x62);
        this->serial->write(0x6d);
        this->serial->write(message.len + 0x04);
        this->serial->write((byte*)&flippedCanId, sizeof(message.id));
        for (uint8_t i = 0; i < message.len; i++) {
            this->serial->write(message.buf[i]);
        }
        this->serial->write("}");
    }
};

#endif /* CAN_H_ */
