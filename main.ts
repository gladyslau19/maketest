/**
 * Button events
 */
enum BBEvents {
    released = 0,
    pressed = 1
}

/**
  * Enumeration of buttons
  */
enum BBButtons {
    //% block="button1"
    Button1 = 0,
    //% block="button2"
    Button2 = 1,
    //% block="button3"
    Button3 = 2,
    //% block="button4"
    Button4 = 3,
}

/**
  * Enumeration of functional keys
  */
enum BBFuncKeys {
    //% block="enter"
    Enter = 0,
    //% block="space"
    Space = 1,
    //% block="backspace"
    Backspace = 2,
    //% block="tab"
    Tab = 3,
    //% block="escape"
    Escape = 4,
    //% block="capslock"
    CapsLock = 5,
}

/**
  * Enumeration of F keys
  */
enum BBFKeys {
    //% block="F1"
    F1 = 0,
    //% block="F2"
    F2 = 1,
    //% block="F3"
    F3 = 2,
    //% block="F4"
    F4 = 3,
    //% block="F5"
    F5 = 4,
    //% block="F6"
    F6 = 5,
    //% block="F7"
    F7 = 6,
    //% block="F8"
    F8 = 7,
    //% block="F9"
    F9 = 8,
    //% block="F10"
    F10 = 9,
    //% block="F11"
    F11 = 10,
    //% block="F12"
    F12 = 11,
}


/**
  * Enumeration of functional keys
  */
enum BBDirections {
    //% block="Up"
    Up = 0,
    //% block="Down"
    Down = 1,
    //% block="Left"
    Left = 2,
    //% block="Right"
    Right = 3,
    //% block="PageUp"
    PageUp = 4,
    //% block="PageDown"
    PageDown = 5,
}

/**
  * Enumeration of volume keys
  */
enum BBVolume {
    //% block="Up"
    Up = 0,
    //% block="Down"
    Down = 1,
    //% block="Mute"
    Mute = 2,
}

//% weight=10 color=#F47442 icon="\uf11b"
namespace bitboard
{
    //% weight=100
    //% blockId=tb_onevent 
    //% block="When touch pad %button| is %event"
    //% button.fieldEditor="gridpicker" button.fieldOptions.columns=4
    //% event.fieldEditor="gridpicker" event.fieldOptions.columns=2
    //% subcategory=Inputs
    //% group=Inputs
    export function onEvent(button: BBButtons, event: BBEvents, handler: Action)
    {
    }

    /**
      *	Send string through BLE
      */
    //% block="send string %text"
    //% subcategory=Inputs
    //% group=Inputs
    //% text.defl="enter string"
    export function sendstr(text: string){
    //send string
    }

    /**
      *	Send functional keys through BLE
      */
    //% block="send %funckey"
    //% funckey.fieldEditor="gridpicker" funckey.fieldOptions.columns=3
    //% subcategory=Inputs
    //% group=Inputs
    export function sendfunckey(funckey: BBFuncKeys){
        switch (funckey)
        {
            case BBFuncKeys.Enter: bitboard.send_function_keys(0x04);
            case BBFuncKeys.Space: bitboard.send_function_keys(0x2c);
            case BBFuncKeys.Backspace: bitboard.send_function_keys(0x2a);
            case BBFuncKeys.Tab: bitboard.send_function_keys(0x2b);
            case BBFuncKeys.Escape: bitboard.send_function_keys(0x29);
            case BBFuncKeys.CapsLock: bitboard.send_function_keys(0x39);
	    default: NULL;
        }
    }

    /**
      *	Send F keys through BLE
      */
    //% block="send %fkey"
    //% fkey.fieldEditor="gridpicker" fkey.fieldOptions.columns=4
    //% subcategory=Inputs
    //% group=Inputs
    export function sendfkey(fkey: BBFKeys){
    //send F Keys
    }

    /**
      *	Send functional keys through BLE
      */
    //% block="go %directions"
    //% directions.fieldEditor="gridpicker" directions.fieldOptions.columns=3
    //% subcategory=Inputs
    //% group=Inputs
    export function godirections(directions: BBDirections){
    //send directions
    }

    /**
      *	Adjusting volume
      */
    //% block="Turn volume %volume"
    //% volume.fieldEditor="gridpicker" volume.fieldOptions.columns=3
    //% subcategory=Inputs
    //% group=Inputs
    export function adjustvolume(volume: BBVolume){
    //adjust volume
    }

    ////% block="pause $ms"
    ////% ms.shadow="timePicker"
    //export function pause(ms: number) {
    //
    //}
}
