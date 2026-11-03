extern "C" void func_0029C410(void* p);
extern "C" void func_002995D0(void* self);

// Destructor whose body clears the object; the class operator delete
// gives the in_chrg & 1 branch.
class Obj_00299588 {
public:
    int m0;
    ~Obj_00299588();
    static void operator delete(void* p) { func_0029C410(p); }
};

Obj_00299588::~Obj_00299588()
{
    func_002995D0(this);
}
