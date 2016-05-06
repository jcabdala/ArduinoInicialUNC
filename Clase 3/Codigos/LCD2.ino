// Demo of a Keypad LCD Shield
// Common design sold by DFRobot, various vendors on eBay etc

#include <LiquidCrystal.h>
#include <DFR_LCD_Keypad.h>

//---------------------------------------------
int         keyPin = 0;
int         localKey = 0;
String      keyString;
/*
** Pin assignments for DFRobot LCD Keypad Shield
**   LiquidCrystal(8, 9, 4, 5, 6, 7);
** DFR_Keypad class use these as default pins
*/
DFR_Keypad  keypad(16, 2, keyPin, 3);

void setup()
{
    keypad.setRepeatMode(false);

    Serial.begin(9600);
    keypad.print(F("Key Grab v1.0"));
    keypad.setCursor(0, 1);
    keypad.print(F("(c) 2013 - f1rmb"));
    delay(1000);

    keypad.clear();
    keypad.setCursor(0, 0);
    keypad.print(F("Press a Key:"));
    keypad.setCursor(0, 1);
    /*
    ** OPTIONAL
    ** keypad.setRate(x);
    ** Sets the sample rate at once every x milliseconds.
    **
    ** Default: 100ms
    */
    //keypad.setRefreshRate(200);

    /*
    ** OPTIONAL
    ** keypad.setLongPressThreshold(x);
    ** Sets the threshold value for long press key state
    **
    ** Default: 800ms
    */
    keypad.setLongPressThreshold(1000);
}

void loop()
{
    /*
    ** keypad.getKey();
    ** Grabs the current key.
    ** Returns a non-zero integer corresponding to the pressed key,
    **   OR
    ** Returns KEY_NO for no keys pressed,
    **   OR
    ** Returns KEY_WAIT (sample wait) when no key is available to be sampled.
    */
    localKey = keypad.getKey();

    if (localKey != KEY_WAIT)
    {
        keypad.clear();
        keypad.setCursor(0, 0);
        keypad.print(F("Press a Key:"));
        keypad.setCursor(0, 1);
       
        switch (localKey)
        {
            case KEY_WAIT:
                keyString = "WAIT";
                break;
            case KEY_NO:
                keyString = "NO-KEY";
                break;
            case KEY_UP:
                keyString = "Arriba";
                //keypad.display();
                break;
            case KEY_DOWN:
                keyString = "Abajo";
                //keypad.noDisplay();
                break;
            case KEY_LEFT:
                keyString = "Izquierda";
                break;
            case KEY_RIGHT:
                keyString = "Derecha";
                break;
            case KEY_SELECT:
                keyString = "Seleccion";
                break;
            default:
                keyString = "UNK";
        }

        keypad.print(keyString);
    }
}