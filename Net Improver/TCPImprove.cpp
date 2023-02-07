#include "TCPImprove.h"

void setRegKey(DWORD dwNewValue, LPCWSTR szNewValue, LPCWSTR path, LPCWSTR regName, DWORD regType) {

    HKEY hKey;

    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, path , 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS)
    {

        if (regType == REG_DWORD)
        {

            RegSetValueExW(hKey, regName, 0, regType, (LPBYTE)&dwNewValue, sizeof(DWORD));

        }

        if (regType == REG_SZ)
        {

            RegSetValueExW(hKey, regName, 0, regType, (LPBYTE)szNewValue, sizeof(WCHAR) * (wcslen(szNewValue) + 1));

        }

        RegCloseKey(hKey);

    }
}

void deleteKey(LPCWSTR path, LPCWSTR regName){

    HKEY hKey;

    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, path, 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
    {

        RegDeleteValueW(hKey, regName);

        RegCloseKey(hKey);

    }
}

void improveTCP(int mode, regDatas &values) {
   //Regedits Dword
    setRegKey(values.affinity, NULL, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", L"Affinity", REG_DWORD);
    setRegKey(values.clockrate, NULL, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", L"Clock Rate", REG_DWORD);
    setRegKey(values.gpupriority, NULL, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", L"GPU Priority", REG_DWORD);
    setRegKey(values.priority, NULL, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", L"Priority", REG_DWORD);
    setRegKey(values.explorer1, NULL, L"SOFTWARE\\Microsoft\\Internet Explorer\\Main\\FeatureControl\\FEATURE_MAXCONNECTIONSPER1_0SERVER", L"explorer.exe", REG_DWORD);
    setRegKey(values.explorer2, NULL, L"SOFTWARE\\Microsoft\\Internet Explorer\\Main\\FeatureControl\\FEATURE_MAXCONNECTIONSPERSERVER", L"explorer.exe", REG_DWORD);
    setRegKey(values.localpriority, NULL, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\ServiceProvider", L"LocalPriority", REG_DWORD);
    setRegKey(values.hostspriority, NULL, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\ServiceProvider", L"HostsPriority", REG_DWORD);
    setRegKey(values.dnspriority, NULL, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\ServiceProvider", L"DnsPriority", REG_DWORD);
    setRegKey(values.netbtpriority, NULL, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\ServiceProvider", L"NetbtPriority", REG_DWORD);
    setRegKey(values.networkthrottlingindex, NULL, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile", L"NetworkThrottlingIndex", REG_DWORD);
    setRegKey(values.systemresponsiveness, NULL, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile", L"SystemResponsiveness", REG_DWORD);
    setRegKey(values.size, NULL, L"SYSTEM\\CurrentControlSet\\Services\\LanmanServer\\Parameters", L"Size", REG_DWORD);
    setRegKey(values.largesystemcache, NULL, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management", L"LargeSystemCache", REG_DWORD);

    //Regedit Strings
    setRegKey(NULL, values.backgroundonly, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", L"Background Only", REG_SZ);
    setRegKey(NULL, values.scheduling, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", L"Scheduling Category", REG_SZ);
    setRegKey(NULL, values.sfio, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games", L"SFIO Priority", REG_SZ);

    if (mode == 1)
    {
        deleteKey(L"SOFTWARE\\Policies\\Microsoft\\Windows\\Psched", L"NonBestEffortLimit");
        deleteKey(L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters", L"MaxUserPort");
        deleteKey(L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters", L"TcpTimedWaitDelay");
        deleteKey(L"SOFTWARE\\Microsoft\\MSMQ\\Parameters", L"TCPNoDelay");
        deleteKey(L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters", L"DefaultTTL");
        deleteKey(L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\QoS", L"Do not use NLA");
    }
    else
    {
        setRegKey(values.nonbesteffortlimit, NULL, L"SOFTWARE\\Policies\\Microsoft\\Windows\\Psched", L"NonBestEffortLimit", REG_DWORD);
        setRegKey(values.maxuserport, NULL, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters", L"MaxUserPort", REG_DWORD);
        setRegKey(values.tcptimedwaitdelay, NULL, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters", L"TcpTimedWaitDelay", REG_DWORD);
        setRegKey(values.tcpnodelay, NULL, L"SOFTWARE\\Microsoft\\MSMQ\\Parameters", L"TCPNoDelay", REG_DWORD);
        setRegKey(values.defaultttl, NULL, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters", L"DefaultTTL", REG_DWORD);
        setRegKey(NULL, values.notusenla, L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\QoS", L"Do not use NLA", REG_SZ);
    }
}

void runCMD(int mode) {

    system("ipconfig /flushdns");
    system("ipconfig /registerdns");
    system("ipconfig /release");
    system("ipconfig /renew");
    system("netsh winsock reset");
    system("netsh int tcp set global rsc=disabled");
    system("netsh interface ipv4 set subinterface \"Ethernet\" mtu=1500 store=persistent");
    system("netsh interface ipv6 set subinterface \"Ethernet\" mtu=1500 store=persistent");
    system("netsh interface ipv4 set subinterface \"Wi-Fi\" mtu=1500 store=persistent");
    system("netsh interface ipv6 set subinterface \"Wi-Fi\" mtu=1500 store=persistent");

    switch (mode) {

    case 1:

        //default
        system("netsh int tcp set supplemental internet congestionprovider=CUBIC");
        system("netsh int tcp set global rss=enabled");

        break;

    case 2:

        //optimal
        system("netsh int tcp set supplemental internet congestionprovider=CUBIC");
        system("netsh int tcp set global rss=disabled");

        break;

    case 3:

        //gaming
        system("netsh int tcp set supplemental internet congestionprovider=ctcp");
        system("netsh int tcp set global rss=disabled");

        break;
    }
}

void runPowerShell(int mode) {

    system("powershell.exe Set-NetTCPSetting -SettingName internet -AutoTuningLevelLocal normal");
    system("powershell.exe Disable-NetAdapterLso -Name *");
    system("powershell.exe Disable-NetAdapterChecksumOffload -Name *");
    system("powershell.exe Set-NetOffloadGlobalSetting -Chimney disabled");
    system("powershell.exe Set-NetTCPSetting -SettingName internet -MaxSynRetransmissions 2");
    system("powershell.exe Set-NetTCPSetting -SettingName internet -InitialRto 2000");
    system("powershell.exe Set-NetTCPSetting -SettingName internet -MinRto 300");

    switch (mode) {

    case 1:

        //default
        system("powershell.exe Set-NetTCPSetting -SettingName internet -ScalingHeuristics default");
        system("powershell.exe Set-NetOffloadGlobalSetting -ReceiveSegmentCoalescing enabled");
        system("powershell.exe Set-NetOffloadGlobalSetting -ReceiveSideScaling enabled");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -EcnCapability default");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -Timestamps default");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -NonSackRttResiliency default");

        break;

    case 2:

        //optimal
        system("powershell.exe Set-NetTCPSetting -SettingName internet -ScalingHeuristics disabled");
        system("powershell.exe Set-NetOffloadGlobalSetting -ReceiveSegmentCoalescing disabled");
        system("powershell.exe Set-NetOffloadGlobalSetting -ReceiveSideScaling enabled");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -EcnCapability default");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -Timestamps disabled");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -NonSackRttResiliency disabled");

        break;

    case 3:

        //gaming
        system("powershell.exe Set-NetTCPSetting -SettingName internet -ScalingHeuristics disabled");
        system("powershell.exe Set-NetOffloadGlobalSetting -ReceiveSegmentCoalescing disabled");
        system("powershell.exe Set-NetOffloadGlobalSetting -ReceiveSideScaling disabled");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -EcnCapability disabled");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -Timestamps disabled");
        system("powershell.exe Set-NetTCPSetting -SettingName internet -NonSackRttResiliency disabled");

        break;
    }

    system("exit");
}


void setRegValues(int mode, regDatas &values) {

    values.affinity = 0x00000000;
    values.clockrate = 0x00002710;
    values.maxuserport = 0x0000fffe;
    values.tcptimedwaitdelay = 0x0000001e;
    values.tcpnodelay = 0x00000001;
    values.defaultttl = 0x00000040;
    values.notusenla = L"1";
    values.backgroundonly = L"False";

    switch (mode) {

    case 1:

        //default
        values.gpupriority = 0x00000002;
        values.priority = 0x00000002;
        values.explorer1 = 0x00000004;
        values.explorer2 = 0x00000002;
        values.localpriority = 0x000001F3;
        values.hostspriority = 0x000001F4;
        values.dnspriority = 0x000007D0;
        values.netbtpriority = 0x000007D1;
        //NonBestEffortLimit
        values.networkthrottlingindex = 0x0000000A;
        values.systemresponsiveness = 0x00000014;
        values.size = 0x00000001;
        values.largesystemcache = 0x00000000;
        //MaxUserPort
        //TcpTimedWaitDelay
        //TCPNoDelay
        //DefaultTTL
        //Do not use NLA
        values.scheduling = L"Medium";
        values.sfio = L"Normal";

        break;

    case 2:

        //optimal
        values.gpupriority = 0x00000008;
        values.priority = 0x00000006;
        values.explorer1 = 0x0000000A;
        values.explorer2 = 0x0000000A;
        values.localpriority = 0x00000004;
        values.hostspriority = 0x00000005;
        values.dnspriority = 0x00000006;
        values.netbtpriority = 0x00000007;
        values.nonbesteffortlimit = 0x00000000;
        values.networkthrottlingindex = 0xffffffff;
        values.systemresponsiveness = 0x0000000A;
        values.size = 0x00000003;
        values.largesystemcache = 0x00000001;
        values.scheduling = L"High";
        values.sfio = L"High";

        break;

    case 3:

        //gaming
        values.gpupriority = 0x00000008;
        values.priority = 0x00000006;
        values.explorer1 = 0x0000000A;
        values.explorer2 = 0x0000000A;
        values.localpriority = 0x00000004;
        values.hostspriority = 0x00000005;
        values.dnspriority = 0x00000006;
        values.netbtpriority = 0x00000007;
        values.nonbesteffortlimit = 0x00000000;
        values.networkthrottlingindex = 0xffffffff;
        values.systemresponsiveness = 0x00000000;
        values.size = 0x00000001;
        values.largesystemcache = 0x00000000;
        values.scheduling = L"High";
        values.sfio = L"High";

        break;
    }
}


void hideCMD(){

    HWND hideCMD;

    AllocConsole();

    hideCMD = FindWindowA("ConsoleWindowClass", NULL);

    ShowWindow(hideCMD, 0);
}

void runOptimization(int mode) {

    regDatas values;

    setRegValues(mode, values);

    improveTCP(mode, values);

    runCMD(mode);

    runPowerShell(mode);

}

void createBackup() {

    TCHAR szPath[MAX_PATH];

    GetEnvironmentVariableA(TEXT("userprofile"), szPath, MAX_PATH);

    std::string backupFile = szPath;

    backupFile += "\\Desktop\\RegBackup.reg";

    std::string backupCommand = "REG EXPORT HKLM\\SYSTEM " + backupFile;

    system(backupCommand.c_str());
}