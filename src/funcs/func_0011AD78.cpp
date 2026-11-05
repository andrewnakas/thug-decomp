struct Src_0011AD78 {
    char pad[0xC];
    int mC;
};

extern "C" Src_0011AD78* func_0011AC50(void* self);
extern "C" int func_0011EA80(Src_0011AD78* src);
extern "C" float func_00119768(void* p);
extern "C" void func_00144D30(void* ctl, char* start, char* end, int a, int b, float f);
extern "C" void func_00144CB0(void* ctl, int a);

struct Obj_0011AD78 {
    int m0;
    void* m4;
    char pad8[0x18 - 8];
    void* m_ctl;
    int Start(char* data);
};

int Obj_0011AD78::Start(char* data)
{
    int a = func_0011EA80(func_0011AC50(this));
    int b = func_0011AC50(this)->mC;
    func_00144D30(m_ctl, data, data + 0x400, a, b, func_00119768(m4));
    func_00144CB0(m_ctl, 1);
    return 1;
}
