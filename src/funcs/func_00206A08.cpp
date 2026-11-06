extern void* D_00392068;
extern "C" int func_002A19A8(void* p);
extern "C" char* func_002A52F0(void* p, int id);
extern "C" char* func_001041B8(char* p);

struct Obj_00206A08 {
    char m_pad0[0x18];
    unsigned short m18;
    char* Get();
};

char* Obj_00206A08::Get()
{
    void* mgr = D_00392068;
    if (func_002A19A8(mgr))
        return func_002A52F0(mgr, m18) + 0x34;
    return func_001041B8((char*)this + 0x1B4);
}
