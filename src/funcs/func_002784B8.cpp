/* sym: _vt$12Obj_002784B8 = 0x003769E0 */
/* sym: _$_13Base_002784B8 = 0x00184DD8 */
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* self);
extern "C" void func_001E6AE8(void* self, int chrg);
extern "C" void func_001E7360(void* s, unsigned int crc, int v);
extern "C" void func_001F0210(unsigned int crc, void* s, int a, int b, int c);

struct Base_002784B8 {
    char pad0[0x18];
    virtual ~Base_002784B8();
};

struct Obj_002784B8 : Base_002784B8 {
    int m_1C;
    virtual void Update();
    virtual ~Obj_002784B8();
};

Obj_002784B8::~Obj_002784B8()
{
    void* s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0x40C698AF, m_1C);
    func_001F0210(0x2575B406, s, 0, 0, 0);
    if (s) {
        func_001E6AE8(s, 3);
    }
}
