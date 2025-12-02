#include <Arduino.h>

#include <infrastructure/shared/input_impl.h>
#include <infrastructure/display.h>
#include <infrastructure/remote_devices/persistence/remote_devices_test_provider.h>
#include <infrastructure/remote_devices/persistence/remote_devices_repository_test_impl.h>
#include <infrastructure/remote_devices/controllers/remote_devices_menu.h>
#include <application/remote_devices/remote_devices_controller.h>
#include <infrastructure/remote_devices/controllers/remote_devices_connected_modal.h>

Display display;
InputImpl input;
RemoteDevicesTestProvider provider;
RemoteDevicesRepositoryTestImpl repository(provider);

RemoteDevicesMenu menu(display, repository);
RemoteDevicesConnectedDeviceModal modal;

RemoteDevicesController controller(input, menu, modal, modal);

void setup()
{
    display.begin();
    input.begin();
    provider.load();
    repository.search();
    menu.load(0);
}
void loop()
{
    controller.execute();
}
