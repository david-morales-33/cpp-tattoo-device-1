#include <Arduino.h>
#include <infrastructure/main/persistence/main_date_time_provider_test.h>
#include <infrastructure/main/persistence/main_date_time_repository_impl.h>
#include <infrastructure/main/controllers/main_menu.h>
#include <infrastructure/shared/input_impl.h>
#include <application/main/main_menu_controller.h>
#include <infrastructure/display.h>

Display display;
InputImpl input;
MainDateTimeProviderTest provider;

MainDateTimeRepositoryImpl repository(provider);
MainMenu menu(display, repository);

MainMenuController controller(input, menu);

void setup()
{
    input.begin();
    display.begin();
}
void loop()
{
    controller.execute();
}
