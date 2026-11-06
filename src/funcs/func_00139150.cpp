class Child_00139150 {
public:
    int m0;
    int m4;
    virtual ~Child_00139150();
};

extern "C" int func_00138918(Child_00139150* c);
extern "C" int func_00139968(void* list, const int* key, Child_00139150* c);

class Node_00139150 {
public:
    int m0;
    short m4;
    void* m8;
    int mC;
    virtual ~Node_00139150();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual int V5(Child_00139150* c);
    void Insert(const int& key, Child_00139150* c) { func_00139968(m8, &key, c); }
    int Add(Child_00139150* c);
};

int Node_00139150::Add(Child_00139150* c)
{
    int key = func_00138918(c);
    func_00139968(m8, &key, c);
    return V5(c);
}
