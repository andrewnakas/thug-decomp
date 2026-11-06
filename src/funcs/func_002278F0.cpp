extern char D_0038F9D0[];
extern char D_0038FA28[];
extern char D_0038FA30[];
extern char D_0038FA08[];
extern char D_003722E0[];
extern int D_00388814;
extern void* D_00388EFC;
extern int D_0038F9C0;
extern void* D_0038F9C4;
extern unsigned int D_0038F9C8;

struct Card_002278F0 {
    char pad0[0xC];
    int m_state;
};

struct Data_002278F0 {
    int m_crc;
    int m_crc2;
    int m_size2;
    int m_total;
    int m_version;
    char m_data[1];
};

class File_002278F0 {
public:
    char pad[0x14];
    virtual ~File_002278F0();
};

extern "C" void func_00228DF0(int a, int b);
extern "C" void func_00228F08(int a, int b);
extern "C" void func_001DFF88(int v);
extern "C" void func_001E0038(int v);
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_00240850();
extern "C" void func_0023D750(void* self);
extern "C" void func_00229058();
extern "C" bool func_00229068();
extern "C" void func_00229088();
extern "C" void func_00229098();
extern "C" void func_002290A8();
extern "C" void func_002290B8();
extern "C" void func_002290C8();
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_00224A50(unsigned int type, void* params);
extern "C" void func_00224C60(void* out, unsigned int type, void* src);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" int func_002277F0(unsigned int type);
extern "C" int func_001E9CF8(void* s, int max);
extern "C" void* func_0010BDE0(unsigned int size);
extern "C" Card_002278F0* func_00112FB8(void* a, int b, int c);
extern "C" int func_00113198(Card_002278F0* p);
extern "C" bool func_002264C8(Card_002278F0* card, unsigned int type, char* name, char* out, int* err);
extern "C" bool func_002260F8(Card_002278F0* card, unsigned int type, char* name, char* out, int* err);
extern "C" void func_00226478(unsigned int type, char* name, char* out);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" File_002278F0* func_00113380(Card_002278F0* card, char* name, int mode, int a);
extern "C" int func_00226B70(Data_002278F0* data, Card_002278F0* card, File_002278F0* f, unsigned int type, char* name);
extern "C" int func_00225EC0(unsigned int type);
extern "C" int func_001E9B08(void* params, char* buf, int size, int a);
extern "C" int func_001053C8(void* p, int size);
extern "C" int func_00113AC0(File_002278F0* f, void* buf, int size);
extern "C" bool func_00113A70(File_002278F0* f);
extern "C" bool func_00113988(File_002278F0* f);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_001E6AE8(void* p, int v);

int func_002278F0(void* params, void* script)
{
    if (D_00388814 == 5)
        func_00228DF0(0, 0);
    if (D_00388814 != 4) {
        func_001DFF88(1);
        func_001E0038(1);
    }
    D_0038F9C0 = 0;
    char* name = D_0038F9D0;
    func_001E8890(params, D_0038FA28, &name, 0);
    unsigned int type = 0;
    func_001E84E8(params, D_0038FA30, &type, 0);
    int flag = 0;
    func_001E7DE8(params, 0xBB609E73, &flag, 0);
    if (flag)
        type = D_0038F9C8;
    else if (type == 0xB010F357)
        func_0023D750(func_00240850());
    int locked = 0;
    func_00229058();
    if (func_00229068()) {
        func_00229088();
        locked = 1;
        func_00229098();
    } else {
        func_002290A8();
    }
    void* s1 = func_001E6978(func_001190D0(8));
    if (flag)
        func_001E6AC8(s1, D_0038F9C4);
    else
        func_00224A50(type, s1);
    void* s2;
    File_002278F0* f = 0;
    s2 = func_001E6978(func_001190D0(8));
    Data_002278F0* data = 0;
    char* pad = 0;
    int result = 0;
    func_00224C60(s2, type, s1);
    func_001E7138(s2, D_003722E0, name);
    int size = func_002277F0(type);
    int n1 = func_001E9CF8(s1, size);
    int n2 = func_001E9CF8(s2, 100);
    unsigned int total = 0x14 + n2 + n1;
    unsigned int padn = size - total;
    if (padn && D_00388814 != 5) {
        pad = (char*)func_0010BDE0(padn);
        for (unsigned int i = 0; i < padn; i++)
            pad[i] = 0x69;
    }
    Card_002278F0* card = func_00112FB8(D_00388EFC, 0, 0);
    if (card && func_00113198(card)) {
        char path[0x70];
        char buf[0x70];
        switch (D_00388814) {
        case 1:
        case 2:
        case 3:
            if (!func_002264C8(card, type, name, path, &D_0038F9C0))
                goto cleanup;
            break;
        case 5:
            func_00226478(type, name, buf);
            func_003331D0(path, D_0038FA08, buf, buf);
            break;
        case 4:
            if (!func_002260F8(card, type, name, path, &D_0038F9C0))
                goto cleanup;
            break;
        default:
            goto cleanup;
        }
        f = func_00113380(card, path, 6, size);
        D_0038F9C0 = card->m_state == 2;
        if (!f)
            goto cleanup;
        data = (Data_002278F0*)func_0010BDE0(total);
        char* p = (char*)data;
        for (unsigned int i = 0; i < 20; i++)
            *p++ = 0;
        if (D_00388814 == 5 && !func_00226B70(data, card, f, type, name))
            goto cleanup;
        p = data->m_data;
        data->m_version = func_00225EC0(type);
        data->m_size2 = n2;
        data->m_total = total;
        func_001E9B08(s2, p, n2, 0);
        data->m_crc2 = func_001053C8(p, n2);
        p += n2;
        func_001E9B08(s1, p, n1, 0);
        if (type == 0xCA41692D) {
            for (unsigned int i = 0; i < (unsigned int)n1; i++)
                p[i] += 0x69;
        }
        data->m_crc = func_001053C8(data, total);
        int w = func_00113AC0(f, data, total);
        D_0038F9C0 = card->m_state == 2;
        if (w != total)
            goto cleanup;
        if (D_00388814 != 5 && padn) {
            w = func_00113AC0(f, pad, padn);
            D_0038F9C0 = card->m_state == 2;
            if (w != padn)
                goto cleanup;
        }
        result = 1;
    }
cleanup:
    if (pad)
        func_0010BEB8(pad);
    if (data)
        func_0010BEB8(data);
    if (f) {
        if (!func_00113A70(f))
            result = 0;
        if (!func_00113988(f))
            result = 0;
        delete f;
    }
    if (s2)
        func_001E6AE8(s2, 3);
    if (s1)
        func_001E6AE8(s1, 3);
    if (locked) {
        func_002290A8();
        func_002290B8();
        func_002290C8();
    }
    if (D_00388814 != 4) {
        func_001DFF88(-1);
        func_001E0038(-1);
    }
    if (D_00388814 == 5)
        func_00228F08(0, 0);
    return result;
}
