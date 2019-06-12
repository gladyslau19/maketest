#ifndef BITBOARD_H
#define BITBOARD_H

#include "MicroBit.h"
#include "mbed.h"
#include "ble/BLE.h"
#include "inc/KeyboardService.h"
#include "MicroBitPin.h"
#include "inc/examples_common.h"
#include "MicroBit.h"

class bitboard {
protected:
    KeyboardService* kbdServicePtr;
    const char* DEVICE_NAME;
    const char* SHORT_DEVICE_NAME;
    uint8_t Buffer;
public:
//    MicroBit &uBit;
    BLE &ble;
    bitboard(/**MicroBit &_uBit,**/ BLE &_ble, KeyboardService* _kbdServicePtr);
    ~bitboard();

    void init();
//    void start_service();
//    void start_broadcast();
    void onDisconnect(const Gap::DisconnectionCallbackParams_t *params);
    void onConnect(const Gap::ConnectionCallbackParams_t *params);
    void onButtonA(MicroBitEvent e);
    void send_keypress(uint8_t key_code);
    uint8_t get_keycode(char c);

};



#endif
