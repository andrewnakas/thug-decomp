struct Rgba_001270E0 {
    unsigned char r, g, b, a;
};

struct Vec_001270E0 {
    float x, y, z, w;
};

struct Heap_001270E0 {
    char pad[0xE4];
    void* mE4;
};

struct Text_001270E0 {
    char pad[0x538];
    Rgba_001270E0 m538;
    void SetColor(Rgba_001270E0 c) { m538 = c; }
};

struct Array_001270E0 {
    char pad[0xC];
    int mC;
};

struct Obj_001270E0 {
    char pad0[0xC];
    unsigned int mC;
    char pad10[0xB8];
    Rgba_001270E0 mC8;
    char padCC[0xF0];
    int m1BC;
    int m1C0;
    float m1C4;
    float m1C8;
    char pad1CC[8];
    Text_001270E0* m1D4;
    int m1D8;
    int m1DC;
    float m1E0;
    float m1E4;
    int m1E8;
    int m1EC;
    int m1F0;
};

extern Heap_001270E0* D_00388A70;

extern "C" void func_00124328(Obj_001270E0* self, void* params);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E8870(void* params, unsigned int name, char** out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, Array_001270E0** out, int req);
extern "C" char* func_001E91C0(Array_001270E0* array, int i);
extern "C" int func_001E8998(void* params, unsigned int name, Vec_001270E0* out, int req);
extern "C" void func_001E4C80(Vec_001270E0* v);
extern "C" void func_00127658(Obj_001270E0* self, unsigned int name);
extern "C" int func_00125A10(Obj_001270E0* self, void* params, unsigned int name, int* a, int* b);
extern "C" int func_00125B78(Obj_001270E0* self, void* params, unsigned int name, void* out);
extern "C" void func_001276E0(Obj_001270E0* self, char** strs, int n);
extern "C" void func_001283E0(Obj_001270E0* self);
extern "C" void func_0010A950(void* heap, void* sub);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" Text_001270E0* func_001304A8(void* mem);
extern "C" void func_001304E0(Text_001270E0* t, int flags);

extern "C" void func_001270E0(Obj_001270E0* self, void* params)
{
    func_00124328(self, params);
    if (func_001E7EB0(params, 0x1FE341D2, &self->m1C4, 0))
        self->mC |= 0x1000;
    func_001E7EB0(params, 0xE3FA22FC, &self->m1C8, 0);
    unsigned int name;
    if (func_001E8398(params, 0x2F6BF72D, &name, 0))
        func_00127658(self, name);
    if (func_00125A10(self, params, 0x67E093E4, &self->m1BC, &self->m1C0))
        self->mC |= 0x1000;
    if (func_001E8708(params, 0x322839A2))
        self->m1DC = 1;
    char* strs[32];
    if (func_001E8870(params, 0xC4745838, &strs[0], 0)) {
        func_001276E0(self, strs, 1);
    } else {
        Array_001270E0* array;
        if (func_001E8248(params, 0xC4745838, &array, 0)) {
            int n = array->mC;
            for (int i = 0; i < n; i++)
                strs[i] = func_001E91C0(array, i);
            func_001276E0(self, strs, n);
        }
    }
    if (func_001E8708(params, 0xD1653C6C) && !self->m1D4) {
        func_0010A950(D_00388A70, D_00388A70->mE4);
        self->m1D4 = func_001304A8(func_0010A638(D_00388A70, 0x540, 1, 0));
        self->m1D4->SetColor(self->mC8);
        func_0010A9B0(D_00388A70);
    } else if (func_001E8708(params, 0x4B73E4F8) && self->m1D4) {
        func_001304E0(self->m1D4, 3);
        self->m1D4 = 0;
    }
    Rgba_001270E0 color;
    if (func_00125B78(self, params, 0x4F0E1182, &color) && self->m1D4)
        self->m1D4->SetColor(color);
    Vec_001270E0 v;
    func_001E4C80(&v);
    if (func_001E8998(params, 0x2A1FE0CC, &v, 0)) {
        self->m1E0 = v.y;
        self->m1E4 = v.z;
    }
    if (func_001E8708(params, 0x8A897DD2))
        self->m1D8 = 1;
    if (func_001E8708(params, 0x95B5B9A0))
        self->m1D8 = 0;
    func_00125B78(self, params, 0x1E7BB1F5, &self->m1E8);
    if (func_001E8708(params, 0x0BF51A0C))
        self->m1F0 = self->m1EC;
    if (func_001E8708(params, 0x61B7B58B))
        self->m1EC = self->m1F0;
    if (func_001E8708(params, 0xB7686F92))
        self->m1EC = 1;
    if (func_001E8708(params, 0xD25BC6CD))
        self->m1EC = 0;
    func_001283E0(self);
}
