#include <Arduino.h>
#include <infrastructure/display.h>
#include <infrastructure/shared/conteiners/inputs_conteiner.h>
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/shared/conteiners/repositories_container.h>
#include <infrastructure/shared/conteiners/ui_container.h>
#include <infrastructure/shared/conteiners/controllers_container.h>
#include <infrastructure/shared/conteiners/app.h>
#include <core/presets/view/presets_voltages_modal.h>

static Display display;
static InputsContainer inputs;

static ProvidersContainerTest providers;
static RepositoriesContainer repositories(providers);

static UIContainer ui(display, repositories);
static ControllersContainer controllers(inputs, ui);

static App app(controllers);

PresetsVoltagesModal view(display);

void setup()
{
    display.begin();
    inputs.begin();
}
void loop()
{
    display.firstPage();
    do
    {
        view.show(repositories.get_devices_configuration().getLineDevices());
    } while (display.nextPage());
        // app.run();
}
