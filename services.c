#include "services.h"
#include <stdio.h>
#include <windows.h>

int service_fax()
{
    SC_HANDLE hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!hSCM)
    {
        printf("Fail open SCM (%lu)\n", GetLastError());
        return 1;
    }

    SC_HANDLE hService = OpenService(hSCM, "Fax", SERVICE_STOP | SERVICE_QUERY_STATUS);
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

    CloseServiceHandle(hService);
    CloseServiceHandle(hSCM);

    return 0;
}

int service_windows_search()
{
    SC_HANDLE hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!hSCM)
    {
        printf("Fail open SCM (%lu)\n", GetLastError());
        return 1;
    }

    SC_HANDLE hService = OpenService(hSCM, "WSearch", SERVICE_STOP | SERVICE_QUERY_STATUS);
    if (!hService)
    {
        printf("Fail open service 'WSearch' (%lu)\n", GetLastError());
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

    CloseServiceHandle(hService);
    CloseServiceHandle(hSCM);

    return 0;
}