struct Node_0023DD78 {
    int m0;
    int m4;
    void* m8;
};

extern "C" void func_0023D750(void* self);
extern "C" Node_0023DD78* func_001E6E90(void* list, Node_0023DD78* prev);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_0023DD78 {
    char pad[0x1C];
    void* m1C;
    int Count(int id);
};

int Obj_0023DD78::Count(int id)
{
    func_0023D750(this);
    int n = 0;
    Node_0023DD78* c = func_001E6E90(m1C, 0);
    while (c) {
        Node_0023DD78* next = func_001E6E90(m1C, c);
        int v = 0;
        if (func_001E7DE8(c->m8, 0x1A4CDE06, &v, 0)) {
            int w = 0;
            func_001E7DE8(c->m8, 0x49807745, &w, 0);
            if (v == id && w) n++;
        }
        c = next;
    }
    return n;
}
