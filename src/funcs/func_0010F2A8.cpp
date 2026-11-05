extern char* D_0038C308;
extern "C" void func_00105260(void* list, void* item);

struct Obj_0010F2A8 {
    int m0[6];
    void* m_18;
    void Remove();
};

void Obj_0010F2A8::Remove()
{
    void* item = m_18;
    func_00105260(D_0038C308 + 8, item);
}
