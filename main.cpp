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
#include <Soft.h>
#include <fmod.h>
#include <fmod.hpp>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <io.h>
#include <limits>
#include <fstream>
#include <fstream>
#include <GameManager3.h>
#include <Wininet.h>
#include <urlmon.h>
#include <shellapi.h>
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "urlmon.lib")
using namespace cocos2d;
using namespace irrklang;
namespace SpeedhackAudio {
    void* channel;
    float speed;
    bool initialized = false;

    // setfrequency
    // setvolume

    void* (__stdcall* setVolume)(void* t_channel, float volume);
    void* (__stdcall* setFrequency)(void* t_channel, float frequency);

    void* __stdcall AhsjkabdjhadbjJHDSJ(void* t_channel, float volume) {
        channel = t_channel;

        if (speed != 1.f) {
            setFrequency(channel, speed);

        }
        return setVolume(channel, volume);
    }

    void init() {
        if (initialized)
            return;

        setFrequency = (decltype(setFrequency))GetProcAddress(GetModuleHandle("fmod.dll"), "?setPitch@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z");
        DWORD hkAddr = (DWORD)GetProcAddress(GetModuleHandle("fmod.dll"), "?setVolume@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z");

        MH_CreateHook(
            (PVOID)hkAddr,
            AhsjkabdjhadbjJHDSJ,
            (PVOID*)&setVolume
        );

        speed = 1.f;
        initialized = true;
    }

    void set(float frequency) {
        if (!initialized)
            init();

        if (channel == nullptr)
            return;

        speed = frequency;
        setFrequency(channel, frequency);
    }
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
namespace fmodchannels
{
    FMOD::Channel* hchannel1;
    FMOD::Channel* hchannel2;
    FMOD::Channel* hchannel3;
    FMOD::Channel* schannel1;
    FMOD::Channel* schannel2;
    FMOD::Channel* schannel3;
}
static bool on = false;
bool init = false;
bool show = false;
static bool nowave2 = false;
static bool cbotbutdis = false;
static bool lol2 = false;
static bool fpsgay = false;
static bool why = false;
static float setv = 1.0f;
static float setv2 = 1.0f;
static int sclick = 0;
static float i3 = 0.1;
static float i2 = 0.1;
static int srelease = 0;
static bool hard = false;
static bool console = false;
static bool bathroom = false;
static int fpsofmacro = 120;
static bool softclicks = false;
int mfwdoramilol = 0;
static bool esoftclicks = false;
static bool audiospe = false;
static bool mfwdorami = false;
static float sliderlol = 1.f;
static int releasesvar = 4;
static int sreleasesvar = 4;
static int num = 4;
static int snum = 4;
static int fuc = 0;
static bool checked = false;
static bool checkBox = false;
static bool pressed = false;
static bool on1 = false;
static float sliderFloat = 0.f;
static int sliderInt = 0.f;
static int fps = 1.0f;
static bool l = false;
static bool fpscounter = false;
static bool sometest = false;
static bool lmao = false;
static bool lmao2 = false;
static int op = 0;
static bool fun = false;
static bool fun2 = false;
static bool nosiold = false;
static bool fpsm = false;
static int wave = 1;
static bool record = false;
static bool playback = false;
static bool icons = false;
static bool repl = false;
static int currentkey = 1;
const char* keys[]{ "Shift", "Tab", "Ctrl", "Insert"};
static bool CBoot = false;
static bool hardclicks = false;
static int hardc = 4;
static int hardr = 4;
static bool xd = true;
static bool cbotnonrealtime = false;
static float setvolumeSoftClicks = 1.0f;
static float setreleasevolume = 1.0f;
static float setsoftreleasevolume = 1.0f;
static int fmodone = 0;
static float j2 = 0.0;
static int is = 0;
std::fstream autosave;


inline unsigned int(__thiscall* resetLevel)(void* self);
//fps bypass
typedef void* (__cdecl* fSharedApplication)();
typedef void(__thiscall* fSetAnimationInterval)(void* instance, double delay);
fSharedApplication sharedApplication;
fSetAnimationInterval setAnimInterval;
float interval = 0;
void Fps(int FPS)
{
    interval = 1.0f / FPS;

    HMODULE hMod = LoadLibrary("libcocos2d.dll");
    
    sharedApplication = (fSharedApplication)GetProcAddress(hMod, "?sharedApplication@CCApplication@cocos2d@@SAPAV12@XZ");
    setAnimInterval = (fSetAnimationInterval)GetProcAddress(hMod, "?setAnimationInterval@CCApplication@cocos2d@@UAEXN@Z");

    void* application = sharedApplication();
    setAnimInterval(application, interval);
}
std::string chooseDLL() //dll
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


bool StringToBool(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::istringstream is(str);
    bool b;
    is >> std::boolalpha >> b;
    return b;
}

std::string BoolToString(bool b)
{
    if (b)
        return "true";
    else
        return "false";
}
std::string IntToString(int i) {
    std::ostringstream ostr;
    ostr << i;
    return ostr.str();
}
int StringToInt(std::string str) {
        int i;
        std::istringstream(str) >> i;
        return i;
}
std::string FloatToString(float i) {
    std::ostringstream ostr;
    ostr << i;
    return ostr.str();
}
float StringToFloat(std::string str) {
    float i;
    std::istringstream(str) >> i;
    return i;
}
void SetValue(std::string option, std::string value)
{
    if (option == "noclip")
        checked = StringToBool(value);
    if (option == "Safe Mode")
        checkBox = StringToBool(value);
    if (option == "Rainbow Icon")
        lmao2 = StringToBool(value);
        if (option == "Fps Physics")
        g_enabled = StringToBool(value);
        if (option == "Noclip Accuracy")
            fpscounter = StringToBool(value);
        if (option == "No Solid Wave")
            nosiold = StringToBool(value);
        if (option == "Pratice Mode")
            pressed = StringToBool(value);
        if (option == "Audio SpeedHack")
            audiospe = StringToBool(value);
        if (option == "No Trail")
            on = StringToBool(value);
        if (option == "No Particles")
            on1 = StringToBool(value);
        if (option == "Anti-Cheat")
            l = StringToBool(value);
        if (option == "Icon Bypass")
            icons = StringToBool(value);
        if (option == "Soft Clicks")
            softclicks = StringToBool(value);
        if (option == "Hard Clicks")
            hardclicks = StringToBool(value);
        if (option == "Click Variantion")
        {
            num = StringToInt(value);

        }
        if (option == "Releases Variantion")
        {
            releasesvar = StringToInt(value);
        }
        if (option == "Soft Releases Variantion")
        {
            sreleasesvar = StringToInt(value);
        }
        if (option == "Soft Click Variantion")
        {
            snum = StringToInt(value);
        }
        if (option == "Hard Clicks Variantion")
        {
            hardc = StringToInt(value);
        }
        if (option == "Hard Releases Variantion")
        {
            hardr = StringToInt(value);
        }
        if (option == "Click Volume")
        {
            setv = StringToFloat(value);
        }
        if (option == "Soft Click Volume")
        {
            setvolumeSoftClicks = StringToFloat(value);
        }
        if (option == "Release Volume")
        {
            setreleasevolume = StringToFloat(value);
        }
        if (option == "Soft Releases Volume")
        {
            setsoftreleasevolume = StringToFloat(value);
        }
        if (option == "KeyBind")
        {
            currentkey = StringToInt(value);
        }
        if (option == "Fps Physics Target Fps")
        {
            g_target_fps = StringToInt(value);
        }
        if (option == "Hangar Preset")
        {
            bathroom = StringToBool(value);
        }
}
std::string FormatOption(std::string option, std::string value)
{
    std::string result;
    result += option;
    result += "=";
    result += value;

    return result;
}
bool write_bytes(
    const std::uintptr_t address,
    std::vector<uint8_t> const& bytes)
{
    return WriteProcessMemory(
        GetCurrentProcess(),
        reinterpret_cast<LPVOID>(address),
        bytes.data(),
        bytes.size(),
        nullptr);
}
std::string replaceAll(std::string subject, const std::string& search,
    const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}
std::string DownloadString(std::string URL) {
    HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
    HINTERNET urlFile;
    std::string rtn;
    if (interwebs) {
        urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
        if (urlFile) {
            char buffer[2000];
            DWORD bytesRead;
            do {
                InternetReadFile(urlFile, buffer, 2000, &bytesRead);
                rtn.append(buffer, bytesRead);
                
                memset(buffer, 0, 2000);
            } while (bytesRead);
            InternetCloseHandle(interwebs);
            InternetCloseHandle(urlFile);
            std::string p = replaceAll(rtn, "|n", "\r\n");
            return p;
        }
    }
    InternetCloseHandle(interwebs);
    std::string p = replaceAll(rtn, "|n", "\r\n");
    return p;
}
bool ReadcbotVersion()
{
    std::string version = DownloadString("https://snopphin.github.io/index.html");
    if (version.find("1.13") != std::string::npos) // 
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DownloadcbotVersion()
{
    std::string url = DownloadString("https://snopphin.github.io/url.html");
    ShellExecute(0, 0, url.c_str(), 0, 0, SW_SHOW);
}
DWORD WINAPI autoupdatethread(void* hModule) { //new thread because imgui issue
    if (ReadcbotVersion() == false)
    {
        if (MessageBox(NULL, "CBot Update", "Update", MB_OKCANCEL) == IDOK)
        {
            DownloadcbotVersion();
        }
    }
    return 0;
}
long __fastcall RenderMain()
{

    
    
    if (!std::filesystem::is_directory(".cbot") || !std::filesystem::exists(".cbot"))
    {
        std::filesystem::create_directory(".cbot");
    }
    autosave.open(".cbot//cbot.dat", std::ios::in | std::ios::binary);

    if (autosave.is_open())
    {
        
        std::string line;
        while (std::getline(autosave, line))
        {
            std::istringstream is_line(line);
            std::string option;
            if (std::getline(is_line, option, '='))
            {
                std::string value;
                if (std::getline(is_line, value))
                    SetValue(option, value);

            }
        }
        
    }
    autosave.close();


    autosave.open(".cbot//cbot.dat", std::ios::out | std::ios::trunc | std::ios::binary);
    if (autosave.is_open())
    {


        autosave << FormatOption("Fps Physics", BoolToString(g_enabled)) << std::endl;
        autosave << FormatOption("Rainbow Icon", BoolToString(lmao2)) << std::endl;
        autosave << FormatOption("Noclip Accuracy", BoolToString(fpscounter)) << std::endl;
        autosave << FormatOption("No Solid Wave", BoolToString(nosiold)) << std::endl;
        autosave << FormatOption("Icon Bypass", BoolToString(icons)) << std::endl;
        autosave << FormatOption("noclip", BoolToString(checked)) << std::endl;
        autosave << FormatOption("Safe Mode", BoolToString(checkBox)) << std::endl;
        autosave << FormatOption("Pratice Mode", BoolToString(pressed)) << std::endl;
        autosave << FormatOption("Audio SpeedHack", BoolToString(audiospe)) << std::endl;
        autosave << FormatOption("No Trail", BoolToString(on)) << std::endl;
        autosave << FormatOption("No Particles", BoolToString(on1)) << std::endl;
        autosave << FormatOption("Anti-Cheat", BoolToString(l)) << std::endl;
        autosave << FormatOption("Click Variantion", IntToString(num)) << std::endl;
        autosave << FormatOption("Releases Variantion", IntToString(releasesvar)) << std::endl;
        autosave << FormatOption("Soft Click Variantion", IntToString(snum)) << std::endl;
        autosave << FormatOption("Soft Releases Variantion", IntToString(sreleasesvar)) << std::endl;
        autosave << FormatOption("Soft Clicks", BoolToString(softclicks)) << std::endl;
        autosave << FormatOption("Hard Clicks", BoolToString(hardclicks)) << std::endl;
        autosave << FormatOption("Hard Clicks Variantion", IntToString(hardc)) << std::endl;
        autosave << FormatOption("Hard Releases Variantion", IntToString(hardr)) << std::endl;
        autosave << FormatOption("Click Volume", FloatToString(setv)) << std::endl;
        autosave << FormatOption("Soft Click Volume", FloatToString(setvolumeSoftClicks)) << std::endl;
        autosave << FormatOption("Release Volume", FloatToString(setreleasevolume)) << std::endl;
        autosave << FormatOption("Soft Releases Volume", FloatToString(setsoftreleasevolume)) << std::endl;
        autosave << FormatOption("KeyBind", IntToString(currentkey)) << std::endl;
        autosave << FormatOption("Fps Physics Target Fps", IntToString(g_target_fps)) << std::endl;
        autosave << FormatOption("Hangar Preset", BoolToString(bathroom)) << std::endl;
    }
    if (checkBox == true)
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
        
    }

    if (checkBox == false)
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
    if (checked == true)
    {
        char* dir;
        std::string str;
        int value = 14315;
        DWORD ptr = (DWORD)(dir), addr = (DWORD)GetModuleHandleA("GeometryDash.exe") + 0x20A1DD, l;
        VirtualProtect((void*)addr, MAX_PATH, PAGE_EXECUTE_READWRITE, &l);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)(addr), &value, 4, NULL);
    }
    if (checked == false)
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

    if (g_enabled == true)
    {
        MH_Initialize();
        size_t base = (size_t)GetModuleHandle(0);
        auto cocos = GetModuleHandleA("libcocos2d.dll");

        MH_CreateHook((void*)(base + 0x205460), PlayLayer_updateVisibility_H, (void**)&PlayLayer_updateVisibility);
        MH_CreateHook(
            (void*)(base + 0x205460),
            PlayLayer_updateVisibility_H,
            (void**)&PlayLayer_updateVisibility);
        MH_CreateHook(GetProcAddress(cocos, "?update@CCScheduler@cocos2d@@UAEXM@Z"), CCScheduler_update_H, (void**)&CCScheduler_update);
        MH_CreateHook(
            GetProcAddress(cocos, "?update@CCScheduler@cocos2d@@UAEXM@Z"),
            CCScheduler_update_H,
            (void**)&CCScheduler_update);
        MH_EnableHook(MH_ALL_HOOKS);

    }
    if (g_enabled == false)
    {

        g_disable_render = false;
    }
    if (lmao2 == true)
    {
 
        auto gm = gd::GameManager::sharedState();
        auto play_layer = gm->getPlayLayer();
        auto player1 = play_layer->m_player1;
        gd::AchievementNotifier::sharedState()->notifyAchievement("Congrats u enabled RainBow icon", "Rainbow icon does rainbow icon", "bird_07_001.png", true);
        if (play_layer)
        {

        }
    }
    if (lmao2 == false)
    {
    }
    if (nosiold == true)
    {

        DWORD base = (DWORD)GetModuleHandleA(0);
        write_bytes(base + 0x1E8162, { 0x90, 0x90 });
        write_bytes(base + 0x1E816B, { 0x90, 0x90 });

    }
    if (nosiold == false)
    {
        DWORD base = (DWORD)GetModuleHandleA(0);
        write_bytes(base + 0x1E8162, { 0x75, 0x18 });
        write_bytes(base + 0x1E816B, { 0x75, 0x0F });

    }
    if (pressed == false)
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
    if (audiospe == true)
    {
        mfwdorami = true;
        MH_Initialize();
        SpeedhackAudio::init();
        MH_EnableHook(MH_ALL_HOOKS);
    }
    if (audiospe == false)
    {

        mfwdorami = false;
    }
    if (on == true)
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
    }
    if (on == false)
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
    if (on1 == true)
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
    }
    if (on1 == false)
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
    if (l == true)
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


    
    if (l == false)
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
    if (icons == true)
    {
        DWORD base = (DWORD)GetModuleHandleA(0);
        write_bytes(base + 0xC50A8, { 0xB0, 0x01, 0x90, 0x90, 0x90 });
        write_bytes(base + 0xC54BA, { 0xB0, 0x01, 0x90, 0x90, 0x90 });
    }
    if (icons == false)
    {
        DWORD base = (DWORD)GetModuleHandleA(0);
        write_bytes(base + 0xC50A8, { 0xE8, 0x7A, 0xCD, 0x19, 0x00 });
        write_bytes(base + 0xC54BA, { 0xE8, 0x68, 0xC9, 0x19, 0x00 });
    }
    if (softclicks == true)
    {
        esoftclicks = true;
    }
    if (softclicks == false)
    {
        esoftclicks = false;
    }
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGuiStyle* style = &ImGui::GetStyle();
    ImVec4* colors = ImGui::GetStyle().Colors;

    style->FrameRounding = 4.0f;
    style->GrabRounding = 4.0f;
    style->Alpha = 1.f;
    style->WindowRounding = 12.f;
    style->FrameRounding = 4.f;
    style->ScrollbarSize = 2.f;
    style->ScrollbarRounding = 12.f;
    style->PopupRounding = 4.f;

    ImFontConfig font_config;
    font_config.OversampleH = 1; //or 2 is the same
    font_config.OversampleV = 1;
    font_config.PixelSnapH = 1;

    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(255, 255, 255, 0);
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
    static bool shift = false;
    static bool tab = true;
    static bool control = false;
    static bool insert = false;
    //bool because skill issue
    if (currentkey == 0) //shift
    {
        insert = false;
        shift = true;
        control = false;
        tab = false;
        if (shift == true)
        {
            if (GetAsyncKeyState(VK_SHIFT) & 1) {
                show = !show;

            }
        }
    }
    if (currentkey == 1) //tab
    {
        tab = true;

        insert = false;
        shift = false;
        control = false;
        if (tab == true)
        {
            if (GetAsyncKeyState(VK_TAB) & 1) {
                show = !show;

            }
        }
    }
    if (currentkey == 2) //control 
    {
        control = true;

        insert = false;
        tab = false;
        shift = false;
        if (control == true)
        {
            if (GetAsyncKeyState(VK_CONTROL) & 1) {
                show = !show;

            }
        }
    }
    if (currentkey == 3) // insert
    {
        insert = true;

        tab = false;
        control = false;
        shift = false;
        if (insert == true)
        {
            if (GetAsyncKeyState(VK_INSERT) & 1) {
                show = !show;

            }
        }
    }

    if (show) {
        ImGui::Begin("Mods");
        if (ImGui::InputFloat("Float", &i2))
        {

        }
        if (ImGui::InputInt("Int", &sclick))
        {

        }
        if (ImGui::InputFloat("Fps Physics", &g_target_fps))
        {

        }
        if (ImGui::Checkbox("Enable Fps Physics", &g_enabled))
        {



            if (g_enabled) 
            {
                g_disable_render = false;
            }
        }
        if (ImGui::Checkbox("Enable Rainbow Icon", &lmao2))
        {
            if (lmao2 == false)
            {
            }
        }
        if (ImGui::Checkbox("Enable Solid Wave Trail", &nosiold))
        {

            if (nosiold == true)
            {
            }
        }
        if (ImGui::Checkbox("Enable Icon Bypass", &icons))
        {
            if (icons == false)
            {

            }
        }
        if (ImGui::Checkbox("Enable Noclip", &checked))
        {

            if (checked == false)
            {

            }

        }
        if (ImGui::Checkbox("Enable Safe Mode", &checkBox))
        {

            if (checkBox == false)
            {

            }
        }

        if (ImGui::Checkbox("Enable Pratice Hack", &pressed))
        {

            if (pressed == true)
            {

            }
        }
        if (ImGui::Checkbox("Enable Audio Speedhack", &audiospe))
        {

            if (audiospe == false)
            {

            }
        }
        if (ImGui::Checkbox("Enable No Trail", &on))
        {

            if (on == false)
            {

            }

        }

        if (ImGui::Checkbox("Enable No Particles", &on1))
        {


            if (on1 == false)
            {

            }
        }
        if (ImGui::Checkbox("Enable Anti-Cheat", &l))
        {


            if (l == false)
            {

            }
        }
        if (ImGui::InputFloat("Speed", &sliderlol, 0.1f, 1.f))
        {
            if (audiospe == true)
            {
                SpeedhackAudio::set(sliderlol);
            }
            Speedhack::Setup();
            Speedhack::SetSpeed(sliderlol);
            if (sliderlol == 0.0f)
            {
                sliderlol = 0.1f;
            }
            if (sliderlol == 0)
            {
                sliderlol = 0.1f;
            }
        }
        static int sliderlol2 = 60;//fps

        ImGui::Combo("KeyBind", &currentkey, keys, IM_ARRAYSIZE(keys));
        if (ImGui::InputInt("Fps Bypass", &sliderlol2, 0, 10000, 0))
        {
            Fps(sliderlol2);
        }
        if (ImGui::Button("Inject Dll")) {
            std::string stringpath = chooseDLL();
            const char* DllPath = stringpath.c_str();
            
            // Open a handle to target process
            HWND hWnd = FindWindow(0, "Geometry Dash");
                DWORD proccess_ID;
                GetWindowThreadProcessId(hWnd, &proccess_ID);
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);
                LPVOID pDllPath = VirtualAllocEx(hProcess, 0, strlen(DllPath) + 1,
                MEM_COMMIT, PAGE_READWRITE);
                WriteProcessMemory(hProcess, pDllPath, (LPVOID)DllPath,
                strlen(DllPath) + 1, 0);
                HANDLE hLoadThread = CreateRemoteThread(hProcess, 0, 0,
                (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32.dll"), "LoadLibraryA"), pDllPath, 0, 0);
                WaitForSingleObject(hLoadThread, INFINITE);
                VirtualFreeEx(hProcess, pDllPath, strlen(DllPath) + 1, MEM_RELEASE);
            
        }
        ImGui::End();
        ImGui::Begin("CBot Non-Realtime");
        ImGui::Checkbox("Enable CBot Non-Realtime", &cbotnonrealtime); //not finished
        ImGui::Begin("CBot 1.1");
        static bool disabled = false;
        static bool bot = false;
        ImGui::SetWindowSize(ImVec2(180, 180));
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
                    Soft::mem_init();
                    // Enable all hooks
                    MH_EnableHook(MH_ALL_HOOKS);


                    if (CBoot == false)
                    {
                        cbotbutdis = false;
                    }


                }
            }
        }

        if (ImGui::InputInt("Click Variantion", &num, 1, 30))
        {
        }
        if (ImGui::InputInt("Releases Variantion", &releasesvar, 1, 30))
        {
        }
        if (ImGui::InputInt("Soft Click Variantion", &snum))
        {
        }
        if (ImGui::InputInt("Soft Releases Variantion", &sreleasesvar))
        {
        }
        if (ImGui::InputInt("Hard Clicks Variantion", &hardc, 1, 30))
        {
        }
        if (ImGui::InputInt("Hard Releases Variantion", &hardr, 1, 30))
        {
        }


        if (ImGui::InputInt("Fps Of Replay", &fpsofmacro))
        {

        }
        ImGui::InputFloat("Click Volume", &setv, 0.1, 65.f);
        ImGui::InputFloat("Soft Click Volume", &setvolumeSoftClicks, 0.1, 65.f);
        ImGui::InputFloat("Release Volume", &setreleasevolume, 0.1, 65.f);
        ImGui::InputFloat("Soft Release Volume", &setsoftreleasevolume, 0.1, 65.f);
        {
        }
        if (ImGui::Checkbox("Enable Soft Clicks", &softclicks))
        {
        }
        if (ImGui::Checkbox("Enable Hard Clicks", &hardclicks))
        {

        }
        if (ImGui::Checkbox("Enable Hangar preset", &bathroom))
        {

        }

        static bool lolgay2 = false;
        if (ImGui::Checkbox("Enable Pc Noise", &lol2))
        {
            ISoundEngine* engine = createIrrKlangDevice();
            ISound* music = engine->play2D(".cbot//Clicks//noise//silent.wav", true, false, true, ESM_AUTO_DETECT, true);
            ISoundEffectControl* fx = 0;
            if (music)
            {
                fx = music->getSoundEffectControl();
            }



            if (lol2 == false)
            {
               
                music->stop();
            }
            return 0;
        }
        if (ImGui::Checkbox("Enable Console", &console))
        {

            if (console == false)
            {



            }
            return 0;

        }
        ImGui::Text(" %.3f ms (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();

    
    }
    return 0;
}
namespace fmlol
{
    FMOD::System* system = nullptr;
    FMOD_RESULT result;
    FMOD::Reverb3D* reverb;
}
namespace fmclicks
{
    FMOD::Sound* sound = nullptr;
    FMOD::Sound* ssound = nullptr;
}
int i; //real
bool __fastcall Soft::InitFMOD(CCLayer* self, int edx, void* GJGameLevel) 
{

    if (cbotbutdis == true)
    {
        fmlol::result = fmlol::system->createReverb3D(&fmlol::reverb);
            fmodone += 1;
            if (fmodone < 2) //only once calls fmod init and bathroom preset
            {
                fmlol::result = FMOD::System_Create(&fmlol::system);
                fmlol::result = fmlol::system->init(512, FMOD_INIT_NORMAL, nullptr);
                fmclicks::sound;
                fmclicks::ssound;
            }
            if (bathroom == false)
            {
                FMOD_REVERB_PROPERTIES prop2 = FMOD_PRESET_OFF;
                fmlol::reverb->setProperties(&prop2);
            }
            if (bathroom == true)
            {
                FMOD_REVERB_PROPERTIES prop2 = FMOD_PRESET_HANGAR;
                fmlol::reverb->setProperties(&prop2);
            }
    }
    return Soft::initfm(self, GJGameLevel);
}

void __fastcall Soft::hkSoft(cocos2d::CCLayer* self, void* edx, float delta) //playlayer::update
{
    auto gm = gd::GameManager::sharedState();
    auto play_layer = gm->getPlayLayer();

    if (play_layer)
    {
        
            if (cbotbutdis == true)
            {
                if (esoftclicks == true)
                {
                    if (fpsofmacro < 60)
                    {
                        i2 += 0.035;
                        i3 += 0.035;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1)
                        {
                            sclick -= 0.003;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1)
                        {
                            srelease -= 0.003;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 60)
                    {
                        i2 += 0.047;
                        i3 += 0.047;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1)
                        {
                            sclick -= 0.001;
                            i2 = 0;
                        }



                        if (srelease < 0) 
                        {
                            srelease += 1;

                        }
                        if (srelease > 3) 
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1)
                        {
                            srelease -= 0.001;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 90)
                    {
                        i2 += 0.05453;
                        i3 += 0.05453;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1.1)
                        {
                            sclick -= 1;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1.1)
                        {
                            srelease -= 1;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 120)
                    {
                        i2 += 0.03288;
                        i3 += 0.03288;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1.1)
                        {
                            sclick -= 1;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1.1)
                        {
                            srelease -= 0.002;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 144)
                    {
                        i2 += 0.0299999;
                        i3 += 0.0299999;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1.1)
                        {
                            sclick -= 1;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1.1)
                        {
                            srelease -= 1;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 240)
                    {
                        i2 += 0.01798622;
                        i3 += 0.01798622;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1.1)
                        {
                            sclick -= 1;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1.1)
                        {
                            srelease -= 1;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 288)
                    {
                        i2 += 0.015175;
                        i3 += 0.015175;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1.1)
                        {
                            sclick -= 1;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1.1)
                        {
                            srelease -= 1;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 360)
                    {
                        i2 += 0.01251;
                        i3 += 0.01251;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1.1)
                        {
                            sclick -= 1;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1.1)
                        {
                            srelease -= 1;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro == 480)
                    {
                        i2 += 0.004;
                        i3 += 0.004;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1)
                        {
                            sclick -= 0.004;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1)
                        {
                            srelease -= 0.004;
                            i3 = 0;
                        }
                    }
                    if (fpsofmacro > 480)
                    {
                        i2 += 0.003;
                        i3 += 0.003;
                        if (sclick < 0)
                        {
                            sclick += 1;

                        }
                        if (sclick > 3)
                        {
                            sclick -= 1;
                        }
                        if (i2 > 1)
                        {
                            sclick -= 0.002;
                            i2 = 0;
                        }



                        if (srelease < 0)
                        {
                            srelease += 1;

                        }
                        if (srelease > 3)
                        {
                            srelease -= 1;
                        }
                        if (i3 > 1)
                        {
                            srelease -= 0.002;
                            i3 = 0;
                        }
                    }
                    
                }
            }
        
        
    }
    return Soft::SF(self, delta);
}

void __fastcall Soft::levelCompleteHook(void* self) {


    return Soft::levelComplete(self);
}
void Soft::mem_init() {
    size_t base = (size_t)GetModuleHandle(0);
    if (cbotnonrealtime == true)
    {
        MH_CreateHook(
            (PVOID)(base + 0x1FD3D0),
            Soft::levelCompleteHook,
            (LPVOID*)&Soft::levelComplete);
    }
    if (CBoot == true)
    {
        MH_CreateHook(
            (PVOID)(base + 0x2029C0),
            Soft::hkSoft,
            (LPVOID*)&Soft::SF);
        MH_CreateHook(
            (PVOID)(base + 0x01FB780),
            Soft::InitFMOD,
            (LPVOID*)&Soft::initfm);
    }
}

void holdran()
{
    FMOD::Channel* channel = nullptr;
    FMOD::Channel* channel2 = nullptr;
    FMOD::Channel* channel3 = nullptr;
    auto gm = gd::GameManager::sharedState();
    auto play_layer = gm->getPlayLayer();
    if (play_layer)
    {
        if (esoftclicks == true)
        {
            sclick += 1.69;
        }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        int n = 1;
        const std::string clicks[] = { "Clicks//clicks//1.wav", "Clicks//clicks//2.wav", "Clicks//clicks//3.wav", "Clicks//clicks//4.wav", "Clicks//clicks//5.wav", "Clicks//clicks//6.wav", "Clicks//clicks//7.wav", "Clicks//clicks//8.wav", "Clicks//clicks//9.wav", "Clicks//clicks//10.wav","Clicks//clicks//11.wav", "Clicks//clicks//12.wav", "Clicks//clicks//13.wav", "Clicks//clicks//14.wav", "Clicks//clicks//15.wav", "Clicks//clicks//16.wav", "Clicks//clicks//17.wav", "Clicks//clicks//18.wav", "Clicks//clicks//19.wav", "Clicks//clicks//20.wav", "Clicks//clicks//21.wav", "Clicks//clicks//22.wav" };
        const std::string hclicks[] = { "Clicks//hardClicks//1.wav", "Clicks//hardClicks//2.wav", "Clicks//hardClicks//3.wav", "Clicks//hardClicks//4.wav", "Clicks//hardClicks//5.wav", "Clicks//hardClicks//6.wav", "Clicks//hardClicks//7.wav", "Clicks//hardClicks//8.wav", "Clicks//hardClicks//9.wav", "Clicks//hardClicks//10.wav", "Clicks//hardClicks//12.wav", "Clicks//hardClicks//13.wav", "Clicks//hardClicks//14.wav", };
        const std::string sclicks[] = { "Clicks//softClicks//1.wav", "Clicks//softClicks//2.wav", "Clicks//softClicks//3.wav", "Clicks//softClicks//4.wav", "Clicks//softClicks//5.wav", "Clicks//softClicks//6.wav", "Clicks//softClicks//7.wav", "Clicks//softClicks//8.wav", "Clicks//softClicks//9.wav", "Clicks//softClicks//10.wav", "Clicks//softClicks//11.wav", "Clicks//softClicks//12.wav" };
       

        std::string click = ".cbot//";
        std::string hardclick = ".cbot//";

        std::string softclick = ".cbot//";
        std::mt19937 generator(seed);
        std::uniform_int_distribution<>randclick(0, num - 1);
        std::uniform_int_distribution<>randsclick(0, snum - 1);
        std::uniform_int_distribution<>randhclick(0, hardc - 1);
        for (int i = 0; i < n; i++)
        {
            click += clicks[randclick(generator)];
            softclick += sclicks[randsclick(generator)];
            hardclick += hclicks[randhclick(generator)];
        }
        if (esoftclicks == true)
        {
            if (sclick == 1)
            {
                if (hardclicks == false)
                {

                    fmlol::system->createSound(click.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
                    if (mfwdorami == false)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel);
                    }
                    if (mfwdorami == true)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &fmodchannels::hchannel1);
                        fmodchannels::hchannel1->setPitch(sliderlol);
                        fmodchannels::hchannel1->setVolume(setv);
                    }

                    channel->setVolume(setv);
                    bool isPlaying1 = false;
                    do {
                        fmlol::system->update();
                    } while (isPlaying1);
                }
                if (hardclicks == true)
                {

                    fmlol::system->createSound(hardclick.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
                    if (mfwdorami == false)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel);
                    }
                    if (mfwdorami == true)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &fmodchannels::hchannel1);
                        fmodchannels::hchannel1->setPitch(sliderlol);
                        fmodchannels::hchannel1->setVolume(setv);
                    }

                    channel->setVolume(setv);
                    bool isPlaying1 = false;
                    do {
                        fmlol::system->update();
                    } while (isPlaying1);
                }
            }
            if (sclick == 2)
            {
                fmlol::system->createSound(click.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
                if (mfwdorami == false)
                {
                    fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel2);
                }
                if (mfwdorami == true)
                {
                    fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &fmodchannels::hchannel2);
                    fmodchannels::hchannel2->setPitch(sliderlol);
                    fmodchannels::hchannel2->setVolume(setv);
                }
                channel2->setVolume(setv);
                bool isPlaying2 = false;
                do {
                    fmlol::system->update();
                } while (isPlaying2);
            }
            if (sclick > 2)
            {
                fmlol::system->createSound(softclick.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::ssound);
                if (mfwdorami == false)
                {
                    fmlol::result = fmlol::system->playSound(fmclicks::ssound, nullptr, false, &channel3);
                }
                if (mfwdorami == true)
                {
                    fmlol::result = fmlol::system->playSound(fmclicks::ssound, nullptr, false, &fmodchannels::hchannel3);
                    fmodchannels::hchannel3->setPitch(sliderlol);
                }
                channel3->setVolume(setvolumeSoftClicks);
                bool isPlaying3 = false;
                do {
                    fmlol::system->update();
                } while (isPlaying3);
            }
        }
        if (esoftclicks == false)
        {
            fmlol::system->createSound(click.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
            fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel);
            channel->setVolume(setv);
            bool isPlaying1 = false;
            do {
                fmlol::system->update();
            } while (isPlaying1);
        }
        if (console == true)
        {
            if (sclick == 1)
            {
                if (hardclicks == false)
                std::cout << click.c_str() << "" << std::endl;
                if (hardclicks == true)
                std::cout << hardclick.c_str() << "" << std::endl;
            }
            if (sclick == 2)
            {
                std::cout << click.c_str() << "" << std::endl;
            }
            if (softclicks == true)
            {
                if (sclick > 2)
                {
                    std::cout << softclick.c_str() << "" << std::endl;
                }
            }
        }

    }
}
void releaseran()
{

    FMOD::Channel* channel = nullptr;
    FMOD::Channel* channel2 = nullptr;
    FMOD::Channel* channel3 = nullptr;
    auto gm = gd::GameManager::sharedState();
    auto play_layer = gm->getPlayLayer();
    if (play_layer)
    {
        if (esoftclicks == true)
        {
            srelease += 1.69;
        }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        int n = 1;
        const std::string clicks[] = { "Clicks//releases//1.wav", "Clicks//releases//2.wav", "Clicks//releases//3.wav", "Clicks//releases//4.wav", "Clicks//releases//5.wav", "Clicks//releases//6.wav", "Clicks//releases//7.wav", "Clicks//releases//8.wav", "Clicks//releases//9.wav", "Clicks//releases//10.wav","Clicks//releases//11.wav", "Clicks//releases//12.wav", "Clicks//releases//13.wav", "Clicks//releases//14.wav", "Clicks//releases//15.wav", "Clicks//releases//16.wav", "Clicks//releases//17.wav", "Clicks//releases//18.wav", "Clicks//releases//19.wav", "Clicks//releases//20.wav" };
        const std::string srele[] { "Clicks//softReleases//1.wav", "Clicks//softReleases//2.wav", "Clicks//softReleases//3.wav", "Clicks//softReleases//4.wav", "Clicks//softReleases//5.wav", "Clicks//softReleases/6.wav", "Clicks//softReleases//7.wav", "Clicks//softReleases//8.wav", "Clicks//softReleases//9.wav", "Clicks//softReleases//10.wav", "Clicks//softReleases//11.wav", "Clicks//softReleases//12.wav" };
        const std::string hreleases[] ={ "Clicks//hardReleases//1.wav", "Clicks//hardReleases//2.wav", "Clicks//hardReleases//3.wav", "Clicks//hardReleases//4.wav", "Clicks//hardReleases//5.wav", "Clicks//hardReleases//6.wav", "Clicks//hardReleases//7.wav", "Clicks//hardReleases//8.wav", "Clicks//hardReleases//9.wav", "Clicks//hardReleases//10.wav", "Clicks//hardReleases//11.wav", "Clicks//hardReleases//12.wav", "Clicks//hardReleases//13.wav", };
        std::string click = ".cbot//";
        std::string hardclick = ".cbot//";
        std::string softclick = ".cbot//";
        std::random_device random_device;
        std::mt19937 Seeds(seed);
        std::uniform_int_distribution<>randclick(0, releasesvar - 1);
        std::uniform_int_distribution<>randsclick(0, sreleasesvar - 1);
        std::uniform_int_distribution<>randhclick(0, hardr - 1);
        for (int i = 0; i < n; i++)
        {
            click += clicks[randclick(Seeds)];
            softclick += srele[randsclick(Seeds)];
            hardclick += hreleases[randhclick(Seeds)];
        }
        if (esoftclicks == true)
        {
            if (srelease == 1)
            {
                if (hardclicks == false)
                {
                    fmlol::system->createSound(click.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
                    if (mfwdorami == false)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel);
                    }
                    if (mfwdorami == true)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &fmodchannels::schannel1);
                        fmodchannels::schannel1->setPitch(sliderlol);
                        fmodchannels::schannel1->setVolume(setreleasevolume);
                    }
                    channel->setVolume(setreleasevolume);
                    bool isPlaying1 = false;
                    do {
                        fmlol::system->update();
                    } while (isPlaying1);
                }
                if (hardclicks == true)
                {
                    fmlol::system->createSound(hardclick.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
                    if (mfwdorami == false)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel);
                    }
                    if (mfwdorami == true)
                    {
                        fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &fmodchannels::schannel1);
                        fmodchannels::schannel1->setPitch(sliderlol);
                        fmodchannels::schannel1->setVolume(setreleasevolume);
                    }
                    channel->setVolume(setreleasevolume);
                    bool isPlaying1 = false;
                    do {
                        fmlol::system->update();
                    } while (isPlaying1);
                }
            }

        }
        if (srelease == 2)
        {
            fmlol::system->createSound(click.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
            if (mfwdorami == false)
            {
                fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel2);
            }
            if (mfwdorami == true)
            {
                fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &fmodchannels::schannel2);
                fmodchannels::schannel2->setPitch(sliderlol);
                fmodchannels::schannel2->setVolume(setreleasevolume);
            }
            channel2->setVolume(setreleasevolume);
            bool isPlaying1 = false;
            do {
                fmlol::system->update();
            } while (isPlaying1);
        }
        if (srelease > 2)
        {
            fmlol::system->createSound(softclick.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::ssound);
            if (mfwdorami == false)
            {
                fmlol::result = fmlol::system->playSound(fmclicks::ssound, nullptr, false, &channel3);
            }
            if (mfwdorami == true)
            {
                fmlol::result = fmlol::system->playSound(fmclicks::ssound, nullptr, false, &fmodchannels::schannel3);
                fmodchannels::schannel3->setPitch(sliderlol);
                fmodchannels::schannel3->setVolume(setsoftreleasevolume);
            }
            channel3->setVolume(setsoftreleasevolume);
            bool isPlaying1 = false;
            do {
                fmlol::system->update();
            } while (isPlaying1);


        }
        if (esoftclicks == false)
        {
            fmlol::system->createSound(click.c_str(), FMOD_DEFAULT, nullptr, &fmclicks::sound);
            fmlol::result = fmlol::system->playSound(fmclicks::sound, nullptr, false, &channel);
            channel->setVolume(setreleasevolume);
            bool isPlaying1 = false;
            do {
                fmlol::system->update();
            } while (isPlaying1);
        }
        if (console == true)
        {
            if (sclick == 1)
            {
                if (hardclicks == false)
                    std::cout << click.c_str() << "" << std::endl;
                if (hardclicks == true)
                    std::cout << hardclick.c_str() << "" << std::endl;
            }
            if (sclick == 2)
            {
                std::cout << click.c_str() << "" << std::endl;
            }
            if (softclicks == true)
            {
                if (sclick > 2)
                {
                    std::cout << softclick.c_str() << "" << std::endl;
                }
            }
        }
    }
}
bool __fastcall PlayerObject::pushButtonHook(void* self, int edx, void* PlayerButton) {

    if (cbotbutdis == true && !PlayerButton)
    {
    holdran();
    }
    return PlayerObject::pushButton(self, PlayerButton);
}

bool __fastcall PlayerObject::releaseButtonHook(void* self, int edx, void* PlayerButton) {
    if (cbotbutdis == true && !PlayerButton)
    {
    releaseran();
    }

    return PlayerObject::releaseButton(self, PlayerButton);
}
unsigned int __fastcall resetLevelHook(void* self, int* edx) {
    sclick = 0;
    srelease = 0;
    i3 = 0;
    i2 = 0;

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
            CreateThread(0, 0x1000, autoupdatethread, hMod, 0, 0);
			ImGuiHook::Load(RenderMain);
			break;
		case DLL_PROCESS_DETACH:
            MH_Uninitialize();
			ImGuiHook::Unload();
            autosave.close();
			break;
		}
		return TRUE;
	}

