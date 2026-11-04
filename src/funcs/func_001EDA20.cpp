struct Entry_001EDA20 {
    int m0;
    void* data;
    Entry_001EDA20* next;
};

extern Entry_001EDA20* D_0038E6F8;
extern "C" void func_0010BEB8(void* p);

void func_001EDA20()
{
    if (!D_0038E6F8) return;
    Entry_001EDA20* b = D_0038E6F8;
    for (unsigned int i = 0; i < 0x1000; i++) {
        Entry_001EDA20* e = b->next;
        while (e) {
            Entry_001EDA20* n = e->next;
            func_0010BEB8(e->data);
            func_0010BEB8(e);
            e = n;
        }
        if (b->data) func_0010BEB8(b->data);
        b++;
    }
    func_0010BEB8(D_0038E6F8);
    D_0038E6F8 = 0;
}
