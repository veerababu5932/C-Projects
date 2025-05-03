#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Simulates typing text with keyboard
void typeText(const char *text) {
	int i;
    for( i = 0; text[i] != '\0'; i++) {
        keybd_event(VkKeyScanA(text[i]), 0, 0, 0);
        keybd_event(VkKeyScanA(text[i]), 0, KEYEVENTF_KEYUP, 0);
        Sleep(50); // Delay between keystrokes
    }
}

// Simulates mouse click at coordinates (x,y)
void mouseClick(int x, int y) {
    SetCursorPos(x, y);
    Sleep(500);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(100);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

int main() {
    printf("Starting WhatsApp automation...\n");
    
    // Open WhatsApp Web in Chrome
    system("start chrome https://web.whatsapp.com");
    printf("Opened WhatsApp Web\n");
    Sleep(15000); // Wait 15 seconds for QR scan
    
    // Click on search bar (adjust coordinates)
    printf("Focusing search bar...\n");
    mouseClick(300, 200);
    Sleep(1000);
    
    // Type contact name
    const char *contact = "Ts Hub Thub";
    printf("Searching for contact: %s\n", contact);
    typeText(contact);
    Sleep(2000);
    
    // Press Enter to select contact
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    Sleep(1000);
    
    // Type message
    const char *message = "Hello from automated C program!";
    printf("Sending message: %s\n", message);
    typeText(message);
    Sleep(1000);
    
    // Press Enter to send
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    
    printf("Message sent successfully!\n");
    return 0;
}
