#pragma once
#include <EEPROM.h>

class EEPROMManager
{
private:
    size_t size;

public:
    EEPROMManager(size_t _size) : size(_size) {}

    bool begin()
    {
        return EEPROM.begin(size);
    }

    void writeByte(int address, uint8_t value)
    {
        EEPROM.writeUChar(address, value);
        EEPROM.commit();
    }

    uint8_t readByte(int address) const
    {
        return EEPROM.readUChar(address);
    }

    void writeInt(int address, int value)
    {
        EEPROM.writeInt(address, value);
        EEPROM.commit();
    }

    int readInt(int address) const
    {
        return EEPROM.readInt(address);
    }

    void writeFloat(int address, float value)
    {
        EEPROM.writeFloat(address, value);
        EEPROM.commit();
    }

    float readFloat(int address) const
    {
        return EEPROM.readFloat(address);
    }

    void writeString(int address, const String &str)
    {
        EEPROM.writeString(address, str);
        EEPROM.commit();
    }

    String readString(int address) const
    {
        return EEPROM.readString(address);
    }

    template <typename T>
    void writeObject(int address, const T &obj)
    {
        EEPROM.put(address, obj);
        EEPROM.commit();
    }

    template <typename T>
    T readObject(int address) const
    {
        T obj;
        EEPROM.get(address, obj);
        return obj;
    }
};
