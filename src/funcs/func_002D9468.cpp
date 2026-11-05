struct Obj_002D9468;
extern "C" void func_002F1D28(Obj_002D9468* o);
extern "C" void func_001048F0(void* p);

struct Obj_002D9468 {
    void* m0;
    int m4;
    int m8;
    void Clear();
};

void Obj_002D9468::Clear()
{
    func_002F1D28(this);
    func_001048F0(m0);
    m4 = 0;
    m8 = 0;
}
