#ifndef HIDLIBCONSTANTS_H
#define HIDLIBCONSTANTS_H

#endif // HIDLIBCONSTANTS_H

enum THIDMessageID
{
    HID_RECEIVER_IDLE = 0,
    HID_REMOTE_DATA = 1,
    HID_REMOTE_SET_DATA = 2,
    HID_RECEIVER_GET_UID = 3,
    HID_RECEIVER_SET_INTERACTIVE_MODE = 4,
    HID_RECEIVER_GET_INTERACTIVE_MODE = 5
};

enum RemoteCommand
{
    RF_ACK_IDLE = 0,
    RF_ACK = 1,
    RF_ACK_DATA = 2,
    RF_ACK_WAIT = 3,
    RF_ACK_TEXT_DATA_START = 4,
    RF_ACK_TEXT_DATA = 5,
    RF_ACK_TEXT_DATA_END = 6,
    RF_ACK_TEXT_DATA_CLEAR= 7,
    RF_ACK_TEXT_DATA_ERROR = 8,
    RF_ACK_IMAGE_DATA_START = 9,
    RF_ACK_IMAGE_DATA= 10,
    RF_ACK_IMAGE_DATA_END = 11,
    RF_ACK_IMAGE_DATA_CLEAR = 12,
    RF_ACK_IMAGE_DATA_ERROR = 13,
    RF_ACK_TAG_READ_SINGLE = 14,
    RF_ACK_TAG_READ_SERIAL = 15,
    RF_ACK_POWER_DOWN = 16,
    RF_ACK_DISPLAY_IMAGE = 17,
    RF_ACK_DISPLAY_TEXT = 18,
    RF_ACK_GET_BATT = 19,
    RF_ACK_GET_FW_VER = 20,
    RF_ACK_DISPLAY_LOGO = 21
};

enum RF_ACK_extensions
{
    CMD_NONE = 0,
    CMD_NO_ACTION = 1,
    CMD_SET_T2 = 2,
    CMD_CLR_T2 = 3,
    CMD_POWER_DOWN = 4,
    CMD_DISPLAY_CLEAR = 5,
    CMD_DISPLAY_CHAR = 6,
    CMD_DISPLAY_CHAR_DEF = 7,
    CMD_DISPLAY_CHAR_CLEAR = 8,
    CMD_DISPLAY_STRING = 9,
    CMD_DISPLAY_STRING_DEF = 10,
    CMD_DISPLAY_STRING_CLEAR = 11,
    CMD_LED_SCN = 12,
    CMD_LED_OFF = 13,
    CMD_LED_ON = 14,
    CMD_TAG_READ = 15,
    CMD_TAG_READ_SERIAL = 16,
    CMD_DISPLAY_LOGO = 17,
    CMD_WAIT = 18,
    CMD_LED_FLASH = 19
};
