struct Item_0023E1D8 {
    char pad[0x18];
    void* m_obj;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" Item_0023E1D8* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_002498B0(void* obj, void* params);

struct Owner_0023E1D8 {
    void Run(void* params);
};

void Owner_0023E1D8::Run(void* params)
{
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    func_002498B0(func_0023BAD8(this, id, 1)->m_obj, params);
}
