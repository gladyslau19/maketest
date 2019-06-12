#include "bitboard.h"

namespace bitboard{

    BLEDevice ble;
    KeyboardService* kbdServicePtr;
    bitboard btboard(ble, kbdServicePtr);
    btboard.init();

    void send_string(uint8_t key_code){
        btboard.send_keypress(key_code);
    }
    void send_f_keys(uint8_t key_code){
        btboard.send_keypress(key_code);
    }
    void send_function_keys(uint8_t key_code){
        btboard.send_keypress(key_code);
    }
    void send_direction_keys(uint8_t key_code){
        btboard.send_keypress(key_code);
    }
    void send_volumn_keys(uint8_t key_code){
        btboard.send_keypress(key_code);
    }
}
