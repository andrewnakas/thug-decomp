extern short D_00392840[];
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void* func_002CC830();
extern "C" void func_002CC1F8(void* mgr, int id, void* data);

struct Obj_002C84F8 {
    char pad[0x80];
    char m80[0x24];
    char mA4[0x20];
    int mC4;
    int mC8;
    int mCC;
    void Set(char* name, int v);
};

void Obj_002C84F8::Set(char* name, int v)
{
    if (name) {
        if (!name[0])
            *(short*)mA4 = D_00392840[0];
        else
            func_00331A9C(mA4, name);
    }
    if (v >= 0)
        mC4 = v;
    func_002CC1F8(func_002CC830(), mCC, m80);
}
