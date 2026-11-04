/* sym: _vt$12Own_00252CA0 = 0x00375068 */
/* sym: _$_10S_00252CA0 = 0x001E6AE8 */
/* sym: _$_12Arr_00252CA0 = 0x001E8DE8 */
struct Pool_00252CA0;
extern Pool_00252CA0* D_00388A70;
extern "C" void func_0010A8D8(Pool_00252CA0* p, void* m);

class S_00252CA0 {
public:
    int m0;
    ~S_00252CA0();
};

class Arr_00252CA0 {
public:
    int m0;
    ~Arr_00252CA0();
};

extern "C" void func_001E6518(Arr_00252CA0* a);

class Own_00252CA0 {
public:
    S_00252CA0* m0;
    Arr_00252CA0* m4;
    Arr_00252CA0* m8;
    virtual void Update();
    virtual ~Own_00252CA0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Own_00252CA0::~Own_00252CA0()
{
    if (m0) delete m0;
    if (m4) {
        func_001E6518(m4);
        delete m4;
    }
    if (m8) {
        func_001E6518(m8);
        delete m8;
    }
}
