#include "clear_cache.h"

#include <windows.h>
#include <stdio.h>

static int delete_folder_contents(const char *path)
{
    printf("Starting deleting (temps) | Waiting (1/10)\n");

    WIN32_FIND_DATA find_file_data;

    char search_path[MAX_PATH];
    snprintf(search_path, MAX_PATH, "%s\\*", path);

    HANDLE hFind = FindFirstFile(search_path, &find_file_data);

    if (hFind == INVALID_HANDLE_VALUE) return 0;

    do
    {
        if (strcmp(find_file_data.cFileName, ".") != 0 &&
            strcmp(find_file_data.cFileName, "..") != 0)
        {
            char full_path[MAX_PATH];

            snprintf(full_path, MAX_PATH, "%s\\%s", path, find_file_data.cFileName);

            if (find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                printf("Deleting path:(%s)...\n", full_path);
                delete_folder_contents(full_path);
                RemoveDirectory(full_path);
            }
            else
            {
                if (!DeleteFile(full_path))
                {
                    printf("[Warning] No-Deleting path:(%s)...\n", full_path);
                }
            }
        }
    } while (FindNextFile(hFind, &find_file_data));

    FindClose(hFind);

    return 1;
}

int cache_temp()
{
    char temp_path[MAX_PATH];
    DWORD len = GetTempPath(MAX_PATH, temp_path);

    if (len > 0 && len < MAX_PATH)
    {
        return delete_folder_contents(temp_path);
    }

    return 0;
}