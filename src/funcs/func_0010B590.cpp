class Heap_0010B590 {
public:
    char pad[0x18];
    virtual ~Heap_0010B590();
};

struct Obj_0010B590;
extern "C" void func_0010AFE0(Obj_0010B590* self, void* item);

struct Obj_0010B590 {
    char pad[0x100];
    Heap_0010B590* m100;
    void* m104;
    void* m108;
    void Shutdown();
};

void Obj_0010B590::Shutdown()
{
    if (m100) {
        func_0010AFE0(this, m104);
        func_0010AFE0(this, m108);
        delete m100;
        m100 = 0;
    }
}
