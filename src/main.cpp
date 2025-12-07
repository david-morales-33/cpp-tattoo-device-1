#include <Arduino.h>
#include <infrastructure/display.h>
#include <infrastructure/shared/conteiners/inputs_conteiner.h>
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/shared/conteiners/repositories_container.h>
#include <infrastructure/shared/conteiners/ui_container.h>
#include <infrastructure/shared/conteiners/controllers_container.h>
#include <infrastructure/shared/conteiners/app.h>


static Display display;
static InputsContainer inputs;

static ProvidersContainerTest providers;
static RepositoriesContainer repositories(providers);

static UIContainer ui(display, repositories);
static ControllersContainer controllers(inputs, ui);

static App app(controllers);

void setup()
{
    display.begin();
    inputs.begin();
}
void loop() { app.run(); }
