#include <Arduino.h>
#include <infrastructure/shared/input_impl.h>
#include <infrastructure/display.h>
#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/shared/conteiners/respositories_container.h>

static Display display;
static InputImpl input;

static ProvidersContainerTest providers;
static RepositoriesContainer repositories(providers);

void setup()
{
    display.begin();
    input.begin();
}
void loop()
{
}
