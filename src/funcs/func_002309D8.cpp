struct Child_002309D8 {
    char pad[0x18];
    virtual void V0();
    virtual void V1();
    virtual ~Child_002309D8() = 0;
};

struct Obj_002309D8 {
    char pad[0x1C];
    Child_002309D8* m_1C;
    Child_002309D8* m_20;
    void Release();
};

void Obj_002309D8::Release()
{
    delete m_1C;
    delete m_20;
}
