extern "C" void* func_00185578(void* obj, unsigned int crc);
extern "C" void* func_001A0E08(void* c);
extern "C" int func_001A0AD0(void* c, void* d);
extern "C" float func_001A0EC8(void* c);
extern "C" float func_001A0AB0(void* c, void* d);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001E7138(void* s, const char* name, const char* value);
extern "C" int func_0033ECA8(float f);
extern "C" void func_001F0370(const char* name, void* s, int a, int b);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void* func_00256BD8(void* obj);
extern "C" int func_0013EF10(void* p);
extern "C" void func_00255F68(void* obj);

extern char D_00390910[];
extern char D_00390918[];
extern char D_00390920[];
extern char D_00390928[];
extern char D_00390930[];
extern char D_00390938[];
extern char D_00375408[];
extern char D_00375418[];
extern char D_00375428[];
extern char D_00375438[];

struct Obj_002561B0 {
    char pad[0x170];
    float m170;
    int m174;
    int m178;
};

static inline int Get_002561B0(Obj_002561B0* o) { if (o->m174) return 0; return func_0033ECA8(o->m170); }
extern "C" void func_002561B0(Obj_002561B0* o)
{
    if (func_00185578(o, 0x72AD7B23) && o->m178) {
        void* a = func_00185578(o, 0x72AD7B23);
        if (func_001A0AD0(a, func_001A0E08(func_00185578(o, 0x72AD7B23)))) {
            void* s = func_001E6978(func_001190D0(8));
            char buf0[128];
            char buf1[128];
            char buf2[128];
            char buf3[128];
            func_003331D0(buf0, D_00390910, D_00390918);
            func_001E7138(s, D_00390920, buf0);
            func_003331D0(buf1, D_00375408, Get_002561B0(o));
            func_001E7138(s, D_00390928, buf1);
            func_003331D0(buf2, D_00375418, func_0033ECA8(func_001A0EC8(func_00185578(o, 0x72AD7B23))), func_0033ECA8(func_001A0AB0(func_00185578(o, 0x72AD7B23), func_001A0E08(func_00185578(o, 0x72AD7B23)))));
            func_001E7138(s, D_00390930, buf2);
            func_003331D0(buf3, D_00375428, (int)(func_001A0EC8(func_00185578(o, 0x72AD7B23)) * 60.0f), (int)(func_001A0AB0(func_00185578(o, 0x72AD7B23), func_001A0E08(func_00185578(o, 0x72AD7B23))) * 60.0f));
            func_001E7138(s, D_00390938, buf3);
            func_001F0370(D_00375438, s, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
        }
    }
    if (func_0013EF10(func_00256BD8(o)))
        func_00255F68(o);
}
