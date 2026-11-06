typedef int qword __attribute__((mode(TI)));

union Vec_0018BAF8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Arr_0018BAF8 {
    char pad0[0xC];
    unsigned int m_size;
    unsigned int GetSize() { return m_size; }
};

struct Holder_0018BAF8 {
    char pad0[0x260];
    void* m_model;
};

struct Obj_0018BAF8 {
    char pad0[0x104];
    unsigned int m_flags;
};

struct Comp_0018BAF8 {
    char pad0[0xC];
    Obj_0018BAF8* m_obj;
    char pad10[0x20 - 0x10];
    Vec_0018BAF8 m20;
    char pad30[0x260 - 0x30];
    void* m_model;
    char pad264[0x284 - 0x264];
    int m284;
    int m288;
    void InitFromParams(void* params);
};

extern char D_0038C8D8[];
extern char D_0038C8E0[];
extern char D_00361DE8[];
extern char D_00361DF8[];
extern char D_00361E08[];
extern void* D_0038C608;

extern "C" void func_00104418(char* s);
extern "C" int func_00131288(Vec_0018BAF8* v, void* params);
extern "C" void func_00131738(const char* name, char* ext, char* out);
extern "C" void* func_001317D0(unsigned int name);
extern "C" void* func_00134F18(void* p);
extern "C" void* func_0013C2E0(void* p, int a, int b);
extern "C" void* func_0013C380(void* p, int a, void* model);
extern "C" void func_0013C568(void* r, int a);
extern "C" void func_0013D170(void* model, unsigned int name, int a, int b);
extern "C" void func_0013D2F0(void* model, char* s, int a, int b, int c, int d, int e);
extern "C" void func_0013D518(void* model, void* r, unsigned int name);
extern "C" int func_0013D8B0(void* model, int a);
extern "C" void* func_0013DA40(void* model, unsigned int name);
extern "C" void func_0013EA58(void* model);
extern "C" void func_0013EDD0(void* model, Vec_0018BAF8* v);
extern "C" Vec_0018BAF8 func_0013EF90(void* model);
extern "C" Holder_0018BAF8* func_00185578(void* obj, unsigned int name);
extern "C" void* func_00187B48(void* mgr, unsigned int name);
extern "C" void func_0018B860(Comp_0018BAF8* c, unsigned int name);
extern "C" void func_0018C1C0(Comp_0018BAF8* c, int lod, float dist);
extern "C" void func_0018DC18(Comp_0018BAF8* c);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7F50(void* params, char* name, float* out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, Arr_0018BAF8** out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E8870(void* params, unsigned int name, const char** out, int req);
extern "C" int func_001E8890(void* params, char* name, const char** out, int req);
extern "C" unsigned int func_001E9300(Arr_0018BAF8* a, unsigned int i);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_003364D8(char* a, char* b);

void Comp_0018BAF8::InitFromParams(void* params)
{
    func_0013EA58(m_model);
    Vec_0018BAF8 scale;
    scale.f.x = 1.0f;
    scale.f.y = 1.0f;
    scale.f.z = 1.0f;
    scale.f.w = 1.0f;
    if (func_00131288(&scale, params)) {
        func_0013EDD0(m_model, &scale);
    }
    unsigned int asset = 0;
    unsigned int type = 0;
    func_001E8398(params, 0x12B4E660, &type, 0);
    if (type == 0xB7B3BD86) {
        unsigned int name;
        func_001E8398(params, 0xA1DC81F9, &name, 1);
        func_0018B860(this, name);
    } else {
        int a = 1;
        func_001E7DE8(params, 0xC63C8D38, &a, 0);
        int b = 0;
        func_001E7DE8(params, 0xF891AC27, &b, 0);
        unsigned int c;
        if (func_001E8398(params, 0x153A84DE, &c, 0)) {
            m288 = 1;
            m284 = c;
            func_0013D8B0(m_model, 6);
        } else {
            unsigned int d;
            if (func_001E8398(params, 0x86BD5B8F, &d, 0)) {
                int e = 0;
                func_001E7DE8(params, 0x92B43E79, &e, 0);
                func_0013D170(m_model, d, 0, e != 0);
            } else {
                unsigned int f;
                if (func_001E8398(params, 0x7DD037B3, &f, 0)) {
                    Holder_0018BAF8* h = func_00185578(func_00187B48(D_0038C608, f), 0x286A8D26);
                    Arr_0018BAF8* arr = 0;
                    unsigned int g;
                    if (func_001E8398(params, 0xE7308C1F, &g, 0)) {
                        void* r = func_0013C380(func_0013DA40(h->m_model, g), 1, m_model);
                        func_0013C568(r, 1);
                        func_0013D518(m_model, r, g);
                    } else if (func_001E8248(params, 0x44E31DFF, &arr, 0)) {
                        for (unsigned int i = 0; i < arr->GetSize(); i++) {
                            unsigned int cs = func_001E9300(arr, i);
                            if (cs) {
                                void* r = func_0013C380(func_0013DA40(h->m_model, cs), 1, m_model);
                                func_0013C568(r, 1);
                                func_0013D518(m_model, r, cs);
                            }
                        }
                    }
                } else {
                    const char* str;
                    if (func_001E8870(params, 0x286A8D26, &str, 0) || func_001E8870(params, 0xB974F2FC, &str, 0)) {
                        if (func_001F0D78(str) != 0x806FFF30) {
                            char name[0x200];
                            unsigned int h;
                            if (func_001E8398(params, 0x09794932, &h, 0)) {
                                func_00131738(str, D_0038C8D8, name);
                            } else {
                                func_00131738(str, D_0038C8E0, name);
                            }
                            func_00104418(name);
                            int x = func_001E8708(params, 0x6C37FDC7);
                            if (func_003364D8(name, D_00361DE8)) {
                                a = 0;
                            }
                            func_0013D2F0(m_model, name, 0, a != 0, b, x, 0);
                            int last = 0;
                            for (int k = 0; k < 4; k++) {
                                float dist;
                                unsigned int q;
                                char key[0x100];
                                func_003331D0(key, D_00361DF8, last + 1);
                                if (func_001E8890(params, key, &str, 0)) {
                                    func_003331D0(key, D_00361E08, last + 1);
                                    if (func_001E7F50(params, key, &dist, 0)) {
                                        if (func_001E8398(params, 0x09794932, &q, 0)) {
                                            func_00131738(str, D_0038C8D8, name);
                                        } else {
                                            func_00131738(str, D_0038C8E0, name);
                                        }
                                        func_00104418(name);
                                        func_0013D2F0(m_model, name, last + 1, a != 0, b, 0, 0);
                                        func_0018C1C0(this, last + 1, dist);
                                        last++;
                                    }
                                }
                            }
                        }
                    } else if (func_001E8398(params, 0x286A8D26, &asset, 0)) {
                        void* r = func_0013C2E0(func_00134F18(func_001317D0(asset)), 1, 0);
                        func_0013C568(r, 1);
                        func_0013D518(m_model, r, 0);
                    }
                }
            }
        }
    }
    if (m_obj->m_flags & 0x20) {
        func_0018DC18(this);
    }
    m20 = func_0013EF90(m_model);
}
