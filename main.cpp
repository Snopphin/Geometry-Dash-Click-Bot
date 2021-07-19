#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cocos2d.h>
#include <imgui.h>
#include <imgui_hook.h>
#include <MinHook.h>
#include <fstream>
#include <gd.h>
#include "kiero/kiero.h"
#include <d3d9.h>
#include <imgui/imgui_impl_win32.h>
#include <PlayLayer.h>
#include <CCDirectorModified.h>
#include <GameManager.h>
#include <PlayerObject.h>
#include <iostream>
#include <detours.h>
#include "speed.h"
#include <string>
#include <conio.h>
#include <commdlg.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <random>
#include "sha1.h"
#include <irrKlang.h>
#include <ik_irrKlangTypes.h>
#include <ik_ISound.h>
#include <ik_ISoundEngine.h>
#include <ik_ISoundSource.h>
#include <ik_ISoundEffectControl.h>
#include <ik_ISoundSource.h>
#include <chrono>
#include <PlayLayer2.h>
#include <GameManager2.h>
#include <PlayLayer3.h>
#include <GameManager3.h>
#include <MenuOptions.h>
using namespace cocos2d;

typedef void* (__cdecl* fSharedApplication)();
typedef void(__thiscall* fSetAnimationInterval)(void* instance, double delay);
fSharedApplication sharedApplication;
fSetAnimationInterval setAnimInterval;
float interval = 0; //this is changed externally

void Fps(int FPS)
{
    interval = 1.0f / FPS;

    HMODULE hMod = LoadLibrary("libcocos2d.dll");
    
    sharedApplication = (fSharedApplication)GetProcAddress(hMod, "?sharedApplication@CCApplication@cocos2d@@SAPAV12@XZ");
    setAnimInterval = (fSetAnimationInterval)GetProcAddress(hMod, "?setAnimationInterval@CCApplication@cocos2d@@UAEXN@Z");

    void* application = sharedApplication();

    setAnimInterval(application, interval);
    

   
}

std::string chooseDLL()
{
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    	if (GetOpenFileName(&ofn))
        return fileName;

}

static bool on = true;

DWORD __declspec(dllexport) WINAPI Hooking(void* hModule) {
    return 0;
}

void WriteBytes(void* location, std::vector<BYTE> bytes) { //thx to fig
    DWORD old_prot;
    VirtualProtect(location, bytes.size(), PAGE_EXECUTE_READWRITE, &old_prot);

    memcpy(location, bytes.data(), bytes.size());

    VirtualProtect(location, bytes.size(), old_prot, &old_prot);
}



static HWND window = NULL;


bool init = false;


bool show = false;



static bool nowave2 = false;
#include "sha1.h" //mhv5
#include <sstream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <handler.cpp>
#include <io.h>
static int num = 4;
static int snum = 4;
#include <fstream>
std::string Folder()
{
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    if (GetOpenFileName(&ofn))
        return fileName;

}
//mat
float g_target_fps = 60.f;
bool g_enabled = false;
bool g_disable_render = false;
float g_left_over = 0.f;

void(__thiscall* CCScheduler_update)(CCScheduler*, float);
void __fastcall CCScheduler_update_H(CCScheduler* self, int, float dt) {
    if (!g_enabled)
        return CCScheduler_update(self, dt);
    auto speedhack = self->getTimeScale();

    const float newdt = 1.f / g_target_fps / speedhack;
    g_disable_render = true;

    const int times = min(static_cast<int>((dt + g_left_over) / newdt), 100); 
    for (int i = 0; i < times; ++i) {
        if (i == times - 1)
            g_disable_render = false;
        CCScheduler_update(self, newdt);
    }

    g_left_over += dt - newdt * times;
}

void(__thiscall* PlayLayer_updateVisibility)(void*);
void __fastcall PlayLayer_updateVisibility_H(void* self) {
    if (!g_disable_render)
    PlayLayer_updateVisibility(self);
}
static bool cbotbutdis = false;
static bool lol2 = false;
static bool fpsgay = false;
static bool why = false;
long __fastcall RenderMain()
{


    HWND g = FindWindow(0, "Geometry Dash");
    HWND d = SetActiveWindow(g);

    HWND hWnd = FindWindow(0, "Geometry Dash");
    {
        DWORD proccess_ID;
        GetWindowThreadProcessId(hWnd, &proccess_ID);
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);
    }
    ImGui::GetStyle().FrameRounding = 4.0f;
    ImGui::GetStyle().GrabRounding = 4.0f;

    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    if (GetAsyncKeyState(VK_TAB) & 1) {
        show = !show;
    }
    if (show) {
        static bool checked = false;
        static bool checkBox = false;
        static bool pressed = false;
        static bool on = false;
        static bool on1 = false;
        static float sliderFloat = 0.f;
        static int sliderInt = 0.f;
        static int fps = 1.0f;
        static bool l = false;
        static bool fpscounter = false;
        static bool fps22 = false;
        static bool sometest = false;
        static bool lmao = false;
        static bool lmao2 = false;
        static int op = 0;
        static bool fun = false;
        static bool fun2 = false;
        static bool fpsm = false;

        ImGui::Begin("Mods");
        ImGui::SetWindowSize(ImVec2(182, 215));
        if (ImGui::InputFloat("Fps Physhic", &g_target_fps, 60.f, 5000.f))
        {

        }
        if (ImGui::Checkbox("Enable Fps Multiplier", &g_enabled))
        {

            MH_Initialize();
            size_t base = (size_t)GetModuleHandle(0);
            auto cocos = GetModuleHandleA("libcocos2d.dll");

            MH_CreateHook((void*)(base + 0x205460), PlayLayer_updateVisibility_H, (void**)&PlayLayer_updateVisibility);

            MH_CreateHook(GetProcAddress(cocos, "?update@CCScheduler@cocos2d@@UAEXM@Z"), CCScheduler_update_H, (void**)&CCScheduler_update);

            MH_EnableHook(MH_ALL_HOOKS);

    
            if (g_enabled == false)
            {
                g_disable_render = false;
            }

        }
        if (ImGui::Checkbox("Enable Rainbow Icon", &lmao2))
        {

            auto gm = gd::GameManager::sharedState();
            auto play_layer = gm->getPlayLayer();
            auto player1 = play_layer->m_player1;
            if (play_layer)
            {
                player1->setOpacity({ 80 });
            }
        }
        if (ImGui::Checkbox("Enable Fps Counter", &fps22))
        {

            size_t base = (size_t)GetModuleHandle(0);
            fpsgay = true;
            MH_Initialize();


            PlayLayer3::mem_init();
            GameManager3::mem_init();

            MH_EnableHook(MH_ALL_HOOKS);
            if (fps22 == false)
            {
                fpsgay = false;

            }
        }
        if (ImGui::Checkbox("Enable Noclip Accuracy", &fpscounter)) //by fig
        {           
            char* dir;
            std::string str;
            int value = 14315;
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A1DD, l;
            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &l);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            why = true;
            MH_Initialize();

            PlayLayer2::mem_init();
            GameManager2::mem_init();

            MH_EnableHook(MH_ALL_HOOKS);
            if (fpscounter == false)
            {
                why = false;
                size_t base = (size_t)GetModuleHandle(0);
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 107118730;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A1DD, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                strcpy(dir, "test");


            }
        }
        static bool nowae = false;
        if (ImGui::Checkbox("Enable No Wave", &nowae))//not finished
        {
            DWORD baseGame = reinterpret_cast<DWORD>(GetModuleHandle(0));
            DWORD oldProtect;
            VirtualProtect(reinterpret_cast<void*>(baseGame + 0x1E8688), 6, PAGE_EXECUTE_READWRITE, &oldProtect);




            memcpy_s(reinterpret_cast<void*>(baseGame + 0x1E8688), 6, "\xF3\x0F\x10\x05\x00\x00\x00\x00", 7);
            VirtualProtect(reinterpret_cast<void*>(baseGame + 0x1E8688), 6, oldProtect, &oldProtect);



            if (nowae == false)
            {
                DWORD baseGame = reinterpret_cast<DWORD>(GetModuleHandle(0));
                DWORD oldProtect;
                VirtualProtect(reinterpret_cast<void*>(baseGame + 0x00000), 6, PAGE_EXECUTE_READWRITE, &oldProtect);

                memcpy_s(reinterpret_cast<void*>(baseGame + 0x00000), 6, "\x00", 6);
                VirtualProtect(reinterpret_cast<void*>(baseGame + 0x00000), 6, oldProtect, &oldProtect);
            }
        }
    
    
    
        if (ImGui::Checkbox("Enable Noclip", &checked))
        {

            char* dir;
            std::string str;
            int value = 14315;
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A1DD, l;
            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &l);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            if (!checked)
            {
                {
                    std::vector<std::string> v;
                    char* dir;
                    std::string str;



                    int value = 107118730;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A1DD, old;

                    VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                    WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                    strcpy(dir, "test");


                }
            }

        }
        static bool CBoot = false;
        if (ImGui::Checkbox("Enable Safe Mode", &checkBox))
        {
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 105193;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A3B2, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                strcpy(dir, "test");
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 398313;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD40F, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                strcpy(dir, "test");
            }
            if (!checkBox)
            {
                {
                    std::vector<std::string> v;
                    char* dir;
                    std::string str;



                    int value = 76856192;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A3B2, old;

                    VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                    WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                    strcpy(dir, "test");
                }
                {
                    std::vector<std::string> v;
                    char* dir;
                    std::string str;



                    int value = 56932739;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD40F, old;

                    VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                    WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                }
            }
        }
        if (ImGui::Checkbox("Enable Pratice Hack", &pressed))
        {
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 2425393296;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20C925, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                strcpy(dir, "test");
            }
            std::vector<std::string> v;
            char* dir;
            std::string str;



            int value = 2391511184;
            dir = new char[MAX_PATH];
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20D143, old;

            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            {
                strcpy(dir, "test");

                int value = 2391511184;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A563, old;
            }
            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            {
                strcpy(dir, "test");

                int value = 2341179536;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A595, old;


                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            if (!pressed)
            {
                {
                    std::vector<std::string> v;
                    char* dir;
                    std::string str;



                    int value = 16221455;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20C925, old;

                    VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                    WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                    strcpy(dir, "test");
                }
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 2391490933;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20D143, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
                {
                    strcpy(dir, "test");

                    int value = 2341158517;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A563, old;
                }
                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
                {
                    strcpy(dir, "test");

                    int value = 1692929141;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A595, old;


                    VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                    WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
                }

            }
        }
        if (ImGui::Checkbox("Enable No Trail", &on))
        {

            std::vector<std::string> v;
            char* dir;
            std::string str;



            int value = 158185;
            dir = new char[MAX_PATH];
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAEDCC, old;
            HMODULE hMod = LoadLibrary("libcocos2d.dll");

            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            if (!on)
            {
                {
                    std::vector<std::string> v;
                    char* dir;
                    std::string str;



                    int value = 40403983;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAEDCC, old;
                    HMODULE hMod = LoadLibrary("libcocos2d.dll");

                    VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                    WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                    strcpy(dir, "test");


                }
            }
        }

        if (ImGui::Checkbox("Enable No Particles", &on1))
        {
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 3435971328;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("libcocos2d.dll") + 0xB8ED6, old;
                HMODULE hMod = LoadLibrary("libcocos2d.dll");

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            if (!on1)
            {
                {
                    std::vector<std::string> v;
                    char* dir;
                    std::string str;



                    int value = 3435971329;
                    dir = new char[MAX_PATH];
                    DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("libcocos2d.dll") + 0xB8ED6, old;
                    HMODULE hMod = LoadLibrary("libcocos2d.dll");

                    VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                    WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);

                }
            }
        }
        if (ImGui::Checkbox("Enable Anti-Cheat", &l))
        {
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 1877487339;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x202AAA, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {std::vector<std::string> v;
            char* dir;
            std::string str;



            int value = 3414909163;
            dir = new char[MAX_PATH];
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x15FC2E, old;

            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {std::vector<std::string> v;
            char* dir;
            std::string str;



            int value = 3481996523;
            dir = new char[MAX_PATH];
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD557, old;

            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 48269255;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD742, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 2425393296;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD756, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 48269255;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD79A, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 144;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD7AF, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 2425393296;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20D3B3, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 3496513680;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FF7A2, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 1566245296;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x18B2B4, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 55273;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20C4E6, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
        }

        if (!l)
        {
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 1877487220;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x202AAA, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }

            {std::vector<std::string> v;
            char* dir;
            std::string str;



            int value = 3414909044;
            dir = new char[MAX_PATH];
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x15FC2E, old;

            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {std::vector<std::string> v;
            char* dir;
            std::string str;



            int value = 3481996404;
            dir = new char[MAX_PATH];
            DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD557, old;

            VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 48086912;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD742, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 4261250063;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD756, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 4256793615;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD79A, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 4255417615;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FD7AF, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 284904;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20D3B3, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 3496504948;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x1FF7A2, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 1566294922;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x18B2B4, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
            {
                std::vector<std::string> v;
                char* dir;
                std::string str;



                int value = 14058767;
                dir = new char[MAX_PATH];
                DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20C4E6, old;

                VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &old);
                WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
            }
        }        
        static float sliderlol = 1.f;
        if (ImGui::InputFloat("Speed", &sliderlol, 0.1, 1.0))
        {

            Speedhack::Setup();
            Speedhack::SetSpeed(sliderlol);
        }
        static int sliderlol2 = 60;
        if (ImGui::InputInt("Fps Bypass", &sliderlol2, 0, 10000, 0))
        {
        Fps(sliderlol2);
        }

        ImGui::End();
        ImGui::Begin("CBot 1.1");
        ImGui::SetWindowSize(ImVec2(180, 180));
        static bool disabled = false;

        static bool bot = false;
        if (ImGui::Checkbox("Enable CBot", &CBoot))
        {

            HWND hWnd = FindWindow(0, "Geometry Dash");

            if (hWnd == 0)
            {
                MessageBox(0, "Error cannot find window.", "Error", MB_OK | MB_ICONERROR);
            }
            else
            {
                DWORD proccess_ID;
                GetWindowThreadProcessId(hWnd, &proccess_ID);
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);
                if (!hProcess)
                {
                    MessageBox(0, "Could not open the process!", "Error!", MB_OK | MB_ICONERROR);
                }
                else
                {

                       cbotbutdis = true;
                        MH_Initialize();

                        // Hooking
                        PlayLayer::mem_init();
                        PlayerObject::mem_init();

                        // Enable all hooks
                        MH_EnableHook(MH_ALL_HOOKS);


                    if (CBoot == false)
                    {
                        cbotbutdis = false;
                    }
                    

                }
            }
        }
        if (ImGui::InputInt("Click Variantions", &num, 1, 30))
        {
            
        }
        if (ImGui::InputInt("Soft Click Variantions", &snum, 1, 30))
        {

        }
        if (ImGui::Button("Choose Folder"))
        {
            Folder();
        }

        using namespace irrklang;
        static bool lolgay2 = false;
        if (ImGui::Checkbox("Enable Pc Noise", &lol2))
        {
            lolgay2 = true;
            if (lolgay2 == true)
            {
                ISoundEngine* engine = createIrrKlangDevice();
                ISound* music = engine->play2D("Clicks//noise//silent.wav", true, false, true, ESM_AUTO_DETECT, true);
                ISoundEffectControl* fx = 0;
                if (music)
                {
                    fx = music->getSoundEffectControl();
                    music->setVolume(0.1f);
                    fx->enableParamEqSoundEffect();
                    fx->enableCompressorSoundEffect();
                }
            }
            if (lol2 == false)
            {
                lolgay2 = false;
                
            }
            return 0;
        }
        static int sliderInt2 = 0.f;
        if (ImGui::SliderInt)
        if (ImGui::Button("Inject Dll")) {
            std::string stringpath = chooseDLL();
            const char* DllPath = stringpath.c_str();

            // Open a handle to target process
            HWND hWnd = FindWindow(0, "Geometry Dash");

            if (hWnd == 0)
            {
                MessageBox(0, "Error cannot find window.", "Error", MB_OK | MB_ICONERROR);
            }
            else
            {
                DWORD proccess_ID;
                GetWindowThreadProcessId(hWnd, &proccess_ID);
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);

                // Allocate memory for the dllpath in the target process
                // length of the path string + null terminator
                LPVOID pDllPath = VirtualAllocEx(hProcess, 0, strlen(DllPath) + 1,
                    MEM_COMMIT, PAGE_READWRITE);

                // Write the path to the address of the memory we just allocated
                // in the target process
                WriteProcessMemory(hProcess, pDllPath, (LPVOID)DllPath,
                    strlen(DllPath) + 1, 0);

                // Create a Remote Thread in the target process which
                // calls LoadLibraryA as our dllpath as an argument -> program loads our dll
                HANDLE hLoadThread = CreateRemoteThread(hProcess, 0, 0,
                    (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32.dll"),
                        "LoadLibraryA"), pDllPath, 0, 0);

                // Wait for the execution of our loader thread to finish
                WaitForSingleObject(hLoadThread, INFINITE);

                std::cout << "Dll path allocated at: " << std::hex << pDllPath << std::endl;
                std::cin.get();

                // Free the memory allocated for our dll path
                VirtualFreeEx(hProcess, pDllPath, strlen(DllPath) + 1, MEM_RELEASE);
            }

        }

    
                ImGui::Text(" %.3f ms (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
            
        
    }
    return 0;
}



inline unsigned int(__thiscall* resetLevel)(void* self);
inline unsigned int(__thiscall* holds)(void* self, void* PlayerButton);
int i;
using namespace irrklang;
#include <iomanip>
double clockToMilliseconds(clock_t ticks) {
    // units/(units/time) => time (seconds) * 1000 = milliseconds
    return (ticks / (double)CLOCKS_PER_SEC) * 1000.0;
}
//...
clock_t deltaTime = 0;
unsigned int frames = 0;
double  frameRate = 30;
double  averageFrameTimeMilliseconds = 33.333;

bool PlayLayer3::wouldDie2 = false;
int PlayLayer3::frames2 = 0;
int PlayLayer3::deaths2 = 0;
float PlayLayer3::totalDelta2 = 0;
float PlayLayer3::prevX2 = 0;
std::string getfpstext() {

    clock_t current_ticks, delta_ticks;
    clock_t fps = 0;
    current_ticks = clock();

    delta_ticks = clock() - current_ticks; //the time, in ms, that took to render the scene
    if (delta_ticks > 0)
        fps = CLOCKS_PER_SEC / delta_ticks;

    if (PlayLayer3::frames2 == 0) return "Fps: ";
    float p = (int)fps;
    std::stringstream stream;
    stream << "Fps: " << std::fixed << std::setprecision(0) << ("", 10.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    return stream.str();
}

bool __fastcall PlayLayer3::initHook2(CCLayer* self, int edx, void* GJGameLevel) {
    if (fpsgay == true)
    {
        size_t base = (size_t)GetModuleHandle(0);

        prevX2 = 0;

        if (base + 0x3222d0) {
            CCLabelBMFont* textObj = CCLabelBMFont::create("Fps: ", "bigFont.fnt");

            textObj->setZOrder(1000);
            textObj->setTag(10000);

            textObj->setScale(0.5);
            auto size = textObj->getScaledContentSize();

            textObj->setPosition({ size.width / 2 + 3, size.height / 2 + 280 });

            self->addChild(textObj);

        }
    }
    return init2(self, GJGameLevel);
}

void __fastcall PlayLayer3::hkUpdate2(cocos2d::CCLayer* self, void* edx, float delta) {
    if (fpsgay == true)
    {
        void* player1 = *(void**)((char*)self + 0x224);
        float x = *(float*)((size_t)player1 + 0x67c);

        if (x != prevX2) {
            frames2 += 1;
            totalDelta2 += delta;
        }



        size_t base = (size_t)GetModuleHandle(0);

        {
            CCLabelBMFont* textObj = (CCLabelBMFont*)self->getChildByTag(10000);
            auto text = getfpstext();
            textObj->setString(text.c_str());
            auto size = textObj->getScaledContentSize();

            textObj->setPosition({ size.width / 2 + 3, size.height / 2 + 300 });
        }


        if (wouldDie2) {
            wouldDie2 = false;
            if (totalDelta2 >= 0.1 && x != prevX2) {
                deaths2 += 1;
            }
        }


        prevX2 = x;
    }
    return update2(self, delta);
}

int __fastcall PlayLayer3::hkResetLevel2(void* self) {
    int res = resetLevel3(self);
    void* player1 = *(void**)((char*)self + 0x224);
    prevX2 = *(float*)((size_t)player1 + 0x67c);
    frames2 = 0;
    totalDelta2 = 0;
    deaths2 = 0;
    wouldDie2 = false;

    return res;
}

int __fastcall PlayLayer3::hkDeath2(void* self, void*, void* go, void* powerrangers) {
    size_t base = (size_t)GetModuleHandle(0);

    if (base + 0x3222d0) {
        wouldDie2 = true;
    }

    return death2(self, go, powerrangers);
}

void PlayLayer3::mem_init() {
    size_t base = (size_t)GetModuleHandle(0);
    MH_CreateHook(
        (PVOID)(base + 0x01FB780),
        PlayLayer3::initHook2,
        (LPVOID*)&PlayLayer3::init2);

    MH_CreateHook(
        (PVOID)(base + 0x20A1A0),
        PlayLayer3::hkDeath2,
        (LPVOID*)&PlayLayer3::death2);

    MH_CreateHook(
        (PVOID)(base + 0x20BF00),
        PlayLayer3::hkResetLevel2,
        (LPVOID*)&PlayLayer3::resetLevel3);

    MH_CreateHook(
        (PVOID)(base + 0x2029C0),
        PlayLayer3::hkUpdate2,
        (LPVOID*)&PlayLayer3::update2);
}
const int MAX_SIZE = 26;



void holdran()
{


    auto gm = gd::GameManager::sharedState();
    auto play_layer = gm->getPlayLayer();

    auto player = play_layer->m_player1;
    auto player1 = player->create();

    if (play_layer)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        int n = 1;
        auto clicks = std::vector<std::string>{ "Clicks//softClicks//1.wav", "Clicks//softClicks//2.wav", "Clicks//softClicks//3.wav", "Clicks//softClicks//4.wav", "Clicks//clicks//1.wav", "Clicks//clicks//2.wav", "Clicks//clicks//3.wav", "Clicks//clicks//4.wav", "Clicks//clicks//5.wav", "Clicks//clicks//6.wav", "Clicks//clicks//7.wav", "Clicks//clicks//8.wav", "Clicks//clicks//9.wav", "Clicks//clicks//10.wav","Clicks//clicks//11.wav", "Clicks//clicks//12.wav", "Clicks//clicks//13.wav", "Clicks//clicks//14.wav", "Clicks//clicks//15.wav", "Clicks//clicks//16.wav", "Clicks//clicks//17.wav", "Clicks//clicks//18.wav", "Clicks//clicks//19.wav", "Clicks//clicks//20.wav", "Clicks//clicks//21.wav", "Clicks//clicks//22.wav" };
        std::string click = "";
        for (int i = 0; i < n; i++)
        {
            click = click + clicks[rand() % num];
        }
        ISoundEngine* engine = createIrrKlangDevice();
        ISound* music = engine->play2D(click.c_str(), false, false, false, ESM_AUTO_DETECT, true);
        ISoundEffectControl* fx = 0;
        if (music)
        {
            fx = music->getSoundEffectControl();
            music->setVolume(1.0f);
        }

    }
}

void releaseran()
{

    auto gm = gd::GameManager::sharedState();
    auto play_layer = gm->getPlayLayer();
    auto player = play_layer->m_player1;
    if (play_layer)
    {
        {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        int n = 1;
        auto clicks = std::vector<std::string>{ "Clicks//softReleases//1.wav", "Clicks//softReleases//2.wav", "Clicks//softReleases//3.wav", "Clicks//softReleases//4.wav", "Clicks//releases//1.wav", "Clicks//releases//2.wav", "Clicks//releases//3.wav", "Clicks//releases//4.wav", "Clicks//releases//5.wav", "Clicks//releases//6.wav", "Clicks//releases//7.wav", "Clicks//releases//8.wav", "Clicks//releases//9.wav", "Clicks//releases//10.wav","Clicks//releases//11.wav", "Clicks//releases//12.wav", "Clicks//releases//13.wav", "Clicks//releases//14.wav", "Clicks//releases//15.wav", "Clicks//releases//16.wav", "Clicks//releases//17.wav", "Clicks//releases//18.wav", "Clicks//releases//19.wav", "Clicks//releases//20.wav" };
        std::string click = "";
        for (int i = 0; i < n; i++)
        {
        click = click + clicks[rand() % num]; //num 
        }
        ISoundEngine* engine = createIrrKlangDevice();
        ISound* music = engine->play2D(click.c_str(), false, false, false, ESM_AUTO_DETECT, true);
        ISoundEffectControl* fx = 0;
        if (music)
        {
            fx = music->getSoundEffectControl();
            music->setVolume(1.2f);
        }
        }
    }
}

bool __fastcall PlayerObject::pushButtonHook(void* self, int edx, void* PlayerButton) {
    if (cbotbutdis == true)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        holdran();
    }
    return PlayerObject::pushButton(self, PlayerButton);
}

bool __fastcall PlayerObject::releaseButtonHook(void* self, int edx, void* PlayerButton) {
    if (cbotbutdis == true)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        releaseran();
    }
    return PlayerObject::releaseButton(self, PlayerButton);
}
unsigned int __fastcall resetLevelHook(void* self, int* edx) {
    
    
    MH_Initialize();
    // Hooking
    PlayerObject::mem_init();
    // Enable all hooks
    MH_EnableHook(MH_ALL_HOOKS);


    return resetLevel(self);
}

#include "PlayLayer2.h"
#include "GameManager2.h"
#include <iomanip>

bool PlayLayer2::wouldDie = false;
int PlayLayer2::frames = 0;
int PlayLayer2::deaths = 0;
float PlayLayer2::totalDelta = 0;
float PlayLayer2::prevX = 0;


std::string getAccuracyText() {
    if (PlayLayer2::frames == 0) return "Died: 0";
    int p = (int)(PlayLayer2::frames - PlayLayer2::deaths) / (int)PlayLayer2::frames;
    
    std::stringstream stream;
    stream << "Died: " << std::setprecision(3) << p * 1 << "";
    return stream.str();
}

bool __fastcall PlayLayer2::initHook(CCLayer* self, int edx, void* GJGameLevel) {
    if (why == true)
    {
        size_t base = (size_t)GetModuleHandle(0);

        prevX = 0;

        if (base + 0x3222d0) {
            CCLabelBMFont* textObj = CCLabelBMFont::create("Died: 0", "bigFont.fnt");

            textObj->setZOrder(1000);
            textObj->setTag(1000000);

            textObj->setScale(0.5);
            auto size = textObj->getScaledContentSize();

            textObj->setPosition({ size.width / 2 + 3, size.height / 2 + 3 });

            self->addChild(textObj);


        }
        else {


        }
    }
    return init(self, GJGameLevel);
}
void __fastcall PlayLayer2::hkUpdate(cocos2d::CCLayer* self, void* edx, float delta) {
    if (why == true)
    {

        void* player1 = *(void**)((char*)self + 0x224);
        float x = *(float*)((size_t)player1 + 0x67c);






        if (x != prevX) {
            frames += 1;
            totalDelta += delta;
        }

        size_t base = (size_t)GetModuleHandle(0);

        {
            CCLabelBMFont* textObj = (CCLabelBMFont*)self->getChildByTag(1000000);
            auto text = getAccuracyText();
            textObj->setString(text.c_str());
            auto size = textObj->getScaledContentSize();

            textObj->setPosition({ size.width / 2 + 3, size.height / 2 + 3 });
        }


        if (wouldDie) {
            wouldDie = false;

        }

        prevX = x;
    }
    return update(self, delta);
}

int __fastcall PlayLayer2::hkResetLevel(void* self) {
    int res = resetLevel2(self);
    void* player1 = *(void**)((char*)self + 0x224);
    prevX = *(float*)((size_t)player1 + 0x67c);
    frames = 0;
    totalDelta = 0;
    deaths = 0;
    wouldDie = false;

    return res;
}

int __fastcall PlayLayer2::hkDeath(void* self, void*, void* go, void* powerrangers) {
    size_t base = (size_t)GetModuleHandle(0);

    if (base + 0x3222d0) {
        wouldDie = true;
    }
    deaths += -1;
    frames += -1;

    return death(self, go, powerrangers);
}


void PlayLayer2::mem_init() {
    size_t base = (size_t)GetModuleHandle(0);
    MH_CreateHook(
        (PVOID)(base + 0x01FB780),
        PlayLayer2::initHook,
        (LPVOID*)&PlayLayer2::init);

    MH_CreateHook(
        (PVOID)(base + 0x20A1A0),
        PlayLayer2::hkDeath,
        (LPVOID*)&PlayLayer2::death);

    MH_CreateHook(
        (PVOID)(base + 0x20BF00),
        PlayLayer2::hkResetLevel,
        (LPVOID*)&PlayLayer2::resetLevel2);

    MH_CreateHook(
        (PVOID)(base + 0x2029C0),
        PlayLayer2::hkUpdate,
        (LPVOID*)&PlayLayer2::update);
}

void PlayLayer::mem_init()
{
    size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));

    MH_CreateHook(
        (PVOID)(base + 0x20BF00),
        resetLevelHook,
        (LPVOID*)&resetLevel
    );

}

void PlayerObject::mem_init()
{

    size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));

    MH_CreateHook(
        (PVOID)(base + 0x1F4E40),
        PlayerObject::pushButtonHook,
        (LPVOID*)&PlayerObject::pushButton
    );

    MH_CreateHook(
        (PVOID)(base + 0x1F4F70),
        PlayerObject::releaseButtonHook,
        (LPVOID*)&PlayerObject::releaseButton
    );
}



	BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
	{

		switch (dwReason)
		{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hMod); 
			ImGuiHook::Load(RenderMain);
            CreateThread(0, 0x1000, Hooking, hMod, 0, 0);
			break;
		case DLL_PROCESS_DETACH:
            MH_Uninitialize();
			ImGuiHook::Unload();
			break;
		}
		return TRUE;
	}

