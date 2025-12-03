#include <Arduino.h>
#include <infrastructure/shared/input_impl.h>
#include <infrastructure/display.h>
#include <infrastructure/properties/persistence/properties_memory_provider.h>
#include <infrastructure/properties/persistence/properties_timer_test_provider.h>
#include <infrastructure/properties/persistence/properties_timer_repository.h>
#include <infrastructure/properties/controllers/properties_menu.h>
#include <application/properties/properties_controller.h>

Display display;
InputImpl input;
PropertiesMemoryProvider memory_provider;
PropertiesTimerTestProvider time_provider;
PropertiesTimerRepository repository(memory_provider, time_provider);
PropertiesMenu menu(display, repository);
PropertiesController controller(input, menu);

void setup()
{
    display.begin();
    input.begin();
}
void loop()
{
    controller.execute();
}
