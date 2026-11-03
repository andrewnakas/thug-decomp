extern char D_0037BE18[];
extern char D_0037BE00[];
extern char D_0037BDD8[];
extern char D_0037BC50[];
extern char D_0037BC60[];
extern char D_0037BC70[];
extern char D_00392BA0[];
extern char D_0037BC80[];
extern char D_00392BA8[];
extern char D_00392BB0[];
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* p, int v);
extern "C" void func_002E42A0(int id, char* name);
extern "C" void func_002D26C0();
extern "C" void func_002D2700();
extern "C" void func_002D2850();

struct Head_002D29A0 {
    int m0;
    unsigned int m4;
    int m8;
    Head_002D29A0* mC;
    Head_002D29A0* m10;
    void* vt;
    Head_002D29A0(char* v) { vt = v; m4 = 0xFFFFFFFF; m8 = 0; mC = this; m10 = this; }
};

struct Head2_002D29A0 {
    int m0;
    unsigned int m4;
    int m8;
    Head2_002D29A0* mC;
    Head2_002D29A0* m10;
    void* vt;
    Head2_002D29A0(char* v) { vt = v; m4 = 0xFFFFFFFF; mC = this; m10 = this; m8 = 0; }
};

struct Cb_002D29A0 {
    char pad[0x18];
    void* vt;
    void* fn;
    void* owner;
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Cb_002D29A0(void* f, void* o) { func_001047F8(this, 0); vt = D_0037BDD8; fn = f; owner = o; }
};

struct Mgr_002D29A0 : Head_002D29A0 {
    Head2_002D29A0 m18;
    char pad30[0x13C - 0x30];
    int m13C;
    int m140;
    int m144;
    char pad148[0x154 - 0x148];
    int m154;
    int m158;
    int m15C;
    Cb_002D29A0* m160;
    Cb_002D29A0* m164;
    Cb_002D29A0* m168;
    Mgr_002D29A0();
};

Mgr_002D29A0::Mgr_002D29A0() : Head_002D29A0(D_0037BE18), m18(D_0037BE00)
{
    m154 = 0;
    m13C = 0;
    m158 = 0;
    m144 = 1;
    m160 = new Cb_002D29A0((void*)func_002D26C0, this);
    m164 = new Cb_002D29A0((void*)func_002D2700, this);
    m168 = new Cb_002D29A0((void*)func_002D2850, this);
    func_002E42A0(0x33, D_0037BC50);
    func_002E42A0(0x34, D_0037BC60);
    func_002E42A0(0x35, D_0037BC70);
    func_002E42A0(0x36, D_00392BA0);
    func_002E42A0(0x37, D_0037BC80);
    func_002E42A0(0x38, D_00392BA8);
    func_002E42A0(0x39, D_00392BB0);
}
