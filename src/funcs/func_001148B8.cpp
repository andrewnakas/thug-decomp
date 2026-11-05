extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Heap_001148B8 {
public:
    char pad[0x18];
    virtual void V1();
    virtual void V2();
    virtual ~Heap_001148B8();
};

class Obj_001148B8;
extern "C" void func_001147C8(Obj_001148B8* self);

class Obj_001148B8 {
public:
    int m0;
    void* m4;
    void* m8;
    Heap_001148B8* mC;
    ~Obj_001148B8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_001148B8::~Obj_001148B8()
{
    func_0010A8D8(D_00388A70, m4);
    func_0010A8D8(D_00388A70, m8);
    delete mC;
    func_001147C8(this);
}
