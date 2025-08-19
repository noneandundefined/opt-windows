#include "clear_cache.h"
#include "services.h"
#include <stdlib.h>

int main(void)
{
    int cCache = cache_temp();

    int sFax = service_fax();
    int sWSearch = service_windows_search();
    int sWbio = service_wbio();
    int sSeclogon = service_seclogon();
    int sSpooler = service_Spooler();
    int sTapiSrv = service_TapiSrv();
    int sAdobeUpdate = service_AdobeUpdate();
    int sOsppsvc = service_osppsvc();

    system("PAUSE");
    return (cCache || sFax || sWSearch || sWbio || sSeclogon || sSpooler || sTapiSrv || sAdobeUpdate || sOsppsvc);
}