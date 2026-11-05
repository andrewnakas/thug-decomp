class Heap_0010BD68 {
public:
    char pad[0x18];
    virtual ~Heap_0010BD68();
};

struct Rec_0010BD68 {
    Heap_0010BD68* m_heap;
    void* m4;
    int m8;
    char padC[0x8C - 0xC];
    int m8C;
};

struct Obj_0010BD68;
extern "C" Rec_0010BD68* func_0010BC50(Obj_0010BD68* self, int id);
extern "C" void func_0010AFE0(Obj_0010BD68* self, void* item);

struct Obj_0010BD68 {
    int m0;
    int Release(int id);
};

int Obj_0010BD68::Release(int id)
{
    Rec_0010BD68* r = func_0010BC50(this, id);
    if (r) {
        func_0010AFE0(this, r->m4);
        delete r->m_heap;
        r->m_heap = 0;
        r->m4 = 0;
        r->m8 = 0;
        r->m8C = 0;
        return 1;
    }
    return 0;
}
