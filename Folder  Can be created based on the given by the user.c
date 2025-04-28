#include <windows.h>
#include <stdio.h>

int main() {
    // Specify the drive path (e.g., D:\)
    const char* drivePath = "D:\\";
    
    // Build the full path for the new folder
    char newFolderPath[MAX_PATH];
    sprintf(newFolderPath, "%sFolder", drivePath);

    // Create the empty folder
    if (CreateDirectoryA(newFolderPath, NULL)) {
        printf("Successfully created folder at: %s\n", newFolderPath);
    } else {
        DWORD error = GetLastError();
        if (error == ERROR_ALREADY_EXISTS) {
            printf("Folder already exists at: %s\n", newFolderPath);
        } else {
            printf("Failed to create folder (Error %d)\n", error);
            return 1;
        }
    }
    return 0;
}
