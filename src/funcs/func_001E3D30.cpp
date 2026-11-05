struct CdFile_001E3D30 {
    unsigned int lsn;
    unsigned int size;
    char name[16];
    unsigned char date[8];
    int pad;
};

extern char D_00364688[];
extern char D_00364698[];
extern "C" void func_001E2AA8();
extern "C" void func_0010FE68();
extern "C" void func_00328660(int a);
extern "C" char* func_00106818();
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_00331BB8(char* s);
extern "C" int func_00328438(CdFile_001E3D30* f, char* name);
extern "C" void func_00103F28(char* fmt, ...);

unsigned int func_001E3D30(char* name)
{
    char buf[0x100];
    CdFile_001E3D30 file;
    func_001E2AA8();
    func_0010FE68();
    func_00328660(0);
    func_003331D0(buf, D_00364688, func_00106818(), name);
    for (int i = func_00331BB8(buf) - 1; i > 0; i--) {
        unsigned char c = buf[i];
        if ((unsigned int)(c - 'a') < 26) buf[i] = c - 0x20;
    }
    if (!func_00328438(&file, buf)) {
        func_00103F28(D_00364698, buf, 0);
        return 0;
    }
    return file.lsn;
}
