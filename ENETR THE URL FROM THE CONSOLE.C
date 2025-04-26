#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main()
{
    char url[256];
    
    // Get URL from user
    printf("Enter URL to open in Chrome: ");
    fgets(url, sizeof(url), stdin);
    
    // Remove newline character if present
    url[strcspn(url, "\n")] = '\0';
    
    // Check if URL is empty
    if (strlen(url) == 0) {
        printf("No URL provided. Using about:blank\n");
        strcpy(url, "about:blank");
    }
    
    // Build the command to open Chrome with the URL
    char command[512];
    snprintf(command, sizeof(command), "start chrome \"%s\"", url);
    
    // Execute the command
    system(command);
    
    return 0;
}
