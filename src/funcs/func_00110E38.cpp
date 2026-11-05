extern int D_0038881C;
extern char D_0035BE90[];
extern "C" int func_001092D0();
extern "C" int func_001092E0();
extern "C" int func_001E5628(unsigned int checksum, int a);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void* func_00109328(const char* name, const char* mode, int a);
extern "C" void* func_001103E8(const char* name, const char* mode);
extern "C" void* func_0010FF90(const char* name, const char* mode);

extern "C" void* func_00110E38(const char* name, const char* mode)
{
    bool notWrite = mode[0] != 'w';
    if (func_001E5628(0xE99935C2, 0)) {
        func_00103F28(D_0035BE90, name);
    }
    if (notWrite && func_001092D0()) {
        void* r = func_00109328(name, mode, 0);
        if (func_001092E0()) {
            return r;
        }
    }
    if (D_0038881C) {
        return func_0010FF90(name, mode);
    }
    return func_001103E8(name, mode);
}
