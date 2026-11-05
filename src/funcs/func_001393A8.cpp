class Child_001393A8 {
public:
    int m0;
    int m4;
    virtual ~Child_001393A8();
};

extern "C" void func_00139968(void* list, int* key, Child_001393A8* c);

class Node_001393A8 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    virtual ~Node_001393A8();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual Child_001393A8* V7();
    Child_001393A8* Create(int key);
};

Child_001393A8* Node_001393A8::Create(int key)
{
    Child_001393A8* c = V7();
    if (c) {
        c->m0 = key;
        func_00139968(m8, &key, c);
    }
    return c;
}
