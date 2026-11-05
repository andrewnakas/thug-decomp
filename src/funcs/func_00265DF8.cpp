extern "C" void func_00265DB8(void* p);
extern "C" void func_002668B0(void* list, void (*fn)(void*), void* ctx);
extern "C" void func_002659C8(void* a, int b, int count, int* items, int flag);

struct Ids_00265DF8 {
    int m_items[32];
    int m_count;
};

struct Obj_00265DF8 {
    int m0;
    int m4;
    int m8[6];
    void Send(void* to);
};

void Obj_00265DF8::Send(void* to)
{
    Ids_00265DF8 ids;
    ids.m_count = 0;
    func_002668B0(m8, func_00265DB8, &ids);
    if (ids.m_count)
        func_002659C8(to, 1000, ids.m_count, ids.m_items, 1);
}
