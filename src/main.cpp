#include <Arduino.h>
#include <infrastructure/display.h>
#include <infrastructure/shared/conteiners/inputs_conteiner.h>
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/shared/conteiners/repositories_container.h>
#include <infrastructure/shared/conteiners/ui_container.h>
#include <infrastructure/shared/conteiners/controllers_container.h>
#include <infrastructure/shared/conteiners/app.h>
#include <core/settings/views/pedal_modal.h>
#include <infrastructure/settings/controllers/settings_reset_modal.h>

static Display display;
static InputsContainer inputs;

static ProvidersContainerTest providers;
static RepositoriesContainer repositories(providers);

static UIContainer ui(display, repositories);
static ControllersContainer controllers(inputs, ui);

static App app(controllers);

SettingsResetModal modal(display);
void setup()
{
    display.begin();
    inputs.begin();
    SettingsSelectors selectors;
    selectors.side_selector = 1;
    selectors.value_selector = 1;
    modal.load(selectors);
}
void loop()
{
    modal.render();
    // display.firstPage();
    // do
    // {
    //    modal.show();
    // } while (display.nextPage());
    // app.run();
}
