extern void* D_0038EB78;
extern char D_003920B0[];
extern char D_003920B8[];
extern char D_003920C0[];
extern char D_00377F70[];
extern char D_00377F90[];
extern char D_00377FA8[];
extern char D_00377FC8[];
extern char D_00377FE8[];
extern char D_00377FF8[];
extern char D_00378018[];
extern char D_00378038[];
extern char D_00378058[];
extern char D_00378078[];
extern char D_00378098[];
extern char D_003780B8[];
extern char D_003780D8[];
extern char D_003780F0[];
extern char D_00378110[];
extern char D_00378128[];
extern char D_00378148[];

struct Front_002A0438 {
    char pad0[0x180];
    int m180;
    char pad184[0x1A0 - 0x184];
    unsigned int m1A0;
};

extern "C" int func_001FA698(void* n);
extern "C" int func_001FA648(void* n);
extern "C" int func_001FA550(void* n);
extern "C" int func_001FA198(void* n);
extern "C" int func_001FA6A8(void* n);
extern "C" void func_002A7918(Front_002A0438* f);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" char* func_001E5488(int id, int v);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E7A30(void* p, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001F0210(unsigned int name, void* a, int b, int c, int d);

struct Obj_002A0438 {
    char pad0[0x20];
    Front_002A0438* m20;
    void Update();
};

void Obj_002A0438::Update()
{
    void* net = D_0038EB78;
    Front_002A0438* f = m20;
    int st = func_001FA698(net);
    if (st != f->m180) {
        void* p = func_001E6978(func_001190D0(8));
        char buf[128];
        switch (st) {
        case 0:
            if (func_001FA648(net) == 3)
                func_003331D0(buf, D_003920B0, func_001E54B8(D_00377F70, 0));
            else
                func_003331D0(buf, D_003920B8, func_001E54B8(D_00377F90, 0), func_001FA550(net));
            func_001E7A30(p, func_001F0D78(D_003920C0), 3, buf);
            func_001F0370(D_00377FA8, p, 0, 0);
            break;
        case 1:
            func_001E7A30(p, func_001F0D78(D_003920C0), 3, func_001E54B8(D_00377FC8, 0));
            func_001F0370(D_00377FA8, p, 0, 0);
            break;
        case 2:
            if (func_001FA648(net) == 1)
                func_003331D0(buf, D_00377FE8, func_001E54B8(D_00377FF8, 0), func_001FA198(net));
            else
                func_003331D0(buf, D_003920B0, func_001E54B8(D_00377FF8, 0));
            func_001E7A30(p, func_001F0D78(D_003920C0), 3, buf);
            func_001F0370(D_00378018, p, 0, 0);
            break;
        case 3:
            func_001E7A30(p, func_001F0D78(D_003920C0), 3, func_001E54B8(D_00378038, 0));
            func_001F0370(D_00378058, p, 0, 0);
            break;
        case 4:
            func_001E7A30(p, func_001F0D78(D_003920C0), 3, func_001E54B8(D_00378078, 0));
            func_001F0370(D_00378058, p, 0, 0);
            break;
        case 5:
            func_001E7A30(p, func_001F0D78(D_003920C0), 3, func_001E54B8(D_00378098, 0));
            func_001F0370(D_00378018, p, 0, 0);
            break;
        case 6:
            func_002A7918(f);
            if (f->m1A0) func_001F0210(f->m1A0, 0, 0, 0, 0);
            break;
        case 7: {
            int id;
            switch (func_001FA6A8(net)) {
            case 3:
                id = func_001F0D78(D_003780B8);
                break;
            case 6:
                id = func_001F0D78(D_003780D8);
                break;
            case 5:
                id = func_001F0D78(D_003780F0);
                break;
            case 8:
                id = func_001F0D78(D_00378110);
                break;
            case 11:
                id = func_001F0D78(D_00378148);
                break;
            case 4:
            case 7:
            case 9:
            case 10:
            default:
                id = func_001F0D78(D_00378128);
                break;
            }
            func_001E7A30(p, func_001F0D78(D_003920C0), 3, func_001E5488(id, 0));
            func_001F0370(D_00378018, p, 0, 0);
            break;
        }
        }
        if (p) func_001E6AE8(p, 3);
    }
    f->m180 = st;
}
