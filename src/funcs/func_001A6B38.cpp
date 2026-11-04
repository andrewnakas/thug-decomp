struct Params1A6B38;
struct Obj1A6B38;
extern "C" int func_001E8398(Params1A6B38* p, unsigned int name, int* out, int required);
extern "C" void* func_00229668(int id, int a);
extern "C" void func_001A6AB8(Obj1A6B38* o, void* target);

struct Obj1A6B38 {
    char m_pad[0x1C];
    int m_flags;
    void SetTarget(Params1A6B38* params);
};

void Obj1A6B38::SetTarget(Params1A6B38* params)
{
    int id;
    if (func_001E8398(params, 0xA1DC81F9, &id, 0)) {
        func_001A6AB8(this, func_00229668(id, 1));
        m_flags = (m_flags | 0x10) & ~8;
    }
}
