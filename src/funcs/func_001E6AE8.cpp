extern "C" void func_00119120(void* p);
extern "C" void func_001E6B30(void* self);

// Destructor whose body clears the object; the class operator delete
// gives the in_chrg & 1 branch.
class Obj_001E6AE8 {
public:
    int m0;
    ~Obj_001E6AE8();
    static void operator delete(void* p) { func_00119120(p); }
};

Obj_001E6AE8::~Obj_001E6AE8()
{
    func_001E6B30(this);
}
