#pragma once 
#include <core/shared/interfaces/data_provider.h>
#include <core/device_configuration/data_transfer_objects/voltage.h>
#include <core/device_configuration/data_transfer_objects/voltage_list.h>
#include <infrastructure/persistence/shared/EEPROM_manager.h>

class VoltageProvider : public DataProvider<Voltage, VoltageList>
{
private:
    VoltageList element_list;
    EEPROMManager &eeprom_manager;
    int memory_address_line_machine[4] = {10, 20, 30, 40};
    int memory_address_shade_machine[4] = {50, 60, 70, 80};

public:
    explicit VoltageProvider(EEPROMManager &memory) : eeprom_manager(memory) {}

    void begin() { load(); }
    void persist(const Voltage &volt) override
    {
        if (volt.getElement() != NONE)
            return;

        int addr = (volt.getType() == LINE)
                       ? memory_address_line_machine[volt.getElement()]
                       : memory_address_shade_machine[volt.getElement()];

        if (volt.getType() == LINE && element_list.getLine().updateByIndex(volt.getElement(), volt.getValue()))
        {
            eeprom_manager.writeByte(addr, 0xAA);
            eeprom_manager.writeObject(addr + 1, volt);
        }

        else if (volt.getType() == SHADE && element_list.getShade().updateByIndex(volt.getElement(), volt.getValue()))
        {
            eeprom_manager.writeByte(addr, 0xAA);
            eeprom_manager.writeObject(addr + 1, volt);
        }
    }
    void reset() override
    {
        for (int addr : memory_address_line_machine)
            eeprom_manager.writeByte(addr, 0x00);

        for (int addr : memory_address_shade_machine)
            eeprom_manager.writeByte(addr, 0x00);
    }
    void load() override
    {
        for (int i = 0; i < 4; i++)
        {
            int addr = memory_address_line_machine[i];

            if (eeprom_manager.readByte(addr) == 0xAA)
            {
                Voltage v = eeprom_manager.readObject<Voltage>(addr + 1);
                element_list.getLine().updateByIndex(i, v.getValue());
            }
            else
            {
                // Valor por defecto
                element_list.getLine().updateByIndex(i, 0.0f);
            }
        }

        // ---- Cargar SHADE ----
        for (int i = 0; i < 4; i++)
        {
            int addr = memory_address_shade_machine[i];

            if (eeprom_manager.readByte(addr) == 0xAA)
            {
                Voltage v = eeprom_manager.readObject<Voltage>(addr + 1);
                element_list.getShade().updateByIndex(i, v.getValue());
            }
            else
            {
                element_list.getShade().updateByIndex(i, 0.0f);
            }
        }
    }
    const VoltageList &get() const override { return element_list; }
};