extern "C" void func_00125E58(void* p);
extern "C" void func_001E8E38(void* self);

// Destructor whose body clears the object; the class operator delete
// gives the in_chrg & 1 branch.
class Obj_001E8DE8 {
public:
    int m0;
    ~Obj_001E8DE8();
    static void operator delete(void* p) { func_00125E58(p); }
};

Obj_001E8DE8::~Obj_001E8DE8()
{
    func_001E8E38(this);
}
