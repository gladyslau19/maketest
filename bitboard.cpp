#include "bitboard.h"

bitboard::bitboard(/**MicroBit &_uBit,**/ BLE &_ble, KeyboardService* _kbdServicePtr, const char* _DEVICE_NAME, const char* _SHORT_DEVICE_NAME): /**uBit(_uBit),**/ ble(_ble), kbdServicePtr(_kbdServicePtr), DEVICE_NAME(_DEVICE_NAME), SHORT_DEVICE_NAME(_SHORT_DEVICE_NAME){
    Buffer = 0; //might change data type to allow for multi keypress
    }

bitboard::~bitboard(){
    delete DEVICE_NAME;
    delete SHORT_DEVICE_NAME;
    }

void bitboard::init(){
//    uBit.init();
//    uBit.serial.send("uBit init...\r\n");
//    uBit.serial.send("BLE init...\r\n");
    ble.init();
    
    ble.gap().onDisconnection(this, &bitboard::onDisconnect);
    ble.gap().onConnection(this, &bitboard::onConnect);
//    uBit.serial.send("Security init...\r\n");
    initializeSecurity(ble);
    
    KeyboardService kbdService(ble);
    kbdServicePtr = &kbdService;
//    uBit.serial.send("HOGP init...\r\n");
    initializeHOGP(ble);
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::KEYBOARD);
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::SHORTENED_LOCAL_NAME, (uint8_t *)SHORT_DEVICE_NAME, sizeof(SHORT_DEVICE_NAME));
    ble.gap().setDeviceName((const uint8_t *)DEVICE_NAME);
//    uBit.serial.send("advertising...\r\n");
    ble.gap().startAdvertising();
    }

void bitboard::onDisconnect(const Gap::DisconnectionCallbackParams_t *params){
    ble.gap().startAdvertising(); // restart advertising
//    uBit.serial.send("Disconnected, advertising...\r\n");
    }

void bitboard::onConnect(const Gap::ConnectionCallbackParams_t *params){
//    uBit.serial.send("Connected...\r\n");
    }

void bitboard::onButtonA(MicroBitEvent e){
//    uBit.display.print("A");
//    uBit.serial.send("Button A pressed");
//    uBit.serial.send(e.value);
    }

void bitboard::send_keypress(){
    inputReportData[0] = 0;
    inputReportData[2] = Buffer;
    kbdServicePtr->send(inputReportData);
    kbdServicePtr->send(emptyInputReportData);
    wait(0.1);
    }
uint8_t bitboard::get_keycode(char c){
      switch (c){
        case 'A':
        case 'a':
            return 0x04;
        case 'B':
        case 'b':
            return 0x05;
        case 'C':
        case 'c':
            return 0x06;
        case 'D':
        case 'd':
            return 0x07;
        case 'E':
        case 'e':
            return 0x08;
        case 'F':
        case 'f':
            return 0x09;
        case 'G':
        case 'g':
            return 0x0a;
        case 'H':
        case 'h':
            return 0x0b;
        case 'I':
        case 'i':
            return 0x0c;
        case 'J':
        case 'j':
            return 0x0d;
        case 'K':
        case 'k':
            return 0x0e;
        case 'L':
        case 'l':
            return 0x0f;
        case 'M':
        case 'm':
            return 0x10;
        case 'N':
        case 'n':
            return 0x11;
        case 'O':
        case 'o':
            return 0x12;
        case 'P':
        case 'p':
            return 0x13;
        case 'Q':
        case 'q':
            return 0x14;
        case 'R':
        case 'r':
            return 0x15;
        case 'S':
        case 's':
            return 0x16;
        case 'T':
        case 't':
            return 0x17;
        case 'U':
        case 'u':
            return 0x18;
        case 'V':
        case 'v':
            return 0x19;
        case 'W':
        case 'w':
            return 0x1a;
        case 'X':
        case 'x':
            return 0x1b;
        case 'Y':
        case 'y':
            return 0x1c;
        case 'Z':
        case 'z':
            return 0x1d;
        case '!':
        case '1':
            return 0x1e;
        case '@':
        case '2':
            return 0x1f;
        case '#':
        case '3':
            return 0x20;
        case '$':
        case '4':
            return 0x21;
        case '%':
        case '5':
            return 0x22;
        case '^':
        case '6':
            return 0x23;
        case '&':
        case '7':
            return 0x24;
        case '*':
        case '8':
            return 0x25;
        case '(':
        case '9':
            return 0x26;
        case ')':
        case '0':
            return 0x27;
        case '\n': // LF
            return 0x28;
        case '\b': // BS
            return 0x2a;
        case '\t': // TAB
            return 0x2b;
        case ' ':
            return 0x2c;
        case '_':
        case '-':
            return 0x2d;
        case '+':
        case '=':
            return 0x2e;
        case '{':
        case '[':
            return 0x2f;
        case '}':
        case ']':
            return 0x30;
        case '|':
        case '\\':
            return 0x31;
        case ':':
        case ';':
            return 0x33;
        case '"':
        case '\'':
            return 0x34;
        case '~':
        case '`':
            return 0x35;
        case '<':
        case ',':
            return 0x36;
        case '>':
        case '.':
            return 0x37;
        case '?':
        case '/':
            return 0x38;
        default:
            return 0;
    }
}
