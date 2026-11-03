extern "C" void func_00104A20(void* self, int arg);

class Obj104E90;

// Node owned by the object (vtable D_0035AA00): slot 1 is the deleting
// destructor func_00105318.
class OwnerLink {
public:
    int m0;
    Obj104E90* m_owner;
    int m8;
    OwnerLink* m_prev;
    OwnerLink* m_next;
    virtual ~OwnerLink();
    virtual void Run();
};

struct Obj104E90 {
    char pad[0x28];
    OwnerLink* m_link;
    void Destroy(int arg);
};

void Obj104E90::Destroy(int arg)
{
    delete m_link;
    func_00104A20(this, arg);
}
