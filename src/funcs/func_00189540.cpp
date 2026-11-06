/* sym: _vt$13Pool_00189540 = 0x00361D90 */
/* sym: _$_13Hash_00189540 = 0x0018ADD0 */
/* sym: _$_14Slots_00189540 = 0x00188D98 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Hash_00189540 {
public:
    ~Hash_00189540();
};

class Slots_00189540 {
public:
    char m[0xB1FC];
    ~Slots_00189540();
};

class Pool_00189540 {
public:
    int m0;
    int m4;
    Hash_00189540* m_hash;
    char padC[0x14];
    Slots_00189540 m_slots;

    virtual void Key();
    virtual ~Pool_00189540();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Pool_00189540::~Pool_00189540()
{
    delete m_hash;
}
