#include "product_key.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

static const char *win_10_home_key = "37GNV-YCQVD-38XP9-T848R-FC2HD";
static const char *win_10_home_n_key = "33CY4-NPKCC-V98JP-42G8W-VH636";
static const char *win_10_pro_key = "NF6HC-QH89W-F8WYV-WWXV4-WFG6P";
static const char *win_10_pro_n_key = "NH7W7-BMC3R-4W9XT-94B6D-TCQG3";
static const char *win_10_sl_key = "NH7W7-BMC3R-4W9XT-94B6D-TCQG3";
static const char *win_10_chn_sl_key = "NH7W7-BMC3R-4W9XT-94B6D-TCQG3";

int activate()
{
    printf("ACTIVATE Windows (product key)...\n");

    char *product_key;

    DWORD productType = 0;
    if (GetProductInfo(10, 0, 0, 0, &productType))
    {
        switch (productType)
        {
        case PRODUCT_CORE:
            printf("Your Windows: Windows 10 Home\n");
            product_key = win_10_home_key;

        case PRODUCT_PROFESSIONAL:
            printf("Your Windows: Windows 10 Pro\n");
            product_key = win_10_pro_key;

        case PRODUCT_ENTERPRISE:
            printf("Your Windows: Windows 10 Enterprise\n");
            product_key = NULL;

        case PRODUCT_EDUCATION:
            printf("Your Windows: Windows 10 Education\n");
            product_key = NULL;
        
        default:
            printf("Your Windows: Undefined(");
            break;
        }
    }

    char command[512];

    snprintf(command, sizeof(command), "cscript //nologo slmgr.vbs /ipk %s", product_key);
    if (system(command) != 0)
    {
        printf("Failed to set product key\n");
        return 1;
    }

    if (system("cscript //nologo slmgr.vbs /ato") != 0)
    {
        printf("Failed to activate Windows\n");
        return 1;
    }

    printf("Success activated Windows\n");
    return 0;
}