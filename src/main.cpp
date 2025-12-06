#include <Arduino.h>

#include <infrastructure/shared/conteiners/providers_container_test.h>
#include <infrastructure/shared/conteiners/respositories_container.h>
#include <infrastructure/shared/conteiners/hmi_conteiner.h>

static HMIContainer hmi;
static ProvidersContainerTest providers;
static RepositoriesContainer repositories(providers);

void setup()
{
    hmi.begin();
}
void loop()
{
}
