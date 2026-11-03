extern "C" void func_002CBB40(void* p);
extern "C" void func_002CD4D8(void* self);

// Destructor whose body clears the object; the class operator delete
// (func_002CBB40) gives the in_chrg & 1 branch.
class Obj_002CD490 {
public:
    int m0;
    ~Obj_002CD490();
    static void operator delete(void* p) { func_002CBB40(p); }
};

Obj_002CD490::~Obj_002CD490()
{
    func_002CD4D8(this);
}
