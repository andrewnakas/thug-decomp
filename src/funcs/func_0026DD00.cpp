struct Node_0026DD00 {
    char pad[0x48];
    int m48;
};

extern "C" Node_0026DD00* func_0026DC58(void* self, int idx);

int Get_0026DD00(void* self, int idx)
{
    return func_0026DC58(self, idx)->m48;
}
