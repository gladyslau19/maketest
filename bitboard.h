#ifndef BITBOARD_H
#define BITBOARD_H

#include "MicroBit.h"
#include "mbed.h"
#include "ble/BLE.h"
#include "KeyboardService.h"
#include "MicroBitPin.h"
#include "examples_common.h"
#include "MicroBit.h"
#include "keymap.h"

class bitboard {
protected:
    KeyboardService* kbdServicePtr;
    const char* DEVICE_NAME;
    const char* SHORT_DEVICE_NAME;
    uint8_t Buffer;
public:
//    MicroBit &uBit;
    BLE &ble;
    bitboard(/**MicroBit &_uBit,**/ BLE &_ble, KeyboardService* _kbdServicePtr, const char* _DEVICE_NAME, const char* _SHORT_DEVICE_NAME);
    ~bitboard();

    void init();
//    void start_service();
//    void start_broadcast();
    void onDisconnect(const Gap::DisconnectionCallbackParams_t *params);
    void onConnect(const Gap::ConnectionCallbackParams_t *params);
    void onButtonA(MicroBitEvent e);
    void send_keypress();
    uint8_t get_keycode(char c);

};



#endif
