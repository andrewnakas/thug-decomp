extern char D_0038F9D0[];
extern char D_0038FA28[];
extern char D_0038FA30[];
extern char D_0038F9E8[];
extern char D_0038FA08[];
extern char D_00372218[];
extern char D_00372340[];
extern char D_00372350[];
extern int D_00388814;
extern void* D_00388EFC;
extern void* D_0038F9C4;
extern unsigned int D_0038F9C8;

struct Script_00227F98 {
    char pad[0x18];
    void* m_params;
};

struct Data_00227F98 {
    int m_crc;
    int pad4;
    int pad8;
    int m_size;
    int m_version;
    char m_data[1];
};

class File_00227F98 {
public:
    char pad[0x14];
    virtual ~File_00227F98();
};

extern "C" void func_001DFF88(int v);
extern "C" void func_001E0038(int v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_00112FB8(void* a, int b, int c);
extern "C" int func_00113198(void* p);
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" char* func_00225FE8(unsigned int type, char* name);
extern "C" char* func_00113130(void* card, char* name);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" char* func_00106810();
extern "C" char* func_002242C8(char* buf, char* name, unsigned int type);
extern "C" void func_00226478(unsigned int type, char* name, char* out);
extern "C" File_00227F98* func_00113380(void* card, char* name, int mode, int a);
extern "C" int func_001139D8(File_00227F98* f, int off, int whence);
extern "C" Data_00227F98* func_0010BDE0(int size);
extern "C" int func_00113B10(File_00227F98* f, Data_00227F98* buf, int size);
extern "C" int func_001053C8(void* p, int size);
extern "C" int func_00225EC0(unsigned int type);
extern "C" char* func_001E9D70(void* s, void* src);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_002259B0(unsigned int type, void* s, Script_00227F98* script);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" bool func_00113988(File_00227F98* f);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_001E6AE8(void* p, int v);

int func_00227F98(void* params, Script_00227F98* script)
{
    if (D_00388814 != 4) {
        func_001DFF88(1);
        func_001E0038(1);
    }
    File_00227F98* f = 0;
    Data_00227F98* data = 0;
    int result = 0;
    void* s1 = func_001E6978(func_001190D0(8));
    void* s2 = func_001E6978(func_001190D0(8));
    unsigned int type = 0;
    char* name = D_0038F9D0;
    int flag = 0;
    func_001E7DE8(params, 0x8C6808D4, &flag, 0);
    void* card = func_00112FB8(D_00388EFC, 0, 0);
    if (card && func_00113198(card)) {
        func_001E8890(params, D_0038FA28, &name, 0);
        func_001E84E8(params, D_0038FA30, &type, 0);
        char path[0x70];
        char buf[0x20];
        char buf2[0x70];
        path[0] = 0;
        switch (D_00388814) {
        case 1:
        case 2:
        case 3: {
            char* prefix = func_00106810();
            func_002242C8(buf, name, type);
            func_003331D0(path, D_00372218, prefix, buf, prefix, buf);
            break;
        }
        case 5:
            func_00226478(type, name, buf2);
            func_003331D0(path, D_0038FA08, buf2, buf2);
            break;
        case 4: {
            char* dir = func_00113130(card, func_00225FE8(type, name));
            if (!dir)
                goto cleanup;
            func_003331D0(path, D_0038F9E8, dir, dir);
            break;
        }
        default:
            goto cleanup;
        }
        f = func_00113380(card, path, 1, 0);
        if (!f)
            goto nofile;
        int size = func_001139D8(f, 0, 2);
        data = func_0010BDE0(size);
        func_001139D8(f, 0, 0);
        if (func_00113B10(f, data, size) != size)
            goto cleanup;
        int crc = data->m_crc;
        int ok = 0;
        data->m_crc = 0;
        if (data->m_size <= 500000 && func_001053C8(data, data->m_size) == crc)
            ok = data->m_version == func_00225EC0(type);
        if (ok) {
            char* p = func_001E9D70(s1, data->m_data);
            if (type == 0xCA41692D) {
                int n = data->m_size - (p - (char*)data);
                for (int i = 0; i < n; i++)
                    p[i] -= 0x69;
            }
            func_001E9D70(s2, p);
            if (flag) {
                void* g = func_001E6978(func_001190D0(8));
                D_0038F9C4 = g;
                func_001E6AC8(g, s2);
                D_0038F9C8 = type;
                if (type == 0x61A1BC57)
                    func_002259B0(0x61A1BC57, s2, script);
            } else {
                func_002259B0(type, s2, script);
            }
            result = 1;
        } else {
            void* sp = script->m_params;
            func_001E7360(sp, 0, func_001F0D78(D_00372340));
        }
        if (result && !flag)
            func_001F0370(D_00372350, params, 0, 0);
    }
cleanup:
    if (f) {
        func_00113988(f);
        delete f;
    }
nofile:
    if (data)
        func_0010BEB8(data);
    if (s1)
        func_001E6AE8(s1, 3);
    if (s2)
        func_001E6AE8(s2, 3);
    if (D_00388814 != 4) {
        func_001DFF88(-1);
        func_001E0038(-1);
    }
    return result;
}
