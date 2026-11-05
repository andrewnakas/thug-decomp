extern "C" int func_002654F8(void* self, int id);

struct Buf_00265678 {
    int m0;
    int m4;
    int m_items[1];
};

struct Obj_00265678 {
    char pad[0x18];
    int m18;
    void Add(Buf_00265678* b);
};

void Obj_00265678::Add(Buf_00265678* b)
{
    if (func_002654F8(this, b->m0)) {
        b->m_items[b->m4] = m18;
        b->m4++;
    }
}
