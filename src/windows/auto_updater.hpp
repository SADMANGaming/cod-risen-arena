void CL_GetAutoUpdate_f();
bool UnzipWithPowerShell(const char* zipPath, const char* destPath);
const char* isUpdateable();
const char* getLatestUpdate();
void CL_CheckAutoUpdate(); //Run in Com_Init or somewhere??????????