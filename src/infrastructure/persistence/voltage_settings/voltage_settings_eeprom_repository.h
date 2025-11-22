#include <core/device_configuration/interfaces/voltage_settings_repository.h>
#include <infrastructure/persistence/voltage_settings/voltage_settings_eeprom_provider.h>
#include <core/device_configuration/data_transfer_objects/voltage_group.h>

class VoltageSettingsEepromRepository : public IVoltageSettingsRepository
{
private:
    IDataProvider<Voltage, VoltageList> &provider;

public:
    explicit VoltageSettingsEepromRepository(VoltageSettingsEepromProvider &_provider) : provider(_provider) {}

    void update(Voltage voltage) override { provider.persist(voltage); }
    const VoltageGroup &getLineDevices() const override { return provider.get().getLine(); }
    const VoltageGroup &getShadeDevices() const override { return provider.get().getShade(); }
};