#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Function to simulate key presses (modified for C)
void PressKey(BYTE key, BOOL ctrl, BOOL shift, BOOL alt) {
    if (ctrl)  keybd_event(VK_CONTROL, 0, 0, 0);
    if (shift) keybd_event(VK_SHIFT, 0, 0, 0);
    if (alt)   keybd_event(VK_MENU, 0, 0, 0);

    keybd_event(key, 0, 0, 0);
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);

    if (alt)   keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
    if (shift) keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
    if (ctrl)  keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

// Function to type text
void TypeText(const char* text) {
	 int i=0;
    for ( i = 0; text[i] != '\0'; i++) {
        SHORT key = VkKeyScanA(text[i]);
        BYTE vk = LOBYTE(key);
        BYTE modifiers = HIBYTE(key);
        
        // Call PressKey with explicit modifier flags
        PressKey(vk, modifiers & 1, modifiers & 2, modifiers & 4);
        Sleep(50);
    }
}

int main() {
    const char* contactName = "Veerababu Thub";  // Change to "Thub" if needed
    const char* message = "Hello from automated WhatsApp message!";

    // Open WhatsApp Web in Chrome
    system("start chrome https://web.whatsapp.com");
    printf("Scan the QR code in Chrome, then return here and press Enter...");
    getchar();  // Wait for user to scan QR code

    Sleep(3000);  // Wait for WhatsApp to load

    // Focus search bar (Ctrl+Alt+/ in WhatsApp Web)
    PressKey(VK_OEM_2, TRUE, FALSE, TRUE);  // Ctrl+Alt+/
    Sleep(1000);

    // Type contact name
    TypeText(contactName);
    Sleep(1500);  // Wait for search results

    // Press Enter to select the contact
    PressKey(VK_RETURN, FALSE, FALSE, FALSE);
    Sleep(1000);  // Wait for chat to open

    // Type and send the message
    TypeText(message);
    Sleep(500);
    PressKey(VK_RETURN, FALSE, FALSE, FALSE);  // Send message

    printf("\nMessage sent to %s!", contactName);
    return 0;
}
