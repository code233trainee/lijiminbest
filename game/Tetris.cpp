#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <thread> 
#include <chrono>
#include <vector>
#pragma comment(lib, "user32.lib")

using namespace std;

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char* pField = nullptr;

int nScreenWidth = 120;   //Console Screen Size X (columns)列
int nScreenHeight = 30;  //Console Screen Size Y (rows)行

int Rotate(int px, int py, int r)
{
    switch (r % 4)
    {
        case 0: return py * 4 +px;        //0 degrees
        case 1: return 12 + py - (px * 4);//90 degrees
        case 2: return 15 - (py * 4) - px;//180 degrees
        case 3: return 3 - py + (px * 4); //270 degrees
    }
    return 0;
}

//碰撞检测
bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
{
    for(int px = 0; px < 4; px++)
    {
        for(int py = 0; py < 4; py++)//遍历整个方块
        {
            // Get index into piece
            int pi = Rotate(px, py, nRotation);

            // Get index into field
            int fi = (nPosY + py) * nFieldWidth + (nPosX + px);

            if(nPosX + py >= 0 && nPosX + px < nFieldWidth)
            {
                if(nPosY + py >= 0 && nPosY + py < nFieldHeight)
                {
                    if(tetromino[nTetromino][pi] == L'X' && pField[fi] != 0)
                    {
                        return false; // fail on first hit
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    //Create assets
    tetromino[0].append(L"..X.");//A
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");//B
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".X..");//C
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");//D
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");//E
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");//F
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"....");//G
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    auto  temp = tetromino[0];
    auto index = temp[0];

    pField = new unsigned char[nFieldWidth * nFieldHeight];// Creat play field buffer
    for(int x = 0; x < nFieldWidth; x++)// Board Boundary
    {
        for(int y = 0; y < nFieldHeight; y++)
        {
            //通过数组索引获取当前元素的位置，并判断是边框还是空
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth -1 || y == nFieldHeight - 1) ? 9 : 0;
        } 
    }

    //画出整块屏幕
    wchar_t* screen = new wchar_t[nScreenWidth*nScreenHeight];
    for(int i = 0; i < nScreenWidth*nScreenHeight; i++)
    {
        //当然应该为空
        screen[i] = L' ';
    }
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;
    
    // Game Logic Stuff
    bool bGameOver = false;

    int nCurrentPiece = 0;//游戏开始时的块
    int nCurrentRotation = 0;//旋转(0,1,2,3)
    int nCurrentX = nFieldWidth / 2;//在游戏区域的X坐标
    int nCurrentY = 0;//在游戏区域的Y坐标

    bool bKey[4];
    bool bRotateHold = false;//判断是否按住了旋转

    int nSpeed = 20;
    int nSpeedCounter = 0;
    bool bForceDown = false;
    int nPieceCount = 0;
    int nScore = 0;

    std::vector<int> vLines;

    while (!bGameOver)
    {
        // GAME TIMING ===================================
        this_thread::sleep_for(50ms);// Game Tick
        nSpeedCounter++;
        bForceDown = (nSpeedCounter == nSpeed);

        // INPUT =========================================
        for(int k = 0; k < 4; k++)
        {                                                        // R   L  D  Z
            bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;
            //使用位与操作符 & 来检查 GetAsyncKeyState 返回值的最高位（Bit 15）是否被设置(只有被设置了才不为0)。
            //0x8000 是一个十六进制数，其二进制表示是 1000 0000 0000 0000，
            //所以当它与 GetAsyncKeyState 的返回值进行位与时，只有最高位会被考虑。
        }

        // GAME LOGIC ====================================

        nCurrentX += (bKey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0; 
        nCurrentX -= (bKey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0; 
        nCurrentY += (bKey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0;

        if(bKey[3])
        {
            nCurrentRotation += (!bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0;
            bRotateHold = true;
        }
        else 
        {
            bRotateHold = false;
        }
         

        if(bForceDown)
        {
            if(DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
            {
                nCurrentY++;//It can, so do it!
            }
            else
            {
                // Lock the current piece in the field
                for(int px = 0; px < 4; px++)
                {
                    for(int py = 0; py < 4; py++)
                    {
                        if(tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
                        {
                            pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;
                        }
                    }
                }

                //增加游戏难度
                nPieceCount++;
                if(nPieceCount % 10 == 0)
                {
                    if(nSpeed >= 10)
                    {
                        nSpeed--;
                    }
                }

                // Check have got any lines
                for(int py = 0; py < 4; py++)
                {
                    if(nCurrentY + py < nFieldHeight - 1)
                    {
                        bool bLine = true;
                        for(int px = 1; px < nFieldWidth - 1; px++)
                        {
                            bLine &= (pField[(nCurrentY + py) * nFieldWidth + px]) != 0;
                        }
                        if(bLine)
                        {
                            // Remove Line, set to =
                            for(int px = 1; px < nFieldWidth - 1; px++)
                            {
                                pField[(nCurrentY + py) * nFieldWidth + px] = 8;
                            }
                            vLines.push_back(nCurrentY + py);
                        }
                    }
                }

                //分数计算
                nScore += 25;
                if(!vLines.empty())
                {
                    //是否可以看成多次左移(多次乘2)
                    nScore += (1 << vLines.size()) * 100;
                }

                // Choose next piece
                nCurrentX = nFieldWidth / 2;
                nCurrentY = 0;
                nCurrentRotation = 0;
                nCurrentPiece = rand() % 7;

                // if piece does not fit
                bGameOver = !DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
            }

            nSpeedCounter = 0;
        }
        // if(bKey[1])
        // {
        //     if(DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY))
        //     {
        //         nCurrentX = nCurrentX - 1;
        //     }
        // }

        // if(bKey[0])
        // {
        //     if(DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY))
        //     {
        //         nCurrentX = nCurrentX + 1;
        //     }
        // }

        // if(bKey[2])
        // {
        //     if(DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
        //     {
        //         nCurrentY = nCurrentY + 1;
        //     }
        // }

        // RENDER OUTPUT =================================


        //Draw Field
        for(int x = 0; x < nFieldWidth; x++)
        {
            for(int y = 0; y < nFieldHeight; y++)
            {
                //(y + 2)和(x + 2)指的是不从{0.0}位置开始                决定是空的还是边框
                screen[(y + 2)*nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
            }   
        }

        //Draw Current Piece 当前的块
        for(int px = 0; px < 4; px++)
        {
            for(int py = 0; py < 4; py++)
            {
                if(tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
                {
                    screen[(nCurrentY + py + 2)*nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;//ASCll码65开始为A，B，C...
                }
            }
        }

        // Draw Score
        swprintf_s(&screen[2 * nScreenWidth + nFieldWidth + 6], 16, L"SCORE: %8d", nScore);

        if(!vLines.empty())
        {
            // Display Frame (cheekily to draw lines)
            WriteConsoleOutputCharacterW(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
            this_thread::sleep_for(400ms);// Delay a bit

            for(auto &v : vLines)
            {
                for(int px = 1; px < nFieldWidth - 1; px++)
                {
                    for(int py = v; py > 0; py--)
                    {
                        pField[py * nFieldWidth + px] = pField[(py - 1) * nFieldWidth + px];
                    }
                    pField[px] = 0;
                }
            }
            vLines.clear();
        }
        
        //Display Frame
        WriteConsoleOutputCharacterW(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
    }
    // oh Dear
    CloseHandle(hConsole);
    wcout << "Game Over!! Score:" << nScore << endl;
    system("pause");
}

    