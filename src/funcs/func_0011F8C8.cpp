/* sym: _$_13Base_0011F8C8 = 0x00183D80 */
/* sym: _$_12Sub_0011F8C8 = 0x001E6AE8 */
/* sym: _vt$12Obj_0011F8C8 = 0x0035CA80 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Sub_0011F8C8 {
    int m0;
    int m4;
    ~Sub_0011F8C8();
};

class Base_0011F8C8 {
public:
    int m0;
    int m4;
    virtual ~Base_0011F8C8();
};

class Obj_0011F8C8 : public Base_0011F8C8 {
public:
    char padC[0x48 - 0xC];
    Sub_0011F8C8 m48;
    void* m50;
    virtual void Run();
    virtual ~Obj_0011F8C8();
};

Obj_0011F8C8::~Obj_0011F8C8()
{
    if (m50) {
        func_0010A8D8(D_00388A70, m50);
        m50 = 0;
    }
}
