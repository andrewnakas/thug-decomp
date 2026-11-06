/* sym: _$_14Table_001827B0 = 0x00104F70 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Table_001827B0 {
public:
    char m[0x4C];
    ~Table_001827B0();
};

class Owner_001827B0 {
public:
    int m0;
    int m4;
    Table_001827B0 m8;
    Table_001827B0 m54;
    Table_001827B0 mA0;
    ~Owner_001827B0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Owner_001827B0::~Owner_001827B0()
{
}
