# TSY-VIRUS
这是一份关于TSY病毒（原名CmdTool.exe）的主要说明。

零、前言
免责声明：本文旨在演示TSY病毒的发作及其预防，无任何不良引导。本文演示的恶意程序和木马病毒仅用于学习目的。本人十分反对病毒，样本请勿用于非法用途，请遵守我国相关法律法规。

一、概述
TSY病毒是由Win7MEMZ-BX及其团队编写的一款伪装成Cmd优化工具的计算机特效程序，大小为35.5KB，版本号为4.4.4.4，其目的仅用于学习和提高自我防护能力。本病毒可避开火绒的静态安全检测并正常运行。并且会进行自我复制，保持自身完整性，无法通过删除样本来隔绝病毒。本病毒开源在BX团队公开服务器内。

二、病毒的发作
病毒伪装为Cmd优化工具（CmdTool），用户运行病毒时，病毒会弹出错误窗口“本程序因文件缺失无法运行”用于迷惑用户，而后将进行自我复制并添加自启动项目，在根目录与病毒所在目录创建文本文档，内为文字“你知道吗？你的电脑已被TSY入侵，这台电脑已经是我的了:)”，然后退出运行。此后每次用户开启计算机时，病毒会自动启动。自动启动时的病毒一般时间不会进行操作，此时用户可以正常使用电脑。
病毒会分别在1月8日、7月7日、7月23日、11月4日、12月13日自我启动时进行发作，操作分别为不允许用户打开任何程序、循环弹出“Windows无法运行”窗口、修改注册表使计算机更加难以使用、自动关闭计算机与删除系统引导。但是，若用户在以上日期手动打开该病毒，则与其他时间无异。
此外，病毒在12月13日删除系统引导后，无法直接通过进行引导修复来修复该计算机，病毒会创建隐藏标记文件，并重新删除系统引导。

三、病毒的修复
如果您不幸遇上了病毒做出的所有恶意操作，不用担心。您可以通过以下方法进行修复：
    1.在您的计算机中插入PE启动盘并从该介质启动。
    2.使用DiskGenius或AOMEI等分区工具进行磁盘搜索，找回原分区，保存修改。
    3.使用引导修复工具修复原系统的引导。
    4.开始进行注册表的修改。在PE的注册表编辑器中的HKEY_LOCAL_MACHINE加载配置单元[主系统盘符]\Windows\System32\config\software与system，在HKEY_USERS加载配置单元[主系统盘符]\Users\[用户名]\ntuser.dat，然后删除以下：
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoLogOff [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoClose [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDrives
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFolderOptions
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRun
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFind
 HKEY_CURRENT_USER\Software\Policies\Microsoft\MMC\RestrictToPermittedSnapins
 HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows\Explorer\DisableNotificationCenter
 [主系统盘符]\Users\[用户名]\ntuser.dat\Software\Policies\Microsoft\Windows\System\DisableCMD
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoViewOnDrives
 [主系统盘符]\Users\[用户名]\ntuser.dat\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableTaskMgr
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\UseDefaultTile
 [主系统盘符]\Windows\System32\config\SOFTWARE\Policies\Microsoft\Windows\System\DisableLogonBackgroundImage
 [主系统盘符]\Users\[用户名]\ntuser.dat\Control Panel\Mouse\SwapMouseButtons
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\DisableCAD /f
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\HideClock
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\HideSCANetwork
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\HideSCAVolume
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFileMenu
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoStartMenuMorePrograms
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoTrayContextMenu
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoSetTaskbar
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\StartMenuLogOff
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\TaskbarLockAll
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoPropertiesMyDocuments
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\HideClock
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\HideSCANetwork
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\HideSCAVolume
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFileMenu
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoStartMenuMorePrograms
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoTrayContextMenu
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoSetTaskbar
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\StartMenuLogOff
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\TaskbarLockAll
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoPropertiesMyDocuments
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoStartMenuMyGames
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoStartMenuMyMusic
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoStartMenuNetworkPlaces
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoStartMenuPinnedList
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\EnableLUA /f
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDriveTypeAutoRun
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoSetFolders
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRealMode
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRecenDocsMenu
 HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows Defender\DisableAntiSpyware
 [主系统盘符]\Windows\System32\config\Software\Microsoft\Windows\CurrentVersion\Policies\System\HideFastUserSwitching
 [主系统盘符]\Users\[用户名]\ntuser.dat\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableChangePassword
 [主系统盘符]\Users\[用户名]\ntuser.dat\Software\Microsoft\Windows\CurrentVersion\Policies\System\DisableLockWorkstation
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoTrayItemsDisplay
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\shutdownwithoutlogon /f
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDesktop
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoLogOff /t ROEG_DWORD1
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoClose
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDrives
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFolderOptions
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoRun
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoFind
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoDesktop
 [主系统盘符]\Windows\System32\config\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoControlPanel
 [主系统盘符]\Users\[用户名]\ntuser.dat\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\NoControlPanel
 [主系统盘符]\Users\[用户名]\ntuser.dat\Software\Microsoft\Windows\CurrentVersion\Policies\System\Disableregistrytools
    5.删除系统根目录下的hints.txt。这是病毒创建的标记文件，同时删除主系统环境变量中的%temp%目录下的tsy.com。
    6.重新启动计算机。
经过以上操作后，TSY病毒就成功从您的计算机移除了。

四、病毒的源码
TSY病毒将会开源到github上。源码仅供学习，请勿用于非法用途，请遵守我国相关法律法规。若有危害网络公共安全的，需自行承担法律责任，本人概不负责。

五、结语
本人编写TSY病毒仅为学习，本文也仅作本人个人的心路历程分享。请勿将TSY病毒用作任何非法用途。

