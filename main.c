#include "clear_cache.h"
#include "services.h"

int main(void)
{
    int cCache = cache_temp();

    int sFax = service_fax();
    int sWSearch = service_windows_search();

    return (cCache || sFax || sWSearch);
}