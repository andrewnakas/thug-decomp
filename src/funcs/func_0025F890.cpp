struct Node_0025F890 {
    int m0;
    int m_key;
    int m8;
    Node_0025F890* m_next;
    Node_0025F890* Valid()
    {
        if (m_key == -1)
            return 0;
        return this;
    }
};

struct Item_0025F890 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual int Get();
};

struct Obj_0025F890;
extern "C" Item_0025F890* func_0025F1C8(Obj_0025F890* self, int id);
extern "C" Item_0025F890* func_0025F128(Obj_0025F890* self, int index);

struct Obj_0025F890 {
    char m_pad[0x54];
    Node_0025F890* m_head;
    int GetCurrent(int id);
};

int Obj_0025F890::GetCurrent(int id)
{
    int n = 0;
    for (Node_0025F890* p = m_head->Valid(); p; p = p->m_next->Valid())
        n++;
    if (!n)
        return 0;
    if (id) {
        Item_0025F890* it = func_0025F1C8(this, id);
        if (it)
            return it->Get();
        return 0;
    }
    return func_0025F128(this, 0)->Get();
}
