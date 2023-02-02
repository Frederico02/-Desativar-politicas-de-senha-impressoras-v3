/*            Desativar politicas de senha impressoras     */
/*		              Refatorado em 23/01/2023             */
/*	Frederico Almeida - Analista de Suporte Jr - Gupo Multi */


#include <windows.h>

int main() {
		
	// esconder prompt de comando
	ShowWindow(GetConsoleWindow(), SW_HIDE); 
	
    HKEY hKey;
    DWORD dwValue = 0;
    LONG lError = RegCreateKeyEx(HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Policies\\Microsoft\\Windows NT\\printers\\PointAndPrint",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL);
    if (lError == ERROR_SUCCESS) {
        lError = RegSetValueEx(hKey,
            "RestrictDriverInnstallationToAdministrators",
            0,
            REG_DWORD,
            (BYTE*)&dwValue,
            sizeof(dwValue));
        if (lError != ERROR_SUCCESS) {
            // handle error
        }
        RegCloseKey(hKey);
    }
    else {
        // handle error
    }
    return 0;
}
