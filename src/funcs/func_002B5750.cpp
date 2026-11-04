struct Heap_002B5750 {
    char pad0[0xE4];
    int mE4;
};

struct S_002B5750 {
    int m0;
};

struct Item_002B5750 {
    char pad0[0x30];
    int m30;
    int m34;
    int m38;
    char pad3C[0x44 - 0x3C];
    char m44[0x20];
    char m64[0x24];
    int m88;
    signed char m8C;
    char pad8D[3];
    int m90;
    int m94;
};

extern Heap_002B5750* D_00388A70;
extern S_002B5750* D_00392068;
extern char D_00392460[];
extern char D_00379C50[];
extern char D_00379C70[];
extern char D_00379C90[];
extern char D_00379CA8[];
extern char D_00379CC8[];
extern char D_00379CE0[];
extern char D_00379CF0[];
extern char D_00379D00[];
extern char D_00379D18[];
extern char D_00379D30[];
extern char D_00379D48[];
extern char D_00379D60[];
extern char D_00379D78[];
extern char D_00379D90[];
extern char D_00379DB8[];
extern char D_003924D0[];
extern char D_003924D8[];
extern char D_003924E0[];
extern char D_003924E8[];
extern char D_003924F0[];
extern char D_003924F8[];
extern char D_00392500[];
extern char D_00392490[];
extern char D_003923C8[];
extern char D_00392450[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" int func_001E8398(void* params, int name, int* out, int req);
extern "C" Item_002B5750* func_002B5098(S_002B5750* s, int id);
extern "C" char* func_001E5518(char* name, int a);
extern "C" void* func_001E55F8(char* name, int a);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001E8890(void* p, char* name, char** out, int req);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_002A1A28(S_002B5750* s);
extern "C" int func_002B5558(Item_002B5750* it, int i);
extern "C" char* func_002B54B0(Item_002B5750* it, int i);

bool func_002B5750(void* params)
{
    char buf[0x80];
    int id;
    char* str;
    S_002B5750* g = D_00392068;
    void* s;
    func_001E8398(params, func_001F0D78(D_00392460), &id, 0);
    Item_002B5750* it = func_002B5098(g, id);
    func_001F0370(D_00379C50, 0, 0, 0);
    func_0010A950(D_00388A70, D_00388A70->mE4);
    if (it->m88) {
        s = func_001E6978(func_001190D0(8));
        func_003331D0(buf, D_003924D0, func_001E5518(D_00379C70, 0));
        func_001E7138(s, D_003924D8, buf);
        func_001F0370(D_00379C90, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    }
    if (it->m90 == 1) {
        s = func_001E6978(func_001190D0(8));
        func_003331D0(buf, D_003924D0, func_001E5518(D_00379CA8, 0));
        func_001E7138(s, D_003924D8, buf);
        func_001F0370(D_00379C90, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    } else if (it->m90 == 2) {
        s = func_001E6978(func_001190D0(8));
        func_003331D0(buf, D_003924D0, func_001E5518(D_00379CC8, 0));
        func_001E7138(s, D_003924D8, buf);
        func_001F0370(D_00379C90, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    }
    s = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_003924D0, func_001E5518(D_00379CE0, 0));
    func_001E7138(s, D_003924D8, buf);
    if (it->m30 == 9999)
        func_003331D0(buf, D_00392490);
    else
        func_003331D0(buf, D_003923C8, it->m30);
    func_001E7138(s, D_003924E0, buf);
    func_001F0370(D_00379C90, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);

    s = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_003924D0, func_001E5518(D_00379CF0, 0));
    func_001E7138(s, D_003924D8, buf);
    func_003331D0(buf, D_003924E8, it->m64);
    func_001E7138(s, D_003924E0, buf);
    func_001F0370(D_00379C90, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);

    func_001E8890(func_001E9378(func_001E55F8(D_00379D00, 0), it->m8C), D_003924D8, &str, 0);
    s = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_003924D0, func_001E5518(D_00379D18, 0));
    func_001E7138(s, D_003924D8, buf);
    func_003331D0(buf, D_003924E8, str);
    func_001E7138(s, D_003924E0, buf);
    func_001F0370(D_00379C90, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);

    s = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_003924D0, func_001E5518(D_00379D30, 0));
    func_001E7138(s, D_003924D8, buf);
    func_003331D0(buf, D_003924E8, it->m44);
    func_001E7138(s, D_003924E0, buf);
    func_001F0370(D_00379C90, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);

    if (func_002A1A28(g)) {
        s = func_001E6978(func_001190D0(8));
        func_003331D0(buf, D_003924D0, func_001E5518(D_00379D48, 0));
        func_001E7138(s, D_003924D8, buf);
        if (it->m94)
            func_003331D0(buf, D_003924E8, func_001E5518(D_00379D60, 0));
        else
            func_003331D0(buf, D_003924E8, func_001E5518(D_00379D78, 0));
        func_001E7138(s, D_003924E0, buf);
        func_001F0370(D_00379C90, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    }

    s = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_003924F0, it->m34, it->m38);
    func_001E7138(s, D_00392450, buf);
    func_001F0370(D_00379D90, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);

    for (int i = 0; i < it->m34; i++) {
        int v = (int)(func_002B5558(it, i) * 0.003448275849f);
        s = func_001E6978(func_001190D0(8));
        func_003331D0(buf, D_003924F8, i + 1);
        func_001E7268(s, D_00392500, v);
        func_001E7138(s, D_003924D8, buf);
        func_003331D0(buf, D_003924E8, func_002B54B0(it, i));
        func_001E7138(s, D_003924E0, buf);
        func_001F0370(D_00379DB8, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
    }
    func_0010A9B0(D_00388A70);
    return true;
}
