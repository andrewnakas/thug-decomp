extern char D_0037BBC8[];
extern char D_0037BBD8[];
extern char D_0037BC00[];
extern char D_0037B9B0[];
extern char D_00392AB0[];
extern char D_00392B98[];
extern char D_0037BC18[];

struct Entry_002D2530 {
    char pad[0x13C];
    int m13C;
};

struct Mgr_002D2530 {
    char pad[0xC];
    void* mC;
    void* m10;
};

extern Mgr_002D2530* D_00392068;
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_002D0610(Entry_002D2530* e);
extern "C" int func_002D7EB8(void* p);
extern "C" int func_001E54B8(char* s, int v);
extern "C" int func_002D30A8(void* p);
extern "C" void func_002D8248(void* p, int a, int b, int c);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_002DA188(void* p);
extern "C" int func_002DA2A8(void* p);
extern "C" int func_00305EB8(void* p);
extern "C" void func_00307150(void* p, void* q, int n, int a, char** b, char** c);
extern "C" void func_002D1390();
extern "C" void func_003072B0(void* p, void* q, char* name, int a, char** b, void (*f)(), void* e, int z);

void func_002D2530(void* conn, int ok, int unused, void* q, Entry_002D2530* e)
{
    Mgr_002D2530* mgr = D_00392068;
    if (ok) {
    func_001F0370(D_0037BBC8, 0, 0, 0);
    func_001F0370(D_0037BBD8, 0, 0, 0);
    e->m13C = 1;
    func_002D0610(e);
    if (func_002D7EB8(mgr->mC)) {
        char b0[0x40];
        char b1[0x40];
        char* arr[2];
        func_002D8248(mgr->mC, 4, func_001E54B8(D_0037BC00, 0), func_002D30A8(e));
        func_003331D0(b1, D_0037B9B0);
        func_003331D0(b0, D_00392AB0, func_002DA2A8(func_002DA188(mgr->m10)));
        arr[0] = b1;
        arr[1] = b0;
        func_00307150(conn, q, func_00305EB8(conn), 1, &arr[0], &arr[1]);
        func_003072B0(conn, q, D_00392B98, 1, arr, func_002D1390, e, 0);
    }
    } else {
        func_001F0370(D_0037BC18, 0, 0, 0);
    }
}
