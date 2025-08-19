#include "services.h"
#include <stdio.h>
#include <windows.h>

static int stop_services(const char *service_name)
{
    SC_HANDLE hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!hSCM)
    {
        printf("Fail open SCM (%lu)\n", GetLastError());
        return 1;
    }

    SC_HANDLE hService = OpenService(hSCM, service_name, SERVICE_STOP | SERVICE_QUERY_STATUS | SERVICE_CHANGE_CONFIG);
    if (!hService)
    {
        printf("Fail open service 'Fax' (%lu)\n", GetLastError());
        CloseServiceHandle(hSCM);
        return 1;
    }

    SERVICE_STATUS status;
    if (ControlService(hService, SERVICE_CONTROL_STOP, &status))
    {
        printf("Service 'Fax' stopped\n");
    }
    else
    {
        printf("Failed stopped serivce 'Fax'\n");
    }

    if (ChangeServiceConfig(
            hService,
            SERVICE_NO_CHANGE,
            SERVICE_DISABLED,
            SERVICE_NO_CHANGE,
            NULL, NULL, NULL,
            NULL, NULL, NULL, NULL)) {
        printf("Service %s disabled\n", service_name);
    } else {
        printf("Faild disabled service: %s (%lu)\n", service_name, GetLastError());
    }

    CloseServiceHandle(hService);
    CloseServiceHandle(hSCM);

    return 0;
}

int service_fax()
{
    const char *service_name = "Fax";
    return stop_services(service_name);
}

int service_windows_search()
{
    const char *service_name = "WSearch";
    return stop_services(service_name);
}

int service_wbio()
{
    const char *service_name = "WbioSrvc";
    return stop_services(service_name);
}

int service_seclogon()
{
    const char *service_name = "seclogon";
    return stop_services(service_name);
}

int service_Spooler()
{
    const char *service_name = "Spooler";
    return stop_services(service_name);
}

int service_TapiSrv()
{
    const char *service_name = "TapiSrv";
    return stop_services(service_name);
}

int service_AdobeUpdate()
{
    const char *service_name = "AdobeUpdate";
    return stop_services(service_name);
}

int service_osppsvc()
{
    const char *service_name = "osppsvc";
    return stop_services(service_name);
}