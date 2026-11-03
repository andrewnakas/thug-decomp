extern char D_0037B9D8[];
extern char D_0037B808[];
extern char D_0037BAF0[];
extern char D_0037BB08[];

struct Mgr_002D1E70 {
    char pad[0xC];
    void* mC;
};

extern Mgr_002D1E70* D_00392068;
extern "C" int func_002A1A38(void* s);
extern "C" void* func_002D3D30(void* p);
extern "C" void func_002A39D0(void* s, unsigned short port);
extern "C" void func_002A39C0(void* s, int ip);
extern "C" int func_00305F68(void* p);
extern "C" void func_002A39C8(void* s, int v);
extern "C" void* func_002A6070(void* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8890(void* s, char* name, int* out, int a);
extern "C" int func_002D30A8(void* p);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_002D7EB8(void* p);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_002D8248(void* p, int a, int b, char* c);

void func_002D1E70(void* self, int ip, unsigned short port, void* peer)
{
    char buf[1024];
    int val;
    Mgr_002D1E70* mgr = D_00392068;
    void* q = mgr->mC;
    if (!func_002A1A38(mgr))
        return;
    if (!func_002D3D30(peer))
        return;
    func_002A39D0(mgr, port);
    func_002A39C0(mgr, ip);
    func_002A39C8(mgr, func_00305F68(func_002D3D30(peer)));
    func_001E8890(func_00202EF8(func_002A6070(mgr), func_001F0D78(D_0037B9D8)), D_0037B808, &val, 1);
    func_003331D0(buf, D_0037BAF0, ip, func_00305F68(func_002D3D30(peer)), port, val, func_002D30A8(peer));
    if (func_002D7EB8(q))
        func_002D8248(q, 2, func_001E54B8(D_0037BB08, 0), buf);
}
