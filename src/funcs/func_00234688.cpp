struct Info_00234688 {
    char m0;
    char m1;
    unsigned char m2;
    char m3;
    char m4;
    char pad5[3];
    int m8;
    int padC;
    unsigned long m10;
    int m18;
    int m1C;
    int m20;
    int m24;
    char m28[1];
};

struct Self_00234688 {
    Info_00234688* m_info;
    int pad4[4];
    void* m14;
    int pad18;
    void* m1C;
};

struct Array_00234688 {
    int pad[3];
    int m_size;
};

extern void* D_00392068;
extern unsigned int D_00388830;
extern char D_0038FDB0[];
extern char D_0038FDB8[];
extern char D_0038FDC0[];
extern char D_0038FDC8[];
extern char D_0038FDD0[];
extern char D_0038FDD8[];
extern char D_00373228[];
extern char D_00373238[];
extern char D_00373248[];
extern char D_00373268[];
extern char D_00373280[];
extern char D_003730B8[];
extern char D_00373290[];
extern char D_003732A8[];
extern char D_003732C0[];
extern char D_003732D8[];
extern char D_003732F0[];
extern char D_00373308[];
extern char D_00373320[];
extern char D_00373330[];

extern "C" void func_002A8250(void* self, int n);
extern "C" void func_002B4BF8(void* self);
extern "C" void func_00202B38(void* self, int v);
extern "C" void func_002027E8(void* self, unsigned int v);
extern "C" void func_002A7658(void* self, int v);
extern "C" void func_002A7650(void* self, int v);
extern "C" void func_002A84A8(void* self, int v);
extern "C" void func_002A6D68(void* self, char* v);
extern "C" void* func_001190D0(unsigned int size);
extern "C" void* func_00122CF8(unsigned int size);
extern "C" void* func_001E6978(void* self);
extern "C" void* func_001E8DD0(void* self);
extern "C" void func_001E6B30(void* self);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7A68(void* self, unsigned int name, int type, int value);
extern "C" void func_001E7B38(void* self, unsigned int name, void* value);
extern "C" void func_001E7268(void* self, const char* name, int value);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" void func_001F0370(const char* name, void* params, void* a, int b);
extern "C" void func_001F0210(unsigned int name, void* params, void* a, int b, int c);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" void func_00202688(void* self, int v);
extern "C" void* func_0022E358(void* self);
extern "C" void func_0022E9B8(void* self);
extern "C" void func_0024F728(void* self, int v);
extern "C" void func_0024FA70(void* self, int v);
extern "C" void func_0024F418(void* self, int v);
extern "C" void func_0024EFE0(void* self, int v);
extern "C" void func_0024FBD8(void* self, void* params);
extern "C" void func_0022D728(void* self, int v);
extern "C" void func_002A80F0(void* self, int v);
extern "C" int func_001E5648(const char* name, int assert_);
extern "C" Array_00234688* func_001E55F8(const char* name, int assert_);
extern "C" void func_001E66C0(void* self, void* src);
extern "C" void* func_001E9378(void* self, int index);
extern "C" bool func_001E8A50(void* self, const char* name, unsigned int* out, int assert_);
extern "C" bool func_002A19A8(void* self);
extern "C" bool func_002A18E0(void* self);
extern "C" bool func_00215778(int a, int b);
extern "C" void func_002A3EA8(void* self);

bool func_00234688(Self_00234688* self)
{
    int i;
    void* game = D_00392068;
    func_002A8250(game, 7);
    func_002B4BF8(game);
    Info_00234688* info = self->m_info;
    void* sess = self->m1C;
    if (info->m1) {
        func_00202B38(self->m14, 0);
        func_002027E8(self->m14, (1000 / D_00388830) * 2);
    } else {
        func_00202B38(self->m14, 1);
        func_002027E8(self->m14, (1000 / D_00388830) * 2);
    }
    func_002A7658(game, info->m2);
    func_002A7650(game, info->m18);
    func_002A84A8(game, info->m0);
    func_002A6D68(game, info->m28);
    void* params = func_001E6978(func_001190D0(8));
    func_001E6B30(params);
    func_001E7A68(params, func_001F0D78(D_0038FDB0), 13, info->m18);
    func_001F0370(D_00373228, params, 0, 0);
    if (params)
        func_001E6AE8(params, 3);
    func_001F0370(D_00373238, 0, 0, 0);
    func_001F0370(D_00373248, 0, 0, 0);
    func_00202688(self->m14, 0);
    func_0024F728(func_0022E358(sess), info->m4);
    func_0024FA70(func_0022E358(sess), info->m10);
    func_0022E9B8(sess);
    func_0024FA70(func_0022E358(sess), info->m10);
    func_0024F418(func_0022E358(sess), info->m1C);
    func_002A80F0(game, info->m3);
    for (i = 0; i < 7; i++) {
        if ((info->m3 >> i) & 1) {
            void* p = func_001E6978(func_001190D0(8));
            func_001E7268(p, D_0038FDB8, func_001E5648(D_00373268, 1) + i);
            func_001F0370(D_0038FDC0, p, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
        }
    }
    void* settings = func_001E6978(func_001190D0(8));
    if (info->m10 != func_001F0D78(D_00373280)) {
        if (info->m20 == 0 && info->m10 != func_001F0D78(D_0038FDC8) && info->m10 != func_001F0D78(D_003730B8)) {
            if (info->m10 != 0x3D6D444F && info->m10 != 0xBFF33600) {
                void* arr = func_001E8DD0(func_00122CF8(0x10));
                func_001E66C0(arr, func_001E55F8(D_00373290, 0));
                void* first = func_001E9378(arr, 0);
                func_001E7A68(first, func_001F0D78(D_0038FDD0), 1, info->m24);
                func_001E7B38(settings, func_001F0D78(D_003732A8), arr);
            }
            func_001E7A68(settings, func_001F0D78(D_003732C0), 1, 0);
            func_0022D728(sess, 0);
            func_0024FBD8(func_0022E358(sess), settings);
        } else {
            func_001E7A68(settings, func_001F0D78(D_003732C0), 1, info->m20);
            if (info->m10 == func_001F0D78(D_0038FDC8)) {
                void* arr = func_001E8DD0(func_00122CF8(0x10));
                func_001E66C0(arr, func_001E55F8(D_003732D8, 0));
                func_001E7B38(settings, func_001F0D78(D_003732A8), arr);
            }
            func_0022D728(sess, info->m20);
            func_0024EFE0(func_0022E358(sess), info->m8);
            func_0024FBD8(func_0022E358(sess), settings);
        }
    }
    if (settings)
        func_001E6AE8(settings, 3);
    Array_00234688* types;
    if (func_002A19A8(game))
        types = func_001E55F8(D_003732F0, 0);
    else
        types = func_001E55F8(D_00373308, 0);
    for (i = 0; i < types->m_size; i++) {
        void* type = func_001E9378(types, i);
        unsigned int checksum;
        func_001E8A50(type, D_00373320, &checksum, 1);
        if (checksum == info->m10) {
            void* p = func_001E6978(func_001190D0(8));
            func_001E7268(p, D_0038FDD8, info->m20);
            func_001E7268(p, D_0038FDD0, info->m24);
            if (info->m20 == 0)
                func_001E7200(p, 0xF0E712D2, 1);
            else
                func_001E7200(p, 0xF0E712D2, 0);
            unsigned int script;
            func_001E8A50(type, D_00373330, &script, 1);
            func_001F0210(script, p, 0, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
            break;
        }
    }
    if (func_002A19A8(game) && !func_002A18E0(game) && !func_00215778(0, 0))
        func_002A3EA8(game);
    return true;
}
