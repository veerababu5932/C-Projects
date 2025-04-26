#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// Constants
#define LETTER_HEIGHT 100
#define LETTER_WIDTH 60
#define LETTER_SPACING 20
#define CANVAS_MARGIN 50

void LeftClick() {
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(100);
}

void selectPencilTool() {
    int pencilX = 50;
    int pencilY = 80;
    SetCursorPos(pencilX, pencilY);
    LeftClick();
    Sleep(1);
}

void drawLine(int x1, int y1, int x2, int y2) {
    // Move to starting position without drawing
    SetCursorPos(x1, y1);
    Sleep(50);
    
    // Press left mouse button
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);
    
    // Move to end position while holding button
    SetCursorPos(x2, y2);
    Sleep(50);
    
    // Release mouse button
    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(50);
}

void calculateCenterPosition(int* centerX, int* centerY) {
    RECT canvasRect;
    HWND hwnd = FindWindowA(NULL, "Untitled - Paint");
    if (hwnd) {
        GetClientRect(hwnd, &canvasRect);
        *centerX = (canvasRect.right - canvasRect.left) / 2 - (4*LETTER_WIDTH + 3*LETTER_SPACING + 10)/2;
        *centerY = (canvasRect.bottom - canvasRect.top) / 2 - LETTER_HEIGHT/2 + 50;
    } else {
        *centerX = 400;
        *centerY = 400;
    }
}
void drawT(int x, int y) {
    // First draw vertical stem (centered)
    drawLine(x, y, x, y + LETTER_HEIGHT);
    
    // Then draw horizontal top bar (centered on the vertical stem)
    int topBarHalfWidth = LETTER_WIDTH / 2;
    drawLine(x - topBarHalfWidth, y, x + topBarHalfWidth, y);
    
    // Optional: Make lines thicker by drawing again slightly offset
    drawLine(x + 1, y, x + 1, y + LETTER_HEIGHT);  // Thicker vertical
    drawLine(x - topBarHalfWidth, y + 1, x + topBarHalfWidth, y + 1);  // Thicker horizontal
}

void drawH(int x, int y) {
    drawLine(x, y, x, y + LETTER_HEIGHT);
    drawLine(x + LETTER_WIDTH, y, x + LETTER_WIDTH, y + LETTER_HEIGHT);
    drawLine(x, y + LETTER_HEIGHT/2, x + LETTER_WIDTH, y + LETTER_HEIGHT/2);
}

void drawU(int x, int y) {
    drawLine(x, y, x, y + LETTER_HEIGHT - 20);
    drawLine(x, y + LETTER_HEIGHT - 20, x + 10, y + LETTER_HEIGHT);
    drawLine(x + 10, y + LETTER_HEIGHT, x + LETTER_WIDTH - 10, y + LETTER_HEIGHT);
    drawLine(x + LETTER_WIDTH - 10, y + LETTER_HEIGHT, x + LETTER_WIDTH, y + LETTER_HEIGHT - 20);
    drawLine(x + LETTER_WIDTH, y, x + LETTER_WIDTH, y + LETTER_HEIGHT - 20);
}

void drawB(int x, int y) {
    drawLine(x, y, x, y + LETTER_HEIGHT);
    drawLine(x, y, x + LETTER_WIDTH - 10, y);
    drawLine(x + LETTER_WIDTH - 10, y, x + LETTER_WIDTH, y + 10);
    drawLine(x + LETTER_WIDTH, y + 10, x + LETTER_WIDTH, y + LETTER_HEIGHT/2 - 10);
    drawLine(x + LETTER_WIDTH, y + LETTER_HEIGHT/2 - 10, x + LETTER_WIDTH - 10, y + LETTER_HEIGHT/2);
    drawLine(x + LETTER_WIDTH - 10, y + LETTER_HEIGHT/2, x, y + LETTER_HEIGHT/2);
    drawLine(x, y + LETTER_HEIGHT/2, x + LETTER_WIDTH - 10, y + LETTER_HEIGHT/2);
    drawLine(x + LETTER_WIDTH - 10, y + LETTER_HEIGHT/2, x + LETTER_WIDTH, y + LETTER_HEIGHT/2 + 10);
    drawLine(x + LETTER_WIDTH, y + LETTER_HEIGHT/2 + 10, x + LETTER_WIDTH, y + LETTER_HEIGHT - 10);
    drawLine(x + LETTER_WIDTH, y + LETTER_HEIGHT - 10, x + LETTER_WIDTH - 10, y + LETTER_HEIGHT);
    drawLine(x + LETTER_WIDTH - 10, y + LETTER_HEIGHT, x, y + LETTER_HEIGHT);
}

void drawHyphen(int x, int y) {
    drawLine(x, y + LETTER_HEIGHT/2, x + LETTER_WIDTH/2, y + LETTER_HEIGHT/2);
}

void drawTHub() {
    int startX, startY;
    calculateCenterPosition(&startX, &startY);
    
    // Draw T
    drawT(startX, startY);
    startX += LETTER_WIDTH + LETTER_SPACING + 10;
    
    // Draw hyphen
    drawHyphen(startX, startY);
    startX += LETTER_WIDTH/2 + LETTER_SPACING;
    
    // Draw H
    drawH(startX, startY);
    startX += LETTER_WIDTH + LETTER_SPACING;
    
    // Draw U
    drawU(startX, startY);
    startX += LETTER_WIDTH + LETTER_SPACING;
    
    // Draw B
    drawB(startX, startY);
}

int main() {
    system("start mspaint");
    Sleep(3000);

    HWND hwnd = FindWindowA(NULL, "Untitled - Paint");
    if (hwnd) {
        ShowWindow(hwnd, SW_MAXIMIZE);
        Sleep(1);
    }

    selectPencilTool();
    drawTHub();

    return 0;
}
