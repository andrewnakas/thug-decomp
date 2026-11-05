/* sym: __13Base_001D52A0RC13Base_001D52A0 = 0x001D7248 */
/* sym: _vt$13Copy_001D52A0 = 0x00364040 */
typedef int qword_001D52A0 __attribute__((mode(TI)));

struct Heap_001D52A0;
extern Heap_001D52A0* D_00388A70;
extern "C" void* func_0010A638(Heap_001D52A0* heap, unsigned int size, int a, int b);

struct Vec_001D52A0 {
    union {
        struct { float x, y, z, w; };
        qword_001D52A0 q;
    };
};

struct Root_001D52A0 {
    int m0;
    unsigned short m4;
    short m6;
    int m8;
    virtual ~Root_001D52A0();
    virtual Root_001D52A0* Clone();
};

struct Base_001D52A0 : Root_001D52A0 {
    char pad10[0xA0];
    Base_001D52A0();
    Base_001D52A0(const Base_001D52A0& o);
};

struct Pair_001D52A0 {
    short a, b;
};

struct Copy_001D52A0 : Base_001D52A0 {
    Vec_001D52A0 mB0;
    Vec_001D52A0 mC0;
    int mD0;
    short mD4;
    Pair_001D52A0 mD6;
    virtual void Update();
    virtual Root_001D52A0* Clone();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

Root_001D52A0* Copy_001D52A0::Clone()
{
    Copy_001D52A0* c = new Copy_001D52A0(*this);
    c->m8 = 0;
    c->m4 |= 0x8000;
    return c;
}
