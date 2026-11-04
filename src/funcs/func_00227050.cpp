extern char D_0038FA28[];
extern char D_0038FA30[];
extern char D_0038F9E8[];
extern char D_00372218[];
extern char D_00372228[];
extern int D_00388814;
extern void* D_00388EFC;

struct Script_00227050 {
    char pad[0x18];
    void* m_params;
};

class File_00227050 {
public:
    char pad[0x14];
    virtual ~File_00227050();
};

extern "C" void* func_00112FB8(void* a, int b, int c);
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" char* func_00225FE8(unsigned int type, char* name);
extern "C" char* func_00113130(void* card, char* name);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" char* func_00106810();
extern "C" char* func_002242C8(char* buf, char* name, unsigned int type);
extern "C" File_00227050* func_00113380(void* card, char* name, int mode, int a);
extern "C" int func_001139D8(File_00227050* f, int off, int whence);
extern "C" int func_00225D90(unsigned int type, int size);
extern "C" void func_001E7268(void* params, char* name, int value);
extern "C" bool func_00113A70(File_00227050* f);
extern "C" bool func_00113988(File_00227050* f);
extern "C" void func_00113110(void* card, char* name);

bool func_00227050(void* params, Script_00227050* script)
{
    void* card = func_00112FB8(D_00388EFC, 0, 0);
    if (!card)
        return false;
    char* name = 0;
    func_001E8890(params, D_0038FA28, &name, 0);
    unsigned int type = 0;
    func_001E84E8(params, D_0038FA30, &type, 0);
    if (!name || !type)
        return false;
    char path[0x70];
    char buf[0x20];
    char* fname = 0;
    path[0] = 0;
    switch (D_00388814) {
    case 4: {
        fname = func_00225FE8(type, name);
        char* dir = func_00113130(card, fname);
        if (!dir)
            return false;
        func_003331D0(path, D_0038F9E8, dir, dir);
        break;
    }
    case 1:
    case 2:
    case 3:
    case 5: {
        char* prefix = func_00106810();
        func_002242C8(buf, name, type);
        func_003331D0(path, D_00372218, prefix, buf, prefix, buf);
        break;
    }
    }
    File_00227050* f = func_00113380(card, path, 1, 0);
    if (f) {
        int size = func_001139D8(f, 0, 2);
        int v = func_00225D90(type, size);
        func_001E7268(script->m_params, D_00372228, v);
        func_00113A70(f);
        func_00113988(f);
        delete f;
        return true;
    }
    if (D_00388814 == 4)
        func_00113110(card, fname);
    return false;
}
