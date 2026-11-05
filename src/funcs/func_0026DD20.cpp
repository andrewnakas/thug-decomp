typedef int qword __attribute__((mode(TI)));
union Vec_0026DD20 {
    qword q;
    float c[4];
    Vec_0026DD20& operator=(const Vec_0026DD20& o)
    {
        q = o.q;
        return *this;
    }
};

struct Node_0026DD20 {
    char pad[0x20];
    Vec_0026DD20 m20;
    Vec_0026DD20 m30;
};

extern "C" Node_0026DD20* func_0026DC58(void* self, int idx);

void Get_0026DD20(void* self, int idx, Vec_0026DD20* a, Vec_0026DD20* b)
{
    Node_0026DD20* n = func_0026DC58(self, idx);
    *a = n->m20;
    *b = n->m30;
}
