/* sym: __13Base_001B7F00 = 0x00184DC0 */
/* sym: _vt$12Obj_001B7F00 = 0x00362E88 */
/* sym: __14Inner_001B7F00 = 0x00114C30 */
extern "C" void* func_001046B0(unsigned int size);

struct Inner_001B7F00 {
    char pad[0xC0];
    Inner_001B7F00();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

struct Base_001B7F00 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001B7F00();
    virtual ~Base_001B7F00();
};

struct Obj_001B7F00 : Base_001B7F00 {
    int m1C;
    Inner_001B7F00* m20;
    Obj_001B7F00();
    virtual void Update();
};

Obj_001B7F00::Obj_001B7F00()
{
    m_type = 0xC4E311FA;
    m1C = 1;
    m20 = new Inner_001B7F00;
}
