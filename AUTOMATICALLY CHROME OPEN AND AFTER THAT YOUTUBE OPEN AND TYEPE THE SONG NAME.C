#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void simulateKeystrokes(const char* text) {
	int i=0;
    for (i = 0; text[i] != '\0'; i++) {
        keybd_event(VkKeyScanA(text[i]), 0, 0, 0);
        keybd_event(VkKeyScanA(text[i]), 0, KEYEVENTF_KEYUP, 0);
        Sleep(50);
    }
}

int main() {
    // Open Chrome with YouTube
    system("start chrome https://www.youtube.com");
    
    // Wait for Chrome to open and YouTube to load
    Sleep(5000);
    
    // Focus the search bar (shortcut is Ctrl+L for address bar, but on YouTube it's /)
    keybd_event(VkKeyScanA('/'), 0, 0, 0);
    keybd_event(VkKeyScanA('/'), 0, KEYEVENTF_KEYUP, 0);
    
    Sleep(500);
    
    // Type the song name (change this to your desired song)
    const char* songName = "I hate you for ever";
    simulateKeystrokes(songName);
    
    Sleep(500);
    
    // Press Enter to search
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    
    Sleep(3000);
    
    // Simulate clicking the first video (this might need adjustment)
    // We'll use Tab navigation to reach the first result
    int i;
    for (i = 0; i < 5; i++) {
        keybd_event(VK_TAB, 0, 0, 0);
        keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
        Sleep(200);
    }
    
    // Press Enter to play the video
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    
    return 0;
}
