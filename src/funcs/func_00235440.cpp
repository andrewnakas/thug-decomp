typedef int (*Handler_00235440)(void* msg);

extern "C" int func_002317A0(void* msg);
extern "C" int func_002318F0(void* msg);
extern "C" int func_00231850(void* msg);
extern "C" int func_00231A78(void* msg);
extern "C" int func_00231F88(void* msg);
extern "C" int func_00231FE8(void* msg);
extern "C" int func_00233B28(void* msg);
extern "C" int func_00231A28(void* msg);
extern "C" int func_00231C60(void* msg);
extern "C" int func_00231E30(void* msg);
extern "C" void* func_001FBF60(void* disp, int id, Handler_00235440 h, int flags, void* data, int mask);
extern "C" bool func_002A1998(void* net);
extern "C" void func_002A3870(void* net);
extern "C" void* func_002A2680(void* net, int a, int b);
extern "C" void func_00105260(void* list, void* node);
extern "C" bool func_00201288(void* client);

extern void* D_00392068;

struct Lists_00235440 {
    char pad[8];
    char m_list[1];
};

extern Lists_00235440* D_0038C308;

struct Obj_00235440 {
    char pad[0x1C];
    void* m_1C;
    void* m_20;
};

struct Client_00235440 {
    int pad;
    char m_disp[1];
};

void func_00235440(Obj_00235440* obj)
{
    void* net = D_00392068;
    bool locked = false;
    Lists_00235440* lists = D_0038C308;
    if (func_002A1998(net)) {
        locked = true;
        func_002A3870(net);
    }
    Client_00235440* client = (Client_00235440*)func_002A2680(net, !locked, 1);
    if (client) {
        func_00105260(lists->m_list, obj->m_1C);
        func_00105260(lists->m_list, obj->m_20);
        void* disp = client->m_disp;
        func_001FBF60(disp, 0x3B, func_002317A0, 0, 0, 0x80);
        func_001FBF60(disp, 0x52, func_002318F0, 0, obj, 0x80);
        func_001FBF60(disp, 0x86, func_00231850, 0, obj, 0x80);
        func_001FBF60(disp, 0x4C, func_00231A78, 2, 0, 0x80);
        func_001FBF60(disp, 0x45, func_00231F88, 2, 0, 0x80);
        func_001FBF60(disp, 0x23, func_00231FE8, 3, 0, 0x80);
        if (!func_00201288(client)) {
            func_001FBF60(disp, 0x7E, func_00233B28, 0, 0, 0x80);
            func_001FBF60(disp, 0x83, func_00231A78, 0, obj, 0x80);
            func_001FBF60(disp, 0x89, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x89, func_00231A28, 0, 0, 0x80);
            func_001FBF60(disp, 0x29, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x2B, func_00231C60, 0, 0, 0x80);
            func_001FBF60(disp, 0x2A, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x76, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x8C, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x77, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x78, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x2C, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x3C, func_00231C60, 0, 0, 0x80);
            func_001FBF60(disp, 0x3D, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x3E, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x41, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x35, func_00231C60, 0, 0, 0x80);
            func_001FBF60(disp, 0x36, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x39, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x3A, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x37, func_00231A78, 0, 0, 0x80);
            func_001FBF60(disp, 0x38, func_00231A78, 2, 0, 0x80);
            func_001FBF60(disp, 0x48, func_00231E30, 2, 0, 0x80);
            func_001FBF60(disp, 0x49, func_00231E30, 2, 0, 0x80);
        }
    }
}
