extern "C" bool func_00116170(void* a, void* b, void* c, void* d);

struct Obj_00144D58 {
    int m0;
    void* m_4;
    char pad[0xA04];
    int m_A0C;
    bool Start(void* b, void* c);
};

bool Obj_00144D58::Start(void* b, void* c)
{
    bool ok = func_00116170(m_4, b, c, this);
    m_A0C = 1;
    return ok;
}
