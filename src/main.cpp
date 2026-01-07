#include <Arduino.h>
#include <infrastructure/display.h>
#include <infrastructure/shared/conteiners/inputs_conteiner.h>
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/shared/conteiners/listeners_container_test.h>
#include <infrastructure/shared/conteiners/repositories_container.h>
#include <infrastructure/shared/conteiners/ui_container.h>
#include <infrastructure/shared/conteiners/controllers_container.h>
#include <infrastructure/shared/conteiners/app.h>
#include <infrastructure/presets/controllers/presets_remote_devices_modal.h>

static Display display;
static InputsContainer inputs;

static ProvidersContainerTest providers;
static ListenerContainerTest listeners;
static RepositoriesContainer repositories(providers, listeners);

static UIContainer ui(display, repositories);
static ControllersContainer controllers(inputs, ui);

static App app(controllers);

Counter counter{30};

PresetsRemoteDevicesModal modal(display, repositories.get_presets_repository());

void setup()
{
    display.begin();
    inputs.begin();
    providers.get_performance_perovider().load();
    ui.get_performance_menu().load();
}
void loop()
{
    app.run();
}
