class Child_001390E0 {
public:
    int m0;
    int m4;
    virtual ~Child_001390E0();
};

extern "C" int func_00138918(Child_001390E0* c);
extern "C" void func_001325A0();
extern "C" void func_001398B0(void* list, int* key);

class Node_001390E0 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    virtual ~Node_001390E0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int V4(Child_001390E0* c);
    bool Remove(Child_001390E0* c);
};

bool Node_001390E0::Remove(Child_001390E0* c)
{
    int key = func_00138918(c);
    func_001325A0();
    if (V4(c)) {
        func_001398B0(m8, &key);
        return true;
    }
    return false;
}
