extern char D_00372778[];
extern char D_00372748[];
extern char D_00372758[];
extern char D_003727C8[];
extern char D_003727A0[];
extern int D_0038881C;
extern void* D_0038EB78;
extern float D_00394348;
extern float D_00394344;

struct Viewer_0022BC20;
extern Viewer_0022BC20* D_0038FC00;

extern "C" void func_0022ACB0();
extern "C" void func_0022A920();
extern "C" void func_0022B408();
extern "C" void func_0022A8A8();

struct Handler_0022BC20 {
    char pad[0x18];
    void* m_vtbl;
    void (*m_func)();
    Viewer_0022BC20* m_data;
};

struct Input_0022BC20 {
    char pad[0x18];
    void* m_vtbl;
    char pad1C[8];
    int m_24;
    void (*m_func)();
    Viewer_0022BC20* m_data;
};

struct Viewer_0022BC20 {
    char pad[0x14];
    void* m_vtbl;
    Input_0022BC20* m_18;
    Input_0022BC20* m_1C;
    Handler_0022BC20* m_20;
    Handler_0022BC20* m_24;
    char pad28[0x28];
    int m_50;
    int m_54;
    char pad58[4];
    void* m_5C;
};

extern "C" Viewer_0022BC20* func_001829A8(Viewer_0022BC20* self);
extern "C" void* func_001FA640(void* net);
extern "C" int func_00326E30(void* a);
extern "C" void func_001F9EF0(void* net);
extern "C" void* func_001F9150(void* net, int a, char* name, int b, int c, int d, int e);
extern "C" int func_001E5628(unsigned int key, int a);
extern "C" void* func_001046B0(int size);
extern "C" void func_001047F8(void* self, int pri);
extern "C" int func_00103F28(const char* fmt, ...);

static inline void InitHandler_0022BC20(Handler_0022BC20* h, void (*f)(), Viewer_0022BC20* d)
{
    func_001047F8(h, 0);
    h->m_vtbl = D_003727C8;
    h->m_func = f;
    h->m_data = d;
}

static inline void InitInput_0022BC20(Input_0022BC20* in, int pri, int id, void (*f)(), Viewer_0022BC20* d)
{
    func_001047F8(in, pri);
    in->m_24 = id;
    in->m_vtbl = D_003727A0;
    in->m_func = f;
    in->m_data = d;
}

Viewer_0022BC20* func_0022BC20(Viewer_0022BC20* self)
{
    func_001829A8(self);
    self->m_vtbl = D_00372778;
    self->m_50 = 0;
    self->m_54 = 0;
    if (!D_0038881C) {
        void* net = D_0038EB78;
        func_00326E30(func_001FA640(net));
        func_001F9EF0(net);
        self->m_5C = func_001F9150(net, 0, D_00372748, 4, 10000, func_00326E30(func_001FA640(net)), 16);
    }
    int id = func_001E5628(0x702247A5, 0);

    Handler_0022BC20* h1 = (Handler_0022BC20*)func_001046B0(0x24);
    InitHandler_0022BC20(h1, func_0022ACB0, self);
    self->m_20 = h1;

    Input_0022BC20* in1 = (Input_0022BC20*)func_001046B0(0x30);
    InitInput_0022BC20(in1, 0, id, func_0022A920, self);
    self->m_18 = in1;

    D_00394348 = 400.0f;
    D_00394344 = 120.0f;
    func_00103F28(D_00372758);

    Handler_0022BC20* h2 = (Handler_0022BC20*)func_001046B0(0x24);
    InitHandler_0022BC20(h2, func_0022B408, self);
    self->m_24 = h2;

    Input_0022BC20* in2 = (Input_0022BC20*)func_001046B0(0x30);
    InitInput_0022BC20(in2, 1000, id, func_0022A8A8, self);
    self->m_1C = in2;

    D_0038FC00 = self;
    return self;
}
