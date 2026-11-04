extern "C" void func_001325A0();
extern "C" void func_00174170(int a);
extern "C" void* func_00240850();
extern "C" void func_0023C298(void* p, int a);
extern "C" void func_0023C1A0(void* p);
extern "C" void func_002C5370(void* p);
extern "C" void func_002C5338(void* p);
extern "C" void func_001235E0();
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" void func_0022E0F8(void* p);
extern "C" void func_00144F10(void* p);
extern "C" void func_00143578();
extern "C" void func_00229520();
extern "C" void func_001440C0(int a);
extern "C" void func_001F0F28();
extern "C" void func_001DBFE0();
extern "C" void func_001DC7B0(void* p);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_001D0A08(void* p, int a);
extern "C" void* func_001E4FC8(unsigned int name);
extern "C" void func_002294C0(void* p);
extern "C" void func_00210C60(int a, int b);
extern "C" void func_0010B8E0(void* p);
extern "C" void* func_0010DD88(void* p);
extern "C" bool func_0010DE48(void* p);
extern "C" void func_0010D970(void* p);
extern "C" void func_00109128(void* p, const char* name, int a);
extern "C" void func_0013B2D8();
extern "C" void func_001363F0();
extern "C" void func_0013A9F0(int a);
extern "C" void* func_00259EB8();
extern "C" void func_0025A190(void* p);
extern "C" bool func_00230648(void* p);
extern "C" bool func_002306A0(void* p);
extern "C" void func_0010B428(void* p);
extern "C" void func_0010B4A0(void* p);
extern "C" void func_0010B4F8(void* p);
extern "C" void func_0010B590(void* p);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_0010BD68(void* p, unsigned int id, int a);

extern void* D_00392808;
extern void* D_0038FC78;
extern void* D_00389C30;
extern void* D_0038E0A0;
extern void* D_0038DB38;
extern void* D_00388A70;
extern void* D_00388A44;
extern void* D_00394138[2];
extern char D_003707D8[];
extern char D_003707F0[];
extern char D_00370818[];
extern char D_00370840[];
extern char D_00370878[];
extern char D_003708A8[];
extern char D_003708D0[];
extern char D_0038F568[];

struct Script_00213420 {
    char pad[0xCC];
    unsigned int m_flag : 1;
};

struct Item_00213420 {
    int m0;
    int m4;
    void* m8;
};

bool Cmd_00213420(void* params, Script_00213420* script)
{
    int preserve = 0;
    func_001325A0();
    func_00174170(0);
    void* p = func_00240850();
    func_0023C298(p, 0);
    func_0023C1A0(p);
    void* q = D_00392808;
    func_002C5370(q);
    func_002C5338(q);
    void* game = D_0038FC78;
    func_001235E0();
    if (params) {
        preserve = func_001E87B8(params, D_003707D8);
    }
    int saved = 0;
    if (script) {
        saved = script->m_flag;
        script->m_flag = 0;
    }
    func_0022E0F8(game);
    if (script) {
        script->m_flag = saved;
    }
    func_00144F10(D_00389C30);
    func_00143578();
    func_00229520();
    func_001440C0(0);
    func_001F0F28();
    func_001DBFE0();
    func_001DC7B0(D_0038E0A0);
    func_00103F28(D_003707F0);
    func_001D0A08(D_0038DB38, 0);
    func_00103F28(D_00370818);
    Item_00213420* item = (Item_00213420*)func_001E4FC8(0xC472ECC5);
    if (item) {
        func_002294C0(item->m8);
    }
    for (int i = 0; i < 2; i++) {
        func_002294C0(D_00394138[i]);
        D_00394138[i] = 0;
    }
    func_00103F28(D_00370840);
    func_00210C60(0, 0);
    func_00103F28(D_00370878);
    if (!preserve) {
        func_00103F28(D_003708A8);
        func_0010B8E0(D_00388A70);
    }
    void* node = func_0010DD88(0);
    while (node) {
        void* next = func_0010DD88(node);
        if (!func_0010DE48(node)) {
            func_0010D970(node);
        }
        node = next;
    }
    func_00109128(D_00388A44, D_003708D0, 1);
    func_0013B2D8();
    func_001363F0();
    func_0013A9F0(0);
    func_0025A190(func_00259EB8());
    if (func_00230648(game)) {
        func_0010B428(D_00388A70);
    } else {
        func_0010B4A0(D_00388A70);
    }
    void* mem = D_00388A70;
    func_0010BD68(mem, func_001F0D78(D_0038F568), 0);
    if (func_002306A0(game)) {
        func_0010B4F8(D_00388A70);
    } else {
        func_0010B590(D_00388A70);
    }
    return true;
}
