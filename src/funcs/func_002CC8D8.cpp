extern "C" void func_002CE508(void* p);
extern "C" void func_002CC920(void* self);

// Destructor whose body clears the object; the class operator delete
// (func_002CE508) gives the in_chrg & 1 branch.
class Obj_002CC8D8 {
public:
    int m0;
    ~Obj_002CC8D8();
    static void operator delete(void* p) { func_002CE508(p); }
};

Obj_002CC8D8::~Obj_002CC8D8()
{
    func_002CC920(this);
}
